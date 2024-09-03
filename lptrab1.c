#include <string.h>
#include <stdio.h>
int cont,stringFound,Successful;
char nome[50],x;
typedef struct{
   int cod,quant;
   char nome[50];
   float preco;
}Produto;
Produto prodlist[99];
void inserir () {
   if (cont >= 99){
      printf("Não é possível inserir mais produtos \n");
      return;
   }
   printf("Insira o codigo do produto: \n");
   scanf("%d", &prodlist[cont].cod);
   for (int i = 0; i < cont; i++){
      if (prodlist[cont].cod == prodlist[i].cod){
         printf("Codigo ja existente, tente novamente.\n");
         return;
      }
   }
   printf("Insira o nome do produto: \n");
   scanf("%s", &prodlist[cont].nome);
   printf("Insira o preco do produto: \n");
   scanf("%f", &prodlist[cont].preco);
   printf("Insira a quantidade do produto: \n");
   scanf("%d", &prodlist[cont].quant);
   printf("Produto inserido com sucesso!\n");
   cont++;
}
void listar () {
   for (int i = 0; i < cont; i++){
      printf ("\nNome: %s \n",prodlist[i].nome);
      printf ("Codigo: %d \n",prodlist[i].cod);
      printf ("Preco: %.2f \n",prodlist[i].preco);
      printf ("Quantidade: %d \n\n",prodlist[i].quant);
   }
}
void buscar (){
   printf("Insira o nome do produto que deseja buscar: \n");
   scanf("%s", &nome);
   for (int i = 0; i < cont; i++){
      stringFound = strcmp(nome, prodlist[i].nome);
      if (stringFound == 0){
         printf ("\nNome: %s \n",prodlist[i].nome);
         printf ("Codigo: %d \n",prodlist[i].cod);
         printf ("Preco: %.2f \n",prodlist[i].preco);
         printf ("Quantidade: %d \n\n",prodlist[i].quant);
         Successful = 1;
      }
   }
   if (Successful != 1){
      printf("Produto nao encontrado\n");
   }
}
void remover (){
   printf ("Insira o nome do produto que deseja remover: \n");
   scanf("%s", &nome);
   for (int i = 0; i <cont; i++){
      stringFound = strcmp(nome, prodlist[i].nome);
      if (stringFound == 0){
         for (int j = 0; j < 50; j++){
            prodlist[i].nome[j] = prodlist[cont-1].nome[j];
         }
      prodlist[i].cod = prodlist[cont-1].cod;
      prodlist[i].preco = prodlist[cont-1].preco;
      prodlist[i].quant = prodlist[cont-1].quant;
      Successful = 1;
      }
   }
   if (Successful != 1){
      printf("Produto nao encontrado.\n");
   }else {
      printf("Produto removido com sucesso!\n");
      cont--;
   }
   stringFound = 1;
   Successful = 0;
}
void main(){
   cont = 0;
   while (x != 53) {
      printf("\nBem vindo ao sistema de estoque!\n");
      printf("O que deseja fazer?\n");
      printf("1 - Inserir produto\n");
      printf("2 - Listar produtos\n");
      printf("3 - Buscar produto por nome\n");
      printf("4 - Excluir produto por nome\n");
      printf("5 - Sair\n");
      scanf(" %c", &x);
      getchar(); //melhorar isso aq
      if (x == 49) {
         inserir();
      }
      if (x == 50) {
         listar();
      }
      if (x == 51) {
         buscar();
      }
      if (x == 52) {
         remover();
      }
   }
}