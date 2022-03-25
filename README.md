# Caso_2_Analisis 

Para el algoritmo de quick sort se genera una lista de numeros aleatorios dentro del main. 
Cada una de las 10 ejecuciones que se corren incrementa en 50,000 la cantidad de elementos
de la lista que se ordena. A fin de no utlizar ni el mejor caso, ni el peor caso, la lista se
llena con numeros que se generan aleatoriamente entre 1 y el tamano de la lista.
Se evidencia de los resultados que, el logaritmo del tiempo que toma cada una de las ejecuciones"
aumenta, respecto de la anterior, pero cada vez en menor cantidad. Este crecimiento es del tipo"
logaritmico.

En el algoritmo de insertion se genera una lista del peor caso que traiga los numeros ordenados de mayor
a menor.Como se nota de los resultados, el incremento en los ticks totales que tarda cada ciclo es del tipo cuadratico. Por su parte el incremento en la raiz de cada resultado total
tiende a 16 (4^2), de forma que el incremento entre la raiz de cada resultado es de tipo lineal.

Para el algoritmo de freetext se buscan 5 palabras diferentes las cuales se definen en el main. 
De los resultados obtenidos, la medicion de los tiempo entre busquedas con mayor cantidad de
incidencias en el texto donde se busca, incrementa en intervalos de tiempo muy pequeños.
Sin embargo, ese incremento de cada resultado es de tipo lineal.