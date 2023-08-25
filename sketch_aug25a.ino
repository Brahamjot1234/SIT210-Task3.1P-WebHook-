#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include "DHT.h"

char SSID[] = "iPhoneB";         
char PASW[] = "Jaanu1234";     
unsigned long channelId =2251783;   
const char *APIkey = "mwa0000030896461";

WiFiClient clients;
DHT dht(3, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting to WiFi: ");
    Serial.println(SSID);
    WiFi.begin(SSID, PASW);
    delay(1000);
  }

  Serial.println("WiFi Connected Succesfully");

  ThingSpeak.begin(clients);

}


void loop() {
  // put your main code here, to run repeatedly:
  float Temperature = dht.readTemperature();
  Serial.print("The Temprature");
  Serial.print(Temperature);
  Serial.println("Celcius");

  ThingSpeak.writeField(channelId, 1, Temperature, APIkey);
  Serial.print("Data sent succesfully: ");
  
  delay(30000);  
}
