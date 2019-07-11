/* C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y
ademas nacieron en verano. Mostrar todos los datos de cada empleado.
*/

#include "funciones.h"

void mujeres(tVectorEmpleados empleados, int maximoLogico) /* modificaci�n : saque el puntero del maximoLogico */
{
	int i;
	int posicion = 0;
	char apellido[LARGOCAMPOSTEXTO];
	tipoFecha empieza_verano;
	empieza_verano.dia = 21;
	empieza_verano.mes = 12;
	tipoFecha termina_verano;
	termina_verano.dia = 20;
	termina_verano.mes = 3;
	borrarPantalla();
	printf("C. BUSQUEDA POR APELLIDO DE MUJERES NACIDAS EN VERANO\n\n");
	printf("Ingrese el apellido de la mujer a buscar EN MAYUSCULAS: ");
	fgets(apellido, LARGOCAMPOSTEXTO, stdin);
	apellido[strlen(apellido) - 1] = '\0';
	printf("\nMUJERES DE APELLIDO %s NACIDAS EN VERANO:\n\n", apellido);
	mostrarEncabezado();
	for (i = 0; i < maximoLogico; i++)
	{
		if (empleados[i].sexo == 'F')
		{ /* Asignamos el anio del empleado a el anio del verano para poder reusar nuestra funcion que compara fechas*/
			empieza_verano.anio = empleados[i].fecha.anio;
			termina_verano.anio = empleados[i].fecha.anio;
			if ((strcmp(empleados[i].apellidos, apellido) == 0) && ((esPosterior(empleados[i].fecha, empieza_verano) >= 1) || (esPosterior(termina_verano, empleados[i].fecha) >= 1)))
			/*               Pido que tengan mismo apellido                Que haya nacido a partir del 21 de Diciembre              Que haya nacido hasta el 20 de marzo      */
			{
				mostrarRegistro(empleados, i); /* Muestro el empleado que cumple las condiciones */
			}
		}
	}
	mostrarPie();
	pausa();
}
