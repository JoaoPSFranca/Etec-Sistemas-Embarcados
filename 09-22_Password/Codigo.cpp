#include <IRremote.h>

#define SENSOR 8
#define VERMELHO 6
#define AZUL 5
#define VERDE 3

// Nome das teclas e o valor em HEX

// Ligar FD00FF;
// Vol+ FD807F;
// Func/Stop FD40BF;

// Esquerda FD20DF;
// play FDA05F;
// Direita FD609F;

// Baixo FD10EF;
// Vol- FD906F;
// Cima FD50AF;

// N0 FD30CF;
// EQ FDB04F;
// ST/Rept FD708F;

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


String senhaInserida = "";
String senhaCorreta = "12345";

void setup()
{
  
  pinMode(VERMELHO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  
  receptor.enableIRIn();
  
  Serial.begin(9600);
}

void loop()
{
  if (receptor.decode(&resultados)) {
    switch(resultados.value) 
    {
		case(0xFD08F7):
			senhaInserida += "1";
            break;
      	case(0xFD8877):
      		senhaInserida += "2";
            break;
      	case(0xFD48B7):
      		senhaInserida += "3";
            break;
      	case(0xFD28D7):
      		senhaInserida += "4";
            break;
      	case(0xFDA857):
      		senhaInserida += "5";
            break;
      	case(0xFD6897):
      		senhaInserida += "6";
            break;
      	case(0xFD18E7):
      		senhaInserida += "7";
            break;
      	case(0xFD9867):
      		senhaInserida += "8";
            break;
      	case(0xFD58A7):
      		senhaInserida += "9";  	
    }
    if (senhaInserida.length() == 5) 
    {
      if (senhaCorreta == senhaInserida)
      {
        digitalWrite(VERMELHO, LOW);
        digitalWrite(VERDE, HIGH);
		digitalWrite(AZUL, LOW);
        delay(5000);
        senhaInserida = "";
      }
      else 
      {
        digitalWrite(VERMELHO, HIGH);
        digitalWrite(VERDE, LOW);
        digitalWrite(AZUL, LOW);
      }
    }
    receptor.resume();
    delay(100);
  }
}