// función reciba un arreglo de enteros y su tamaño 
//retorne la suma de los elementos de un arreglo
#include<iostream>
#include<stdlib.h> // rand and srand prototype 
#include<time.h> // time prototype 

using namespace std;

void fillin(int *a, unsigned int n)
{
    for(int i=0; i<n; i++)
        a[i] = 1 + rand()% 77; // random numbers from 1 to 77
}

unsigned int sumIte(int *a, unsigned int n)
{
    unsigned int sum = 0;
    for (int i=0; i<n; i++)
        sum += a[i];
    return sum;
}

unsigned int sumRec(int *a, unsigned int n) // Not working with n = one million
{
    while(n>0)
        return (a[n-1] + sumRec(a,n-1));
    return 0;
    /*
    if (n == 0)
        return 0;
    else
        return (a[n-1] + sumRec(a,n-1));
    */
}

int main()
{
    srand(static_cast<int>( time(0))); // randomizer

    // the limit of static array < 10,000,000
    // because I use dynamic array
    unsigned int n = 1000000;
    int *a = new int[n];

    fillin(a,n);
    cout << "Iterative sum: " << sumIte(a,n) << endl;
    cout << "Recursive sum: " << sumRec(a,n) << endl;

    delete []a;
    return 0;
}