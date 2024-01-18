//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Set these to run example.
#define FIREBASE_HOST "nodemcu-ab5ac-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "VAxSD0GVKiGNxJ2PjHAkuJdyTDdMzbuHDasTlx31"
#define WIFI_SSID "My_Station"
#define WIFI_PASSWORD "myhome@123"
#define led D5

float randNumber1;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("led",0);
}

int ledDb ;

void loop() {

ledDb = Firebase.getInt("led");

randNumber1 = random(10);
Serial.println(randNumber1);



}