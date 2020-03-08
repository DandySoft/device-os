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

#include "pinmap_hal.h"

#if PLATFORM_ID == PLATFORM_TRACKER

static Hal_Pin_Info s_pin_map[TOTAL_PINS] = {
/* User space */
/* D0            - 00 */ { NRF_PORT_0, 3,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 0,                 0,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D1            - 01 */ { NRF_PORT_0, 2,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 0,                 1,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D2            - 02 */ { NRF_PORT_0, 29, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 0,                 2,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D3            - 03 */ { NRF_PORT_0, 31, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 0,                 3,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D4            - 04 */ { NRF_PORT_0, 30, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 1,                 0,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D5            - 05 */ { NRF_PORT_0, 28, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 1,                 1,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D6            - 06 */ { NRF_PORT_0, 4,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 1,                 2,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D7            - 07 */ { NRF_PORT_0, 5,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 1,                 3,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D8            - 08 */ { NRF_PORT_0, 6,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 2,                 0,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* D9            - 09 */ { NRF_PORT_0, 8,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 2,                 1,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},

/* System space */
/* RGBR          - 10 */ { NRF_PORT_1, 6,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 3,                 1,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* RGBG          - 11 */ { NRF_PORT_1, 5,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 3,                 2,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* RGBB          - 12 */ { NRF_PORT_1, 3,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, 3,                 3,                8, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* MODE BUTTON   - 13 */ { NRF_PORT_1, 12, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* SDA1          - 14 */ { NRF_PORT_0, 11, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* SCL1          - 15 */ { NRF_PORT_0, 12, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* SCK1          - 16 */ { NRF_PORT_1, 4,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* MOSI1         - 17 */ { NRF_PORT_1, 2,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* MISO1         - 18 */ { NRF_PORT_1, 1,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* TX1           - 19 */ { NRF_PORT_0, 16, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* RX1           - 20 */ { NRF_PORT_0, 15, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* RTS1          - 21 */ { NRF_PORT_0, 14, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* CTS1          - 22 */ { NRF_PORT_0, 13, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* PMIC_INT      - 23 */ { NRF_PORT_0, 26, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* RTC_INT       - 24 */ { NRF_PORT_0, 27, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* BGRST         - 25 */ { NRF_PORT_0, 7,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* BGPWR         - 26 */ { NRF_PORT_1, 8,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* BGVINT        - 27 */ { NRF_PORT_1, 14, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* CAN_INT       - 28 */ { NRF_PORT_1, 9,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* IOE_INT       - 29 */ { NRF_PORT_0, 24, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* IOE_RST       - 30 */ { NRF_PORT_0, 25, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* SEN_INT       - 31 */ { NRF_PORT_1, 7,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* NFC1          - 32 */ { NRF_PORT_0, 9,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* NFC2          - 33 */ { NRF_PORT_0, 10, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* DEMUX_C       - 34 */ { NRF_PORT_1, 10, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* DEMUX_B       - 35 */ { NRF_PORT_1, 11, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* DEMUX_A       - 36 */ { NRF_PORT_1, 13, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* BLE_ANT_SW    - 37 */ { NRF_PORT_1, 15, PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_MCU},
/* WIFI_EN       - 38 */ { NRF_PORT_0, 0,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* WIFI_INT      - 39 */ { NRF_PORT_0, 1,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* WIFI_BOOT     - 40 */ { NRF_PORT_0, 2,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* BGDTR         - 41 */ { NRF_PORT_0, 3,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* RTC_WDI       - 42 */ { NRF_PORT_0, 4,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* LOW_BAT_UC    - 43 */ { NRF_PORT_0, 5,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* GPS_PWR       - 44 */ { NRF_PORT_0, 6,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* GPS_INT       - 45 */ { NRF_PORT_0, 7,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* GPS_BOOT      - 46 */ { NRF_PORT_1, 0,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* GPS_RST       - 47 */ { NRF_PORT_1, 1,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_RST       - 48 */ { NRF_PORT_1, 2,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_PWR       - 49 */ { NRF_PORT_1, 3,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_STBY      - 50 */ { NRF_PORT_1, 4,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_RTS2      - 51 */ { NRF_PORT_1, 5,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_RTS1      - 52 */ { NRF_PORT_1, 6,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* CAN_RTS0      - 53 */ { NRF_PORT_1, 7,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_IO_EXPANDER},
/* GPS_CS        - 54 */ { NRF_PORT_0, 1,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_DEMUX},
/* IOE_CS        - 55 */ { NRF_PORT_0, 2,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_DEMUX},
/* SEN_CS        - 56 */ { NRF_PORT_0, 3,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_DEMUX},
/* WIFI_CS       - 57 */ { NRF_PORT_0, 4,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_DEMUX},
/* CAN_CS        - 58 */ { NRF_PORT_0, 5,  PIN_MODE_NONE, PF_NONE, ADC_CHANNEL_NONE, PWM_INSTANCE_NONE, PWM_CHANNEL_NONE, 0, EXTI_CHANNEL_NONE, HAL_PIN_TYPE_DEMUX},
};

const uint8_t NRF_PIN_LOOKUP_TABLE[48] = {
    /* P0.00     P0.01        P0.02        P0.03        P0.04        P0.05        P0.06        P0.07*/
    PIN_INVALID, PIN_INVALID, 1,           0,           6,           7,           8,           25,           /* P0.00 ~ P0.07 */
    /* P0.08     P0.09        P0.10        P0.11        P0.12        P0.13        P0.14        P0.15*/
    9,           32,          33,          14,          15,          22,          21,          20,           /* P0.08 ~ P0.15 */
    /* P0.16     P0.17        P0.18        P0.19        P0.20        P0.21        P0.22        P0.23*/
    19,          PIN_INVALID, PIN_INVALID, PIN_INVALID, PIN_INVALID, PIN_INVALID, PIN_INVALID, PIN_INVALID,  /* P0.16 ~ P0.23 */
    /* P0.24     P0.25        P0.26        P0.27        P0.28        P0.29        P0.30        P0.31*/
    29,          30,          23,          24,          5,           2,           4,           3,            /* P0.24 ~ P0.31 */
    /* P1.00     P1.01        P1.02        P1.03        P1.04        P1.05        P1.06        P1.07*/
    PIN_INVALID, 18,          17,          12,          16,          11,          10,          31,           /* P1.00 ~ P1.07 */
    /* P1.08     P1.09        P1.10        P1.11        P1.12        P1.13        P1.14        P1.15*/
    26,          28,          34,          35,          13,          36,           27,          37,            /* P1.08 ~ P1.15 */
};

#endif // PLATFORM_ID == PLATFORM_TRACKER


Hal_Pin_Info* HAL_Pin_Map(void) {
    return s_pin_map;
}