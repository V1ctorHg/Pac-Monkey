#ifndef WALL_H
#define WALL_H
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

using namespace std;

class Wall {

public:
    Wall();
    Wall(int, int);
    Wall(const Wall&);
    ~Wall();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void desenha();

private:
    int  x;
    int  y;
    ALLEGRO_BITMAP* imagem;
};

#endif
