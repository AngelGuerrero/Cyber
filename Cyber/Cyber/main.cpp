/* 
	Programa: Cyber
	Programador: �ngel Guerrero
	�ltima modificaci�n: Marzo 16. 

	Descripci�n del programa: https://github.com/AngelGuerrero/Cyber
*/


// Cabeceras est�ndar
#include <ctime>
#include <string>
#include <random>
#include <iostream>
#include <Windows.h>
using namespace std;


// Definiciones
#define MAX_SIZE 20		// N�mero total de m�quinas disponibles


// Clases inclu�das
#include "LES.h"


// Cabeceras no est�ndar
#include "rlutil.h"


// Variables globales
computador	Computadoras[MAX_SIZE];
LES			ListaElementos;


// Funciones prototipos
void agregarUsuario();


// Funci�n principal
int main()
{

	agregarUsuario();
	ListaElementos.getElementos();
	system("pause");
}


// Cuerpo de las funciones prototipo

void agregarUsuario()
{
	// Funci�n para los n�meros aleatorios
	srand(time(0));

	// En esta funci�n primero verifica que el total de m�quinas posibles no se rebase, que no pase de 19, contando el cero
	if (ListaElementos.getTotalElementos() > MAX_SIZE)
	{
		cout << "Ya no hay m�quinas disponibles" << endl;
	}
	else
	{
		string curp;

		// Pide los datos al usuario
		cout << "\t\t\t\t Ingresar Curp" << endl;
		cout << "\n\nIngresa tu curp: " << endl;
		cin >> curp;

		//Genera un n�mero aleatorio
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
