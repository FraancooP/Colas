/*Crear un programa con el siguiente menu de opciones: 
Agregar un nodo a la cola.
Borrar el primer nodo de la cola.
Imprimir cola.
Cantidad de nodos en la cola.
Cantidades de letras mayusculas y minusculas en la cola.
El usuario cargará la cola con letras mayusculas o minusculas. 
Nota: Las letras en ASCII mayusculas estan entre el 65 a 90 y las minusculas entre  97 a 122 inclusive.*/
#include <iostream>
#include <ctime>
using namespace std;
struct node
{
    char data;
    struct node *link;
};
void push(struct node **,struct node **, char);
int main(int argc, char *argv[]){
    char op=' ',cass=' ',letras=' ';
    int mayusculas=0, minusculas=0;
    srand(time(NULL));
    struct node *front = NULL;
	struct node *back = NULL;
    do{
        printf("Selecciona una opcion.\n");
        printf("A)Cargar un nodo\n");
        printf("B)Borrar primer nodo.\n");
        printf("C)Imprimir la cola.\n");
        printf("D)Cantidad de nodos en la cola.\n");
        printf("E)Cantidad de mayusculas y minusculas.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
        printf("Ingrese letras[. para terminar]\n");
        do{
				scanf(" %c", &letras);
				if(letras!='.' && ((letras>=65 && letras<=90)||(letras>=97 && letras<=122))){
					push(&front, &back, letras);
				}else{
					if(letras=='.')
						printf("Fin de la carga.\n");
					else
						printf("No es una letra, ingrese otra:\n");
				}
			}while(letras!='.');
            break;
        case 'b':
        case 'B':
            break;
        case 'c':
        case 'C':
            break;
        case 'd':
        case 'D':
            break;
        case 'e':
        case 'E':
            break;
        default:
            break;
        }
        
    } while (op=='s');
    
    return 0;
}
void push(struct node **front, struct node **back, char c){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->data=c;
	temp->link=NULL;
	if(*back==NULL){ //Insercion del primer nodo
		*back=temp;
		*front=*back;
	}else{ //Insercion del resto de los nodos
		(*back)->link =temp;
		*back=temp;
	}
}