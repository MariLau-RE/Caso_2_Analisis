#include <iostream>
#include <ctime>
#include <sysinfoapi.h>
#include <chrono>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int resultanterior;
int diferencia;
double difraiz;
double raizanterior; 


void Insercion (int lista[], int largo)
{

using namespace std::chrono;
int i, j;
int aux;
int raiz;

long int ticks_insercion= 0;
//long int acum_ticks_for= 0;

ticks_insercion = GetTickCount();
cout<<endl;
cout << "Largo de lista: "<< largo <<endl;
//cout <<"GetTickCount inicial: "<<ticks_insercion<<endl;

//auto start = std::chrono::system_clock::now();

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
//acum_ticks_for = acum_ticks_for + ticks_insercion;
    //cout <<"GetTickCount final: "<<GetTickCount()<<endl;
	//cout << "While tardo un total de " << acum_ticks_while << " ticks." << endl;
	cout << "Insercion tardo un total de " << ticks_insercion << " ticks" << endl;
    diferencia= ticks_insercion - resultanterior;
    difraiz= sqrt(ticks_insercion) - raizanterior;
    cout << "Incremento real de " << diferencia << " ticks" << endl;
    cout << "Raiz cuadrada del total: "<<sqrt(ticks_insercion)<<endl;
    cout <<"Incremento en la raiz: " <<difraiz<<endl;
    resultanterior = ticks_insercion;
    raizanterior = sqrt(ticks_insercion);

	//auto end = std::chrono::system_clock::now();

    //std::chrono::duration<float,std::milli> duration = end - start;
    //std::cout << duration.count() << " milisegundos " << endl;

}

void quicksort(long lista[], int primero, int largo)
{
int ultimo;
int i, j, centro;
double pivote;
double temporal;

ultimo= largo-1;

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

    using namespace std::chrono;
    
    long i;
    long j;
    long cantitems;

    /*for ( i=0; i<10; i++){
        cantitems = 100000*(i+1);
        long lista [cantitems];
        cout<<i<<endl;
        for (j = 0; j < cantitems; j++){
           lista[j]=cantitems-j;
        }  
    
    int largo = sizeof(lista) / sizeof(lista[0]);

    long int ticks_quick= 0;
    long int acum_ticks= 0;

    ticks_quick = GetTickCount();
    cout<<endl;
    cout << "Largo de lista: "<< largo <<endl;

    auto start = std::chrono::system_clock::now();

    quicksort(lista, 0, largo);
    
    ticks_quick = GetTickCount() - ticks_quick;
    acum_ticks = acum_ticks + ticks_quick;
   
	cout << "Quicksort tardo un total de " << acum_ticks << " ticks" << endl;
	auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << duration.count() << " milisegundos " << endl;

     
    }*/
     

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
    
    Insercion(lista2, largo2);
    }
    cout<<endl;
    cout <<"Como se nota de los resultados, el incremento en los ticks totales que tarda cada ciclo"<< endl;
    cout <<"es del tipo cuadratico. Por su parte el incremento en la raiz de cada resultado total"<< endl;
    cout <<"tiende a 16 (2^4), de forma que el incremento entre la raiz de cada resultado es de tipo lineal."<<endl;
    cout <<endl;
    return 0;

}
