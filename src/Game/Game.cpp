#include<iostream>
using namespace std;

#include "Game.h"

vector<int> Game::alleys = {1, 2, 3, 4};

int Game::createSession(vector<Player>& players)
{
	if(Game::alleys.size() == 0)
	{
		cout << "All alleys are currently occupied!\n";
		return 0;
	}
	GameSession gameSession;
	gameSession.setPlayers(players);
	gameSession.setAlley(alleys.back());
	Game::alleys.pop_back();
	gameSessions[gameSession.getId()] = gameSession;
	return gameSession.getId();
}

void Game::makeActive(int alley)
{
	Game::alleys.push_back(alley);
}

void Game::declareWinner(int index)
{
	bool winnerFlag = gameSessions[index].declareWinner();

	if(!winnerFlag)
	{
		cout << "No winners for this game yet" << endl;
	}
}

void Game::roll(int index, Player &player, int pins)
{
	GameSession *gameSession = &gameSessions[index];
	gameSession->makeRoll(player, pins);
}