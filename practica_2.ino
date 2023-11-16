#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int inputPin = 7;

int value = 0;
int matriculaIndex = 0;

String matriculas[] = {"202253420","2","3","4","5","6"};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Matriculas");
  lcd.setCursor(0, 1);
  lcd.print("Oprima el boton");
  // Print a message to the LCD.

  pinMode(inputPin, INPUT);    // sets the digital pin 7 as input
}

void loop() {

  value = digitalRead(inputPin);

  if (value) {
    lcd.clear();
    lcd.print("Matricula:");
    lcd.setCursor(0, 1);
    lcd.print(matriculas[matriculaIndex]);
    delay(1000);
    matriculaIndex = (matriculaIndex + 1) % (sizeof(matriculas) / sizeof(matriculas[0]));
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Matriculas");
  }
} 
