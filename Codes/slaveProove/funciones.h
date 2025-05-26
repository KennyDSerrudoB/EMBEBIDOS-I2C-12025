#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <Wire.h>

#define BR    9600
#define IR_PIN  A0
#define TRIG_PIN 5
#define ECHO_PIN 7
#define DIR_S 0x08
#define TIME_C  59
#define TP      10
#define BUFFER  32



void initCom();
void initSensors();

uint16_t  readIR();
uint16_t  readUSound();
void sendData();
void printData();

#endif