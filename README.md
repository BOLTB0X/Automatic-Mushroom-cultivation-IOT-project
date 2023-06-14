# 버섯자동재배 IoT 프로젝트

<img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/앱_초기.png?raw=true" width="150" height="300"/> <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/설정.png?raw=true" width="150" height="300"/>
<br>

## 외관

<img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/외관.png?raw=true" width="300" height="150"/> <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/외관_뒷면.jpeg?raw=true" width="300" height="150"/>
<br>

<img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/실제%20회로도.jpeg?raw=true" width="300" height="150"/> <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/img/LCD_온습도_표시.jpeg?raw=true" width="300" height="150"/>
<br>

## 프로젝트 정보

- 기관: 세종대학교 기초설계 수업
  <br/>
- 참여인원: 4명
  <br/>
- 기간: 2019.09~2019.12
  <br/>
- 나의 역할: 조장, 임베디드 sw파트
  <br/>
- 주제: 아두이노를 활용하여 앱과 연동되는 버섯재배 박스
  <br/>

## 기술스택

- language: C/C++
  <br/>
- IDE: Arduino sketch, App inventor
  <br/>
- 사용부품: 아두이노보드(우노),펠티어소자,릴레이모듈,워터펌프,모터드라이브,블루투스센서
  <br/>

## 기능

**_원하는 버섯을 선택하면 그 버섯에 맞는 적절한 온습도를 자동조절~!_**
<br/>

## 작품 시연

![KakaoTalk_Video_2023-04-08-21-01-55](https://user-images.githubusercontent.com/83914919/230720362-8c7563a5-1f4d-4c2e-8bb6-dd0edb9b926c.gif) ![KakaoTalk_Video_2023-04-08-21-02-00](https://user-images.githubusercontent.com/83914919/230720427-4381850e-34f8-45c7-b0c3-3a84245cb9aa.gif)
<br/>

### 진행 과정

1. 펠티어 소자 테스트
   <br/>
   <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/video/펠티어소자로%20온습도%20조절.gif?raw=true" width="300" height="150"/> <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/video/펠티어소자%20테스트-2.gif?raw=true" width="300" height="150"/>
   <br>

2. BLE 테스트
   <br/>
   <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/video/BLE_연결.gif?raw=true" width="300" height="150"/> <img src="https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/video/BLE_테스트.gif?raw=true" width="300" height="150"/>
   <br>

## 코드

<details><summary>온습도 조절 코드(C)</summary>

```cpp
if ((humi >= myhum) && (temp >= mytemp)){
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,HIGH);
      digitalWrite(RELAY2,LOW);


      lcd.setCursor(0,0);
      lcd.print("Temperate: ");
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
      lcd.print("Temperate: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else if((humi < myhum)&&(temp < mytemp)){
      digitalWrite(pump,LOW);
      delay(2000);
      digitalWrite(pump,LOW);
      delay(2000);
      digitalWrite(RELAY1,LOW);
      digitalWrite(RELAY2,HIGH);


      lcd.setCursor(0,0);
      lcd.print("Temperate: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else if((humi >= myhum) && (temp < mytemp)){
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(RELAY1,LOW);
      digitalWrite(RELAY2,HIGH);


      lcd.setCursor(0,0);
      lcd.print("Temperate: ");
      lcd.print(temp);
      lcd.setCursor(0,1);
      lcd.print("Humidity: ");
      lcd.print(humi);
      delay(1000);
    }
    else{
      digitalWrite(pump,HIGH);
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
```

</details>

[온습도 조절 소스코드 원본](https://github.com/BOLTB0X/Automatic-Mushroom-cultivation-IOT-project/blob/master/iot_final.ino)
<br/>
