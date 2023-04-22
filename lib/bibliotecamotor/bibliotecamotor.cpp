#include <Arduino.h>
#include <bibliotecamotor.h>

//funÃ§Ã£o construtiva



motor::motor(byte f,byte r) {
  //declaraÃ§Ã£o de variavÃ©is encapsulamento equivalentes as variÃ¡veis do objeto
  fpriv = f;
  rpriv = r;

  //declaraÃ§Ã£o de pinos
  pinMode(fpriv,OUTPUT);
  pinMode(rpriv,OUTPUT);
}
void motor::frente(int v){
  analogWrite(fpriv,v);
  digitalWrite(rpriv,LOW);
}
void motor::re(int v){
  digitalWrite(fpriv,LOW);
  analogWrite(rpriv,v);
}

void motor::direita(){
  digitalWrite(rpriv,LOW);
  digitalWrite(fpriv,HIGH);
}
void motor::esquerda(){
  digitalWrite(rpriv,HIGH);
  digitalWrite(fpriv,LOW);

}
void motor::para(){
  digitalWrite(rpriv,LOW);
  digitalWrite(fpriv,LOW);
}
/*motor::shifto( dataPin,  clockPin,  bitOrder,  val){
  uint8_t i;

  
}
*/

