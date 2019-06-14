#include <Grove_I2C_Motor_Driver.h>

// default I4C address is 0x0f
#define I2C_ADDRESS 0x0f


int signalPin;

int GSpeed = 0;
int DSpeed = 0;

int state = 200;



void setup() {
  Motor.begin(I2C_ADDRESS);

  pinMode(signalPin, INPUT); // initialize the digital pin as an output:
  Serial.begin(9700);  // initialize serial communications at 9700 bps:
}



void loop() {

  //Tout les capteurs Blancs
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && state < 200) {
    setSpeed (65, 65);    // AVANCE PENDANT 200 TOUR DE LOOP
    state = state + 1;
  }
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && state >= 200) {
    setSpeed (0, 0);     // STOPE
  }
  //Tout les capteurs Noirs
  if ( digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    setSpeed (65, 65);   // TOURNE DROITE
    delay (300);
    setSpeed (80, -70);
    delay (600);
    state =0;
  }



  // Capteur milieu Noir
  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    setSpeed (65, 65);    // AVANCE
    state = 0;
  }
  // Capteur gauche Noir
  if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH ) {
    setSpeed (-70, 80);   // CALIBRE GAUCHE
    state = 0;
  }
  // Capteur droit Noir
  if (  digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
    setSpeed (80, -70);   // CALIBRE DROITE
    state = 0;
  }


  // Capteurs milieu et gauche Noirs
  if (  digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    setSpeed (65, 65);   // TOURNE GAUCHE
    delay (300);
    setSpeed (-80, 80);
    delay (600);
    state =0;
  }
  // Capteurs milieu et droit Noirs
  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    setSpeed (65, 65);   // TOURNE DROITE
    delay (300);
    setSpeed (80, -80);
    delay (600);
    state =0;
  }
  // Capteur gauche et droit Noirs
  if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
    setSpeed (65, 65);   // TOURNE DROITE
    delay (300);
    setSpeed (80, -80);
    delay (600);
    state =0;
  }




}


void setSpeed (int GSpeed, int DSpeed) {
  Motor.speed(MOTOR1, GSpeed);  // Set speed of MOTOR1
  Motor.speed(MOTOR2, DSpeed);  // Set speed of MOTOR2
}
