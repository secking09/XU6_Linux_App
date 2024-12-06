#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <iomanip>

extern "C" {
#include "imx477.h" // Include the C header file
}

void WritetoSensor(const std::string& i2cBus, uint8_t deviceAddress, I2CReg SetofCommands[]) {
    int i = 0;

    std::cout << "Starting sensor initialization..." << std::endl;

    while (SetofCommands[i].regAddr != 0x0000 || SetofCommands[i].regData != 0x00) { // End marker assumed to be {0x0000, 0x00}
        uint16_t reg = SetofCommands[i].regAddr; // 2-byte register
        uint8_t value = SetofCommands[i].regData; // 1-byte value

        // Split the register into high and low bytes
        uint8_t regHigh = (reg >> 8) & 0xFF;
        uint8_t regLow = reg & 0xFF;

        // Combine the value with the low byte for i2cset
        uint16_t combinedValue = (static_cast<uint16_t>(value) << 8) | regLow;

        // Construct the i2cset command
        std::ostringstream command;
        command << "i2cset -y " << i2cBus << " 0x" << std::hex << std::setfill('0')
                    << std::setw(2) << static_cast<int>(deviceAddress) << " 0x"
                    << std::setw(2) << static_cast<int>(regHigh) << " 0x" << std::setw(4)
                    << combinedValue << " w";

        // Execute the command
        int result = std::system(command.str().c_str());
        if (result != 0) {
            std::cerr << "Error: Failed to write register 0x" << std::hex << reg << std::endl;
        } else {
            std::cout << "Command executed: " << command.str() << std::endl;
        }

        i++; // Move to the next entry
    }

    std::cout << "Sensor initialization complete." << std::endl;
}

int sanity() {
    int i = 0;

    std::cout << "Reading sensor_init array:" << std::endl;
    while (imx477_sensor_base_configuration_settings[i].regAddr != 0x00 || sensor_init[i].regData != 0x00) { // Loop until the end marker
        std::cout << "Register: 0x" << std::hex << static_cast<int>(sensor_init[i].regAddr)
                  << ", Value: 0x" << static_cast<int>(sensor_init[i].regData) << std::endl;
        i++;
    }

    std::cout << "Finished reading sensor_init array." << std::endl;
    return 0;
}
int main(int argc, char* argv[]) {



    std::string i2cBus = argv[1];      // I2C bus number
    uint8_t deviceAddress = std::stoi(argv[2], nullptr, 16);
    std::string command = argv[3];

    if (command == "configure"){
        WritetoSensor(i2cBus,deviceAddress,imx477_sensor_base_configuration_settings);
    }
    if (command == "raw"){
        WritetoSensor(i2cBus,deviceAddress,SENSOR_RAW8_1012x760_ConfigurationSettings);
    }
    if (command == "stream"){
        WritetoSensor(i2cBus,deviceAddress,SENSOR_START_STREAM);
    }
    if (command == "stop"){
        WritetoSensor(i2cBus,deviceAddress,SENSOR_STOP_STREAM);
    }
    if (command == "hi"){
        WritetoSensor(i2cBus,deviceAddress,sensor_init);
    }
    if (command == "exposure"){
        WritetoSensor(i2cBus,deviceAddress,INCREASE_EXPOSURE);
    }


    return 0;
}