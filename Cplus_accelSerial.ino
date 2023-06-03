#include <M5StickCPlus.h>
//#include <M5StickC.h>
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
float temp;
char accXStr[10],accYStr[10],accZStr[10];
char gyroXStr[10],gyroYStr[10],gyroZStr[10];
char tempStr[10];
char buff[100];

void setup() {
M5.begin();
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
M5.Lcd.println("IMU->Serial Test");
M5.IMU.Init();
}

void loop() {
M5.IMU.getAccelData(&accX,&accY,&accZ);
M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
M5.IMU.getTempData(&temp);
dtostrf(accX*100, 6, 2, accXStr);
dtostrf(accY*100, 6, 2, accYStr);
dtostrf(accZ*100, 6, 2, accZStr);
dtostrf(gyroX, 6, 2, gyroXStr);
dtostrf(gyroY, 6, 2, gyroYStr);
dtostrf(gyroZ, 6, 2, gyroZStr);
dtostrf(temp, 5, 1, tempStr);
sprintf(buff, "%s,%s,%s,%s,%s,%s,%s", accXStr, accYStr,
accZStr,gyroXStr, gyroYStr, gyroZStr, tempStr);
Serial.println(buff);
delay(100);
}
