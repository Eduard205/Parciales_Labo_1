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
#include "ePantalla.h"
//#include "eContratacion.h"
#define TAM 100

int main(void) {
	setbuf(stdout, NULL);

	ePantalla listaPantallas[TAM];
	//eContratacion listaContrataciones[TAM];
	int opcion;
	char resp= 's';
	int posicion;
	int criterioDeOrdenamiento;
	int flagOpcion1 = 0;

	//char cuit[14];

	inicializarPantalla(listaPantallas, TAM);
//	inicializarContratacion(listaContrataciones, TAM);
	//utn_pedirCuit(cuit,"\nIngrese CUIT: ", "\nError en ingreso de CUIT: ", 3);
	//printf("\n%s",cuit);

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
						"Ingreso una opción invalida, las opciones disponibles son (1, 2, 3, 4, 5): ");
				scanf("%d", &opcion);
			}
*/
			switch (opcion) {

			case 1:
				 if(buscarLibrePantalla(listaPantallas, &posicion, TAM) != -1)
					{
						if(altaPantalla(listaPantallas, posicion)==1){
							flagOpcion1 = 1;
						}
						else{
							printf("Error en el alta");
						}
					}
				break;


			case 2:
				if(flagOpcion1 ==1){
				if(modificarPantalla(listaPantallas, TAM)==0){
					printf("\nError, NO se modifico la pantalla");
				}
				}
				else{
					printf("No ha dado de alta pantallas, ingrese a la opción 1");
				}
				break;

			case 3:
				if(flagOpcion1 ==1){
				if(bajaPantalla(listaPantallas, TAM)==0){
					printf("Error, NO se dio de baja la pantalla");
				}
				}
				else{
					printf("No ha dado de alta pantallas, ingrese a la opción 1");
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

				ordenarPantallas(listaPantallas, TAM, criterioDeOrdenamiento);
				if(mostrarPantallas(listaPantallas, TAM)){
					system("pause");
				}
				else{
						printf("No hay pantallas para mostrar");
				}
				}
				else{
				printf("No ha dado de alta pantallas, ingrese a la opción 1");
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
