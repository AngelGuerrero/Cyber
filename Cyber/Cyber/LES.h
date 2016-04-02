#pragma once

#include "Nodo.h"

// Lista Enlazada simple
class LES
{
public:
	Nodo *ptr_PrimerElemento;
	Nodo *ptr_UltimoElemento;
	Nodo *ptr_ElementoAnterior;

	LES();
	~LES();

// Modificadores
	void AgregarElemento(computador objeto);						// Recibe el objeto para agregar a la lista, si la funci�n retorna false, el elemento no se agreg� a la lista.

// Funciones de acceso
	// Muestra todos los elementos de la lista
	void getElementos(computador devuelveArray[]);		// Muestra todos los elementos listados
	bool esta_vacio();
	int getTotalElementos();

};

