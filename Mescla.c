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

       // Função para calcular a distância de Levenshtein entre duas strings
int levenshteinDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int min = matrix[i - 1][j - 1];
                if (matrix[i][j - 1] < min) {
                    min = matrix[i][j - 1];
                }
                if (matrix[i - 1][j] < min) {
                    min = matrix[i - 1][j];
                }
                matrix[i][j] = 1 + min;
            }
        }
    }

    return matrix[len1][len2];
}


int main() {
    char texto[100];
    char palavraChave[50];
    char text[1000];
    int escolha = 0, op = 0;

    printf("Bem-vindo ao programa de busca de texto!\n");
    printf("\nSelecione qual algoritmo você utilizará\n1 - Pattern Searching Exato\n2 - Pattern Searching Aproximado\n Insira sua escolha: ");
    scanf ("%d", &op);
    switch (op)
    {
    case 1:
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
        break;
    case 2:
    fflush(stdin);

    printf("Digite um texto: ");
    fgets(text, sizeof(text), stdin);
    
    fflush(stdin);

    char searchWord[50];
    printf("Digite a palavra para buscar: ");
    scanf("%s", searchWord);

    // Tokenize o texto em palavras
    char *word = strtok(text, " \t\n");

    printf("Palavras aproximadas encontradas:\n");
    while (word != NULL) {
        int distance = levenshteinDistance(searchWord, word);
        if (distance <= 2) {  // Defina uma distância de edição máxima permitida
            printf("%s (Distância: %d)\n", word, distance);
        }
        word = strtok(NULL, " \t\n");
    }
        break;

    default:
        break;
    }

    return 0;
}
