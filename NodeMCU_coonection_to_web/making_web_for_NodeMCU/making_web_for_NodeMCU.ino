#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led D5
#define led2 D4
String request ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin("My_Station","myhome@123");
while(WiFi.status() != WL_CONNECTED)
{

delay(200);
Serial.print("...");
}
Serial.println("NodeMCU is connected!");
Serial.println(WiFi.localIP());
server.begin();

pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

client = server.available();
if (client == 1)
{
request = client.readStringUntil('\n');

Serial.println(request);
request.trim();

if (request == "GET /ledon HTTP/1.1")
{
  digitalWrite(led,HIGH);
}

if (request == "GET /ledoff HTTP/1.1")
{
  digitalWrite(led,LOW);
}

if (request == "GET /led2on HTTP/1.1")
{
  digitalWrite(led2,HIGH);
}

if (request == "GET /led2off HTTP/1.1")
{
  digitalWrite(led2,LOW);
}

if (request == "GET /ledon HTTP/1.1")
{
  digitalWrite(led,HIGH);
}
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML");
client.println("<html>");
client.println("<h1> Welcome to the Webpage! <h1>");
client.println("<h3> LED CONTROLS <h3>");
client.println("<br>");
client.println("<a href=\"/ledon\"\"><button> LED 1 ON</button></a>");
client.println("<a href=\"/ledoff\"\"><button> LED 1 OFF</button></a><br/>");
client.println("<a href=\"/led2on\"\"><button> LED 2 ON</button></a>");
client.println("<a href=\"/led2off\"\"><button> LED 2 OFF</button></a><br/>");
client.println("</html>");

}
}
