#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int boletim()
{
   system("cls");
    float nota1, nota2, nota3, nota4, nota5;
    float media, maior, menor;
    int idade;
    char nome[50];

    printf("\n====Boletim Escolar====\n\n");

    printf("Informe um nome:");
    scanf("%s", nome);

    printf("informe a sua idade:");
    scanf("%d", &idade);

    printf("informe sua 1° nota:");
    scanf("%f", &nota1);

    printf("informe sua 2° nota:");
    scanf("%f", &nota2);

    printf("informe sua 3° nota:");
    scanf("%f", &nota3);

    printf("informe sua 4° nota:");
    scanf("%f", &nota4);

    printf("informe sua 5° nota:");
    scanf("%f", &nota5);

   media = (nota1 + nota2 + nota3 + nota4 + nota5)/5;
   //-----------------resultado--------------------------------

    printf("====Resultado====\n\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Nota1: %.2f\n", nota1);
    printf("Nota2: %.2f\n", nota2);
    printf("Nota3: %.2f\n", nota3);
    printf("Nota4: %.2f\n", nota4);
    printf("Nota5: %.2f\n", nota5);
    printf("A media é:%.2f", media);

//-------------------------Aprov&Reprov-----------------------------

   if(media >= 7)
   {
    printf("\nSua nota final é:%.2f\nAprovado\n", media);
   }
   if(media >= 5 && media<7)
   {
    printf("\nMedia é:%.2f\nRecuperação", media);
   }
   else{
    printf("\nReprovado");
   }

//-----------------------maior nota---------------------------------
   printf("\n===Notas Maiores e Menores===\n");
   if (maior <= nota1)
   {
        maior = nota1;
   }
   if(maior <= nota2)
   {
        maior = nota2;
   }
   if(maior <= nota3)
   {
        maior = nota3;
   }
   if(maior <= nota4)
   {
        maior = nota4;
   }
   if (maior<= nota5)
   {
        maior = nota5;
   }

   printf("\n====Maior Nota====\nA maior nota é:%.2f", maior,"\n----------------------------------------------------");

//-----------------------------menor nota-----------------------------------------------------
   menor=nota1;
   if (menor >= nota1)
   {
        menor = nota1;
   }
   if(menor >= nota2)
   {
        menor = nota2;
   }
   if(menor >= nota3)
   {
        menor = nota3;
   }
   if(menor >= nota4)
   {
        menor = nota4;
   }
   if (menor>= nota5)
   {
        menor = nota5;
   }

   printf("\n\n====Menor Nota====\n\nA menor nota é:%.2f", menor);


//---------------------notas maiores---------------------------------
   printf("\nNotas aprovadas e reprovadas");
   maior = nota1;
   if(media <= nota1)
   {
     printf("\nnotas acima da Media%.2f", nota1);
   }
      if(media <= nota2)
   {
     printf("\nnotas acima da Media:%.2f", nota2);
   }
      if(media <= nota3)
   {
     printf("\nnotas acima da Media:%.2f", nota3);
   }
      if(media <= nota4)
   {
     printf("\nnotas acima da Media:%.2f", nota4);
   }
      if(media <= nota5)
   {
     printf("\nnotas acima da Media:%.2f", nota5);
   }
//------------------notas menores-----------------------------
   menor = 5;
   if(media <= nota1)
   {
     printf("\nnotas abaixo da Media:%.2f", nota1);
   }
      if(media <= nota2)
   {
     printf("\nnotas abaixo da Media:%.2f", nota2);
   }
      if(media <= nota3)
   {
     printf("\nnotas abaixo da Media:%.2f", nota3);
   }
      if(media <= nota4)
   {
     printf("\nnotas abaixo da Media:%.2f", nota4);
   }
      if(media <= nota5)
   {
     printf("\nnotas abaixo da Media:%.2f", nota5);
   }
      printf("\n-----------------------------------------------");
   //main();

}
