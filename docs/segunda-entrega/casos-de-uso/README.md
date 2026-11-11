# Casos de uso

O diagrama `diagrama-casos-de-uso.png` representa as funcionalidades do IntegraPSE e a interação do operador da equipe intersetorial do PSE com o sistema.

| Código | Caso de uso | Fluxo principal | Fluxo alternativo |
| --- | --- | --- | --- |
| UC01 | Cadastrar ação | O operador escolhe a opção 1 e informa os dados da ação. O sistema valida os dados e grava a ação como planejada. | Se algum dado for inválido, o cadastro é cancelado e uma mensagem de erro é exibida. |
| UC02 | Listar ações | O operador escolhe a opção 2 e o sistema exibe todas as ações cadastradas. | Se não houver ações, o sistema informa que nenhuma ação foi cadastrada. |
| UC03 | Pesquisar ação | O operador escolhe o critério (código, escola ou tema), informa o valor e o sistema exibe as ações encontradas. | Se nenhuma ação corresponder ao critério, o sistema informa que nada foi encontrado. |
| UC04 | Atualizar situação | O operador informa o código e a nova situação, e o sistema grava a alteração. | Se o código não existir ou a situação for inválida, nenhuma alteração é feita. |
| UC05 | Registrar participantes efetivos | Quando a nova situação é REALIZADA, o operador informa o número de participantes efetivos. | Se o valor for negativo ou não numérico, a atualização é cancelada. |
| UC06 | Gerar resumo geral | O operador escolhe a opção 5 e o sistema exibe as quantidades por situação e o percentual de participação. | Se não houver ações realizadas, o percentual é exibido como 0,0%. |
| UC07 | Validar entradas | O sistema verifica tipo, preenchimento, formato e faixa de cada dado informado. | Se a entrada for inválida, a operação é cancelada sem alterar os registros. |

O caso de uso **Validar entradas (UC07)** é incluído («include») no cadastro, na pesquisa e na atualização. O caso de uso **Registrar participantes efetivos (UC05)** estende («extend») a atualização da situação, pois só ocorre quando a ação é marcada como realizada.
