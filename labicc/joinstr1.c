#include <stdio.h>
#include <string.h>

#define maxA 130
#define maxB 130
#define maxparam 20

void remover_final(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}

void remover_inicio(char **str) {
    while (**str == ' ') {
        (*str)++;
    }
}

int main() {
    char A[maxA + 1];
    char B[maxB + 1];
    char param[maxparam + 1];

    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    fgets(param, sizeof(param), stdin);

    remover_final(A);
    remover_final(B);
    remover_final(param);

    char *posA = strstr(A, param);
    char *posB = strstr(B, param);

    if (posA) {
        int lenA = posA - A;
        char temp[lenA + 1];
        strncpy(temp, A, lenA);
        temp[lenA] = '\0';
        remover_final(temp);
        printf("%s", temp);
        if (*(posA + strlen(param)) != ' ') {
            printf(" ");
        }
    } else {
        remover_final(A);
        printf("%s", A);
        printf(" ");
    }

    if (posB) {
        int tamParam = strlen(param);
        char *restB = posB + tamParam;
        remover_inicio(&restB);
        printf("%s", restB);
    }

    printf("\n");

    return 0;
}
