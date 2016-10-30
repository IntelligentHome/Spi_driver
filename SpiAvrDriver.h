
#pragma once

#include "ISpiDriver.h"
#include "IGpioDriver.h"

namespace spi_avr_driver {

typedef uint8_t (*IsSent) (void);

class SpiAvr : public spi_driver::ISpi {

public:
    SpiAvr(
        gpio_driver::IGpio *cs,
        IsSent is_sent,
        volatile uint8_t *spi_trans_reg
        );

    SpiAvr(
        gpio_driver::IGpio *cs);

    virtual void Send(uint8_t *psend_buff, uint16_t size);
    virtual void Get(uint8_t *precv_buff, uint16_t size);
    virtual void SendAndGet(uint8_t *psend_buff, uint8_t *precv_buff, uint16_t size);

    static uint8_t CheckIfSent(void);
private:
    gpio_driver::IGpio *cs_;
    IsSent is_sent_;
    volatile uint8_t *spi_trans_reg_;

};

} /*namespace spi_avr_driver*/
