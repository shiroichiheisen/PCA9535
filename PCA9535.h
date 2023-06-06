#ifndef PCA9535_h
#define PCA9535_h

#include "Arduino.h"
#include <Wire.h>

class PCA9535
{
public:
	PCA9535(uint8_t PCAaddress, bool beginWire = false);
	uint8_t readInputGpioGroup0();
	uint8_t readInputGpioGroup1();
	uint8_t readOutputGpioGroup0();
	uint8_t readOutputGpioGroup1();
	void writeGpioGroup0(uint8_t groupValue);
	void writeGpioGroup1(uint8_t groupValue);
	uint8_t readInputPolarityGroup0();
	uint8_t readInputPolarityGroup1();
	void setPolarityInversionGroup0(uint8_t groupValue);
	void setPolarityInversionGroup1(uint8_t groupValue);
	uint8_t readConfigurationGroup0();
	uint8_t readConfigurationGroup1();
	void setConfigurationGroup0(uint8_t configuration);
	void setConfigurationGroup1(uint8_t configuration);

private:
	enum commandRegisters
	{
		inputP0 = 0,
		inputP1,
		outputP0,
		outputP1,
		polarityInversionP0,
		polarityInversionP1,
		configurationP0,
		configurationP1
	};

	uint8_t
		PCA9535Address,
		returnDataSize = 1;

	void writeI2c(uint8_t address, uint8_t data);
	void writeI2c(uint8_t address, uint8_t data, uint8_t data2);
	uint8_t readI2c(uint8_t address);

	TwoWire *wire;
};

#endif
