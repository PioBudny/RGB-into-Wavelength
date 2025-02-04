#include "apds9960.h"

int apds9960_init(I2C_HandleTypeDef *hi2c) {
	HAL_StatusTypeDef status = HAL_OK;

	// Pyta o ID
	uint8_t id;
	status = HAL_I2C_Mem_Read(hi2c, APDS9960_ADDR, APDS9960_REG_ID, 1, &id, 1, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	if (id != 0xA8) return 2;

	// Odłącza zasilanie i resetuje
	uint8_t tx = 0;
	status = HAL_I2C_Mem_Write(hi2c, APDS9960_ADDR, APDS9960_REG_ENABLE, 1, &tx, 1, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	// Zasilanie/ALS/Przerwania
	tx = APDS9960_ENABLE_POWER | APDS9960_ENABLE_ALS | APDS9960_ENABLE_ALS_INT;
	status = HAL_I2C_Mem_Write(hi2c, APDS9960_ADDR, APDS9960_REG_ENABLE, 1, &tx, 1, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	// Czas integracji
	tx = APDS9960_INTEGRATION_TIME_100MS;
	status = HAL_I2C_Mem_Write(hi2c, APDS9960_ADDR, APDS9960_REG_ATIME, 1, &tx, 1, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	// wzmacnia odbierany sygnał
	tx = APDS9960_GAIN_16X;
	status = HAL_I2C_Mem_Write(hi2c, APDS9960_ADDR, APDS9960_REG_CONTROL, 1, &tx, 1, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	return 0;
}

uint8_t apds9960_read_status(I2C_HandleTypeDef *hi2c) { //odczytuje status
	uint8_t rx;
	HAL_I2C_Mem_Read(hi2c, APDS9960_ADDR, APDS9960_REG_STATUS, 1, &rx, 1, HAL_MAX_DELAY);

	return rx;
}

int apds9960_intr_clear(I2C_HandleTypeDef *hi2c) { //czyści przerwania
	uint8_t tx;
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, APDS9960_ADDR, APDS9960_REG_AICLEAR, 0, &tx, 0, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	return 0;
}

int apds9960_read_colors(I2C_HandleTypeDef *hi2c, uint16_t *r, uint16_t *g, uint16_t *b) {
	uint8_t rx[6];
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, APDS9960_ADDR, APDS9960_REG_RGBDATA_START, 1, &rx[0], 6, HAL_MAX_DELAY);
	if (status != HAL_OK) return 1;

	// łączenie bitów 2x8 -> 16
	*r = rx[0] | (rx[1] << 8);
	*g = rx[2] | (rx[3] << 8);
	*b = rx[4] | (rx[5] << 8);

	return 0;
}
