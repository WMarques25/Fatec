// Desafio em Arduino com tela lcd, potenciômetro, ldr. 
// link para o simulador com circuito montado abaixo.
// https://www.tinkercad.com/things/7WQPClX3da9?sharecode=dLqwzGIEuqbS1qPxSSYnwXeQ9D6Y3mlDx9duF33hcdk

#include <Adafruit_LiquidCrystal.h>
  int led1 = 13; 
  int led2 = 10;
  int led3 = 9;
  int BT1 = 7;
  int BT2 = 6;
  int buzz = 8;
  int LDR = A0;
  int LM35 = A1;
  int Pot = A2; 
  unsigned int valorPot; 
  unsigned int pwm;