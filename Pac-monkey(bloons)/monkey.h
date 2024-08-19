
#ifndef MONKEY_H
#define MONKEY_H

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
#include "movimento_padrao.h"

using namespace std;

class Monkey : public Movimento {

public:

    Monkey();
    Monkey(int,int,string);
    ~Monkey();
    virtual void Movimentacao();
    ALLEGRO_BITMAP* movi;
private:


};

#endif

