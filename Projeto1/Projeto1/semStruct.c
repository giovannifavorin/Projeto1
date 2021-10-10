//Giovanni Favorin de Melo
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Declaração das funções
void cadastraUser(int criaId, char criaNome[100], char criaEmail[100], char criaSexo[10], char criaEndereco[100], double criaAltura, bool criaVacina, int criaIdade);
void pegaID(int criaId);
void pegaNome(char criaNome[][100]);
void pegaIdade(int criaIdade);
void pegaSexo(char criaSexo[10]);
void pegaAltura(double criaAltura);
void pegaEndereco(char criaEndereco[100]);
void pegaVacina(bool criaVacina);
void pegaEmail(char criaEmail[100]);
void printUser(int printId, char printNome[100], char printEmail[100], char printSexo[10], char printEndereco[100], double printAltura, bool printVacina, int printIdade);
void excludeUser(int excludeID, char excludeNome[100], char excludeEmail[100], char excludeSexo[10], char excludeEndereco[100], double excludeAltura, bool excludeVacina, int excludeIdade);
void editUser(int ID, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, bool vacina, int idade);
void menuBackup(int ID, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, bool vacina, int idade, int quantUser);
void backupUser(int backupOption, int ID, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, bool vacina, int idade);
int buscaID(int ID);
int buscaEmail(char email[100]);

int contUser;
//Término de declaração de variáveis

//Criação das funções
int main(){
    int ID[1000], escolhaMain, escolha2, escolhaEdit = 0, idade[1000], buscaID = 0, buscaEmail = 0, fim = 0, posUser = 0;
    char nome[1000][100], sexo[1000][10], endereco[1000][100], email[1000][100];
    double altura[1000];//Entre 1m a 2m
    bool vacinaUser[1000];
    int quantUser = 0;
    int escolhaCadast;

    do{
        do{
            printf("Bem vindo ao menu\nEscolha a opcao que deseja\n");
            printf("\nDigite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira excluir algum usuario\nDigite 3 - Caso queira procurar um usuario pelo ID\nDigite 4 - Caso queira editar os dados de algum usuario\nDigite 5 - Caso queira restaurar os usuarios\nDigite 6 - Caso queira encerrar a sessao\nDigite 7 - Caso queira buscar o usuario pelo Email");
            scanf("%d", &escolhaMain);
            switch (escolhaMain){
                case 1:
                    do{
                        cadastraUser(ID[quantUser], nome[quantUser], email[quantUser], sexo[quantUser], endereco[quantUser], altura[quantUser], vacinaUser[quantUser], idade[quantUser]);
                        quantUser++;
                        do{
                            printf("Deseja cadastrar mais alguem? 5-sim, 0-nao");
                            scanf("%d",&escolha2);
                        } while (escolha2 != 5 || escolha2 !=0);
                    } while (escolha2 != 0);
                    contUser = quantUser;
                    break;

                case 2:
                    excludeUser(ID[quantUser], nome[quantUser], email[quantUser], sexo[quantUser], endereco[quantUser], altura[quantUser], vacinaUser[quantUser], idade[quantUser]);
                    quantUser--;
                    contUser = quantUser;
                    break;

                case 3:
                    posUser = &buscaID(ID);
                    printf("A posicao do usuario: %d", posUser);
                    break;

                case 4:
                    printf("Para editar o usuario, sera necessario encontrar o mesmo, prefere encontrar ele atraves de ID-1 ou Email-2?");
                    scanf("%d", &escolhaEdit);
                    do{
                        if (escolhaEdit == 1)
                            posUser = &buscaID(ID);
                    
                        else if (escolhaEdit == 2)
                            posUser = &buscaEmail(email);
                    } while (escolhaEdit != 1 || escolhaEdit != 2);
                    
                    editUser(ID[posUser], nome[posUser], email[posUser], sexo[posUser], endereco[posUser], altura[posUser], vacinaUser[posUser], idade[posUser]);
                    break;

                case 5:
                    menuBackup(ID[], nome[], email[], sexo[], endereco[], altura[], vacinaUser[], idade[], quantUser[]);
                    break;

                case 6:
                    fim = 5;
                    break;

                case 7:
                    posUser = &buscaEmail(email);
                    printf("A posicao do usuario: %d", posUser);
                    break;

                default:
                    printf("Opcao invalida\nTente novamente");
                    break;
            }

            printf("Opcao invalida");
            system("pause");
            printf("\33[H\33[2J");
        } while (escolhaMain < 1 || escolhaMain > 7);
    } while(fim != 5);

        return 0;
}

void menuBackup(int id, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, bool vacina, int idade, int quantUser){
    int backupOption;

    do{
        do{
            printf("\33[H\33[2J");
            printf("1-Criar Backup\n");
            printf("2-recuperar Backup\n");
            printf("3-Voltar\n");
            printf("Digite um opcao: ");
            scanf("%d", &backupOption);
        } while (backupOption < 1 || backupOption > 3);

        switch (backupOption)
        {
        case 1:
            printf("backup realizado com sucesso!!!\n");
            system("pause");
            backupUser(backupOption, id, nome, email, sexo, endereco, altura, vacina, idade);
            break;
        
        case 2:
            printf("backup restaurado com sucesso!!!\n");
            system("pause");
            backupUser(backupOption, id, nome, email, sexo, endereco, altura, vacina, idade);
            break;

        case 3:
            printf("Voce irá retornar ao menu agora");
            return;
            break;

        default:
            printf("\33[H\33[2J");
            printf("Opcao invalida!! digite novamente");
            system("pause");
            break;
        }
    } while (backupOption != 3);
}

void cadastraUser(int criaId,char criaNome[100], char criaEmail[100], char criaSexo[10], char criaEndereco[100], double criaAltura, bool criaVacina, int criaIdade){//Cadastrar o usuário 
        printf("\33[H\33[2J"); 
        printf("Cadastro de usuario"); 

        pegaNome(criaNome[]);
        pegaEmail(criaEmail);
        pegaIdade(criaIdade);
        pegaAltura(criaAltura);
        pegaSexo(criaSexo);
        pegaVacina(criaVacina);
        pegaEndereco(criaEndereco);
        pegaID(criaId);

        printUser(criaId, criaNome, criaEmail, criaSexo, criaEndereco, criaAltura, criaVacina, criaIdade);
        printf("\33[H\33[2J"); 
}

void pegaID(int criaID){//criar o ID randômicamente
    srand(time(NULL));
    criaID[contUser] = (rand() % (999999 - 100000 + 100000) + 100000);
    for (int i = 0; i < contUser; i++){
        if (criaID[contUser] == criaID[i]){
            criaID[contUser] = (rand() % (999999 - 100000 + 100000) + 100000);
            i = 0;
        }
    }
}

void pegaNome(char criaNome[][100]){
    do{
        printf("Qual o nome do usuário?");
        fflush(stdin);
        fgets(criaNome[], 100, stdin);
    } while (strlen(criaNome[] < 2));
}

void pegaIdade(int criaIdade){
    do{
        printf("Qual a idade do usuário?");
        scanf("%d", &criaIdade[contUser]);
    } while (criaIdade[contUser] > 0 && criaIdade[contUser] < 100);
}

void pegaSexo(char criaSexo[10]){
    int i = 1;
    do{
        printf("Qual o sexo do usuário? Homem, Mulher ou NDA");
        fflush(stdin);
        fgets(criaSexo, 10, stdin);

        if (stricmp(criaSexo, "NDA\n") == 0 || stricmp(criaSexo, "Mulher\n") == 0 || stricmp(criaSexo, "Homem\n") == 0){
            i = 0;
        }
    } while (i == 1);
}

void pegaAltura(double criaAltura){
    do{
        printf("Qual a altura do usuario?");
        scanf("%lf", criaAltura);
    } while (criaAltura < 1 || criaAltura > 2);
}

void pegaEndereco(char criaEndereco[100]){
    do{
        printf("Qual o endereco do usuário?");
        fflush(stdin);
        fgets(criaEndereco, 100, stdin);
    } while (strlen(criaEndereco < 2));
}

void pegaVacina(bool criaVacina){
    char pergVacina[10];
    int i = 0;

    do
    {
        printf("Usuario vacinado? sim ou nao");
        fflush(stdin);
        fgets(criaVacina, 10, stdin);

        if (stricmp(pergVacina, "sim\n" == 0)){
            criaVacina = true;
            i = 1;
        }
        else if(stricmp(pergVacina, "nao\n" == 0)){
            criaVacina = false;
            i = 1;
        }
    } while (i != 1);
}

void pegaEmail(char criaEmail[100]){
    do
    {
        printf("Qual o email do usuario?");
        fflush(stdin);
        fgets(criaEmail, 100, stdin);
    } while (strchr(criaEmail, '@') == NULL);
}

void excludeUser(int excludeID[1000], char excludeNome[100], char excludeEmail[100], char excludeSexo[10], char excludeEndereco[100], double excludeAltura, bool excludeVacina, int excludeIdade){//Excluir os dados do usuário
    int escolha = 0, posUser = 0, option = 0;
    int j;

    j = contUser;

    do{
        do{
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida: ");
            scanf("%d", &escolha);
        } while (escolha > 3 || escolha < 1);
        switch (escolha) {
            case 1 :
                posUser = buscaID(excludeID);
                break;
            case 2 :
                posUser = buscaEmail(excludeEmail);
                break;
            case 3 :
                return;
                break;
        }

        for (int j = 1; j != contUser; j++){
            for (posUser = 0; posUser != j; posUser++){
                excludeID[posUser] = excludeID[j];
                excludeAltura[posUser] = excludeAltura[j];
                excludeVacina[posUser] = excludeVacina[j];
                strcpy(&excludeNome[posUser], &excludeNome[j]);
                strcpy(&excludeEmail[posUser], &excludeEmail[j]);
                strcpy(&excludeSexo[posUser], &excludeSexo[j]);
                strcpy(&excludeEndereco[posUser], &excludeEndereco[j]);
            }
        }

        do{
            printf("\33[H\33[2J"); 
            printf("deseja excluir outro usuario(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}

void editUser(int editID, int editNome, char editEmail[100], char editSexo[100], char editEndereco[100], double editAltura, bool editVacina, int editIdade){
    int option1, option2, optionFinal, posFinal;

    do{
        printf("\33[H\33[2J");

        printf("_________________Editar___________________\n");

        do{
            printf("Buscar usuario:\n");
            printf("1-Por ID\n");
            printf("2-Por Email\n");
            printf("3-Voltar\n");
            printf("Digite uma opcao valida:");
            scanf("%d", &option1);
        } while (option1 < 1 || option1 > 3);

        switch (option1)
        {
        case 1:
            posFinal = buscaID(editID);
            break;

        case 2:
            posFinal = buscaEmail(editEmail);
            break;
        
        default:
            return;
            break;
        }

        do{
            printf("\33[H\33[2J");
            printf("1-Nome\n");
            printf("2-Email\n");
            printf("3-Sexo\n");
            printf("4-Endereco\n");
            printf("5-Altura\n");
            printf("6-Vacina\n");
            printf("7-Idade\n");
            printf("8-Volta\n");
            printf("Digite a opcao que deseja alterar:");
            scanf("%d", &option2);

        } while (option2 < 1 || option2 > 8);

        switch (option2)
        {
        case 1:
            pegaNome(&editNome[posFinal][100]);
            break;

        case 2:
            pegaEmail(&editEmail[posFinal][100]);
            break;
        
        case 3:
            pegaSexo(&editSexo[posFinal][10]);
            break;
        
        case 4:
            pegaEndereco(&editEndereco[posFinal][100]);
            break;

        case 5:
            pegaAltura(&editAltura[posFinal]);
            break;

        case 6:
            pegaVacina(&editVacina[posFinal]);
            break;

        case 7:
            pegaIdade(&editIdade[posFinal]);
            break;

        default:
            return;
            break;
        }

        printUser(&editID[posFinal], editNome[posFinal][100], &editEmail[posFinal], &editSexo[posFinal][10], &editEndereco[posFinal][100], &editAltura[posFinal], &editVacina[posFinal], &editIdade[posFinal]);

        do{
            printf("\33[H\33[2J");
            printf("Deseja editar outro usuario? 1-sim   2-nao");
            scanf("%d", &optionFinal);
        } while (optionFinal < 1 || optionFinal > 2);
    } while (optionFinal == 1);
}

void printUser(int printId, char printNome[100], char printEmail[100], char printSexo[10], char printEndereco[100], double printAltura, bool printVacina, int printIdade){//Printar na tela limpa os dados do usuário

    printf("\33[H\33[2J");
    printf("_______________________________________________\n");
    printf("O ID do usuario: %d\n", *printId);
    printf("O nome do usuario: %s\n", *printNome);
    printf("O email do usuario: %s\n", *printEmail);
    printf("O sexo do usuario: %s\n", *printSexo);
    printf("O endereco do usuario: %s\n", *printEndereco);
    printf("O altura do usuario: %lf\n", *printAltura);

    if (printVacina == true){
        printf("O usuario tomou a vacina\n");
    }

    else{
        printf("O usuario nao tomou a vacina\n");
    }

    printf("\n__________________________________________________\n");
    system("pause");
}

void backupUser(int backupOption, int ID, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, bool vacina, int idade){//Salvar os dados do usuário num backup
    int backId[1000], backIdade[1000], backcontUser;
    bool backVacina[1000];
    double backAltura[1000];
    char backNome[1000][100], backEmail[1000][100], backSexo[1000][100], backEndereco[1000][100];

    if (backupOption == 1){
        for (int i = 0; i < contUser; i++){
            backId[i] = id[i];
            strcpy(backNome[i], nome[i]);
            strcpy(backEmail[i], email[i]);
            strcpy(backSexo[i], sexo[i]);
            strcpy(backEndereco[i], endereco[i]);
            backAltura[i] = altura[i];
            backVacina[i] = vacina[i];
        }
        backcontUser = contUser;
    }
    else if (backupOption == 2){
        for (int i = 0; i < contUser; i++){
            id[i] = backId[i];
            strcpy(nome[i], backNome[i]);
            strcpy(email[i], backEmail[i]);
            strcpy(sexo[i], backSexo[i]);
            strcpy(endereco[i], backEndereco[i]);
            altura[i] = backAltura[i];
            vacina[i] = backVacina[i];
        }
        contUser = backcontUser;
    }
}

int buscaID(int ID){
    int escolhaID;
    int escolha = 0;

    do{
        printf("Qual o ID do usuario? ");
        scanf("%d", &escolhaID);

        for (int i = 0; i < contUser; i++){
            if (ID[i] == escolhaID){
                return i;//Retorna a posicao na int main
            }
        }

        do{
            printf("ID invalido!");
            printf("Tentar novamente? 1-sim 2-nao:");
            scanf("%d", &escolha);
        } while (escolha < 1 || escolha > 2);
    } while (escolha == 1);
}

int buscaEmail(char email[100]){
    int escolha;
    char escolhaEmail[100];

    do{
        printf("Digite o email do usuario: ");
        fflush(stdin);
        fgets(escolhaEmail, 100, stdin);

        for (int i = 0; i < contUser; i++){
            if (stricmp(escolhaEmail, email[i]) == 0){
                return i;//Retorna na int main
            }
        }

        do{
            printf("email invalido!");
            printf("Deseja tenta novamente(1-sim 2-nao):");
            scanf("%d", &escolha);
        } while (escolha < 1 || escolha > 2);
    } while (escolha == 1);
}
//Término das criações das funções


