#include <iostream>
#include <ctime>
#include <sysinfoapi.h>
using namespace std;


void Insercion (int lista[], int largo)
{
int i, j;
int aux;

long int ticks_for= 0;
long int ticks_while= 0;
long int acum_ticks_for= 0;
long int acum_ticks_while= 0;

ticks_for = GetTickCount();
cout <<"GetTickCount for: "<<ticks_for<<endl;

for (i = 1; i < largo; i++){
/* indice j explora la sublista a[i-1]..a[0] buscando la
posicion correcta del elemento destino, lo asigna a a[j] */
cout<< "In for"<<endl;
j = i;
aux = lista[i];
/* se localiza el punto de inserción explorando hacia abajo */

ticks_while = GetTickCount();
cout <<"GetTickCount while: "<<ticks_while<<endl;

while (j > 0 && aux < lista[j-1]) {
/* desplazar elementos hacia arriba para hacer espacio */
cout<< "In while"<<endl;
lista[j] = lista[j-1];
j--;
}
ticks_while = GetTickCount() - ticks_while;
acum_ticks_while = acum_ticks_while + ticks_while;
cout << "While took: " << ticks_while << " ticks" << endl;

lista[j] = aux;
}
ticks_for = GetTickCount() - ticks_for;
acum_ticks_for = acum_ticks_for + ticks_for;

	cout << "While took a total of " << acum_ticks_while << " ticks." << endl;
	cout << "For took a total of " << acum_ticks_for << " ticks" << endl;
	
}

void quicksort(double lista[], int primero, int ultimo)
{
int i, j, centro;
double pivote;
double temporal;
centro = (primero + ultimo)/2;
pivote = lista[centro];
i = primero;
j = ultimo;
do {
while (lista[i] < pivote) i++;
while (lista[j] > pivote) j--;
if (i <= j)
{

temporal = lista[i];
lista[i] = lista[j];
lista[j] = temporal; /* intercambia a[i] con a[j] */
i++;
j--;
}
}while (i <= j);
if (primero < j)
quicksort(lista, primero, j); /* mismo proceso con sublista izqda */
if (i < ultimo)
quicksort(lista, i, ultimo); /* mismo proceso con sublista drcha */
}


int main(){

    double lista []={6,9,3,4,6,1};
    int largo = sizeof(lista) / sizeof(lista[0]);
    quicksort(lista, 0, largo-1);
    /*cout << "\nLista ordenada: ";
    for (int i = 0; i < largo; i++){
	
    	cout << lista[i] << " ";
   	}*/
    int lista2 []={21,6,9,3,4,1,19,5,7,1,2};
    int largo2 = sizeof(lista2) / sizeof(lista2[0]);
    Insercion(lista2, largo2);
    cout << "\nLista ordenada: ";
    for (int i = 0; i < largo2; i++){
	
    	cout << lista2[i] << " ";
   	}
 

    return 0;

}
