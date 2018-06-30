#include <stdlib.h>
#include <stdio.h>

char c[8];
int d[8];
int b[8];


int caracter_ascii();
int ascii_caracter();
int ascii_bin();

int main()
{

  int x;

  printf("Escolha:\n");
  printf("1 caracter para ascii\n");
  printf("2 ascii para caracter\n");
  printf("3 ascii para binario\n");
  scanf("%i",&x);

  if(x==1)
  {
    caracter_ascii();
  }
  if (x==2)
  {
    ascii_caracter();
  }
  if (x==3)
  {
    ascii_bin();
  }


  return 0;
}

int caracter_ascii()
{

    for(int i=0; i<8; i++)
    {
      scanf("%s",&c[i]);
    }

    for (int i =0; i<8; i++)
    {
      d[i]=(int) c[i];
      printf("%i\n",d[i]);
    }
}

int ascii_caracter()
{

    for(int i=0; i<8; i++)
    {
      scanf("%i",&d[i]);
    }

    for (int i=0; i<8; i++)
    {
      c[i]=(char) d[i];
      printf("%c\n",c[i]);
    }
}

int ascii_bin()
{

  int bits = 8;
  int num = 0;
  int vetor[bits];
  int i = bits -1;
  int j = i;


  printf("Digite um numero\n");
  scanf("%i",&num);
  printf("\n");

  if (num >= 1)
  {
    while (num/2 > 0)
    {
      vetor[i] = num%2;
      num /= 2;
      i--;
      j--;
    }

    for (i = 0; i <j; i++)
      vetor[i] = 0;

    vetor[j] = 1;

    for (i = 0; i < bits; i++)
    {
      printf("%i",vetor[i]);
    }

  } else if (num == 0)
  {
    for (i = 0; i <bits; i++)
    {
      vetor[i] = 0;
    }

    for (i = 0; i <bits; i++)
    {
      printf("%i",vetor[i]);
    }

  }

  printf("\n\n");


}
