
#ifndef MOVIMENTO_PADRAO_H
#define MOVIMENTO_PADRAO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Movimento {

public:
    Movimento();
    Movimento(int,int,string);
    Movimento(const Movimento&);
    ~Movimento();

    int getPosicaoX();
    int getPosicaoY();
    string getLoadImage();
    void setPosicaoX(int);
    void setPosicaoY(int);
    void setLoadImage(string);
    virtual void Movimentacao() = 0;

private:
    int PosicaoX;
    int PosicaoY;
    string LoadImage;

};
#endif


