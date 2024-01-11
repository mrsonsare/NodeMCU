#include <ESP8266WiFi.h>

WiFiClient client;    //here client is a variable which can be anything 
WiFiServer server(80);

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
}

void loop() {
  client = server.available();
  if (client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);

  }

}
