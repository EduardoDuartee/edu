#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int opcao;
float num1, num2,soma;
char operaC;
int calculadora(){
    system("cls");
    printf("\n=====Bem-Vindo a Calculadora=====");
    
    printf("\nEscolha uma Operação\n1 - Somar +\n2 - Diminuir -\n3 - Multiplicar *\n4 - Dividir  \n5 - Faça voce\n6 - Sair");
    printf("\nEscolha uma opção > ");
    scanf("%d", &opcao);
//-------------------braker--------------------------------
switch(opcao){
        case 1:
        printf("\nDigite um numero:");
        scanf("%f", &num1);
        printf("\nDigite um numero:");
        scanf("%f", &num2);
        soma = num1 + num2;

        printf("%.2f + %.2f = %.2f", num1, num2, soma);
        break;
    //=====================================================
        case 2:
        printf("\nDigite um numero:");
        scanf("%f", &num1);
        printf("\nDigite um numero:");
        scanf("%f", &num2);
        soma = num1 - num2;

        printf("%.2f - %.2f = %.2f", num1, num2, soma);
        break;
    //=====================================================
        case 3:
        printf("\nDigite um numero");
        scanf("%f", &num1);
        printf("\nDigite um numero");
        scanf("%f", &num2);
        soma = num1 * num2;

        printf("%.2f * %.2f = %.2f", num1, num2, soma);
        break;

        case 4:
        printf("\nDigite um numero:");
        scanf("%f", &num1);
        printf("\nDigite um numero:");
        scanf("%f", &num2);
        soma = num1 / num2;

        printf("%.2f / %.2f = %.2f", num1, num2, soma);
        break;

        case 5:

    
        scanf("%f %c %f" , &num1, &operaC ,&num2);
    //=====================================================

    switch (operaC){
            scanf(" %c", &operaC);
            case  '+' :
            soma = num1 + num2;
                printf("\n%.2f + %.2f = %.2f", num1, num2, soma);
            break;

                case  '-' :
            soma = num1 + num2;
                printf("\n%.2f - %.2f = %.2f", num1, num2, soma);
            break;

                case  '*' :
            soma = num1 * num2;
                printf("\n%.2f * %.2f = %.2f", num1, num2, soma);
            break;

                case  '/' :
            soma = num1 / num2;
                printf("\n%.2f / %.2f = %.2f", num1, num2, soma);
            break;

            default:
            printf("Operação não permitida");

            break;
        }
        case 6:
            main();
        break;
    }
    main();
}

