# IntegraPSE

Sistema de Planejamento e Acompanhamento de Ações do Programa Saúde na Escola (PSE).

Projeto desenvolvido como parte da **AEP do 2º semestre de 2026** do curso de Engenharia de Software da UniCesumar.

## Sobre o projeto

O IntegraPSE é uma aplicação desenvolvida em linguagem C com o objetivo de auxiliar no planejamento e acompanhamento de ações realizadas no âmbito do Programa Saúde na Escola.

O sistema permite organizar informações sobre atividades realizadas em diferentes escolas, facilitando o cadastro, consulta, acompanhamento e análise das ações.

Para fins acadêmicos, são utilizados apenas dados fictícios e informações coletivas, sem armazenamento de dados pessoais ou clínicos dos estudantes.

## Objetivo

Desenvolver uma aplicação simples executada em terminal capaz de registrar e acompanhar ações coletivas do Programa Saúde na Escola, aplicando conceitos de lógica de programação, linguagem C e Engenharia de Software.

## Funcionalidades

* Cadastro de ações do PSE;
* Listagem das ações cadastradas;
* Pesquisa por código, escola ou tema;
* Atualização da situação de uma ação;
* Registro da quantidade efetiva de participantes;
* Geração de resumo geral das ações;
* Validação das entradas fornecidas pelo usuário.

## Informações de uma ação

Cada ação possui:

* Código;
* Escola;
* Tema;
* Data prevista;
* Público-alvo;
* Responsável;
* Quantidade prevista de participantes;
* Quantidade efetiva de participantes;
* Situação da ação.

As situações possíveis são:

* Planejada;
* Realizada;
* Cancelada.

## Tecnologias

* Linguagem C
* Git
* GitHub
* Dev-C++

## Como executar

1. Baixe o repositório e abra o arquivo `src/integrapse.c` no Dev-C++.
2. Selecione **Execute > Compile & Run** (tecla F11).
3. Utilize o menu exibido no console.

Também é possível compilar pelo terminal:

```bash
gcc src/integrapse.c -o integrapse
./integrapse
```

O manual completo está em `docs/segunda-entrega/manual-do-usuario.md`.

## Estrutura do projeto

```text
integra-pse/
├── README.md
├── .gitignore
├── docs/
│   ├── primeira-entrega/
│   └── segunda-entrega/
└── src/
    └── integrapse.c
```

A pasta `docs` armazena os artefatos relacionados à documentação da AEP, enquanto `src` armazena o código-fonte da aplicação.

## Documentação

A documentação da primeira etapa inclui:

* Produção textual;
* Requisitos funcionais e não funcionais;
* Fluxogramas;
* Pseudocódigos;
* Planejamento das sprints;
* Referências utilizadas.

Os arquivos podem ser encontrados em `docs/primeira-entrega/`.

A documentação da segunda etapa inclui:

* Documento completo da segunda entrega;
* Diagrama e descrição dos casos de uso;
* Requisitos atualizados;
* Testes realizados;
* Manual do usuário;
* Acompanhamento das sprints;
* Capturas de tela da execução.

Os arquivos podem ser encontrados em `docs/segunda-entrega/`.

## Vídeo de apresentação

O vídeo de apresentação do projeto está disponível em: [https://youtu.be/PSBip6JPchY](https://youtu.be/PSBip6JPchY)

## Status do projeto

✅ **Concluído — 2ª etapa: implementação, testes e documentação final**

A aplicação em C foi implementada com todas as funcionalidades previstas e testada no Dev-C++.

## Integrantes

* Felipe Zotareli Froes — RA: 26003110-2
* Julia Petrafeza de Oliveira — RA: 26009540-2
* Vitor Hugo Fernandes Lissoni — RA: 26002354-2

## Instituição

**Universidade Cesumar — UniCesumar**

Curso de Engenharia de Software
2º semestre — 2026

## Observação

Este projeto possui finalidade acadêmica. Todos os exemplos utilizados pelo sistema utilizam informações fictícias e coletivas, preservando a privacidade dos estudantes.
