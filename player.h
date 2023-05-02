#pragma once
#include "settings.h"
#include "gameObject.h"

class Player : public GameObject {
private:
	float speedy = 0.f;
	float speedx = 0.f;
	int score = 0;
	sf::FloatRect bounds;

public:

	Player() {
		texture.loadFromFile("TETRISSFML.png");
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			(WINDOW_WIDTH - bounds.width) / 2,
			WINDOW_HEIGHT - bounds.height - 50.f
		);
	}


	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			speedx = -PLAYER_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			speedx = PLAYER_SPEED;
		}
		sprite.move(speedx, 0.f);
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
	/*void incScore(int damage) { score = score + damage; }
	void decScore() { score--; }*/

	
	


};
