#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char nome[45];
  int idade;
  int active; /* 1 = ativo, 0 = deletado (soft-delete) */
} usuarios;

/* Insere usuário: reutiliza slots deletados quando possível */
void inserir_usuario(usuarios usuario[], int *contador) {
  system("cls");
  int reuse = -1;
  for (int i = 0; i < *contador; i++) {
    if (usuario[i].active == 0) { reuse = i; break; }
  }

  if (reuse == -1 && *contador >= 10) {
    printf("Limite de usuários atingido.\n");
    return;
  }

  int idx = (reuse != -1) ? reuse : *contador;
  printf("Insira o nome do usuário: \n");
  scanf("%44s", usuario[idx].nome);
  printf("Insira a idade do usuário: \n");
  scanf("%d", &usuario[idx].idade);
  usuario[idx].id = idx + 1;
  usuario[idx].active = 1;
  if (reuse == -1) (*contador)++;
  printf("Usuário inserido com sucesso!\n");
  printf("ID: %d\n", usuario[idx].id);
  printf("Nome: %s\n", usuario[idx].nome);
  printf("Idade: %d\n", usuario[idx].idade);
}

/* Lista apenas usuários ativos */
void listar_usuarios(usuarios usuario[], int contador) {
  system("cls");
  printf("Usuários:\n");
  for (int i = 0; i < contador; i++) {
    if (usuario[i].active) {
      printf("ID: %d\n", usuario[i].id);
      printf("Nome: %s\n", usuario[i].nome);
      printf("Idade: %d\n", usuario[i].idade);
      printf("---------------------------------------\n");
    }
  }
  printf("Fim da lista de usuários.\n");
}

/* Edita usuário se ativo */
void editar_usuario(usuarios usuario[], int contador) {
  system("cls");
  int aux;
  printf("Insira o ID do usuário que deseja editar: \n");
  scanf("%d", &aux);
  int encontrado_edit = 0;
  for (int i = 0; i < contador; i++) {
    if (usuario[i].id == aux && usuario[i].active) {
      printf("Nome: %s\n", usuario[i].nome);
      printf("Idade: %d\n", usuario[i].idade);
      printf("Insira o novo nome do usuário: \n");
      scanf("%44s", usuario[i].nome);
      printf("Insira a nova idade do usuário: \n");
      scanf("%d", &usuario[i].idade);
      printf("Usuário editado com sucesso!\n");
      encontrado_edit = 1;
      break;
    }
  }
  if (!encontrado_edit) {
    printf("Usuário com ID %d não encontrado.\n", aux);
  }
}

/* Soft-delete: marca active = 0 */
void excluir_usuario(usuarios usuario[], int contador) {
  system("cls");
  int aux;
  char resposta[2];
  printf("Insira o ID do usuário que deseja deletar: \n");
  scanf("%d", &aux);
  int encontrado_del = 0;
  for (int i = 0; i < contador; i++) {
    if (usuario[i].id == aux && usuario[i].active) {
      printf("Nome: %s\n", usuario[i].nome);
      printf("Idade: %d\n", usuario[i].idade);
      printf("Tem certeza que deseja deletar esse usuário? (s/n)\n");
      scanf(" %c", &resposta[0]);
      if (resposta[0] == 's' || resposta[0] == 'S') {
        usuario[i].active = 0;
        printf("Usuário deletado com sucesso!\n");
      } else {
        printf("Usuário não deletado.\n");
      }
      encontrado_del = 1;
      break;
    }
  }
  if (!encontrado_del) {
    printf("Usuário com ID %d não encontrado.\n", aux);
  }
}

int main() {

  usuarios usuario[10];
  int escolha, contador, aux;
  char resposta[2];
  contador = 0;
  escolha = 0;

  /* inicializa todos como inativos */
  for (int i = 0; i < 10; i++) {
    usuario[i].active = 0;
    usuario[i].id = 0;
    usuario[i].nome[0] = '\0';
    usuario[i].idade = 0;
  }

  while (escolha != 5) {
    printf("-----MENU-----\n");
    printf("[1] - Inserir usuários\n");
    printf("[2] - Listar usuários\n");
    printf("[3] - Editar usuário\n");
    printf("[4] - Excluir usuário\n");
    printf("[5] - Sair\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      inserir_usuario(usuario, &contador);
      break;

    case 2:
      listar_usuarios(usuario, contador);
      break;

    case 3:
      editar_usuario(usuario, contador);
      break;

    case 4:
      excluir_usuario(usuario, contador);
      break;

    case 5:
      system("cls");
      printf("Saindo...\n");
      break;

    default:
      printf("Opção inválida! Escolha 1-5.\n");
      break;
    }
  }
  return 0;
}
