#include <LiquidCrystal.h>
int rs = 11, e= 10, d4 =4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int led = 2, PIR = 9, buzzer = 12;
int PIR_state = LOW;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.print("THIS IS MY INTRUDER ALERT SYSTEM PROJECT\n");
  Serial.println("my buzzer will sound for");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INTRUDER ALERT");
  lcd.setCursor(3,2);
  lcd.print("SYSTEM");
  delay(2000);
  PIR_state = digitalRead(PIR);
  if(PIR_state == HIGH)
    intruderMode();
}
void intruderMode(){
  lcd.clear();
  for(int x = 0; x < 20; x++){
    Serial.println(x+1);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    delay(500);
    lcd.setCursor(0,0);  
    delay(100);       
    lcd.print(" INTRUDER DETECTED ");
    lcd.scrollDisplayLeft();
    
  }
}

