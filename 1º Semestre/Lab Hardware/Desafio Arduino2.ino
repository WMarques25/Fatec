// Desafio em Arduino com tela lcd, potenciômetro, ldr. 
// link para o simulador com circuito montado abaixo.
// https://www.tinkercad.com/things/7WQPClX3da9?sharecode=dLqwzGIEuqbS1qPxSSYnwXeQ9D6Y3mlDx9duF33hcdk

#include <Adafruit_LiquidCrystal.h>
  int led1 = 13; 
  int led2 = 10;
  int led3 = 9;
  int BT1 = 7;
  int Bt1;
  int BT2 = 6;
  int Bt2;
  int buzz = 8;
  int LDR = A0;
  int ldrValor;
  int LM35 = A1;
  float temperatura;
  int Pot = A2; 
  unsigned int valorPot; 
  unsigned int pwm;

  Adafruit_LiquidCrystal lcd_1(0);

  void setup(){
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(BT1, INPUT);
    pinMode(BT2, INPUT);
    pinMode(buzz, OUTPUT);

    lcd_1.begin(16, 2);
    lcd_1.print("LD     L1:  L2: ");
    lcd_1.setCursor(0, 1);
    lcd_1.print("TP:       PT:   ");
  }

    void Limpa(){
      lcd_1.setCursor(2, 0);
      lcd_1.print("     ");
      lcd_1.setCursor(3, 1);
      lcd_1.print("       ");
      lcd_1.setCursor(13, 1);
      lcd_1.print("   ");
    }

  void EscreveLed(int a){
    if(a == 1){
      if(Bt1 == LOW){
        lcd_1.setCursor(10, 0);
        lcd_1.print("L");
      }
      else{
        lcd_1.setCursor(10, 0);
        lcd_1.print("D");
      }
    }
    else{
      if(Bt2 == LOW){
        lcd_1.setCursor(15, 0);
        lcd_1.print("L");
      }
      else{
        lcd_1.setCursor(15, 0);
        lcd_1.print("D");
      }
    }
  }

  void LedON(int a){
    if(a == 1){
      if(Bt1 == LOW){
        digitalWrite(led1, HIGH);
      }
      else{
        digitalWrite(led1, LOW);
      }
    }
    else{
      if(Bt2 == LOW){
        digitalWrite(led2, HIGH);
      }
      else{
        digitalWrite(led2, LOW);
      }
    }
  }

  void LerBT(int a){
    if(a == 1){
      Bt1 = digitalRead(BT1);
    }
    else{
      Bt2 = digitalRead(BT2);
    }
  }

  void EscreveLDR(){
    lcd_1.setCursor(2, 0);
    lcd_1.print(ldrValor);
  }

  void LerLDR(){
    ldrValor = analogRead(LDR);
  }

  void LerPOT(){
    valorPot = analogRead(Pot);
  }

  void CalcPOT(){
    pwm = map(valorPot, 0, 1023, 0, 255);
    lcd_1.setCursor(13, 1);
    lcd_1.print(pwm);
  }

  void EscrevePot(){
    digitalWrite(led3, pwm);
  }

  void LerTemp(){
    temperatura = float(((((analogRead(LM35)*5.0)/1023)*1000)-500)/10);
  }

  void TempBuzz(){
    if(temperatura > 100){
      tone(buzz, 30);
    }
    else{
      noTone(buzz);
    }
  }

  void EscreveTemp(){
    lcd_1.setCursor(3, 1);
    lcd_1.print(temperatura);
  }

  void loop(){
    Limpa();

    // LED 1
    LerBT(1);
    LedON(1);
    EscreveLed(1);

    // LED 2 
    LerBT(2);
    LedON(2);
    EscreveLed(2);

    // LDR
    LerLDR();
    EscreveLDR();

    // POTENCIOMETRO
    LerPOT();
    CalcPOT();
    EscrevePot();

    // LM35
    LerTemp();
    TempBuzz();
    EscreveTemp();

  }