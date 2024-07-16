#include<iostream>
using namespace std;
#include <cstring>

#include "../Game/Game.h"

Player::Player(string name)
{
	memset(rolls, 0, sizeof rolls);
	this->name = name;
	this->score = 0;
	this->firstRoll = true;
	this->frameIndex = 0;
	this->canPlay = true;
	this->currentRoll = 0;
}

bool Player::isStrike()
{
	return this->firstRoll == true && rolls[frameIndex] == 10;
}

bool Player::isCanPlay() const {
	return canPlay;
}

bool Player::isSpare()
{
	return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}

void Player::roll(int pins)
{
	if(this->canPlay == false)
		return;
	rolls[currentRoll++] = pins;
	updateScore();
}

void Player::updateScore()
{
	if(isStrike())
	{
		score += 20;
		rolls[currentRoll++] = 0;
		frameIndex += 2;
		if(frameIndex >= MAX_ROLLS_ALLOWED)
			this->canPlay = false;
	}
	else
	{
		if(frameIndex >= MAX_ROLLS_ALLOWED - 1)
		{
			score += rolls[frameIndex];
			this->canPlay = false;
		}
		else if(firstRoll == true)
		{
			firstRoll = false;
		}
		else
		{
			if(isSpare())
				score += 5;

			score += (rolls[frameIndex] + rolls[frameIndex + 1]);
			frameIndex += 2;
			firstRoll = true;
			if(frameIndex >= MAX_ROLLS_ALLOWED - 3)
				this->canPlay = false;
		}
	}
}

const string& Player::getName() const {
	return name;
}

int Player::getScore() const {
	return score;
}