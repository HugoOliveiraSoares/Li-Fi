#define tam 8

const int led = 13;
char mensagem;
int ascii;
int bin[tam];
int i = 7;
int j = i;
int *p;

void conversor();

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}// end setup

void loop() 
{
  if(Serial.available())
  {
    mensagem = Serial.read();

    conversor();

    p = bin;
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    

    for(int x= 0; x< tam; x++)
    {
      if( *(p+x) == 1)
      {
        digitalWrite(led, HIGH);
        //Serial.print("ligado ");
      }
      else
      {
        digitalWrite(led, LOW); 
        //)Serial.print("desligado ");
      }
         delay(1050);
    }
  }
  else
  {
    delay(500);
    digitalWrite(led,HIGH);
  }


}// end loop

void conversor()
{
  ascii =(int) mensagem;
  Serial.print("ascii");
  Serial.println(ascii);
  if (ascii >= 1)
  {
    while (ascii/2 > 0)
    {
      bin[i] = ascii%2;
      ascii /= 2;
      i--;
      j--;
    }

    for (i = 0; i <j; i++)
      bin[i] = 0;

    bin[j] = 1;

    Serial.print("Binario:");
    for (i = 0; i < tam; i++)
    {
      Serial.print(bin[i]);
    }

  } 
  else if (ascii == 0)
  {
    for (i = 0; i < tam; i++)
    {
      bin[i] = 0;
    }

    Serial.print("Binario:");
    for (i = 0; i < tam; i++)
    {
      Serial.print(bin[i]);
    }

  }
  Serial.print("\n\n");
}


