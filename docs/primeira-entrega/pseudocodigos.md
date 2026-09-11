# Pseudocódigos do IntegraPSE

Este documento apresenta os pseudocódigos planejados para as principais funcionalidades do sistema IntegraPSE.

Os algoritmos servirão como referência para a posterior implementação em linguagem C.

---

## 1. Menu principal

```text
INÍCIO

    DECLARAR opção
    DECLARAR vetor de ações
    DEFINIR quantidadeAcoes ← 0

    REPITA

        EXIBIR "INTEGRAPSE"
        EXIBIR "1 - Cadastrar ação"
        EXIBIR "2 - Listar ações"
        EXIBIR "3 - Pesquisar ação"
        EXIBIR "4 - Atualizar situação"
        EXIBIR "5 - Gerar resumo geral"
        EXIBIR "0 - Encerrar"

        LER opção

        ESCOLHA opção

            CASO 1:
                CADASTRAR_ACAO()

            CASO 2:
                LISTAR_ACOES()

            CASO 3:
                PESQUISAR_ACAO()

            CASO 4:
                ATUALIZAR_SITUACAO()

            CASO 5:
                GERAR_RESUMO()

            CASO 0:
                EXIBIR "Programa encerrado."

            CASO CONTRÁRIO:
                EXIBIR "Opção inválida."

        FIM ESCOLHA

    ATÉ opção = 0

FIM
```

---

## 2. Cadastro de ação

```text
ALGORITMO CADASTRAR_ACAO

    SE quantidadeAcoes = LIMITE ENTÃO

        EXIBIR "Limite de armazenamento atingido."
        RETORNAR

    FIM SE

    LER código

    SE código já estiver cadastrado ENTÃO

        EXIBIR "Código já cadastrado."
        RETORNAR

    FIM SE

    LER escola
    LER tema
    LER dataPrevista
    LER publicoAlvo
    LER responsável
    LER participantesPrevistos

    SE escola estiver vazia OU
       tema estiver vazio OU
       responsável estiver vazio ENTÃO

        EXIBIR "Existem campos obrigatórios vazios."
        RETORNAR

    FIM SE

    SE participantesPrevistos < 0 ENTÃO

        EXIBIR "Quantidade de participantes inválida."
        RETORNAR

    FIM SE

    DEFINIR situação ← "PLANEJADA"
    DEFINIR participantesEfetivos ← 0

    ARMAZENAR ação no vetor

    quantidadeAcoes ← quantidadeAcoes + 1

    EXIBIR "Ação cadastrada com sucesso."

FIM ALGORITMO
```

---

## 3. Listagem de ações

```text
ALGORITMO LISTAR_ACOES

    SE quantidadeAcoes = 0 ENTÃO

        EXIBIR "Nenhuma ação cadastrada."
        RETORNAR

    FIM SE

    PARA posição ← 0 ATÉ quantidadeAcoes - 1 FAÇA

        EXIBIR código da ação
        EXIBIR escola
        EXIBIR tema
        EXIBIR data prevista
        EXIBIR público-alvo
        EXIBIR responsável
        EXIBIR participantes previstos
        EXIBIR participantes efetivos
        EXIBIR situação

    FIM PARA

FIM ALGORITMO
```

---

## 4. Pesquisa de ações

```text
ALGORITMO PESQUISAR_ACAO

    EXIBIR "1 - Pesquisar por código"
    EXIBIR "2 - Pesquisar por escola"
    EXIBIR "3 - Pesquisar por tema"

    LER opçãoPesquisa

    DEFINIR encontrado ← FALSO

    SE opçãoPesquisa = 1 ENTÃO

        LER códigoProcurado

        PARA cada ação cadastrada FAÇA

            SE código da ação = códigoProcurado ENTÃO
                EXIBIR dados da ação
                encontrado ← VERDADEIRO
            FIM SE

        FIM PARA

    SENÃO SE opçãoPesquisa = 2 ENTÃO

        LER escolaProcurada

        PARA cada ação cadastrada FAÇA

            SE escola da ação = escolaProcurada ENTÃO
                EXIBIR dados da ação
                encontrado ← VERDADEIRO
            FIM SE

        FIM PARA

    SENÃO SE opçãoPesquisa = 3 ENTÃO

        LER temaProcurado

        PARA cada ação cadastrada FAÇA

            SE tema da ação = temaProcurado ENTÃO
                EXIBIR dados da ação
                encontrado ← VERDADEIRO
            FIM SE

        FIM PARA

    SENÃO

        EXIBIR "Opção de pesquisa inválida."
        RETORNAR

    FIM SE

    SE encontrado = FALSO ENTÃO
        EXIBIR "Nenhuma ação encontrada."
    FIM SE

FIM ALGORITMO
```

---

## 5. Atualização da situação

```text
ALGORITMO ATUALIZAR_SITUACAO

    LER códigoProcurado

    PROCURAR ação pelo código

    SE ação não for encontrada ENTÃO

        EXIBIR "Ação não encontrada."
        RETORNAR

    FIM SE

    EXIBIR "1 - Planejada"
    EXIBIR "2 - Realizada"
    EXIBIR "3 - Cancelada"

    LER novaSituação

    SE novaSituação = 1 ENTÃO

        situação ← "PLANEJADA"
        participantesEfetivos ← 0

    SENÃO SE novaSituação = 2 ENTÃO

        LER participantesEfetivos

        SE participantesEfetivos < 0 ENTÃO

            EXIBIR "Quantidade inválida."
            RETORNAR

        FIM SE

        situação ← "REALIZADA"

    SENÃO SE novaSituação = 3 ENTÃO

        situação ← "CANCELADA"
        participantesEfetivos ← 0

    SENÃO

        EXIBIR "Situação inválida."
        RETORNAR

    FIM SE

    EXIBIR "Situação atualizada com sucesso."

FIM ALGORITMO
```

---

## 6. Resumo geral

```text
ALGORITMO GERAR_RESUMO

    DEFINIR planejadas ← 0
    DEFINIR realizadas ← 0
    DEFINIR canceladas ← 0
    DEFINIR totalPrevistosRealizados ← 0
    DEFINIR totalEfetivos ← 0

    PARA cada ação cadastrada FAÇA

        SE situação = "PLANEJADA" ENTÃO

            planejadas ← planejadas + 1

        SENÃO SE situação = "REALIZADA" ENTÃO

            realizadas ← realizadas + 1

            totalPrevistosRealizados ←
                totalPrevistosRealizados + participantesPrevistos

            totalEfetivos ←
                totalEfetivos + participantesEfetivos

        SENÃO SE situação = "CANCELADA" ENTÃO

            canceladas ← canceladas + 1

        FIM SE

    FIM PARA

    SE totalPrevistosRealizados > 0 ENTÃO

        percentualParticipação ←
            (totalEfetivos / totalPrevistosRealizados) × 100

    SENÃO

        percentualParticipação ← 0

    FIM SE

    EXIBIR "Ações planejadas: ", planejadas
    EXIBIR "Ações realizadas: ", realizadas
    EXIBIR "Ações canceladas: ", canceladas

    EXIBIR "Participantes previstos nas ações realizadas: ",
           totalPrevistosRealizados

    EXIBIR "Participantes efetivos: ",
           totalEfetivos

    EXIBIR "Percentual de participação: ",
           percentualParticipação

FIM ALGORITMO
```

---

## Relação com a implementação

Os pseudocódigos foram elaborados a partir dos requisitos funcionais do IntegraPSE.

Durante a implementação, cada algoritmo deverá ser convertido em funções e estruturas correspondentes em linguagem C, mantendo a relação entre requisitos, modelagem e código-fonte.
