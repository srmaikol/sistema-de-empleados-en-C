#include "funciones.h"

int main()
{
	//system("COLOR F0"); pone la consola en texto negro sobre fondo blanco para capturar las pantallas
	int maximoLogico, salir;
	char opcion;
	maximoLogico = 0;
	salir = 0;
	tVectorEmpleados empleados;
	cargarDatosDeEjemplo(empleados, &maximoLogico);
	while (!salir)
	{
		printf("SISTEMA EMPLEADOS 2019\n\n");
		printf("A. Cargar empleados\nB. Nacidos antes de 2000\nC. Busqueda de mujeres nacidas en verano\n");
		printf("D. Uruguayos y argentinos con mas de una nacionalidad\nE. Porcentaje de empleados argentinos\n");
		printf("F. Listar toda la base\nS. Salir\n\nINGRESE LA OPCION DESEADA: ");
		scanf(" %c", &opcion);
		fflush(stdin);
		switch (opcion)
		{
			case 'A':
			case 'a':
				cargarEmpleados(empleados, &maximoLogico);
				pausa();
				break;
			case 'B':
			case 'b':
				antesDel2000(empleados, maximoLogico);
				break;
			case 'C':
			case 'c':
				mujeres(empleados, maximoLogico);
				break;
			case 'D':
			case 'd':
				dobleNacionalidad(empleados, maximoLogico);
				break;
			case 'E':
			case 'e':
				argentinos(empleados, maximoLogico);
				break;
			case 'S':
			case 's':
				salir = 1;
				break;
			case 'F':
			case 'f':
				borrarPantalla();
				printf("BASE DE EMPLEADOS\n\n");
				mostrarBase(empleados, maximoLogico);
				break;
			default:
				printf("Por favor digite una opcion valida. Pulse Enter para continuar");
				getchar();
				borrarPantalla();
		}
	}
borrarPantalla();
printf("\nGRACIAS POR UTILIZAR SISTEMA EMPLEADOS 2019!\n\n");
return 0;
}

void borrarPantalla()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void pausa()
{
	printf("\nPulse Enter para volver al Menu Principal");
	fflush(stdin);
	getchar();
	borrarPantalla();
	return;
}
