
#pragma once

#include "SpiDriver.h"
#include "IConsole.h"

namespace spi_avr {

class SpiAvr : public spi_driver::SpiDriver {

public:
    SpiAvr(
        gpio_driver::IGpio *cs,
        iconsole::IConsole *console);

    virtual uint8_t Reset(void);
    virtual void Send(uint8_t send_buff[], uint16_t size);
    virtual void Get(uint8_t recv_buff[], uint16_t size);
    virtual void SendAndGet(uint8_t send_buff[], uint8_t recv_buff[], uint16_t size);

private:
    gpio_driver::IGpio *cs_;
    iconsole::IConsole *console_;

    uint8_t SendAndGetByte(const uint8_t data);

};

} /*namespace spi_avr_driver*/
