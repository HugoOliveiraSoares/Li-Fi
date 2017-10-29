
#define tam 8

int byt = 0;
const int LDR = 0;
int valorlido[10]; // armazena valor do LDR
int valorbyt;
int valor, valormedio;
boolean flag = false;
int vetor[tam];
int Sdf[4];
int i;

void leitura();
void calibra();
void sdf();

void setup() {
  // Inicializa a comunicacao serial a 9600 bits por segundo:
  Serial.begin(9600);
  calibra();
}// end setup

void loop() {
  //calibra();
  //start:
  //leitura();
  //goto start;
  
  //if( flag==true )// verifica se acomunicação ira começar
  //{
    for(i=0;i<tam;i++)// le os dados
    {
      leitura();
      vetor[i] = byt;
      Serial.print(vetor[i]);
    }
    Serial.print(" |\n");
    //flag = false;
  //}
  
}// end loop

void leitura()
{
  //calibra();
  int comp, comp1;
  comp = valormedio*1,5;
  comp1 = valormedio*1,3;
  
  valorbyt = analogRead(LDR);

  if(valorbyt <= comp1)
    byt = 0;

  
  if(valorbyt >= comp)
    byt = 1;

 
 //Serial.print("byt:");
 //Serial.println(byt);
 delay(1000);

}// end leitura

void calibra()
{
  int i;
   for ( i = 0 ; i < 10 ; i++)
   {
     valorlido[i] = analogRead(LDR);
     delay(50);
   }
  for ( i = 0 ; i < 10 ; i++)
  {
    valor += valorlido[i];
    /*
    Serial.print("valorlido:");
    Serial.println(valorlido[i]);
    Serial.print("valor:");
    Serial.println(valor);
    */
  }
  valormedio = valor/10;

  Serial.print("Valor medio");
  Serial.println(valormedio);

}// end calibra

/*
void sdf()
{
  for(i=0;i<4;i++)
  {
    Sdf[i] = byt;
  }// end for

  if(vetor[1]==1)
  {
    if(vetor[2]==1)
    {
      if(vetor[3]==1)
      {
        if(vetor[4]==1)
        {
          flag==true;
        }
      }
    }
  }// end if
}// end sdf*/
