
#include "SpiAvr.h"
#include <avr/io.h>

namespace spi_avr {

SpiAvr::SpiAvr(
        gpio_driver::IGpio *cs,
        iconsole::IConsole *console)
    :
    cs_(cs),
    console_(console)
{
    // By default Spi device will not be select.
    cs_->Set();

    // add preprocesor define only for atmega8.
    DDRB |= (1 << 5) | (1 << 3) | (1 << 2);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0) | (1 << SPR1);

    console_->print("SpiAvr").newline();

}

uint8_t SpiAvr::Reset(void) {
    return 0;
}

void SpiAvr::Send(uint8_t send_buff[], uint16_t size) {

    cs_->Clear();

    for (uint16_t i = 0; i < size; i++)
        this->SendAndGetByte(send_buff[i]);

    cs_->Set();
}

void SpiAvr::Get(uint8_t recv_buff[], uint16_t size) {

    cs_->Clear();

    for (uint16_t i = 0; i < size; i++)
        recv_buff[i] = this->SendAndGetByte(0xFF);

    cs_->Set();
}

void SpiAvr::SendAndGet(uint8_t send_buff[], uint8_t recv_buff[], uint16_t size) {

    cs_->Clear();

    for (uint16_t i = 0; i < size; i++)
        recv_buff[i] = this->SendAndGetByte(send_buff[i]);

    cs_->Set();
}

uint8_t SpiAvr::SendAndGetByte(const uint8_t data) {

    SPDR = data;

    this->console_->print("SpiAvr::SendAndGetByte ").print(data).newline();

    while (!(SPSR & (1 << SPIF)));

    this->console_->print("SpiAvr::SendAndGetByte - end ").print(SPDR).newline();

    return SPDR;
}

} /*namespace spi_avr*/
