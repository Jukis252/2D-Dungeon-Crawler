#include "Player.h"
using namespace std;


int x = 1;
int y = 1;
int noc = 0; //kapeikos
int lygis = -1;

string dialog = "";
bool dialog_displayed = false;
bool treasure_opened = false;
bool kitas = false;
set<char>got_key = {};


Player::Player()
{

}

Player::~Player()
{

}

void Player::Create(char zemelapis[10][50], const char cdfv[])
{
	ifstream fd(cdfv);
	for (int i = 0; i < 10; i++)
	{
		fd.getline(zemelapis[i], 50);
	}
	fd.close();
}

void Player::Move(int V, int H)
{
	if (lygis == -1 and kitas == true)
	{
		x = 21;
		y = 8;
		kitas = false;
	}
	if (lygis == 1 and kitas == true)
	{
		x = 1;
		y = 1;
		kitas = false;
	}
	if (lygis == 2 and kitas == true)
	{
		x = 1;
		y = 4;
		kitas = false;
	}
	if (lygis == 3 and kitas == true)
	{
		x = 21;
		y = 8;
		kitas = false;
	}
	if (lygis == 4 and kitas == true)
	{
		x = 21;
		y = 1;
		kitas = false;
	}
	if (lygis == 5 and kitas == true)
	{
		x = 21;
		y = 1;
		kitas = false;
	}
	if (lygis == 6 and kitas == true)
	{
		x = 21;
		y = 8;
		kitas = false;
	}
	if (lygis == 7 and kitas == true)
	{
		x = 1;
		y = 8;
		kitas = false;
	}
	/*if (lygis == 8 and kitas == true)
	{
		x = 39;
		y = 8;
		kitas = false;
	}*/
	int y2 = y + V;
	int x2 = x + H;
	//----------Pinigai---------------
	if (zemelapis[y2][x2]=='+')
	{
		treasure_opened = true;
	}
	if (zemelapis[y2][x2] == '*')
	{
		noc++;
	}
	if (zemelapis[y2][x2] == '#')
	{
		noc--;
	}
	//-----------------Raktai------------
	if (zemelapis[y2][x2] == 'X')
	{
		got_key.insert('X');
	}
	if (zemelapis[y2][x2] == 'Y')
	{
		got_key.insert('Y');
	}
	if (zemelapis[y2][x2] == 'Z')
	{
		got_key.insert('Z');
	}
	if (zemelapis[y2][x2] == 'C')
	{
		got_key.insert('C');
	}
	if (zemelapis[y2][x2] == 'V')
	{
		got_key.insert('V');
	}
	//--------------Durys------------
	if (y2 == 4 && x2 == 6)
	{
		auto search = got_key.find('X');
		if (lygis == 7 && search == got_key.end())
		{
			dialog = "Reikia X rakto.";
		}
	}
	if (y == 4 && x == 6)
	{
		auto search = got_key.find('X');
		if (search != got_key.end())
		{
			zemelapis[y2][x] = ' ';
		}
	}
	if (y2 == 6 && x2 == 12)
	{
		auto search = got_key.find('Y');
		if (lygis == 7 && search == got_key.end())
		{
			dialog = "Reikia Y rakto.";
		}
	}
	if (y == 6 && x == 12)
	{
		auto search = got_key.find('Y');
		if (search != got_key.end())
		{
			zemelapis[y2][x] = ' ';
		}
	}
	if (y2 == 4 && x2 == 18)
	{
		auto search = got_key.find('Z');
		if (lygis == 7 && search == got_key.end())
		{
			dialog = "Reikia Z rakto.";
		}
	}
	if (y == 4 && x == 18)
	{
		auto search = got_key.find('Z');
		if (search != got_key.end())
		{
			zemelapis[y2][x] = ' ';
		}
	}
	if (y2 == 6 && x2 == 24)
	{
		auto search = got_key.find('C');
		if (lygis == 7 && search == got_key.end())
		{
			dialog = "Reikia C rakto.";
		}
	}
	if (y == 6 && x == 24)
	{
		auto search = got_key.find('C');
		if (search != got_key.end())
		{
			zemelapis[y2][x] = ' ';
		}
	}
	if (y2 == 4 && x2 == 30)
	{
		auto search = got_key.find('V');
		if (lygis == 7 && search == got_key.end())
		{
			dialog = "Reikia V rakto.";
		}
	}
	if (y == 4 && x == 30)
	{
		auto search = got_key.find('V');
		if (search != got_key.end())
		{
			zemelapis[y2][x] = ' ';
		}
	}
	//---------Vaiksciojimas---------
	if (zemelapis[y][x2] == ' ' or zemelapis[y][x2] == '*' or  zemelapis[y][x2] == '+'
		or zemelapis[y][x2] == 'X' or zemelapis[y][x2] == 'V' or zemelapis[y][x2] == 'Z' or zemelapis[y][x2] == 'C'
		or zemelapis[y][x2] == 'S' or zemelapis[y][x2] == '1' or zemelapis[y][x2] == '2' or zemelapis[y][x2] == '3'
		or zemelapis[y][x2] == '4' or zemelapis[y][x2] == '5' or zemelapis[y][x2] == '6' or zemelapis[y][x2] == 'F'
		or zemelapis[y][x2] == 'Y' or zemelapis[y][x2] == 'W')
	{	
		if (zemelapis[y][x2] == 'S')
		{
			kitas = true;
			lygis = -1;
		}
		if (zemelapis[y][x2] == '1')
		{
			kitas = true;
			lygis = 1;
		}
		if (zemelapis[y][x2] == '2')
		{
			kitas = true;
			lygis = 2;
		}
		if (zemelapis[y][x2] == '3')
		{
			kitas = true;
			lygis = 3;
		}
		if (zemelapis[y][x2] == '4')
		{
			kitas = true;
			lygis = 4;
		}
		if (zemelapis[y][x2] == '5')
		{
			kitas = true;
			lygis = 5;
		}
		if (zemelapis[y][x2] == '6')
		{
			kitas = true;
			lygis = 6;
		}
		if (zemelapis[y][x2] == 'F')
		{
			kitas = true;
			lygis = 7;
		}
		/*if (zemelapis[y][x2] == 'W')
		{
			kitas = true;
			lygis = 8;
		}*/
		zemelapis[y][x] = ' ';
		x += H;
		zemelapis[y][x] = '@';
	}

	if (zemelapis[y2][x] == ' ' or zemelapis[y2][x] == '*' or  zemelapis[y2][x] == '+'
		or zemelapis[y2][x] == 'X' or zemelapis[y2][x] =='V' or zemelapis[y2][x] == 'Y' or zemelapis[y2][x] == 'Z'
		or zemelapis[y2][x] == 'S' or zemelapis[y2][x] == '1' or zemelapis[y2][x] == '2' or zemelapis[y2][x] == '3'
		or zemelapis[y2][x] == '4' or zemelapis[y2][x] == '5' or zemelapis[y2][x] == '6' or zemelapis[y2][x] == 'F'
		or zemelapis[y2][x] == 'Z' or zemelapis[y2][x] == 'W')
	{
		if (zemelapis[y2][x] == 'S')
		{
			kitas = true;
			lygis = -1;
		}
		if (zemelapis[y2][x] == '1')
		{
			kitas = true;
			lygis = 1;
		}
		if (zemelapis[y2][x] == '2')
		{
			kitas = true;
			lygis = 2;
		}
		if (zemelapis[y2][x] == '3')
		{
			kitas = true;
			lygis = 3;
		}
		if (zemelapis[y2][x] == '4')
		{
			kitas = true;
			lygis = 4;
		}
		if (zemelapis[y2][x] == '5')
		{
			kitas = true;
			lygis = 5;
		}
		if (zemelapis[y2][x] == '6')
		{
			kitas = true;
			lygis = 6;
		}
		if (zemelapis[y2][x] == 'F')
		{
			kitas = true;
			lygis = 7;
		}
		/*if (zemelapis[y2][x] == 'W')
		{
			kitas = true;
			lygis = 8;
		}*/
		zemelapis[y][x] = ' ';
		y += V;
		zemelapis[y][x] = '@';
	}
	
	if (treasure_opened)
	{
		zemelapis[y2 - 1][x2 - 1] = '*';
		zemelapis[y2 - 1][x2] = '*';
		zemelapis[y2 - 1][x2 + 1] = '*';
		zemelapis[y2 + 1][x2 - 1] = '*';
		zemelapis[y2 + 1][x2] = '*';
		zemelapis[y2 + 1][x2 + 1] = '*';
		zemelapis[y2][x + 1] = '*';
		zemelapis[y2][x - 1] = '*';
		dialog = "You opened treasure chest";
		dialog_displayed = true;
		treasure_opened = false;
	}	
}
