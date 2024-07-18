#pragma once
#include "OpenKNX.h"

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

class SmartMF
{
  protected:
    uint8_t _hardwareVariant = 0;
    uint8_t _hardwareRevision = 0;

#ifdef SmartMF_HardwareVariant
    uint8_t mapHardwareVariant(uint32_t value);
    void readHardwareVariant();
#endif
#ifdef SmartMF_HardwareRevision
    void readHardwareRevision();
#endif

  public:
    SmartMF();

    void init();
    uint8_t hardwareVariant();
    uint8_t hardwareRevision();
};

extern SmartMF smartmf;