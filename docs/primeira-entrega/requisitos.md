# Requisitos do IntegraPSE

Documentação dos requisitos definidos para o projeto **IntegraPSE — Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola**, desenvolvido como parte da AEP do 2º semestre de 2026 do curso de Engenharia de Software da UniCesumar.

---

## 1. Usuários envolvidos

O usuário principal previsto para o IntegraPSE será o operador da equipe intersetorial responsável pelo acompanhamento das ações do Programa Saúde na Escola.

Esse usuário representa profissionais ou colaboradores das áreas de Saúde e Educação que necessitam registrar, consultar e atualizar informações coletivas relacionadas às atividades realizadas nas escolas.

Na primeira versão do sistema, não haverá cadastro individual de estudantes nem diferentes níveis de acesso.

---

## 2. Escopo do sistema

O IntegraPSE será uma aplicação executada em terminal e desenvolvida em linguagem C.

O sistema deverá permitir:

- cadastrar ações do Programa Saúde na Escola;
- listar as ações cadastradas;
- pesquisar ações por código, escola ou tema;
- atualizar a situação de uma ação;
- registrar a quantidade efetiva de participantes;
- gerar um resumo geral das ações;
- validar as principais entradas fornecidas pelo usuário.

Não fazem parte do escopo obrigatório da primeira versão:

- banco de dados;
- interface gráfica;
- aplicação web;
- autenticação de usuários;
- armazenamento de dados clínicos individuais.

---

## 3. Informações registradas

Cada ação deverá possuir as seguintes informações:

| Campo | Descrição |
| --- | --- |
| Código | Identificador único da ação. |
| Escola | Instituição de ensino em que a ação será realizada. |
| Tema | Tema relacionado ao Programa Saúde na Escola. |
| Data prevista | Data planejada para realização da atividade. |
| Público-alvo | Grupo ao qual a ação será destinada. |
| Responsável | Profissional ou equipe responsável pela atividade. |
| Participantes previstos | Quantidade estimada de participantes. |
| Participantes efetivos | Quantidade registrada após a realização. |
| Situação | Planejada, realizada ou cancelada. |

---

## 4. Requisitos funcionais

| Código | Requisito | Descrição |
| --- | --- | --- |
| RF01 | Cadastrar ação | O sistema deverá permitir o cadastro de uma ação contendo código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista de participantes e situação inicial. |
| RF02 | Listar ações | O sistema deverá permitir a visualização de todas as ações cadastradas, apresentando suas principais informações de forma organizada. |
| RF03 | Pesquisar ação | O sistema deverá permitir pesquisar ações cadastradas utilizando código, escola ou tema como critério de busca. |
| RF04 | Atualizar situação | O sistema deverá permitir alterar a situação de uma ação entre planejada, realizada e cancelada. |
| RF05 | Registrar participantes | Ao marcar uma ação como realizada, o sistema deverá permitir informar a quantidade efetiva de participantes. |
| RF06 | Gerar resumo geral | O sistema deverá apresentar a quantidade de ações planejadas, realizadas e canceladas. |
| RF07 | Calcular participação | O sistema deverá apresentar o total de participantes efetivos e calcular o percentual de participação em relação à quantidade prevista nas ações realizadas. |
| RF08 | Validar entradas | O sistema deverá validar informações fornecidas pelo usuário, evitando códigos repetidos, quantidades negativas, campos obrigatórios vazios e opções inexistentes. |

---

## 5. Requisitos não funcionais

| Código | Requisito | Descrição |
| --- | --- | --- |
| RNF01 | Usabilidade | O sistema deverá apresentar menus e mensagens claras, facilitando a compreensão das operações pelo usuário. |
| RNF02 | Organização | O código deverá ser dividido em funções com responsabilidades específicas, evitando concentrar toda a lógica na função principal. |
| RNF03 | Compatibilidade | A aplicação deverá ser desenvolvida em linguagem C e executada em ambiente compatível com o utilizado na disciplina. |
| RNF04 | Privacidade | O sistema deverá utilizar somente informações coletivas e dados fictícios, sem armazenar dados clínicos individuais dos estudantes. |
| RNF05 | Simplicidade | A primeira versão deverá funcionar em terminal e utilizar armazenamento em memória, sem depender de banco de dados, interface gráfica ou bibliotecas avançadas. |

---

## 6. Requisitos técnicos

A aplicação deverá utilizar:

- menu principal controlado por estrutura de repetição;
- estruturas condicionais;
- laços de repetição;
- vetores;
- funções com responsabilidades específicas;
- estrutura de dados para representar cada ação;
- mensagens claras de confirmação e erro;
- armazenamento dos registros em memória durante a execução.

A persistência em arquivo poderá ser considerada futuramente como melhoria adicional.

---

## 7. Limites éticos

O projeto utilizará somente dados fictícios e informações coletivas.

Não deverão ser cadastrados:

- nomes de estudantes;
- diagnósticos;
- prontuários;
- condições clínicas;
- outros dados sensíveis individuais.

O sistema também não realizará diagnóstico, triagem, prescrição ou recomendação de tratamento.

---

## 8. Riscos identificados

| Risco | Possível impacto | Tratamento |
| --- | --- | --- |
| Entradas inválidas | Informações incorretas podem comprometer os resultados do sistema. | Aplicar validações antes da confirmação das operações. |
| Código duplicado | Registros com o mesmo código dificultariam a identificação das ações. | Verificar a existência do código antes do cadastro. |
| Limite de armazenamento | O vetor poderá atingir sua capacidade máxima. | Definir um limite de registros e informar o usuário. |
| Perda dos registros | Dados armazenados somente em memória serão perdidos ao encerrar o programa. | Documentar a limitação e considerar arquivos como melhoria futura. |
| Aumento excessivo do escopo | Recursos adicionais podem prejudicar a conclusão das funcionalidades obrigatórias. | Priorizar os requisitos definidos pela AEP. |
| Conflitos entre integrantes | Alterações simultâneas podem causar retrabalho ou perda de alterações. | Utilizar GitHub e manter uma divisão clara das atividades. |

---

## Status

**1ª etapa — análise e planejamento.**

A implementação completa em linguagem C será realizada progressivamente nas próximas etapas do projeto.
