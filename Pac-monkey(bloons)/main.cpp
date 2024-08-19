#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "wall.h"
#include "pill.h"
#include "movimento_padrao.h"
#include "monkey.h"
#include "balao.h"


using namespace std;
#define Linha 21
#define Coluna 21

//Mapa Bloons
int Mapa[Linha][Coluna] =  {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
                            {1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,0,1},
                            {1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1},
                            {1,0,0,0,6,1,0,0,0,0,0,0,0,0,0,1,5,0,0,0,1},
                            {1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1},
                            {1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1},
                            {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
                            {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
                            {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
                            {1,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0,1},
                            {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
                            {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
                            {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
                            {1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1},
                            {1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1},
                            {1,0,0,0,4,1,0,0,0,0,0,0,0,0,0,1,3,0,0,0,1},
                            {1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1},
                            {1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,0,1},
                            {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};   //Paredes - 228  Pilulas - 208


int main() {

    //Inicialização
    al_init();
    al_init_image_addon();
    al_init_font_addon(); 
    al_init_ttf_addon(); 
    al_init_acodec_addon(); 
    al_install_keyboard(); 
    bool key_w = false;
    bool key_s = false;
    bool key_a = false;
    bool key_d = false;
    const float fps = 5.0;
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / fps);

    ALLEGRO_DISPLAY* display = al_create_display(1160, 675); 
    ALLEGRO_BITMAP* image = al_load_bitmap("Sprites/fundo.jpg"); 
    ALLEGRO_BITMAP* imageParede = al_load_bitmap("Sprites/wall.png"); 
    ALLEGRO_BITMAP* imageBanana = al_load_bitmap("Sprites/pill.png"); 
    ALLEGRO_BITMAP* imageMacaco = al_load_bitmap("Sprites/Macaco.png"); 
    ALLEGRO_BITMAP* imageBalaoV = al_load_bitmap("Sprites/BalaoV.png"); 
    ALLEGRO_BITMAP* imageBalaoA = al_load_bitmap("Sprites/BalaoA.png"); 
    ALLEGRO_BITMAP* imageBalaoVd = al_load_bitmap("Sprites/BalaoVd.png"); 
    ALLEGRO_BITMAP* imagePerseguidor = al_load_bitmap("Sprites/perseguidor.png"); 
    ALLEGRO_FONT* Font = al_load_font("Fontes/04B_30__.TTF", 48, 0); 
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    bool isStarting = true;
    while (isStarting) {
        if (!al_init()) {
            al_show_native_message_box(display, "Error", "Error", "Failed to initialize Allegro!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!al_init_image_addon()) {
            al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!al_init_ttf_addon()) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_ttf_addon!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!al_init_font_addon()) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_font_addon!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!al_init_acodec_addon()) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_acodec_addon!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!al_install_keyboard()) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to install keyboard!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!display) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to create display!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!timer) {
            al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!image) {  
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/fundo.jpg!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!imageParede) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/wall.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!imageBanana) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/pill.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!imageMacaco) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/macaco.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!imageBalaoV) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/BalaoV.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
            return 0;
        }
        if (!imageBalaoA) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/BalaoA.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
            return 0;
        }
        if (!imageBalaoVd) { 
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/BalaoVd.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
            return 0;
        }
        if (!imagePerseguidor) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load Sprites/perseguidor.png!", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
            return 0;
        }
        if (!Font) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load 04B_30_.TTF!", NULL, ALLEGRO_MESSAGEBOX_ERROR); 
            return 0;
        }
        if (!event_queue) {
            al_show_native_message_box(display, "Error", "Error", "Failed to create event queue!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }

        isStarting = false;
    }

    Wall Parede[227];
    Pill Banana[207];
    Monkey Macaco;
    Balao BalaoV, BalaoA, BalaoVd, Perseguidor;
    int score = 0;
    int X = 0;
    int Y = 0;

    int Posicao = 0;
    int direcaoBalaoV = 0;
    int direcaoBalaoA = 0;
    int direcaoBalaoVd = 0;
    int sentidoBalaoV = 0;
    int sentidoBalaoVd = 0;
    int sentidoBalaoA = 0;
    bool GameOver = false;
    bool teclas[255] = { false };
    int tempo, miliseg = 200;
    bool Retry = true;
    for (int i = 0; i < Linha; i++) {    //Definindo posições
        for (int j = 0; j < Coluna; j++) {

            if (Mapa[i][j] == 1) {
                Parede[X].setX(j);
                Parede[X].setY(i);
                X++;
            }
            else if (Mapa[i][j] == 0) {

                Banana[Y].setX(j);
                Banana[Y].setY(i);
                Banana[Y].setEspacoVazio(true);
                Y++;
            }
            else if (Mapa[i][j] == 2) {
                Macaco.setPosicaoX(j);
                Macaco.setPosicaoY(i);
                               
            }
            else if (Mapa[i][j] == 3) {
                BalaoV.setPosicaoX(j);
                BalaoV.setPosicaoY(i);
            }
            else if (Mapa[i][j] == 4) {
                BalaoA.setPosicaoX(j);
                BalaoA.setPosicaoY(i);
            }
            else if (Mapa[i][j] == 5) {
                BalaoVd.setPosicaoX(j);
                BalaoVd.setPosicaoY(i);
            }
            else if (Mapa[i][j] == 6) {
                Perseguidor.setPosicaoX(j);
                Perseguidor.setPosicaoY(i);
            }
        }
    }
    al_register_event_source(event_queue, al_get_display_event_source(display));//Evento da Tela
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo
    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado
    al_flip_display();
    al_start_timer(timer);

    while (!GameOver) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        tempo = al_get_timer_count(timer);

        if (ev.type == ALLEGRO_EVENT_TIMER) {

            if ((key_w == true || teclas[ALLEGRO_KEY_W]) && ((Mapa[Macaco.getPosicaoY() - 1][Macaco.getPosicaoX()]) != 1)) {
                Posicao = Macaco.getPosicaoY(); 
                Posicao--; 
                Macaco.setPosicaoY(Posicao); 
                Posicao = 0; 
                key_w = true;
                key_a = false;
                key_s = false;
                key_d = false;
            } 
            if ((key_s == true || teclas[ALLEGRO_KEY_S]) && ((Mapa[Macaco.getPosicaoY() + 1][Macaco.getPosicaoX()]) != 1)) {
                Posicao = Macaco.getPosicaoY(); 
                Posicao++; 
                Macaco.setPosicaoY(Posicao); 
                Posicao = 0; 
                key_w = false; 
                key_a = false; 
                key_s = true;
                key_d = false; 
            }
            if ((key_a == true || teclas[ALLEGRO_KEY_A]) && ((Mapa[Macaco.getPosicaoY()][Macaco.getPosicaoX() - 1]) != 1)) {
                Posicao = Macaco.getPosicaoX(); 
                Posicao--; 
                Macaco.setPosicaoX(Posicao); 
                Posicao = 0; 
                key_w = false; 
                key_a = true;
                key_s = false; 
                key_d = false; 
            }
            if ((key_d == true || teclas[ALLEGRO_KEY_D]) && ((Mapa[Macaco.getPosicaoY()][Macaco.getPosicaoX() + 1]) != 1)) {
                Posicao = Macaco.getPosicaoX(); 
                Posicao++; 
                Macaco.setPosicaoX(Posicao); 
                Posicao = 0; 
                key_w = false; 
                key_a = false; 
                key_s = false; 
                key_d = true;
            }
            //Morte
            if (Macaco.getPosicaoX() == BalaoV.getPosicaoX() && Macaco.getPosicaoY() == BalaoV.getPosicaoY()) 
                GameOver = true;             
            if (Macaco.getPosicaoX() == BalaoA.getPosicaoX() && Macaco.getPosicaoY() == BalaoA.getPosicaoY()) 
                GameOver = true;             
            if (Macaco.getPosicaoX() == BalaoVd.getPosicaoX() && Macaco.getPosicaoY() == BalaoVd.getPosicaoY())  
                GameOver = true;             
            if (Perseguidor.getPosicaoX() == Macaco.getPosicaoX() && Perseguidor.getPosicaoY() == Macaco.getPosicaoY())  
                GameOver = true; 
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[ev.keyboard.keycode] = false;
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                GameOver = true;
        }
        if (Retry && al_is_event_queue_empty(event_queue)) {
           
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(image, 0, 0, 0);
            for (int i = 0; i < X; i++) {
                al_draw_bitmap(imageParede, Parede[i].getX() * 32, Parede[i].getY() * 32, 0);
            }
            for (int i = 0; i < Y; i++) {
                if (Banana[i].getEspacoVazio()) {
                    al_draw_bitmap(imageBanana, Banana[i].getX() * 32 + 8, Banana[i].getY() * 32 + 8, 0);
                }
            }
                direcaoBalaoV = rand() % 4;
                direcaoBalaoA = rand() % 4;
                direcaoBalaoVd = rand() % 4;

                if (sentidoBalaoV != 2 && direcaoBalaoV == 0 && Mapa[BalaoV.getPosicaoY() - 1][BalaoV.getPosicaoX()] != 1) {
                    BalaoV.setPosicaoY(BalaoV.getPosicaoY() - 1);
                    sentidoBalaoV = 1;
                }
                else if (sentidoBalaoV != 1 && direcaoBalaoV == 1 && Mapa[BalaoV.getPosicaoY() + 1][BalaoV.getPosicaoX()] != 1) {
                    BalaoV.setPosicaoY(BalaoV.getPosicaoY() + 1);
                    sentidoBalaoV = 2;
                }
                else if (sentidoBalaoV != 4 && direcaoBalaoV == 2 && Mapa[BalaoV.getPosicaoY()][BalaoV.getPosicaoX() - 1] != 1) {
                    BalaoV.setPosicaoX(BalaoV.getPosicaoX() - 1);
                    sentidoBalaoV = 3;
                }
                else if (sentidoBalaoV != 3 && direcaoBalaoV == 3 && Mapa[BalaoV.getPosicaoY()][BalaoV.getPosicaoX() + 1] != 1) {
                    BalaoV.setPosicaoX(BalaoV.getPosicaoX() + 1);
                    sentidoBalaoV = 4;
                }

                if (sentidoBalaoA != 2 && direcaoBalaoA == 0 && Mapa[BalaoA.getPosicaoY() - 1][BalaoA.getPosicaoX()] != 1) {
                    BalaoA.setPosicaoY(BalaoA.getPosicaoY() - 1);
                    sentidoBalaoA = 1;
                }
                else if (sentidoBalaoA != 1 && direcaoBalaoA == 1 && Mapa[BalaoA.getPosicaoY() + 1][BalaoA.getPosicaoX()] != 1) {
                    BalaoA.setPosicaoY(BalaoA.getPosicaoY() + 1);
                    sentidoBalaoA = 2;
                }
                else if (sentidoBalaoA != 4 && direcaoBalaoA == 2 && Mapa[BalaoA.getPosicaoY()][BalaoA.getPosicaoX() - 1] != 1) {
                    BalaoA.setPosicaoX(BalaoA.getPosicaoX() - 1);
                    sentidoBalaoA = 3;
                }
                else if (sentidoBalaoA != 3 && direcaoBalaoA == 3 && Mapa[BalaoA.getPosicaoY()][BalaoA.getPosicaoX() + 1] != 1) {
                    BalaoA.setPosicaoX(BalaoA.getPosicaoX() + 1);
                    sentidoBalaoA = 4;
                }


                if (sentidoBalaoVd != 2 && direcaoBalaoVd == 0 && Mapa[BalaoVd.getPosicaoY() - 1][BalaoVd.getPosicaoX()] != 1) {
                    BalaoVd.setPosicaoY(BalaoVd.getPosicaoY() - 1);
                    sentidoBalaoVd = 1;
                }
                else if (sentidoBalaoVd != 1 && direcaoBalaoVd == 1 && Mapa[BalaoVd.getPosicaoY() + 1][BalaoVd.getPosicaoX()] != 1) {
                    BalaoVd.setPosicaoY(BalaoVd.getPosicaoY() + 1);
                    sentidoBalaoVd = 2;
                }
                else if (sentidoBalaoVd != 4 && direcaoBalaoVd == 2 && Mapa[BalaoVd.getPosicaoY()][BalaoVd.getPosicaoX() - 1] != 1) {
                    BalaoVd.setPosicaoX(BalaoVd.getPosicaoX() - 1);
                    sentidoBalaoVd = 3;
                }
                else if (sentidoBalaoVd != 3 && direcaoBalaoVd == 3 && Mapa[BalaoVd.getPosicaoY()][BalaoVd.getPosicaoX() + 1] != 1) {
                    BalaoVd.setPosicaoX(BalaoVd.getPosicaoX() + 1);
                    sentidoBalaoVd = 4;
                }

                if (Perseguidor.getPosicaoX() < Macaco.getPosicaoX() && (Mapa[Perseguidor.getPosicaoY()][Perseguidor.getPosicaoX() + 1] != 1)) 
                    Perseguidor.setPosicaoX(Perseguidor.getPosicaoX() + 1);                
                else if (Perseguidor.getPosicaoX() > Macaco.getPosicaoX() && (Mapa[Perseguidor.getPosicaoY()][Perseguidor.getPosicaoX() - 1] != 1)) 
                    Perseguidor.setPosicaoX(Perseguidor.getPosicaoX() - 1);                
                else if (Perseguidor.getPosicaoY() < Macaco.getPosicaoY() && (Mapa[Perseguidor.getPosicaoY() + 1][Perseguidor.getPosicaoX()] != 1)) 
                    Perseguidor.setPosicaoY(Perseguidor.getPosicaoY() + 1);                
                else if (Perseguidor.getPosicaoY() > Macaco.getPosicaoY() && (Mapa[Perseguidor.getPosicaoY() - 1][Perseguidor.getPosicaoX()] != 1)) 
                    Perseguidor.setPosicaoY(Perseguidor.getPosicaoY() - 1);

            for (int i = 0; i < Y; i++) {
                if (Macaco.getPosicaoX() == Banana[i].getX() && Macaco.getPosicaoY() == Banana[i].getY()) {
                    Banana[i].setEspacoVazio(false);
                    
                    }
                }
            
        int cont = 0;
        for (int i = 0; i < Y; i++) {

            if (Banana[i].getEspacoVazio() == false) {
                cont++;
            }
        }
        score = cont;
        if (score == 207) {
            cout << "Voce Ganhou" << endl;
            GameOver = true;

        }
            al_draw_bitmap(imageMacaco, Macaco.getPosicaoX() * 32, Macaco.getPosicaoY() * 32, 0);
            al_draw_bitmap(imageBalaoV, BalaoV.getPosicaoX() * 32, BalaoV.getPosicaoY() * 32, 0);
            al_draw_bitmap(imageBalaoA, BalaoA.getPosicaoX() * 32, BalaoA.getPosicaoY() * 32, 0);
            al_draw_bitmap(imageBalaoVd, BalaoVd.getPosicaoX() * 32, BalaoVd.getPosicaoY() * 32, 0);
            al_draw_bitmap(imagePerseguidor, Perseguidor.getPosicaoX() * 32, Perseguidor.getPosicaoY() * 32, 0);
            al_draw_textf(Font, al_map_rgb(255, 255, 255), 22 * 32, 2 * 32, 0, "%s", "Pac-Monkey");
            al_draw_textf(Font, al_map_rgb(255, 255, 255), 23 * 32, 5 * 32, 0, "%s", "Score:");
            al_draw_textf(Font, al_map_rgb(255, 255, 255), 31 * 32, 5 * 32, 0, "%d", score);
            
        }
        al_flip_display();
    }

     
    al_destroy_display(display);  
    al_destroy_bitmap(image);    
    al_destroy_bitmap(imageParede);
    al_destroy_bitmap(imageBanana);
    al_destroy_bitmap(imageMacaco);
    al_destroy_bitmap(imageBalaoV);
    al_destroy_bitmap(imageBalaoVd);
    al_destroy_bitmap(imageBalaoA);
    al_destroy_bitmap(imagePerseguidor);
    al_destroy_font(Font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}


