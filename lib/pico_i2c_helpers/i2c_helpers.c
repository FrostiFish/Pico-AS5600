/*
 * File: i2c_helpers.c
 * Project: pico-as5600
 * -----
 * This source code is released under BSD-3 license.
 * Check LICENSE file for full license agreement.
 * Check COPYING for 3rd party licenses.
 * -----
 * Copyright 2025 H.Eikens (FrostiFish) & 2024 M.Kusiak (Timax)
 */

 #include "i2c_helpers.h"

 /**
 * @brief           Set GPIO function to I2C and set pull ups.
 *
 * @param sda    GPIO SDA pin.
 * @param scl    GPIO SCL pin.
 */
 void i2c_set_gpio(uint8_t sda, uint8_t scl) {
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);
 }

 /**
 * @brief i2c pin types.
 */
typedef enum {
    CLOCK,
    DATA
} gpio_i2c_t;

/**
 * @brief       Get gpio pin i2c type.
 *
 * @param gpio  gpio pin.
 * @return      i2c pin type.
 */
gpio_i2c_t get_gpio_i2c_type(uint8_t gpio)
{
    if (gpio % 2)
        return CLOCK;
    return DATA;
}

/**
 * @brief       Get i2c instance pointer.
 *
 * @param gpio  gpio pin.
 * @return      i2c instance pointer.
 */
i2c_inst_t* get_i2c_inst(uint8_t gpio)
{
    if ((gpio % 4) < 2)
        return i2c0;
    return i2c1;
}

/**
 * @brief       Get i2c instance number.
 *
 * @param gpio  gpio pin.
 * @return      i2c instance number.
 */
uint8_t get_i2c_num(uint8_t gpio)
{
    return (gpio / 2 % 2);
}
