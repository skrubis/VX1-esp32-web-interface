#ifndef CONFIG_H
#define CONFIG_H

#define EEPROM_VERSION 3
typedef struct {
    int version;
    int canRXPin;
    int canTXPin;
    int canEnablePin;
    char wifiSSID1[32];
    char wifiPassword1[64];
    char wifiSSID2[32];
    char wifiPassword2[64];
    bool wifiEnabled;
    int wifiRetryInterval; // seconds between retry attempts
} EEPROMSettings;

// I2C pins
extern int I2C_SDA;
extern int I2C_SCL;

// SD card pins
extern int SD_DAT0;
extern int SD_DAT1;
extern int SD_DAT2;
extern int SD_DAT3;
extern int SD_CLK;
extern int SD_CMD;

// I2C GPIO EXPANDER (MCP23017)
#define GPIO_EXPANDER_ADDR 0x26
#define GPIO_EXPANDER_INT_PIN 33

// Expander GPIO definitions - Adafruit MCP23017 library format
// PORT A (pins 0-7)
#define RELAY_1_GPIO     0 // GPA0
#define RELAY_2_GPIO     1 // GPA1
#define MOSFET_SWITCH_1  2 // GPA2
#define MOSFET_SWITCH_2  3 // GPA3
#define MOSFET_SWITCH_3  4 // GPA4
#define MOSFET_SWITCH_4  5 // GPA5
#define VSPI_CAN1_RESET  6 // GPA6
#define VSPI_CAN2_RESET  7 // GPA7
// PORT B (pins 8-15)
#define VSPI_CAN1_CS     8  // GPB0
#define VSPI_CAN2_CS     9  // GPB1
#define GPS_LDO_EN       10 // GPB2
#define LTE_POWERKEY     11 // GPB3
#define LTE_GPIO5        12 // GPB4
#define VSPI_CAN2_INT    13 // GPB5
#define VSPI_CAN1_INT    14 // GPB6
#define EXT_GPIO         15 // GPB7

// LTE MODEM (SIM7070G)
#define LTE_DTR 35
#define LTE_TX 17
#define LTE_RX 27

// TWAI CAN BUS - Used for BMS communication
#define TWAI_TX 25
#define TWAI_RX 26

// SPI BUS
#define VSPI_MOSI 23
#define VSPI_SCK 18
#define VSPI_MISO 19

// Additional pins
#define IGNITION_SIGNAL_PIN 34
#define ACCEL_GYRO_INT_PIN 39

class Config
{
  public:
    Config();
    void load();
    int getCanRXPin();
    void setCanRXPin(int pin);

    int getCanTXPin();
    void setCanTXPin(int pin);


    int getCanEnablePin();
    void setCanEnablePin(int pin);

    // WiFi configuration methods
    const char* getWifiSSID1();
    const char* getWifiPassword1();
    const char* getWifiSSID2();
    const char* getWifiPassword2();
    bool getWifiEnabled();
    int getWifiRetryInterval();
    
    void setWifiSSID1(const char* ssid);
    void setWifiPassword1(const char* password);
    void setWifiSSID2(const char* ssid);
    void setWifiPassword2(const char* password);
    void setWifiEnabled(bool enabled);
    void setWifiRetryInterval(int interval);

    void saveSettings();
  private:
    EEPROMSettings settings;

};
#endif