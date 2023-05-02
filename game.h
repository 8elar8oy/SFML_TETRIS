#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include "gameObject.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	void update() {
		player.update();
	}
	void checkCollisions() {}
	void draw() {
		window.clear();
		player.draw(window);
		window.display();
	}
public:
	Game() :window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
	{ window.setFramerateLimit(FPS); }

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