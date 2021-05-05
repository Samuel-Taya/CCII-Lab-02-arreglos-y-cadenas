// Invierta los elementos de un arreglo de enteros (Iterativa y recursiva)
#include<iostream>

using namespace std;

void fillin(int a[], unsigned int n)
{
    for(int i=0; i<n; i++)
        a[i] = i; 
}

void show(int a[], unsigned int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "[" << a[i] <<"] "; 
    }
}

void invIte(int a[], unsigned int n)
{
    int aux = 0;
    for (int i=0; i<n; i++,n--)
    {
        aux = a[i];
        a[i] = a[n-1];
        a[n-1] = aux;  
    }
}

int main()
{
    unsigned int n = 1000000;
    int a[n];
    
    cout << "10 first elements of Array: " << endl;
    fillin(a,n);
    show(a,10);
    cout << endl;

    cout << "\nIterativ reverse: " << endl;
    invIte(a,n);
    show(a,10);
    cout << endl;

    return 0;
}