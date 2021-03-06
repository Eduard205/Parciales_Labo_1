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

int salon_Obtener_idSalon(eSalon cadena[], int tam, int *idSalonValidado){

	int rtn=0;
	eSalon bufferAux;

	if (pedirEntero(&bufferAux.idSalon, 1, 100, 3, "Ingrese Id del Salon: ",
				"Error, reingrese Id del Salon: ") == 1 && buscarSalon(cadena,tam, bufferAux.idSalon)!=-1){

			*idSalonValidado= bufferAux.idSalon;
			rtn=1;

		printf("El ID de Salon (%d) es VALIDO\n", *idSalonValidado);

		}
	else{
		printf("El ID de Salon ingresado NO existe");
	}

	return rtn;
}

int altaSalon(eSalon cadena[], int posicion) {

	int rtn = 0;
	eSalon buffer;

	if (pedirCadena(buffer.nombre, NOMBRE_LEN, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1
			&& pedirCadena(buffer.direccion, DIRECCION_LEN, 3,
					"Ingrese direccion: ", "Error reingrese direccion: ") == 1
			&& pedirEntero(&buffer.tipoDeSalon, 1, 2, 3,
					"Ingrese Tipo (1-Shopping, 2-Local): ",
					"Error reingrese tipo (1-Shopping, 2-Local): ") == 1) {

		buffer.idSalon = obtenerId();
		cadena[posicion] = buffer;
		cadena[posicion].isEmpty = 0;
		rtn = 1;
		}

	if (rtn == 1) {
		printf("Salon dado de alta\n");
		mostrarUnSalon(cadena[posicion]);
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

int modificarUnSalon(eSalon *cadena/*int posicion*/) {

	int rtn = 0;

	if (pedirCadena(cadena->nombre, NOMBRE_LEN, 3, "Ingrese nombre: ",
			"Error reingrese nombre: ") == 1
			&& pedirCadena(cadena->direccion, DIRECCION_LEN, 3,
					"Ingrese direccion: ", "Error reingrese direccion: ") == 1
			&& pedirEntero(&cadena->tipoDeSalon, 1, 2, 3,
					"Ingrese Tipo (1-Shopping, 2-Local): ",
					"Error reingrese tipo (1-Shopping, 2-Local): ") == 1) {

					rtn = 1;
	}

	return rtn;
}

int modificarSalon(eSalon cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3, "Ingrese el id del Salon a modificar: ",
			"Error. Ingrese un Id de Salon entre (1-100): ") == 1
			&& buscarSalon(cadena, tam, idAux) != -1) {

		posicion = buscarSalon(cadena, tam, idAux);
		if (modificarUnSalon(&cadena[posicion]) == 1) {
			rtn = 1;
		} else {
			printf("Error, no se modificaron los campos");
			rtn = 0;
		}

	} else {
		printf("No existe el id ingresado\n ");
		rtn = 0;
	}

	if (rtn == 1) {
		printf("Se modifico el Salon con el id %d\n", cadena[posicion].idSalon);
		printf("Nuevo Nombre: %s\n", cadena[posicion].nombre);
		printf("Nuevo direccion: %s\n", cadena[posicion].direccion);
		printf("Nuevo tipo: %d\n", cadena[posicion].tipoDeSalon);

	}

	return rtn;
}

int bajaSalon(eSalon cadena[], int tam, int* idSalonEliminado) {

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
			*idSalonEliminado =idAux;
			rtn = 1;
		}
	}

	if (rtn == 1) {
		printf("Se dio de baja al Salon con el id %d\n",
				cadena[posicion].idSalon);

	}else{
		printf("Error, NO se dio de baja al Salon");
	}

	return rtn;
}

void mostrarUnSalon(eSalon cadena) {

	printf("ID SALON: %d - NOMBRE: %s - DIRECCION: %s - TIPO DE SALON: %d\n",
			cadena.idSalon, cadena.nombre, cadena.direccion,
			cadena.tipoDeSalon);

}

int mostrarSalones(eSalon cadena[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t**********LISTADO DE SALONES**********\n");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == OCUPADO) {
				mostrarUnSalon(cadena[i]);
				rtn++;
			}
		}
	}
	return rtn;
}

void imprimirUnSalonParaEliminar(eSalon cadena) {

	printf("ID SALON: %d - NOMBRE: %s - DIRECCION: %s\n",
			cadena.idSalon, cadena.nombre, cadena.direccion);

}

int imprimirSalonesParaElimar(eSalon cadena[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t**********LISTADO DE SALONES**********\n");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == 0) {
				imprimirUnSalonParaEliminar(cadena[i]);
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


int salon_altaForzada(eSalon cadena[], int posicion, char *nombre, char *direccion, int tipoDeSalon) {

	int rtn = 0;
	eSalon bufferAux;

	if (cadena != NULL && posicion>=0 && nombre != NULL
			&& direccion != NULL && tipoDeSalon > 0) {

		bufferAux.idSalon = obtenerId();
		strncpy(bufferAux.nombre, nombre, NOMBRE_LEN);
		strncpy(bufferAux.direccion, direccion, DIRECCION_LEN);
		bufferAux.tipoDeSalon = tipoDeSalon;
		bufferAux.isEmpty = 0;
		cadena[posicion] = bufferAux;
		rtn = 1;
	}
	return rtn;
}
