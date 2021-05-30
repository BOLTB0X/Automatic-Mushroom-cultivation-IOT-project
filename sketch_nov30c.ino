#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  

int relay = 2;

void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop(){
  
  float soil = analogRead(A1);
  Serial.println(soil);

  if(soil < 800 ){
    digitalWrite(relay, LOW);
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("moisture : ");
    lcd.print(soil);
    delay(1000);
    
  }
  else{
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("moisture : ");
    lcd.print(soil);
    delay(1000);
  }
  delay(5000);
 
}
