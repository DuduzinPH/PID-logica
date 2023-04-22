#ifndef bibliotecamotor_H
#define bibliotecamotor_H

#include "arduino.h"




class motor{
  public:
  //declaraÃ§Ã£o de objeto
  motor(byte f, byte r);
  motor1(byte f,byte r1);
  //motor1(byte f1, byte r1);
  //declaraÃ§Ã£o de mÃ©todos
  void frente(int v);
  void re(int v);
  void direita();
  void esquerda();
  void para();

  private:
  //declaraÃ§Ã£o de variavÃ©is privadas
  //int bin;
  int fpriv;
  int rpriv;
};




#endif
