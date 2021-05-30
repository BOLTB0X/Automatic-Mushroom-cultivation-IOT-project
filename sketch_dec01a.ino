#include <DHT.h>
#define DHTPIN 4// 습도센서 Signal 선 연결
#define DHTTYPE DHT11 // 습도센서 종류: DHT22
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
DHT dht(DHTPIN, DHTTYPE);


LiquidCrystal_I2C lcd(0x27, 16, 2);  
int pump = 13;
float hum ;
float temp;

  void setup(){
    Serial.begin(9600);
    pinMode(pump, OUTPUT);
    lcd.init();
    lcd.backlight();

  }

  void loop(){
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
    delay(1000);
    Serial.print("humidity = ");
    Serial.println(hum);
    Serial.print("Temperature = ");
    Serial.println(temp);
   
    if (hum < 40){
      digitalWrite(pump,HIGH);
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(hum);
      delay(1000);
    }
    else{
      digitalWrite(pump,LOW);
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(hum);
      delay(1000);
    }
    delay(1000);
  } 
 
