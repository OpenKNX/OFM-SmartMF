#include "RgbLed.h"
#include "PCA9632.h"

RgbLed::RgbLed()
{
}

void RgbLed::ownLoop()
{
    if (delayCheck(_LoopTimer, 100))
    {
        _LoopTimer = millis();
        OpenKNX::Led::Base::loop();
    }
}

void RgbLed::writeLed(uint8_t brightness) {
#ifdef I2C_RGBLED_DEVICE_ADDRESS
    uint8_t calcBrightness = (uint32_t)brightness * _maxBrightness / 255;

    if (calcBrightness == _currentLedBrightness && !_ColorDirty)
        return;

    uint8_t red   = ((uint32_t)_Red   * calcBrightness * OpenKNX_LedColor_Calibration[0] / (255 * 255));
    uint8_t green = ((uint32_t)_Green * calcBrightness * OpenKNX_LedColor_Calibration[1] / (255 * 255));
    uint8_t blue  = ((uint32_t)_Blue  * calcBrightness * OpenKNX_LedColor_Calibration[2] / (255 * 255));

    PCA9632_SetColor(red, green, blue);
    
    _currentLedBrightness = calcBrightness;
    _ColorDirty = false;
#endif
}

void RgbLed::init() {
    PCA9632_SetColor(0, 0, 0);
    _initialized = true;
}

void RgbLed::powerSave(bool active) {
    if (active) {
        writeLed(0); // Turn off LED in power save mode
    }
    _powerSave = active;
}

void RgbLed::setColor(uint8_t r, uint8_t g, uint8_t b) {
    // Implementation for setting RGB color can be added here
    _Red = r;
    _Green = g;
    _Blue = b;
    _ColorDirty = true;
    writeLed(_currentLedBrightness);
}
