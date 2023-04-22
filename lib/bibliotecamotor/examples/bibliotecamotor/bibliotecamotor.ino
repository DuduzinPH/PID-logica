/* 
 =====================================================
  Biblioteca de motores simples

  
  powered by Eduardo,Tomaz,Guerra e Yan
  March,2023.
 ====================================================
 */

//incluindo a biblioteca
#include <bibliotecamotor.h>

//declarando os motores:
motor (12,13); // pino de frente e pino de ré

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.frente(); // função que faz o motor ir para frente
  motor.re(); // função que faz o motor ir para trás
}
