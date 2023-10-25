#include <stdio.h>
#include <string.h>
// 97 -> 122

void buscarSubstring(const char* texto, const char* palavraChave) {
    const char* resultado = strstr(texto, palavraChave);
    
    if (resultado) {
        int posicao_inicial = resultado - texto;
        int posicao_final = posicao_inicial + strlen(palavraChave) - 1;
        printf("Texto encontrado na posio: %d a %d\n", posicao_inicial, posicao_final);
    } else {
        printf("Texto não encontrado.\n");
    }
}

int main() {
    char texto[100];
    char palavraChave[50];
    int escolha = 0;

    printf("Bem-vindo ao programa de busca de texto!\n");

    while (1) {
        printf("\nOpcoes:\n");
        printf("1. Inserir uma nova string\n");
        printf("2. Buscar uma palavra-chave\n");
        printf("3. Sair\n");

        printf("Escolha a opcao (1/2/3): ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite uma nova string: ");
                scanf(" %[^\n]", texto);

                break;
            case 2:
                if (strlen(texto) == 0) {
                    printf("Nenhuma string inserida. Insira uma string primeiro.\n");
                } else {
                    printf("Digite a palavra-chave a ser buscada: ");
                    scanf(" %[^\n]", palavraChave);
                    buscarSubstring(texto, palavraChave);
                }
                break;
            case 3:
                printf("Saindo do programa. Adeus!\n");
                return 0;
            default:
                printf("Opção inválida. Escolha 1, 2 ou 3.\n");
        }
    }

    return 0;
}
