#include<allegro5/allegro.h>
#include<allegro5/color.h>
#include <vector>
#include "Explosion.h"
#include "Enemigos.h"
#include "Ajustes.h"
void GenerarExplosion(std::vector<PtrEnemigo>& Enemigos, std::vector<PtrExplosion>& Explosiones) {
	for (int i = 0; i < Enemigos.size(); i++) {
		PtrEnemigo enemigo = Enemigos[i];
		if (enemigo->Colision == true) { //inicializacion de una nueva explocion
			PtrExplosion explosion = new(Explosion);
			explosion->X = enemigo->X;
			explosion->Y = enemigo->Y;
			explosion->index = 0;
			explosion->segundo_indice = 0;
			explosion->delay = duracion;
			explosion->activa = true;
			explosion->size = enemigo->size;
			Explosiones.push_back(explosion); //encolamos la explocion
		}
	}
}
void AnimarExplosion(std::vector<PtrExplosion>& Explosiones) {
	for (int i = 0; i < Explosiones.size(); i++) {
		PtrExplosion explosion = Explosiones[i];
		if (explosion->segundo_indice > 5) {
			explosion->activa = false; //cuando se mostraron todas las imagenes, se desactiva la explocion
		}
		if (explosion->activa) {
			explosion->segundo_indice += explosion->delay; //sumamos al indice decimal 0.2, asi las animaciones no corren tan rapido
			explosion->index = explosion->segundo_indice; // actualizamos el indice entero
		}


	}
}


void DrawExplosion(ALLEGRO_BITMAP* Imagenes[6], std::vector<PtrExplosion>& Explosiones) {
	for (int i = 0; i < Explosiones.size(); i++) {
		al_draw_scaled_bitmap(
			Imagenes[Explosiones[i]->index], //imagen a mostrar (Frame de la explocion)
			0, 0, //se pinta toda la imagen
			al_get_bitmap_width(Imagenes[Explosiones[i]->index]), al_get_bitmap_height(Imagenes[Explosiones[i]->index]), //alto y ancho de la explocion
			Explosiones[i]->X - 100, Explosiones[i]->Y - 100, //coordenadas en las que se pinta la explosion
			al_get_bitmap_width(Imagenes[Explosiones[i]->index]) * 3, al_get_bitmap_height(Imagenes[Explosiones[i]->index]) * 3, //aumentamos el alto y ancho de la explosion en un factor de tres
			NULL
		);
	}
}



void BorrarExplosiones(std::vector<PtrExplosion>& Explosiones) {
	for (int i = 0; i < Explosiones.size(); i++) {
		if (Explosiones[i]->activa == false) { //se borran de memoria las explociones vencidas
			std::vector<PtrExplosion>::iterator IteradorExplosion = Explosiones.begin() + i; 
			Explosiones.erase(IteradorExplosion);
		}
	}
}