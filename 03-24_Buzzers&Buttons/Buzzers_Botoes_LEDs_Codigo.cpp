//1 e 2 não deu tão certo infelizmente, mas 5 é a melhor 

#define Botao1 2
#define Botao2 3
#define Botao3 4
#define Botao4 5
#define Botao5 6
#define Botao6 7

#define Buzzer1 8
#define Buzzer2 9
#define Buzzer3 10
#define Buzzer4 11
#define Buzzer5 12

#define Leds_Vermelhos 13

#define C2 65.40639
#define C_2 69.29566
#define D2 74.41619
#define D_2 77.78175
#define E2 82.40689
#define F2 87.30706
#define F_2 92.49861
#define G2 97.99886
#define G_2 103.8262
#define A2 110
#define A_2 116.5409
#define B2 123.4708

#define C3 130.8128
#define C_3 138.5913
#define D3 146.8324
#define D_3 155.5635
#define E3 164.8138
#define F3 174.6141
#define F_3 184.9972
#define G3 195.9977
#define G_3 207.6523
#define A3 220
#define A_3 233.0819
#define B3 246.9417

#define C4 261.6256
#define C_4 277.1826
#define D4 293.6648
#define D_4 311.1270
#define E4 329.6276
#define F4 349.2282
#define F_4 369.9944
#define G4 391.9954
#define G_4 415.3047
#define A4 440
#define A_4 466.1638
#define B4 493.8833

#define C5 523.2511
#define C_5 554.3653
#define D5 587.3295
#define D_5 622.2540
#define E5 659.2551
#define F5 698.4565
#define F_5 739.9888
#define G5 783.9909
#define G_5 830.6094
#define A5 880
#define A_5 932.3275
#define B5 987.7666

#define C6 1046.502
#define C_6 1108.731
#define D6 1174.659
#define D_6 1244.508
#define E6 1318.510
#define F6 1396.913
#define F_6 1479.978
#define G6 1567.982
#define G_6 1661.219
#define A6 1760
#define A_6 1864.655
#define B6 1975.533

#define TEMPO 1000
#define MEIO_TEMPO 500

void setup()
{
  pinMode(Botao1, INPUT_PULLUP);
  pinMode(Botao2, INPUT_PULLUP);
  pinMode(Botao3, INPUT_PULLUP);
  pinMode(Botao4, INPUT_PULLUP);
  pinMode(Botao5, INPUT_PULLUP);
  pinMode(Botao6, INPUT_PULLUP);
  
  pinMode(Buzzer1, OUTPUT);
  pinMode(Buzzer2, OUTPUT);
  pinMode(Buzzer3, OUTPUT);
  pinMode(Buzzer4, OUTPUT);
  pinMode(Buzzer5, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int ValorBotao1 = digitalRead(Botao1);
  int ValorBotao2 = digitalRead(Botao2);
  int ValorBotao3 = digitalRead(Botao3);
  int ValorBotao4 = digitalRead(Botao4);
  int ValorBotao5 = digitalRead(Botao5);
  int ValorBotao6 = digitalRead(Botao6);
  
  Serial.println(ValorBotao1);
  
  if(!ValorBotao1) //Darth Vader que deu errado
  {
    tone(Buzzer1, A2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, A2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, A2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, F2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, C3, MEIO_TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, A2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, F2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, C3, MEIO_TEMPO);
  	delay(TEMPO);
    tone(Buzzer1, A2, TEMPO);
  	delay(3000);
  }
  
  if(!ValorBotao2)  //Bad Guy que deu certo mais ou menos
  {
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, A_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, A_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, F2, TEMPO);
  	delay(TEMPO);
    
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, A_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, G2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, A_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, F2, TEMPO);
  	delay(TEMPO);
    
    tone(Buzzer2, C3, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, C3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, D_3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, C3, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, C3, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, C3, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, C3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, D_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, G2, TEMPO);
  	delay(TEMPO);
    
    tone(Buzzer2, D2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, D2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, F_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, D2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, D2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, D2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, D2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, F_2, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer2, F2, TEMPO);
  	delay(TEMPO);
    tone(Buzzer2, A2, TEMPO);
  	delay(3000);
  }
  
  if(!ValorBotao3)  //Asa Branca que deu bom
  {
    tone(Buzzer3, F4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, D4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, E4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, C4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, D4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, B3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, C4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, A3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, B3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, G3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, A3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, G3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, E3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, G3, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer3, G3, MEIO_TEMPO);
  	delay(3000);
  }
  
  if(!ValorBotao4)  //HP ta brabo
  {
    tone(Buzzer4, B3, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, E4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, G4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer4, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer4, E4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, B4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer4, A4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, F_4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, E4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, G4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer4, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer4, D_4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, F4, TEMPO);
  	delay(TEMPO);
    tone(Buzzer4, B3, TEMPO);
  	delay(3000);
  }
  
  if(!ValorBotao5)  //Um Morto Muito Louco a braba
  {
    tone(Buzzer5, E4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, G_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, A4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, A4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, G_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    
    tone(Buzzer5, E4, 250);
  	delay(250);
    tone(Buzzer5, F_4, 250);
  	delay(250);
    tone(Buzzer5, E4, 250);
  	delay(250);
    tone(Buzzer5, F_4, 250);
  	delay(250);
    
    tone(Buzzer5, E4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, G_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, A4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, A4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, F_4, MEIO_TEMPO);
  	delay(MEIO_TEMPO);
    tone(Buzzer5, G_4, MEIO_TEMPO);
  	delay(3000);
  }
  
  if(!ValorBotao6)
  {
  	digitalWrite(Leds_Vermelhos, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(Leds_Vermelhos, LOW);
    delay(1000);
  }
}