
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "movimento_padrao.h"
#include "balao.h"

using namespace std;

Balao::Balao() {
}
Balao::Balao(int PosicaoX, int PosicaoY,string IMG) : Movimento(PosicaoX, PosicaoX,IMG) {
}
Balao::~Balao() {
}
void Balao::Movimentacao() {
}

