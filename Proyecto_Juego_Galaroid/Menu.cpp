
#include "Menu.h"
#include "Ajustes.h"






void instrucciones(ALLEGRO_EVENT_QUEUE* cola_eventos, ALLEGRO_FONT* fuente1) { //En esta funci?n, unicamente se imprimen als instrucciones generales del juego.

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	al_register_event_source(cola_eventos, al_get_timer_event_source(timer));

	bool comojugar = true;

	while (comojugar) {
		ALLEGRO_EVENT Evento;
		al_wait_for_event(cola_eventos, &Evento);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		//Se imprimen las instrucciones.

		al_draw_textf(fuente1, al_map_rgb(255, 255, 255), ANCHO_PANTALLA / 2.0, (ALTO_PANTALLA) / 20, ALLEGRO_ALIGN_CENTER, "Bienvenido a Galaroid");
		al_draw_textf(fuente1, al_map_rgb(255, 255, 255), ANCHO_PANTALLA / 2.0, ((ALTO_PANTALLA) / 20) * 10, ALLEGRO_ALIGN_CENTER, "En este juego debes destuir meteoritos al dispararles con la nave.");
		al_draw_textf(fuente1, al_map_rgb(255, 255, 255), ANCHO_PANTALLA / 2.0, ((ALTO_PANTALLA) / 20) * 11, ALLEGRO_ALIGN_CENTER, "Esta se controla con las flechas del teclado y con la tecla de espacio se dispara.");
		al_draw_textf(fuente1, al_map_rgb(255, 255, 255), ANCHO_PANTALLA / 2.0, ((ALTO_PANTALLA) / 20) * 12, ALLEGRO_ALIGN_CENTER, "Cambiando el angulo de la nave con las fleachas horizontales y propulsando con la flecha vertical superior");
		al_draw_textf(fuente1, al_map_rgb(255, 255, 255), ANCHO_PANTALLA / 2.0, ALTO_PANTALLA / 12 * 10, ALLEGRO_ALIGN_CENTER, "Presione ESC para volver al menu");
		if (Evento.type = ALLEGRO_EVENT_KEY_DOWN) {

			if (Evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {

				comojugar = false;

			}

		}
		al_flip_display();


	}

}
