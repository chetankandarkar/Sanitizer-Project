#define trig 7 //trigger pin of ultrasonic sensor
#define echo 6 //Echo pin of ultrasonic sensor
#define ir A0 // Output pin of IR sensor
#define buz 13 // For Buzzer
#define bolt 2 // Pin to Bolt Wifi module PIN 0
#define pump 9 //pump


int count1 =0; // counting number of persons by ultrasonic sensor
int count2=0; // counting number of persons by IR sensor sensor

void setup()
{
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
delayMicroseconds(2);
pinMode(buz,OUTPUT);
pinMode(ir,INPUT);
pinMode(bolt,OUTPUT);
while (!Serial);
digitalWrite(bolt,HIGH);
Serial.begin(9600);
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
  count1=count1+1;
digitalWrite(pump,HIGH);

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
delay(5000);
digitalWrite(buz,LOW);

}
}
