#include <stdio.h>
#include "erros.c"
#include "boletim.c"
#include "calculadora.c"
#include "banco.c"
#include "estacionamento.c"
#include "iaacreditando.c"

int main() {

    int atividade;
    int erroCodigo = 0;

    while(1) {

        erroCodigo = 0;

        printf("\n=========== MENU ===========\n");
        printf("1 - Boletim\n");
        printf("2 - Calculadora\n");
        printf("3 - Banco\n");
        printf("4 - Estacionamentos\n");
        printf("0 - Sair\n\n");

        printf("Opcao: ");
        scanf("%d", &atividade);

        switch(atividade) {

            case 1:
                //erroCodigo = boletim();
            break;

            case 2:
                //erroCodigo = calculadora();
            break;

            case 3:
                //erroCodigo = banco();
            break;

            case 4:
                erroCodigo = estacionamentos();
            break;

            case 5:
                //erroCodigo = iaacreditando();
            break;

            case 0:
                printf("\nEncerrando programa...\n");
                return 0;

            default:
                erroCodigo = 404;
            break;

        }

        if(erroCodigo != 0) {
            erro(erroCodigo);
        }

    }
}
