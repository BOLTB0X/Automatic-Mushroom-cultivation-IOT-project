int pwmPin = 12; // assigns pin 12 to variable pwm
int push = 8 ; // assigns analog input A0 to variable pot
int c1 = 0;   // declares variable c1
int c2 = 0;   // declares variable c2

void setup()  // setup loop
{
  pinMode(pwmPin, OUTPUT); 
  pinMode(push, INPUT);  
}

void loop()
{
  c2= analogRead(push); 
  if (c2 == HIGH)// subtracts c2 from 1000 ans saves the result in c1
  {digitalWrite(pwmPin, HIGH); 
  }  else
  {digitalWrite(pwmPin, LOW);
  }
  }
