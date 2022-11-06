#include "Bala.h"
#include <allegro5/allegro_color.h>

#include "Ajustes.h"
#include <math.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>

void EncolarBala(std::vector<PtrBala>& Balas, PtrBala& NuevaBala) { //Funcion que encola las balas
	Balas.push_back(NuevaBala);
}
void BorrarPosicion(std::vector<PtrBala>& Balas) {
	for (int i = 0; i < Balas.size(); i++) {
		if (Balas[i]->activa == false) { //se borran las balas desactivadas
			std::vector<PtrBala>::iterator IteradorBala = Balas.begin() + i;
			Balas.erase(IteradorBala);
		}
	}
}
void CrearBala(Jugador jugador, std::vector<PtrBala>& Balas) {
	al_install_audio();

	ALLEGRO_SAMPLE* Disparos = al_load_sample("Musica/Disparo.wav");
	al_play_sample(Disparos, 0.3, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	//inicializa una nueva bala
	PtrBala NuevaBala = new(Bala);
	NuevaBala->activa = true;
	NuevaBala->Angulo = jugador.angulo; //la bala y el jugador siempre tienen el mismo angulo cuando ocurre el disparo
	NuevaBala->Velociad = VELOCIDAD_BALA;
	NuevaBala->X = jugador.X;
	NuevaBala->Y = jugador.Y;
	EncolarBala(Balas, NuevaBala);
}

void CheckBorde(PtrBala& Aux) { 
	if ((Aux)->X >= ANCHO_PANTALLA || (Aux)->X <= 0) { //si la bala se salio por los bordes derechos o izquierdos de la pantalla
		(Aux)->activa = false;
	}
	if ((Aux)->Y >= ALTO_PANTALLA || (Aux)->Y <= 0) {//si la bala se salio por el borde superior o inferior
		(Aux)->activa = false;
	}
}
void Actualizar(std::vector<PtrBala>& Balas) {
	for (auto&& BalasIter : Balas) {
		(BalasIter)->Y += (BalasIter)->Velociad * -cos((BalasIter)->Angulo); //Movemos a la bala en X
		(BalasIter)->X += (BalasIter)->Velociad * sin((BalasIter)->Angulo); // EN Y
		CheckBorde(BalasIter);
	}
}

void DrawBala(std::vector<PtrBala>& Balas, ALLEGRO_BITMAP*& Imagen) {
	for (std::vector<PtrBala>::iterator BalasIter = Balas.begin(); BalasIter != Balas.end(); BalasIter++) {
		al_draw_rotated_bitmap(
			Imagen, //imagen a dibujar
			al_get_bitmap_width(Imagen) / 2, al_get_bitmap_height(Imagen) / 2, //obtenemos el centro de la bala
			(*BalasIter)->X, (*BalasIter)->Y, //se coloca en el X y Y del jugasdor
			(*BalasIter)->Angulo, //se dibuja con el angulo asignado
			0);
	}

}
