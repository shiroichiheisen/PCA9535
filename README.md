 # PCA9535 Library

This Arduino library provides a simple interface for interacting with the PCA9535 I/O expander. It allows for easy reading and writing to the GPIOs with additional control over polarity and configuration.
 ## Usage Instructions

Initialize the library with the I2C address of your PCA9535 chip and begin communication. Optionally, start the Wire library if it hasn't been started yet.
 ```cpp 

#include <PCA9535.h> // Make sure to include the PCA9535 library at the top of your sketch

// Define the I2C address for the PCA9535
uint8_t pcaAdress = 0x20;

// Create a PCA9535 object
PCA9535 pca(pcaAdress);
PCA9535 pca(pcaAdress, 1); // Initialize the library and optionally start the Wire library

void setup() {
// Setup configurations if necessary
}

void loop() {
// Reading input states from both GPIO groups
uint8_t inputGpio0 = pca.readInputGpioGroup0();
uint8_t inputGpio1 = pca.readInputGpioGroup1();

// Reading output states from both GPIO groups
uint8_t outputGpio0 = pca.readOutputGpioGroup0();
uint8_t outputGpio1 = pca.readOutputGpioGroup1();

// Reading polarity inversion registers from both GPIO groups
uint8_t polarityInversionGpio0 = pca.readPolarityInversionGroup0();
uint8_t polarityInversionGpio1 = pca.readPolarityInversionGroup1();

// Reading configuration registers from both GPIO groups
uint8_t configurationGpio0 = pca.readConfigurationGroup0();
uint8_t configurationGpio1 = pca.readConfigurationGroup1();

// Writing to output GPIO groups
pca.writeOutputGpioGroup0(uint8_t value);
pca.writeOutputGpioGroup1(uint8_t value);

// Writing to polarity inversion registers
pca.writePolarityInversionGroup0(uint8_t value);
pca.writePolarityInversionGroup1(uint8_t value);

// Writing to configuration registers
pca.writeConfigurationGroup0(uint8_t value);
pca.writeConfigurationGroup1(uint8_t value);
}
 ``` 

This library abstracts the intricacies of handling the PCA9535, providing straightforward methods for managing inputs, outputs, and configurations.
