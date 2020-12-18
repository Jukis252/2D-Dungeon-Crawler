#include "Player.h";
using namespace std;

Player player;

const char startas[] = "zemelapisS.txt";
const char pirmas[] = "zemelapis1.txt";
const char antras[] = "zemelapis2.txt";
const char trecias[] = "zemelapis3.txt";
const char ketvirtas[] = "zemelapis4.txt";
const char penktas[] = "zemelapis5.txt";
const char sestas[] = "zemelapis6.txt";
const char laimejimas[] = "zemelapisL.txt";
const char finishas[] = "zemelapisF.txt";

bool gamerunning = true;
char zemelapis[10][50];

void Go(int lygis, bool kitas, const char startas[], const char pirmas[], const char antras[], const char trecias[], const char ketvirtas[], const char penktas[], const char sestas[], const char finishas[], const char laimejimas[], char zemelapis[10][50])
{
    if (kitas == true and lygis == -1)
    {
        player.Create(zemelapis, startas);
    }
    if (kitas == true and lygis == 1)
    {
        player.Create(zemelapis, pirmas);
    }
    if (kitas == true and lygis == 2)
    {
        player.Create(zemelapis, antras);
    }
    if (kitas == true and lygis == 3)
    {
        player.Create(zemelapis, trecias);
    }
    if (kitas == true and lygis == 4)
    {
        player.Create(zemelapis, ketvirtas);
    }
    if (kitas == true and lygis == 5)
    {
        player.Create(zemelapis, penktas);
    }
    if (kitas == true and lygis == 6)
    {
        player.Create(zemelapis, sestas);
    }
    if (kitas == true and lygis == 7)
    {
        player.Create(zemelapis, finishas);
    }
};

int main()
{
    player.Create(zemelapis, startas);
   
    while (gamerunning)
    {
        Go(lygis, kitas, startas, pirmas,antras,trecias,ketvirtas,penktas,sestas,finishas,laimejimas,zemelapis);
        stringstream ss;
        ss << noc;
        string money="Kapeikos: ";
        money += ss.str();
        system("cls");
        //--------Piesti------------
        for (int i = 0; i < 10; i++)
        {
            cout << zemelapis[i] << endl;
        }
        //----------Raktu funkcija---------
        set <char>::iterator it;
        cout << "Jusu raktai: " << endl;
        for (it = got_key.begin(); it != got_key.end(); ++it)
        {
            cout << " " << *it << " ";
        }
        cout << endl;
        //--------Koordinates--------
        cout <<" Y: "<< y << " X: " << x << endl;
        //--------Pinigai----------
        for (int i = 0; i < 1; i++)
        {
            cout << money << endl;
        }
        //-------Tekstas----------
        for (int i = 0; i < 1; i++)
        {
            cout << dialog << endl;
        }
        system("pause>nul");
        //--------Kontroles----------
        if (GetAsyncKeyState(VK_UP))
        {
            player.Move(-1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            player.Move(1, 0);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            player.Move(0, 1);
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            player.Move(0, -1);
        }
        if (GetAsyncKeyState(VK_RETURN) && dialog_displayed)
        {
            dialog = "";
        }
   }
    system("pause");
}