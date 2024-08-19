
#ifndef BALAO_H
#define BALAO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "movimento_padrao.h"

using namespace std;


class Balao : public Movimento {

public:

    Balao();
    Balao(int, int,string);
    ~Balao();
    virtual void Movimentacao();

private:


};

#endif

