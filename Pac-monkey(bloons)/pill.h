#ifndef PILl_H
#define PILl_H

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

class Pill {

public:

    Pill();
    Pill(int, int);
    Pill(const Pill&);
    ~Pill();

    int getX();
    int getY();
    bool getEspacoVazio();

    void setX(int);
    void setY(int);
    void desenha();
    void setEspacoVazio(bool);

private:
    int  x;
    int  y;
    bool EspacoVazio;
    ALLEGRO_BITMAP* imagem;
};

#endif
