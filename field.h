#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
using namespace sf;
class field {
private:

public:

};



int pos_x[4];//позиция одного из 4 кубиков тетрамино по x
int pos_y[4];//позиция одного из 4 кубиков тетрамино по y
int n = 3; // задаем тип тетрамино
for (int i = 0; i < 4; i++)
{
	pos_x = tetramino[n][i] % 2;
	pos_y = tetramino[n][i] / 2;
}
for (int i = 0; i < 4; i++)
{
	// Устанавливаем позицию каждого кусочка тетрамино
	sprite.setPosition(pos_x * 36, pos_y * 36);
	// Отрисовка спрайта
	window.draw(sprite);
}