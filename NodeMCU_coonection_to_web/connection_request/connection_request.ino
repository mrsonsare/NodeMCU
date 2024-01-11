#include <ESP8266WiFi.h>

WiFiClient client;    //here client is a variable which can be anything 
WiFiServer server(80);

#define led D5
String request;

void setup() {
  Serial.begin(9600);
  WiFi.begin("My_Station","myhome@123");
  while(WiFi.status() != WL_CONNECTED)
  {
 delay(200);
 Serial.print("...");
  }
  Serial.println();
  Serial.println("NodeMCU is Connected ! ");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(led,OUTPUT);
}

void loop() {
  client = server.available();
  if (client == 1)
  {
     request = client.readStringUntil('\n');
    Serial.println(request);
    
    request.trim();

   if (request == "GET /ledon HTTP/1.1")
    {
       Serial.println("ledon");
        digitalWrite(D5,HIGH);
    }

   if (request == "GET /ledoff HTTP/1.1")
   {
     Serial.println("ledoff");
     digitalWrite(D5,LOW);
    }

  }

}
