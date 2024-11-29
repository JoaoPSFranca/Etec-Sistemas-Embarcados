/*	
Um relogio com funções de cronometro e temporizador

Cronometro: 
	A partir de uma duração inserida, 
	o tempo vai diminuindo até chegar a zero.
    
Temporizador:
	Fica mostrando o tempo desde que foi apertado em iniciar
 
São 6 botões de comando

	A: Inicia se estiver parado, e para se estiver rodando
	B: Recomça a contagem e para
	C: Ativa o modo Temporizador
	D: Ativa o modo Cronometro
	*: Move o cursor para a esquerda
	#: Move o cursor para a direita
    
Nota: 
	Existe bastante erros para todo que é lado, 
	mas 99% deles, é causado pelo tinkercad,
    Então tem partes que tá implementada e deveria 
    funcionar mas não funciona.

*/
#include <LiquidCrystal.h> 
#define PinBuzzer 12

struct Posicao {
  byte Linha;
  byte Coluna;
  bool operator==(const Posicao& Pos2){
    return this->Linha  == Pos2.Linha 
        && this->Coluna == Pos2.Coluna;
  }
  bool Valida(){
    return Linha < 4 || Coluna < 4;
  }
  String toString(){
    return String(Linha) + ":" + String(Coluna); 
  }
}; 
class Teclado{  

  public:    
    byte C[4];
    byte L[4]; 
    Posicao PosAnterior = {200,200}; 
  
    Teclado(byte L1,byte  L2,byte L3,byte L4,byte C1,byte C2,byte C3,byte C4)
      :C{C1,C2,C3,C4}
      ,L{L1,L2,L3,L4}
    {      
      
      for(byte i = 0; i < 4;i++) {
        pinMode(L[i], INPUT_PULLUP);
        pinMode(C[i], OUTPUT);
        digitalWrite(L[i], HIGH); 
      };
    }
    struct Posicao PosTeclaAtual(){
      for(byte c = 0; c < 4; c++)
        digitalWrite(C[c], true);
      for(byte c = 0; c < 4; c++){
        digitalWrite(C[c], false); 
        for(byte l = 0; l < 4; l++){ 
            if(!digitalRead(L[l])){
              digitalWrite(C[c], true);
              Posicao PosAtual = {l,c};  
              return PosAtual;
            }
        } 
        digitalWrite(C[c], true);
      }
      return {200, 200};
    }  
    char TeclaAtual(){
      return ' ';
    }
  void AguardarFim(struct Posicao Pos){
    digitalWrite(C[Pos.Coluna], false);   
    while(!digitalRead(L[Pos.Linha])){}
  }
  void AguardarMudanca(){ 
    PosAnterior = PosTeclaAtual();
    while(PosAnterior == PosTeclaAtual()){};
  };
  
};
struct Tempo {
  long Hor;
  long Min;
  long Seg;
  long mSeg;
  Tempo(){};
  Tempo(long span){
    setSpan(span);
  }
  long getSpan()
  {
    return (mSeg+1000*(Seg+60*(Min+60*(Hor))));
  } 
  void setSpan(const long& span){ 
    Hor  = ( span            ) / (3600000);
    Min  = ( span %(3600000) ) / (  60000);
    Seg  = ( span %(  60000) ) / (   1000);
    mSeg = ( span %(   1000) ) / (      1);  
  }
  String toString(){
    return (Hor  < 10  ? "0" : "") + String(Hor) + "h:"
         + (Min  < 10  ? "0" : "") + String(Min) + "m:"
         + (Seg  < 10  ? "0" : "") + String(Seg) + "S." 
         + (mSeg < 100 ? "0" : "") + String(mSeg/10) +"mS"; 
  }
  struct Tempo operator-(long span){
    return Tempo(getSpan() - span);;
  }
};



class Ferramenta { 
protected:
  LiquidCrystal LCD = LiquidCrystal(0,0,0,0,0,0);
  bool Parado = true;
  long _TempoPercorrido=0;
  long MomentoInicio=0;
protected:
  long getTempoPercorrido(){ 
    if(Parado)
      return _TempoPercorrido;
    else
      return _TempoPercorrido +  millis() - MomentoInicio;
  }
  void MostrarMomento(struct Tempo Momento)
  { 
    LCD.setCursor(0,0); 
    LCD.print(Momento.toString());   
  }
  virtual void _Iniciar() = 0;
  virtual void _Parar() = 0;
  virtual void _Reiniciar() = 0;
public:   
  Ferramenta(LiquidCrystal lcd){
    LCD = lcd;
  }
  void Iniciar(){
  	MomentoInicio = millis();
    _Iniciar();
  };
  void Parar(){
  	_TempoPercorrido +=  millis() - MomentoInicio  ;
    _Parar();
  };
  void Reiniciar(){
    Parado = true;
    _TempoPercorrido = 0;
    MomentoInicio = 0;
  };
  virtual void Atualizar()=0;
  virtual void TeclaApertada(char Tecla)=0;
  void IniciarParar() {
    Parado = !Parado;
    if (Parado) 
      Iniciar();
    else
      Parar();  
  }

};

class Cronometro : public Ferramenta 
{  
private:
  Tempo Duracao;
  byte IndexCursor; 
  bool DefinindoDuracao = true;
  int InserirDigito(int Numero, int NumeroInserir, int Indice)
  {
    int pot = pow(10,Indice); 
    return Numero - Numero % (pot*10) + Numero % pot +  NumeroInserir*pot;
  };
protected:
  void _Iniciar(){ 
    DefinindoDuracao = false;
  };
  void _Parar(){};
  void _Reiniciar(){
    DefinindoDuracao = true;
  }; 
public: 
  
  Cronometro(LiquidCrystal lcd)
    :Ferramenta(lcd){} 
  
  void TeclaApertada(char Tecla){
    if(DefinindoDuracao){
      if(Tecla >= '0' && Tecla <= '9')
      { 
        int MaxIndex, MaxVal;
        long* PtrVar;
        switch(IndexCursor){
          case 0 ... 1: PtrVar = &Duracao.Hor;   MaxIndex = 1; MaxVal = 100; break;
          case 2 ... 3: PtrVar = &Duracao.Min;   MaxIndex = 3; MaxVal = 60 ; break;  
          case 4 ... 5: PtrVar = &Duracao.Seg;   MaxIndex = 5; MaxVal = 60 ; break;   
          case 6 ... 7: PtrVar = &Duracao.mSeg;  MaxIndex = 7; MaxVal = 100; break;   
        }  
        
        long Aux = InserirDigito(*PtrVar, Tecla-'0', MaxIndex-IndexCursor ); 
        if(Aux < MaxVal){
          IndexCursor++;
          *PtrVar = Aux;
        }

      }
      else if (Tecla == '*')
        IndexCursor--;
      else if (Tecla == '#')
        IndexCursor++;

      if(IndexCursor > 7)
        IndexCursor = 7;
      if(IndexCursor < 0)
        IndexCursor = 0;
    }  
  };
  void Atualizar(){
    Serial.println(getTempoPercorrido());
    if(Duracao.getSpan()- getTempoPercorrido()< 0 ){
      TocarBuzzer();
      Reiniciar();
    }
    LCD.clear();    
    
    if(DefinindoDuracao)
      MostrarMomento(Duracao); 
    else 
      MostrarMomento(Duracao - getTempoPercorrido());
    
    if(DefinindoDuracao && millis() % 1000 < 500)
      MostrarCursor();
     
    //Serial.println(getTempoPercorrido());
  } 
  void MostrarCursor(){
     LCD.setCursor(IndexCursor + 2*floor(IndexCursor/2),0);
     LCD.print('_'); 
  }

  void TocarBuzzer(){
    tone(PinBuzzer,500);
  	delay(500);
  	noTone(PinBuzzer);
  }
};

class Temporizador : public Ferramenta{
protected:
  void _Iniciar(){};
  void _Parar(){};
  void _Reiniciar(){}; 
public:
  Temporizador(LiquidCrystal lcd)
    :Ferramenta(lcd){};
  void TeclaApertada(char Tecla){};
  void Atualizar(){
    MostrarMomento(Tempo(getTempoPercorrido()));
  }; 
}; 
const char GridChar[4][4] 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};  
Teclado Tec(11,10,9,8,7,6,5,4);
LiquidCrystal LCD(A0,A1,A2,A3,A4,A5);
Ferramenta* ferramentaAtual; 

void setup() { 
  ferramentaAtual = new Temporizador(LCD);
  Serial.begin(9600);
   LCD.begin(16,2);
  pinMode(PinBuzzer, OUTPUT); 

}


void loop() { 
  Posicao Pos = Tec.PosTeclaAtual();  
  if (millis() % 100 == 0)
    ferramentaAtual->Atualizar();
  if(Pos.Valida()){ 
    char Tecla =  GridChar[Pos.Linha][Pos.Coluna];
    switch(Tecla){
      case 'A': ferramentaAtual->IniciarParar() ;     break;
      case 'B': ferramentaAtual->Reiniciar()  ;     break;
      case 'C': ferramentaAtual = new Temporizador(LCD); break;
      case 'D': ferramentaAtual = new Cronometro(LCD);   break;
      default : ferramentaAtual-> TeclaApertada(Tecla); break;
    }
    Tec.AguardarMudanca();  
    //Serial.println(Pos.toString());

  } 
}
