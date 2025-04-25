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

  // Exibe "Exercicio 9" no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Exercicio 9");
  delay(2000); // Aguarda 2 segundos para exibir o título

  // Instruções para o usuário no monitor serial
  Serial.println("Exercicio 9: Ler Dados do Utilizador");
  Serial.println("Digite um numero inteiro:");
}

void loop() {
  static int etapa = 0; // Controla qual dado está sendo lido
  static int inteiro;
  static float decimal;
  static char caractere;

  if (Serial.available() > 0) {
    if (etapa == 0) {
      // Lê um número inteiro
      inteiro = Serial.parseInt();
      Serial.println("Digite um numero decimal:");
      etapa++;
    } else if (etapa == 1) {
      // Lê um número decimal
      decimal = Serial.parseFloat();
      Serial.println("Digite um caractere:");
      etapa++;
    } else if (etapa == 2) {
      // Lê um caractere
      caractere = Serial.read();
      while (caractere == '\n' || caractere == '\r') {
        caractere = Serial.read(); // Ignora caracteres de nova linha
      }

      // Exibe os valores no LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Int:");
      lcd.print(inteiro);
      delay(2000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Float:");
      lcd.print(decimal);
      delay(2000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Char:");
      lcd.print(caractere);
      delay(2000);

      // Exibe os valores no monitor serial
      Serial.println("\nValores lidos:");
      Serial.print("Inteiro: ");
      Serial.println(inteiro);
      Serial.print("Decimal: ");
      Serial.println(decimal);
      Serial.print("Caractere: ");
      Serial.println(caractere);

      // Reinicia a leitura
      etapa = 0;
      Serial.println("\nDigite um numero inteiro:");
    }
  }
}