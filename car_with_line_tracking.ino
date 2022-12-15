//Getting car to follow line
#define A3 7
#define A4 5
#define B1 8
#define B2 6


void setup() {
 
for (int i=3; i<9; i++){
pinMode (i, OUTPUT);
}

}


void move ( bool a, int b, bool c, int d){

digitalWrite(A3, a);
digitalWrite(B1, c);

analogWrite(A4, b);
analogWrite(B2, d);
}

void loop() {


  int middle = analogRead(A1);
  int left = analogRead(A2);
  int right = analogRead(A0);

if ( middle >= 50 ){//moves forward if middle sensor at max value
move( 1, 60, 1, 60);
}

else if (left >= 50){
  move( 1, 255, 1, 0); //moves left if left sensor detects line
}

else if (right >= 50){
  move (1, 0, 1, 255); //moves right if right sensor detects line
}

else if ( middle <= 50 && left <= 50 && right <= 50){
  move( 1, 0, 1, 120); //rotates to find line if all sensors dont pick up line
 }

}




