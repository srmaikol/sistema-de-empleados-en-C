// B- Mostrar un listado de personas nacidas antes de 2000 ordenado por Fecha de nacimiento. Mostrar todos los datos de cada empleado.
#include "funciones.h"

void ordenarPorFechaNacimiento(tVectorEmpleados vector, int maximoLogico, tVectorEmpleados vectorOrdenado);
int esPosterior(tipoFecha fecha, tipoFecha fecha2);

void antesDel2000(tVectorEmpleados empleados, int maximoLogico)
{
	tVectorEmpleados nacidosAntesDel2000, ordenadosAntesDel2000;
	int i, i2000, maximoLogico2000;
	i2000 = 0;
	borrarPantalla();
	// GENERAMOS NUEVO VECTOR FILTRADO CON SOLO LOS NACIDOS LUEGO DEL 2000
	for (i = 0; i < maximoLogico; i++)
	{
		if (empleados[i].fecha.anio < 2000)
		{
			nacidosAntesDel2000[i2000] = empleados[i];
			i2000++;
		}
	}
	maximoLogico2000 = i2000;
	// ORDENAMOS EL VECTOR FILTRADO Y LO MOSTRAMOS
	ordenarPorFechaNacimiento(nacidosAntesDel2000, maximoLogico2000, ordenadosAntesDel2000);
	printf("B. EMPLEADOS NACIDOS ANTES DEL 2000 ORDENADOS POR FECHA DE NACIMIENTO\n\n");
	mostrarBase(ordenadosAntesDel2000, maximoLogico2000);
	return;
}

// ORDENA VECTORES POR FECHA
void ordenarPorFechaNacimiento(tVectorEmpleados vector, int maximoLogico, tVectorEmpleados vectorOrdenado)
{
	int i, j, posicion;
	for (i = 0; i < maximoLogico; i++)
	{
		vectorOrdenado[i].fecha.dia = 0;
	}
	/* ORDENAMOS POR EL METODO INSERTION SORT: PARA CADA ELEMENTO, RECORREMOS EL VECTOR CONTANDO EN posicion 
	TODOS LOS ELEMENTOS QUE SON MENORES AL ELEMENTO ACTUAL. lUEGO LO COPIAMOS EN EL NUEVO VECTOR EN LA UBICACION posicion */
	borrarPantalla();
	for (i = 0; i < maximoLogico; i++)
	{
		posicion = 0;
		// COMPARAMOS LA FECHA DEL ELEMENTO ACTUAL CONTRA lA FECHA DE TODOS LOS OTROS ELEMENTOS DEL VECTOR:
		for (j = 0; j < maximoLogico; j++)
		{
			if (i != j)
			{ // lO VAMOS COMPARANDO CONTRA TODOS LOS OTROS ELEMENTOS Y ESTABLECEMOS LA POSICION EN Q DEBE QUEDAR
				if (esPosterior(vector[i].fecha, vector[j].fecha) == 1)
				{
					posicion++;
				}
			}
		}
		//		SI EN EL VECTOR ORDENADO YA HAY ELEMENTOS CON IGUAL FECHA, LO UBICAMOS EN LA SIGUIENTE POSICION
		while (esPosterior(vectorOrdenado[posicion].fecha, vector[i].fecha) == 2)
		{
			posicion++;
		}
		vectorOrdenado[posicion] = vector[i];
	}
}

/* COMPARA DE FECHAS. DEVUELVE: 
0 SI FECHA2>FECHA
1 SI FECHA>FECHA2,
2 SI FECHA==FECHA2
*/
int esPosterior(tipoFecha fecha, tipoFecha fecha2)
{
	int esPost = 0;
	if (fecha.anio > fecha2.anio)
	{
		esPost = 1;
	}
	if (fecha.anio == fecha2.anio)
	{
		if (fecha.mes > fecha2.mes)
		{
			esPost = 1;
		}
		if (fecha.mes == fecha2.mes)
		{
			if (fecha.dia > fecha2.dia)
			{
				esPost = 1;
			}
			if (fecha.dia == fecha2.dia)
			{
				esPost = 2; // misma fecha de nacimiento!!!
			}
		}
	}
	return esPost;
}
