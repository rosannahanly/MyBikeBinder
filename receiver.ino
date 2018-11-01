#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
 
// tx/rx configuration
const int txSpeed = 2000;
const int rxPin = 5;
const int txPin = 6;
const int pttPin = 7;
const int buzzer = A1; //buzzer to arduino pin 9
//const int PIEZO_PIN = A1; // Piezo output 
RH_ASK driver(txSpeed, rxPin, txPin, pttPin);
 
void setup()
{
  Serial.begin(9600);  // Debugging only
  pinMode(buzzer, OUTPUT);
  if (!driver.init())
    Serial.println("init failed");
}
 
void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN] = {0};
  uint8_t buflen = sizeof(buf);
 
  if (driver.recv(buf, &buflen)) // if message received, save it
  {
      tone(buzzer, 440);
      delay(1000);
      tone(buzzer, 880);// Send 1KHz sound signal...
      delay(1000);  
    Serial.println((char*)buf); // print received message
  }
}
