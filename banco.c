#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

    float dinheiro = 1000, adicionar, sacar, resultado,investimento,rendimento, somatotal;
    int escolha, i, mes;
int banco(){
    printf("\n\n===Bem vindo ao banco SENAI===\n");
    printf("\n1 - Consultar Saldo\n2 - Depositar\n3 - Sacar\n4 - Rendimentos\n5 - sair> ");

    acoes();

//======================================================escolha=========================================================


}


void acoes(){
        
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        printf("\n\n===================================\nSeu Saldo é >");
        printf("%.3f", dinheiro);
        banco();
    break;
    
    case 2:
    system("cls");
        printf("\n\n==Bem Vindo A Area de Deposito==\nValor Deposito:");
        scanf("%f", &adicionar);
        printf("\nO Valor Depositado %.3f", adicionar);
        resultado = dinheiro + adicionar;

       

        printf("\nSeu saldo Atual é %.3f", resultado);
         banco();
    break;

    case 3:
        printf("\n\n==Bem Vindo A Area de Saque==\nValor De Saque:");
        scanf("%f", &sacar);
        //printf("\nO Valor Do Saque %.3f", sacar);
        resultado = resultado - sacar;

        printf("\nSeu saldo Atual é %.3f\n", resultado);

        banco();
    break;

    case 4:
    

        printf("Quantos meses voce quer investir\n");
        scanf("%d", &mes);
        printf("Quantos quer investir?\n");
        scanf("%f", &investimento);
        printf("Qual é a taxa  ");
        scanf("%f", &rendimento);

            for ( i = 1; i <=mes; i++)
            {
                resultado = rendimento * investimento;
                somatotal = investimento + resultado;

                printf( "mes %d: %.2f x %.2f = %2.f \n", i, investimento, rendimento, resultado);
                resultado = rendimento * investimento;
                investimento = resultado;
                resultado = rendimento * investimento;
            
            }
            
        banco();
    break;
    


    default:
        system("cls");
         printf("\nObrigado pela Confiança \nSENAI o Seu Banco Digital ^-^\n\n");
         main();

    break;
    
    }
}