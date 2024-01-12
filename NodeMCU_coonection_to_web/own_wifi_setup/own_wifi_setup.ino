#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led D5
String request ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.softAP("DarkMan","Hasup@05"); /// to setup own Wifi
Serial.println();
Serial.println("NodeMCU Strated");
Serial.println(WiFi.softAPIP());  //Own wifi IP Address 
server.begin();
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
client = server.available();

if (client == 1 )
{
request = client.readStringUntil('\n');
Serial.println(request);
request.trim();
}

if (request == "GET /ledon HTTP/1.1")
{
 digitalWrite(led,HIGH);
}

if (request == "GET /ledoff HTTP/1.1")
{
 digitalWrite(led,LOW);
}
 
}
