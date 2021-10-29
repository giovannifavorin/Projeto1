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
    int quantUsers, posCad, posedit, posSalva, posExc, posEdit, pos, i, backContUser;
} contadores;

typedef struct {
    int IDBusca, achou;
    char emailBusca[100];
} complementares;

typedef struct {
    int choiceInic, final, choiceCad, choiceExc, choiceFinalExc, buscaExc, escID, choiceEdit, buscaEdit, choiceFinalEdit, backIn, choiceFinalBack;
} choices;
//Fim de Structs

//print user e dar a oferta de editar ou excluir o user em base da pos

//Declaração das Funções 
void inicializarStruct(dadosUser *inCadUser, contadores *inCounts, choices *inChoices, complementares *inComp);//editar todas as var
void pegaID(dadosUser *CadUser, contadores *Counts);
void pegaNome(dadosUser *CadUser);
void pegaIdade(dadosUser *CadUser);
void pegaSexo(dadosUser *CadUser);
void pegaAltura(dadosUser *CadUser);
void pegaEndereco(dadosUser *CadUser);
void pegaVacina(dadosUser *CadUser);
void pegaEmail(dadosUser *CadUser);
void printUser(dadosUser *printUser);
void saveBack(dadosUser *saveBack, dadosUser *user, contadores *backCounts);
void fazBack(dadosUser *saveBack, dadosUser *user, contadores *backCounts);
void buscaID(dadosUser *User, contadores *Counts, complementares *comp);
void buscaEmail(dadosUser *User, contadores *Counts, complementares *comp);
void limpaTela();
void statusQuant(contadores *Counts);

//Fim das Funções

//Main
int main(){
    int i = 0;
    dadosUser cadUser[1000];
    dadosUser backupUser[1000];
    contadores count;
    choices choices;
    complementares comp;

    for (int j = 0; j != 1000; j++)
        inicializarStruct(&cadUser[j], &count, &choices, &comp);

    do{
        do{
            limpaTela();
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n\n");
            statusQuant(&count);
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

                    limpaTela();

                    printUser(&cadUser[count.quantUsers]);

                    count.quantUsers++;
                    statusQuant(&count);
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

                if (count.quantUsers > 0){
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
                                    printf("Qual o ID que deseja procurar?\n");
                                    scanf("%d", &comp.IDBusca);
                                    for ( count.i = 0; count.i != count.quantUsers; count.i++)
                                        buscaID(&cadUser[count.i], &count, &comp);
                                    
                                    if (comp.achou == 1){
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
                                        statusQuant(&count);
                                    } else {
                                        printf("Valor nao encontrado\nDigite um inteiro para seguir\n");
                                        scanf("%d", &i);
                                        i = 0;
                                    }
                                    break;

                                case 2:
                                    printf("Qual o email que deseja procurar?\n");
                                    fflush(stdin);
                                    fgets(comp.emailBusca, 100, stdin);

                                    for ( count.i = 0; count.i != count.quantUsers; count.i++)
                                        buscaEmail(&cadUser[count.i], &count, &comp);

                                    if (comp.achou == 1){
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
                                    statusQuant(&count);
                                    } else {
                                        printf("Valor nao encontrado\n");
                                        scanf("%d", &i);
                                        i = 0;
                                    }
                                    break;
                            }
                            break;

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
                            statusQuant(&count);
                            break;
                        }
                        do{
                            printf("Deseja excluir mais algum usuario? 1-SIM 2-NAO\n");
                            scanf("%d", &choices.choiceFinalExc);
                        }while(choices.choiceFinalExc < 1 && choices.choiceFinalExc > 2);
                    }while(choices.choiceFinalExc != 2);
                } else {
                    printf("Quantidade insuficiente de usuarios\nDigite um inteiro para seguir\n");
                    scanf("%d", &i);
                    i = 0;
                }
                break;

            case 3://Editar usuario
                limpaTela();
                printf("_________________Editar___________________\n");
                printf("Preencha os dados a seguir para editar um usuario\n");

                if (count.quantUsers > 0){
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
                            switch (choices.buscaEdit){
                            case 1:
                                printf("Qual o ID que deseja procurar?\n");
                                scanf("%d", &comp.IDBusca);

                                for (count.i = 0; count.i < count.quantUsers; count.i++)
                                    buscaID(&cadUser[count.i], &count, &comp);

                                if (comp.achou == 1){
                                    count.posEdit = count.pos;
                                    pegaNome(&cadUser[count.posEdit]);
                                    pegaIdade(&cadUser[count.posEdit]);
                                    pegaSexo(&cadUser[count.posEdit]);
                                    pegaAltura(&cadUser[count.posEdit]);
                                    pegaEndereco(&cadUser[count.posEdit]);
                                    pegaVacina(&cadUser[count.posEdit]);
                                    pegaEmail(&cadUser[count.posEdit]);

                                    printUser(&cadUser[choices.buscaEdit]);
                                } else {
                                    printf("Valor nao encontrado\nDigite um inteiro para seguir\n");
                                    scanf("%d", &i);
                                    i = 0;
                                }
                                break;
                            case 2:
                                printf("Qual o email que deseja procura\n");
                                fflush(stdin);
                                fgets(comp.emailBusca, 100, stdin);

                                for ( count.i = 0; count.i != count.quantUsers; count.i++)
                                    buscaEmail(&cadUser[count.i], &count, &comp);

                                if (comp.achou == 1){
                                    count.posEdit = count.pos;
                                    pegaNome(&cadUser[count.posEdit]);
                                    pegaIdade(&cadUser[count.posEdit]);
                                    pegaSexo(&cadUser[count.posEdit]);
                                    pegaAltura(&cadUser[count.posEdit]);
                                    pegaEndereco(&cadUser[count.posEdit]);
                                    pegaVacina(&cadUser[count.posEdit]);
                                    pegaEmail(&cadUser[count.posEdit]);

                                    printUser(&cadUser[choices.buscaEdit]);
                                } else {
                                    printf("Valor nao encontrado\nDigite um inteiro para seguir\n");
                                    scanf("%d", &i);
                                    i = 0;
                                }
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

                            printUser(&cadUser[choices.buscaEdit]);
                            break;
                        }
                        do{
                            printf("Deseja editar mais algum usuario? 1-SIM 2-NAO\n");
                            scanf("%d", &choices.choiceFinalEdit);
                        }while(choices.choiceFinalEdit < 1 && choices.choiceFinalEdit > 2);
                    } while (choices.choiceFinalEdit != 2);
                } else{
                    printf("Quantidade insuficiente de usuarios\nDigite um inteiro para seguir\n");
                    scanf("%d", &i);
                    i = 0;
                }
                break;

            case 4://Backup
                limpaTela();
                printf("_________________Backup___________________\n");
                printf("Preencha os dados a seguir para fazer o backup dos usuarios\n");
                printf("O backup salvara todos os dados atuais, e quando necessario, ira substituir todos os presentes naquele momento\n");

                do{
                    do{
                        printf("Digite 1 - Para salvar os usuarios atuais\nDigite 2 - Para recuperar os usuarios salvos\n");
                        scanf("%d", &choices.backIn);
                    } while(choices.backIn > 2 || choices.backIn < 1);

                    if (count.quantUsers > 0){
                        switch (choices.backIn){
                        case 1:
                            for ( count.i = 0; count.i < count.quantUsers; count.i++){
                                printUser(&cadUser[count.i]);
                                saveBack(&backupUser[count.i], &cadUser[count.i], &count);
                            }

                            printf("O backup foi salvo com sucesso\nDigite um inteiro para seguir\n");
                            scanf("%d", &i);
                            i = 0;
                            break;

                        case 2:
                            for ( count.i = 0; count.i < count.quantUsers; count.i++){
                                fazBack(&backupUser[count.i], &cadUser[count.i], &count);
                                printUser(&cadUser[count.i]);
                            }
                            printf("O backup foi realizado com sucesso\nDigite um inteiro para seguir\n");
                            scanf("%d", &i);
                            i = 0;
                            break;
                        }
                    } else{
                        printf("Quantia insuficiente de usuarios, faca pelo menos um cadastro\nDigite um inteiro para seguir\n");
                        scanf("%d", &i);
                        i = 0;
                    }
                    do{
                        printf("Deseja fazer algo a mais no backup? 1-SIM 2-NAO\n");
                        scanf("%d", &choices.choiceFinalBack);
                    }while(choices.choiceFinalBack < 1 && choices.choiceFinalBack > 2);
                } while (choices.choiceFinalBack != 2);
                break;

            case 5://printa usuarios
                limpaTela();
                printf("O total de users: %d\n", count.quantUsers);

                for (int i = 0; i < count.quantUsers; i++){
                    printf("A posicao: %d\n", i);
                    printUser(&cadUser[i]);
                }
                printf("Digite um inteiro para sair");
                scanf("%d", &i);
                i = 0;
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

void inicializarStruct(dadosUser *inCadUser, contadores *inCounts, choices *inChoices, complementares *inComp){
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

    inComp->achou = 0;
}

void limpaTela(){
    printf("\33[H\33[2J");
    system("cls");
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
        printf("Qual o bairro do usuario?\n");
        fflush(stdin);
        fgets(cadUser->endereco.bairro, 100, stdin);
    } while (strlen(cadUser->endereco.bairro) < 2);
    do{
        printf("Qual o numero da casa do usuario?\n");
        scanf("%d", &cadUser->endereco.casa);
    } while (cadUser->endereco.casa < 0);
    do{
        printf("Qual o CEP do usuario?\n");
        scanf("%d", &cadUser->endereco.CEP);
    } while (cadUser->endereco.CEP < 0);
    do{
        printf("Qual a quadra do usuario?\n");
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
    printf("____________________________________\n");
    printf("\nID: %d\n", printUser->ID);
    printf("Nome: %s", printUser->nome);
    printf("Sexo: %s", printUser->sexo);
    printf("Idade: %d\n", printUser->idade);
    printf("Altura: %.2lf\n", printUser->altura);
    printf("Bairro: %s", printUser->endereco.bairro);
    printf("Numero da casa: %d\n", printUser->endereco.casa);
    printf("CEP: %d\n", printUser->endereco.CEP);
    printf("Quadra: %s", printUser->endereco.Quadra);

    if (printUser->vacina == true){
        printf("O usuario tomou a vacina\n\n");
    }

    else{
        printf("O usuario nao tomou a vacina\n\n");
    }
    printf("____________________________________\n");
}

void saveBack(dadosUser *saveBack, dadosUser *user, contadores *backCounts){
    saveBack->ID = user->ID;
    saveBack->endereco.casa = user->endereco.casa;
    saveBack->endereco.CEP = user->endereco.CEP;
    saveBack->idade = user->idade;
    saveBack->altura = user->altura;
    saveBack->vacina = user->vacina;
    backCounts->backContUser = backCounts->quantUsers;
    strcpy(saveBack->nome, user->nome);
    strcpy(saveBack->email, user->email);
    strcpy(saveBack->sexo, user->sexo);
    strcpy(saveBack->endereco.bairro, user->endereco.bairro);
    strcpy(saveBack->endereco.Quadra, user->endereco.Quadra);
}

void fazBack(dadosUser *saveBack, dadosUser *user, contadores *backCounts){
    user->ID = saveBack->ID;
    user->endereco.casa = saveBack->endereco.casa;
    user->endereco.CEP = saveBack->endereco.CEP;
    user->idade = saveBack->idade;
    user->altura = saveBack->altura;
    user->vacina = saveBack->vacina;
    backCounts->quantUsers = backCounts->backContUser;
    strcpy(user->nome, saveBack->nome);
    strcpy(user->email, saveBack->email);
    strcpy(user->sexo, saveBack->sexo);
    strcpy(user->endereco.bairro, saveBack->endereco.bairro);
    strcpy(user->endereco.Quadra, saveBack->endereco.Quadra);
}

void buscaID(dadosUser *User, contadores *Counts, complementares *comp){
    if (comp->IDBusca == User->ID){
        Counts->pos = Counts->i;
        comp->achou = 1;
    }
}

void buscaEmail(dadosUser *User, contadores *Counts, complementares *comp){
    if (strcmp(comp->emailBusca, User->email) == 0){
        Counts->pos = Counts->i;
        comp->achou = 1;
    }
}

void statusQuant(contadores *Counts){
    int i;
    i = Counts->quantUsers;
    printf("A quantidade de cadastros em aberto: %d\nA quantidade de cadastros atuais: %d \n", 1000 - i, Counts->quantUsers);
}
