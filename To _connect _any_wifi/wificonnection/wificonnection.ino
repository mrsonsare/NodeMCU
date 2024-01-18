#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
WiFi.begin("My_Station","myhome@123");
Serial.begin(9600);
while(WiFi.status() != WL_CONNECTED)
{
  Serial.print("..");
  delay(200);
}
Serial.println();
Serial.println("NodeMCU is Connected !");
Serial.println(WiFi.localIP());

}

void loop() {
  
}
