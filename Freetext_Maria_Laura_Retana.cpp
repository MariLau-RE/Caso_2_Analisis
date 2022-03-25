//Librerias
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <cmath>
#include<fstream>
#include <string>
#include <cstring>
using namespace std;

// numcaracter is the number of characters in the input alphabet  
#define numcaracter 256  

  
void BuscarElemento(char busca[], char listatext[], int q)  
{  
    int M = strlen(busca);  
    int N = strlen(listatext);  
    int i, j;  
    int b = 0; // hash value de busca  
    int lt = 0; // hash value de listatext  
    int h = 1;  
  
    for (i = 0; i < M - 1; i++)  
        h = (h * numcaracter) % q;  
  
    // Calculate the hash value of busca and first  
 
    for (i = 0; i < M; i++)  
    {  
        b = (numcaracter * b + busca[i]) % q;  
        lt = (numcaracter * lt + listatext[i]) % q;  
    }  
  
    // Slide the pattern over text one by one  
    for (i = 0; i <= N - M; i++)  
    {  
  
        // Check the hash values of current window of text  
        // and pattern. If the hash values match then only  
        // check for characters on by one  
        if ( b == lt )  
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)  
            {  
                if (listatext[i+j] != busca[j])  
                    break;  
            }  
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
            if (j == M)  {
                    cout<<"\nPatron encontrado en el indice:  "<< i<<endl;
            }
  

        }  
  
        // Calculate hash value for next window of text: Remove  
        // leading digit, add trailing digit  
        if ( i < N-M )  
        {  
            lt = (numcaracter*(lt - listatext[i]*h) + listatext[i+M])%q;  
            // We might get negative value of t, converting it  
            // to positive  
            if (lt < 0)  
            lt = (lt + q);  
        }  
    }  
     
}  


int main(){

    using namespace std::chrono;


    //Apartir de aqui comienza el main de free text

    cout <<"\nFree text"<< endl;

    long size = 2000000;
    char listatext[size];
    int cantcaracter = 0;
    int a = 0;
    int porbuscar []={};

    ifstream myfile ("freetext.txt");

     if (myfile.is_open())
        {
          while ( !myfile.eof())
          {
                myfile >> listatext[a];
                a++;
                cantcaracter ++;
          }      

    for (int i = 0; i <= cantcaracter; i++)
      {

         //cout << listatext[i];
      }  
     }
     else{
        cout<<"\nEl archivo no existe"<<endl;  
        cout<<"Para realizar la prueba el archivo a analizar se debe llamar freetext.txt"<<endl; 

     }
    char busca1[] ="Jaboc";
    char busca2[] = "Sarai";
    char busca3[] = "pan";
    char busca4[] = "cielo";
    char busca5[] = "agua";
    
    int q = 101; // un numero primo  
 
        auto start1 = chrono::system_clock::now();
   
        BuscarElemento(busca1, listatext, q); 
  

        auto end1 = chrono::system_clock::now();
        cout << "\nTiempo que tomo: "
        <<chrono::duration_cast<chrono::nanoseconds> (end1 - start1).count()
        << " nanosegundos " << endl;

        auto start2 = chrono::system_clock::now();
   
        BuscarElemento(busca2, listatext, q); 
  

        auto end2 = chrono::system_clock::now();
        cout << "\nTiempo que tomo: "
        <<chrono::duration_cast<chrono::nanoseconds> (end2 - start2).count()
        << " nanosegundos " << endl;

        auto start3 = chrono::system_clock::now();
   
        BuscarElemento(busca3, listatext, q); 
   

        auto end3 = chrono::system_clock::now();
        cout << "\nTiempo que tomo: "
        <<chrono::duration_cast<chrono::nanoseconds> (end3 - start3).count()
        << " nanosegundos " << endl;

        auto start4 = chrono::system_clock::now();
   
        BuscarElemento(busca4, listatext, q); 
   

        auto end4 = chrono::system_clock::now();
        cout << "\nTiempo que tomo: "
        <<chrono::duration_cast<chrono::nanoseconds> (end4 - start4).count()
        << " nanosegundos " << endl;

        auto start5 = chrono::system_clock::now();
   
        BuscarElemento(busca5, listatext, q); 
    

        auto end5 = chrono::system_clock::now();
        cout << "\nTiempo que tomo: "
        <<chrono::duration_cast<chrono::nanoseconds> (end5 - start5).count()
        << " nanosegundos " << endl;
    cout <<"\nDe los resultados obtenidos, la medicion de los tiempo entre busquedas con mayor cantidad de"<< endl;
    cout <<"incidencias en el texto donde se busca, incrementa en intervalos de tiempo muy pequeños."<< endl;
    cout <<"Sin embargo, ese incremento de cada resultado es de tipo lineal.\n"<<endl;
   
    return 0;

}
