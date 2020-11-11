#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_info.c"
#include "client_info.c"

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

void menu(){

    char m1 = "'";
    int i;

    //do{
        printf("\n");
        printf("---------------------------------------------")
        for(i=0;i<2;i++){
            printf("%c",m1);
        }
    //}


}

int main(){

   // init();
    menu();


}
