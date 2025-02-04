#pragma once

#include "stm32f4xx_hal.h"
#include <stdbool.h>

int apds9960_init(I2C_HandleTypeDef *hi2c);
uint8_t apds9960_read_status(I2C_HandleTypeDef *hi2c);
int apds9960_read_colors(I2C_HandleTypeDef *hi2c, uint16_t *r, uint16_t *g, uint16_t *b);

#define APDS9960_ADDR (0x39 << 1)

#define APDS9960_REG_ID 0x92
#define APDS9960_REG_ENABLE 0x80
#define APDS9960_REG_ATIME 0x81
#define APDS9960_REG_STATUS 0x93
#define APDS9960_REG_CONTROL 0x8F
#define APDS9960_REG_RGBDATA_START 0x96
#define APDS9960_REG_AICLEAR 0xE7

#define APDS9960_ID 0xA8

#define APDS9960_ENABLE_POWER (1 << 0)
#define APDS9960_ENABLE_ALS (1 << 1)
#define APDS9960_ENABLE_ALS_INT (1 << 4)

#define APDS9960_INTEGRATION_TIME_100MS 0xDB

#define APDS9960_GAIN_16X 0x3
