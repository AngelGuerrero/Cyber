#pragma once

// Clases inclu�das
#include "LES.h"

// Cabeceras no est�ndar
#include "rlutil.h"

//		-------Definiciones ---
#define MAX_SIZE	20		// N�mero total de m�quinas disponibles
#define MAX_LENGTH	256		// N�mero m�ximo de caracteres
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




/* ---Variables globales--- */
computador	Computadoras[MAX_SIZE];				/* Array de computadoras con la medida definida por el problema */
LES			ListaElementos;						/* Lista de elementos, que contendr� los elementos objetos de las computadoras*/


/* ---Funciones prototipo--- */

void menu();									/* Men� principal de la aplicaci�n*/

void agregarUsuario();							/* Primera funci�n del problema*/
void mostrarUsuarios();							/* Muestra los usuarios que est�n en la lista */

/* ---Funciones adicionales--- */
void puntitos(std::string mensaje, int cantidad, int tiempo);
