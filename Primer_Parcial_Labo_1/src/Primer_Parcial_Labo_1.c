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

#include "eSalon.h"
#include "utn.h"
#include "eArcade.h"
#define CANT_SALONES 100
#define CANT_ARCADES 1000

int main(void) {
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	eArcade listaArcades[CANT_ARCADES];
	int opcion;
	char resp= 's';
	int posicion;
	int criterioDeOrdenamiento;
	int flagOpcion1 = 1;///CAMBIAR VALOR A 0 AL TERMINAR
	int idSalonEliminado;


	inicializarSalon(listaSalones, CANT_SALONES);
	inicializarArcade(listaArcades, CANT_ARCADES);

	salon_altaForzada(listaSalones, 2, "SALON A", "CABA", SHOPPING);
	salon_altaForzada(listaSalones, 1, "SALON B", "NORDELTA", LOCAL);
	salon_altaForzada(listaSalones, 0, "SALON C", "OLIVOS", SHOPPING);
	//mostrarSalones(listaSalones, CANT_SALONES);

	arcade_altaForzada(listaArcades, 2, 1, "EEUU", "CALL DUTY", 4, 100, ESTEREO);
	arcade_altaForzada(listaArcades, 0, 3, "JAPON", "POKEMON", 2, 200, MONO);
	arcade_altaForzada(listaArcades, 1, 2, "CHINA", "PACMAN", 1, 150, ESTEREO);
	mostrarArcades(listaArcades, CANT_ARCADES);


	do {
		mostrarMenu(&opcion);
		/*	printf("\nIngrese una opcion del menu:"
					"\n1-Alta de Pantalla"
					"\n2-Modificar Pantalla"
					"\n3-Baja Pantalla"
					"\n4-Informes"
					"\n5-Salir\n");
			scanf("%d", &opcion);

			while (opcion < 1 || opcion > 5) {
				printf(
						"Ingreso una opci�n invalida, las opciones disponibles son (1, 2, 3, 4, 5): ");
				scanf("%d", &opcion);
			}
*/
			switch (opcion) {

			case 1:
				 if(buscarLibreSalon(listaSalones, &posicion, CANT_SALONES) != -1)
					{
						if(altaSalon(listaSalones, posicion)==1){
							flagOpcion1 = 1;
						}
						else{
							printf("Error en el alta");
						}
					}
				 /*
				 if(buscarLibreArcade(listaArcades, &posicion, CANT_ARCADES) != -1)
				 					{
				 						if(altaArcade(listaArcades, posicion)==1){
				 							flagOpcion1 = 1;
				 						}
				 						else{
				 							printf("Error en el alta");
				 						}
				 					}
				 	*/
				break;


			case 2:
				if(flagOpcion1 ==1){
					imprimirSalonesParaElimar(listaSalones,CANT_SALONES);
					if(bajaSalon(listaSalones, CANT_SALONES,&idSalonEliminado)==1){
						bajaArcadesPorIdSalon(listaArcades, CANT_ARCADES, idSalonEliminado);
						}
					}
					else{
						printf("No ha dado de alta Salones, ingrese a la opci�n 1");
					}
				/*
				if(flagOpcion1 ==1){
				if(modificarSalon(listaSalones, CANT_SALONES)==0){
					printf("\nError, NO se modifico el Salon");
				}
				}
				else{
					printf("No ha dado de alta pantallas, ingrese a la opci�n 1");
				}
				*/
				break;

			case 3:
				if(flagOpcion1 ==1){
				if(mostrarSalones(listaSalones, CANT_SALONES)==0){
					printf("Error, NO se encontraron Salones para imprimir");
				}
				}
				else{
					printf("No ha dado de alta Salones, ingrese a la opci�n 1");
				}
				break;
			case 4:
				if(flagOpcion1 ==1){
				printf("\nIngrese criterio de ordenamiento:"
						"\n1-Ordenar de forma descendente lista de pantallas por tipo"
						"\n-1-Ordenar de forma ascendente lista de pantallas por tipo");

				scanf("%d", &criterioDeOrdenamiento);

								while (criterioDeOrdenamiento!= 1 && criterioDeOrdenamiento!=-1) {
								printf("Ingreso un criterio valido, las opciones disponibles son (1 o -1): ");
								scanf("%d", &criterioDeOrdenamiento);
										}

				ordenarSalones(listaSalones, CANT_SALONES, criterioDeOrdenamiento);
				if(mostrarSalones(listaSalones, CANT_SALONES)){
					system("pause");
				}
				else{
						printf("No hay pantallas para mostrar");
				}
				}
				else{
				printf("No ha dado de alta pantallas, ingrese a la opci�n 1");
				}
				break;


			case 5:
				printf("A salido del programa");
				resp = !'s';
				break;

		}
	}while (resp == 's');

	return EXIT_SUCCESS;
}
