//calculadora simples utilizando pilha
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
double value;
struct Node *next;
}node;

node *head = NULL;

void push(double value){
if(head == NULL){
    head = (node *) malloc(sizeof(node));
    head->value = value;
    head->next = NULL;
    }
else{
    node *new_node = (node *) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = head;
    head = new_node;
    }
}

double pop(){
double tmp;
if(head != NULL){
    tmp = head->value;
    node *old_head = head;
    head = head->next;
    free(old_head);
}
    return tmp;
}

void peek(){
   double tmp;
   if(head != NULL){ 
   tmp = head->value;
   printf("\n\t\t%.2f\n", tmp);
   }
    else{
    printf("\n\t\t%.2f\n", tmp);
    }
}

void calc(){
int opc = 0;
double n;

    while(opc != 6){
        peek();
        printf("\n  1- Somar");
        printf("\n  2- Subtrair");
        printf("\n  3- Multiplicar");
        printf("\n  4- Dividir");
        printf("\n  5- Limpar");
        printf("\n  6- Sair\n\n");
        printf("  ");
        scanf("%d", &opc);
    
        switch(opc){
            case 1:
            {
                printf("  ");
                scanf("%lf", &n);
                if(head == NULL){
                    head = (node *) malloc(sizeof(node));
                    head->value = n;
                    head->next = NULL;
                }
                else{
                    push(pop() + n);
                }
            break;            
            }
            
            case 2:
            {
                printf("  ");
                scanf("%lf", &n);
                if(head == NULL){
                    head = (node *) malloc(sizeof(node));
                    head->value = n;
                    head->next = NULL;
                }
                else{
                    push(pop() - n);
                }
            break;            
           }

            case 3:
            {
                printf("  ");
                scanf("%lf", &n);
                if(head == NULL){
                    head = (node *) malloc(sizeof(node));
                    head->value = n;
                    head->next = NULL;
                }
                else{                 
                    push(pop() * n);
                }
            break;            
           }

            case 4:
            {
                printf("  ");
                scanf("%lf", &n);
                if(n == 0){
                    printf("\n  Valor invalido!\n");
                break;
                }

                if(head == NULL){
                    head = (node *) malloc(sizeof(node));
                    head->value = n;
                    head->next = NULL;
                }
                else{                 
                    push(pop() / n);
                }
            break;            
           }

            case 5:
            {
                if(head != NULL){
                    pop();
                }
            break;
            }
            
            case 6:
            {
                if(head != NULL){
                    pop();
                }
            break;
            }
        }
    }
}

int main(int argc, char **argv){

calc();

return 0;
}
