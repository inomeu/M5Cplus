#include <M5StickCPlus.h>
//#include <M5StickC.h>

int cnt = 0;
const int CNT_MAX = 5;

void setup()
{
M5.begin();
pinMode(M5_LED, OUTPUT);
M5.Lcd.setRotation(3);
M5.Lcd.setTextSize(2);
M5.Lcd.print("Hello World");
}
void loop()
{
digitalWrite(M5_LED, LOW);
delay(500);
digitalWrite(M5_LED, HIGH);
delay(500);

M5.Lcd.println(cnt);
cnt ++;
if(cnt > CNT_MAX){
cnt = 0;
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setCursor(0, 0);
}
}
