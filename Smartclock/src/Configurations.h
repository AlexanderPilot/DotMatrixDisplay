/***************************************************************************
 * Header für die Konfiguarationen der Smartclock
 *
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/***************************************************************************
 * Versionierung der Smartclock
 * 
 * Version 1.0 wird vergeben,sobald die Smartclock initial funktioniert
 * 
 * Versionshistorie:
 * v1.0 Erstinbetriebnahme der Smartclock
 **************************************************************************/
#define VERSION "0.2"

/***************************************************************************
 * Einbinden von benötigten Bibliotheken
 **************************************************************************/
#include "WiFi.h"
#include <Arduino.h>

// Pin for LED control
#define LED_PIN 26

/***************************************************************************
 * Serielle Verbindung
 **************************************************************************/
#define SERIAL_SPEED 115200

/***************************************************************************
 * Debug Botschaften aktivieren/deaktivieren
 **************************************************************************/
#define DEBUG_PRINT

#ifdef DEBUG_PRINT
  #define _DEBUG_BEGIN(x)       Serial.begin(x);
  #define _DEBUG_PRINT(x)       Serial.print(x);
  #define _DEBUG_PRINTLN(x)     Serial.println(x);
  #define _DEBUG_WRITE(x)       Serial.write(x);
#else
  #define _DEBUG_BEGIN(x)
  #define _DEBUG_PRINT(x)
  #define _DEBUG_PRINTLN(x)
  #define _DEBUG_WRITE(x)
#endif

#define PRINT_SEPARATOR         "-------------------------"
#define PRINT_SEPARATOR_LONG    "--------------------------------------------------"


/***************************************************************************
 * WiFi Einstellungen
 **************************************************************************/
#define WIFI_MAX_TIME_CONNECTING    20  //max. Dauer, die gewartet wird bis Verbindungsaufbau abgebrochen wird

/***************************************************************************
 * NTP Server Einstellungen
 **************************************************************************/
#define NTP_SERVER_NAME     "pool.ntp.org"

/***************************************************************************
 * Bluetooth Einstellungen
 **************************************************************************/
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define BT_DEVICE_NAME    "Smartclock"
#define MAX_BT_CLIENTS    1
#define BT_PASSWORD       "1234"

/***************************************************************************
 * Spracheinstellungen
 **************************************************************************/
#define GERMAN 0

/***************************************************************************
 * I2C Einstellungen
 **************************************************************************/
/* Adresse fuer DS3231 */
#define DS3231_ADDRESS  0x68
#define SDA_PIN         21
#define SCL_PIN         22


/***************************************************************************
 * Timer Interrupt Einstellungen
 **************************************************************************/
//#define NTP_TIMER_VALUE_SEC 3600 //Aufruf der ISR und damit Synchronisation der Uhrzeit mit NTP Server alle Stunde
#define NTP_TIMER_VALUE_SEC 60 //für Testzwecke
#define TIMER_VALUE_MS 1000

