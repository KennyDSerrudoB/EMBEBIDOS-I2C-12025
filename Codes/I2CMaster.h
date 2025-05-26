#ifndef I2CMASTER_H
#define I2CMASTER_H

#include <Arduino.h>

// Inicializa la comunicación I2C en el ESP32 (SDA = GPIO 21, SCL = GPIO 22 por defecto)
void iniciarComunicacionI2C();

// Solicita una cantidad específica de datos desde un dispositivo esclavo I2C.
// direccion: dirección del esclavo I2C
// cantidad: número de bytes a solicitar
// Devuelve una cadena con los caracteres imprimibles recibidos
String leerDesdeEsclavoI2C(uint8_t direccion, uint8_t cantidad);

#endif
