#include<iostream>
using namespace std;

class Player
{
public:
	Player(string);
	static const int MAX_ROLLS_ALLOWED = 23;
	const string& getName() const;
	int getScore() const;
	void roll(int);
	bool isCanPlay() const;

private:
	string name;
	int score;
	int rolls[MAX_ROLLS_ALLOWED];
	bool isStrike();
	bool isSpare();
	bool firstRoll;
	int frameIndex;
	bool canPlay;
	int currentRoll;
	void updateScore();
};