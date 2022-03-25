//Librerias
#include <iostream>
#include <sysinfoapi.h>
#include <chrono>
#include <cmath>

using namespace std;

//GLOBALES de Quicksort
double diflogaritmo;
double loganterior = 0; 


void Quicksort(long lista[], int primero, int largo)
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
Quicksort(lista, primero, j); /* mismo proceso con sublista izqda */
if (i < ultimo)
Quicksort(lista, i, ultimo); /* mismo proceso con sublista drcha */

}

int main(){

    using namespace std::chrono;

    //Apartir de aqui comienza el main de Quicksort

    cout <<"\nQuicksort"<< endl;
    
    long i;
    long j;
    long cantitems;
    long tiempo_corrida;
    double log_tiempo_corrida;
    int aleatorio;
    int desde;
    int hasta;

    for ( i=0; i<10; i++){
        cantitems = 50000*(i+1);
        long lista [cantitems];
        int desde = 1;
        int hasta = cantitems;

        for (j = 0; j < cantitems; j++){
            aleatorio = rand() % (hasta - desde + 1) + desde;
            //cout << aleatorio<<endl;
            
            lista[j]=aleatorio;
        }  
    
    int largo = sizeof(lista) / sizeof(lista[0]);

    long int ticks_quick= 0;
    long int acum_ticks= 0;

    cout<<endl;
    cout << "Largo de lista: "<< largo <<endl;

    auto start = chrono::system_clock::now();

    Quicksort(lista, 0, largo);
    
	
    auto end = chrono::system_clock::now();
    tiempo_corrida = chrono::duration_cast<chrono::nanoseconds> (end - start).count();
    log_tiempo_corrida = log(tiempo_corrida);
    cout << "Tiempo que tomo: "<< tiempo_corrida << " nanosegundos"<< endl;

    cout<<"Logaritmo del tiempo total: "<<log_tiempo_corrida<<endl;
    diflogaritmo = log_tiempo_corrida-loganterior;
    loganterior = log_tiempo_corrida;
    cout<<"Incremento respecto del logaritmo anterior: "<<diflogaritmo<<endl;
     
    }
    cout<<"\nCada una de las 10 ejecuciones que se corren incrementa en 50,000 la cantidad de elementos"<<endl;
    cout<<"de la lista que se ordena. A fin de no utlizar ni el mejor caso, ni el peor caso, la lista se"<<endl;
    cout<<"llena con numeros que se generan aleatoriamente entre 1 y el tamano de la lista."<<endl;
    cout <<"\nSe evidencia de los resultados que, el logaritmo del tiempo que toma cada una de las ejecuciones"<< endl;
    cout <<"aumenta, respecto de la anterior, pero cada vez en menor cantidad. Este crecimiento es del tipo"<< endl;
    cout <<"logaritmico.\n"<<endl;

    return 0;

}
