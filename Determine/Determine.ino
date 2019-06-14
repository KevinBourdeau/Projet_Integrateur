#include <Grove_I2C_Motor_Driver.h>

// default I4C address is 0x0f
#define I2C_ADDRESS 0x0f


int GSpeed = 0;
int DSpeed = 0;

int stopCount = 150;

String NextDir = "Avance";



void setup() {
  Motor.begin(I2C_ADDRESS);
}



void loop() {
  avance();
  checkLine();

}


void avance () {
  // Tout les capteurs Blancs
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && stopCount < 150) {
    setSpeed (65, 65);    // AVANCE PENDANT 200 TOURS DE LOOP
    stopCount = stopCount + 1;
  }
  if ( digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH && stopCount >= 150) {
    setSpeed (0, 0);     // STOPE
  }

  // Capteur milieu Noir
  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    setSpeed (65, 65);    // AVANCE
    stopCount = 0;

    // Capteur gauche Noir
    if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) != HIGH ) {
      setSpeed (-70, 80);   // CALIBRE GAUCHE
      stopCount = 0;
    }
    // Capteur droit Noir
    if (  digitalRead(4) != HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
      setSpeed (80, -70);   // CALIBRE DROITE
      stopCount = 0;
    }
  }
}



void checkLine() {
  if ( digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    checkNextDir ();
  }

  if (  digitalRead(4) == HIGH && digitalRead(3) == HIGH && digitalRead(2) != HIGH ) {
    checkNextDir ();
  }

  if (  digitalRead(4) != HIGH && digitalRead(3) == HIGH && digitalRead(2) == HIGH ) {
    checkNextDir ();
  }

  if (  digitalRead(4) == HIGH && digitalRead(3) != HIGH && digitalRead(2) == HIGH ) {
    checkNextDir ();
  }
}



void checkNextDir () {

  // get new dir

  if (NextDir == "Gauche") {
    turnLeft ();
  }

  if (NextDir == "Droite") {
    turnRight ();
  }

}



void turnLeft () {
  setSpeed (65, 65);
  delay (150);
  setSpeed (-75, 75);   // TOURNE GAUCHE
  delay (800);
  stopCount = 0;

}



void turnRight () {
  setSpeed (65, 65);
  delay (150);
  setSpeed (75, -75);   // TOURNE DROITE
  delay (800);
  stopCount = 0;

}

void calibrateLeft () {
  
}

void calibrateRight () {
  
}


void setSpeed (int GSpeed, int DSpeed) {
  Motor.speed(MOTOR1, GSpeed);  // Set speed of MOTOR1
  Motor.speed(MOTOR2, DSpeed);  // Set speed of MOTOR2
}
