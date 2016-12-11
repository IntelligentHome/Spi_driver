
#include "SpiAvrDriver.h"

namespace spi_avr_driver {

SpiAvr::SpiAvr(
        gpio_driver::IGpio *cs,
        IsSent is_sent,
        volatile uint8_t *spi_trans_reg)
    :
    cs_(cs),
    is_sent_(is_sent),
    spi_trans_reg_(spi_trans_reg)
{
    // By default Spi device will not be select.
    cs_->Set();
}

uint8_t SpiAvr::Reset(void) {
    return 0;
}

void SpiAvr::Send(uint8_t *psend_buff, uint16_t size) {

    cs_->Clear();

    cs_->Set();
}

void SpiAvr::Get(uint8_t *precv_buff, uint16_t size) {

    cs_->Clear();

    cs_->Set();
}

void SpiAvr::SendAndGet(uint8_t *psend_buff, uint8_t *precv_buff, uint16_t size) {

    cs_->Clear();

    cs_->Set();
}

uint8_t SpiAvr::CheckIfSent(void) {

#if defined (__AVR_ATmega8__)

#else
#	warning  "Unknown MCU"
#endif

    return 0;
}

} /*namespace spi_avr_driver*/
