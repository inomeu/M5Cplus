#include <M5StickCPlus.h>
//#include <M5StickC.h>
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
float temp;

void setup() {
M5.begin();
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
M5.Lcd.println(" X Y Z");
M5.IMU.Init();
}

void loop() {
M5.IMU.getAccelData(&accX,&accY,&accZ);
M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
M5.IMU.getTempData(&temp);
M5.Lcd.setCursor(0, 15);
M5.Lcd.printf("A: %.2f %.2f %.2f ",
accX * 10,accY * 10, accZ * 10);
M5.Lcd.setCursor(0, 30);
M5.Lcd.printf("G: %.2f %.2f %.2f ",
gyroX, gyroY,gyroZ);
M5.Lcd.setCursor(0, 45);
M5.Lcd.printf("Temperature : %.2f C", temp);
delay(100);
}
