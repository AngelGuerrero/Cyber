#pragma once

// Incluye la clase del cual creará los nodos
#include "computador.h"


class Nodo
{
public:
	// Atributos
	computador Computador;
	Nodo *NodoSiguiente;


	Nodo();
	Nodo(computador objeto);
	~Nodo();
};

