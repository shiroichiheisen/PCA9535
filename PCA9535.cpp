#include "Arduino.h"
#include "PCA9535.h"

PCA9535::PCA9535(uint8_t PCAaddress, bool beginWire)
{
  PCA9535Address = PCAaddress;
  if (beginWire)
    Wire.begin();
}

void PCA9535::writeI2c(uint8_t address, uint8_t data)
{
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.endTransmission();
}

void PCA9535::writeI2c(uint8_t address, uint8_t data, uint8_t data2)
{
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.write(data2);
  Wire.endTransmission();
}

uint8_t PCA9535::readI2c(uint8_t address)
{
  Wire.requestFrom(address, returnDataSize);
  return Wire.read();
}

uint8_t PCA9535::readInputGpioGroup0()
{
  writeI2c(PCA9535Address, inputP0);
  return readI2c(PCA9535Address);
}

uint8_t PCA9535::readInputGpioGroup1()
{
  writeI2c(PCA9535Address, inputP1);
  return readI2c(PCA9535Address);
}

uint8_t PCA9535::readOutputGpioGroup0()
{
  writeI2c(PCA9535Address, outputP0);
  return readI2c(PCA9535Address);
}

uint8_t PCA9535::readOutputGpioGroup1()
{
  writeI2c(PCA9535Address, outputP1);
  return readI2c(PCA9535Address);
}

void PCA9535::writeGpioGroup0(uint8_t groupValue)
{
  writeI2c(PCA9535Address, outputP0, groupValue);
}

void PCA9535::writeGpioGroup1(uint8_t groupValue)
{
  writeI2c(PCA9535Address, outputP1, groupValue);
}

uint8_t PCA9535::readInputPolarityGroup0()
{
  writeI2c(PCA9535Address, polarityInversionP0);
  return readI2c(PCA9535Address);
}

uint8_t PCA9535::readInputPolarityGroup1()
{
  writeI2c(PCA9535Address, polarityInversionP1);
  return readI2c(PCA9535Address);
}

void PCA9535::setPolarityInversionGroup0(uint8_t groupValue)
{
  writeI2c(PCA9535Address, polarityInversionP0, groupValue);
}

void PCA9535::setPolarityInversionGroup1(uint8_t groupValue)
{
  writeI2c(PCA9535Address, polarityInversionP1, groupValue);
}

uint8_t PCA9535::readConfigurationGroup0()
{
  writeI2c(PCA9535Address, configurationP0);
  return readI2c(PCA9535Address);
}

uint8_t PCA9535::readConfigurationGroup1()
{
  writeI2c(PCA9535Address, configurationP1);
  return readI2c(PCA9535Address);
}

void PCA9535::setConfigurationGroup0(uint8_t configuration)
{
  writeI2c(PCA9535Address, configurationP0, configuration);
}

void PCA9535::setConfigurationGroup1(uint8_t configuration)
{
  writeI2c(PCA9535Address, configurationP1, configuration);
}
