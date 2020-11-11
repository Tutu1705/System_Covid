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
        crtuser();
    } else if(opt==2){
       // system("cls");
        access();
    } else {
        printf("Opção incorreta. \n Tente novamente.");
        return init();
    }
    return 0;
}



//      CRIACAO DOS ARQUIVOS NECESSÁRIOS
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

    char id[21], senha[21];
    int tam;

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","a");
    if(logincred==NULL){
        logincred = fopen("/home/k4nek1/Desktop/login.txt","w");
    }
    inicio :
    printf("\nCrie seu login de usuário com seu primeiro nome: \n");
    scanf("%s",&id);
    tam = strlen(id);
    if(tam > 20){
        printf("Limite de caracteres excedido, tente novamente.");
        goto inicio;
    }
    check_pass :
    printf("\nCrie sua senha com 8 à 20 caracteres.\n");
    scanf("%s",&senha);
    tam = strlen(senha);
    if(tam < 8 || tam > 20){
        printf("Senha não segue os critérios, tente novamente.");
        goto check_pass;
    }
    fprintf(logincred,"%s ",id);
    fprintf(logincred, "%s \n", senha);
    fclose(logincred);
}

int access(){

    char nome[21], senha[21], id[21], pw[21];

    FILE *logincred;
    logincred = fopen("/home/k4nek1/Desktop/login.txt","r");

    log: ;
    int nm=0;
    printf("\nDigite seu usuário:\n");
    scanf("%s",&nome);
    while(fscanf(logincred,"%s",id)!= EOF){
        if(strcmp(nome,id)==0){
            nm = 1;
            break;
        }
    }

    pwd: ;
    int sn=0;
    printf("\nDigite sua senha: \n");
    scanf("%s",&senha);
    while(fscanf(logincred,"%s",pw)!= EOF){
        if(strcmp(pw,senha)==0){
            sn = 1;
            break;
        }
    }

    fclose(logincred);
    if(nm == 1 && sn == 1){
        printf("Acesso realizado com sucesso! \n");
        //system("cls");
        menup();
    }else if(nm == 0){
        printf("Login não cadastrado. Tente novamente.\n");
        goto log;
    }else if(sn == 0){
        printf("Senha incorreta.");
        goto pwd;
    }
}


//      BLOCO DE CADASTROS DOS PACIENTES
struct endStruct{
    char rua[50];
    char bairro[40];
    char numero;
    char cep[9];
    char cidade[20];
    char estado[20];
};

struct dnStruct{
    int dia;
    int mes;
    int ano;
};

struct ddStruct{
    int dia;
    int mes;
    int ano;
};

struct sauStruct{
    char morb[20];
    struct ddStruct tp_diag_d;
};

struct persStruct{
    char nome[30];
    int cpf;
    int tel;
    char mail[40];
    struct endStruct tp_end;
    struct dnStruct tp_d_nasc;
    struct sauStruct tp_saude;
};

struct persStruct cad_paciente[5];


int cadastro(){

    int i;
    char opt_morb, opt_cad;
    char em[13] = {'@','o','u','t','l','o','o','k','.','c','o','m'};

    FILE *cadpac;
    cadpac = fopen("/home/k4nek1/Desktop/cadastro.txt","a");
    if(cadpac==NULL){
        printf("Erro ao criar o arquivo - 'PACIENTES'.");
        return EXIT_FAILURE;
    }

    cadp: ;
    for(i=0;i<1;i++){
        printf("---------------------------------------------\n");
        printf("Insira os dados do paciente: ");
        //      DADOS PESSOAIS
        printf("\n\nNome: ");
        scanf("%s",&cad_paciente[i].nome);
        printf("\nCPF: ");
        scanf("%d",&cad_paciente[i].cpf);
        printf("\nTelefone: ");
        scanf("%d",&cad_paciente[i].tel);
        printf("\nEmail: ");
        scanf("%s",&cad_paciente[i].mail);
        printf("\nDia de Nascimento: ");
        scanf("%d",&cad_paciente[i].tp_d_nasc.dia);
        printf("\nMes de Nascimento: ");
        scanf("%d",&cad_paciente[i].tp_d_nasc.mes);
        printf("\nAno de Nascimento: ");
        scanf("%d",&cad_paciente[i].tp_d_nasc.ano);

        //      DADOS DE ENDEREÇO
        printf("\nRua: ");
        scanf("%s",&cad_paciente[i].tp_end.rua);
        printf("\nBairro: ");
        scanf("%s",&cad_paciente[i].tp_end.bairro);
        printf("\nNumero: ");
        scanf("%d",&cad_paciente[i].tp_end.numero);
        printf("\nCEP: ");
        scanf("%d",&cad_paciente[i].tp_end.cep);
        printf("\nCidade: ");
        scanf("%s",&cad_paciente[i].tp_end.cidade);
        printf("\nEstado: ");
        scanf("%s",&cad_paciente[i].tp_end.estado);

        //      DADOS DE SAÚDE
        printf("\nDia do Diagnóstico: ");
        scanf("%d",&cad_paciente[i].tp_saude.tp_diag_d.dia);
        printf("\nMes do Diagnóstico: ");
        scanf("%d",&cad_paciente[i].tp_saude.tp_diag_d.mes);
        printf("\nAno: ");
        scanf("%d",&cad_paciente[i].tp_saude.tp_diag_d.ano);

        cadmorb:
        printf("\nPaciente possui alguma morbidade? S|N");
        scanf("%c",&opt_morb);
        if(opt_morb == 'S'){
            printf("Informe a morbidade: ");
            scanf("%s",&cad_paciente[i].tp_saude.morb);
        }else if(opt_morb == 'N'){
            goto result_cad;
        }else{
            printf("Opção inválida. Tente novamente.");
            goto cadmorb;
        }

        result_cad:
        printf("\nCadastro de paciente realizado com sucesso.");
    }

        repeat_cadp:
        printf("\nDeseja cadastrar outro paciente? S|N");
        scanf("%c",&opt_cad);
        if(opt_cad=='S'||opt_cad=='s'){
            goto cadp;
        }else if(opt_cad=='N'||opt_cad=='n'){
            menup();
        }else{
            printf("Opção inválida. Tente novamente.");
            goto repeat_cadp;
        }





}

//      MENU OPÇÃO
void menup(){

    int opt;
    int i;

    do{
        printf("Selecione uma das opções: \n");
        printf("---------------------------------------------\n");
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
                cadastro();
                break;
            case 2:
                init();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Opção inválida. Tente novamente.\n\n");
                return menup();
        }
    }
    while(opt != 3);
}


//      MAIN...
int main(){

    //init();
    //access();
    cadastro();
    //cadastro();
}
