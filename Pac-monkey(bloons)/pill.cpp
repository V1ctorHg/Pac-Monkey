#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "pill.h"

using namespace std;

Pill::Pill() {

    x = 8;
    y = 8;

    imagem = NULL;
}

Pill::Pill(int PosiX, int PosiY) {

    this->x = PosiX;
    this->y = PosiY;

}

Pill::Pill(const Pill& obj) {

    this->x = obj.x;
    this->y = obj.y;

}

Pill::~Pill() {

}

//Gets
int Pill::getX() {
    return x;
}
int Pill::getY() {
    return y;
}
bool Pill::getEspacoVazio() {
    return EspacoVazio;
}
void Pill::setX(int NumX) {
    x = NumX;
}
void Pill::setY(int NumY) {
    y = NumY;
}
void Pill::desenha() {
    imagem = al_load_bitmap("Sprites/pill.png");
    if (!imagem) {
        cout << "Error\n";
    }
    al_draw_bitmap(imagem,x ,y, 0);
}
void Pill::setEspacoVazio(bool valor) {
    EspacoVazio = valor;
}
