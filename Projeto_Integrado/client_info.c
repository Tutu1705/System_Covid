#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct endStruct{
    char rua[50];
    char bairro[40];
    char numero[5];
    char cep[9];
    char cidade[20];
    char estado[20];
}end;


typedef struct persStruct{
    char nome[30];
    int cpf[12];
    int tel[12];
    int nasc[8];
    char mail[40];

}pers;


typedef struct sauStruct{
    int diagd[8];
    char cmbd[20];
}sau;


