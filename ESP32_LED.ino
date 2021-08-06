#include <WiFi.h> 
#include <ArduinoJson.h> 
#include <HTTPClient.h> 
int led1 = 12;
int led2 = 13;
int led3 = 14;
int led4 = 27;
int led5 = 19;
int led6 = 23;
// WIFI-Zugangsdaten
const char* ssid = "Ayush";
const char* password =  "ayush2015";

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);        
  Serial.begin(115200);
  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  delay(1000);
  Serial.println("Hello, world!");
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) {

    HTTPClient http; //Instance of HTTPClient
    http.begin("https://dashboard-ayush.000webhostapp.com/pinout.php"); 
    int httpCode = http.GET(); //Answer of the server

    if (httpCode == 200) {
      String payload = http.getString(); //Save data in variable
      const size_t capacity = JSON_ARRAY_SIZE(5) + 5 * JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + 200;
      DynamicJsonDocument doc(capacity);
      deserializeJson(doc, payload);
      int p1 = doc["p1"];
      int p2 = doc["p2"];
      int p3 = doc["p3"];
      int p4 = doc["p4"];
      int p5 = doc["p5"];
      int p6 = doc["p6"];
      Serial.print("p1 = ");
      Serial.print(p1);
      Serial.print(" ");
      Serial.print("p2 = ");
      Serial.println(p2);
      Serial.print(" ");
      Serial.print("p3 = ");
      Serial.print(p3);
      Serial.print(" ");
      Serial.print("p4 = ");
      Serial.print(p4);
      Serial.print(" ");
      Serial.print("p5 = ");
      Serial.print(p5);
      Serial.print(" ");
      Serial.print("p6 = ");
      Serial.print(p6);
      Serial.print(" "); 

     if(p1==1){
      digitalWrite(led1,1);
     }
     else{
      digitalWrite(led1,0);
     }

          if(p2==1){
      digitalWrite(led2,1);
     }
     else{
      digitalWrite(led2,0);
     }

          if(p3==1){
      digitalWrite(led3,1);
     }
     else{
      digitalWrite(led3,0);
     }

          if(p4==1){
      digitalWrite(led4,1);
     }
     else{
      digitalWrite(led4,0);
     }

          if(p5==1){
      digitalWrite(led5,1);
     }
     else{
      digitalWrite(led5,0);
     }

     if(p6==1){
      digitalWrite(led6,1);
     }
     else{
      digitalWrite(led6,0);
     }
                       
    }
  }
  //delay(10000);
}
