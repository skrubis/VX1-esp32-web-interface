#include "config.h"
#include <EEPROM.h>

// Initialize config.h variables
// I2C pins
int I2C_SDA = 21;
int I2C_SCL = 22;

// SD card pins
int SD_DAT0 = 2;
int SD_DAT1 = 4; 
int SD_DAT2 = 12;
int SD_DAT3 = 13;
int SD_CLK = 14;
int SD_CMD = 15;

Config::Config() {
}

void Config::load() {

    EEPROM.begin(sizeof(settings));
    EEPROM.get(0, settings);
    if (settings.version != EEPROM_VERSION) {
        //defaults
        settings.version = EEPROM_VERSION;
        settings.canRXPin = GPIO_NUM_26;
        settings.canTXPin = GPIO_NUM_25;
        settings.canEnablePin = 0;
    }
}
int Config::getCanRXPin() {
    return settings.canRXPin;
}

int Config::getCanTXPin() {
    return settings.canTXPin;
}

int Config::getCanEnablePin() {
    return settings.canEnablePin;
}


void Config::setCanEnablePin(int pin) {
    settings.canEnablePin = pin;
}

void Config::setCanTXPin(int pin) {
    settings.canTXPin = pin;
}

void Config::setCanRXPin(int pin) {
    settings.canRXPin = pin;
}

void Config::saveSettings() {
    EEPROM.put(0, settings); //save all change to eeprom
    EEPROM.commit();
}