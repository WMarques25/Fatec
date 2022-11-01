#include <Adafruit_LiquidCrystal.h>
#define DO 264 
#define RE 297 
#define MI 330 
#define FA 352 
#define SOL 396 
#define LA 440 
#define SI 495

int buzz = 2;
int Bdo = 3;
int Bre = 4;
int Bmi = 5;
int Bfa	= 6;
int Bsol = 7;
int Bla = 8;
int Bsi = 9;
int led = 13;

int BSdo = 0;
int BSre = 0;
int BSmi = 0;
int BSfa = 0;
int BSsol = 0;
int BSla = 0;
int BSsi = 0;
Adafruit_LiquidCrystal lcd_1(0);


void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(Bdo, INPUT);
  pinMode(Bre, INPUT);
  pinMode(Bmi, INPUT);
  pinMode(Bfa, INPUT);
  pinMode(Bsol, INPUT);
  pinMode(Bla, INPUT);
  pinMode(Bsi, INPUT);
  pinMode(led, OUTPUT);
  lcd_1.begin(16, 2);
  lcd_1.print("DO  RE  MI  FA  ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("SOL  LA  SI  LDd");
}

void limpa()
{
  lcd_1.setCursor(2, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(6, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(10, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(14, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(3, 1);
  lcd_1.print(" ");
  lcd_1.setCursor(7, 1);
  lcd_1.print(" ");
  lcd_1.setCursor(11, 1);
  lcd_1.print(" ");
}

void led_on()
{
  digitalWrite(led, HIGH);
  lcd_1.setCursor(15, 1);
  lcd_1.print("l");
  delay(100);
  digitalWrite(led, LOW);
  lcd_1.setCursor(15, 1);
  lcd_1.print("d");
}

void loop() {
 BSdo = digitalRead(Bdo);
  if(BSdo == LOW)
  {
  limpa();
  lcd_1.setCursor(2, 0);
  lcd_1.print("x");
  tone(buzz, DO);
  led_on();
  noTone(buzz);
  }
  
 BSre = digitalRead(Bre);
  if(BSre == LOW)
  {
  limpa();
  lcd_1.setCursor(6, 0);
  lcd_1.print("x");
  tone(buzz, RE);
  led_on();
  noTone(buzz);
  }
  
 BSmi = digitalRead(Bmi);
  if(BSmi == LOW)
  {
  limpa();
  lcd_1.setCursor(10, 0);
  lcd_1.print("x");
  tone(buzz, MI);
  led_on();
  noTone(buzz);
  }
  
 BSfa = digitalRead(Bfa);
  if(BSfa == LOW)
  {
  limpa();
  lcd_1.setCursor(14, 0);
  lcd_1.print("x");
  tone(buzz, FA);
  led_on();
  noTone(buzz);
  }
  
 BSsol = digitalRead(Bsol);
  if(BSsol == LOW)
  {
  limpa();
  lcd_1.setCursor(3, 1);
  lcd_1.print("x");
  tone(buzz, SOL);
  led_on();
  noTone(buzz);
  }
  
 BSla = digitalRead(Bla);
  if(BSla == LOW)
  {
  limpa();
  lcd_1.setCursor(7, 1);
  lcd_1.print("x");
  tone(buzz, LA);
  led_on();
  noTone(buzz);
  }
  
 BSsi = digitalRead(Bsi);
  if(BSsi == LOW)
  {
  limpa();
  lcd_1.setCursor(11, 1);
  lcd_1.print("x");
  tone(buzz, SI);
  led_on();
  noTone(buzz);
  }
  
}