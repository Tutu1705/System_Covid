#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#include <ctype.h>


//      INÍCIO DO PROGRAMA
int init(){

    char opt;
    printf("------------------ANTI-COVID SYSTEMS------------------");
    printf("\n\nEscolha um item:\n[1] Criar login e senha\n[2] Entrar com login e senha existentes.\n\n");
    scanf("%d",&opt);

    if(opt==1){
        //system("cls");
        crtuser();
        fflush(stdin);
    } else if(opt==2){
       // system("cls");
        access();
        fflush(stdin);
    } else {
        printf("Opção incorreta. \n Tente novamente.");
        return init();
    }
    return 0;
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
    fprintf(logincred,"%s ", id);
    fprintf(logincred, "%s \n", senha);
    system("cls");
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
    fflush(stdin);
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
    fflush(stdin);
    while(fscanf(logincred,"%s",pw)!= EOF){
        if(strcmp(pw,senha)==0){
            sn = 1;
            break;
        }
    }

    fclose(logincred);
    if(nm == 1 && sn == 1){
        printf("\nAcesso realizado com sucesso! \n");
        //system("cls");
        menup();
    }else if(nm == 0){
        printf("Login não cadastrado. Tente novamente.\n");
        goto log;
    }else if(sn == 0){
        printf("Senha incorreta.\n");
        goto log;
    }
}


//      BLOCO DE CADASTROS DOS PACIENTES
struct endStruct{
    char rua[50];
    char bairro[40];
    char numero[4];
    char cep[10];
    char cidade[20];
    char estado[20];
};

struct dnStruct{
    char dia[3];
    char mes[3];
    //char ano[5];
    int ano[5];
};

struct ddStruct{
    char dia[3];
    char mes[3];
    char ano[5];
};

struct sauStruct{
    char morb[20];
    char opt_morb;
    struct ddStruct tp_diag_d;
};

typedef struct {
    char nome[40];
    char cpf[12];
    char tel[12];
    char mail[40];
    struct endStruct tp_end;
    struct dnStruct tp_d_nasc;
    struct sauStruct tp_saude;
}persStruct;

void cadastro(){

    int i, len, len1, idade, atual = 2020, gp_risco = 0, p_morb = 0, *p;
    char opt_cad, t=0;
    persStruct cad_paciente[5];
    p = cad_paciente->tp_d_nasc.ano;

    FILE *cadpac;
    cadpac = fopen("/home/k4nek1/Desktop/cadastro.dbc","ab");
    if(cadpac==NULL){
        printf("Erro ao abrir o arquivo - 'PACIENTES'.");
        return EXIT_FAILURE;
    }

    FILE *grupo_risco;
    grupo_risco = fopen("/home/k4nek1/Desktop/grupo_risco.txt","a");
    if(grupo_risco==NULL){
        printf("Erro ao abrir o arquivo - GRUPO DE RISCO.");
        return EXIT_FAILURE;
    }

    /*if(t==0){
        fprintf(grupo_risco,"%s ","NOME ");
        fprintf(grupo_risco,"%s ","IDADE ");
        fprintf(grupo_risco,"%s ","CEP ");
        fprintf(grupo_risco,"%s \n","COMORBIDADE ");
        t = 1;
    }*/

    cadp: ;
    for(i=0;i<1;i++){
        printf("---------------------------------------------");
        printf("\nInsira os dados do paciente: \n");
        printf("---------------------------------------------");
        //      DADOS PESSOAIS
        printf("\nNome: ");
        fgets(&cad_paciente[i].nome,"%s",stdin);
        len = strlen(cad_paciente[i].nome);
        if(cad_paciente->nome[len-1]=='\n')
            cad_paciente->nome[len-1]=0;

        printf("\nCPF: ");
        fgets(&cad_paciente[i].cpf,"%s ",stdin);

        printf("\nTelefone: ");
        fgets(&cad_paciente[i].tel,"%s ",stdin);

        printf("\nEmail: ");
        fgets(&cad_paciente[i].mail,"%s ",stdin);

        printf("\nDia de Nascimento: ");
        fgets(&cad_paciente[i].tp_d_nasc.dia,"%s ",stdin);

        printf("\nMes de Nascimento: ");
        fgets(&cad_paciente[i].tp_d_nasc.mes,"%s ",stdin);

        printf("\nAno de Nascimento com 4 digitos: ");
        //fgets(&cad_paciente[i].tp_d_nasc.ano,"%d",stdin);
        scanf("%d",&cad_paciente[i].tp_d_nasc.ano);
        getchar();

        //      DADOS DE ENDEREÇO
        printf("\nRua: ");
        fgets(cad_paciente[i].tp_end.rua,"%s ",stdin);

        printf("\nBairro: ");
        fgets(cad_paciente[i].tp_end.bairro,"%s ",stdin);

        printf("\nNumero: ");
        fgets(&cad_paciente[i].tp_end.numero,"%s ",stdin);

        printf("\nCEP: ");
        fgets(cad_paciente[i].tp_end.cep,"%s ",stdin);
        len1 = strlen(cad_paciente[i].tp_end.cep);
        if(cad_paciente->tp_end.cep[len1-1]=='\n')
            cad_paciente->tp_end.cep[len1-1]=0;

        printf("\nCidade: ");
        fgets(cad_paciente[i].tp_end.cidade,"%s ",stdin);

        printf("\nEstado: ");
        fgets(cad_paciente[i].tp_end.estado,"%s ",stdin);

        //      DADOS DE SAÚDE
        printf("\nDia do Diagnóstico: ");
        fgets(&cad_paciente[i].tp_saude.tp_diag_d.dia,"%s ",stdin);

        printf("\nMes do Diagnóstico: ");
        fgets(&cad_paciente[i].tp_saude.tp_diag_d.mes,"%s ",stdin);

        printf("\nAno do Diagnóstico: ");
        fgets(&cad_paciente[i].tp_saude.tp_diag_d.ano,"%s ",stdin);

        cadmorb:
        printf("\nPaciente possui alguma morbidade? [S/N] ");
        fgets(&cad_paciente[i].tp_saude.opt_morb,"%s ",stdin);
        if(cad_paciente[i].tp_saude.opt_morb == 'S'|| cad_paciente[i].tp_saude.opt_morb == 's'){
            printf("\nInforme a morbidade: ");
            fgets(&cad_paciente[i].tp_saude.morb,"%s ",stdin);
        }else if(cad_paciente[i].tp_saude.opt_morb == 'N'||cad_paciente[i].tp_saude.opt_morb == 'n'){
            goto result_cad;
        }else{
            printf("\nOpção inválida. Tente novamente.");
            goto cadmorb;
        }

        result_cad:
        printf("\Paciente cadastrado com sucesso.");

        idade = atual - *p;
        printf("A idade do paciente e: %d",idade);

        if(idade>65){
            if(cad_paciente[i].tp_saude.opt_morb == 'S' || cad_paciente[i].tp_saude.opt_morb == 's'){
                //printf("\nPaciente %s possui morbidade.",cad_paciente[i].nome);
                p_morb = 1;
                gp_risco = 1;
                goto validate;
            }else{
                //printf("\nPaciente %s nao possui morbidade.",cad_paciente[i].nome);
                gp_risco = 1;
                goto validate;
            }
        }else{
            printf("\nPaciente esta fora do grupo de risco.");
        }

        validate:
        if(gp_risco == 1 && p_morb == 1){

            fprintf(grupo_risco,"%s ",cad_paciente->nome);
            fprintf(grupo_risco,"%d ",idade);
            fprintf(grupo_risco,"%s ",cad_paciente->tp_end.cep);
            fprintf(grupo_risco,"%s",cad_paciente->tp_saude.morb);
            //fwrite(idade,sizeof(int),1,grupo_risco);
            //fwrite(&cad_paciente[i].tp_end.cep,sizeof(cad_paciente),1,grupo_risco);

        }else if(gp_risco == 1 && p_morb == 0){

            fprintf(grupo_risco,"%s ",cad_paciente->nome);
            fprintf(grupo_risco,"%d ",idade);
            fprintf(grupo_risco,"%s",cad_paciente->tp_end.cep);

        }else{
            goto repeat_cadp;
        }
        fclose(grupo_risco);

    }

    fwrite(&cad_paciente,sizeof(persStruct),1,cadpac);

        //system("cls");

    repeat_cadp:
    printf("\n\nDeseja cadastrar outro paciente? [S/N]  ");
    scanf("%s",&opt_cad);
    if(opt_cad == 'S' || opt_cad == 's'){
        //system("cls");
        goto cadp;
    }else if(opt_cad == 'N'||opt_cad == 'n'){
        menup();
    }else{
        printf("\nOpção inválida. Tente novamente.");
        goto repeat_cadp;
    }
    fclose(cadpac);

}


//      MENU PRINCIPAL
int menup(){

    char opt;
    int i;

    do{
        printf("\nSelecione uma das opcoes: \n");
        printf("---------------------------------------------\n");
        printf("| [1] - Cadastrar paciente.                 |\n");
        printf("| [2] - Sair do login atual.                |\n");
        printf("| [3] - Sair do programa.                   |\n");
        printf("---------------------------------------------");
        printf("\n");
        scanf("%d",&opt);
        getchar();
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

    int grupo_risco;
    persStruct cad_paciente[5];

    init();
    access();
    cadastro();

    /*FILE *cadpac;
    cadpac = fopen("/home/k4nek1/Desktop/cadastro.dbc","rb");

    while(fread(&cad_paciente,sizeof(persStruct),1,cadpac)){
        printf("%s%s%s%s",cad_paciente->nome,cad_paciente->cpf,cad_paciente->tel,cad_paciente->mail);
    }*/



}

