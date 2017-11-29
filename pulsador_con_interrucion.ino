#include <Servo.h>

#define PIN_PULSADOR 2
#define PIN_LED 3
#define PIN_SERVO 9

boolean estado = false;
Servo motor;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_PULSADOR, INPUT);

  attachInterrupt(digitalPinToInterrupt(PIN_PULSADOR), apretado, RISING);

  motor.attach(PIN_SERVO);
}

void apretado() {
  estado = !estado;  //negamos el estado, si es true => false, si es false=>true

  if (estado) {
    digitalWrite(PIN_LED, 110);
  }
  else {
    digitalWrite(PIN_LED, 0);
  }
}


void loop() {
  motor.write(0);
  delay(250);
  motor.write(180);
  delay(250);
}
