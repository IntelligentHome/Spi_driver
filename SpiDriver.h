#pragma once

#include "ITransport.h"
#include "IGpioDriver.h"

namespace spi_driver {

class SpiDriver : public transport::ITransport {

public:

    virtual uint8_t Reset(void) = 0;
    virtual void Send(uint8_t send_buff[], uint16_t size) = 0;
    virtual void Get(uint8_t recv_buff[], uint16_t size) = 0;
    virtual void SendAndGet(uint8_t send_buff[], uint8_t recv_buff[], uint16_t size) = 0;
};

} /* namespace spi_driver */
