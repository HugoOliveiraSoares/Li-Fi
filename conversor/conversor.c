#include <stdlib.h>
#include <stdio.h>

#define tam  8


int caracter_binario();
int binario_caracter();

int main()
{
  int x = 0;

  printf("Conversor\n");
  printf("1 Caracter para binario\n");
  printf("2 Binario para caracter\n");
  scanf("%i",&x);

  if (x==1)
  {
    caracter_binario();
  }

  if (x==2)
  {
    binario_caracter();
  }

  return 0;
}

int caracter_binario()
{

  char caracter;
  int ascii;
  int bin[tam];
  int i = 7;
  int j = i;


  printf("Digite um caracter:");
  scanf("%s", &caracter);

  // caracter para ascii
  ascii=(int) caracter;
  printf("Ascii: %i\n",ascii);

  //ascii para binario
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

    printf("Binario:");
    for (i = 0; i < tam; i++)
    {
      printf("%2i",bin[i]);
    }

  } else if (ascii == 0)
  {
    for (i = 0; i <tam; i++)
    {
      bin[i] = 0;
    }

    printf("Binario:");
    for (i = 0; i <tam; i++)
    {
      printf("%2i",bin[i]);
    }

  }

  printf("\n\n");
}

int binario_caracter()
{

  char caracter;
  int ascii = 0;
  int bin[tam];
  int i = 7;
  int j = i;

  printf("Digite um numero em binario\n");

  for (int a = 0; a < tam; a++)
  {
    scanf("%i",&bin[a]);
  }

  ascii += bin[7] * 1;
  ascii += bin[6] * (2);
  ascii += bin[5] * (2*2);
  ascii += bin[4] * (2*2*2);
  ascii += bin[3] * (2*2*2*2);
  ascii += bin[2] * (2*2*2*2*2);
  ascii += bin[1] * (2*2*2*2*2*2);
  ascii += bin[0] * (2*2*2*2*2*2*2);

  printf("Ascii: %i\n",ascii);
  caracter =(char) ascii;
  printf("%c\n",caracter);

}
