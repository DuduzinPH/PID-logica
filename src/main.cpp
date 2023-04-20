#include <Arduino.h>
#include <bibliotecamotor.h>

motor md(5,6);
motor me(10,11);
int sensores[5] = {sdd,sd,sc,se,see};

int sensor[5] = {digitalRead(sdd),digitalRead(sd),digitalRead(sc),digitalRead(se),digitalRead(see)}
#define sdd 2
#define sd 3
#define sd 4
#define sd 8
#define sd 9

int ki = 0;
int kp = 35;
int kd = 35;

void setup() {
  for (int i = 0;i <= 5;i++){
    pinMode(sensores[i],INPUT);
  }
}

void loop() {
  
}

void calculoerro(){
  if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
  else if(sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
}