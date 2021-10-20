//Giovanni Favorin de Melo
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Declaração de Structs
typedef struct {
    char Quadra[100], bairro[100];
    int casa, CEP;
} endereco;

typedef struct {
    int ID, idade;
    char nome[100], sexo[10], email[100];
    double altura;
    bool vacina;
    endereco endereco;
} dadosUser;

typedef struct {
    int quantUsers, posCad, posedit, posSalva, posExc, posEdit, pos;
} contadores;

typedef struct {
    int choiceInic, final, choiceCad, choiceExc, choiceFinalExc, buscaExc, escID, choiceEdit, buscaEdit, choiceFinalEdit;
} choices;
//Fim de Structs

//print user e dar a oferta de editar ou excluir o user em base da pos

//Declaração das Funções 
void inicializarStruct(dadosUser *inCadUser, contadores *inCounts, choices *inChoices);
void pegaID(dadosUser *CadUser, contadores *Counts);
void pegaNome(dadosUser *CadUser);
void pegaIdade(dadosUser *CadUser);
void pegaSexo(dadosUser *CadUser);
void pegaAltura(dadosUser *CadUser);
void pegaEndereco(dadosUser *CadUser);
void pegaVacina(dadosUser *CadUser);
void pegaEmail(dadosUser *CadUser);
void limpaTela();
void printUser(dadosUser *printUser);
void excludeUser(dadosUser *exUser, contadores *exCounts);
// void editUser(dadosUser *editUser, contadores *editCounts);
// void menuBackup();
// void backupUser();
// void menuBusca();
// void buscaEmail();
// void buscaID();

//Fim das Funções


//Main
int main(){
    int quantTotal = 0, quantAtual = 0, i = 0, buscaID = 0;
    dadosUser cadUser[1000];
    contadores count;
    choices choices;
    char buscaEmail[100];

    for (int j = 0; j != 1000; j++){
        inicializarStruct(&cadUser[j], &count, &choices);
    }

    do{
        do{
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n");
            printf("\nDigite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira excluir algum usuario\nDigite 3 - Caso queira editar os dados de algum usuario\nDigite 4 - Caso queira abrir o menu de Backup\nDigite 5 - Caso queira ver a lista de todos os cadastros\nDigite 6 - Caso queira encerrar a sessao\n");
            scanf("%d", &choices.choiceInic);
            switch (choices.choiceInic){
            case 1://Cadastrar usuario
                limpaTela();
                printf("_________________Cadastro___________________\n");
                printf("Preencha os dados a seguir para concluir o cadastro\n");

                do{
                pegaID(&cadUser[i], &count);
                pegaNome(&cadUser[i]);
                pegaIdade(&cadUser[i]);
                pegaSexo(&cadUser[i]);
                pegaAltura(&cadUser[i]);
                pegaEndereco(&cadUser[i]);
                pegaVacina(&cadUser[i]);
                pegaEmail(&cadUser[i]);

                //printUser(&cadUser[i], &count);

                i++;
                count.quantUsers = i;
                printf("A quantidade de cadastros em aberto: %d\nA quantidade de cadastros atuais: %d: \n", 1000 - i, i);
                printf("Deseja cadastrar mais alguem? 0 - SIM  1 - NAO\n");
                scanf("%d", &choices.choiceCad);
                } while (choices.choiceCad != 1);
                break;

            case 2://Exclude usuario
                limpaTela();
                printf("_________________Excluir___________________\n");
                printf("Preencha os dados a seguir para excluir um usuario\n");

                do{
                    do{
                        printf("Caso já saiba o ID ou o Email do usuario que deseja excluir, digite '1', caso nao, digite '2'\n");
                        scanf("%d", &choices.choiceExc);
                    } while (choices.choiceExc != 1 || choices.choiceExc != 2);

                    switch (choices.choiceExc){
                    case 1:
                        limpaTela();
                        printf("Deseja encontrar o usuario pelo ID '1' ou pelo Email '2'?\n");
                        scanf("%d", &choices.buscaExc);
                        switch (choices.buscaExc){
                        case 1:
                            buscaID();
                            count.posExc = count.pos;
                            excludeUser(&cadUser[count.posExc], &count);
                            break;

                        case 2:
                            buscaEmail();
                            count.posExc = count.pos;
                            excludeUser(&cadUser[count.posExc], &count);
                            break;
                        }
                        break;

                    case 2:
                        limpaTela();
                        for (i = 0; i != count.quantUsers; i++){
                            int j = i + 1;
                            printf("Posiçao: %d\n", j);
                            printUser(&cadUser[i]);
                        }
                        do{
                            printf("Qual posicao deseja excluir?");
                            scanf("%d", &count.posExc);
                            count.posExc = count.posExc - 1;
                        } while (count.posExc > count.quantUsers || count.posExc < 1);
                        
                        excludeUser(&cadUser[count.posExc], &count);
                        break;
                    }
                    printf("Deseja excluir mais alguem? 0 - SIM  1 - NAO\n");
                    scanf("%d", &choices.choiceFinalExc);
                } while (choices.choiceFinalExc != 1);
                break;

            case 3://Editar usuario
                do {
                    do{
                        printf("Caso já saiba o ID ou o Email do usuario que deseja excluir, digite '1', caso nao, digite '2'\n");
                        scanf("%d", &choices.choiceEdit);
                    }while (choices.choiceEdit != 1 || choices.choiceEdit != 2);

                    switch(choices.choiceEdit){
                    case 1:
                        limpaTela();
                        printf("Deseja encontrar o usuario pelo ID '1' ou pelo Email '2'?\n");
                        scanf("%d", &choices.buscaEdit);
                        switch(choices.buscaEdit){
                        case 1:   
                            buscaID();
                            count.posEdit = count.pos;
                            editUser(&cadUser[count.posEdit], count);
                            break;

                        case 2:
                            buscaEmail();
                            count.posEdit = count.pos;
                            editUser(&cadUser[count.posEdit], count);
                            break;
                        }
                        break;

                    case 2:
                        limpaTela();
                        for (i = 0; i != count.quantUsers; i++){
                            int j = i + 1;
                            printf("Posiçao: %d\n", j);
                            printUser(&cadUser[i]);
                        }
                        do{
                            printf("Qual posicao deseja editar?");
                            scanf("%d", &count.posEdit);
                            count.posEdit = count.posEdit - 1;
                        } while (count.posEdit > count.quantUsers || count.posEdit < 1);
                        editUser(&cadUser[count.posEdit], count);
                        break;
                    }
                    printf("Deseja excluir mais alguem? 0 - SIM  1 - NAO\n");
                    scanf("%d", &choices.choiceFinalEdit);
                }while(choices.choiceFinalEdit != 1);
                break;

            // case 4://Backup
            //     backupUser();
            //     break;

            case 5://printa usuarios
                for (i = 0; i != count.quantUsers; i++){
                    int j = i + 1;
                    printf("Posiçao: %d\n", j);
                    printUser(&cadUser[i]);
                }
                break;

            case 6://Encerrar sessao
                printf("Obrigado pelo tempo, até uma proxima vez");
                choices.final = 6;
                break;
            }
        } while (choices.choiceInic > 6 || choices.choiceInic < 1);
    } while (choices.final != 6);

    return 0;
}
//Fim da Main


//criação das Funções

void inicializarStruct(dadosUser *inCadUser, contadores *inCounts, choices *inChoices){
    inCadUser->ID = 0;
    inCadUser->idade = 0;
    inCadUser->altura = 0;
    
    inCounts->quantUsers = 0;
    inCounts->posCad = 0;
    inCounts->posSalva = 0;

    inChoices->choiceCad = 0;
    inChoices->final = 0;
    inChoices->choiceInic = 0;
    inChoices->choiceExc = 0;
    inChoices->choiceFinalExc = 0;
    inChoices->buscaExc = 0;
    inChoices->escID = 0;
}

void limpaTela(){
    printf("\33[H\33[2J");
}

void pegaID(dadosUser *cadUser, contadores *Counts){
    srand(time(NULL));
    cadUser->ID = (rand() % (999999 - 100000 + 100000) + 100000);
    // for (int i = 0; i < counts->posSalva; i++){
    //     if (cadUser->ID == cadUser[i]->ID){
    //         cadUser->ID = (rand() % (999999 - 100000 + 100000) + 100000);
    //         i = 0;
    //     }
    // }
}

void pegaNome(dadosUser *cadUser){
    do{
        printf("Qual o nome do usuário?\n");
        fflush(stdin);
        fgets(cadUser->nome, 100, stdin);
    } while (strlen(cadUser->nome) < 2);
}

void pegaIdade(dadosUser *cadUser){

}

void pegaSexo(dadosUser *cadUser){

}

void pegaAltura(dadosUser *cadUser){

}

void pegaEndereco(dadosUser *cadUser){

}

void pegaVacina(dadosUser *cadUser){

}

void pegaEmail(dadosUser *cadUser){

}

void buscaID(){
    i = 0;
    printf("Qual o ID do usuario? ");
    scanf("%d", &buscaID);
    do{
        if (cadUser[i].ID == buscaID){
        count.pos = i;
        i = count.quantUsers;
        return 0;
        }
    i++;
    } while (i != count.quantUsers);
}

void buscaEmail(){
    i = 0;
    printf("Qual o Email do usuario? ");
    fflush(stdin);
    fgets(buscaEmail, 100, stdin);
    do{
        if (strecmp(cadUser[i].email) == 0){
        count.pos = i;
        i = count.quantUsers;
        return 0;
        }
    i++;
    } while (i != count.quantUsers);
}
