#include <iostream>
#include <vector>
using namespace std;

class Player;

class GameSession {
public:
    void setAlley(int);
	int getId() const;
	void setPlayers(const vector<Player>&);
	bool declareWinner();
	GameSession();
	void makeRoll(Player&, int);
private:
    int alley;
	int id;
	int getUniqueId();
	vector<Player> players;
};