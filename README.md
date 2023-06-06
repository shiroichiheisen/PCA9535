# PCA9535 Library

To use this library:

```
uint8_t pcaAdress = 0x20;

PCA9535 pca(Wire, pcaAdress);
PCA9535 pca(Wire, pcaAdress, 1); // to inicialize the library and start the wire library

void loop() {
  uint8_t inputGpio0 = pca.readInputGpioGroup0(); // read the input GPIO group 0
  uint8_t inputGpio1 = pca.readInputGpioGroup1(); // read the input GPIO group 1
  uint8_t outputGpio0 = pca.readOutputGpioGroup0(); // read the output GPIO group 0
  uint8_t outputGpio1 = pca.readOutputGpioGroup1(); // read the output GPIO group 1
  uint8_t polarityInversionGpio0 = pca.readPolarityInversionGroup0(); // read the polarity inversion group 0
  uint8_t polarityInversionGpio1 = pca.readPolarityInversionGroup1(); // read the polarity inversion group 1
  uint8_t configurationGpio0 = pca.readConfigurationGroup0(); // read the configuration group 0
  uint8_t configurationGpio1 = pca.readConfigurationGroup1(); // read the configuration group 1

  pca.writeOutputGpioGroup0(uint8_t value); // write the output GPIO group 0
  pca.writeOutputGpioGroup1(uint8_t value); // write the output GPIO group 1
  pca.writePolarityInversionGroup0(uint8_t value); // write the polarity inversion group 0
  pca.writePolarityInversionGroup1(uint8_t value); // write the polarity inversion group 1
  pca.writeConfigurationGroup0(uint8_t value); // write the configuration group 0
  pca.writeConfigurationGroup1(uint8_t value); // write the configuration group 1
}
```