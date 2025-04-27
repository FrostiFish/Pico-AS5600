/*
 * File: rp2040_i2c_assert.c
 * Project: pico-as5600
 * -----
 * This source code is released under BSD-3 license.
 * Check LICENSE file for full license agreement.
 * Check COPYING for 3rd party licenses.
 * -----
 * Generated with Chat-GPT4 2025 H.Eikens (FrostiFish)
 */

#pragma once

 #define IS_VALID_I2C_SDA(gpio) ( \
     (gpio) == 0  || (gpio) == 2  || (gpio) == 4  || (gpio) == 6  || \
     (gpio) == 8  || (gpio) == 10 || (gpio) == 12 || (gpio) == 14 || \
     (gpio) == 16 || (gpio) == 18 || (gpio) == 20 || (gpio) == 22 || \
     (gpio) == 24 || (gpio) == 26 || (gpio) == 28 )
 
 #define IS_VALID_I2C_SCL(gpio) ( \
     (gpio) == 1  || (gpio) == 3  || (gpio) == 5  || (gpio) == 7  || \
     (gpio) == 9  || (gpio) == 11 || (gpio) == 13 || (gpio) == 15 || \
     (gpio) == 17 || (gpio) == 19 || (gpio) == 21 || (gpio) == 23 || \
     (gpio) == 25 || (gpio) == 27 || (gpio) == 29 )
 
 #define GPIO_TO_I2C_NUM(gpio) ( \
     ((gpio) == 0  || (gpio) == 1  || \
      (gpio) == 4  || (gpio) == 5  || \
      (gpio) == 8  || (gpio) == 9  || \
      (gpio) == 12 || (gpio) == 13 || \
      (gpio) == 16 || (gpio) == 17 || \
      (gpio) == 20 || (gpio) == 21 || \
      (gpio) == 24 || (gpio) == 25 || \
      (gpio) == 28 || (gpio) == 29) ? 0 : 1)
    
#define GPIO_TO_I2C_INSTANCE(gpio) (I2C_INSTANCE(GPIO_TO_I2C_NUM(gpio)))
 
 #define ASSERT_I2C_CONFIG(SDA_PIN, SCL_PIN) \
     /* Check if SDA pin is valid */ \
     _Static_assert(IS_VALID_I2C_SDA(SDA_PIN), "Invalid SDA pin for I2C!"); \
     /* Check if SCL pin is valid */ \
     _Static_assert(IS_VALID_I2C_SCL(SCL_PIN), "Invalid SCL pin for I2C!"); \
     /* Check if they are same instance */ \
     _Static_assert(GPIO_TO_I2C_NUM(SDA_PIN) == GPIO_TO_I2C_NUM(SCL_PIN), "SDA and SCL must belong to the same I2C instance!");
 