/*
 * ePantalla.c
 *Desarrollo de funciones de la biblioteca ePantalla.h
 */

#include "ePantalla.h"

static int obtenerId(void);

static int obtenerId(void) {

	static int contador = 1;

	return (contador++);
}

int inicializarPantalla(ePantalla array[], int tam) {
	int devolucion = -1;
	if (array != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			array[i].isEmpty = 1;
			array[i].id = 0;
			strcpy(array[i].nombre, " ");
			strcpy(array[i].direccion, " ");
			array[i].tipo = 0;
			array[i].precio = 0;
		}
		devolucion = 0;
	}
	return devolucion;
}

int buscarLibrePantalla(ePantalla array[], int *posicion, int tam) {

	int rtn = -1;
	if (array != NULL && posicion != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (array[i].isEmpty == 1) {
				*posicion = i;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

int altaPantalla(ePantalla array[], int posicion) {

	int rtn = 0;
	char auxChar1[100];
	char auxChar2[100];
	int auxInt;
	float auxFloat;

	if (pedirCadena(auxChar1, 10, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1) {

		if (pedirCadena(auxChar2, 10, 3, "Ingrese direccion: ",
				"Error reingrese direccion: ") == 1) {

			if (pedirEntero(&auxInt, 1, 5, 3, "Ingrese Tipo: ",
					"Error reingrese tipo: ") == 1) {

				if (pedirFlotante(&auxFloat, 3, "Ingrese precio: ",
						"Error reingrese precio: ") == 1) {

					array[posicion].id = obtenerId();
					strcpy(array[posicion].direccion, auxChar2);
					strcpy(array[posicion].nombre, auxChar1);
					array[posicion].tipo = auxInt;
					array[posicion].precio = auxFloat;
					array[posicion].isEmpty = 0;
					rtn = 1;

					printf("Id Pantalla: %d\n", array[posicion].id);
					printf("Nombre: %s\n", array[posicion].nombre);
					printf("Direccion: %s\n", array[posicion].direccion);
					printf("Tipo: %d\n", array[posicion].tipo);
					printf("Precio: %.2f\n", array[posicion].precio);
				}
			}
		}

	}

	//printf("isEmpty: %d\n", array[posicion].isEmpty);

	return rtn;
}

int buscarPantalla(ePantalla array[], int tam, int id) {
	int rtn = -1;
	int i;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].id == id && array[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int modificarUnaPantalla(ePantalla *array) {

	int rtn = 0;
	char auxChar1[100];
	char auxChar2[100];
	int auxInt;
	float auxFloat;

	if (pedirCadena(auxChar1, 10, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1) {

		if (pedirCadena(auxChar2, 10, 3, "Ingrese direccion: ",
				"Error reingrese direccion: ") == 1) {

			if (pedirEntero(&auxInt, 1, 5, 3, "Ingrese Tipo: ",
					"Error reingrese tipo: ") == 1) {

				if (pedirFlotante(&auxFloat, 3, "Ingrese precio: ",
						"Error reingrese precio: ") == 1) {

					strcpy(array->direccion, auxChar2);
					strcpy(array->nombre, auxChar1);
					array->tipo = auxInt;
					array->precio = auxFloat;
					rtn = 1;
				}
			}
		}

	}
	return rtn;
}

int modificarPantalla(ePantalla array[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3,
			"Ingrese el id de la pantalla a modificar: ",
			"Error. Ingrese un Id de pantalla entre (1-100): ") == 1) {
		if (buscarPantalla(array, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarPantalla(array, tam, idAux);
			if (modificarUnaPantalla(&array[posicion]) == 1) {
				rtn = 1;
			} else {
				printf("Error, no se modificaron los campos");
			}
		}
	}

	if (rtn == 1) {
		printf("Se modifico la pantalla con el id %d\n", array[posicion].id);
		printf("Nuevo Nombre: %s\n", array[posicion].nombre);
		printf("Nuevo direccion: %s\n", array[posicion].direccion);
		printf("Nuevo tipo: %d\n", array[posicion].tipo);
		printf("Nuevo precio: %.2f\n", array[posicion].precio);
	}

	return rtn;
}

int bajaPantalla(ePantalla array[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3,
			"Ingrese el id de la pantalla a dar de baja: ",
			"Error. Ingrese un Id de pantalla entre (1-100): ") == 1) {
		if (buscarPantalla(array, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarPantalla(array, tam, idAux);
			array[posicion].isEmpty = 1;
			rtn = 1;
		}
	}

	if (rtn == 1) {
		printf("Se dio de baja a la pantalla con el id %d\n",
				array[posicion].id);
		printf("Nombre: %s\n", array[posicion].nombre);
		printf("Direccion: %s\n", array[posicion].direccion);
		printf("Tipo: %d\n", array[posicion].tipo);
		printf("Precio: %.2f\n", array[posicion].precio);
	}

	return rtn;
}

void mostrarUnaPantalla(ePantalla array) {

	printf("%5d%10s%10s%7d%13.2f\n", array.id, array.nombre, array.direccion,
			array.tipo, array.precio);

}

int mostrarPantallas(ePantalla array[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t> LISTADO PANTALLAS\n");
	printf("%5s%10s%10s%10s%9s\n", "ID", "NOMBRE", "DIRECCION", "TIPO",
			"PRECIO");

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].isEmpty == 0) {
				mostrarUnaPantalla(array[i]);
				rtn++;
			}
		}

	}
	return rtn;
}

int ordenarPantallas(ePantalla array[], int tam, int criterio) {

	int rtn = 0;
	int i;
	int j;
	ePantalla aux;

	if (array != NULL && tam > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (array[i].isEmpty == 0 && array[j].isEmpty == 0) {
						if (array[i].tipo > array[j].tipo) {
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (array[i].isEmpty == 0 && array[j].isEmpty == 0) {
						if (array[i].tipo < array[j].tipo) {
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
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
