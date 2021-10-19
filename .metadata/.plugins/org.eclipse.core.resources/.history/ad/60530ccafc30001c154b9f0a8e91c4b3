/*
 * informes.c
 *
 *  Desarrollo de las funciones de la biblioteca informes.
 *      Author: Eduard Brito
 */
#include "informes.h"

int mostrarSalonesConMasArcades(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {
	int i;
	int rtn = 0;
	int j;
	int contadorArcades;

	printf("\n\t**********LISTADO DE SALONES**********\n");

	if (cadenaSalon != NULL && tamSalon > 0 && cadenaArcade != NULL
			&& tamArcade > 0) {

		for (i = 0; i < tamSalon; i++) {

			if (cadenaSalon[i].isEmpty == OCUPADO) {

				for (j = 0; j < tamArcade; j++) {

					if (cadenaArcade[j].isEmpty == OCUPADO
							&& cadenaArcade[j].idSalon
									== cadenaSalon[i].idSalon) {
						contadorArcades++;

						if (contadorArcades > 4) {
							mostrarUnSalon(cadenaSalon[i]);
							rtn++;
						}
					}

				}

			}
		}
	}
	return rtn;
}
