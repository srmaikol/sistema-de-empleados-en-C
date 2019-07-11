# sistema-de-empleados-en-C
Proyecto realizado para la materia Algoritmos y Programación I - 2019 - Facultad de Ingeniería - Universidad de Buenos Aires

ENUNCIADO

Una empresa que se dedica a la reubicación de empleados tiene una lista de 500 empleados (como máximo) con la siguiente información:
- Nombre y apellido. Con el formato "Apellidos, Nombres". 
- Fecha de nacimiento del empleado. 
- Sexo (M, F) 
- Nacionalidad 
Las nacionalidades pueden ser: Argentina, Uruguaya, Chilena, Peruana, Boliviana, Paraguaya, Brasileña. Un empleado puede tener más de una nacionalidad. 

Se pide armar las estructuras y el programa en lenguaje C que permita:

A- Realizar la carga de datos. Validar todos los datos ingresados.

B- Mostrar un listado de personas nacidas antes de 2000 ordenado por Fecha de nacimiento. Mostrar todos los datos de cada empleado. 

C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y además nacieron en verano. Mostrar todos los datos de cada empleado. 

D- Emitir un informe de empleados uruguayos y argentinos que tengan más de una nacionalidad. Mostrar todos los datos de cada empleado. 

E- Indicar el porcentaje de empleados argentinos 

<hr>

MODULOS
Para trabajar eficientemente en equipo, distribuimos el TP varios archivos .c, uno por módulo y colocamos todas las definiciones de tipos, librerías a incluir y constantes globales en un archivo funciones.h a ser incluido en todos los módulos.

COSTANTES GLOBALES

Utilizamos sólo tres:

MAXIMOFISICO		La máxima cantidad de registros de la tabla principal

NACIONALIDADES		La cantidad de nacionalidades permitidas

LARGOCAMPOSTEXTO	El largo máximo de los strings nombres y apellidos

ESTRUCTURAS

A continuación describimos las estructuras globales utilizadas por todos los módulos.
1. Fecha
typedef struct
	{
		int dia;
		int mes;
		int anio;
	} tipoFecha;


Para las fechas utilizamos la  struct tipoFecha compuesta por los int: dia, mes y anio. Tomamos esta decisión, porque, si bien guardar las fechas en un string "yyyymmdd" facilita el ordenamiento, tener los componentes separados en forma numérica hace menos complejas las búsquedas como "nacidos en verano" o "antes del 2000".

2. Nacionalidades
	typedef int tVectorNacionalidades[NACIONALIDADES];

Luego de considerar varias alternativas, decidimos que la solución más simple para manejar las nacionalidades de cada empleado, es un vector de valores booleanos de tipo tVectorNacionalidades con tantas posiciones como empleados. Cada posición del vector representa una nacionalidad: 0 Argentina,  1 Uruguaya, 2 Chilena, 3 Peruana, 4 Boliviana, 5 Paraguaya, 6 Brasileña. Cada elemento del vector tiene un 1 si el empleado tiene la nacionalidad correspondiente a esa posición o, de lo contrario 0. Esta estructura resultó muy práctica en los módulos de carga de datos y de búsqueda de argentinos y uruguayos con múltiples nacionalidades.

3. Nombres y apellidos
char apellidos[LARGOCAMPOSTEXTO];
	char nombres[LARGOCAMPOSTEXTO];
Los nombres y los apellidos de cada registro están guardados en las cadenas apellidos y nombres de largo LARGOCAMPOSTEXTO.

4. Sexo
	char sexo;
Para guardar el sexo alcanza con un campo de tipo char sexo de un sólo caracter.

5. Registro de cada empleado
typedef struct
	{
		char apellidos[LARGOCAMPOSTEXTO];
		char nombres[LARGOCAMPOSTEXTO];
		tipoFecha fecha;
		char sexo;
		tVectorNacionalidades nacionalidades;
	} typeEmpleado;

Los datos de cada empleado se guardan en un registro de tipo typeEmpleado es una struct compuesta por las 4 estructuras y el campo char descriptos en los puntos anteriores.

6. Tabla principal de empleados
typedef typeEmpleado tVectorEmpleados[MAXIMOFISICO];

Finalmente, la tabla principal con la información de todos los empleados de la empresa, es un vector de tipo tVectorEmpleados de tamaño MAXIMOFÍSICO. Cada elemento del vector es una estructura del tipo typeEmpleado descripto en el punto anterior.
