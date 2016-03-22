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
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

// Clases incluídas
#include "LES.h"


// Cabeceras no estándar
#include "rlutil.h"

//		-------Definiciones ---
#define MAX_SIZE	20		// Número total de máquinas disponibles
#define MAX_LENGTH	256		// Número máximo de caracteres
//		-------Pantalla---
#define ESPANOL				std::locale::global(std::locale("spanish"))		// Muestra los acentos en los strings
#define ESPERAR				system("pause")
#define	JUSTIFICADO			gotoxy((2),(trows() / 8))
#define CENTRAR				rlutil::locate((rlutil::tcols() / 4), rlutil::trows() / 2)
#define ESPERAR_TIEMPO		rlutil::msleep(2500)
#define OCULTAR_CURSOR		rlutil::hidecursor()
#define MOSTRAR_CURSOR		rlutil::showcursor()
#define LIMPIAR_PANTALLA	system("cls")
#define POSICION_NORMAL		rlutil::locate(0, 0);
//		-------Colores---
#define CYAN				rlutil::setColor(rlutil::CYAN);
#define ROJO				rlutil::setColor(4)
#define VERDE				rlutil::setColor(2)
#define BLANCO				rlutil::setColor(15)
#define MAGENTA				rlutil::setColor(5)
#define AZULADO				rlutil::setColor(11)
#define AMARILLO			rlutil::setColor(14)
//		-----DEFINICIONES DEL TECLADO---
#define T_CERO				48
#define	T_UNO				49
#define T_DOS				50
#define T_TRES				51
#define	T_CUATRO			52
#define T_CINCO				53
#define T_SEIS				54
#define T_SIETE				55
#define T_OCHO				56
#define T_NUEVE				57
#define TABULADOR			9
#define DIRECCION_IZQUIERDA	16
#define H					104
#define M					109
//		----Para el sistema---
#define EXIT_SUCCESS		 0




// Variables globales
computador	Computadoras[MAX_SIZE];
LES			ListaElementos;


// Funciones prototipos

//	--menu principal--
void menu();
//	--Primera opción--
void agregarUsuario();

// --Funciones adicionales--
void puntitos(string mensaje, int cantidad, int tiempo);		
//---------------------------

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
		LIMPIAR_PANTALLA;
		CENTRAR;
		puntitos("Mostrar usuarios", 5, 200);
		ListaElementos.getElementos(); 
		ESPERAR;
		menu();
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
	// Función para los números aleatorios
	srand(time(0));

	// Título de la pantalla
	LIMPIAR_PANTALLA;
	VERDE;
	cout << "\t\t\t\t Ingresar Curp" << endl;
	BLANCO;

	// En esta función primero verifica que el total de máquinas posibles no se rebase, que no pase de 19, contando el cero
	if (ListaElementos.getTotalElementos() > MAX_SIZE)
	{
		cout << "Ya no hay máquinas disponibles" << endl;
	}
	else
	{
		string curp;
		int i = 0;

		// Pide los datos al usuario
		cout << "\n\nIngresa tu curp: ";
		cin >> curp;
		cout << "\nTu curp es: " << curp << endl;

		// Manda una confirmación de continuar al usuario
		cout << "\n\nDeseas continuar [s / n]:";
		CYAN;
		OCULTAR_CURSOR;
		rlutil::locate(1, rlutil::trows() - 2);
		cout << "<=[TECLA IZQUIERDA]" << endl;
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
					Computadoras[numeroAleatorio].setCurp(curp);

					// Agrega el objeto a la lista
					ListaElementos.AgregarElemento(Computadoras[numeroAleatorio]);
					
					break; // Termina el bucle
				}
			}
		}
	}
}


// Cuerpos de funciones adicionales
void puntitos(string mensaje, int cantidad, int tiempo)
{
	VERDE;
	cout << mensaje;
	for (int i = 0; i < cantidad; i++)
	{
		printf(".");
		Sleep(tiempo);
	}
	BLANCO;
}