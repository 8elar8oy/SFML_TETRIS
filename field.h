#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
using namespace sf;
class field {
private:

public:

};



int pos_x[4];//������� ������ �� 4 ������� ��������� �� x
int pos_y[4];//������� ������ �� 4 ������� ��������� �� y
int n = 3; // ������ ��� ���������
for (int i = 0; i < 4; i++)
{
	pos_x = tetramino[n][i] % 2;
	pos_y = tetramino[n][i] / 2;
}
for (int i = 0; i < 4; i++)
{
	// ������������� ������� ������� ������� ���������
	sprite.setPosition(pos_x * 36, pos_y * 36);
	// ��������� �������
	window.draw(sprite);
}