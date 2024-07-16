#include <iostream>
using namespace std;

#include "../Game/Game.h"

void GameSession::makeRoll(Player& player, int pins)
{
	for(Player &p: players)
	{
		if(p.getName() == player.getName())
			p.roll(pins);
	}
}

GameSession::GameSession()
{
	this->alley = -1;
	this->id = getUniqueId();
	this->players.clear();
}

int GameSession::getUniqueId()
{
	static int gameSessionId = 1;
	return gameSessionId++;
}

void GameSession::setAlley(int alley) {
	this->alley = alley;
}

int GameSession::getId() const {
	return id;
}

void GameSession::setPlayers(const vector<Player> &players) {
	this->players = players;
}

bool GameSession::declareWinner()
{
	int maxScore = 0;
	Player *winner = NULL;
	for(Player &p: players)
	{
		if(p.isCanPlay() == true)
		{
            cout << "Player " << p.getName() << " hasn't completed yet. The current score: " << p.getScore() << endl;
            cout << "Match is in progress\n";
            return false;
		}
		if(p.getScore() > maxScore)
		{
			maxScore = p.getScore();
			winner = &p;
		}
	}
	if(winner)
	{
        cout << "The winner is: " << winner->getName() << " with a score of " << winner->getScore() << "\n";
	}

	Game::makeActive(this->alley);
	return true;
}