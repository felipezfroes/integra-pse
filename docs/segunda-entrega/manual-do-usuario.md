# Manual do usuário — IntegraPSE

## Objetivo do sistema

O IntegraPSE é uma aplicação de terminal que auxilia equipes de Saúde e Educação no registro e no acompanhamento das ações coletivas do Programa Saúde na Escola. O sistema deve ser utilizado apenas com dados coletivos ou fictícios.

## Como executar

1. Baixe o repositório e abra o arquivo `src/integrapse.c` no Dev-C++.
2. Selecione **Execute > Compile & Run** (tecla F11).
3. Utilize o menu exibido no console, digitando o número da opção e pressionando Enter.

Também é possível compilar pelo terminal:

```bash
gcc src/integrapse.c -o integrapse
./integrapse
```

## Opções do menu

| Opção | Função | Como utilizar |
| --- | --- | --- |
| 1 | Cadastrar ação | Informar código, escola, tema, data prevista (DD/MM/AAAA), público-alvo, responsável e participantes previstos. |
| 2 | Listar ações | Exibe todas as ações cadastradas. |
| 3 | Pesquisar ação | Escolher o critério (1 – código, 2 – escola ou 3 – tema) e digitar o valor procurado. |
| 4 | Atualizar situação | Informar o código e a nova situação (1 – planejada, 2 – realizada ou 3 – cancelada). Para ação realizada, informar os participantes efetivos. |
| 5 | Gerar resumo geral | Exibe as quantidades de ações por situação e o percentual de participação. |
| 0 | Encerrar | Finaliza o programa. |

## Observações

- Os dados ficam armazenados apenas durante a execução e são descartados ao encerrar o programa.
- O sistema permite cadastrar até 100 ações por execução.
- Mensagens iniciadas por `[OK]` indicam sucesso; mensagens iniciadas por `[ERRO]` indicam que nenhuma alteração foi feita.
- Não devem ser cadastrados nomes, diagnósticos ou outros dados pessoais de estudantes.
