
#define F 16736925  // FORWARD
#define B 16754775  // BACK
#define L 16720605  // LEFT
#define R 16761405  // RIGHT
#define S 16712445  // STOP
#define UNKNOWN_F 5316027     // FORWARD
#define UNKNOWN_B 2747854299  // BACK
#define UNKNOWN_L 1386468383  // LEFT
#define UNKNOWN_R 553536955   // RIGHT
#define UNKNOWN_S 3622325019  // STOP
//IR REMOTE CODES 

#define A1 7
#define A2 5
#define B1 8
#define B2 6


#include <IRremote.h>//includes ir library

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN); //initialises ir pin
decode_results results;
unsigned long val;
unsigned long preMillis;
 
void setup() {


digitalWrite(3, OUTPUT);
pinMode(3,1);
for (int i=3; i<9; i++){
pinMode (i, OUTPUT);

move( 1, 0, 1, 0);//stop, makes sure the cars stationary 
irrecv.enableIRIn(); //starts receiver
}
}

void loop(){
 if (irrecv.decode(&results)){ 
    preMillis = millis();
    val = results.value; // signal from ir remote
    irrecv.resume();
    switch(val){ 
      case F: case UNKNOWN_F: move( 1, 100, 1, 100); break; //goes forward
      case B: case UNKNOWN_B: move( 0, 100, 0, 100); break; //reverses
      case L: case UNKNOWN_L: move( 1, 100, 0, 100); break; //goes left
      case R: case UNKNOWN_R: move( 0, 100, 1, 100); break; //goes right
      case S: case UNKNOWN_S: move( 1, 0, 1, 0); break; //stops
      default: break;
    }
  }
  else{
    if(millis() - preMillis > 500){
     move( 1, 0, 1, 0);//stop
      preMillis = millis();
    }
  }
  }


void move ( bool a, int b, bool c, int d){

digitalWrite(A1, a);
digitalWrite(B1, c);

analogWrite(A2, b);
analogWrite(B2, d);
}
