/*
 ============================================================================
 Name        : Primer_Parcial_Labo_1.c
 Author      : Eduard Brito Hernandez
 Division    : 1-H
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "utn.h"
#include "eSalon.h"
#include "eArcade.h"
#include "informes.h"
#define CANT_SALONES 100
#define CANT_ARCADES 1000

int main(void) {
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	eArcade listaArcades[CANT_ARCADES];
	int opcion;
	int subOpcionMenu;
	char resp = 's';
	int posicion;
	int idSalonEliminado;
	int idSalonValidado;
	int flagAltaSalon = 1;
	int flagArcadeAlta = 1;

	inicializarSalon(listaSalones, CANT_SALONES);
	inicializarArcade(listaArcades, CANT_ARCADES);

	salon_altaForzada(listaSalones, 0, "SALON A", "CABA", SHOPPING);
	salon_altaForzada(listaSalones, 1, "SALON B", "NORDELTA", LOCAL);
	salon_altaForzada(listaSalones, 2, "SALON C", "MARTINEZ", LOCAL);
	salon_altaForzada(listaSalones, 3, "SALON D", "ROSARIO", SHOPPING);
	//mostrarSalones(listaSalones, CANT_SALONES);

	arcade_altaForzada(listaArcades, 0, 1, "EEUU", "CALL DUTY", 3, 100,
			ESTEREO);
	arcade_altaForzada(listaArcades, 1, 1, "JAPON", "POKEMON", 3, 200, MONO);
	arcade_altaForzada(listaArcades, 2, 1, "CHINA", "PACMAN", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 3, 1, "JAPON", "KIRBY", 3, 200, MONO);
	arcade_altaForzada(listaArcades, 4, 1, "CHINA", "MATROI", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 5, 1, "PERU", "MARIO", 3, 100, ESTEREO);
	arcade_altaForzada(listaArcades, 6, 1, "JAPON", "ZELDA", 3, 200, MONO);
	arcade_altaForzada(listaArcades, 7, 1, "CHINA", "TETRIS", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 8, 2, "JAPON", "DIGIMON", 3, 200, MONO);
	arcade_altaForzada(listaArcades, 9, 2, "CHINA", "CONTRA", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 10, 2, "CHINA", "CONTRA", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 11, 2, "CHINA", "POKEMON", 3, 150,
			ESTEREO);
	arcade_altaForzada(listaArcades, 12, 2, "CHINA", "CONTRA", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 13, 2, "CHINA", "CONTRA", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 14, 2, "CHINA", "CONTRA", 3, 150, ESTEREO);
	arcade_altaForzada(listaArcades, 15, 3, "CHINA", "CONTRA", 3, 150, ESTEREO);
	//mostrarArcades(listaArcades, CANT_ARCADES);

	do {
		mostrarMenu(&opcion);

		switch (opcion) {

		case 1:
			if (buscarLibreSalon(listaSalones, &posicion, CANT_SALONES) != -1) {
				if (altaSalon(listaSalones, posicion) == 1) {
					flagAltaSalon = 1;
				} else {
					printf("Error en el alta");
				}
			}
			break;

		case 2:
			if (flagAltaSalon == 1) {
				imprimirSalonesParaElimar(listaSalones, CANT_SALONES);
				if (bajaSalon(listaSalones, CANT_SALONES, &idSalonEliminado)
						== 1) {
					bajaArcadesPorIdSalon(listaArcades, CANT_ARCADES,
							idSalonEliminado);
				}
			} else {
				printf("No ha dado de alta Salones, ingrese a la opci?n 1");
			}

			break;

		case 3:
			if (flagAltaSalon == 1) {
				if (mostrarSalones(listaSalones, CANT_SALONES) == 0) {
					printf("Error, NO se encontraron Salones para imprimir");
				}
			} else {
				printf("No ha dado de alta Salones, ingrese a la opci?n 1");
			}
			break;
		case 4:
			if (flagAltaSalon == 1) {
				if (buscarLibreArcade(listaArcades, &posicion, CANT_ARCADES)
						!= -1
						&& salon_Obtener_idSalon(listaSalones, CANT_SALONES,
								&idSalonValidado) == 1) {

					if (altaArcade(listaArcades, posicion, &idSalonValidado)
							== 1) {
						flagArcadeAlta = 1;
					} else {
						printf("Error en el alta");
					}
				}
			} else {
				printf("No han dado de alta SALONES, ingrese a la opci?n 1");
			}

			break;

		case 5:
			if (flagArcadeAlta == 1) {
				mostrarArcades(listaArcades, CANT_ARCADES);
				modificarArcade(listaArcades, CANT_ARCADES);
			} else {
				printf("No han dado de ARCADES, ingrese a la opci?n 4");
			}
			break;

		case 6:
			if (flagArcadeAlta == 1) {
				mostrarArcades(listaArcades, CANT_ARCADES);
				bajaArcade(listaArcades, CANT_ARCADES);
			} else {
				printf("No han dado de ARCADES, ingrese a la opci?n 4");
			}
			break;

		case 7:
			if (flagArcadeAlta == 1) {
				mostrarArcades(listaArcades, CANT_ARCADES);
			} else {
				printf("No han dado de ARCADES, ingrese a la opci?n 4");
			}
			break;

		case 8:
			if (flagArcadeAlta == 1) {
				arcades_ListarJuegos(listaArcades, CANT_ARCADES);
			} else {
				printf("No han dado de alta ARCADES, ingrese a la opci?n 4");
			}

			break;

		case 9:
			if (flagAltaSalon == 1 && flagArcadeAlta == 1) {

				mostrarSubMenu(&subOpcionMenu);

				switch (subOpcionMenu) {

				case 1:
					mostrarSalonesConMasArcades(listaSalones, CANT_SALONES,
							listaArcades, CANT_ARCADES);

					break;

				case 2:

					mostrarArcadesPorCantidadDeJugadores(listaArcades,
							CANT_ARCADES);

					break;

				case 3:

					mostrarPorIdSalonesConArcades(listaSalones, CANT_SALONES,
							listaArcades, CANT_ARCADES);

					break;

				case 4:

					mostrarArcadesDeUnSalon(listaSalones, CANT_SALONES,
							listaArcades, CANT_ARCADES);

					break;

				case 5:

					break;

				case 6:

					break;

				case 7:
					imprimirCantidadDeArcadesPorJuego(listaArcades,
							CANT_ARCADES);

					break;

				case 8:
					mostrarSalonesConMasArcadesAux(listaSalones, CANT_SALONES,
							listaArcades, CANT_ARCADES);

					break;

				case 9:
					imprimnirPromedioDeAracdesPorSalon(listaSalones,
							CANT_SALONES, listaArcades, CANT_ARCADES);

					break;

				case 10:
					printf("A salido del programa");
					resp = !'s';
					break;

				}
			} else {
				printf(
						"No han dado de alta SALONES ni ARCADES, ingrese a la opci?n 1 y 4");
			}
			break;

		case 10:
			printf("A salido del programa");
			resp = !'s';
			break;

		}
	} while (resp == 's');

	return EXIT_SUCCESS;
}
