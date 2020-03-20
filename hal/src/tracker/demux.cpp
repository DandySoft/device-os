/*
 * Copyright (c) 2020 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "demux.h"

#if HAL_PLATFORM_DEMUX

#include "check.h"
#include "system_error.h"

using namespace particle;

Demux::Demux()
        : initialized_(false),
          pinValue_(DEFAULT_PINS_VALUE) {
    init();
}

Demux::~Demux() {

}

int Demux::write(uint8_t pin, uint8_t value) {
    DemuxLock lock();
    CHECK_TRUE(pin < DEMUX_MAX_PIN_COUNT && pin != 0, SYSTEM_ERROR_INVALID_ARGUMENT); // Y0 is not available for user's usage.
    CHECK_TRUE(initialized_, SYSTEM_ERROR_INVALID_STATE);
    // We can do it in this way for now, since the control pins are continuous.
    // Otherwise, we should use the general method below.
    uint32_t currOut = (nrf_gpio_port_out_read(DEMUX_NRF_PORT) >> 10) & 0x00000007;
    if ((currOut == pin && value == 0) || (currOut != pin && value == 1)) {
        return SYSTEM_ERROR_NONE;
    }
    if (value) {
        // Select Y0 by default, so that all other pins output high.
        nrf_gpio_port_out_clear(DEMUX_NRF_PORT, DEMUX_PIN_A_MASK | DEMUX_PIN_B_MASK | DEMUX_PIN_C_MASK);
        setPinValue(0, 0);
    } else {
        nrf_gpio_port_out_set(DEMUX_NRF_PORT, ((uint32_t)pin) << 10);
        setPinValue(pin, 0);
    }

    // Select Y0 by default, so that all other pins output high.
    // nrf_gpio_port_out_clear(DEMUX_NRF_PORT, DEMUX_PIN_A_MASK | DEMUX_PIN_B_MASK | DEMUX_PIN_C_MASK);
    // setPinValue(0, 0);
    // uint32_t bitSetMask = 0x00000000;
    // if (value == 0) {
    //     if (pin >= 4) {
    //         bitSetMask |= DEMUX_PIN_C_MASK;
    //     }
    //     if ((pin % 4) >= 2) {
    //         bitSetMask |= DEMUX_PIN_B_MASK;
    //     }
    //     if ((pin % 2) == 1) {
    //         bitSetMask |= DEMUX_PIN_A_MASK;
    //     }
    //     nrf_gpio_port_out_set(DEMUX_NRF_PORT, bitSetMask);
    //     setPinValue(pin, value);
    // }
    return SYSTEM_ERROR_NONE;
}

uint8_t Demux::read(uint8_t pin) const {
    return getPinValue(pin);
}

Demux& Demux::getInstance() {
    static Demux demux;
    return demux;
}

int Demux::lock() {
    return mutex_.lock();
}

int Demux::unlock() {
    return mutex_.unlock();
}

void Demux::init() {
    nrf_gpio_port_dir_output_set(DEMUX_NRF_PORT, DEMUX_PIN_A_MASK | DEMUX_PIN_B_MASK | DEMUX_PIN_C_MASK);
    // Select Y0 by default.
    nrf_gpio_port_out_clear(DEMUX_NRF_PORT, DEMUX_PIN_A_MASK | DEMUX_PIN_B_MASK | DEMUX_PIN_C_MASK);
    initialized_ = true;
}

uint8_t Demux::getPinValue(uint8_t pin) const {
    return (pinValue_ >> pin) & 0x01;
}

void Demux::setPinValue(uint8_t pin, uint8_t value) {
    if (value) {
        pinValue_ |= (0x01 << pin);
    } else {
        // Only one pin is active 0 at a time
        pinValue_ = ~(0x01 << pin) & DEFAULT_PINS_VALUE;
    }
}

constexpr uint8_t Demux::DEFAULT_PINS_VALUE;

#endif // HAL_PLATFORM_DEMUX
