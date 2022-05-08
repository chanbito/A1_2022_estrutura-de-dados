#include <stdio.h>
#include <stdlib.h>

struct matriz
{

  int linhas;
  int colunas;
  float *valor;
};

typedef struct matriz Matriz;

Matriz *cria(int m, int n)
{

  Matriz *mat = (Matriz *)malloc(sizeof(Matriz));

  mat->linhas = m;
  mat->colunas = n;
  mat->valor = (float *)malloc(m * n * sizeof(float));

  return mat;
}

void libera(Matriz *mat)
{
  free(mat->valor);
  free(mat);
}

int get_space_valor(Matriz *mat, int i, int j)
{
  return i * mat->colunas + j;
}

float acessa(Matriz *mat, int i, int j)
{
  return mat->valor[get_space_valor(mat, i, j)];
}

void atribui(Matriz *mat, int i, int j, float valor)
{
  mat->valor[get_space_valor(mat, i, j)] = valor;
}

int linhas(Matriz *mat)
{

  return mat->linhas;
}

int colunas(Matriz *mat)
{

  return mat->colunas;
}

void preencher_valor(Matriz *m1, int qtda_linhas, int qtda_colunas)
{
  int i, j;
  float valor;
  for (i = 0; i < qtda_linhas; i++)
  {
    for (j = 0; j < qtda_colunas; j++)
    {
      printf("\nDigite o valor da posicao (%d,%d): ", i, j);
      scanf("%f", &valor);
      atribui(m1, i, j, valor);
    }
  }
}

void printar_valores(Matriz *m1, int qtda_linhas, int qtda_colunas)
{
  int i, j;
  for (i = 0; i < qtda_linhas; i++)
  {
    for (j = 0; j < qtda_colunas; j++)
    {
      printf("Valor da posicao (%d,%d): %f \n", i, j, acessa(m1, i, j));
    }
  }
}

void finalizar()
{
  printf("\nObrigado pela atencao, ate a proxima!\n");
}

void printar_primos(Matriz *m1, int qtda_linhas, int qtda_colunas)
{
  int i, j;
  for (i = 0; i < qtda_linhas; i++)
  {
    for (j = 0; j < qtda_colunas; j++)
    {
      int teste_val = 0;
      int teste = acessa(m1, i, j);
      if (teste > 2)
      {
        if (teste % 2 == 0)
        {
          teste_val++;
        }
      }
      if (teste > 3)
      {
        if (teste % 3 == 0)
        {
          teste_val++;
        }
      }
      if (teste > 5)
      {
        if (teste % 5 == 0)
        {
          teste_val++;
        }
      }
      if (teste > 7)
      {
        if (teste % 7 == 0)
        {
          teste_val++;
        }
      }
      if (teste > 11)
      {
        if (teste % 11 == 0)
        {
          teste_val++;
        }
      }
      if (teste > 13)
      {
        if (teste % 13 == 0)
        {
          teste_val++;
        }
      }
      if (teste_val == 0)
      {
        printf("\nValor da posicao (%d,%d) e primo, sendo: %f \n", i, j, acessa(m1, i, j));
      }
    }
  }
}

int main()
{
  int executar;

  printf("Deseja criar um vetor? (1 = SIM, 0 = NAO): ");
  scanf("%d", &executar);

  Matriz *m1;

  if (executar == 1)
  {
    int qtda_linhas, qtda_colunas;

    printf("\nQuantidade de Linhas: ");
    scanf("%d", &qtda_linhas);
    printf("\nQuantidade de Colunas: ");
    scanf("%d", &qtda_colunas);

    m1 = cria(qtda_linhas, qtda_colunas);

    int continuar, opcao;
    continuar = 1;
    while (continuar == 1)
    {
      // vetor ja criado, agora fazer menu
      system("cls");
      printf("Digite o valor corespondente a acao que deseja tomar\n");
      printf("Para sair, digite 0:\n");
      printf("Para preencher os valores do vetor, digite 1:\n");
      printf("Para printar os valores do vetor, digite 2:\n");
      printf("Para saber o tamanho do vetor, digite 3:\n");
      printf("Para printar os valores primos, digite 4:\n");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 0:
        continuar = 0;
        break;
      case 1:
        preencher_valor(m1, qtda_linhas, qtda_colunas);
        break;
      case 2:
        printar_valores(m1, qtda_linhas, qtda_colunas);
        system("pause");
        break;
      case 3:
        printf("\nQuantidade de linhas %d", linhas(m1));
        printf("\nQuantidade de colunas %d \n", colunas(m1));
        system("pause");
        break;
      case 4:
        printar_primos(m1, qtda_linhas, qtda_colunas);
        system("pause");
        break;
      default:
        printf("\nNao compreendi, poderia repetir?\n");
        system("pause");
        break;
      }
    }
    libera(m1);
    finalizar();
  }
  else if (executar == 0)
  {
    finalizar();
  }
  else
  {
    printf("Por favor, seleciona uma opção valida!");
  }
}
