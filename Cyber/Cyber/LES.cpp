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


// Funciones de modificación ---
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
void LES::getElementos(computador copiaElementos[])
{
	if (esta_vacio())
	{
		std::cout << "\nLa lista está vacía" << std::endl;
	}
	else
	{
		Nodo *Iterador = ptr_PrimerElemento;
		for (int i = 0; Iterador != nullptr; i++)
		{
			copiaElementos[i].setId(Iterador->Computador.getId());
			copiaElementos[i].setnombreUsuario(Iterador->Computador.getnombreUsuario());
			//std::cout << "\nIdentificador: " << Iterador->Computador.getId() << " nombreUsuario: " << Iterador->Computador.getnombreUsuario() << std::endl;
			Iterador = Iterador->NodoSiguiente;
		}
		delete(Iterador);
	}
}


//Verifica que la lista esté vacía o no
bool LES::esta_vacio()
{
	return (ptr_PrimerElemento == nullptr);
}


// Cuenta el total de elementos en la lista
int  LES::getTotalElementos()
{
	Nodo *Iterador = ptr_PrimerElemento;
	int total;										// Suma el total de elementos

	for (total = 0; Iterador != nullptr; total++)
	{
		Iterador = Iterador->NodoSiguiente;
	}
	delete(Iterador);

	return total;
}