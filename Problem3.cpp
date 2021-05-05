// ordene los elementos de un arreglo: ascendente
#include<iostream>
#include<stdlib.h> // rand and srand prototype 
#include<time.h> // time prototype
#include<math.h> // para operaciones aritmeticas
#include<vector> // para almacenar temporalmente elementos del arreglo 

using namespace std;

vector< vector <int> > Vec; // declaramos un vector de vector de manera global

void fillin(int *a, unsigned int n)
{
    for(int i=0; i<n; i++)
        a[i] = 1 + rand()% 1000000; // random numbers 
}

void show(int a[], unsigned int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "[" << a[i] <<"] "; 
    }
}

void radix(int a[], int n) // Algoritmo radix
{
	Vec.resize(10); // le asignamos un tama�o al vector auxiliar - tama�o 10 porque digito 0 1 2 3 4 5 6 7 8 9
	// declaramos variables auxiliares
	int temp, m=0; // temp:temporal (almacena el valor de las unidades, decenas, centenas,etc
					// m: indice para ir almacenando nuevamente en el arreglo
	
	for(int i=0; i<7; i++) // soporta hasta numero de 7 cifras 1234567
	{
		for(int j=0; j<n; j++)
		{
			temp = (int) (a[j]/pow(10,i)) % 10; // desglosa las unidades, decenas, centenas, etc
			// como el resultado de arriba nos da un double, hacemos un cast con "(int)"
			Vec[temp].push_back(a[j]); // almacenamos en la posicion [temp] el valor del arreglo
			// push_back a�ade el elemento al final del vector
			
			// printVector(Vec);
			//(opcional) esta funcion es para ir visualizando el ordenamiento
		}
		
		for (int k=0; k<10;k++) // ahora transferimos esos elementos a nuestro arreglo original
		{
			for(int p=0; p<Vec[k].size();p++) // recorre hasta el tama�o de la fila
			{ 
				a[m]=Vec[k][p];
				m++;	
			}
			Vec[k].clear(); //limpiamos el vector de la posicion "k" porque despues ira por la decenas, centenas, etc.
		}
		m = 0; // una vez terminado el ciclo, regresamos a la primera posicion para seguir con las decenas, centenas, etc.
	}
}

int main()
{
    srand(static_cast<int>( time(0))); // randomizer

    unsigned int n = 1000000;
    int a[n];

    fillin(a,n);

    cout << "10 first elements: " << endl;
    cout << "\nBefore sort: " << endl;
    show(a,10);

    cout << endl;

    cout << "\nAfter sort:" << endl;
    radix(a,n);
    show(a,10);

    return 0;
}