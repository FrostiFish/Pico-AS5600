/*
 * File: i2c_helpers.h
 * Project: pico-as5600
 * -----
 * This source code is released under BSD-3 license.
 * Check LICENSE file for full license agreement.
 * Check COPYING for 3rd party licenses.
 * -----
 * Copyright 2025 H.Eikens (FrostiFish) & 2024 M.Kusiak (Timax)
 */

#ifndef I2C_HELPERS_H
#define I2C_HELPERS_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "rp2040_i2c_assert_config.h"

// Functions

void i2c_set_gpio(uint8_t sda, uint8_t scl);
uint8_t get_i2c_num(uint8_t gpio);

#endif