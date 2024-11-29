#define Verde 11
#define Azul 12
#define Vermelho 13

#define Linha1 2
#define Linha2 3
#define Linha3 4
#define Linha4 5

#define Coluna1 6
#define Coluna2 7
#define Coluna3 8
#define Coluna4 9 

void setup()
{
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  pinMode(Vermelho, OUTPUT);
  
  pinMode(Linha1, INPUT);
  pinMode(Linha2, INPUT);
  pinMode(Linha3, INPUT);
  pinMode(Linha4, INPUT);
  
  digitalWrite(Linha1, HIGH);
  digitalWrite(Linha2, HIGH);
  digitalWrite(Linha3, HIGH);
  digitalWrite(Linha4, HIGH);
  
  pinMode(Coluna1, OUTPUT);
  pinMode(Coluna2, OUTPUT);
  pinMode(Coluna3, OUTPUT);
  pinMode(Coluna4, OUTPUT);
  
  digitalWrite(Coluna1, HIGH);
  digitalWrite(Coluna2, HIGH);
  digitalWrite(Coluna3, HIGH);
  digitalWrite(Coluna4, HIGH);
  
  Serial.begin(9600);
}

void loop()
{
  LerCodigo();
  Pressionando();
}

void LerCodigo()
{
  //Linha 1
  if(digitalRead(Linha1) == LOW & digitalRead(Coluna1) == LOW)
  {
    analogWrite(Vermelho, 139);
    analogWrite(Verde, 0);
    analogWrite(Azul, 0);
  }
  
  if(digitalRead(Linha1) == LOW & digitalRead(Coluna2) == LOW)
  {
    analogWrite(Vermelho, 184);
    analogWrite(Verde, 35);
    analogWrite(Azul, 35);
  }
  
  if(digitalRead(Linha1) == LOW & digitalRead(Coluna3) == LOW)
  {
    analogWrite(Vermelho, 230);
    analogWrite(Verde, 51);
    analogWrite(Azul, 51);
  }
  
  if(digitalRead(Linha1) == LOW & digitalRead(Coluna4) == LOW)
  {
    analogWrite(Vermelho, 229);
    analogWrite(Verde, 102);
    analogWrite(Azul, 102);
  }
  
  
  //Linha2
  if(digitalRead(Linha2) == LOW & digitalRead(Coluna1) == LOW)
  {
    analogWrite(Vermelho, 79);
    analogWrite(Verde, 106);
    analogWrite(Azul, 17);
  }
  
  if(digitalRead(Linha2) == LOW & digitalRead(Coluna2) == LOW)
  {
    analogWrite(Vermelho, 106);
    analogWrite(Verde, 135);
    analogWrite(Azul, 38);
  }
  
  if(digitalRead(Linha2) == LOW & digitalRead(Coluna3) == LOW)
  {
    analogWrite(Vermelho, 158);
    analogWrite(Verde, 200);
    analogWrite(Azul, 60);
  }
  
  if(digitalRead(Linha2) == LOW & digitalRead(Coluna4) == LOW)
  {
    analogWrite(Vermelho, 197);
    analogWrite(Verde, 236);
    analogWrite(Azul, 106);
  }
  
  
  //Linha3
  if(digitalRead(Linha3) == LOW & digitalRead(Coluna1) == LOW)
  {
    analogWrite(Vermelho, 6);
    analogWrite(Verde, 120);
    analogWrite(Azul, 153);
  }
  
  if(digitalRead(Linha3) == LOW & digitalRead(Coluna2) == LOW)
  {
    analogWrite(Vermelho, 26);
    analogWrite(Verde, 163);
    analogWrite(Azul, 203);
  }
  
  if(digitalRead(Linha3) == LOW & digitalRead(Coluna3) == LOW)
  {
    analogWrite(Vermelho, 84);
    analogWrite(Verde, 191);
    analogWrite(Azul, 222);
  }
  
  if(digitalRead(Linha3) == LOW & digitalRead(Coluna4) == LOW)
  {
    analogWrite(Vermelho, 156);
    analogWrite(Verde, 231);
    analogWrite(Azul, 252);
  }
  
  
  //Linha4
  if(digitalRead(Linha4) == LOW & digitalRead(Coluna1) == LOW)
  {
    analogWrite(Vermelho, 139);
    analogWrite(Verde, 128);
    analogWrite(Azul, 0);
  }
  
  if(digitalRead(Linha4) == LOW & digitalRead(Coluna2) == LOW)
  {
    analogWrite(Vermelho, 240);
    analogWrite(Verde, 221);
    analogWrite(Azul, 0);
  }
  
  if(digitalRead(Linha4) == LOW & digitalRead(Coluna3) == LOW)
  {
    analogWrite(Vermelho, 255);
    analogWrite(Verde, 240);
    analogWrite(Azul, 66);
  }
  
  if(digitalRead(Linha4) == LOW & digitalRead(Coluna4) == LOW)
  {
    analogWrite(Vermelho, 255);
    analogWrite(Verde, 245);
    analogWrite(Azul, 133);
  }
}

void Pressionando()
{
  while(digitalRead(Coluna1) == LOW | digitalRead(Coluna2) == LOW | digitalRead(Coluna3) == LOW | digitalRead(Coluna4) == LOW)
  { }
}