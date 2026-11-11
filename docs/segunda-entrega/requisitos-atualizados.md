# Requisitos atualizados — IntegraPSE

Durante a implementação e os testes, alguns requisitos definidos na primeira entrega (`docs/primeira-entrega/requisitos.md`) foram ajustados. Os demais requisitos permaneceram como descritos originalmente.

| Requisito | Alteração | Justificativa |
| --- | --- | --- |
| Cadastrar ação (RF01) | A situação inicial passou a ser definida automaticamente como planejada. | Evitar que uma ação seja cadastrada como realizada sem participantes efetivos. |
| Pesquisar ação (RF03) | A pesquisa por escola e tema passou a aceitar parte do nome, sem diferenciar maiúsculas e minúsculas. | Nos testes, a pesquisa exata exigia digitar o nome completo da escola ou do tema. |
| Gerar resumo geral (RF06) | O resumo passou a mostrar também o total de ações cadastradas. | Facilitar a conferência dos valores apresentados. |
| Validar entradas (RF08) | Foram incluídas a validação da data e de textos digitados em campos numéricos. | Situações identificadas durante os testes. |
| Compatibilidade (RNF03) | As mensagens do programa foram escritas sem acentuação. | Garantir a exibição correta no console do Windows. |
