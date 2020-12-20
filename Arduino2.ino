#define trig 7 //trigger pin of ultrasonic sensor
#define echo 6 //Echo pin of ultrasonic sensor
#define ir A0 // Output pin of IR sensor
#define buz 13 // For Buzzer
#define bolt 2 // Pin to Bolt Wifi module PIN 0
#include <Stepper.h>

int in1Pin = 12;
int in2Pin = 11; // for stepper motor
int in3Pin = 10;
int in4Pin = 9;

// change this to the number of steps on your motor
#define STEPS 512

Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);
int count1 =0; // counting number of persons by ultrasonic sensor
int count2=0; // counting number of persons by IR sensor sensor
void setup()
{
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
delayMicroseconds(2);
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(in3Pin, OUTPUT);
pinMode(in4Pin, OUTPUT);
pinMode(buz,OUTPUT);
pinMode(ir,INPUT);
pinMode(bolt,OUTPUT);
while (!Serial);
digitalWrite(bolt,HIGH);
Serial.begin(9600);
motor.setSpeed(50);
}

void loop()
{

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

int t = pulseIn(echo,HIGH);

int d = (0.000001)*(34300*t)/2; // d is the distance calculated by ultrasonic sensor
delay(500);

if(d<=10)
{
motor.step(-100);
count1 = count1 +1;
motor.step(100);
}
Serial.println("US");
Serial.println(count1);
if(digitalRead(ir) == LOW)
{
count2=count2+1;
}
Serial.println("IR");
Serial.println(count2);
if(count2 > count1)
{

digitalWrite(buz,HIGH);
digitalWrite(bolt,LOW);

}
}
