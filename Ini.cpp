#include <iostream>
#include <C:\Users\fingx\OneDrive\Dokumente\Programming\C++\Snake Game\decla.h>
using namespace std;


bool Game::Initialize() {
	screenx = 720;
	screeny = 480;
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result != 0) {
		return false;
	}
	int result2 = TTF_Init();
	if (result2 != 0) {
		 return false;
	}
	aWindow = SDL_CreateWindow(
		"Snake game",
		100, 100, screenx, screeny, 0
	);
	aRenderer = SDL_CreateRenderer(
		aWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	SDL_SetRenderDrawColor(aRenderer, 0, 0, 0, 255);
	isRunning = true;
	step = 1;
	SnakePos.x = screenx / 1.5f;
	SnakePos.y = screeny / 2.0f;
	m_u = 1;
	m_d = 2;
	m_l = 3;
	m_r = 4;
	move = m_l;
	Coins = 0;
	CoinPos.x = screenx / 2.0f;
	CoinPos.y = screeny / 2.0f;
	Sans = TTF_OpenFont("C:/Users/fingx/OneDrive/Dokumente/Programming/C++/Snake Game/milker.otf", 24);
	White = { 255, 255, 255 };
	Score = "Score: " + to_string(Coins);
	Text = TTF_RenderText_Solid(Sans, Score.c_str(), White);
	TheScoreTexture = SDL_CreateTextureFromSurface(aRenderer, Text);
}
void Game::Runloop() {
	while (isRunning) {
		ProcessInput();
		UpdateGame();
		ProcessOutput();
	}
}
void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
	if (state[SDL_SCANCODE_UP]) { if (move != m_d) { move = m_u; } }
	if (state[SDL_SCANCODE_RIGHT]) { if (move != m_l) { move = m_r; } }
	if (state[SDL_SCANCODE_DOWN]) { if (move != m_u) { move = m_d; } }
	if (state[SDL_SCANCODE_LEFT]) { if (move != m_r) { move = m_l; } }

}

void Game::UpdateGame() {
	
	//move left
	if (move == m_l ) {
		SnakePos.x -= step;
	}
	//move up
	else if (move == m_u ) {
		SnakePos.y -= step;
	}
	//move right
	else if (move == m_r ) {
		SnakePos.x += step;
	}
	//move down
	else if (move == m_d ) {
		SnakePos.y += step;
	}

	//Colisions logic
	else if (move == 5 ) {
		SnakePos.x -= step;
	}
	if (SnakePos.x < 0){
		SnakePos.x += screenx;
	}
	if (SnakePos.x > screenx) {
		SnakePos.x -= screenx;
	}
	if (SnakePos.y <= 0 || SnakePos.y >= screeny) {
		isRunning = false;
	}
	diff = SnakePos.y - CoinPos.y;
	diff = (diff > 0.0f) ? diff : -diff;
	diff2 = SnakePos.x - CoinPos.x;
	diff2 = (diff2 > 0.0f) ? diff2 : -diff2;
	
	if (diff <=  10.0f && diff2 <= 10.0f) {
		randomPosx = rand() % (screenx + 1);
		randomPosy = rand() % (screeny + 1);
		CoinPos.x = randomPosx;
		CoinPos.y = randomPosy;
		step += 0.1f;
		Coins += 1;
		Score = "Score: " + to_string(Coins);
		Text = TTF_RenderText_Solid(Sans, Score.c_str(), White);
		TheScoreTexture = SDL_CreateTextureFromSurface(aRenderer, Text);
	}

}

void Game::ProcessOutput() {
	SDL_RenderClear(aRenderer);
	//Render Snake
	SDL_SetRenderDrawColor(aRenderer, 255, 255, 255, 255);
	SDL_Rect Snake{SnakePos.x, SnakePos.y, 15, 10};
	SDL_RenderFillRect(aRenderer, &Snake);
	//Render Coin
	SDL_SetRenderDrawColor(aRenderer, 255, 0, 0, 255);
	SDL_Rect Coin{ CoinPos.x, CoinPos.y, 10, 10 };
	SDL_RenderFillRect(aRenderer, &Coin);
	//Render Score
;	SDL_Rect Score {10, 10 ,100 , 20};
	SDL_RenderCopy(aRenderer, TheScoreTexture, NULL, &Score);
	//Render all
	SDL_RenderPresent(aRenderer);
	SDL_SetRenderDrawColor(aRenderer, 0, 0, 0, 255);
}




void Game::Endloop() {
	SDL_DestroyRenderer(aRenderer);
	SDL_DestroyWindow(aWindow);
	SDL_DestroyTexture(TheScoreTexture);
	TTF_Quit();
	SDL_Quit();
}