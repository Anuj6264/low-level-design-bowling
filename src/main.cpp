#include<iostream>
using namespace std;

#include "Game/Game.h"

int main() {
    Player p1("Thor");
    Player p2("Loki");
    Player p3("Hela");
    Player p4("Odin");

    vector<Player> vec;
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    vec.push_back(p4);

    Game g;
    int index = g.createSession(vec);

    vector<int> s1;
    vector<int> s2;
    vector<int> s3;
    vector<int> s4;
    int score;
    for(int i=0; i<20; ++i)
    {
    	score = abs(rand()%10);
    	s1.push_back(score);
        g.roll(index, p1, score);
    	score = abs(rand()%10);
    	s2.push_back(score);
        g.roll(index, p2, score);
    	score = abs(rand()%10);
    	s3.push_back(score);
        g.roll(index, p3, score);
    	score = abs(rand()%10);
    	s4.push_back(score);
        g.roll(index, p4, score);
    }
    cout << "Player 1: ";
    for(int i: s1)
    	cout << i << " ";
    cout << "\n";

    cout << "Player 2: ";
    for(int i: s2)
    	cout << i << " ";
    cout << "\n";

    cout << "Player 3: ";
    for(int i: s3)
    	cout << i << " ";
    cout << "\n";

    cout << "Player 4: ";
    for(int i: s4)
    	cout << i << " ";
    cout << "\n";


    g.createSession(vec);
    g.createSession(vec);
    g.createSession(vec);
    g.declareWinner(index);
    g.createSession(vec);
	return 0;
}