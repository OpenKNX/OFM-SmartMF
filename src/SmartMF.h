#pragma once
#include "OpenKNX.h"
#include "RgbLed.h"

#ifdef SmartMF_HardwareVariant_PIN
#define SmartMF_HardwareVariant
#endif

#ifdef SmartMF_HardwareRevision_PIN1
#ifdef SmartMF_HardwareRevision_PIN2
#ifdef SmartMF_HardwareRevision_PIN3
#define SmartMF_HardwareRevision
#endif
#endif
#endif

class SmartMF : public OpenKNX::Module
{
  protected:
    uint8_t _hardwareVariant = 0;
    uint8_t _hardwareRevision = 0;
    RgbLed *_RgbLed = nullptr;
#ifdef SmartMF_HardwareVariant
    uint8_t mapHardwareVariant(uint32_t value);
    void readHardwareVariant();
#endif
#ifdef SmartMF_HardwareRevision
    void readHardwareRevision();
#endif

  public:
    SmartMF() {};

    uint8_t hardwareVariant();
    uint8_t hardwareRevision();
    
    const std::string version() override { return MODULE_SmartMF_Version; }
    virtual const std::string name() override { return "SmartMF"; };
    virtual void init() override;
    virtual void loop(bool configured) override;
};

extern SmartMF smartmf;