#define A 2
#define B 3
#define DP 4
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8

#define Botao 10

int i;
int incrementando;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(Botao, INPUT_PULLUP);
  
  i = 0;
  incrementando = 1;
}

void loop()  
{
  int valorBotao = digitalRead(Botao);
  Serial.println(valorBotao);
  
  mudarNumero(i);
  
  if (!valorBotao)
  {
    if (incrementando)
    {
      i++;
      if (i == 9)
      {
        incrementando = 0;
      }
    }
    else
    {
      i--;
      if (i == 0)
      {
        incrementando = 1;
      }
    }
    delay(100);
  }
}

void mudarNumero(int n)
{
  switch (n)
  {
    case 0:
    	numero0();
    	break;
    case 1:
    	numero1();
    	break;
    case 2:
    	numero2();
    	break;
    case 3:
    	numero3();
    	break;
    case 4:
    	numero4();
    	break;
    case 5:
    	numero5();
    	break;
    case 6:
    	numero6();
    	break;
    case 7:
    	numero7();
    	break;
    case 8:
    	numero8();
    	break;
    default:
    	numero9();
    	break;
  }
}

void numero0()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void numero1()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void numero2()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero3()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero4()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero5()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero6()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero7()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, LOW);
}

void numero8()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}

void numero9()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
}