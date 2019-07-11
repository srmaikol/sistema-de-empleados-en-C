// A. CARGA Y VALIDACION DE DATOS
#include "funciones.h"

#define ANIOACTUAL 2019

int esCadenaValida(char texto[LARGOCAMPOSTEXTO]);
void cargarNacionalidad(tVectorNacionalidades nacEmpleados);
char validarSexo(char sexo);
void validarFecha(int *dia, int *mes, int *anio);
void validarnacionalidad(int *numNacionalidad);

void cargarEmpleados(tVectorEmpleados empleados, int *maximoLogico)
{
	int i;
	char seguimos;
	i = *maximoLogico;
	borrarPantalla();
	printf("A. CARGA DE EMPLEADOS\n\n");
	do
	{
		do
		{
			printf("Apellidos: ");
			fgets(empleados[i].apellidos, LARGOCAMPOSTEXTO, stdin);
			fflush(stdin);
		} while (!esCadenaValida(empleados[i].apellidos));
		do
		{
			printf("Nombres: ");
			fgets(empleados[i].nombres, LARGOCAMPOSTEXTO, stdin);
			fflush(stdin);
		} while (!esCadenaValida(empleados[i].nombres));
		printf("Dia de nacimiento: ");
		scanf("%d", &empleados[i].fecha.dia);
		fflush(stdin);
		printf("Mes de nacimiento: ");
		scanf("%d", &empleados[i].fecha.mes);
		fflush(stdin);
		printf("Anio de nacimiento: ");
		scanf("%d", &empleados[i].fecha.anio);
		validarFecha(&empleados[i].fecha.dia, &empleados[i].fecha.mes, &empleados[i].fecha.anio);
		fflush(stdin);

		printf("Sexo: ");
		scanf(" %c", &empleados[i].sexo);
		fflush(stdin);
		empleados[i].sexo = validarSexo(empleados[i].sexo);

		cargarNacionalidad(empleados[i].nacionalidades);

		i++;
		printf("Otro empleado? (s para continuar): ");
		scanf(" %c", &seguimos);
		fflush(stdin);
	} while ((seguimos == 's') && (i < 100));
	*maximoLogico = i;
	return;
}

int esCadenaValida(char texto[LARGOCAMPOSTEXTO])
{
	int esValida = 1;
	int i = 0;
	if (texto[0] <= 32)
		esValida = 0; // si comienza con espacio o la cadena es vacia no es valida
	while (esValida && (texto[i] != 10) && (texto[i] != 0))
	{ // mientras las letras sean validas y no llegamos al final, continua recorriendo la cadena
		if ((texto[i] >= 97) && (texto[i] <= 122))
		{ // si es una letra en minuscula pasar a mayuscula
			texto[i] -= 32;
		}
		else
		{
			if (((texto[i] < 65) || (texto[i] > 90)) && (texto[i] != 32))
			{ // si la letra no es una mayuscula o espacio no es valida
				esValida = 0;
				printf("Solo letras no regionales y espacios por favor\n");
			}
		}
		i++;
	}
	texto[i] = 0; // le quita el new line
	return esValida;
}

void cargarNacionalidad(tVectorNacionalidades nacEmpleados)
{
	int i;
	int nacionalidad;
	char seguimos;
	i = 0;
	do
	{
		printf("Nacionalidad: \n");
		printf("1. Argentina \n2. Uruguaya\n3. Chilena\n4. Peruana\n5. Boliviana \n6. Paraguaya\n7. Brasilera\n");
		scanf("%i", &nacionalidad);
		fflush(stdin);
		validarnacionalidad(&nacionalidad);
		nacEmpleados[nacionalidad - 1] = 1; // colocamos un 1 en la posicion correspondiente del vector nacionalidades
		i++;
		printf("Otra nacionalidad (s/n)? ");
		fflush(stdin);
		scanf("%c", &seguimos);
		while (seguimos != 's' && seguimos != 'n')
		{
			printf("El dato no es valido. Ingrese 's' o 'n': ");
			scanf("%c", &seguimos);
			fflush(stdin);
		}
	} while ((seguimos == 's') && (i < 7));
	return;
}

char validarSexo(char sexo)
{
	while ((sexo != 'm') && (sexo != 'f'))

	{
		if ((sexo != 'f' && sexo != 'm'))
		{
			printf("Sexo invalido. Ingrese 'm' o 'f' : ");
			scanf("%c", &sexo);
			fflush(stdin);
		}
	}
	sexo -= 32; // pasamos a may�sculas
	return sexo;
}
void validarFecha(int *dia, int *mes, int *anio)
{
	int correcto;
	correcto = 0;
	while (correcto == 0)
	{
		if (*mes >= 1 && *mes <= 12)
		{

			switch (*mes)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (*dia >= 1 && *dia <= 31)
				{

					correcto = 1;
				}
				else
				{
					correcto = 0;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (*dia >= 1 && *dia <= 30)
				{
					correcto = 1;
				}
				else
				{
					correcto = 0;
				}
				break;
			case 2:
				if (*anio % 4 == 0 && *anio % 100 != 0 || *anio % 400 == 0)
					if (*dia >= 1 && *dia <= 29)
						correcto = 1;
					else
						correcto = 0;
				else if (*dia >= 1 && *dia <= 28)
					correcto = 1;
				else
					correcto = 0;
			}
		}
		else
			correcto = 0;

		if (correcto == 0 || (*anio > ANIOACTUAL || *anio < 1900))
		{
			printf("Fecha invalida. Ingrese otra (DD/MM/AAAA)\n");

			fflush(stdin);
			printf("Dia de nacimiento: ");
			scanf("%i", &(*dia));
			fflush(stdin);
			printf("Mes de nacimiento: ");
			scanf("%i", &(*mes));
			fflush(stdin);
			printf("Anio de nacimiento: ");
			scanf("%i", &(*anio));
			fflush(stdin);
			correcto = 0;
		}
	}
}
void validarnacionalidad(int *numNacionalidad)
{
	while (*numNacionalidad > 7 || *numNacionalidad < 1)
	{
		printf("El dato ingresado es invalido. Ingrese un numero entre 1 y 7: \n");
		scanf("%i", numNacionalidad);
		fflush(stdin);
	}
}
