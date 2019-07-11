#include <stdio.h>
#include <string.h>
// CONSTANTES Y TIPOS GLOBALES
#ifndef DEFINICIONES_CARGADAS
	#define DEFINICIONES_CARGADAS
	#define MAXIMOFISICO 500
	#define NACIONALIDADES 7
	#define LARGOCAMPOSTEXTO 20
	// ESTRUCTURA FECHA Y VECTOR NACIONALIDADES A INCLUIR EN CADA REGISTRO
	typedef struct
	{
		int dia;
		int mes;
		int anio;
	} tipoFecha;
	typedef int tVectorNacionalidades[NACIONALIDADES];
	/*	TIPO DE DATOS DE CADA REGISTRO: typeEmpleado 
		TIPO DE DATOS DEL VECTOR PRINCIPAL: tVectorEmpleados */
	typedef struct
	{
		char apellidos[LARGOCAMPOSTEXTO];
		char nombres[LARGOCAMPOSTEXTO];
		tipoFecha fecha;
		char sexo;
		tVectorNacionalidades nacionalidades;
	} typeEmpleado;
	typedef typeEmpleado tVectorEmpleados[MAXIMOFISICO];
	#include "mostrarBase.c"
	#include "cargarDatosDeEjemplo.c"
	#include "TP_1_Modulo_A.c"
	#include "TP_1_Modulo_B.c"
	#include "TP_1_Modulo_C.c"
	#include "TP_1_Modulo_D.c"
	#include "TP_1_Modulo_E.c"
#endif
void borrarPantalla();
void pausa();
