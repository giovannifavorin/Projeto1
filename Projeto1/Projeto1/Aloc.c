#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Address {
    char quadra[50];
    char bairro[50];
    char casa[50];
    char cep[50];
} Address;
typedef struct User {
    int id;
    char nome[50];
    int idade;
    char sexo;
    char email[50];
    char altura[50];
    int vacina;
    Address Address;
} User;
struct node {
    User data;
    struct node *next;
};
/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */
void limpaTela() {
    system("clear");
}
void pausaTela() {
    printf("\n\nPressione ENTER para continuar...");
    getchar();
}
/* -------------------------------------------------------------------------- */
/*                                    LISTA                                   */
/* -------------------------------------------------------------------------- */
int inserirFinal(struct node **list, User data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*list == NULL) {
        *list = newNode;
    } else {
        struct node *last = *list;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    return 1;
}
/* -------------------------------------------------------------------------- */
/*                                  IMPRIMIR                                  */
/* -------------------------------------------------------------------------- */
void imprimir(struct node **inicial) {
    struct node *current = *inicial;
    while (current != NULL) {
        printf("==========================================================\n");
        printf("ID: %d\n", current->data.id);
        printf("Nome: %s\n", current->data.nome);
        printf("Idade: %d\n", current->data.idade);
        printf("Sexo: %c\n", current->data.sexo);
        printf("Email: %s\n", current->data.email);
        printf("Altura: %s\n", current->data.altura);
        if (current->data.vacina == 1) {
            printf("Vacina: Sim\n");
        } else {
            printf("Vacina: N??o\n");
        }
        printf("Quadra: %s\n", current->data.Address.quadra);
        printf("Bairro: %s\n", current->data.Address.bairro);
        printf("Casa: %s\n", current->data.Address.casa);
        printf("CEP: %s\n", current->data.Address.cep);
        printf("==========================================================\n");
        current = current->next;
    }
}
/* -------------------------------------------------------------------------- */
/*                                    MENU                                    */
/* -------------------------------------------------------------------------- */
int menu() {
    printf("Escolha uma das op????es:\n");
    printf("1 - Inserir novo usu??rio\n");
    printf("2 - Remover usu??rio\n");
    printf("3 - Alterar usu??rio\n");
    printf("4 - Imprimir usu??rios\n");
    printf("5 - Salvar usu??rios\n");
    printf("6 - Recarregar usu??rios\n");
    printf("7 - Remover Backup\n");
    printf("8 - Sair\n");
    int option;
    scanf("%d", &option);
    return option;
}
/* -------------------------------------------------------------------------- */
/*                            ADICIONAR NOVO USUARIO                          */
/* -------------------------------------------------------------------------- */
int generateId() {
    int id = rand() % 10000;
    return id;
}
User generateUser() {
    User user;
    user.id = generateId();
    printf("Digite o nome do usu??rio: ");
    scanf("%s", user.nome);
    printf("Digite a idade do usu??rio: ");
    scanf("%d", &user.idade);
    printf("Selecione o seu sexo: \n");
    printf("M - Masculino\n");
    printf("F - Feminino\n");
    printf("O - Outro\n");
    scanf(" %c", &user.sexo);
    printf("Digite o email do usu??rio: ");
    scanf("%s", user.email);
    printf("Digite a altura do usu??rio: ");
    scanf("%s", user.altura);
    printf("Digite o cep do usu??rio: ");
    scanf("%s", user.Address.cep);
    printf("Digite a quadra do usu??rio: ");
    scanf("%s", user.Address.quadra);
    printf("Digite o bairro do usu??rio: ");
    scanf("%s", user.Address.bairro);
    printf("Digite a casa do usu??rio: ");
    scanf("%s", user.Address.casa);
    printf("O usu??rio ?? vacinado? (1 - Sim / 0 - N??o): ");
    scanf("%d", &user.vacina);
    return user;
}
void adicionarUsuario(struct node **lista) {
    User user = generateUser();
    int resultado = inserirFinal(lista, user);
    limpaTela();
    if (resultado == 1) {
        printf("\n");
        printf("Usu??rio adicionado com sucesso!\n");
    } else {
        printf("\n");
        printf("Erro ao adicionar usu??rio!\n");
    }
}
/* -------------------------------------------------------------------------- */
/*                               REMOVER USUARIO                              */
/* -------------------------------------------------------------------------- */
void removerUsuarioPorEmail(struct node **lista) {
    char email[50];
    printf("Digite o email do usu??rio que deseja remover: ");
    scanf("%s", email);
    struct node *current = *lista;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.email, email) == 0) {
            if (previous == NULL) {
                *lista = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Usu??rio removido com sucesso!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Usu??rio n??o encontrado!\n");
}
void removerUsuarioPorId(struct node **lista) {
    int id;
    printf("Digite o ID do usu??rio que deseja remover: ");
    scanf("%d", &id);
    struct node *current = *lista;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data.id == id) {
            if (previous == NULL) {
                *lista = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Usu??rio removido com sucesso!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Usu??rio n??o encontrado!\n");
}
void removerUsuario(struct node **lista) {
    int opcao;
    printf("Como gostaria de remover um usu??rio?\n");
    printf("1 - Remover pelo ID\n");
    printf("2 - Remover pelo email\n");
    printf("Pressione qualquer outra tecla para voltar ao menu principal\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            removerUsuarioPorId(lista);
            break;
        case 2:
            removerUsuarioPorEmail(lista);
        default:
            break;
    }
    pausaTela();
}
/* -------------------------------------------------------------------------- */
/*                               ALTERAR USUARIO                              */
/* -------------------------------------------------------------------------- */
void alterarUsuarioPorEmail(struct node **lista) {
    char email[50];
    printf("Digite o email do usu??rio que deseja alterar: ");
    scanf("%s", email);
    struct node *current = *lista;
    while (current != NULL) {
        if (strcmp(current->data.email, email) == 0) {
            printf("Digite o novo nome do usu??rio: ");
            scanf("%s", current->data.nome);
            printf("Digite a nova idade do usu??rio: ");
            scanf("%d", &current->data.idade);
            printf("Selecione o sexo do usu??rio: \n");
            printf("M - Masculino\n");
            printf("F - Feminino\n");
            printf("O - Outro\n");
            scanf(" %c", &current->data.sexo);
            printf("Digite o novo email do usu??rio: ");
            scanf("%s", current->data.email);
            printf("Digite a nova altura do usu??rio: ");
            scanf("%s", current->data.altura);
            printf("Digite o novo cep do usu??rio: ");
            scanf("%s", current->data.Address.cep);
            printf("Digite a nova quadra do usu??rio: ");
            scanf("%s", current->data.Address.quadra);
            printf("Digite o novo bairro do usu??rio: ");
            scanf("%s", current->data.Address.bairro);
            printf("Digite a nova casa do usu??rio: ");
            scanf("%s", current->data.Address.casa);
            printf("O usu??rio ?? vacinado? (1 - Sim / 0 - N??o): ");
            scanf("%d", &current->data.vacina);
            printf("Usu??rio alterado com sucesso!\n");
            return;
        }
        current = current->next;
    }
    printf("Usu??rio n??o encontrado!\n");
}
void alterarUsuarioPorId(struct node **lista) {
    int id;
    printf("Digite o ID do usu??rio que deseja alterar: ");
    scanf("%d", &id);
    struct node *current = *lista;
    while (current != NULL) {
        if (current->data.id == id) {
            printf("Digite o novo nome do usu??rio: ");
            scanf("%s", current->data.nome);
            printf("Digite a nova idade do usu??rio: ");
            scanf("%d", &current->data.idade);
            printf("Selecione o sexo do usu??rio: \n");
            printf("M - Masculino\n");
            printf("F - Feminino\n");
            printf("O - Outro\n");
            scanf(" %c", &current->data.sexo);
            printf("Digite o novo email do usu??rio: ");
            scanf("%s", current->data.email);
            printf("Digite a nova altura do usu??rio: ");
            scanf("%s", current->data.altura);
            printf("Digite o novo cep do usu??rio: ");
            scanf("%s", current->data.Address.cep);
            printf("Digite a nova quadra do usu??rio: ");
            scanf("%s", current->data.Address.quadra);
            printf("Digite o novo bairro do usu??rio: ");
            scanf("%s", current->data.Address.bairro);
            printf("Digite a nova casa do usu??rio: ");
            scanf("%s", current->data.Address.casa);
            printf("O usu??rio ?? vacinado? (1 - Sim / 0 - N??o): ");
            scanf("%d", &current->data.vacina);
            printf("Usu??rio alterado com sucesso!\n");
            return;
        }
        current = current->next;
    }
    printf("Usu??rio n??o encontrado!\n");
}
void alterarUsuario(struct node **lista) {
    int opcao;
    printf("Como gostaria de alterar um usu??rio?\n");
    printf("1 - Alterar pelo ID\n");
    printf("2 - Alterar pelo email\n");
    printf("Pressione qualquer outra tecla para voltar ao menu principal\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            alterarUsuarioPorId(lista);
            break;
        case 2:
            alterarUsuarioPorEmail(lista);
        default:
            break;
    }
    pausaTela();
}
/* -------------------------------------------------------------------------- */
/*                               SALVA USUARIOS                               */
/* -------------------------------------------------------------------------- */
void salvarUsuarios(struct node *lista) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    struct node *current = lista;
    while (current != NULL) {
        fprintf(arquivo, "%d %s %d %c %s %s %s %s %s %s %d\n", current->data.id, current->data.nome, current->data.idade, current->data.sexo, current->data.email, current->data.altura, current->data.Address.cep, current->data.Address.quadra, current->data.Address.bairro, current->data.Address.casa, current->data.vacina);
        current = current->next;
    }
    fclose(arquivo);
}
/* -------------------------------------------------------------------------- */
/*                              CARREGA USUARIOS                              */
/* -------------------------------------------------------------------------- */
void carregarUsuarios(struct node **lista) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    struct node *current = *lista;
    while (current != NULL) {
        current = current->next;
    }
    while (!feof(arquivo)) {
        User usuario;
        fscanf(arquivo, "%d %s %d %c %s %s %s %s %s %s %d\n", &usuario.id, usuario.nome, &usuario.idade, &usuario.sexo, usuario.email, usuario.altura, usuario.Address.cep, usuario.Address.quadra, usuario.Address.bairro, usuario.Address.casa, &usuario.vacina);
        inserirFinal(lista, usuario);
    }
    fclose(arquivo);
}
/* -------------------------------------------------------------------------- */
/*                                    MAIN                                    */
/* -------------------------------------------------------------------------- */
int main(void)
{
    struct node *inicial = NULL;
    limpaTela();
    while (1) {
        printf("\n");
        int option = menu();
        limpaTela();
        switch (option) {
            case 1:
                printf("Inserir novo usu??rio\n");
                adicionarUsuario(&inicial);
                break;
            case 2:
                printf("Remover usu??rio\n");
                removerUsuario(&inicial);
                break;
            case 3:
                printf("Alterar usu??rio\n");
                alterarUsuario(&inicial);
                break;
            case 4:
                printf("Imprimir usu??rios\n");
                imprimir(&inicial);
                pausaTela();
                break;
            case 5:
                printf("Salvar usu??rios\n");
                salvarUsuarios(inicial);
                break;
            case 6:
                printf("Recarregar usu??rios\n");
                carregarUsuarios(&inicial);
                break;
            case 7:
                printf("Remover backup\n");
                remove("usuarios.txt");
                break;
            case 8:
                printf("Tchau tchau o/ \n");
                return EXIT_SUCCESS;
            default:
                printf("Op????o inv??lida\n");
                break;
        }
    }
            
    return EXIT_SUCCESS;
}
