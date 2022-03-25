#Maria Laura Retana Elizondo, 2019390522, Analisis de algoritmos
#Este es el make file para compilar el caso

all: QuickSort_Maria_Laura_Retana Insertion_Maria_Laura_Retana Freetext_Maria_Laura_Retana 

QuickSort_Maria_Laura_Retana: QuickSort_Maria_Laura_Retana
	g++ -o QuickSort_Maria_Laura_Retana QuickSort_Maria_Laura_Retana.cpp
	.\QuickSort_Maria_Laura_Retana


Insertion_Maria_Laura_Retana: Insertion_Maria_Laura_Retana
	g++ -o Insertion_Maria_Laura_Retana Insertion_Maria_Laura_Retana.cpp 
	.\Insertion_Maria_Laura_Retana
	
	

Freetext_Maria_Laura_Retana: Freetext_Maria_Laura_Retana
	g++ -o Freetext_Maria_Laura_Retana Freetext_Maria_Laura_Retana.cpp
	.\Freetext_Maria_Laura_Retana
	
	
