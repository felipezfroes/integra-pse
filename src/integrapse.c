/*
 * IntegraPSE - Sistema de Planejamento e Acompanhamento de Acoes de Saude na Escola
 * AEP 2o semestre de 2026 - Engenharia de Software - UniCesumar
 *
 * Aplicacao de terminal para registrar e acompanhar acoes coletivas do
 * Programa Saude na Escola (PSE). Utiliza apenas dados ficticios e coletivos.
 *
 * Compilacao: gcc integrapse.c -o integrapse
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef MAX_ACOES
#define MAX_ACOES 100
#endif
#define TAM_TEXTO 61
#define TAM_DATA 11
#define TAM_ENTRADA 128

#define SITUACAO_PLANEJADA 1
#define SITUACAO_REALIZADA 2
#define SITUACAO_CANCELADA 3

typedef struct {
    int codigo;
    char escola[TAM_TEXTO];
    char tema[TAM_TEXTO];
    char dataPrevista[TAM_DATA];
    char publicoAlvo[TAM_TEXTO];
    char responsavel[TAM_TEXTO];
    int participantesPrevistos;
    int participantesEfetivos;
    int situacao;
} Acao;

/* ---------- Prototipos ---------- */
void exibirMenu(void);
void lerTexto(const char *rotulo, char *destino, int tamanho);
int lerInteiro(const char *rotulo, int *valor);
int textoVazio(const char *texto);
int dataValida(const char *data);
int contemTexto(const char *texto, const char *trecho);
int buscarPorCodigo(const Acao acoes[], int quantidade, int codigo);
const char *nomeSituacao(int situacao);
void exibirAcao(const Acao *acao);

void cadastrarAcao(Acao acoes[], int *quantidade);
void listarAcoes(const Acao acoes[], int quantidade);
void pesquisarAcao(const Acao acoes[], int quantidade);
void atualizarSituacao(Acao acoes[], int quantidade);
void gerarResumo(const Acao acoes[], int quantidade);

/* ---------- Funcao principal ---------- */
int main(void) {
    Acao acoes[MAX_ACOES];
    int quantidadeAcoes = 0;
    int opcao;

    do {
        exibirMenu();

        if (!lerInteiro("Escolha uma opcao: ", &opcao)) {
            printf("\n[ERRO] Digite apenas o numero de uma opcao do menu.\n");
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarAcao(acoes, &quantidadeAcoes);
                break;
            case 2:
                listarAcoes(acoes, quantidadeAcoes);
                break;
            case 3:
                pesquisarAcao(acoes, quantidadeAcoes);
                break;
            case 4:
                atualizarSituacao(acoes, quantidadeAcoes);
                break;
            case 5:
                gerarResumo(acoes, quantidadeAcoes);
                break;
            case 0:
                printf("\nPrograma encerrado. ");
                printf("Os dados desta execucao foram descartados.\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida. Escolha um numero entre 0 e 5.\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ---------- Funcoes auxiliares de entrada e saida ---------- */
void exibirMenu(void) {
    printf("\n==============================================\n");
    printf("        INTEGRAPSE - Programa Saude na Escola\n");
    printf("==============================================\n");
    printf(" 1 - Cadastrar acao\n");
    printf(" 2 - Listar acoes\n");
    printf(" 3 - Pesquisar acao\n");
    printf(" 4 - Atualizar situacao\n");
    printf(" 5 - Gerar resumo geral\n");
    printf(" 0 - Encerrar\n");
    printf("----------------------------------------------\n");
}

/* Le uma linha inteira, remove a quebra de linha e descarta o excedente. */
void lerTexto(const char *rotulo, char *destino, int tamanho) {
    int c;

    printf("%s", rotulo);
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    if (strchr(destino, '\n') != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    if (strlen(destino) > 0 && destino[strlen(destino) - 1] == '\r') {
        destino[strlen(destino) - 1] = '\0';
    }
}

/* Retorna 1 se a entrada for um numero inteiro valido e 0 caso contrario. */
int lerInteiro(const char *rotulo, int *valor) {
    char entrada[TAM_ENTRADA];
    char *fim;
    long numero;

    lerTexto(rotulo, entrada, TAM_ENTRADA);
    if (textoVazio(entrada)) {
        return 0;
    }

    numero = strtol(entrada, &fim, 10);
    while (isspace((unsigned char)*fim)) {
        fim++;
    }
    if (*fim != '\0' || numero > 999999 || numero < -999999) {
        return 0;
    }

    *valor = (int)numero;
    return 1;
}

int textoVazio(const char *texto) {
    while (*texto != '\0') {
        if (!isspace((unsigned char)*texto)) {
            return 0;
        }
        texto++;
    }
    return 1;
}

/* Aceita o formato DD/MM/AAAA e confere dia, mes e ano bissexto. */
int dataValida(const char *data) {
    int dia, mes, ano, i;
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i])) {
            return 0;
        }
    }

    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');
    ano = atoi(&data[6]);

    if (ano < 2000 || ano > 2100 || mes < 1 || mes > 12) {
        return 0;
    }
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        diasNoMes[1] = 29;
    }
    return dia >= 1 && dia <= diasNoMes[mes - 1];
}

/* Pesquisa por trecho, sem diferenciar letras maiusculas e minusculas. */
int contemTexto(const char *texto, const char *trecho) {
    int i, j;
    int tamTexto = (int)strlen(texto);
    int tamTrecho = (int)strlen(trecho);

    for (i = 0; i <= tamTexto - tamTrecho; i++) {
        for (j = 0; j < tamTrecho; j++) {
            if (tolower((unsigned char)texto[i + j]) !=
                tolower((unsigned char)trecho[j])) {
                break;
            }
        }
        if (j == tamTrecho) {
            return 1;
        }
    }
    return 0;
}

/* Retorna a posicao da acao no vetor ou -1 se o codigo nao existir. */
int buscarPorCodigo(const Acao acoes[], int quantidade, int codigo) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

const char *nomeSituacao(int situacao) {
    switch (situacao) {
        case SITUACAO_PLANEJADA: return "PLANEJADA";
        case SITUACAO_REALIZADA: return "REALIZADA";
        case SITUACAO_CANCELADA: return "CANCELADA";
        default: return "DESCONHECIDA";
    }
}

void exibirAcao(const Acao *acao) {
    printf("----------------------------------------------\n");
    printf("Codigo ..................: %d\n", acao->codigo);
    printf("Escola ..................: %s\n", acao->escola);
    printf("Tema ....................: %s\n", acao->tema);
    printf("Data prevista ...........: %s\n", acao->dataPrevista);
    printf("Publico-alvo ............: %s\n", acao->publicoAlvo);
    printf("Responsavel .............: %s\n", acao->responsavel);
    printf("Participantes previstos .: %d\n", acao->participantesPrevistos);
    printf("Participantes efetivos ..: %d\n", acao->participantesEfetivos);
    printf("Situacao ................: %s\n", nomeSituacao(acao->situacao));
}

/* ---------- Funcionalidades do sistema ---------- */
void cadastrarAcao(Acao acoes[], int *quantidade) {
    Acao nova;
    char data[TAM_ENTRADA];

    printf("\n--- CADASTRAR ACAO ---\n");

    if (*quantidade >= MAX_ACOES) {
        printf("[ERRO] Limite de %d acoes atingido. ", MAX_ACOES);
        printf("Nao e possivel cadastrar.\n");
        return;
    }

    if (!lerInteiro("Codigo da acao (numero positivo): ", &nova.codigo) ||
        nova.codigo <= 0) {
        printf("[ERRO] Codigo invalido. Informe um numero inteiro maior que zero.\n");
        return;
    }
    if (buscarPorCodigo(acoes, *quantidade, nova.codigo) != -1) {
        printf("[ERRO] Ja existe uma acao com o codigo %d.\n", nova.codigo);
        return;
    }

    lerTexto("Escola: ", nova.escola, TAM_TEXTO);
    lerTexto("Tema: ", nova.tema, TAM_TEXTO);
    lerTexto("Data prevista (DD/MM/AAAA): ", data, TAM_ENTRADA);
    lerTexto("Publico-alvo: ", nova.publicoAlvo, TAM_TEXTO);
    lerTexto("Responsavel: ", nova.responsavel, TAM_TEXTO);

    if (textoVazio(nova.escola) || textoVazio(nova.tema) ||
        textoVazio(nova.publicoAlvo) || textoVazio(nova.responsavel)) {
        printf("[ERRO] Existem campos obrigatorios vazios. Cadastro cancelado.\n");
        return;
    }
    if (!dataValida(data)) {
        printf("[ERRO] Data invalida. Use DD/MM/AAAA. Cadastro cancelado.\n");
        return;
    }
    strcpy(nova.dataPrevista, data);
    if (!lerInteiro("Participantes previstos: ", &nova.participantesPrevistos) ||
        nova.participantesPrevistos < 0) {
        printf("[ERRO] Quantidade de participantes invalida. Cadastro cancelado.\n");
        return;
    }

    nova.participantesEfetivos = 0;
    nova.situacao = SITUACAO_PLANEJADA;

    acoes[*quantidade] = nova;
    (*quantidade)++;

    printf("[OK] Acao %d cadastrada com sucesso ", nova.codigo);
    printf("(situacao inicial: PLANEJADA).\n");
}

void listarAcoes(const Acao acoes[], int quantidade) {
    int i;

    printf("\n--- LISTA DE ACOES (%d cadastrada(s)) ---\n", quantidade);

    if (quantidade == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        exibirAcao(&acoes[i]);
    }
    printf("----------------------------------------------\n");
}

void pesquisarAcao(const Acao acoes[], int quantidade) {
    int opcao, codigo, i, encontrados = 0;
    char termo[TAM_TEXTO];

    printf("\n--- PESQUISAR ACAO ---\n");

    if (quantidade == 0) {
        printf("Nenhuma acao cadastrada para pesquisar.\n");
        return;
    }

    printf(" 1 - Por codigo\n 2 - Por escola\n 3 - Por tema\n");
    if (!lerInteiro("Criterio de pesquisa: ", &opcao) || opcao < 1 || opcao > 3) {
        printf("[ERRO] Criterio de pesquisa invalido.\n");
        return;
    }

    if (opcao == 1) {
        if (!lerInteiro("Codigo procurado: ", &codigo)) {
            printf("[ERRO] Codigo invalido.\n");
            return;
        }
        i = buscarPorCodigo(acoes, quantidade, codigo);
        if (i != -1) {
            exibirAcao(&acoes[i]);
            encontrados = 1;
        }
    } else {
        if (opcao == 2) {
            lerTexto("Escola (ou parte do nome): ", termo, TAM_TEXTO);
        } else {
            lerTexto("Tema (ou parte do nome): ", termo, TAM_TEXTO);
        }
        if (textoVazio(termo)) {
            printf("[ERRO] O termo de pesquisa nao pode ficar vazio.\n");
            return;
        }
        for (i = 0; i < quantidade; i++) {
            const char *campo = (opcao == 2) ? acoes[i].escola : acoes[i].tema;
            if (contemTexto(campo, termo)) {
                exibirAcao(&acoes[i]);
                encontrados++;
            }
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma acao encontrada para o criterio informado.\n");
    } else {
        printf("----------------------------------------------\n");
        printf("%d acao(oes) encontrada(s).\n", encontrados);
    }
}

void atualizarSituacao(Acao acoes[], int quantidade) {
    int codigo, posicao, novaSituacao, efetivos;

    printf("\n--- ATUALIZAR SITUACAO ---\n");

    if (quantidade == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    if (!lerInteiro("Codigo da acao: ", &codigo)) {
        printf("[ERRO] Codigo invalido.\n");
        return;
    }
    posicao = buscarPorCodigo(acoes, quantidade, codigo);
    if (posicao == -1) {
        printf("[ERRO] Acao com codigo %d nao encontrada.\n", codigo);
        return;
    }

    printf("Situacao atual: %s\n", nomeSituacao(acoes[posicao].situacao));
    printf(" 1 - Planejada\n 2 - Realizada\n 3 - Cancelada\n");
    if (!lerInteiro("Nova situacao: ", &novaSituacao) ||
        novaSituacao < 1 || novaSituacao > 3) {
        printf("[ERRO] Situacao invalida. Nenhuma alteracao foi feita.\n");
        return;
    }

    if (novaSituacao == SITUACAO_REALIZADA) {
        if (!lerInteiro("Participantes efetivos: ", &efetivos) || efetivos < 0) {
            printf("[ERRO] Quantidade invalida. Nenhuma alteracao foi feita.\n");
            return;
        }
        acoes[posicao].participantesEfetivos = efetivos;
    } else {
        acoes[posicao].participantesEfetivos = 0;
    }

    acoes[posicao].situacao = novaSituacao;
    printf("[OK] Acao %d atualizada para %s.\n", codigo, nomeSituacao(novaSituacao));
}

void gerarResumo(const Acao acoes[], int quantidade) {
    int i;
    int planejadas = 0, realizadas = 0, canceladas = 0;
    int previstosRealizadas = 0, totalEfetivos = 0;
    float percentual = 0.0f;

    printf("\n--- RESUMO GERAL ---\n");

    if (quantidade == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        if (acoes[i].situacao == SITUACAO_PLANEJADA) {
            planejadas++;
        } else if (acoes[i].situacao == SITUACAO_REALIZADA) {
            realizadas++;
            previstosRealizadas += acoes[i].participantesPrevistos;
            totalEfetivos += acoes[i].participantesEfetivos;
        } else if (acoes[i].situacao == SITUACAO_CANCELADA) {
            canceladas++;
        }
    }

    if (previstosRealizadas > 0) {
        percentual = (float)totalEfetivos / previstosRealizadas * 100.0f;
    }

    printf("Total de acoes cadastradas ...............: %d\n", quantidade);
    printf("Acoes planejadas .........................: %d\n", planejadas);
    printf("Acoes realizadas .........................: %d\n", realizadas);
    printf("Acoes canceladas .........................: %d\n", canceladas);
    printf("Participantes previstos (acoes realizadas): %d\n", previstosRealizadas);
    printf("Participantes efetivos ...................: %d\n", totalEfetivos);
    printf("Percentual de participacao ...............: %.1f%%\n", percentual);
}
