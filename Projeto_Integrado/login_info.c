#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//      INÍCIO DO PROGRAMA
int init(){

    char opt;
    printf("------------------ANTI-COVID SYSTEMS------------------");
    printf("\n\nEscolha um item:\n[1] Criar login e senha\n[2] Entrar com login e senha existentes.\n\n");
    scanf("%d",&opt);

    if(opt==1){
        //system("cls");
        crtaccess();
    } else if(opt==2){
       // system("cls");
        access();
    } else {
        printf("Opção incorreta. \n Tente novamente.");
        return init();
    }
    return 0;
}



// CRIACAO DOS ARQUIVOS NECESSÁRIOS
int crtfile(){

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","a");
    if(logincred==NULL){
        printf("Erro ao criar o arquivo 'LOGIN'.\n");
        return EXIT_FAILURE;
    }
    fclose(logincred);

    FILE *cadpac;
    cadpac = fopen("/home/k4nek1/Desktop/cadastro.txt","a");
    if(cadpac==NULL){
        printf("Erro ao criar o arquivo - 'PACIENTES'.");
        return EXIT_FAILURE;
    }
}


//      BLOCO DE FUNÇÕES DE LOGIN
int crtuser(){

    char id[20];
    int tam;

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","a");


    printf("\nCrie seu login de usuário com até 20 caracteres: \n");
    scanf("%s",&id);
    tam = strlen(id);
    if(tam>20){
        printf("Limite de caracteres excedido, tente novamente.");
        return crtuser();
    }
    fprintf(logincred,"%s\n",id);
    fclose(logincred);
}

int crtpwd(){

    char pwd[10];
    int tam;

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","a");

    printf("\nCrie sua senha de até 10 caracteres: \n");
    scanf("%s",&pwd);
    tam = strlen(pwd);
    if(tam>10){
        printf("Limite de caracteres excedido, tente novamente.");
        return crtpwd();
    }
    fprintf(logincred,"%s\n",pwd);
    fclose(logincred);
}

int crtaccess(){

    crtuser();
    crtpwd();
    //system("cls");
    printf("\n");
    access();
    return 0;
}

int access(){

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","r");

    char id[20];
    char pwd[10];
    char ida[20];
    char pwda[10];
    char accs[10][100];
    int i;


    printf("Digite seu usuário:\n");
    scanf("%s",&ida);
    for(i=0;i<10 && fgets(accs[i],100,logincred) != NULL;i++){
        if(strcmp(accs[i],ida)==0)
            printf("%s",accs[i]);
        }/*else{
            printf("Login não localizado.");
            break;
        }*/
        //return access;


    printf("\nDigite sua senha: \n");
    scanf("%s",&pwda);
   /* for(i=0;i<10 && fgets(accs[i],100,logincred)!=NULL;i++){

    }*/

    if(strcmp(ida,id)==0 && strcmp(pwda,pwd)==0){
        printf("Acesso realizado com sucesso. \n");
    }else{
        printf("Usuário ou senha incorreto. Tente novamente. \n");
        return access();
    }
    fclose(logincred);
}


//      BLOCO DE CADASTROS DES PACIENTES
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



//      MENU OPÇÃO
void menup(){

    int opt;
    int i;

    do{
        printf("Selecione uma das opções: \n");
        printf("--------------------------------------------- \n");
        printf("| [1] - Cadastrar paciente.                 |\n");
        printf("| [2] - Sair do login atual.                |\n");
        printf("| [3] - Sair do programa.                   |\n");
        printf("---------------------------------------------");
        printf("\n");
        fflush(stdin);
        scanf("%d",&opt);
 //     system("cls");
        switch(opt){
            case 1:
                menuc();
                break;
            case 2:
                init();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Opção inválida. Tente novamente.");
                return menup();
        }
    }
    while(opt != 3);
}



int menuc(){
}


// MAIN...
int main(){
   // init();
    menup();
}
