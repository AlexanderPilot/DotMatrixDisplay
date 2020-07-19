// REQUIRES the following Arduino libraries:
// DHT11 library (DHT11) found at https://github.com/winlinvip/SimpleDHT
// - MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
// - Programming ESP32 with Arduino IDE: https://www.youtube.com/watch?v=9b0Txt-yF7E
// Find All "Great Projects" Videos : https://www.youtube.com/channel/UCCC8DuqicBtP3A_aC53HYDQ/videos

// Header file includes
#include <WiFi.h>
//#include <time.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

//#include "SimpleDHT.h"  
#include "Font_Data.h"

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 16

#define CLK_PIN   18 // or SCK
#define DATA_PIN  19 // or MOSI
#define CS_PIN    5 // or SS


// DHT config.
//int pinDHT11 = 23;
//SimpleDHT11 dht11(pinDHT11);

// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

#define SPEED_TIME  30
#define PAUSE_TIME  0
#define MAX_MESG  300

int timezone = 0;
int dst = 0;
const char* ssid = "OnLine";
const char* password = "Br8#Pojg56";
char Message[MAX_MESG+1] = { "Text1" };
char szMesg[MAX_MESG+1] = { "Text2" };
//char WeatherTh[MAX_MESG+1] = "";
/*
uint16_t  h, m, s;
uint8_t dow;
int  day;
uint8_t month;
String  year;

// Global variables
char szTime[9];    // mm:ss\0
char szsecond[4];    // ss


uint8_t degC[] = { 6, 3, 3, 56, 68, 68, 68 }; // Deg C

char *mon2str(uint8_t mon, char *psz, uint8_t len)
// Get a label from PROGMEM into a char array
{
  static const char str[][4] PROGMEM =
  {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  *psz = '\0';
  mon--;
  if (mon < 12)
  {
    strncpy_P(psz, str[mon], len);
    psz[len] = '\0';
  }

  return(psz);
}

char *dow2str(uint8_t code, char *psz, uint8_t len)
{
  static const char str[][10] PROGMEM =
  {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
  };

  *psz = '\0';
  code--;
  if (code < 7)
  {
    strncpy_P(psz, str[code], len);
    psz[len] = '\0';
  }

  return(psz);
}
void getsec(char *psz)
// Code for reading clock date
{
  sprintf(psz, "%02d", s);
}
void getTime(char *psz, bool f = true)
// Code for reading clock time
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
      h = p_tm->tm_hour;
      m = p_tm->tm_min;
      s = p_tm->tm_sec;
  sprintf(psz, "%02d%c%02d", h, (f ? ':' : ' '), m);
}

void getDate(char *psz)
// Code for reading clock date
{
  char  szBuf[10];
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
      dow = p_tm->tm_wday+1;
      day = p_tm->tm_mday;
      month = p_tm->tm_mon + 1;
  sprintf(psz, "%d %s %04d", day, mon2str(month, szBuf, sizeof(szBuf)-1), (p_tm->tm_year + 1900));
}
void getHumidit(char *psz)
// Code for reading clock date
{   
        strcpy(szMesg, "Humidity : ");
          dtostrf(hu, 3, 1, WeatherTh);
          strcat(szMesg, WeatherTh);
          strcat(szMesg, " % RH");
}
void getTemperatur(char *psz)
// Code for reading clock date
{
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    delay(100);
    return;
  }
        float t = ((int)temperature);
        float  hu = ((int)humidity);
        strcpy(szMesg, "Temperature : ");
          dtostrf(t, 3, 1, WeatherTh);
          strcat(szMesg, WeatherTh);
          strcat(szMesg, " $");
}

void getTimentp()
{

  configTime(timezone * 3600, dst, "pool.ntp.org","time.nist.gov");

  while(!time(nullptr)){
        delay(500);
        Serial.print(".");
  }
        Serial.print("Time Update");
}

*/

void setup(void)
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  delay(3000);
  //getTimentp();
  P.begin(0);
  P.setInvert(false);

  P.setZone(0, 0, 11);
  //P.setZone(1, 12, 12);
  //P.setZone(2, 13, 15);
  //P.setFont(1, numeric7Seg);
  //P.setFont(2, numeric7Se);
  P.displayZoneText(0, Message, PA_CENTER, SPEED_TIME, 0, PA_PRINT, PA_SCROLL_LEFT);
  //P.displayZoneText(1, szsecond, PA_LEFT, SPEED_TIME, 0, PA_PRINT, PA_NO_EFFECT);
  //P.displayZoneText(2, szTime, PA_CENTER, SPEED_TIME, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT);

  //P.addChar('$', degC);
  //getDate(szMesg);
  //getTime(szTime);
}

void loop(void)
{
  //static uint32_t lastTime = 0; // millis() memory
  static uint8_t  display = 0;  // current display mode
  //static bool flasher = false;  // seconds passing flasher

  P.displayAnimate();

  if (P.getZoneStatus(0))
  {
    switch (display)
    {
/*
      case 0: // Temperature deg C
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display++;
        dow2str(dow, szMesg, MAX_MESG);
        break;

      case 1: // Relative Humidity
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display++;
        //getDate(szMesg);
        break;

      case 2: // day of week
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display++;
        //getTemperatur(szMesg);
        break;

      case 3:  // Calendar
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display++;
        //getHumidit(szMesg);
        break;
*/
      default: // Relative Humidity
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        strcpy(szMesg, Message);
        display = 0;
        break;
    }

    P.displayReset(0);
  }
/*
  // Finally, adjust the time string if we have to
  if (millis() - lastTime >= 1000)
  {
    lastTime = millis();
    getsec(szsecond);
    getTime(szTime, flasher);
    flasher = !flasher;

    P.displayReset(1);
    P.displayReset(2);
  }
  */
}


