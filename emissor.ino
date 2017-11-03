#define tam 8

const int ledPin = 9;
char mensagem;
int ascii;
int bin[tam];
int i = 7;
int j = i;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}// end setup

void loop() 
{
  if(Serial.available())
  {
    for(int i=0; i<tam; i++)
    {
      mensagem = Serial.readString();
      ascii =(int) mensagem;
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
          Serial.print("%2i",bin[i]);
        }

      } 
      else if (ascii == 0)
      {
        for (i = 0; i <tam; i++)
        {
          bin[i] = 0;
        }

        Serial.print("Binario:");
        for (i = 0; i <tam; i++)
        {
          Serial.print("%2i",bin[i]);
        }

      }

      Serial.print("\n\n");
    }


  }
  else
  {
    digitalWrite(ledPin,HIGH);
  }

}// end loop

