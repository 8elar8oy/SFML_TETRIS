#pragma once
#include "settings.h"
#include "gameObject.h"

class Player : public GameObject {
private:
	float speedy = 0.f;
	float speedx = 0.f;
	int score = 0;
	sf::FloatRect bounds;
	int dx;
public:

	Player() {
		texture.loadFromFile("TETRISSFML.png");

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,36, 36));
		bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			(WINDOW_WIDTH - bounds.width) / 2,
			WINDOW_HEIGHT - bounds.height - 50.f
		);
	}


	void update() {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			dx = -36;
			sprite.setPosition(sprite.getPosition().x + dx, sprite.getPosition().y);
			dx = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			dx = 36;
			sprite.setPosition(sprite.getPosition().x + dx, sprite.getPosition().y);
			dx = 0;
		}
		
		sf::Vector2f playerPos = sprite.getPosition();
		if (playerPos.x < 0) {
			sprite.setPosition(0.f, playerPos.y);
		}
		else if (playerPos.x > WINDOW_WIDTH - bounds.width) {
			sprite.setPosition(WINDOW_WIDTH - bounds.width, playerPos.y);
		}
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	int getScore() { return score; }
};