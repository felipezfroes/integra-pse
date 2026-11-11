# Testes realizados — IntegraPSE

Os testes foram realizados no console do Windows, a partir do programa compilado no Dev-C++ 5.11 (TDM-GCC 4.9.2), comparando o resultado obtido com o resultado esperado.

| ID | Caso de teste | Resultado esperado | Situação |
| --- | --- | --- | --- |
| CT01 | Cadastro com dados válidos | Ação cadastrada como planejada | Aprovado |
| CT02 | Cadastro com código repetido | Mensagem de código já existente | Aprovado |
| CT03 | Cadastro com código negativo ou com letras | Mensagem de código inválido | Aprovado |
| CT04 | Cadastro com campo obrigatório vazio | Cadastro cancelado | Aprovado |
| CT05 | Cadastro com data inválida (31/02/2026) | Mensagem de data inválida | Aprovado |
| CT06 | Cadastro com participantes negativos | Mensagem de quantidade inválida | Aprovado |
| CT07 | Listagem sem ações cadastradas | Mensagem "Nenhuma acao cadastrada" | Aprovado |
| CT08 | Listagem com quatro ações | Exibição das quatro ações | Aprovado |
| CT09 | Pesquisa por parte do nome da escola | Exibição das ações da escola | Aprovado |
| CT10 | Pesquisa por código inexistente | Mensagem de nenhuma ação encontrada | Aprovado |
| CT11 | Atualizar ação para realizada | Situação alterada e participantes registrados | Aprovado |
| CT12 | Atualizar ação inexistente | Mensagem de ação não encontrada | Aprovado |
| CT13 | Resumo com ações em situações diferentes | Percentual de 90,0% (135 de 150) | Aprovado |
| CT14 | Opção inexistente ou texto no menu | Mensagem de erro e novo menu | Aprovado |
| CT15 | Encerramento do programa | Mensagem de encerramento | Aprovado |

Durante os testes, foi identificada uma falha na leitura da data, que podia ultrapassar o tamanho do campo quando o usuário digitava caracteres a mais. A falha foi corrigida com a leitura da data em uma variável auxiliar, que só é copiada para a estrutura depois de validada.
