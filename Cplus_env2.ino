#include <M5StickCPlus.h>  
#include <DHT12.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Ambient.h>

DHT12 dht12;
Adafruit_BMP280 bme;

#define uS_TO_S_FACTOR 1000000  
#define TIME_TO_SLEEP  6        

WiFiClient client;
Ambient ambient;

const char* ssid = "free-wifi";
const char* password = "free-wifi";

unsigned int channelId = 65107; // AmbientのチャネルID
const char* writeKey = "6edf8eed1a9a3788"; // ライトキー


void setup() {
    M5.begin();
    M5.Axp.ScreenBreath(10);   
    M5.Lcd.setRotation(3);               
    M5.Lcd.setTextSize(2);      
    M5.Lcd.fillScreen(BLACK);   

    Wire.begin();               
    while (!bme.begin(0x76)) {
        M5.Lcd.println("BMP280 init fail");
    }

    float tmp = dht12.readTemperature();
    float hum = dht12.readHumidity();
    float pressure = bme.readPressure();
    double vbat = M5.Axp.GetVbatData() * 1.1 / 1000;  

    M5.Lcd.setCursor(0, 0, 1);
    M5.Lcd.printf("temp: %4.1f'C\r\n", tmp);//気温d1
    M5.Lcd.printf("humid:%4.1f%%\r\n", hum);//湿度d2
    M5.Lcd.printf("press:%4.0fhPa\r\n", pressure / 100);//気圧
    //M5.Lcd.printf("vbat: %4.2fV\r\n", vbat);

    WiFi.begin(ssid, password); 
    while (WiFi.status() != WL_CONNECTED) {  
        delay(500);
        Serial.print(".");
    }
    Serial.print("WiFi connected\r\nIP address: ");
    Serial.println(WiFi.localIP());

    ambient.begin(channelId, writeKey, &client); 


    ambient.set(1, tmp);
    ambient.set(2, hum);
    ambient.set(3, pressure / 100);
    //ambient.set(4, vbat);

    ambient.send();

    esp_deep_sleep(TIME_TO_SLEEP * uS_TO_S_FACTOR); //  ----C
}

void loop() {
}
