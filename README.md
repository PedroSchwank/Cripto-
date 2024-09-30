# Cripto-
Projeto Banco de Criptomoedas em C
. Nomes
-Pedro de Oliveira Schwank
RA: 24.124.052-2
-Felipe Falcon
RA: 24.124.035-7
-Leo Guadagni
RA:24.124.022-5
. Funções:
Funções principais do sistema bancário:
exibir_menu: Mostra o menu principal do sistema e permite que o usuário escolha uma operação.
consultar_saldo: Exibe o saldo da conta, incluindo criptomoedas.
ver_extrato: Lê e exibe o histórico de transações do arquivo extrato.txt.
depositar: Permite o depósito de um valor em reais na conta.
sacar: Permite o saque de um valor da conta.
comprar_criptomoedas: O usuário pode investir seu saldo em criptomoedas.
vender_criptomoedas: O usuário pode vender suas criptomoedas para aumentar o saldo em reais.
atualizar_cotacao: Atualiza as cotações das criptomoedas para valores aleatórios (dentro de um intervalo).
sair: Encerra o programa.
autenticacao: Realiza a autenticação do usuário solicitando CPF e senha.
Funções auxiliares:
random_double: Gera um valor aleatório em um intervalo, usado para simular as cotações de criptomoedas.
carregar_saldo: Carrega o saldo da conta a partir de um arquivo saldo.txt. Se o arquivo não existir, cria um com valores iniciais.
reescrever_no_txt: Reescreve os dados da conta no arquivo saldo.txt após qualquer transação.
escrever_no_extrato: Salva cada transação em um arquivo extrato.txt.
salvar_transacao: Formata e registra uma transação (com data e hora) no extrato.
. Autenticação:
A função autenticacao solicita ao usuário uma senha de 6 dígitos e um CPF de 11 dígitos. A autenticação é simulada comparando com um CPF e senha específicos. Se a combinação for correta, o saldo é carregado e o menu principal é exibido.
. Arquivos criados:
O programa utiliza dois arquivos de texto:

saldo.txt: Armazena as informações da conta (saldo e criptomoedas).
extrato.txt: Armazena o histórico de transações (depósitos, saques, compra/venda de criptomoedas, etc.).
Se esses arquivos não existirem, o programa os criará com valores padrão.

. Processo de funcionamento:
Autenticação: Ao iniciar, o programa pede um CPF e senha. Se o login for bem-sucedido, o saldo da conta é carregado.
Operações: O usuário pode escolher as operações através do menu, como consultar saldo, depositar, sacar ou realizar transações com criptomoedas.
Transações e extrato: Cada operação é registrada no arquivo de extrato com data e hora.
Cotação: As cotações de criptomoedas são simuladas e podem ser atualizadas com valores aleatórios em intervalos predefinidos.
Finalização: O programa pode ser encerrado pela opção "Sair" no menu principal.

. Objetivo do projeto:
Este código simula um sistema básico de gerenciamento financeiro com operações em criptomoedas, integrado com persistência de dados em arquivos de texto.






