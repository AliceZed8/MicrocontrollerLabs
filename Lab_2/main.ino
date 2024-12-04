#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

DHT dht(2, DHT22);
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 rtc;


int hum;
float temp;
int h, m, s;
void setup() {
  dht.begin();
  rtc.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  hum  =  dht.readHumidity();
  temp = dht.readTemperature();

  DateTime now = rtc.now();
  h = now.hour();
  m = now.minute();
  s = now.second();

  lcd.setCursor(0, 0);
  if (h < 10) lcd.print('0');
  lcd.print(h);
  lcd.print(":");

  if (m < 10) lcd.print('0');
  lcd.print(m);
  lcd.print(":");

  if (s < 10) lcd.print('0');
  lcd.print(s);

  lcd.setCursor(9, 0);
  lcd.print(temp);
  lcd.print(" C");


  lcd.setCursor(0, 1);
  lcd.print("Humidity");
  if (hum < 100) lcd.print(" ");
  lcd.print(hum);
  lcd.print("%");
  
  delay(1000);
}

