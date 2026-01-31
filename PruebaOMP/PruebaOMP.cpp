// PruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

using std::cout;
using std::endl;

void imprimeArreglo(float *d);

int main()
{
	float a[N], b[N], c[N];
	int i;
	int min = 1, max = 10000;
	int numero = 0;

	cout << "Sumando Arreglos en Paralelo!\n";

	// Rellenar arreglos a y b con números entre min y max
	for (i = 0; i < N; i++)
	{
		numero = min + rand() % (max - min + 1);
        a[i] = static_cast<float>(numero);

		numero = min + rand() % (max - min + 1);
		b[i] = static_cast<float>(numero);
	}


	int pedazos = chunk;

	#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

	cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << endl;
	imprimeArreglo(a);
	cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << endl;
	imprimeArreglo(b);
	cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
	{
		cout << d[x] << " - ";
	}
	cout << endl;
}