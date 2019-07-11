// D- Emitir un informe de empleados uruguayos y argentinos que tengan más de una nacionalidad. Mostrar todos los datos de cada empleado. 
#include "funciones.h"
void dobleNacionalidad(tVectorEmpleados empleados, int maximoLogico)
{
	int i;
	int posicion;
	int otranacionalidad;
	borrarPantalla();
	printf("D. ARGENTINOS Y URUGUAYOS CON MAS DE UNA NACIONALIDAD\n\n");
	mostrarEncabezado();
	for (i = 0; i < maximoLogico; i++)
	{
		if (empleados[i].nacionalidades[0] == 1 || empleados[i].nacionalidades[1] == 1) //Me fijo que sea Argentino o Uruguayo
		{
			otranacionalidad = 0;
			posicion = 1; // Lo igualo a 1 ya que la posicion 0 es Argentina y lo primero que hago en el while es sumarle uno porque la posicion 1 es Uruguay
			if(empleados[i].nacionalidades[0] == 1 && empleados[i].nacionalidades[1] == 1)//Me fijo el caso de que sea Argentino y Uruguayo
			{
				mostrarRegistro(empleados, i);
			}
			else
			{
				while (otranacionalidad == 0 && posicion < 7)
				{
					posicion++;
					if (empleados[i].nacionalidades[posicion] == 1) //Si se da que es Argentino o Uruguayo y de otra nacionalidad cambio otranacionalidad oir lo que deberia salir del while
						otranacionalidad = 1;
				}
				if (otranacionalidad == 1 ) //Me fijo si cumple que sea Arg o Uru y de otra nacionalidad
				{
					mostrarRegistro(empleados, i);
				}
			}
		}
	}
	mostrarPie();
	pausa();
	return;
}
