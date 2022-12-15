//car moves forward on its own and avoids objects

#define A1 7
#define A2 5
#define B1 8
#define B2 6

#include <Servo.h> // adds servo library
Servo myservo;

int echo = 12;
int trig = 13;



void setup() {
  
Serial.begin(9600);
for (int i=3; i<9; i++){
pinMode (i, OUTPUT);
}
myservo.attach (10);
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);


}


void move ( bool a, int b, bool c, int d){

digitalWrite(A3, a);
digitalWrite(B1, c);

analogWrite(A4, b);
analogWrite(B2, d);
}


int Distancecheck (){ //ultrasonic checks for distance

digitalWrite(trig, LOW);
delayMicroseconds(10);
digitalWrite(trig, LOW);
delayMicroseconds(10);
digitalWrite(trig, LOW);
float  Fdistance = PulseIn;
Fdistance = Fdistance/58;
return (int) Fdistance;



}

void loop() {
 
myservo.write(90);
delay(500);
mD = Distancecheck();
if (mD <= 20)
move(1,0,1,0)//stops if detects something in the middle, directly infront of it

delay(500);
myservo.write(10);
delay (1000);
rD = Distancecheck(); //checks right and collects distance

delay(500);
myservo.write(90);
delay (1000);
myservo.write(180);
lD = Distancecheck(); //checks left and collects distance

delay(500);
myservo.write(90); // returns sensor to facing front position
delay(1000)

if (rD > lD){
 move (1, 0, 1, 150);//moves right if space on the right is more open
delay(360);}

else if (rD < lD){
 move( 1, 150, 1, 0);//moves left if space on the left is more open
delay(360);}

else if  (rD <=20 && lD <= 20){
move(0, 150, 0, 150);// reverses if both sides are blocked
delay(180);}

 else{
   move(1,150,1,150);} // goes forward if all sensors are not picking up objects
}

else{
   move(1,150,1,150);} // continues to go forward as long as middle sensor isnt picking up objects


 }







