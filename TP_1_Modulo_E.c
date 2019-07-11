#include "funciones.h"
void argentinos(tVectorEmpleados empleados, int maximoLogico)
{
	int i, CantidadArgentinos = 0, CodigoArgentina = 0;
	borrarPantalla();
	for (i = 0; i < maximoLogico; i++)
	{
		if (empleados[i].nacionalidades[CodigoArgentina] == 1)
		{
			CantidadArgentinos++;
		}
	}
	printf("\nE. PORCENTAJE DE EMPLEADOS ARGENTINOS:\n\n%.0f%%\n", ((float)CantidadArgentinos / maximoLogico) * 100);
	pausa();
	return;
}
