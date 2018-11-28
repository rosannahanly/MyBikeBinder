#include <RH_ASK.h>
//sources of code
//http://www.theorycircuit.com/piezo-vibration-monitoring-sensor-arduino/
//https://www.arduinolab.net/rf-434mhz-ask-transmitter-and-receiver/


// tx/rx configuration
const int txSpeed = 2000;
const int rxPin = 5;
const int txPin = 6;
const int pttPin = 7;

int piezo_Pin= 0;
int LED_Pin= 13;

//Set the threshold levels
int threshold= 700;

 
RH_ASK driver(txSpeed, rxPin, txPin, pttPin);
 
void setup()
{
  Serial.begin(9600);
  pinMode(LED_Pin, OUTPUT);
  if (!driver.init())
    Serial.println("rf driver init failed");
 
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop()
{
  int reading= analogRead(piezo_Pin);
  Serial.println(reading);
  if (reading > threshold){
    const char *msg = "hello ben!";
 
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    // time to send a message
    delay(3000);
  }
  
}
