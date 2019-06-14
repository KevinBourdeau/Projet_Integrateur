#include <Grove_I2C_Motor_Driver.h>

// default I4C address is 0x0f
#define I2C_ADDRESS 0x0f


int GSpeed = 0;
int DSpeed = 0;

int stopCount = 150;

void setup() {
  Motor.begin(I2C_ADDRESS);

}



void loop() {

  //Tout les capteurs Blancs
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && stopCount < 150) {
    goForward ();               // AVANCE PENDANT 150 TOURS DE LOOP
    stopCount = stopCount + 1;
  }
  //Tout les capteurs Blancs
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && stopCount >= 150) {
    stop();
  }



  // Capteur milieu Noir
  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    goForward ();
    stopCount = 0;
  }




  // Capteur gauche Noir
  if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH ) {
    calibrateLeft ();

  }
  // Capteur droit Noir
  if (  digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
    calibrateRight ();
  }



  // Capteurs milieu et gauche Noirs
  if (  digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    turnLeft ();
  }
  // Capteurs milieu et droit Noirs
  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    turnRight ();
  }
  // Capteur gauche et droit Noirs
  if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
    turnRight ();
  }
  //Tout les capteurs Noirs
  if ( digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    turnRight ();
  }
}



void turnLeft () {
  setSpeed (65, 65);
  delay (150);
  while ( digitalRead(3) != HIGH ) {
    setSpeed (-75, 75);   // TOURNE GAUCHE
  }
  stopCount = 0;
}



void turnRight () {
  setSpeed (65, 65);
  delay (150);
  while ( digitalRead(3) != HIGH ) {
    setSpeed (75, -75);   // TOURNE DROITE
  }
  stopCount = 0;
}



void calibrateLeft () {
  while ( digitalRead(3) != HIGH ) {
    setSpeed (-75, 75);   // CALIBRE GAUCHE
  }
  stopCount = 0;
}



void calibrateRight () {
  while ( digitalRead(3) != HIGH ) {
    setSpeed (75, -75);   // CALIBRE DROITE
  }
  stopCount = 0;
}



void goForward () {
  setSpeed (65, 65);    // AVANCE
}



void stop () {
  setSpeed (0, 0);       // STOP
}



void setSpeed (int GSpeed, int DSpeed) {
  Motor.speed(MOTOR1, GSpeed);  // Set speed of MOTOR1
  Motor.speed(MOTOR2, DSpeed);  // Set speed of MOTOR2
}
