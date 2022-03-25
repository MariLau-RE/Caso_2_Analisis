//Librerias
#include <iostream>
#include <sysinfoapi.h>
#include <chrono>
#include <cmath>
using namespace std;

//GLOBALES de Insertion
int resultanterior;
int diferencia;
double difraiz;
double raizanterior; 


void Insertion_Sort (int lista[], int largo)
{

int i, j;
int aux;
int raiz;

long int ticks_insercion= 0;

ticks_insercion = GetTickCount();
cout<<endl;
cout << "\nLargo de lista: "<< largo <<endl;

for (i = 1; i < largo; i++){
/* indice j explora la sublista a[i-1]..a[0] buscando la
posicion correcta del elemento destino, lo asigna a a[j] */
j = i;
aux = lista[i];
/* se localiza el punto de inserción explorando hacia abajo */

while (j > 0 && aux < lista[j-1]) {
/* desplazar elementos hacia arriba para hacer espacio */
lista[j] = lista[j-1];
j--;
}

lista[j] = aux;
}
ticks_insercion = GetTickCount() - ticks_insercion;

	cout << "Insercion tardo un total de " << ticks_insercion << " ticks" << endl;
    diferencia= ticks_insercion - resultanterior;
    difraiz= sqrt(ticks_insercion) - raizanterior;
    cout << "Incremento real de " << diferencia << " ticks" << endl;
    cout << "Raiz cuadrada del total: "<<sqrt(ticks_insercion)<<endl;
    cout <<"Incremento en la raiz: " <<difraiz<<endl;
    resultanterior = ticks_insercion;
    raizanterior = sqrt(ticks_insercion);



}

int main(){

    //Apartir de aqui comienza el main de Insertion sort

    cout <<"\nInsertion Sort"<< endl;

    int x;
    int y;
    int cantitem;

    for ( x=0; x<10; x++){
        cantitem = 10000*(x+1);
        int lista2 [cantitem];
        for (y = 0; y < cantitem; y++){
           lista2[y]=cantitem-y;
        }  
    
    int largo2 = sizeof(lista2) / sizeof(lista2[0]);
    
    Insertion_Sort(lista2, largo2);
    }
    
    cout <<"\nComo se nota de los resultados, el incremento en los ticks totales que tarda cada ciclo"<< endl;
    cout <<"es del tipo cuadratico. Por su parte el incremento en la raiz de cada resultado total"<< endl;
    cout <<"tiende a 16 (4^2), de forma que el incremento entre la raiz de cada resultado es de tipo lineal.\n"<<endl;

    return 0;

}
