#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#define SDL_MAIN_HANDLED
#include <C:\Users\fingx\OneDrive\Dokumente\Programming\C++\Snake Game\packages\sdl2.nuget.2.32.8\build\native\include\SDL.h>
#include <C:\Users\fingx\OneDrive\Dokumente\Programming\C++\Snake Game\packages\sdl2_ttf.nuget.2.24.0\build\native\include\SDL_ttf.h>
using namespace std;
struct vector2 {
	float x, y;
};

class Game {
public:
	bool Initialize();
	void Runloop();
	void Endloop();

private:
	void ProcessInput();
	void UpdateGame();
	void ProcessOutput();
	SDL_Window* aWindow;
	SDL_Renderer* aRenderer;
	int screenx;
	int screeny;
	bool isRunning;
	vector2 SnakePos;
	vector2 CoinPos;
	float step;
	int move;
	int m_u;
	int m_d;
	int m_l;
	int m_r;
	int randomPosx;
	int randomPosy;
	int diff, diff2;
	int Coins;
	TTF_Font* Sans;
	SDL_Color White;
	SDL_Surface* Text;
	string Score;
	SDL_Texture* TheScoreTexture;




};