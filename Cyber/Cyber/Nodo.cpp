#include "Nodo.h"


Nodo::Nodo()
{
}

Nodo::Nodo(computador objeto)
{
	this->Computador = objeto;
	this->NodoSiguiente = nullptr;
}

Nodo::~Nodo()
{
}
