/*
 * eSalon.c
 *Desarrollo de funciones de la biblioteca eSalon.h
 */

#include "eSalon.h"

static int obtenerId(void);

static int obtenerId(void) {

	static int contador = 1;

	return (contador++);
}

int inicializarSalon(eSalon cadena[], int tam) {
	int devolucion = -1;
	if (cadena != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			cadena[i].isEmpty = 1;
			cadena[i].idSalon = 0;
			strcpy(cadena[i].nombre, " ");
			strcpy(cadena[i].direccion, " ");
			cadena[i].tipoDeSalon = 0;

		}
		devolucion = 0;
	}
	return devolucion;
}

int buscarLibreSalon(eSalon cadena[], int *posicion, int tam) {

	int rtn = -1;
	if (cadena != NULL && posicion != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == 1) {
				*posicion = i;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

int altaSalon(eSalon cadena[], int posicion) {

	int rtn = 0;
	char auxChar1[100];
	char auxChar2[100];
	int auxInt;


	if (pedirCadena(auxChar1, 10, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1) {

		if (pedirCadena(auxChar2, 15, 3, "Ingrese direccion: ",
				"Error reingrese direccion: ") == 1) {

			if (pedirEntero(&auxInt, 1, 2, 3, "Ingrese Tipo (1-Shopping, 2-Local): ",
					"Error reingrese tipo (1-Shopping, 2-Local): ") == 1) {

					cadena[posicion].idSalon = obtenerId();
					strcpy(cadena[posicion].nombre, auxChar1);
					strcpy(cadena[posicion].direccion, auxChar2);
					cadena[posicion].tipoDeSalon = auxInt;
					cadena[posicion].isEmpty = 0;
					rtn = 1;

					printf("Id Salon: %d\n", cadena[posicion].idSalon);
					printf("Nombre: %s\n", cadena[posicion].nombre);
					printf("Direccion: %s\n", cadena[posicion].direccion);
					printf("Tipo: %d\n", cadena[posicion].tipoDeSalon);

			}
		}

	}
	return rtn;
}

int buscarSalon(eSalon cadena[], int tam, int id) {
	int rtn = -1;
	int i;

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].idSalon == id && cadena[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int modificarUnSalon(eSalon *cadena) {

	int rtn = 0;
	char auxChar1[100];
	char auxChar2[100];
	int auxInt;


	if (pedirCadena(auxChar1, 10, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1) {

		if (pedirCadena(auxChar2, 15, 3, "Ingrese direccion: ",
				"Error reingrese direccion: ") == 1) {

			if (pedirEntero(&auxInt, 1, 2, 3, "Ingrese Tipo (1-Shopping, 2-Local): ",
					"Error reingrese tipo: ") == 1) {

					strcpy(cadena->nombre, auxChar1);
					strcpy(cadena->direccion, auxChar2);
					cadena->tipoDeSalon = auxInt;
					rtn = 1;
			}
		}

	}
	return rtn;
}

int modificarSalon(eSalon cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3,
			"Ingrese el id del Salon a modificar: ",
			"Error. Ingrese un Id de Salon entre (1-100): ") == 1) {
		if (buscarSalon(cadena, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarSalon(cadena, tam, idAux);
			if (modificarUnSalon(&cadena[posicion]) == 1) {
				rtn = 1;
			} else {
				printf("Error, no se modificaron los campos");
			}
		}
	}

	if (rtn == 1) {
		printf("Se modifico el Salon con el id %d\n", cadena[posicion].idSalon);
		printf("Nuevo Nombre: %s\n", cadena[posicion].nombre);
		printf("Nuevo direccion: %s\n", cadena[posicion].direccion);
		printf("Nuevo tipo: %d\n", cadena[posicion].tipoDeSalon);

	}

	return rtn;
}

int bajaSalon(eSalon cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3,
			"Ingrese el id del salon a dar de baja: ",
			"Error. Ingrese un Id de salon entre (1-100): ") == 1) {
		if (buscarSalon(cadena, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarSalon(cadena, tam, idAux);
			cadena[posicion].isEmpty = 1;
			rtn = 1;
		}
	}

	if (rtn == 1) {
		printf("Se dio de baja al Salon con el id %d\n",
				cadena[posicion].idSalon);
		printf("Nombre: %s\n", cadena[posicion].nombre);
		printf("Direccion: %s\n", cadena[posicion].direccion);
		printf("Tipo: %d\n", cadena[posicion].tipoDeSalon);
	}

	return rtn;
}

void mostrarUnSalon(eSalon cadena) {

	printf("%5d%10s%10s%7d\n", cadena.idSalon, cadena.nombre, cadena.direccion,
			cadena.tipoDeSalon);

}

int mostrarSalones(eSalon cadena[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t> LISTADO DE SALONES\n");
	printf("%5s%10s%10s%10s\n", "ID", "NOMBRE", "DIRECCION", "TIPO");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == 0) {
				mostrarUnSalon(cadena[i]);
				rtn++;
			}
		}

	}
	return rtn;
}

int ordenarSalones(eSalon cadena[], int tam, int criterio) {

	int rtn = 0;
	int i;
	int j;
	eSalon aux;

	if (cadena != NULL && tam > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (cadena[i].isEmpty == 0 && cadena[j].isEmpty == 0) {
						if (cadena[i].tipoDeSalon > cadena[j].tipoDeSalon) {
							aux = cadena[i];
							cadena[i] = cadena[j];
							cadena[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (cadena[i].isEmpty == 0 && cadena[j].isEmpty == 0) {
						if (cadena[i].tipoDeSalon < cadena[j].tipoDeSalon) {
							aux = cadena[i];
							cadena[i] = cadena[j];
							cadena[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}
