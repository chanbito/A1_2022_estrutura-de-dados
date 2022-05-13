#include <stdio.h>
#include <stdlib.h>

struct vetor
{

  int linhas;
  int *valor;
};

typedef struct vetor Vetor;

Vetor *cria(int m)
{

  Vetor * vet = (Vetor *)malloc(sizeof(Vetor));

  vet->linhas = m;
  vet->valor = (int *)malloc(m * sizeof(int));

  return vet;
}

void libera(Vetor *vet)
{
  free(vet->valor);
  free(vet);
}

int get_space_valor(Vetor *vet, int i)
{
  return i * vet->linhas;
}

int acessa(Vetor *vet, int i)
{
  return vet->valor[get_space_valor(vet, i)];
}

void atribui(Vetor *vet, int i, int valor)
{
  vet->valor[get_space_valor(vet, i)] = valor;
}

int linhas(Vetor *vet)
{
  return vet->linhas;
}

void preencher_valor(Vetor *vet, int qtda_linhas)
{
  int i;
  int valor;
  for (i = 0; i < qtda_linhas; i++)
  {
      printf("\nDigite o valor da posicao (%d): ", i);
      scanf("%d", &valor);
      atribui(vet, i, valor);
    
  }
}

void printar_valores(Vetor *vet, int qtda_linhas)
{
  int i;
  for (i = 0; i < qtda_linhas; i++)
  {
      printf("Valor da posicao (%d): %d \n", i, acessa(vet, i));
  }
}

void finalizar()
{
  printf("\nObrigado pela atencao, ate a proxima!\n");
}

void printar_primos(Vetor *vet, int qtda_linhas)
{
  /*
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
  */
  
  int i, count_resto;
  
  printf("\nPrimos não implementados!\n");
}

int main()
{
  int executar;

  printf("Deseja criar um vetor? (1 = SIM, 0 = NAO): ");
  scanf("%d", &executar);

  Vetor *v1;

  if (executar == 1)
  {
    int qtda_linhas;

    printf("\nQuantidade de posicoes: ");
    scanf("%d", &qtda_linhas);
    
    v1 = cria(qtda_linhas);

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
        preencher_valor(v1, qtda_linhas);
        break;
      case 2:
        printar_valores(v1, qtda_linhas);
        system("pause");
        break;
      case 3:
        printf("\nQuantidade de posicoes %d \n" , linhas(v1));
        system("pause");
        break;
      case 4:
        printar_primos(v1, qtda_linhas);
        system("pause");
        break;
      default:
        printf("\nNao compreendi, poderia repetir?\n");
        system("pause");
        break;
      }
    }
    libera(v1);
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
