// MUESTRA LA BASE COMPLETA O UN REGISTRO i
#include "funciones.h"
typedef char typeNombreNacion[10];
typedef typeNombreNacion tVectorNombreNacion[NACIONALIDADES];
void mostrarRegistro(tVectorEmpleados empleados, int i);
void mostrarEncabezado();
void mostrarPie();

void mostrarBase(tVectorEmpleados empleados, int maximoLogico)
{
	int i;
	mostrarEncabezado();
	for (i = 0; i < maximoLogico; i++)
	{
		mostrarRegistro(empleados, i);
	}
	mostrarPie();
	pausa();
	return;
}

void mostrarEncabezado()
{
	printf("%-20s %-20s %-13s %-5s %s\n", "APELLIDOS", "NOMBRES", "FECHA NAC.", "SEXO", "NACIONALIDAD");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarPie()
{
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarRegistro(tVectorEmpleados empleados, int i)
{
	int codigoNacion;
	tVectorNombreNacion nombreNacionalidad = {"Argentina", "Uruguaya", "Chilena", "Peruana", "Boliviana", "Paraguaya", "Brasilenia"};
	printf("%-20s %-20s %02d-%02d-%d     %-5c", empleados[i].apellidos, empleados[i].nombres, empleados[i].fecha.dia, empleados[i].fecha.mes, empleados[i].fecha.anio, empleados[i].sexo);
	// mostrar las nacionalidades
	for (codigoNacion = 0; codigoNacion < NACIONALIDADES; codigoNacion++)
	{
		if (empleados[i].nacionalidades[codigoNacion] == 1)
		{
			printf("%s ", nombreNacionalidad[codigoNacion]);
		}
	}
	printf("\n");
	return;
}
