/* 
	Programa: Cyber
	Programador: Ángel Guerrero
	Última modificación: Marzo 16. 

	Descripción del programa: https://github.com/AngelGuerrero/Cyber
*/


// Cabeceras estándar
#include <ctime>
#include <string>
#include <random>
#include <iostream>
#include <Windows.h>
using namespace std;


// Definiciones
#define MAX_SIZE 20		// Número total de máquinas disponibles


// Clases incluídas
#include "LES.h"


// Cabeceras no estándar
#include "rlutil.h"


// Variables globales
computador	Computadoras[MAX_SIZE];
LES			ListaElementos;


// Funciones prototipos
void agregarUsuario();


// Función principal
int main()
{

	agregarUsuario();
	ListaElementos.getElementos();
	system("pause");
}


// Cuerpo de las funciones prototipo

void agregarUsuario()
{
	// Función para los números aleatorios
	srand(time(0));

	// En esta función primero verifica que el total de máquinas posibles no se rebase, que no pase de 19, contando el cero
	if (ListaElementos.getTotalElementos() > MAX_SIZE)
	{
		cout << "Ya no hay máquinas disponibles" << endl;
	}
	else
	{
		string curp;

		// Pide los datos al usuario
		cout << "\t\t\t\t Ingresar Curp" << endl;
		cout << "\n\nIngresa tu curp: " << endl;
		cin >> curp;

		//Genera un número aleatorio
		int numeroAleatorio = rand() % MAX_SIZE + 0;		// Entre 0 y 19
		if (numeroAleatorio == Computadoras[numeroAleatorio].getId())
		{
			do
			{
				numeroAleatorio = rand() % MAX_SIZE + 0;
			} while (numeroAleatorio == Computadoras[numeroAleatorio].getId());
		}

		// Modifica los datos de los objetos 
		Computadoras[numeroAleatorio].setId(numeroAleatorio);
		Computadoras[numeroAleatorio].setCurp(curp);

		// Agrega el objeto a la lista
		ListaElementos.AgregarElemento(Computadoras[numeroAleatorio]);
	}
}
