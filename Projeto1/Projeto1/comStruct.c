//Giovanni Favorin de Melo
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Declaração de Structs
typedef struct {
    int ID[1000], idade[1000];
    char nome[1000][100], sexo[1000][10], endereco[1000][100], email[1000][100];
    double altura[1000];
    bool vacina[1000];
} dadosUser;

typedef struct {
    int quantUsers;
    int posCad;
    int posedit;
    int posSalva;

} contadores;
//Fim de Structs

//print user e dar a oferta de editar ou excluir o user em base da pos

//Declaração das Funções 
void inicializarStruct(dadosUser *inCadUser, contadores *inCounts);
void pegaID(dadosUser *CadUser, contadores *Counts);
void pegaNome(dadosUser *CadUser, contadores *Counts);
void pegaIdade(dadosUser *CadUser, contadores *Counts);
void pegaSexo(dadosUser *CadUser, contadores *Counts);
void pegaAltura(dadosUser *CadUser, contadores *Counts);
void pegaEndereco(dadosUser *CadUser, contadores *Counts);
void pegaVacina(dadosUser *CadUser, contadores *Counts);
void pegaEmail(dadosUser *CadUser, contadores *Counts);
void printUser(dadosUser *printUser, contadores *printCounts);
void excludeUser(dadosUser *exUser, contadores *exCounts);
void editUser(dadosUser *editUser, contadores *editCounts);
void menuBackup();
void backupUser();
void menuBusca();
int buscaID(dadosUser *CadUser, contadores *Counts);
int buscaEmail(dadosUser *CadUser, contadores *Counts);
//Fim das Funções


//Main
int main(){
    int choiceInic = 0, final = 0;
    dadosUser cadUser;
    contadores count;

    inicializarStruct(&cadUser, &count);

    do{
        do{
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n");
            printf("\nDigite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira excluir algum usuario\nDigite 3 - Caso queira editar os dados de algum usuario\nDigite 4 - Caso queira abrir o menu de Backup\nDigite 5 - Caso queira encontrar algum usuario\nDigite 6 - Caso queira encerrar a sessao");
            scanf("%d", &choiceInic);
            switch (choiceInic){
            case 1://Cadastrar usuario
                printf("\33[H\33[2J");
                printf("_________________Cadastro___________________\n");
                printf("Preencha os dados a seguir para concluir o cadastro");

                pegaID(&cadUser, &count);
                pegaNome(&cadUser, &count);
                pegaIdade(&cadUser, &count);
                pegaSexo(&cadUser, &count);
                pegaAltura(&cadUser, &count);
                pegaEndereco(&cadUser, &count);
                pegaVacina(&cadUser, &count);
                pegaEmail(&cadUser, &count);

                printf("Os dados sao:\n");
                printUser(&cadUser, &count);
                //printar quantos cad tem e quantos faltam
                
                break;

            case 2://Exclude usuario
                
                excludeUser(&cadUser, &count);
                break;

            case 3://Editar usuario
                editUser(&cadUser, &count);
                break;

            case 4://Backup
                backupUser();
                break;

            case 5://Busca usuario
                menuBusca();
                break;

            case 6://Encerrar sessao
                final = 6;
                break;

            default:
                break;
            }
        } while (choiceInic > 6 || choiceInic < 1);
    } while (final != 6);

    return 0;
}
//Fim da Main


//criação das Funções

void inicializarStruct(dadosUser *inCadUser, contadores *inCounts){
    for (int i = 0; i != 1000; i++){
        inCadUser->ID[i] = 0;
        inCadUser->idade[i] = 0;
        inCadUser->altura[i] = 0;
    }
    inCounts->quantUsers = 0;
    inCounts->posCad = 0;
}

void pegaID(dadosUser *cadUser, contadores *counts){
    srand(time(NULL));
    cadUser->ID[counts->posSalva] = (rand() % (999999 - 100000 + 100000) + 100000);
    for (int i = 0; i < counts->posSalva; i++){
        if (cadUser->ID[counts->posSalva] == cadUser->ID[i]){
            cadUser->ID[counts->posSalva] = (rand() % (999999 - 100000 + 100000) + 100000);
            i = 0;
        }
    }
}

void pegaNome(dadosUser *cadUser, contadores *counts){
    do{
        printf("Qual o nome do usuário?");
        fflush(stdin);
        fgets(cadUser->nome[counts->posSalva], 100, stdin);
    } while (strlen(cadUser->nome[counts->posSalva] < 2));
}

void pegaIdade(dadosUser *cadUser, contadores *counts){

}

void pegaSexo(dadosUser *cadUser, contadores *counts){

}

void pegaAltura(dadosUser *cadUser, contadores *counts){

}

void pegaEndereco(dadosUser *cadUser, contadores *counts){

}

void pegaVacina(dadosUser *cadUser, contadores *counts){

}

void pegaEmail(dadosUser *cadUser, contadores *counts){

}
