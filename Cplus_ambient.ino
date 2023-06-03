#include "M5StickCPlus.h"
#include "Ambient.h"
WiFiClient client;
Ambient ambient;
const char* ssid = "free-wifi";
const char* password = "free-wifi";
unsigned int channelId = 65104;
const char* writeKey = "3826ac2f42131293";

void setup() {
M5.begin();
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(2);
M5.Lcd.println("Ambient Test.");
Serial.begin(115200);
Serial.println("Start:");
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.print("WiFi connected. IP: ");
Serial.println(WiFi.localIP());
ambient.begin(channelId, writeKey, &client);
}

void loop() {
int value = 0;
M5.update();
if (M5.BtnA.isPressed()){
value = 1;
}
else if(M5.BtnB.isPressed()){
value = 2;
}
else{
value = 0;
}
M5.Lcd.setCursor(0, 15);
M5.Lcd.printf("Value: %d", value);
ambient.set(1, value); // key, value
ambient.send();
delay(1000);
}
