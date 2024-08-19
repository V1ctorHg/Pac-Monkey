
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
//construtores
Movimento::Movimento() {

    PosicaoX = 0;
    PosicaoY = 0;

    ALLEGRO_BITMAP* MovimentoImagemEsq = NULL;
    ALLEGRO_BITMAP* MovimentoImagemDir = NULL;
    ALLEGRO_BITMAP* MovimentoImagemBaixo = NULL;
    ALLEGRO_BITMAP* MovimentoImagemCima = NULL;
}

Movimento::Movimento(int PosicaoX, int PosicaoY,string imagem) {

    this->PosicaoX = PosicaoX;
    this->PosicaoY = PosicaoY;
    this->LoadImage = imagem;

}

Movimento::Movimento(const Movimento& obj) {

    this->PosicaoX = obj.PosicaoX;
    this->PosicaoY = obj.PosicaoY;
}
Movimento::~Movimento() {
}

int Movimento::getPosicaoY() {
    return PosicaoY;
}
int Movimento::getPosicaoX() {
    return PosicaoX;
}
string Movimento::getLoadImage() {
    return LoadImage;
}
void Movimento::setPosicaoX(int x) {
    PosicaoX = x;
}
void Movimento::setPosicaoY(int y) {
    PosicaoY = y;
}
void Movimento::setLoadImage(string Personagem) {
    LoadImage = Personagem;
}

