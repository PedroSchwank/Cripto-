#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para guardar dados e informaçoes 
typedef struct {
    double saldo;
    double bitcoin;
    double ethereum;
    double ripple;
    double cotacao_bitcoin;
    double cotacao_ethereum;
    double cotacao_ripple;
} Conta;

// Funções
void exibir_menu(Conta *conta);
void consultar_saldo(Conta *conta);
void ver_extrato();
double depositar(Conta *conta);
double sacar(Conta *conta);
void comprar_criptomoedas(Conta *conta);
void vender_criptomoedas(Conta *conta);
void atualizar_cotacao(Conta *conta);
void sair();
void autenticacao();
void salvar_transacao(const char *tipo, const char *detalhes);
void carregar_saldo(Conta *conta);
void reescrever_no_txt(Conta *conta);
void escrever_no_extrato(const char *extrato);

// Função que gera um valor aleatório 
double random_double(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

// Função pra carregar o saldo pelo TXT
void carregar_saldo(Conta *conta) {
    FILE *arquivo = fopen("saldo.txt", "r");
    if (arquivo == NULL) {
        // Cria o TXT com valores inicais 
        conta->saldo = 0.0;
        conta->bitcoin = 0.0;
        conta->ethereum = 0.0;
        conta->ripple = 0.0;
        conta->cotacao_bitcoin = 320000;
        conta->cotacao_ethereum = 15000;
        conta->cotacao_ripple = 2.62;

        arquivo = fopen("saldo.txt", "w");
        fprintf(arquivo, "%.2f\n%.4f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n", 
                conta->saldo, conta->bitcoin, conta->ethereum, 
                conta->ripple, conta->cotacao_bitcoin, 
                conta->cotacao_ethereum, conta->cotacao_ripple);
    } else {
        fscanf(arquivo, "%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n", 
            &conta->saldo, &conta->bitcoin, &conta->ethereum, 
            &conta->ripple, &conta->cotacao_bitcoin, 
            &conta->cotacao_ethereum, &conta->cotacao_ripple);
    }
    fclose(arquivo);
}

// Função que reescreve todos os dados da conta no TXT depois das transações
void reescrever_no_txt(Conta *conta) {
    FILE *arquivo = fopen("saldo.txt", "w");
    fprintf(arquivo, "%.2f\n%.4f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n", 
            conta->saldo, conta->bitcoin, conta->ethereum, 
            conta->ripple, conta->cotacao_bitcoin, 
            conta->cotacao_ethereum, conta->cotacao_ripple);
    fclose(arquivo);
}

// Função pra salvar as transações no extrato/txtt
void escrever_no_extrato(const char *extrato) {
    FILE *arquivo = fopen("extrato.txt", "a");
    fprintf(arquivo, "%s\n", extrato);
    fclose(arquivo);
}

// Função pra salva transações no TXT
void salvar_transacao(const char *tipo, const char *detalhes) {
    char transacao[256];
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);
    snprintf(transacao, sizeof(transacao), "[%02d/%02d/%d %02d:%02d:%02d] %s: %s", 
             t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, 
             t->tm_hour, t->tm_min, t->tm_sec, tipo, detalhes);
    escrever_no_extrato(transacao);
} 