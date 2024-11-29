#define Motor 2
#define Botao 3
#define Verde 9
#define Vermelho 10

void setup()
{
  pinMode(Botao, INPUT_PULLUP);
  pinMode(Verde, OUTPUT);
  pinMode(Vermelho, OUTPUT);
  pinMode(Motor, OUTPUT);
}

void loop()
{
  if (digitalRead(Botao) == LOW){
    digitalWrite(Motor, HIGH);
    digitalWrite(Verde, HIGH);
    digitalWrite(Vermelho, LOW);
  }
  else{
    digitalWrite(Motor, LOW);
    digitalWrite(Verde, LOW);
    digitalWrite(Vermelho, HIGH);
  }
}