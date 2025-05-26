#include <Arduino.h>
#include "I2CMaster.h"

// Dirección I2C del esclavo
#define SLAVE_ADDRESS 0x08

void setup() {
  Serial.begin(115200);       // Inicializa el monitor serial
  iniciarComunicacionI2C();   // Configura la interfaz I2C
}

void loop() {
  // Solicita datos al esclavo I2C y los muestra por serial
  String datos = leerDesdeEsclavoI2C(SLAVE_ADDRESS, 32);
  Serial.println("Datos recibidos: " + datos);

  delay(1000); // Espera 1 segundo antes de la siguiente lectura
}
