#include <Arduino.h>
//#include <bibliotecamotor.h>
#define sdd 2
#define sd 3
#define sc 4
#define se 8
#define see 9

motor md(5,6);
motor me(10,11);
int sensores[5] = {sdd,sd,sc,se,see};

int sensor[5] = {digitalRead(sdd),digitalRead(sd),digitalRead(sc),digitalRead(se),digitalRead(see)};

int ki = 0; //constante integral usada para acumular erros até chegar no erro final
int kp = 35; //constante proporcional que é usada para definir a velocidade do robô ao compensar o lado que ele deve voltar
int kd = 35; //constante derivada responsàvel por diminuir a velocidade ajustando para o robô realizar curvas mais devagar de acordo com erro

int I = 0, P = 0, D = 0, PID = 0;
int velesq = 0, veldir = 0;
int erro = 0, erroanterior = 0;
void setup() {
  for (int i = 0;i <= 5;i++){
    pinMode(sensores[i],INPUT);
  }
}

void loop() {
  
}

void calculoerro(){
  if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 0; }
  else if(sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1){ erro = 1; }
  else if(sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1){ erro = 2; }
  else if(sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1){ erro = 3; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0){ erro = -1; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 1){ erro = -2; }
  else if(sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 1){ erro = -3; }
}

void calculapid(){
  if (erro == 0){
    I = 0;
  }
  P = erro;
  I = I + erro;
  if(erro > 255){
    I = 255;
  }
  else if(erro < -255){
    I = -255;
  }
  D = erro - erroanterior;
  PID = (kp*P) + (ki*I) + (kd*D); 
  erroanterior = erro;
}

void frente(int v){
  md.frente(v);
  me.frente(v);
}
void re(int v){
  md.re(v);
  me.re(v);
}
void esquerda(int v){
  md.frente(v);
  me.re(v);
}
void direita(int v){
  me.frente(v);
  md.re(v);
}
