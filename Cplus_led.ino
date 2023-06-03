#include <M5StickCPlus.h>
//#include <M5StickC.h>
const int LONG_PRESS = 1000;
const int INIT_INTERVAL = 100;
int interval = INIT_INTERVAL;
int blink_flag = 1;
void setup() {
M5.begin();
pinMode(M5_LED, OUTPUT);
M5.Lcd.setRotation(3);
M5.Lcd.setTextSize(2);
}
void blinkLED(){
digitalWrite(M5_LED, LOW);
delay(interval);
if(blink_flag){
M5.Lcd.println("blink");
digitalWrite(M5_LED, HIGH);
delay(interval);
}
}

void loop() {
M5.update(); // Buttonを更新
if(M5.BtnB.wasReleased()){
interval = interval * 2;
}
if(M5.BtnA.wasReleased()){
interval = interval / 2;
}
if(M5.BtnA.wasReleasefor(LONG_PRESS)){
interval = INIT_INTERVAL;
}
if(M5.Axp.GetBtnPress() == 2){
blink_flag = !blink_flag;
}
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setCursor(0, 0);
M5.Lcd.println(interval);
blinkLED();
}
