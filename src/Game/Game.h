#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#include "../Player/Player.h"
#include "../GameSession/GameSession.h"

class GameSession;

class Game
{
private:
	unordered_map<int, GameSession> gameSessions;
public:
	static vector<int> alleys;
	static void makeActive(int);
	int createSession(vector<Player>&);
	void roll(int, Player&, int);
	void declareWinner(int);
};