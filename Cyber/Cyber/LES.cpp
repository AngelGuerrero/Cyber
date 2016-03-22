#include "LES.h"


#include <cstdlib>	// delete
#include <iostream>


using namespace std;


LES::LES()
{
	ptr_PrimerElemento = ptr_UltimoElemento = ptr_ElementoAnterior = nullptr;
}

LES::~LES()
{
}


// Funciones de modificaci�n ---
void LES::AgregarElemento(computador objeto)
{
	Nodo *NuevoElemento = new (nothrow) Nodo(objeto);
	if (esta_vacio())
	{
		ptr_PrimerElemento = ptr_UltimoElemento = NuevoElemento;
	}
	else
	{
		ptr_UltimoElemento->NodoSiguiente = NuevoElemento;
		ptr_UltimoElemento = NuevoElemento;
	}
}


// Funciones de acceso ---

// Retorna los elementos de la lista en un arreglo
void LES::getElementos()
{
	computador arreglo[20];
	if (esta_vacio())
	{
		cout << "La lista est� vac�a" << endl;
	}
	else
	{
		Nodo *Iterador = ptr_PrimerElemento;
		for (int i = 1; Iterador != nullptr; i++)
		{
			cout << "Identificador: " << Iterador->Computador.getId() << endl;
			Iterador = Iterador->NodoSiguiente;
		}
		delete(Iterador);
	}
}


//Verifica que la lista est� vac�a o no
bool LES::esta_vacio()
{
	return (ptr_PrimerElemento == nullptr);
}


// Cuenta el total de elementos en la lista
int  LES::getTotalElementos()
{
	Nodo *Iterador = ptr_PrimerElemento;
	int total;										// Suma el total de elementos

	for (total = 0; Iterador->NodoSiguiente != nullptr; total++)
	{
		Iterador = Iterador->NodoSiguiente;
	}
	delete(Iterador);

	return total;
}