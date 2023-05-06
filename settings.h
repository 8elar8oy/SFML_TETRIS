#pragma once
#include "SFML/Graphics.hpp"
const float WINDOW_WIDTH = 360;
const float WINDOW_HEIGHT = 720;
const std::string WINDOW_TITLE = "TETRIS";
const float FPS = 60.f;
float PLAYER_SPEED = 1;
const int HEIGHT = 20; // высота игрового поля
const int WIDTH = 10; // ширина игрового поля
int field[WIDTH][HEIGHT] = { 0 }; // игровое поле

// Массив фигурок-тетрамино
int tetramino[7][4] = {
	1,3,5,7, // I
	2,4,5,7, // S
	3,5,4,6, // Z
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};