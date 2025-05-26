#include "funciones.h"

uint16_t ir_value;
int distance_cm;

void initCom(){
  Serial.begin(BR);
  Wire.begin(DIR_S);
  Wire.onRequest(sendData);
}

void initSensors() {
  pinMode(IR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

uint16_t readIR() {
  return analogRead(IR_PIN);
}

uint16_t readUSound() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(TP);
  digitalWrite(TRIG_PIN, LOW);
  long duracion = pulseIn(ECHO_PIN, HIGH);
  return duracion / TIME_C;
}

void sendData() {
  char buffer[BUFFER];
  snprintf(buffer, sizeof(buffer), "%u,%d", ir_value, distance_cm);
  Wire.write(buffer, strnlen(buffer, BUFFER));
}

void printData(){
  ir_value = readIR();
  distance_cm = readUSound();
  Serial.print("IR: ");
  Serial.print(ir_value);
  Serial.print("\tDist: ");
  Serial.println(distance_cm);
}


