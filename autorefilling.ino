#define trig 7 //trigger pin of ultrasonic sensor
#define trig1 8 //trigger pin of ultrasonic1 sensor
#define echo 6 //Echo pin of ultrasonic sensor
#define echo1 5 //Echo pin of ultrasonic1 sensor
#define ir A0 // Output pin of IR sensor
#define buz 13 // For Buzzer
#define pump 9 //pump
#define pump1 10 //pump



int count1 =0; // counting number of persons by ultrasonic sensor
int count2=0; // counting number of persons by IR sensor sensor

void setup()
{
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
digitalWrite(trig,LOW);
digitalWrite(trig1,LOW);
delayMicroseconds(2);
pinMode(buz,OUTPUT);
pinMode(ir,INPUT);
pinMode(pump,OUTPUT);
pinMode(pump1,OUTPUT);
while (!Serial);
Serial.begin(9600);
}

void loop()
{






//dispenser-----------------------------------------------------------------------------




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
delay(2000);
digitalWrite(pump,LOW);
delay(1000);
 

}
if (d>10)
{
digitalWrite(pump,LOW);  
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






//for refilling--------------------------------------------------------------------




digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);

int t1 = pulseIn(echo1,HIGH);

int d1 = (0.000001)*(34300*t1)/2; // d is the distance calculated by ultrasonic sensor
delay(500);

if(d1>=20)
{
digitalWrite(pump1,HIGH);

}
if (d1<10)
{
digitalWrite(pump1,LOW);  
}



}
