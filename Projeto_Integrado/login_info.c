#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char userid[20];
    char password[10];
} login; login l[1];


int init(){

    int opt;

    printf("Escolha um item:\n[1] Criar login e senha\n[2] Entrar com login e senha existentes.\n");
    scanf("%d",&opt);


    switch(opt){
        case '1':
            crtaccess();
            break;
        case '2':
            access();
            break;
        default:
            printf("Opção inválida. \n Tente novamente.");
            return init();
    }


    if(i==1){
        crtaccess();
    } else if(i==2){
        access();
    } else {
        printf("Opção incorreta. \n Tente novamente.");
        return init();
    }
}


int crtaccess(){

    struct login cra;

    printf("\n\nInsira seu primeiro nome, ele será o seu login de usuário : \n");
    scanf("%s",&cra[0].userid);
    printf("Crie sua senha com até 10 caracteres: \n");
    scanf("%s",&cra[0].password);

    return userid1,password;
}

int access(){



    char userid[20];
    char password[10];

    strcpy(l[0].userid, id);
    strcpy(l[0].password, pwd);

    printf("Digite seu usuário: \n");
    scanf("%s",&userid);
    printf("Digite sua senha: \n");
    scanf("%s",&password);

    if((strcmp(userid,l[0].userid)==0)&&strcmp(password,l[0].password)==0){
        printf("Acesso realizado com sucesso.\n");
    }else{
        printf("Usuário ou senha incorreto. Tente novamente\n");
        return access();
    }
}
