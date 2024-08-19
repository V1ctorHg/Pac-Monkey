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
#include "wall.h"

using namespace std;
Wall::Wall() {
    x = 0;
    y = 0;
    imagem = NULL;
}

Wall::Wall(int PosiX, int PosiY) {
    this->x = PosiX;
    this->y = PosiY;

}

Wall::Wall(const Wall& obj) {
    this->x = obj.x;
    this->y = obj.y;

}

Wall::~Wall() {

}

int Wall::getX() {
    return x;
}
int Wall::getY() {
    return y;
}

void Wall::setX(int NumX) {
    x = NumX;
}
void Wall::setY(int NumY) {
    y = NumY;
}
void Wall::desenha() {
    imagem = al_load_bitmap("Sprites/wall.png");
    al_draw_bitmap(imagem, 0, 0, 0);
    if (!imagem) {
        cout << "Error ao carregar a imagem!\n";
    }
}

