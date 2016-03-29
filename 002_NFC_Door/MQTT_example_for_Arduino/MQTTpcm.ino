/***************************************************
  This is an MQTT publish example for the Adafruit CC3000 Wifi Breakout & Shield (https://www.adafruit.com/products/1469).
  
  This script uses some of the methods from the buildtest example for CC3000 that Limor Fried, Kevin Townsend and Phil Burgess 
  wrote for Adafruit Industries to make debugging easier.
 ****************************************************/
 /**********************************************************
  * 2016-03-28 Modified by ChanMin
  * Publish Temp Info. ( drvs/pcm/temp )
  **********************************************************/

#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <cc3000_PubSubClient.h>

// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   7

// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10

// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11
Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT, SPI_CLOCK_DIVIDER);

#define WLAN_SSID       "your Wifi ssid"
#define WLAN_PASS       "your Wifi password"

// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

Adafruit_CC3000_Client client;

int tempPin=3;
int tempInfo;
char tempStr[5];

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

uint32_t server = cc3000.IP2U32( your, broker, ip, address );//ex.(192, 168, 0, 123)
cc3000_PubSubClient mqttclient(server, 1883, callback, client, cc3000);

void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("Hello, CC3000!\n"));

  displayDriverMode();
  
  Serial.println(F("\nInitialising the CC3000 ..."));
  if (!cc3000.begin()) {
    Serial.println(F("Unable to initialise the CC3000! Check your wiring?"));
    for(;;);
  }

  uint16_t firmware = checkFirmwareVersion();
  if (firmware < 0x113) {
    Serial.println(F("Wrong firmware version!"));
    for(;;);
  } 

//  uint16_t firmware = checkFirmwareVersion();
//  if ((firmware != 0x113) && (firmware != 0x118)) {
//    Serial.println(F("Wrong firmware version!"));
//    for(;;);
//  }
  
  displayMACAddress();
  
  Serial.println(F("\nDeleting old connection profiles"));
  if (!cc3000.deleteProfiles()) {
    Serial.println(F("Failed!"));
    while(1);
  }

  /* Attempt to connect to an access point */
  char *ssid = WLAN_SSID;             /* Max 32 chars */
  Serial.print(F("\nAttempting to connect to ")); Serial.println(ssid);
  
  /* NOTE: Secure connections are not available in 'Tiny' mode! */
  if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println(F("Failed!"));
    while(1);
  }
   
  Serial.println(F("Connected!"));
  
  /* Wait for DHCP to complete */
  Serial.println(F("Request DHCP"));
  while (!cc3000.checkDHCP()) {
    delay(100); // ToDo: Insert a DHCP timeout!
  }

  /* Display the IP address DNS, Gateway, etc. */  
  while (!displayConnectionDetails()) {
    delay(1000);
  }
   
   // connect to the broker
   if (!client.connected()) {
     Serial.println(F("Create Connection"));
     //client = cc3000.connectTCP(server.ip, 1883);
     client = cc3000.connectTCP(server, 1883);
   }
   
   // did that last thing work? sweet, let's do something
   if(client.connected()) {
    Serial.println(F("Prepare Pub"));
    if (mqttclient.connect("PCM")) {
      Serial.println(F("Pub"));
      mqttclient.publish("drvs/pcm/temp","is now online");
    }
   }

   pinMode(tempPin, INPUT);
}

void loop(void) {

  //tempInfo = digitalRead(tempPin);
  tempInfo = analogRead(0);
  Serial.println(TempTrans(tempInfo));

  // are we still connected?
  if (!client.connected()) {
     client = cc3000.connectTCP(server, 1883);
     
     if(client.connected()) {
       if (mqttclient.connect("PCM")) {
          String(TempTrans(tempInfo)).toCharArray(tempStr,5);
          mqttclient.publish("drvs/pcm/temp", tempStr);
       }
     } 
  } else {
    // yep, publish that test
    String(TempTrans(tempInfo)).toCharArray(tempStr,5);
    mqttclient.publish("drvs/pcm/temp", tempStr);
  }

  delay(5000);
}

double TempTrans(int raw)
{
  double temp;
  temp = log(((10240000/raw)-10000));
  temp = 1/(0.001129148+(0.000234125+(0.0000000876741 * temp*temp))*temp);
  temp = temp-273.15;
  return temp;
}


/**************************************************************************/
/*!
    @brief  Displays the driver mode (tiny of normal), and the buffer
            size if tiny mode is not being used

    @note   The buffer size and driver mode are defined in cc3000_common.h
*/
/**************************************************************************/
void displayDriverMode(void)
{
  #ifdef CC3000_TINY_DRIVER
    Serial.println(F("CC3000 is configure in 'Tiny' mode"));
  #else
    Serial.print(F("RX Buffer : "));
    Serial.print(CC3000_RX_BUFFER_SIZE);
    Serial.println(F(" bytes"));
    Serial.print(F("TX Buffer : "));
    Serial.print(CC3000_TX_BUFFER_SIZE);
    Serial.println(F(" bytes"));
  #endif
}

/**************************************************************************/
/*!
    @brief  Tries to read the CC3000's internal firmware patch ID
*/
/**************************************************************************/
uint16_t checkFirmwareVersion(void)
{
  uint8_t major, minor;
  uint16_t version;
  
#ifndef CC3000_TINY_DRIVER  
  if(!cc3000.getFirmwareVersion(&major, &minor))
  {
    Serial.println(F("Unable to retrieve the firmware version!\r\n"));
    version = 0;
  }
  else
  {
    Serial.print(F("Firmware V. : "));
    Serial.print(major); Serial.print(F(".")); Serial.println(minor);
    version = major; version <<= 8; version |= minor;
  }
#endif
  return version;
}

/**************************************************************************/
/*!
    @brief  Tries to read the 6-byte MAC address of the CC3000 module
*/
/**************************************************************************/
void displayMACAddress(void)
{
  uint8_t macAddress[6];
  
  if(!cc3000.getMacAddress(macAddress))
  {
    Serial.println(F("Unable to retrieve MAC Address!\r\n"));
  }
  else
  {
    Serial.print(F("MAC Address : "));
    cc3000.printHex((byte*)&macAddress, 6);
  }
}


/**************************************************************************/
/*!
    @brief  Tries to read the IP address and other connection details
*/
/**************************************************************************/
bool displayConnectionDetails(void)
{
  uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;
  
  if(!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv, &dnsserv))
  {
    Serial.println(F("Unable to retrieve the IP Address!\r\n"));
    return false;
  }
  else
  {
    Serial.print(F("\nIP Addr: ")); cc3000.printIPdotsRev(ipAddress);
    Serial.print(F("\nNetmask: ")); cc3000.printIPdotsRev(netmask);
    Serial.print(F("\nGateway: ")); cc3000.printIPdotsRev(gateway);
    Serial.print(F("\nDHCPsrv: ")); cc3000.printIPdotsRev(dhcpserv);
    Serial.print(F("\nDNSserv: ")); cc3000.printIPdotsRev(dnsserv);
    Serial.println();
    return true;
  }
}
