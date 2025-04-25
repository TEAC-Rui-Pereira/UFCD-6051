#include <Arduino.h>
#include <LiquidCrystal.h>

// Define os pinos de conexão com o LCD
const int rs = 11;
const int en = 12;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// Inicializa o objeto LiquidCrystal com os pinos definidos
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Inicializa o LCD
  lcd.begin(16, 2); // Configura o LCD com 16 colunas e 2 linhas

  // Exibe "Exercicio 20" no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Exercicio 20");
  delay(2000); // Aguarda 2 segundos para exibir o título

  // Declara duas variáveis inteiras
  int num1 = 25; // Exemplo: 25
  int num2 = 20; // Exemplo: 20

  // Compara os valores
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Num1: ");
  lcd.print(num1);
  lcd.setCursor(0, 1);
  lcd.print("Num2: ");
  lcd.print(num2);
  delay(3000);

  // Exibe o resultado no monitor serial
  Serial.println("Exercicio 20: Comparacao de Dois Numeros");
  Serial.print("Num1: ");
  Serial.println(num1);
  Serial.print("Num2: ");
  Serial.println(num2);

  lcd.clear();
  lcd.setCursor(0, 0);
  if (num1 > num2) {
    Serial.println("Num1 e maior que Num2");
    lcd.print("Num1 > Num2");
  } else if (num1 < num2) {
    Serial.println("Num1 e menor que Num2");
    lcd.print("Num1 < Num2");
  } else {
    Serial.println("Num1 e igual a Num2");
    lcd.print("Num1 = Num2");
  }
}

void loop() {
  // Não é necessário repetir nada no loop
}