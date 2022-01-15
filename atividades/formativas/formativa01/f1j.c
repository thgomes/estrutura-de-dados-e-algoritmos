#include <stdio.h>

struct tipoFiliacao {
    char nome[80];
    char nomeMae[80];
    char nomePai[80];
};

struct tipoFiliacao separaLinhaCSV(char linha[240]) {
    int indexVirgula[2];
    
    struct tipoFiliacao NOMES;

    int j = 0;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == ',') {
            indexVirgula[j] = i;
            j++;
        }
    }

    int indexNome = 0, indexNomeMae = 0, indexNomePai = 0;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (i < indexVirgula[0]) {
            NOMES.nome[indexNome] = linha[i];
            indexNome++;

        } else if (i > indexVirgula[0] && i < indexVirgula[1]) {
            NOMES.nomeMae[indexNomeMae] = linha[i];
            indexNomeMae++;

        } else if (i > indexVirgula[1]) {
            NOMES.nomePai[indexNomePai] = linha[i];
            indexNomePai++;
        }
    }

    NOMES.nome[indexNome] = '\0';
    NOMES.nomeMae[indexNomeMae] = '\0';
    NOMES.nomePai[indexNomePai] = '\0';

    return NOMES;
};
