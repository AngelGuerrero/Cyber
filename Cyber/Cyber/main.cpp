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

/* Las declaraciones prototipo y las definiciones están en el documento "funciones.h" */
#include "funciones.h"


// Función principal
int main()
{
	BLANCO;
	menu();
}


// Cuerpo de las funciones prototipo
void menu()
{
		
	ESPANOL;
	LIMPIAR_PANTALLA;
	OCULTAR_CURSOR;
	AMARILLO;
	puts("\t\t\t\t\tMenú");
	
	BLANCO;
	puts("[1] \tUsar computadora");
	puts("[2] \tDejar computadora");
	puts("[3] \tCambiar de usuario de computadora");
	puts("[4] \tMostrar usuarios");
	puts("[5] \tGuardar registro de uso");
	puts("[6] \tMostrar registro de uso");
	
	CYAN;
	rlutil::locate(1, rlutil::trows()-2);
	puts("ESCAPE para salir");
	
	int longitud = 33;
	switch (rlutil::getkey())
	{
	case T_UNO:	
		LIMPIAR_PANTALLA;
		CENTRAR;
		puntitos("Agregar Usuario", 5, 200);
		agregarUsuario();
		menu();
		break;

	case T_DOS:				  break;

	case T_TRES:			  break;

	case T_CUATRO:
		mostrarUsuarios();
		break;

	case T_CINCO:break;
	case T_SEIS:			  break;
	case DIRECCION_IZQUIERDA: break;
	case rlutil::KEY_ESCAPE: // Salir
			LIMPIAR_PANTALLA;
			AZULADO;
			OCULTAR_CURSOR;
			CENTRAR;
			puntitos("¡Gracias por usar nuestro sistema!", 10, 200);
			exit(EXIT_SUCCESS);	
		break;
	default:
		menu();
		break;
	}
}
void agregarUsuario()
{
		
	// variables locales
	char nombreUsuario[MAX_LENGTH] = { '\0' };
	
	// Función para los números aleatorios
	srand(time(0));

	// Título de la pantalla
	LIMPIAR_PANTALLA;
	VERDE;
	std::cout << "\t\t\t\t Ingresar Usuario" << std::endl;
	BLANCO;

	// En esta función primero verifica que el total de máquinas posibles no se rebase, que no pase de 19, contando el cero
	if (ListaElementos.getTotalElementos() >= MAX_SIZE)
	{
		std::cout << "Ya no hay máquinas disponibles" << std::endl;
	}
	else
	{
		// Pide los datos al usuario
		std::cout << "\n\nIngresa tu nombre de usuario: ";
		std::cin.getline(nombreUsuario, MAX_LENGTH);
		std::cout << "\nTu nombre de usuario es: " << nombreUsuario << std::endl;

		// Manda una confirmación de continuar al usuario
		std::cout << "\n\nDeseas continuar [s / n]:";
		CYAN;
		OCULTAR_CURSOR;
		rlutil::locate(1, rlutil::trows() - 2);
		std::cout << "<=[TECLA IZQUIERDA]" << std::endl;
		for (;;)
		{
			if (kbhit())
			{
				char opcion = rlutil::getkey();

				if (opcion == DIRECCION_IZQUIERDA || opcion == 'n' || opcion == 'N')
				{
					menu();
				}
				else if (opcion == 's' || opcion == 'S')
				{
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
					Computadoras[numeroAleatorio].setnombreUsuario(nombreUsuario);

					// Agrega el objeto a la lista
					ListaElementos.AgregarElemento(Computadoras[numeroAleatorio]);
					
					break; // Termina el bucle
				}
			}
		}
	}
}
void mostrarUsuarios()
{
	/* Crea un nuevo array de elementos, llamado copiaElementos, en este contendrá los elementos que están en la lista
		esto con la finalidad de separar en las listas la funcionalidad del programa, y en éste ámbito el diseño */
	
	/* Locales */
	computador copiaElementos[MAX_SIZE];
	
	LIMPIAR_PANTALLA;
	CENTRAR;
	puntitos("Mostrar usuarios", 5, 200);		/* Muestra un mensaje en pantalla simplemente */
	LIMPIAR_PANTALLA;
	printf("\t\t\tUsuarios registrados\n\n");
	
	
	ListaElementos.getElementos(copiaElementos);
	for (int i = 0; i < (int)sizeof(copiaElementos) / (int)sizeof(copiaElementos[0]); i++)
	{
		if (copiaElementos[i].getId() != 0)
		{
			std::cout << "[" << i+1 << "]" << " | \tid: " << copiaElementos[i].getId() << "\t| Nombre de usuario: " << copiaElementos[i].getnombreUsuario() << std::endl;
		}
	}
	CYAN;
	rlutil::locate(1, rlutil::trows() - 2);
	ESPERAR;
	menu();
}


// Cuerpos de funciones adicionales
void puntitos(std::string mensaje, int cantidad, int tiempo)
{
	VERDE;
	std::cout << mensaje;
	for (int i = 0; i < cantidad; i++)
	{
		printf(".");
		Sleep(tiempo);
	}
	BLANCO;
}