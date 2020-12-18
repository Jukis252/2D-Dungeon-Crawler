#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Windows.h";
using namespace std;

class Player
{
public:
	Player();
	~Player();
	void Move(int V, int H);
	void Create(char zemelapis[10][50], const char cdfv[]);

};
extern char zemelapis[10][50];
extern int x;
extern int y;
extern int noc;
extern string dialog;
extern bool dialog_displayed;
extern bool treasure_opened;
extern set <char> got_key;
extern bool kitas;
extern int lygis;
extern vector<int>pinigai;
#endif

