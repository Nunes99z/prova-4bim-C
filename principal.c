#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTATOS 50
#define MAX_MENSAGENS 50
#define MAX_HISTORICO 20

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

typedef struct {
    char destinatario[50];
    char conteudo[200];
} Mensagem;

typedef struct {
    char destinatario[50];
    int duracao;
} Ligacao;


int bateria = 100;
int creditos = 10;
char operadora[20] = "MinhaOperadora";
Contato agenda[MAX_CONTATOS];
int total_contatos = 0;
Mensagem mensagens[MAX_MENSAGENS];
int total_mensagens = 0;
Ligacao historico[MAX_HISTORICO];
int total_historico = 0;


void mostrarMenu();
void verNivelBateria();
void mostrarMensagens();
void mostrarHistorico();
void realizarLigacao();
void mostrarAgenda();
void mostrarOperadora();


int main() {
    int opcao;

    while (1) {
        mostrarMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) verNivelBateria();
        else if (opcao == 2) mostrarMensagens();
        else if (opcao == 3) mostrarHistorico();
        else if (opcao == 4) realizarLigacao();
        else if (opcao == 5) mostrarAgenda();
        else if (opcao == 6) mostrarOperadora();
        else if (opcao == 0) break;
        else printf("Opção inválida! Tente novamente.\n");
    }

    printf("Sistema encerrado.\n");
    return 0;
}

void mostrarMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Ver nível de bateria\n");
    printf("2. Mensagens\n");
    printf("3. Histórico de ligações\n");
    printf("4. Realizar ligação\n");
    printf("5. Agenda\n");
    printf("6. Operadora\n");
    printf("0. Sair\n");
}

void verNivelBateria() {
    printf("\nNível de bateria: %d%%\n", bateria);
}

void mostrarMensagens() {
    printf("\n=== MENSAGENS ===\n");
    for (int i = 0; i < total_mensagens; i++) {
        printf("De: %s - %s\n", mensagens[i].destinatario, mensagens[i].conteudo);
    }
    if (total_mensagens == 0) printf("Nenhuma mensagem recebida.\n");
}

void mostrarHistorico() {
    printf("\n=== HISTÓRICO DE LIGAÇÕES ===\n");
    for (int i = 0; i < total_historico; i++) {
        printf("Para: %s - Duração: %d segundos\n", historico[i].destinatario, historico[i].duracao);
    }
    if (total_historico == 0) printf("Nenhuma ligação realizada.\n");
}

void realizarLigacao() {
    if (creditos <= 0) {
        printf("\nSem créditos para realizar ligação.\n");
        return;
    }

    Ligacao ligacao;
    printf("\nDigite o nome do destinatário: ");
    getchar(); // Limpar buffer
    fgets(ligacao.destinatario, 50, stdin);
    ligacao.destinatario[strcspn(ligacao.destinatario, "\n")] = '\0';
    ligacao.duracao = 5;

    printf("Ligando para %s...\n", ligacao.destinatario);
    printf("Ligação encerrada.\n");

    historico[total_historico++] = ligacao;
    creditos--;
}

void mostrarAgenda() {
    int opcao;
    printf("\n=== AGENDA ===\n");
    for (int i = 0; i < total_contatos; i++) {
        printf("Nome: %s - Telefone: %s\n", agenda[i].nome, agenda[i].telefone);
    }
    if (total_contatos == 0) printf("Nenhum contato na agenda.\n");

    printf("\n1. Adicionar contato\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1 && total_contatos < MAX_CONTATOS) {
        Contato novo;
        printf("Digite o nome: ");
        getchar();
        fgets(novo.nome, 50, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';
        printf("Digite o telefone: ");
        fgets(novo.telefone, 15, stdin);
        novo.telefone[strcspn(novo.telefone, "\n")] = '\0';
        agenda[total_contatos++] = novo;
        printf("Contato adicionado.\n");
    }
}

void mostrarOperadora() {
    printf("\nOperadora: %s\n", operadora);
}
