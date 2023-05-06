#pragma once
#include "settings.h"
//#include "gameObject.h"
#include <iostream>

#include <ctime> 

//int n = 3; // задаем тип тетрамино
//

class Tetramino /*: public GameObject*/ {
private:
	float speedy = 0.f;
	float speedx = 0.f;
	int score = 0;
	sf::FloatRect bounds[4];
	sf::Clock timer;
	int pos_x[4];//позиция одного из 4 кубиков тетрамино по x
	int pos_y[4];//позиция одного из 4 кубиков тетрамино по y
	int dx;
	int dy = 36;
	int type;
	int color;
	sf::Sprite sprite[4];
	sf::Texture  texture;
public:

	Tetramino() {
		texture.loadFromFile("TETRISSFML.png");
		type = rand() % 7;
		color = rand() % 7;
		for (int i = 0; i < 4; i++)
		{
			sprite[i].setTexture(texture);
			sprite[i].setTextureRect(sf::IntRect(0+36*color, 0, 36+ 1 * color, 36+ 1 * color));
			pos_x[i] = tetramino[type][i] % 2;
			pos_y[i] = tetramino[type][i] / 2;
			bounds[i] = sprite[i].getGlobalBounds();
			sprite[i].setPosition(pos_x[i] * 36, pos_y[i] * 36);
		}
		timer.restart();
	}
	void update() {
		float time = timer.getElapsedTime().asMilliseconds();
		if (time > 50) {
			timer.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				dx = -36;
				for (int i = 0; i < 4; i++)
				{
					sprite[i].setPosition(sprite[i].getPosition().x + dx, sprite[i].getPosition().y);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				dx = 36;
				for (int i = 0; i < 4; i++)
				{
					sprite[i].setPosition(sprite[i].getPosition().x + dx, sprite[i].getPosition().y);
				}
				
			}
			for (int i = 0; i < 4; i++)
			{
				sprite[i].setPosition(sprite[i].getPosition().x, sprite[i].getPosition().y + dy);
			}
		}
		for (int i = 0; i < 4; i++)
		{
			sf::Vector2f playerPos[] = sprite[i].getPosition();
			if (playerPos[i].x < 0) {
				sprite[i].setPosition(0.f, playerPos[i].y);
			}
			if (playerPos[i].y > WINDOW_HEIGHT) {
				sprite[i].setPosition(playerPos[i].x, WINDOW_HEIGHT - bounds[i].height);
			}
			else if (playerPos[i].x > WINDOW_WIDTH - bounds[i].width) {
				sprite[i].setPosition(WINDOW_WIDTH - bounds[i].width, playerPos[i].y);
			}

		}
		
		
	}
	sf::Vector2f getPositon(int i) { return sprite[i].getPosition(); }
	sf::FloatRect getHitBox(int i) { return sprite[i].getGlobalBounds(); }

	void draw(sf::RenderWindow& window) {
		for (int i = 0; i < 4; i++)
		{
			window.draw(sprite[i]);
		}
		
	}
	int getScore() { return score; }
};