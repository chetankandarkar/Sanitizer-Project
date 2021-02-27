#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define in 8
#define out 9
#define led1 10
#define led2 11
#define led3 12

int count=0;

void setup()
{
  digitalWrite(led3,HIGH);
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(out, INPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}
void loop()
{  
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
    digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
  }

  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
  }


  if(count==0)
  {
    
    lcd.clear();
    lcd.print("Nobody In Room");
    delay(200);
  }
  }

