#include<NewPing.h>

NewPing proW(2,3,400);
NewPing proA(6,7,400);
NewPing proS(4,5,400);
NewPing proD(8,9,400);


#define ledw 10
#define leda 11
#define leds 12
#define ledd 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledw, OUTPUT);
  pinMode(leda, OUTPUT);
  pinMode(leds, OUTPUT);
  pinMode(ledd, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int distanceD = proD.ping_cm();
  if(distanceD < 50 && distanceD != 0) {
//    Serial.println(distanceD);
    digitalWrite(ledd, HIGH);
    Serial.println("R on");
  } else {
//    Serial.println(distanceD);
    digitalWrite(ledd, LOW);
    Serial.println("R off");
  }
  int distanceS = proS.ping_cm();
  if(distanceS == 0) {
    Serial.println(distanceS);
    Serial.println("B on");
    digitalWrite(leds, HIGH);
  } else {
    Serial.println(distanceS);
    Serial.println("B off");
    digitalWrite(leds, LOW);
  }
  int distanceA = proA.ping_cm();
  if(distanceA < 50 && distanceA != 0) {
//  Serial.println(distanceA);
    Serial.println("L on");
    digitalWrite(leda, HIGH);
  } else {
//    Serial.println(distanceA);
    Serial.println("L off");
    digitalWrite(leda, LOW);
  }
  int distanceW = proW.ping_cm();
  if(distanceW < 30 && distanceW != 0) {
//    Serial.println(distanceW);
    Serial.println("F on");
    digitalWrite(ledw, HIGH);
  } else {
//    Serial.println(distanceW);
    Serial.println("F off");
    digitalWrite(ledw, LOW);
  }
}
