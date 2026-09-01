#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int i, zona, tipo, vagas = 20, ocupadas = 0, vagasT = 20, calc, opcaoLimpar, continuar, dia = 1;
int encontrou = 0;
float TarifaC = 8, permanencia, TarifaM = 5, adC = 5, adM = 3, valorPago, valorPagoC = 0, valorPagoM = 0, valorPagoF = 0;
char placa[50];
char tipoa[50] = "carro";
char tipob[50] = "moto";
char tipoTexto[50];
char automoveis[10];
char placabusca[50];
FILE *registro;
FILE *historico;
FILE *caixa;
FILE *temporario;

int estacionamentos()
{
    while (1) 
    {
        printf("\n\n==============================");
        printf("\n     ESTACIONAMENTO SENAI");
        printf("\n==============================");
        printf("\nDia: %d", dia);
        printf("\nVagas disponiveis: %d", vagas);
        printf("\n\n1 - Registrar entrada");
        printf("\n2 - Registrar saida");
        printf("\n3 - Consultar situacao");
        printf("\n4 - Exibir faturamento");
        printf("\n5 - Veiculos estacionados");
        printf("\n6 - Consultar historico");
        printf("\n7 - Fechar caixa / novo dia");
        printf("\n0 - Encerrar");
        printf("\n\nOpcao: ");
        scanf("%d", &zona);

        if (zona == 0) {
            break;
        }

        switch (zona) {
        case 1:
            registro = fopen("arquivos/registrosEstacionamento.txt", "a");
            historico = fopen("arquivos/historico.txt", "a");
            caixa = fopen("arquivos/caixa.txt", "a");

            if (historico == NULL)
            {
                printf("\nError ao historico");
            }

            if (registro == NULL)
            {
                printf("\nError ao registro");
            }

            if (caixa == NULL)
            {
                printf("Erro ao abrir o arquivo caixa\n");
            }

            printf("vagas Do estacionamento\n\n");
            printf("Dia: %d\n", dia);
            printf("[1] - Carro\n[2] - Moto\n");
            scanf("%d", &tipo);

            switch (tipo)
            {
            case 1:
                // ================= CARRO =================
                if (vagas == 0)
                {
                    printf("\nEstacionamento lotado!\n");
                    break;
                }

                printf("Qual e a placa do Automovel?\n");
                scanf("%49s", placa);

                printf("Quanto tempo vai permanecer?\n");
                scanf("%f", &permanencia);

                if (permanencia <= 1)
                {
                    valorPagoC = TarifaC;
                }
                else
                {
                    valorPago = (permanencia - 1) * adC;
                    valorPagoC = TarifaC + valorPago;
                }

                vagas--;
                ocupadas = vagasT - vagas;

                printf("\nUma vaga ocupada!");
                printf("\nVagas disponiveis: %d\n", vagas);

                // Gravado no formato simples para o fscanf ler depois no case 2
                fprintf(registro, "%d %s %s %.2f %.2f\n", dia, tipoa, placa, permanencia, valorPagoC);
                fflush(registro);

                fprintf(
                    historico,
                    "dia: %d Entrou | Tipo: %s | Placa: %s | Entrada: %.2f | Valor por tempo: %.2f | Permanencia: %.2f Hrs | Valor a Pagar: %.2f\n",
                    dia, tipoa, placa, TarifaC, adC, permanencia, valorPagoC
                );
                fflush(historico);

                fprintf(
                    caixa,
                    "dia: %d | Placa: %s | Entrada: %.2f | Valor por tempo: %.2f | Permanencia: %.2f Hrs | Valor a Pagar: %.2f\n",
                    dia, placa, TarifaC, adC, permanencia, valorPagoC
                );
                fflush(caixa);

                break;

            case 2:
                // ================= MOTO =================
                if (vagas == 0)
                {
                    printf("\nEstacionamento lotado!\n");
                    break;
                }

                printf("Qual e a placa do Automovel?\n");
                scanf("%49s", placa);

                printf("Quanto tempo vai permanecer?\n");
                scanf("%f", &permanencia);

                if (permanencia <= 1)
                {
                    valorPagoM = TarifaM;
                }
                else
                {
                    valorPago = (permanencia - 1) * adM;
                    valorPagoM = TarifaM + valorPago;
                }

                vagas--;
                ocupadas = vagasT - vagas;

                printf("\nUma vaga ocupada!");
                printf("\nVagas disponiveis: %d\n", vagas);

                fprintf(registro, "%d %s %s %.2f %.2f\n", dia, tipob, placa, permanencia, valorPagoM);
                fflush(registro);

                fprintf(
                    historico,
                    "dia: %d | Entrou | Tipo: %s | Placa: %s | Entrada: %.2f | Valor por tempo: %.2f | Permanencia: %.2f Hrs | Valor a Pagar: %.2f\n",
                    dia, tipob, placa, TarifaM, adM, permanencia, valorPagoM
                );
                fflush(historico);

                fprintf(
                    caixa,
                    "dia: %d | Placa: %s | Entrada: %.2f | Valor por tempo: %.2f | Permanencia: %.2f Hrs | Valor a Pagar: %.2f\n",
                    dia, placa, TarifaM, adM, permanencia, valorPagoM
                );
                fflush(caixa);

                break;

            default:
                printf("error");
                break;
            }

            fclose(historico);
            fclose(registro);
            fclose(caixa);

            printf("\n[1] - cadastrar novo veiculo\n");
            printf("[2] - Menu\n");
            scanf("%d", &continuar);
            break;

        case 2:
            if (ocupadas == 0)
            {
                printf("\nNao ha veiculos estacionados!\n");
                break;
            }

            printf("\n===== Registrar Saida =====\n");
            printf("Digite a placa do veiculo: ");
            scanf("%49s", placabusca);

            registro = fopen("arquivos/registrosEstacionamento.txt", "r");
            historico = fopen("arquivos/historico.txt", "a");
            temporario = fopen("arquivos/temporario.txt", "w");

            if (registro == NULL)
            {
                printf("\nErro ao abrir registro!\n");
                break;
            }

            if (historico == NULL)
            {
                printf("\nErro ao abrir historico!\n");
                fclose(registro);
                break;
            }

            if (temporario == NULL)
            {
                printf("\nErro ao abrir temporario!\n");
                fclose(registro);
                fclose(historico);
                break;
            }

            encontrou = 0;

            while (
                fscanf(
                    registro,
                    "%d %49s %49s %f %f",
                    &dia,
                    tipoTexto,
                    placa,
                    &permanencia,
                    &valorPagoF
                ) == 5
            )
            {
                if (strcmp(placa, placabusca) == 0 && encontrou == 0)
                {
                    encontrou = 1;

                    printf("\nVeiculo encontrado!");
                    printf("\nTipo: %s", tipoTexto);
                    printf("\nPlaca: %s", placa);
                    printf("\nValor a pagar: R$ %.2f\n", valorPagoF);

                    fprintf(
                        historico,
                        "Dia: %d | Saiu | Tipo: %s | Placa: %s | Valor pago: R$ %.2f\n",
                        dia, tipoTexto, placa, valorPagoF
                    );

                    vagas++;
                    ocupadas--;
                }
                else
                {
                    fprintf(
                        temporario,
                        "Dia: %d | Saiu | Tipo: %s | Placa: %s | Valor pago: R$ %.2f\n",
                        dia, tipoTexto, placa, valorPagoF
                    );
                }
            }

            fclose(registro);
            fclose(temporario);
            fclose(historico);
               
            remove("arquivos/registrosEstacionamento.txt");
            rename("arquivos/temporario.txt", "arquivos/registrosEstacionamento.txt");
               
            if (encontrou == 0)
            {
                printf("\nVeiculo nao encontrado!\n");
            }

            break;

        case 3:
            printf("======Situação======");
            printf("\nVagas Disponiveis: %d", vagas);
            printf("\nVagas Ocupadas: %d", ocupadas);

            printf("\n\n[1] - cadastrar novo veiculo\n");
            printf("[2] - fechar caixa\n");

            scanf("%d", &continuar);

            switch (continuar)
            {
            case 1:
                break;

            case 2:
                dia++;
                break;

            default:
                break;
            }
            break;

        case 4:
            printf("\n\n====$Faturamento$====\n\n");
            valorPagoF = valorPagoC + valorPagoM;
            printf("Caixa Total: %.2fR$", valorPagoF);

            printf("\n\n[1] - cadastrar novo veiculo\n");
            printf("[2] - Voltar ao Menu\n");
            printf("[3] - fechar caixa\n");

            scanf("%d", &continuar);

            switch (continuar)
            {
            case 1:
                break;

            case 2:
                break;

            case 3:
                dia++;
                break;

            default:
                break;
            }
        break;
    

        case 5:
            printf("\n==== Veiculos Estacionados ====\n");

            registro = fopen("arquivos/registrosEstacionamento.txt", "r");
            if (registro == NULL)
            {
                printf("\nNenhum veiculo registrado ou erro ao abrir arquivo!\n");
                break;
            }

            while (fscanf(registro, "%d %49s %49s %f %f", &dia, tipoTexto, placa, &permanencia, &valorPagoF) == 5)
            {
                printf("Dia: %d | Tipo: %s | Placa: %s | Permanencia: %.1fh | Valor pago: R$ %.2f\n",
                       dia, tipoTexto, placa, permanencia, valorPagoF);
            }

            fclose(registro);
        break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }
    return 0;
}