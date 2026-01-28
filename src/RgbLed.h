#pragma once
#include "OpenKNX/Led/RGB.h"

class RgbLed : public OpenKNX::Led::RGB
{
    private:
        uint8_t _Red = 0;
        uint8_t _Green = 0;
        uint8_t _Blue = 0;
        bool _ColorDirty = false;
        uint32_t _LoopTimer = 0;

    protected:
        void writeLed(uint8_t brightness) override;

    public:
        RgbLed();
        
        virtual void init() override;
        virtual void loop() override {}
        virtual void powerSave(bool active = true) override;
        virtual std::string logPrefix() override { return "SmartMF-RGB"; }
        
        // virtual bool isRGB() override { return true; }
        // virtual void setColor(OpenKNX::Led::Color color) override;
        // virtual void setColor(uint32_t rgb) override;
        virtual void setColor(uint8_t r, uint8_t g, uint8_t b) override;
        
        virtual void ownLoop();
    };