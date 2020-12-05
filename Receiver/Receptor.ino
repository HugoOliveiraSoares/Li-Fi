 
#define tam 8

int byt = 0;
const int LDR = 0;
int valorlido[10]; // armazena valor do LDR
int valorbyt = 0;
int valor, valormedio, lastvalor = 0;
boolean flag = false;
int bin[tam]; // armazena os dados em binario
int ascii = 0;// armazena os dados em ascii
char caracter;// armazena os dados em caracteres
int i = 0;

void leitura();
void calibra();
void conversor();
void sdf();

void setup() 
{
  // Inicializa a comunicacao serial a 9600 bits por segundo:
  Serial.begin(9600);
  calibra();
}// end setup

void loop() 
{
  //calibra();
  start:
  //leitura();
  //goto start;
  
// sdf();
 
 //if( flag==true )// verifica se acomunicação ira começar
 //{
    delay(500);
    for(i=0;i<tam;i++)// le os dados
    {
      leitura();
      bin[i] = byt;
      Serial.print(bin[i]);
      delay(50);
    }
    Serial.print(" \n"); 
    conversor();
    //flag = false;
  //}else
  //{
   //goto start; 
  //}
  
}// end loop

void leitura()
{
  //calibra();
  int comp, comp1 = 0;
  comp = valormedio*1,5;
  comp1 = valormedio*1,3;
  
  valorbyt = analogRead(LDR);

  if(valorbyt <= comp1)
    byt = 0;

  
  if(valorbyt >= comp)
    byt = 1;
    

 
 //Serial.print("byt:");
 //Serial.println(byt);
 //Serial.print("valorbyt: ");
 //Serial.println(valorbyt);
 delay(1000);

}// end leitura

void calibra()
{
  int i;
   for ( i = 0; i < 10; i++)
   {
     valorlido[i] = analogRead(LDR);
     delay(100);
   }
  for ( i = 0; i < 10; i++)
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
  
  lastvalor = valormedio;
 

}// end calibra

void conversor()
{
  ascii += bin[7] * 1;
  ascii += bin[6] * (2);
  ascii += bin[5] * (2*2);
  ascii += bin[4] * (2*2*2);
  ascii += bin[3] * (2*2*2*2);
  ascii += bin[2] * (2*2*2*2*2);
  ascii += bin[1] * (2*2*2*2*2*2);
  ascii += bin[0] * (2*2*2*2*2*2*2);
  Serial.print(" ascii: ");
  Serial.print(ascii);
  //Serial.print("\n");
  caracter = (char) ascii;
  Serial.print(" Caracter: ");
  Serial.print(caracter);
  Serial.print("\n");
  ascii = 0;
}


void sdf()
{
  int sdfcomp, sdfcomp1, bite = 0;
  int Sdf[4];
  int *p;

  
  sdfcomp = valormedio*1,3;
  sdfcomp1 = valormedio*1,5;
  
  lastvalor = analogRead(LDR);
  
  if(lastvalor != valormedio)
  {
    valorbyt = analogRead(LDR);
    
    
    for(int x=0; x<4; x++)// le os dados
      {
        if(valorbyt >= sdfcomp1)
            bite = 1;
  
    
        if(valorbyt <= sdfcomp)
            bite = 0;
            
         Sdf[x] = bite;
         //Serial.print("Sdf: ");
         //Serial.print(Sdf[x]);
         delay(50);
      }
      //Serial.print("\n");
      
     p = Sdf;
      
     if( *(p+0) == 1 && *(p+1) == 1 && *(p+2) == 1 && *(p+3) == 1)
      {
       flag = true;
      }
      else
      {
        flag = false;
      }
  }
    
}// end sdf
