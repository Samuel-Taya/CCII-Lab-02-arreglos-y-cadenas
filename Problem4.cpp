#include <iostream>
#include <string.h>

using namespace std;

int tamanio( char c[])
{
    int n=0;
    while (c[n] != 0)
        n++;
    return n;
}

int main()
{
    char cadena[]="This is a example of string";

    cout << "The size of the string is: " << tamanio(cadena);

    return 0;
}
