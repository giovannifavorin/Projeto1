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
}   cadUser;

typedef struct {
    int quantUsers;

}   conts;
//Fim de Structs


//Declaração das Funções 
void inicializarStruct(cadUser *inCadUser, conts *inConts);
void cadastraUser();
void pegaID();
void pegaNome();
void pegaIdade();
void pegaSexo();
void pegaAltura();
void pegaEndereco();
void pegaVacina();
void pegaEmail();
void printUser();
void excludeUser();
void editUser();
void menuBackup();
void backupUser();
void menuBusca();
int buscaID();
int buscaEmail();
//Fim das Funções


//Main
int main(){
int choice1 = 0;

    do{
        do{
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n");
            printf("\nDigite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira excluir algum usuario\nDigite 3 - Caso queira editar os dados de algum usuario\nDigite 4 - Caso queira abrir o menu de Backup\nDigite 5 - Caso queira encontrar algum usuario\nDigite 6 - Caso queira encerrar a sessao");
            switch (choice1){
            case 1://Cadastrar usuario
                cadastraUser();
                break;

            case 2://Exclude usuario
                excludeUser();
                break;

            case 3://Editar usuario
                editUser();
                break;

            case 4://Backup
                backupUser();
                break;

            case 5://Busca usuario
                menuBusca();
                break;

            case 6://Encerrar sessao

                break;

            default:
                break;
            }
        } while ();

    } while ();

    return 0;
}
//Fim da Main


//criação das Funções

void inicializarStruct(cadUser *inCadUser, conts *inConts){
    for (int i = 0; i != 1000; i++){
        inCadUser->ID[i] = 0;
        inCadUser->idade[i] = 0;
        inCadUser->altura[i] = 0;
    }
    

}