#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define SENSOR 8

// Ligar FD00FF;
// Vol+ FD807F;
// Stop FD40BF;

// Esquerda FD20DF;
// play FDA05F;
// Direita FD609F;

// Baixo FD10EF;
// Vol- FD906F;
// Cima FD50AF;

// N0 FD30CF;
// EQ FDB04F;
// ST FD708F;

// N1 FD08F7;
// N2 FD8877;
// N3 FD48B7;

// N4 FD28D7;
// N5 FDA857;
// N6 FD6897;

// N7 FD18E7;
// N8 FD9867;
// N9 FD58A7;

IRrecv receptor(SENSOR);
decode_results resultados;

void setup()
{
  receptor.enableIRIn();
  
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop()
{
  if (receptor.decode(&resultados)) {
  	Serial.println(resultados.value, HEX);
    receptor.resume();
    delay(100);
    
    switch (resultados.value){
      case 0xFD00FF:
      	lcd.clear();
      	lcd.setCursor(2, 0);
      	lcd.print("Botao Ligar");
      	break;
      case 0xFD807F:
      	lcd.clear();
      	lcd.setCursor(3, 0);
      	lcd.print("Botao Vol+");
      	break;
      case 0xFD40BF:
      	lcd.clear();
      	lcd.setCursor(3, 0);
      	lcd.print("Botao Stop");
      	break;
      
      case 0xFD20DF:
      	lcd.clear();
      	lcd.setCursor(1, 0);
      	lcd.print("Botao Esquerda");
      	break;
      case 0xFDA05F:
      	lcd.clear();
      	lcd.setCursor(3, 0);
      	lcd.print("Botao Play");
      	break;
      case 0xFD609F:
      	lcd.clear();
      	lcd.setCursor(1, 0);
      	lcd.print("Botao Direita");
      	break;
      
      case 0xFD10EF:
      	lcd.clear();
      	lcd.setCursor(2, 0);
      	lcd.print("Botao Baixo");
      	break;
      case 0xFD906F:
      	lcd.clear();
      	lcd.setCursor(3, 0);
      	lcd.print("Botao Vol-");
      	break;
      case 0xFD50AF:
      	lcd.clear();
      	lcd.setCursor(3, 0);
      	lcd.print("Botao Cima");
      	break;
      
      case 0xFD30CF:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 0");
      	break;
      case 0xFDB04F:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Botao EQ");
      	break;
      case 0xFD708F:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Botao ST");
      	break;
      
      case 0xFD08F7:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 1");
      	break;
      case 0xFD8877:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 2");
      	break;
      case 0xFD48B7:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 3");
      	break;
      
      case 0xFD28D7:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 4");
      	break;
      case 0xFDA857:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 5");
      	break;
      case 0xFD6897:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 6");
      	break;
      
      case 0xFD18E7:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 7");
      	break;
      case 0xFD9867:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 8");
      	break;
      case 0xFD58A7:
      	lcd.clear();
      	lcd.setCursor(4, 0);
      	lcd.print("Numero 9");
      	break;
    }
  }
}