#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iaacreditando()
{
    int zona = 0;
    int tipo = 0;
    int vagas = 20;
    int ocupadas = 0;
    int dia = 1;
    int continuar = 1;
    int encontrou = 0;

    float tarifaC = 8.0;
    float tarifaM = 5.0;
    float adicionalC = 5.0;
    float adicionalM = 3.0;
    float permanencia = 0.0;
    float valorPagar = 0.0;
    float faturamento = 0.0;

    char placa[20];
    char placaBusca[20];
    char placaArquivo[20];
    char tipoArquivo[20];

    FILE *registro;
    FILE *historico;
    FILE *caixa;
    FILE *temporario;

    while (continuar)
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

        switch (zona)
        {
            /* ================================================
               ENTRADA
               ================================================ */
            case 1:

                if (vagas <= 0)
                {
                    printf("\nEstacionamento lotado!\n");
                    break;
                }

                printf("\n===== REGISTRAR ENTRADA =====\n");

                printf("\n1 - Carro");
                printf("\n2 - Moto");
                printf("\nTipo: ");
                scanf("%d", &tipo);

                if (tipo != 1 && tipo != 2)
                {
                    printf("\nTipo invalido!\n");
                    break;
                }

                printf("Qual e a placa do automovel? ");
                scanf("%19s", placa);

                printf("Quanto tempo vai permanecer? ");
                scanf("%f", &permanencia);

                /*
                    Ate 1 hora:
                    carro = R$ 8
                    moto  = R$ 5

                    Acima de 1 hora:
                    cobra adicional por HORA EXTRA.
                */

                if (tipo == 1)
                {
                    if (permanencia <= 1)
                    {
                        valorPagar = tarifaC;
                    }
                    else
                    {
                        valorPagar = tarifaC +
                                     ((permanencia - 1) * adicionalC);
                    }
                }
                else
                {
                    if (permanencia <= 1)
                    {
                        valorPagar = tarifaM;
                    }
                    else
                    {
                        valorPagar = tarifaM +
                                     ((permanencia - 1) * adicionalM);
                    }
                }

                registro = fopen(
                    "cads/registrosEstacionamento.txt",
                    "a"
                );

                historico = fopen(
                    "cads/historico.txt",
                    "a"
                );

                if (registro == NULL || historico == NULL)
                {
                    printf("\nErro ao abrir os arquivos!\n");

                    if (registro != NULL)
                        fclose(registro);

                    if (historico != NULL)
                        fclose(historico);

                    break;
                }

                if (tipo == 1)
                {
                    fprintf(
                        registro,
                        "%d carro %s %.2f %.2f\n",
                        dia,
                        placa,
                        permanencia,
                        valorPagar
                    );

                    fprintf(
                        historico,
                        "Dia: %d | Entrou | Tipo: carro | "
                        "Placa: %s | Permanencia: %.2f Hrs | "
                        "Valor: R$ %.2f\n",
                        dia,
                        placa,
                        permanencia,
                        valorPagar
                    );
                }
                else
                {
                    fprintf(
                        registro,
                        "%d moto %s %.2f %.2f\n",
                        dia,
                        placa,
                        permanencia,
                        valorPagar
                    );

                    fprintf(
                        historico,
                        "Dia: %d | Entrou | Tipo: moto | "
                        "Placa: %s | Permanencia: %.2f Hrs | "
                        "Valor: R$ %.2f\n",
                        dia,
                        placa,
                        permanencia,
                        valorPagar
                    );
                }

                fclose(registro);
                fclose(historico);

                vagas--;
                ocupadas++;

                printf("\nVeiculo cadastrado com sucesso!");
                printf("\nValor a pagar: R$ %.2f", valorPagar);
                printf("\nVagas restantes: %d\n", vagas);

            break;


            /* ================================================
               SAIDA
               ================================================ */
            case 2:

                if (ocupadas == 0)
                {
                    printf("\nNao ha veiculos estacionados!\n");
                    break;
                }

                printf("\n===== REGISTRAR SAIDA =====\n");

                printf("Digite a placa do veiculo: ");
                scanf("%19s", placaBusca);

                registro = fopen(
                    "cads/registrosEstacionamento.txt",
                    "r"
                );

                temporario = fopen(
                    "cads/temporario.txt",
                    "w"
                );

                historico = fopen(
                    "cads/historico.txt",
                    "a"
                );

                caixa = fopen(
                    "cads/caixa.txt",
                    "a"
                );

                if (
                    registro == NULL ||
                    temporario == NULL ||
                    historico == NULL ||
                    caixa == NULL
                )
                {
                    printf("\nErro ao abrir arquivos!\n");

                    if (registro != NULL)
                        fclose(registro);

                    if (temporario != NULL)
                        fclose(temporario);

                    if (historico != NULL)
                        fclose(historico);

                    if (caixa != NULL)
                        fclose(caixa);

                    break;
                }

                encontrou = 0;

                int diaArquivo;
                float permanenciaArquivo;
                float valorArquivo;

                while (
                    fscanf(
                        registro,
                        "%d %19s %19s %f %f",
                        &diaArquivo,
                        tipoArquivo,
                        placaArquivo,
                        &permanenciaArquivo,
                        &valorArquivo
                    ) == 5
                )
                {
                    /*
                        strcmp() retorna 0 quando as strings
                        sao iguais.
                    */
                    if (
                        strcmp(placaArquivo, placaBusca) == 0 &&
                        encontrou == 0
                    )
                    {
                        encontrou = 1;

                        printf("\nVeiculo encontrado!");
                        printf("\nTipo: %s", tipoArquivo);
                        printf("\nPlaca: %s", placaArquivo);
                        printf(
                            "\nValor a pagar: R$ %.2f\n",
                            valorArquivo
                        );

                        fprintf(
                            historico,
                            "Dia: %d | Saiu | Tipo: %s | "
                            "Placa: %s | Valor pago: R$ %.2f\n",
                            dia,
                            tipoArquivo,
                            placaArquivo,
                            valorArquivo
                        );

                        fprintf(
                            caixa,
                            "Dia: %d | Placa: %s | "
                            "Valor recebido: R$ %.2f\n",
                            dia,
                            placaArquivo,
                            valorArquivo
                        );

                        faturamento += valorArquivo;

                        vagas++;
                        ocupadas--;
                    }
                    else
                    {
                        /*
                            Se NAO for o carro que esta saindo,
                            copia para o temporario.
                        */
                        fprintf(
                            temporario,
                            "%d %s %s %.2f %.2f\n",
                            diaArquivo,
                            tipoArquivo,
                            placaArquivo,
                            permanenciaArquivo,
                            valorArquivo
                        );
                    }
                }

                fclose(registro);
                fclose(temporario);
                fclose(historico);
                fclose(caixa);

                if (encontrou)
                {
                    remove(
                        "cads/registrosEstacionamento.txt"
                    );

                    rename(
                        "cads/temporario.txt",
                        "cads/registrosEstacionamento.txt"
                    );

                    printf("\nSaida registrada com sucesso!\n");
                }
                else
                {
                    /*
                        Nao encontrou. O arquivo original continua.
                    */
                    remove("cads/temporario.txt");

                    printf(
                        "\nPlaca %s nao encontrada!\n",
                        placaBusca
                    );
                }

            break;


            /* ================================================
               SITUACAO
               ================================================ */
            case 3:

                printf("\n===== SITUACAO =====\n");
                printf("\nDia: %d", dia);
                printf("\nTotal de vagas: 20");
                printf("\nVagas disponiveis: %d", vagas);
                printf("\nVagas ocupadas: %d\n", ocupadas);

            break;


            /* ================================================
               FATURAMENTO
               ================================================ */
            case 4:

                printf("\n===== FATURAMENTO =====\n");
                printf(
                    "\nFaturamento atual: R$ %.2f\n",
                    faturamento
                );

            break;


            /* ================================================
               VEICULOS ESTACIONADOS
               ================================================ */
            case 5:

                printf("\n===== VEICULOS ESTACIONADOS =====\n");

                registro = fopen(
                    "cads/registrosEstacionamento.txt",
                    "r"
                );

                if (registro == NULL)
                {
                    printf("\nNenhum registro encontrado.\n");
                    break;
                }

                encontrou = 0;

                int diaListado;
                float permanenciaListada;
                float valorListado;

                while (
                    fscanf(
                        registro,
                        "%d %19s %19s %f %f",
                        &diaListado,
                        tipoArquivo,
                        placaArquivo,
                        &permanenciaListada,
                        &valorListado
                    ) == 5
                )
                {
                    encontrou = 1;

                    printf(
                        "\nDia: %d | Tipo: %s | "
                        "Placa: %s | %.2f Hrs | R$ %.2f",
                        diaListado,
                        tipoArquivo,
                        placaArquivo,
                        permanenciaListada,
                        valorListado
                    );
                }

                if (!encontrou)
                {
                    printf("\nNenhum veiculo estacionado.");
                }

                printf("\n");

                fclose(registro);

            break;


            /* ================================================
               HISTORICO
               ================================================ */
            case 6:

                printf("\n===== HISTORICO =====\n\n");

                historico = fopen(
                    "cads/historico.txt",
                    "r"
                );

                if (historico == NULL)
                {
                    printf("Nenhum historico encontrado.\n");
                    break;
                }

                char linha[300];

                while (
                    fgets(
                        linha,
                        sizeof(linha),
                        historico
                    ) != NULL
                )
                {
                    printf("%s", linha);
                }

                fclose(historico);

            break;


            /* ================================================
               FECHAR CAIXA
               ================================================ */
            case 7:

                printf("\n===== FECHAMENTO DO DIA %d =====\n", dia);
                printf(
                    "Faturamento: R$ %.2f\n",
                    faturamento
                );

                caixa = fopen(
                    "cads/caixa.txt",
                    "a"
                );

                if (caixa != NULL)
                {
                    fprintf(
                        caixa,
                        "FECHAMENTO DIA %d | "
                        "TOTAL: R$ %.2f\n",
                        dia,
                        faturamento
                    );

                    fclose(caixa);
                }

                dia++;
                faturamento = 0;

                printf(
                    "\nCaixa fechado. Iniciando dia %d.\n",
                    dia
                );

            break;


            /* ================================================
               ENCERRAR
               ================================================ */
            case 0:

                printf("\nSistema encerrado.\n");
                continuar = 0;

            break;


            default:

                printf("\nOpcao invalida!\n");

            break;
        }
    }

    return 0;
}