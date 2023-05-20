#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "tetramino.h"
class Game {
private:
	sf::RenderWindow window;
	Tetramino tetramino;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	void update() {
		tetramino.update();
	}
	//void checkCollisions() {}
	void draw() {
		window.clear();
		tetramino.draw(window);
		window.display();
	}
public:
	Game() :window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
	{

		window.setFramerateLimit(FPS);
	}

	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};
