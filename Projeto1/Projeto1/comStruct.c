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
    int quantUsers, posCad, posedit, posSalva, posExc, posEdit, pos, i;
} contadores;

typedef struct {
    int IDBusca;
    char emailBusca[100];
} complementares;

typedef struct {
    int choiceInic, final, choiceCad, choiceExc, choiceFinalExc, buscaExc, escID, choiceEdit, buscaEdit, choiceFinalEdit;
} choices;
//Fim de Structs

//print user e dar a oferta de editar ou excluir o user em base da pos

//Declaração das Funções 
void inicializarStruct(dadosUser *inCadUser, contadores *inCounts, choices *inChoices);//editar todas as var
void pegaID(dadosUser *CadUser, contadores *Counts);
void pegaNome(dadosUser *CadUser);
void pegaIdade(dadosUser *CadUser);
void pegaSexo(dadosUser *CadUser);
void pegaAltura(dadosUser *CadUser);
void pegaEndereco(dadosUser *CadUser);
void pegaVacina(dadosUser *CadUser);
void pegaEmail(dadosUser *CadUser);
void printUser(dadosUser *printUser);
// void backupUser();
void buscaID(dadosUser *User, contadores *Counts, complementares *comp);
void buscaEmail(dadosUser *User, contadores *Counts, complementares *comp);
void limpaTela();

//Fim das Funções

//Main
int main(){
    int quantTotal = 0, quantAtual = 0, i = 0;
    dadosUser cadUser[1000];
    contadores count;
    choices choices;
    complementares comp;

    for (int j = 0; j != 1000; j++){
        inicializarStruct(&cadUser[j], &count, &choices);
    }

    do{
        do{
            limpaTela();
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n");
            printf("\nDigite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira excluir algum usuario\nDigite 3 - Caso queira editar os dados de algum usuario\nDigite 4 - Caso queira abrir o menu de Backup\nDigite 5 - Caso queira ver a lista de todos os cadastros\nDigite 6 - Caso queira encerrar a sessao\n");
            scanf("%d", &choices.choiceInic);
            switch (choices.choiceInic){
            case 1://Cadastrar usuario
                limpaTela();
                printf("_________________Cadastro___________________\n");
                printf("Preencha os dados a seguir para concluir o cadastro\n");

                do{
                    pegaID(&cadUser[count.quantUsers], &count);
                    pegaNome(&cadUser[count.quantUsers]);
                    pegaIdade(&cadUser[count.quantUsers]);
                    pegaSexo(&cadUser[count.quantUsers]);
                    pegaAltura(&cadUser[count.quantUsers]);
                    pegaEndereco(&cadUser[count.quantUsers]);
                    pegaVacina(&cadUser[count.quantUsers]);
                    pegaEmail(&cadUser[count.quantUsers]);

                    printUser(&cadUser[count.quantUsers]);

                    count.quantUsers++;
                    i = count.quantUsers;
                    printf("A quantidade de cadastros em aberto: %d\nA quantidade de cadastros atuais: %d \n", 1000 - i, count.quantUsers);
                    do{
                        printf("Deseja cadastrar mais alguem? 1 - SIM  2 - NAO\n");
                        scanf("%d", &choices.choiceCad);
                    } while (choices.choiceCad < 1 && choices.choiceCad > 2);
                } while (choices.choiceCad != 2);
                break;

            case 2://Exclude usuario
                limpaTela();
                printf("_________________Excluir___________________\n");
                printf("Preencha os dados a seguir para excluir um usuario\n");

                do{
                    do{
                        printf("Sabe o ID ou email do usuario? 1-SIM 2-NAO\n");
                        scanf("%d", &choices.choiceExc);
                    } while(choices.choiceExc < 1 && choices.choiceExc > 2);

                    switch (choices.choiceExc){
                    case 1:
                        do{
                            printf("Deseja encontrar o usuario atraves do ID ou Email? 1-ID 2-EMAIL\n");
                            scanf("%d", &choices.buscaExc);
                        } while (choices.buscaExc < 1 && choices.buscaExc > 2);

                        switch (choices.buscaExc){
                        case 1:
                            for ( count.i = 0; i != count.quantUsers; count.i++)
                                buscaID(&cadUser[count.i], &count, &comp);

                            count.posExc = count.pos;
                            for (; count.posExc != count.quantUsers; count.posExc++){
                                for (int j = count.posExc + 1; j != count.quantUsers; j++){
                                    cadUser[count.posExc].ID = cadUser[j].ID;
                                    cadUser[count.posExc].altura = cadUser[j].altura;
                                    cadUser[count.posExc].vacina = cadUser[j].vacina;
                                    strcpy(cadUser[count.posExc].nome, cadUser[j].nome);
                                    strcpy(cadUser[count.posExc].email, cadUser[j].email);
                                    strcpy(cadUser[count.posExc].sexo, cadUser[j].sexo);
                                    strcpy(cadUser[count.posExc].endereco.bairro, cadUser[j].endereco.bairro);
                                }
                            }
                            count.quantUsers--;
                            break;

                        case 2:
                            for ( count.i = 0; i != count.quantUsers; count.i++)
                                buscaEmail(&cadUser[count.i], &count, &comp);
                            
                            count.posExc = count.pos;
                            for (; count.posExc != count.quantUsers; count.posExc++){
                                for (int j = count.posExc + 1; j != count.quantUsers; j++){
                                    cadUser[count.posExc].ID = cadUser[j].ID;
                                    cadUser[count.posExc].altura = cadUser[j].altura;
                                    cadUser[count.posExc].vacina = cadUser[j].vacina;
                                    strcpy(cadUser[count.posExc].nome, cadUser[j].nome);
                                    strcpy(cadUser[count.posExc].email, cadUser[j].email);
                                    strcpy(cadUser[count.posExc].sexo, cadUser[j].sexo);
                                    strcpy(cadUser[count.posExc].endereco.bairro, cadUser[j].endereco.bairro);
                                }
                            }
                            count.quantUsers--;
                            break;
                        }
                

                    case 2:
                        for (int i = 0; i != count.quantUsers; i++){
                            printf("A posicao: %d\n", i);
                            printUser(&cadUser[i]);
                        }

                        do{
                            printf("Qual destes deseja excluir?\n");
                            scanf("%d", &choices.buscaExc);
                        } while (choices.buscaExc < 0 || choices.buscaExc > count.quantUsers);

                        count.posExc = choices.buscaExc;

                        for (; count.posExc != count.quantUsers; count.posExc++){
                                for (int j = count.posExc + 1; j != count.quantUsers; j++){
                                    cadUser[count.posExc].ID = cadUser[j].ID;
                                    cadUser[count.posExc].altura = cadUser[j].altura;
                                    cadUser[count.posExc].vacina = cadUser[j].vacina;
                                    strcpy(cadUser[count.posExc].nome, cadUser[j].nome);
                                    strcpy(cadUser[count.posExc].email, cadUser[j].email);
                                    strcpy(cadUser[count.posExc].sexo, cadUser[j].sexo);
                                    strcpy(cadUser[count.posExc].endereco.bairro, cadUser[j].endereco.bairro);
                                }
                            }
                        count.quantUsers--;
                        break;
                    }
                    do{
                        printf("Deseja excluir mais algum usuario? 1-SIM 2-NAO\n");
                        scanf("%d", &choices.choiceFinalExc);
                    }while(choices.choiceFinalExc < 1 && choices.choiceFinalExc > 2);
                }while(choices.choiceFinalExc != 2);
                break;

            case 3://Editar usuario
                limpaTela();
                printf("_________________Editar___________________\n");
                printf("Preencha os dados a seguir para editar um usuario\n");

                do{
                    do{
                        printf("Sabe o ID ou email do usuario? 1-SIM 2-NAO\n");
                        scanf("%d", &choices.choiceEdit);
                    } while(choices.choiceEdit < 1 && choices.choiceEdit > 2);

                    switch (choices.choiceEdit){
                    case 1:
                        do{
                            printf("Deseja encontrar o usuario atraves do ID ou Email? 1-ID 2-EMAIL\n");
                            scanf("%d", &choices.buscaEdit);
                        } while (choices.buscaEdit < 1 && choices.buscaEdit > 2);
                        switch (choices.buscaEdit)
                        {
                        case 1:
                            for ( count.i = 0; i != count.quantUsers; count.i++)
                                buscaID(&cadUser[count.i], &count, &comp);

                            count.posEdit = count.pos;
                            pegaNome(&cadUser[count.posEdit]);
                            pegaIdade(&cadUser[count.posEdit]);
                            pegaSexo(&cadUser[count.posEdit]);
                            pegaAltura(&cadUser[count.posEdit]);
                            pegaEndereco(&cadUser[count.posEdit]);
                            pegaVacina(&cadUser[count.posEdit]);
                            pegaEmail(&cadUser[count.posEdit]);
                            break;
                        case 2:
                            for ( count.i = 0; i != count.quantUsers; count.i++)
                                buscaEmail(&cadUser[count.i], &count, &comp);

                            count.posEdit = count.pos;
                            pegaNome(&cadUser[count.posEdit]);
                            pegaIdade(&cadUser[count.posEdit]);
                            pegaSexo(&cadUser[count.posEdit]);
                            pegaAltura(&cadUser[count.posEdit]);
                            pegaEndereco(&cadUser[count.posEdit]);
                            pegaVacina(&cadUser[count.posEdit]);
                            pegaEmail(&cadUser[count.posEdit]);
                            break;
                        }
                        break;

                    case 2:
                        for (int i = 0; i != count.quantUsers; i++){
                            printf("A posicao: %d\n", i);
                            printUser(&cadUser[i]);
                        }
                        do{
                        printf("Qual destes deseja editar?\n");
                        scanf("%d", &choices.buscaEdit);
                        } while (choices.buscaEdit < 0 || choices.buscaEdit > count.quantUsers);
                        pegaNome(&cadUser[choices.buscaEdit]);
                        pegaIdade(&cadUser[choices.buscaEdit]);
                        pegaSexo(&cadUser[choices.buscaEdit]);
                        pegaAltura(&cadUser[choices.buscaEdit]);
                        pegaEndereco(&cadUser[choices.buscaEdit]);
                        pegaVacina(&cadUser[choices.buscaEdit]);
                        pegaEmail(&cadUser[choices.buscaEdit]);
                        break;
                    }
                    do{
                    printf("Deseja excluir mais algum usuario? 1-SIM 2-NAO\n");
                    scanf("%d", &choices.choiceFinalEdit);
                    }while(choices.choiceFinalEdit < 1 && choices.choiceFinalEdit > 2);
                } while (choices.choiceFinalEdit != 2);
                break;

            case 4://Backup
                limpaTela();
                printf("_________________Backup___________________\n");
                printf("Preencha os dados a seguir para fazer o backup dos usuarios\n");
                printf("O backup salvara todos os dados atuais, e quando necessario, ira substituir todos os presentes naquele momento\n");

                // for (int i = 0; i != count.quantUsers; i++){
                //     printf("A posicao: %d\n", i);
                //     printUser(&cadUser[i]);
                //     backupUser(&cadUser[i]);
                // }
                // printf("Backup feito desses usuarios\n");
                break;

            case 5://printa usuarios
                limpaTela();
                for (i = 0; i != count.quantUsers; i++){
                    int j = i + 1;
                    printf("Posiçao: %d\n", j);
                    printUser(&cadUser[i]);
                }
                break;

            case 6://Encerrar sessao
                limpaTela();
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
    int i = 0;
    srand(time(NULL));
    cadUser->ID = (rand() % (999999 - 100000 + 100000) + 100000);
    for (i = Counts->quantUsers - 1; i != Counts->quantUsers; i++){
        if (cadUser->ID == cadUser[i].ID){
            cadUser->ID = (rand() % (999999 - 100000 + 100000) + 100000);
            i = 0;
        }
    }
}

void pegaNome(dadosUser *cadUser){
    do{
        printf("Qual o nome do usuário?\n");
        fflush(stdin);
        fgets(cadUser->nome, 100, stdin);
    } while (strlen(cadUser->nome) < 2);
}

void pegaIdade(dadosUser *cadUser){
    do{
        printf("Qual a idade do usuário?\n");
        scanf("%d", &cadUser->idade);
    } while (cadUser->idade < 0 || cadUser->idade > 100);
}

void pegaSexo(dadosUser *cadUser){
    int i = 1;
    do{
        printf("Qual o sexo do usuário? Homem, Mulher ou NDA\n");
        fflush(stdin);
        fgets(cadUser->sexo, 10, stdin);

        if (strcmp(cadUser->sexo, "NDA\n") == 0 || strcmp(cadUser->sexo, "Mulher\n") == 0 || strcmp(cadUser->sexo, "Homem\n") == 0){
            i = 0;
        }
    } while (i == 1);
}

void pegaAltura(dadosUser *cadUser){
    do{
        printf("Qual a altura do usuario?\n");
        scanf("%lf", &cadUser->altura);
    } while (cadUser->altura < 1 || cadUser->altura > 2);
}

void pegaEndereco(dadosUser *cadUser){
    do{
        printf("Qual o bairro do usuário?\n");
        fflush(stdin);
        fgets(cadUser->endereco.bairro, 100, stdin);
    } while (strlen(cadUser->endereco.bairro) < 2);
    do{
        printf("Qual o numero da casa do usuário?\n");
        scanf("%d", &cadUser->endereco.casa);
    } while (cadUser->endereco.casa < 0);
    do{
        printf("Qual o CEP do usuário?\n");
        scanf("%d", &cadUser->endereco.CEP);
    } while (cadUser->endereco.CEP < 0);
    do{
        printf("Qual a quadra do usuário?\n");
        fflush(stdin);
        fgets(cadUser->endereco.Quadra, 100, stdin);
    } while (strlen(cadUser->endereco.Quadra) < 2);
}

void pegaVacina(dadosUser *cadUser){
    char pergVacina[10];
    int i = 0;

    do{
        printf("Usuario vacinado? sim ou nao\n");
        fflush(stdin);
        fgets(pergVacina, 10, stdin);

        if (strcmp(pergVacina, "sim\n") == 0){
            cadUser->vacina = true;
            i = 1;
        }
        else if(strcmp(pergVacina, "nao\n") == 0){
            cadUser->vacina = false;
            i = 1;
        }
    } while (i != 1);
}

void pegaEmail(dadosUser *cadUser){
    do{
        printf("Qual o email do usuario?\n");
        fflush(stdin);
        fgets(cadUser->email, 100, stdin);
    } while (strchr(cadUser->email, '@') == NULL);
}

void printUser(dadosUser *printUser){
    printf("ID: %d\n", printUser->ID);
    printf("Nome: %s\n", printUser->nome);
    printf("Sexo: %s\n", printUser->sexo);
    printf("Idade: %d\n", printUser->idade);
    printf("Altura: %.2lf\n", printUser->altura);
    printf("Bairro: %s\n", printUser->endereco.bairro);
    printf("Numero da casa: %d\n", printUser->endereco.casa);
    printf("CEP: %d\n", printUser->endereco.CEP);
    printf("Quadra: %s\n", printUser->endereco.Quadra);

    if (printUser->vacina == true){
        printf("O usuario tomou a vacina\n");
    }

    else{
        printf("O usuario nao tomou a vacina\n");
    }
}

// void backupUser(){
//     int backId[1000], backIdade[1000], backcontUser;
//     bool backVacina[1000];
//     double backAltura[1000];
//     char backNome[1000][100], backEmail[1000][100], backSexo[1000][100], backEndereco[1000][100];
// }

void buscaID(dadosUser *User, contadores *Counts, complementares *comp){
    if (comp->IDBusca == User->ID){
        Counts->pos = Counts->i;
    }
}

void buscaEmail(dadosUser *User, contadores *Counts, complementares *comp){
    if (strcmp(comp->emailBusca, User->email) == 0){
        Counts->pos = Counts->i;
    }
}
