#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char text[1000];
    printf("Digite um texto: ");
    fgets(text, sizeof(text), stdin);

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

    return 0;
}
