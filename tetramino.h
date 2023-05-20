#pragma once
#include "settings.h"
#include <iostream>
#include <ctime> 
using namespace sf;
struct Point
{
	int x, y;
} a[4], b[4];
class Tetramino {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int dx = 0;
	bool rotate = 0;
	int colorNum = 1; // цвет
	float timer = 0, delay = 0.3;
	sf::Clock clock;
	bool beginGame = true;
public:
	Tetramino() {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 36, 36));
		texture.loadFromFile("TETRISSFML.png");
		
	}
	void update() {
		int n = rand() % 7;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			dx = -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			dx = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			rotate = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			delay = 0.05;
		} 
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].x += dx;
		}
		if (!check()) {
			for (int i = 0; i < 4; i++)
				a[i] = b[i];
		}
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (rotate)
		{
			Point p = a[1]; // указываем центр вращения
			for (int i = 0; i < 4; i++)
			{
				int x = a[i].y - p.y; // y - y0
				int y = a[i].x - p.x; // x - x0
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
			if (!check()) {
				for (int i = 0; i < 4; i++)
					a[i] = b[i];
			}
		}
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
			if (!check())
			{
				for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
				colorNum = rand() % 7;
				n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}
			}
			timer = 0;
		}
		int k = M - 1;
		for (int i = M - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < N) k--;
		}
		if (beginGame)
		{
			beginGame = false;
			n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}
		dx = 0; rotate = 0;delay = 0.3;
	}
	bool check()
	{
		for (int i = 0; i < 4; i++) {
			if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
			else if (field[a[i].y][a[i].x]) return 0;
			return 1;
		}
	}
	void draw(sf::RenderWindow& window) {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (field[i][j] == 0) continue;
				sprite.setTextureRect(sf::IntRect(field[i][j] * 36, 0, 36, 36));
				sprite.setPosition(j * 36, i * 36);
				window.draw(sprite);
			}
		for (int i = 0; i < 4; i++)
		{
			// Разукрашиваем тетрамино
			sprite.setTextureRect(sf::IntRect(colorNum * 36, 0, 36, 36));
			// Устанавливаем позицию каждого кусочка тетрамино
			sprite.setPosition(a[i].x * 36, a[i].y * 36);
			// Отрисовка спрайта
			window.draw(sprite);
		}

	}
	
};
