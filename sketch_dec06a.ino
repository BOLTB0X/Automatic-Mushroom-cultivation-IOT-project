//블루투스
#include <SoftwareSerial.h>
// 블루투스 통신을 사용하기 위해 불러오는 라이브러리
#include <DHT.h>
// 온습도 센서를 사용하기 위해 불러오는 라이브러리
#define DHTPIN 4// 습도센서 Signal 선 연결
#define DHTTYPE DHT11 // 습도센서 종류: DHT22
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define RELAY1  9
#define RELAY2  8

DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int T = 2;
int R = 3;
// 블루투스 모듈의 TXD 핀과 연결된 2번을 T 라는 변수로,
// 블루투스 모듈의 RXD 핀과 연결된 3번을 R 이라는 변수로 선언한다.
int temp_sensor = 4;
// 온습도센서가 연결된 4번 핀을 LED 라는 변수로 선언한다.
int pump = 7;
int pump_n = 6;


SoftwareSerial my_blue(T, R);
// my_blue 라는 이름의 블루투스 객체를 선언하는데,
// 이 블루투스 객체는 T 와 R 에 의해 제어된다.

DHT my_sensor(temp_sensor, DHT11);
// my_sensor 라는 이름의 온습도계 객체를 선언하는데,
// 이 온습도 객체는 temp_sensor(4번) 핀으로 제어되며 DHT11 종류이다.

void setup(){
  Serial.begin(9600);
  my_blue.begin(9600);
  // 블루투스 통신을 시작한다.
  my_sensor.begin();
  // 온습도계가 측정을 시작한다.
  pinMode(pump, OUTPUT);
  lcd.init();
  lcd.backlight();

  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);

  pinMode(5,INPUT);

}


void loop(){

    
 
  float temp = my_sensor.readTemperature();
  // 온습도계 객체인 my_sensor 가 측정한 온도값을 readTemperature() 함수로 불러와 temp 라는 변수에 저장한다.
  float humi = my_sensor.readHumidity();
  // 온습도계 객체인 my_sensor 가 측정한 습도값을 readHumid
  
  int myhum = my_blue.parseInt();
  int mytemp = my_blue.parseInt();




  if ((humi >= myhum)&& (temp >= mytemp)){
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,HIGH);
      digitalWrite(RELAY2,LOW);
      
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else if((humi < myhum)&&(temp >= mytemp)){
      digitalWrite(pump,LOW);
      delay(2000);
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,HIGH);
      digitalWrite(RELAY2,LOW);
      
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else if((humi < myhum)&&(temp < mytemp)){
      digitalWrite(pump,LOW);
      delay(2000);
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,LOW);
      digitalWrite(RELAY2,HIGH);
      
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else if((humi >= myhum)&&(temp < mytemp)){
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,LOW);
      digitalWrite(RELAY2,HIGH);
      
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else{
      digitalWrite(pump,LOW);
      digitalWrite(RELAY1,LOW);
      digitalWrite(RELAY2,LOW);
      
      lcd.setCursor(0,0);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    delay(1000);
    


  Serial.print("Temperature : ");
  Serial.println(temp,1);
  Serial.print("Humidity : ");
  Serial.println(humi,1);
  Serial.print("I want to make humidity : ");
  Serial.println(myhum);
  Serial.print("%");
  Serial.print("I want to make temperature : ");
  Serial.println(mytemp);  
  

  my_blue.print("현재 온도 : ");
  my_blue.print(temp);
  my_blue.print(" / 현재 습도 : ");
  my_blue.println(humi);
  // 페어링된 기계(여기서는 휴대폰)에 데이터를 출력시킨다.
  // 데이터는 0.5초마다 출력된다.


}
