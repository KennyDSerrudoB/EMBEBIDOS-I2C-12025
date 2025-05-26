#include "I2CMaster.h"
#include <Wire.h>

void iniciarComunicacionI2C() {
  Wire.begin(); // En ESP32: SDA = GPIO 21, SCL = GPIO 22
}

/**
 * Lee datos desde un esclavo I2C, filtrando solo los caracteres imprimibles.
 */
String leerDesdeEsclavoI2C(uint8_t direccion, uint8_t cantidad) {
  String datos = "";

  // Solicita 'cantidad' de bytes al esclavo con la dirección dada
  Wire.requestFrom(direccion, cantidad);

  // Lee los datos disponibles
  while (Wire.available()) {
    char caracter = Wire.read();
    if (isPrintable(caracter)) {
      datos += caracter;
    }
  }

  return datos;
}
