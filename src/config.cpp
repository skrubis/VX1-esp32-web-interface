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
        strcpy(settings.wifiSSID1, "");
        strcpy(settings.wifiPassword1, "");
        strcpy(settings.wifiSSID2, "");
        strcpy(settings.wifiPassword2, "");
        settings.wifiEnabled = true;
        settings.wifiRetryInterval = 30; // 30 seconds default
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

// WiFi configuration getters
const char* Config::getWifiSSID1() {
    return settings.wifiSSID1;
}

const char* Config::getWifiPassword1() {
    return settings.wifiPassword1;
}

const char* Config::getWifiSSID2() {
    return settings.wifiSSID2;
}

const char* Config::getWifiPassword2() {
    return settings.wifiPassword2;
}

bool Config::getWifiEnabled() {
    return settings.wifiEnabled;
}

int Config::getWifiRetryInterval() {
    return settings.wifiRetryInterval;
}

// WiFi configuration setters
void Config::setWifiSSID1(const char* ssid) {
    strncpy(settings.wifiSSID1, ssid, sizeof(settings.wifiSSID1) - 1);
    settings.wifiSSID1[sizeof(settings.wifiSSID1) - 1] = '\0';
}

void Config::setWifiPassword1(const char* password) {
    strncpy(settings.wifiPassword1, password, sizeof(settings.wifiPassword1) - 1);
    settings.wifiPassword1[sizeof(settings.wifiPassword1) - 1] = '\0';
}

void Config::setWifiSSID2(const char* ssid) {
    strncpy(settings.wifiSSID2, ssid, sizeof(settings.wifiSSID2) - 1);
    settings.wifiSSID2[sizeof(settings.wifiSSID2) - 1] = '\0';
}

void Config::setWifiPassword2(const char* password) {
    strncpy(settings.wifiPassword2, password, sizeof(settings.wifiPassword2) - 1);
    settings.wifiPassword2[sizeof(settings.wifiPassword2) - 1] = '\0';
}

void Config::setWifiEnabled(bool enabled) {
    settings.wifiEnabled = enabled;
}

void Config::setWifiRetryInterval(int interval) {
    settings.wifiRetryInterval = interval;
}

void Config::saveSettings() {
    EEPROM.put(0, settings); //save all change to eeprom
    EEPROM.commit();
}