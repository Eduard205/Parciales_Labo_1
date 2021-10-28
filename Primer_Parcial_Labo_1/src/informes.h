/*
 * informes.h
 *
 *  Biblioteca de funciones para informes con las entidades eSalon y eArcade.
 *      Author: eduar
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "utn.h"
#include "eSalon.h"
#include "eArcade.h"

 int mostrarSalonesConMasArcades(eSalon cadenaSalon[], int tamSalon, eArcade cadenaArcade[], int tamArcade);
 int mostrarArcadesPorCantidadDeJugadores(eArcade cadenaArcade[], int tamArcade);
 void mostrarUnArcade_ConDatosParaInformes(eArcade cadena);
 void mostrarUnSalonConSusArcades(eSalon cadenaSalon, int cantidadDeArcades);
 int mostrarPorIdSalonesConArcades(eSalon cadenaSalon[], int tamSalon, eArcade cadenaArcade[], int tamArcade);
 int mostrarArcadesDeUnSalon(eSalon cadenaSalon[], int tamSalon, eArcade cadenaArcade[], int tamArcade);
 int mostrarSalonesConMasArcadesAux(eSalon cadenaSalon[], int tamSalon, eArcade cadenaArcade[], int tamArcade);
 int imprimnirPromedioDeAracdesPorSalon(eSalon cadenaSalon[], int tamSalon, eArcade cadenaArcade[], int tamArcade);
 int imprimirCantidadDeArcadesPorJuego(eArcade cadenaArcade[], int tamArcade);


#endif /* INFORMES_H_ */
