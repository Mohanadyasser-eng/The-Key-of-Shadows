#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct hero
{
    int r;
    int c;
    int minr;
    int minc;
    int maxr;
    int maxc;
    int weapon;
    int weapon2;
    int weapon3;
    int health;
    char direction;
    char jumpdirection;
    int jumpstate;
};

struct enemy
{
    int num;
    int type;
    int r;
    int c;
    int minr;
    int minc;
    int maxr;
    int maxc;
    int jumpstate;
    int autojump;
    int startpos;
    int endpos;
    char direction;
    int health;
};

struct trap
{
    int type;
    int r;
    int c;
    int minr;
    int minc;
    int maxr;
    int maxc;
};
struct elvator
{
    int r;
    int c;
    int minc;
    int maxc;
    int newr;
    int dri;
    int startpos;
    int endpos;
};

struct bullet
{
    int r;
    int c;
    int state;
    int pos;
    int coulmncatch;
    char directioncatch;
    int countdistance;
    int directionstate;
};

struct weapon
{
    int type;
    int r;
    int c;
    int minr;
    int minc;
    int maxr;
    int maxc;
};
struct counter
{
    int ct = 0;
    int ct1 = 0;
    int ct2 = 0;
    int ct3 = 0;
    int ct4 = 0;
    int ctl = 0;
    int ctjump = 0;
    int jumplimit = 0;
    int ladstate = 0;
    int elvstate = 0;
    int cte[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int cted[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int automove[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
};
struct healer
{
    int r;
    int c;
    int amount;
    char d;
    int draw;
};
struct table
{
    int r;
    int c;
};
struct ladd
{
    int r;
    int c;
    int minr;
    int minc;
    int maxr;
    int maxc;
    int state;
};
struct knife
{
    int r;
    int c;
    int pos;
    int state;
};
void ClearScreenFast() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, topLeft);
}
void check_borders(int& r, int& c)
{
    if (r < 0)
    {
        r = 0;
    }
    if (r > 199)
    {
        r = 199;
    }
    if (c < 0)
    {
        c = 0;
    }
    if (c > 599)
    {
        c = 599;
    }
}
/*
void display(char map[200][600], hero h)
{
    for (int r = 0; r < 200; r++)
    {
        for (int c = 0; c < 600; c++)
        {
            cout << map[r][c];
        }
        cout << endl;
    }
    cout << endl;
}
*/
void display(char map[200][600], hero h, int& key)
{
    ClearScreenFast();
    h.r -= 3;
    h.c += 5;
    int minr = h.r - 18;
    int minc = h.c - 41;
    check_borders(minr, minc);
    int maxr = minr + 23;
    int maxc = minc + 79;
    check_borders(maxr, maxc);
    minr = maxr - 23;
    minc = maxc - 79;

    for (int r = minr; r < minr + 2; r++)
    {
        for (int c = minc; c < 599; c++) // h.c + h.health + 38
        {
            check_borders(r, c);
            map[r][c] = ' ';
        }
    }

    minc = h.c - 80;
    check_borders(minr, minc);
    minc = h.c - 65;
    check_borders(minr, minc);
    minr = h.r - 18;
    minc = h.c - 41;
    check_borders(minr, minc);
    maxr = minr + 23;
    maxc = minc + 79;
    check_borders(maxr, maxc);
    minr = maxr - 23;
    minc = maxc - 79;

    minr++;
    for (int c = minc; c < maxc; c++)
    {
        map[minr - 1][c] = (char)205;
    }
    for (int c = minc; c < maxc; c++)
    {
        map[minr + 1][c] = (char)205;
    }
    for (int c = minc; c < 599; c++)
    {
        map[maxr][c] = (char)205;
    }
    for (int i = minr; i < maxr; i++)
    {
        map[i][minc] = (char)186;
    }
    for (int i = minr; i < maxr; i++)
    {
        map[i][maxc] = (char)186;
    }
    minr--;
    map[minr][minc] = (char)201;
    map[minr][maxc] = (char)187;
    map[maxr][minc] = (char)200;
    map[maxr][maxc] = (char)188;

    minc = h.c - 65;
    check_borders(minr, minc);
    minr = h.r - 18;
    minc = h.c - 41;
    check_borders(minr, minc);
    maxr = minr + 23;
    maxc = minc + 79;
    check_borders(maxr, maxc);
    minr = maxr - 23;
    minc = maxc - 79;
    map[minr + 1][minc + 1] = 'H';
    map[minr + 1][minc + 2] = 'e';
    map[minr + 1][minc + 3] = 'a';
    map[minr + 1][minc + 4] = 'l';
    map[minr + 1][minc + 5] = 't';
    map[minr + 1][minc + 6] = 'h';
    int c2 = minc + h.health;
    int pos = minc + 30;
    for (int c = minc + 8; c < c2; c++)
    {
        map[minr + 1][c] = (char)254; // health bar
    }
    if (key == 1)
    {
        map[minr + 1][pos + 40] = 'O';
        map[minr + 1][pos + 41] = (char)196;
        map[minr + 1][pos + 42] = (char)183;
    }
    minr = h.r - 18;
    minc = h.c - 41;
    check_borders(minr, minc);
    maxr = minr + 23;
    maxc = minc + 79;
    check_borders(maxr, maxc);
    minr = maxr - 23;
    minc = maxc - 79;
    for (int r = minr; r <= maxr; r++)
    {
        for (int c = minc; c <= maxc; c++)
        {
            cout << map[r][c];
        }
        cout << endl;
    }
}
void drawladder(char map[200][600], ladd l)
{
    for (int i = l.minr; i <= l.maxr; i++)
    { // 20 rows high
        for (int j = l.minc; j < l.maxc; j++)
        {
            if (j > l.minc && j < l.maxc - 1)
            {
                map[i][j] = (char)196; // step
            }
            else
            {
                map[i][j] = (char)222; // border
            }
        }
    }
}
void drawhealer(char map[200][600], healer heal)
{
    map[heal.r - 1][heal.c - 2] = (char)218, map[heal.r - 1][heal.c - 1] = (char)196, map[heal.r - 1][heal.c] = (char)196, map[heal.r - 1][heal.c + 1] = (char)196, map[heal.r - 1][heal.c + 2] = (char)191;
    map[heal.r][heal.c - 2] = (char)179, map[heal.r][heal.c] = (char)153, map[heal.r][heal.c + 2] = (char)179;
}
void drawtable(char map[200][600], table t)
{
    map[t.r - 5][t.c] = (char)201; // ╔
    for (int col = t.c + 1; col < t.c + 14; ++col)
        map[t.r - 5][col] = (char)205;  // ═
    map[t.r - 5][t.c + 14] = (char)187; // ╗

    // Table side walls
    map[t.r - 4][t.c] = (char)186; // ║
    for (int col = t.c + 1; col < t.c + 14; ++col)
        map[t.r - 4][col] = ' ';
    map[t.r - 4][t.c + 14] = (char)186; // ║

    // Table bottom border
    map[t.r - 3][t.c] = (char)200; // ╚
    for (int col = t.c + 1; col < t.c + 14; ++col)
        map[t.r - 3][col] = (char)205;  // ═
    map[t.r - 3][t.c + 14] = (char)188; // ╝

    // Table legs
    for (int row = t.r - 2; row <= t.r; ++row)
    {
        map[row][t.c + 2] = (char)186;  // Left leg
        map[row][t.c + 12] = (char)186; // Right leg
    }
}
void screen(char map[200][600], hero& h, table tab[12], healer heal[8], ladd lad[12], elvator& elv1, int& weapon, int& weapon2, int& weapon3, int& key)
{
    for (int i = 0; i < 200; i++)
    {
        for (int k = 0; k < 600; k++)
        {
            map[i][k] = ' ';
        }
    }
    map[0][0] = (char)201;     // top-left corner
    map[0][599] = (char)187;   // top-right corner
    map[199][0] = (char)200;   // bottom-right corner
    map[199][599] = (char)188; // bottom-left corner
    for (int i = 1; i < 199; i++)
    {
        map[i][0] = (char)186;   // right wall
        map[i][599] = (char)186; // left wall
    }
    for (int i = 1; i < 599; i++)
    {
        map[0][i] = (char)205;   // top wall
        map[199][i] = (char)205; // bottom wall
    }
    for (int i = 15; i < 31; i++) // floating platform
    {
        map[elv1.r][i] = (char)205;
    }
    for (int i = 198; i >= 180; i--)
    { // level 0 first wall
        map[i][91] = (char)186;
    }
    for (int i = 558; i < 598; i++)
    { // level 9 stairs floor 1
        map[19][i] = (char)205;
    }
    for (int i = 20; i < 19 + 5; i++)
    { // level 9 stairs wall 1
        map[i][558] = (char)186;
    }
    for (int i = 528; i < 558; i++)
    { // level 8 stairs floor 2
        map[19 + 5][i] = (char)205;
    }
    for (int i = 25; i < 24 + 5; i++)
    { // level 8 stairs wall 2
        map[i][528] = (char)186;
    }
    for (int i = 498; i < 528; i++)
    { // level 8 stairs floor 3
        map[24 + 5][i] = (char)205;
    }
    for (int i = 30; i < 34; i++)
    { // level 8 stairs wall 3
        map[i][498] = (char)186;
    }
    for (int i = 468; i < 498; i++)
    { // level 8 stairs floor 4
        map[29 + 5][i] = (char)205;
    }
    for (int i = 35; i < 39; i++)
    { // level 8 stairs wall 4
        map[i][468] = (char)186;
    }
    for (int i = 438; i < 468; i++)
    { // level 8 stairs floor 5
        map[39][i] = (char)205;
    }
    for (int i = 40; i < 40 + 4; i++)
    { // level 8 stairs wall 5
        map[i][438] = (char)186;
    }
    for (int i = 408; i < 438; i++)
    { // level 8 stairs floor 6
        map[44][i] = (char)205;
    }
    for (int i = 45; i < 49; i++)
    { // level 8 stairs wall 6
        map[i][408] = (char)186;
    }
    for (int i = 378; i < 408; i++)
    { // level 8 stairs floor 7
        map[49][i] = (char)205;
    }
    for (int i = 50; i < 54; i++)
    { // level 8 stairs wall 7
        map[i][378] = (char)186;
    }
    for (int i = 348; i < 378; i++)
    { // level 8 stairs floor 8
        map[54][i] = (char)205;
    }
    for (int i = 55; i < 59; i++)
    { // level 8 stairs wall 8
        map[i][348] = (char)186;
    }
    for (int i = 1; i < 70; i++)
    { // level 1 floor p1
        map[179][i] = (char)205;
    }
    for (int i = 47; i < 598; i++)
    { // level 1 floor p2
        map[179][i] = (char)205;
    }
    for (int i = 6; i < 598; i++)
    { // level 2 floor p1
        map[159][i] = (char)205;
    }
    for (int i = 1; i < 598; i++)
    { // level 3 floor p1
        map[139][i] = (char)205;
    }
    for (int i = 1; i < 598; i++)
    { // level 4 floor p1
        map[119][i] = (char)205;
    }
    for (int i = 1; i < 598; i++)
    { // level 5 floor p1
        map[99][i] = (char)205;
    }
    for (int i = 1; i < 598; i++)
    { // level 6 floor p1
        map[79][i] = (char)205;
    }
    for (int i = 1; i < 80; i++)
    { // level 7 floor p1
        map[59][i] = (char)205;
    }
    for (int i = 91; i < 102; i++)
    { // level 7 floor p2 platform 1
        map[59][i] = (char)205;
    }
    for (int i = 114; i < 125; i++)
    { // level 7 floor p3 platform 2
        map[59][i] = (char)205;
    }
    for (int i = 136; i < 147; i++)
    { // level 7 floor p4 platform 3
        map[59][i] = (char)205;
    }
    for (int i = 158; i < 169; i++)
    { // level 7 floor p5 platform 4
        map[59][i] = (char)205;
    }
    for (int i = 180; i < 191; i++)
    { // level 7 floor p6 platform 5
        map[59][i] = (char)205;
    }
    for (int i = 202; i < 213; i++)
    { // level 7 floor p7 platform 6
        map[59][i] = (char)205;
    }
    for (int i = 224; i < 598; i++)
    { // level 7 floor p8
        map[59][i] = (char)205;
    }
    for (int i = 1; i < 270; i++)
    { // level 8 floor p1
        map[39][i] = (char)205;
    }
    for (int i = 1; i < 270; i++)
    { // level 9 floor p1
        map[19][i] = (char)205;
    }
    for (int i = 178; i >= 160; i--)
    { // level 1 wall 1
        map[i][230] = (char)186;
    }
    for (int i = 138; i >= 120; i--)
    { // level 1 wall 1
        map[i][270] = (char)186;
    }
    for (int i = 80; i < 99; i++)
    { // level 5 wall 1
        map[i][315] = (char)186;
    }
    for (int i = 60; i < 79; i++)
    { // level 6 wall 1
        map[i][224] = (char)186;
    }
    for (int i = 20; i < 39; i++)
    { // level 8 wall 1
        map[i][270] = (char)186;
    }
    for (int i = 1; i < 19; i++)
    { // level 9 wall 1
        map[i][270] = (char)186;
    }
    for (int i = 198; i > 198 - 11; i--)
    { // start place door
        map[i][1] = (char)179;
        map[i][13] = (char)179;
        if (i == 188)
        {
            map[i][1] = (char)218;
            map[i][13] = (char)191;
            for (int k = 2; k < 13; k++)
            {
                map[i][k] = (char)196;
            }
        }
    }
    for (int i = 158; i > 158 - 11; i--)
    { // end place door
        map[i][586] = (char)179;
        map[i][598] = (char)179;
        if (i == 158 - 10)
        {
            map[i][586] = (char)218;
            map[i][598] = (char)191;
            for (int k = 587; k < 598; k++)
            {
                map[i][k] = (char)196;
            }
        }
    }
    if (key == 0)
    {
        map[12][260] = 'O';
        map[12][261] = (char)196;
        map[12][262] = (char)183;
    }
    if (weapon == 0) // single bullet weapon
    {
        map[192][99] = (char)201;
        map[192][100] = (char)205;
    }
    if (weapon2 == 0) // multi bullet weapon
    {
        map[72][590] = (char)201;
        map[72][591] = (char)209;
        map[72][592] = (char)205;
    }
    if (weapon3 == 0) // laser bullet weapon
    {
        map[132][260] = (char)209;
        map[132][261] = (char)216;
        map[132][262] = (char)205;
    }
    for (int i = 0; i < 12; i++)
    {
        drawtable(map, tab[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        if (heal[i].draw == 0)
        {
            drawhealer(map, heal[i]);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        drawladder(map, lad[i]);
    }
    map[78 - 11][227 + 2] = '_';
    map[78 - 11][227 + 3] = '_';
    map[78 - 11][227 + 4] = '_';
    map[78 - 11][227 + 5] = '_';
    map[78 - 11][227 + 6] = '_';
    map[78 - 11][227 + 7] = '_';
    map[78 - 11][227 + 8] = '_';
    map[78 - 11][227 + 9] = '_';
    map[78 - 11][227 + 10] = '_';
    map[78 - 11][227 + 11] = '_';
    map[78 - 11][227 + 12] = '_';
    map[78 - 11][227 + 13] = '_';
    map[78 - 11][227 + 14] = '_';
    map[78 - 11][227 + 15] = '_';
    map[78 - 10][227 + 1] = '/';
    map[78 - 10][227 + 16] = '\\'; /// tp 1
    map[78 - 9][227 + 1] = '\\';
    map[78 - 9][227 + 16] = '/';
    map[78 - 8][227 + 1] = '/';
    map[78 - 8][227 + 16] = '\\';
    map[78 - 7][227 + 1] = '\\';
    map[78 - 7][227 + 16] = '/';
    map[78 - 6][227 + 2] = '|';
    map[78 - 6][227 + 15] = '|';
    map[78 - 5][227 + 2] = '|';
    map[78 - 5][227 + 15] = '|';
    map[78 - 4][227 + 2] = '|';
    map[78 - 4][227 + 15] = '|';
    map[78 - 3][227 + 2] = '|';
    map[78 - 3][227 + 15] = '|';
    map[78 - 2][227 + 1] = '/';
    map[78 - 2][227 + 16] = '\\';
    map[78 - 1][227 + 0] = '|';
    map[78 - 1][227 + 17] = '|';
    map[78 - 0][227 + 0] = '|';
    map[78 - 0][227 + 17] = '|';

    map[38 - 11][250 + 2] = '_';
    map[38 - 11][250 + 3] = '_';
    map[38 - 11][250 + 4] = '_';
    map[38 - 11][250 + 5] = '_';
    map[38 - 11][250 + 6] = '_';
    map[38 - 11][250 + 7] = '_';
    map[38 - 11][250 + 8] = '_';
    map[38 - 11][250 + 9] = '_';
    map[38 - 11][250 + 10] = '_';
    map[38 - 11][250 + 11] = '_';
    map[38 - 11][250 + 12] = '_';
    map[38 - 11][250 + 13] = '_';
    map[38 - 11][250 + 14] = '_';
    map[38 - 11][250 + 15] = '_';
    map[38 - 10][250 + 1] = '/';
    map[38 - 10][250 + 16] = '\\';
    map[38 - 9][250 + 1] = '\\';
    map[38 - 9][250 + 16] = '/';
    map[38 - 8][250 + 1] = '/';
    map[38 - 8][250 + 16] = '\\';
    map[38 - 7][250 + 1] = '\\';
    map[38 - 7][250 + 16] = '/';
    map[38 - 6][250 + 2] = '|';
    map[38 - 6][250 + 15] = '|';
    map[38 - 5][250 + 2] = '|';
    map[38 - 5][250 + 15] = '|';
    map[38 - 4][250 + 2] = '|';
    map[38 - 4][250 + 15] = '|';
    map[38 - 3][250 + 2] = '|';
    map[38 - 3][250 + 15] = '|';
    map[38 - 2][250 + 1] = '/';
    map[38 - 2][250 + 16] = '\\';
    map[38 - 1][250 + 0] = '|';
    map[38 - 1][250 + 17] = '|';
    map[38 - 0][250 + 0] = '|';
    map[38 - 0][250 + 17] = '|';
}

void ladder(char x[200][600], hero& h, char action)
{
    if (action == 'w')
    {
        h.r--;
    }
    if (action == 's')
    {
        if (h.r + 1 < 199)
        {
            h.r++;
        }
    }
}

void in_elvator(char map[200][600], hero& h, int p1, int p2)
{
    for (; p1 > p1 - 10; p1--)
    {
        for (; p2 > p2 + 9; p2++)
        {
            map[p1][p2] = (char)178;
        }
    }
}
void elvator3(char map[200][600], hero& h, elvator& elv1, counter& c)
{
    if (elv1.r != elv1.newr)
    {
        if (elv1.dri == 0)
        {
            if (h.r + 1 == elv1.r && h.minc > 16 && h.maxc < 32)
            {
                c.elvstate = 1;
                h.r--;
            }
            else
            {
                c.elvstate = 0;
            }
            elv1.r--;
        }
        else if (elv1.dri == 1)
        {
            if (h.r + 1 == elv1.r && h.minc > 16 && h.maxc < 32)
            {
                c.elvstate = 1;
                h.r++;
            }
            else
            {
                c.elvstate = 0;
            }
            elv1.r++;
        }
    }
    if (elv1.r == elv1.newr)
    {
        if (elv1.dri == 1)
        {
            elv1.newr = elv1.newr - 20;
            elv1.dri = 0;
        }
        else if (elv1.dri == 0)
        {
            elv1.newr = elv1.newr + 20;
            elv1.dri = 1;
        }
    }
}


void gameover()
{
    ClearScreenFast();
    cout << "**************************************************************************************" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*   _______   _______   _______   _______    _______             _______   _______   *" << endl;
    cout << "*  (  ____ \\ (  ___  ) (       ) (  ____ \\  (  ___  ) |\\     /| (  ____ \\ (  ____ )  *" << endl;
    cout << "*  | (    \\/ | (   ) | | () () | | (    \\/  | (   ) | | )   ( | | (    \\/ | (    )|  *" << endl;
    cout << "*  | |       | (___) | | || || | | (__      | |   | | | |   | | | (__     | (____)|  *" << endl;
    cout << "*  | | ____  |  ___  | | |(_)| | |  __)     | |   | | ( (   ) ) |  __)    |     __)  *" << endl;
    cout << "*  | | \\_  ) | (   ) | | |   | | | (        | |   | |  \\ \\_/ /  | (       | (\\ (     *" << endl;
    cout << "*  | (___) | | )   ( | | )   ( | | (____/\\  | (___) |   \\   /   | (____/\\ | ) \\ \\__  *" << endl;
    cout << "*  (_______) |/     \\| |/     \\| (_______/  (_______)    \\_/    (_______/ |/   \\__/  *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "*                                                                                    *" << endl;
    cout << "**************************************************************************************" << endl;
}
void PRESENTEDBY()
{
    ClearScreenFast();
    cout << "*******************************************************************************" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*             __   __   __  __  __      ___  __  __     __                    *" << endl;
    cout << "*            |__) |__) |_  (_  |_  |\ |  |  |_  |  \   |__) \_/               *" << endl;
    cout << "*            |    | \  |__ __) |__ | \|  |  |__ |__/   |__)  |                *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*             __                       __              __  __  __  __         *" << endl;
    cout << "*       |\/| /  \ |__|  /\  |\ |  /\  |  \   \_/  /\  (_  (_  |_  |__)        *" << endl;
    cout << "*       |  | \__/ |  | /--\ | \| /--\ |__/    |  /--\ __) __) |__ | \         *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                      ___  __                __                              *" << endl;
    cout << "*            |__|  /\   _/ |_  |\/|   |__| | (_  |__|  /\  |\/|               *" << endl;
    cout << "*            |  | /--\ /__ |__ |  |   |  | | __) |  | /--\ |  |               *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*******************************************************************************" << endl;
}
void win()
{
    ClearScreenFast();
    cout << "*******************************************************************************" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                   _______                        _________  _               *" << endl;
    cout << "*        |\\     /| (  ___  ) |\\     /|   |\\     /| \\__   __/ ( (    /|        *" << endl;
    cout << "*        ( \\   / ) | (   ) | | )   ( |   | )   ( |    ) (    |  \\  ( |        *" << endl;
    cout << "*         \\ (_) /  | |   | | | |   | |   | | _ | |    | |    |   \\ | |        *" << endl;
    cout << "*          \\   /   | |   | | | |   | |   | |( )| |    | |    | (\\ \\) |        *" << endl;
    cout << "*           ) (    | |   | | | |   | |   | || || |    | |    | | \\   |        *" << endl;
    cout << "*           | |    | (___) | | (___) |   | () () | ___) (___ | )  \\  |        *" << endl;
    cout << "*           \\_/    (_______) (_______)   (_______) \\_______/ |/    )_)        *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*******************************************************************************" << endl;
}
void nameofgame()
{
    ClearScreenFast();
    cout << "*******************************************************************************" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                _        _______             _______  _______                *" << endl;
    cout << "*               | \\    /\\(  ____ \\|\\     /|  (  ___  )(  ____ \\               *" << endl;
    cout << "*               |  \\  / /| (    \\/( \\   / )  | (   ) || (    \\/               *" << endl;
    cout << "*               |  (_/ / | (__     \\ (_) /   | |   | || (__                   *" << endl;
    cout << "*               |   _ (  |  __)     \\   /    | |   | ||  __)                  *" << endl;
    cout << "*               |  ( \\ \\ | (         ) (     | |   | || (                     *" << endl;
    cout << "*               |  /  \\ \\| (____/\\   | |     | (___) || )                     *" << endl;
    cout << "*               |_/    \\/(_______/   \\_/     (_______)|/                      *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*        _______           _______  ______   _______           _______        *" << endl;
    cout << "*       (  ____ \\|\\     /|(  ___  )(  __  \\ (  ___  )|\\     /|(  ____ \\       *" << endl;
    cout << "*       | (    \\/| )   ( || (   ) || (  \\  )| (   ) || )   ( || (    \\/       *" << endl;
    cout << "*       | (_____ | (___) || (___) || |   ) || |   | || | _ | || (_____        *" << endl;
    cout << "*       (_____  )|  ___  ||  ___  || |   | || |   | || |( )| |(_____  )       *" << endl;
    cout << "*             ) || (   ) || (   ) || |   ) || |   | || || || |      ) |       *" << endl;
    cout << "*       /\\____) || )   ( || )   ( || (__/  )| (___) || () () |/\\____) |       *" << endl;
    cout << "*       \\_______)|/     \\||/     \\|(______/ (_______)(_______)\\_______)       *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                          press any key to continue.                         *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*******************************************************************************" << endl;
}
void howtoplay()
{
    ClearScreenFast();
    cout << "*******************************************************************************" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*      ____ ____ ____ _________ ____  ____ _________ ____ ____ ____ ____      *" << endl;
    cout << "*     ||H |||O |||W |||       |||T ||||O |||       |||P |||L |||A |||Y ||     *" << endl;
    cout << "*     ||__|||__|||__|||_______|||__||||__|||_______|||__|||__|||__|||__||     *" << endl;
    cout << "*     |/__\\|/__\\|/__\\|/_______\\|/__\\||/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|     *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                   1)  To Move Right Press 'D'                               *" << endl;
    cout << "*                   2)  To Move Left Press 'A'                                *" << endl;
    cout << "*                   3)  To Jump press 'W'                                     *" << endl;
    cout << "*                   4)  To Jump left press 'Q'                                *" << endl;
    cout << "*                   5)  To Jump Right press 'E'                               *" << endl;
    cout << "*                   6)  To Equip Weapons Press 'F'                            *" << endl;
    cout << "*                   7)  To Shoot Bullet-Laser Press 'R'                       *" << endl;
    cout << "*                   8)  TO Active The TP Portal Press 'F'                     *" << endl;
    cout << "*                   9)  TO Active The End Door Press 'F'                      *" << endl;
    cout << "*                   10) TO Consume Healers press 'F'                          *" << endl;
    cout << "*                   11) TO Double jump Double Press 'W,Q,E'                   *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                           Press D For Next --->                             *" << endl;
    cout << "*******************************************************************************" << endl;
}
void howtowin()
{
    ClearScreenFast();
    cout << "*******************************************************************************" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*    ____  ____  ____  _________  ____   ____  _________  ____  ____  ____    *" << endl;
    cout << "*   ||H ||||O ||||W ||||       ||||T || ||O ||||       ||||W ||||I ||||N ||   *" << endl;
    cout << "*   ||__||||__||||__||||_______||||__|| ||__||||_______||||__||||__||||__||   *" << endl;
    cout << "*   |/__\\||/__\\||/__\\||/_______\\||/__\\| |/__\\||/_______\\||/__\\||/__\\||/__\\|   *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   1) Start from the Starter Door.                                           *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   2) Explore the dungeon and find weapons.                                  *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   3) Fight and eliminate any enemies in your path.                          *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   4) Locate the hidden Key of Shadow.                                       *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   5) Search for the End Door.                                               *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*   6) Use the key to unlock the End Door and escape to victory!              *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*  <--- Press A To Back                                Press D To Start --->  *" << endl;
    cout << "*                                                                             *" << endl;
    cout << "*******************************************************************************" << endl;
}

void position_h(hero& h, int r_minval, int c_minval, int r_maxval, int c_maxval)
{
    h.minr = r_minval;
    h.minc = c_minval;
    h.maxr = r_maxval;
    h.maxc = c_maxval;
}

void position_e(enemy& e, int r_minval, int c_minval, int r_maxval, int c_maxval)
{
    e.minr = r_minval;
    e.minc = c_minval;
    e.maxr = r_maxval;
    e.maxc = c_maxval;
}

void position_t(trap& t, int r_minval, int c_minval, int r_maxval, int c_maxval)
{
    t.minr = r_minval;
    t.minc = c_minval;
    t.maxr = r_maxval;
    t.maxc = c_maxval;
}

void callpos(hero& h, enemy e[11], trap t[14])
{
    if (h.direction == 'r' && h.weapon == 0 && h.weapon2 == 0 && h.weapon3 == 0)
    {
        position_h(h, h.r - 9, h.c, h.r, h.c + 10); // maxc+1
    }
    else if (h.direction == 'l' && h.weapon == 0 && h.weapon2 == 0 && h.weapon3 == 0)
    {
        position_h(h, h.r - 9, h.c, h.r, h.c + 10);
    }
    else if (h.direction == 'r' && (h.weapon == 1 || h.weapon2 == 1 || h.weapon3 == 1))
    {
        position_h(h, h.r - 9, h.c, h.r, h.c + 12); // maxc+1
    }
    else if (h.direction == 'l' && (h.weapon == 1 || h.weapon2 == 1 || h.weapon3 == 1))
    {
        position_h(h, h.r - 9, h.c, h.r, h.c + 12); // maxc+1
    }

    for (int i = 0; i < 11; i++)
    {
        if (e[i].direction == 'r' && (e[i].type == 1 || e[i].type == 2))
        {
            position_e(e[i], e[i].r - 9, e[i].c, e[i].r, e[i].c + 10);
        }
        else if (e[i].direction == 'l' && (e[i].type == 1 || e[i].type == 2))
        {
            position_e(e[i], e[i].r - 9, e[i].c, e[i].r, e[i].c + 10);
        }
        else if (e[i].direction == 'r' && e[i].type == 3)
        {
            position_e(e[i], e[i].r - 9, e[i].c, e[i].r, e[i].c + 12); // maxc+1
        }
        else if (e[i].direction == 'l' && e[i].type == 3)
        {
            position_e(e[i], e[i].r - 9, e[i].c, e[i].r, e[i].c + 12); // maxc+1
        }
        else if (e[i].type == 0)
        {
            position_e(e[i], e[i].r - 2, e[i].c - 3, e[i].r + 1, e[i].c + 3);
        }
    }
    for (int i = 0; i < 14; i++)
    {
        position_t(t[i], t[i].r - 2, t[i].c, t[i].r, t[i].c + 3);
    }
}

void hero_jump(char map[200][600], hero& h, counter& c)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (c.ctjump == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218; // '┌'
            map[h.r - 8][h.c + 4] = (char)196; // '─'
            map[h.r - 8][h.c + 5] = (char)196; // '─'
            map[h.r - 8][h.c + 6] = (char)191; // '┐'
            map[h.r - 7][h.c + 3] = (char)179; // '│'
            map[h.r - 7][h.c + 4] = (char)111; // 'o'
            map[h.r - 7][h.c + 5] = (char)111; // 'o'
            map[h.r - 7][h.c + 6] = (char)179; // '│'
            map[h.r - 6][h.c + 2] = (char)32;  // ' '
            map[h.r - 6][h.c + 3] = (char)92;  // '\'
            map[h.r - 6][h.c + 4] = (char)94;  // '^'
            map[h.r - 6][h.c + 5] = (char)94;  // '^'
            map[h.r - 6][h.c + 6] = (char)47;  // '/'
            map[h.r - 5][h.c + 0] = (char)218; // '┌'
            map[h.r - 5][h.c + 1] = (char)196; // '─'
            map[h.r - 5][h.c + 2] = (char)179; // '│'
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // '│'
            map[h.r - 5][h.c + 8] = (char)196; // '─'
            map[h.r - 5][h.c + 9] = (char)191; // '┐'
            map[h.r - 4][h.c + 0] = (char)179; // '│'
            map[h.r - 4][h.c + 1] = (char)32;  // ' '
            map[h.r - 4][h.c + 2] = (char)179; // '│'
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // '│'
            map[h.r - 4][h.c + 8] = (char)32;  // ' '
            map[h.r - 4][h.c + 9] = (char)179; // '│'
            map[h.r - 3][h.c + 0] = (char)192; // '└'
            map[h.r - 3][h.c + 1] = (char)196; // '─'
            map[h.r - 3][h.c + 3] = (char)92;  // '\'
            map[h.r - 3][h.c + 4] = (char)196; // '─'
            map[h.r - 3][h.c + 5] = (char)196; // '─'
            map[h.r - 3][h.c + 6] = (char)47;  // '/'
            map[h.r - 3][h.c + 8] = (char)196; // '─'
            map[h.r - 3][h.c + 9] = (char)217; // '┘'
            map[h.r - 2][h.c + 3] = (char)47;  // '/'
            map[h.r - 2][h.c + 4] = (char)47;  // '/'
            map[h.r - 2][h.c + 5] = (char)92;  // '\'
            map[h.r - 2][h.c + 6] = (char)92;  // '\'
            map[h.r - 1][h.c + 2] = (char)47;  // '/'
            map[h.r - 1][h.c + 3] = (char)47;  // '/'
            map[h.r - 1][h.c + 6] = (char)92;  // '\'
            map[h.r - 1][h.c + 7] = (char)92;  // '\'
            map[h.r - 0][h.c + 1] = (char)92;  // '\'
            map[h.r - 0][h.c + 2] = (char)47;  // '/'
            map[h.r - 0][h.c + 3] = (char)32;  // ' '
            map[h.r - 0][h.c + 7] = (char)92;  // '\'
            map[h.r - 0][h.c + 8] = (char)47;  // '/'
        }
        if (c.ctjump == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218; // ┌
            map[h.r - 8][h.c + 4] = (char)196; // ─
            map[h.r - 8][h.c + 5] = (char)196; // ─
            map[h.r - 8][h.c + 6] = (char)191; // ┐
            map[h.r - 7][h.c + 3] = (char)179; // │
            map[h.r - 7][h.c + 4] = (char)111; // o
            map[h.r - 7][h.c + 5] = (char)111; // o
            map[h.r - 7][h.c + 6] = (char)179; // │
            map[h.r - 6][h.c + 0] = (char)218; // ┌
            map[h.r - 6][h.c + 1] = (char)191; // ┐
            map[h.r - 6][h.c + 3] = (char)92;  //
            map[h.r - 6][h.c + 4] = (char)94;  // ^
            map[h.r - 6][h.c + 5] = (char)94;  // ^
            map[h.r - 6][h.c + 6] = (char)47;  // /
            map[h.r - 6][h.c + 8] = (char)218; // ┌
            map[h.r - 6][h.c + 9] = (char)191; // ┐
            map[h.r - 5][h.c + 0] = (char)179; // │
            map[h.r - 5][h.c + 1] = (char)192; // └
            map[h.r - 5][h.c + 2] = (char)179; // │
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // │
            map[h.r - 5][h.c + 8] = (char)217; // ┘
            map[h.r - 5][h.c + 9] = (char)179; // │
            map[h.r - 4][h.c + 0] = (char)192; // └
            map[h.r - 4][h.c + 1] = (char)196; // ─
            map[h.r - 4][h.c + 2] = (char)179; // │
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // │
            map[h.r - 4][h.c + 8] = (char)196; // ─
            map[h.r - 4][h.c + 9] = (char)217; // ┘
            map[h.r - 3][h.c + 3] = (char)92;  //
            map[h.r - 3][h.c + 4] = (char)196; // ─
            map[h.r - 3][h.c + 5] = (char)196; // ─
            map[h.r - 3][h.c + 6] = (char)47;  // /
            map[h.r - 2][h.c + 3] = (char)47;  // /
            map[h.r - 2][h.c + 4] = (char)47;  // /
            map[h.r - 2][h.c + 5] = (char)92;  //
            map[h.r - 2][h.c + 6] = (char)92;  //
            map[h.r - 1][h.c + 2] = (char)47;  // /
            map[h.r - 1][h.c + 3] = (char)47;  // /
            map[h.r - 1][h.c + 6] = (char)92;  //
            map[h.r - 1][h.c + 7] = (char)92;  //
            map[h.r - 0][h.c + 1] = (char)92;  // '\'
            map[h.r - 0][h.c + 2] = (char)47;  // '/'
            map[h.r - 0][h.c + 7] = (char)92;  // '\'
            map[h.r - 0][h.c + 8] = (char)47;  // '/'
        }
    }
}
void hero_jumpR(char map[200][600], hero& h, counter& c)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (c.ctjump == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218; //'┌'
            map[h.r - 8][h.c + 4] = (char)196; //'─'
            map[h.r - 8][h.c + 5] = (char)196; //'─'
            map[h.r - 8][h.c + 6] = (char)191; //'┐'
            map[h.r - 7][h.c + 3] = (char)179; //'│'
            map[h.r - 7][h.c + 4] = ' ';       //' '
            map[h.r - 7][h.c + 5] = (char)111; //'o'
            map[h.r - 7][h.c + 6] = (char)111; //'o'
            map[h.r - 7][h.c + 7] = (char)41;  //')'
            map[h.r - 6][h.c + 3] = (char)92;  //'\'
            map[h.r - 6][h.c + 4] = (char)32;  //' '
            map[h.r - 6][h.c + 5] = (char)94;  //'^'
            map[h.r - 6][h.c + 6] = (char)47;  //'/'
            map[h.r - 5][h.c + 0] = (char)218; //'┌'
            map[h.r - 5][h.c + 1] = (char)196; //'─'
            map[h.r - 5][h.c + 2] = (char)179; //'│'
            map[h.r - 5][h.c + 3] = ' ';       //' '
            map[h.r - 5][h.c + 4] = ' ';       //' '
            map[h.r - 5][h.c + 5] = ' ';       //' '
            map[h.r - 5][h.c + 6] = ' ';       //' '
            map[h.r - 5][h.c + 7] = (char)179; //'│'
            map[h.r - 5][h.c + 8] = (char)196; //'─'
            map[h.r - 5][h.c + 9] = (char)191; //'┐'
            map[h.r - 4][h.c + 0] = (char)179; //'│'
            map[h.r - 4][h.c + 1] = ' ';       //' '
            map[h.r - 4][h.c + 2] = (char)179; //'│'
            map[h.r - 4][h.c + 3] = ' ';       //' '
            map[h.r - 4][h.c + 4] = ' ';       //' '
            map[h.r - 4][h.c + 5] = ' ';       //' '
            map[h.r - 4][h.c + 6] = ' ';       //' '
            map[h.r - 4][h.c + 7] = (char)179; //'│'
            map[h.r - 4][h.c + 8] = ' ';       //' '
            map[h.r - 4][h.c + 9] = (char)179; //'│'
            map[h.r - 3][h.c + 0] = (char)192; //'└'
            map[h.r - 3][h.c + 1] = (char)196; //'─'
            map[h.r - 3][h.c + 2] = ' ';       //' '
            map[h.r - 3][h.c + 3] = (char)92;  //'\'
            map[h.r - 3][h.c + 4] = (char)196; //'─'
            map[h.r - 3][h.c + 5] = (char)196; //'─'
            map[h.r - 3][h.c + 6] = (char)47;  //'/'
            map[h.r - 3][h.c + 7] = ' ';       //' '
            map[h.r - 3][h.c + 8] = (char)196; //'─'
            map[h.r - 3][h.c + 9] = (char)217; //'┘'
            map[h.r - 2][h.c + 3] = (char)92;  //'\'
            map[h.r - 2][h.c + 4] = (char)92;  //'\'
            map[h.r - 2][h.c + 6] = (char)92;  //'\'
            map[h.r - 2][h.c + 7] = (char)92;  //'\'
            map[h.r - 1][h.c + 3] = (char)47;  //'/'
            map[h.r - 1][h.c + 4] = (char)47;  //'/'
            map[h.r - 1][h.c + 6] = (char)47;  //'/'
            map[h.r - 1][h.c + 7] = (char)47;  //'/'
            map[h.r - 0][h.c + 2] = (char)192; //'└'
            map[h.r - 0][h.c + 3] = (char)217; //'┘'
            map[h.r - 0][h.c + 6] = (char)192; //'└'
            map[h.r - 0][h.c + 7] = (char)217; //'┘'
        }
        else if (c.ctjump == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218; //'┌'
            map[h.r - 8][h.c + 4] = (char)196; //'─'
            map[h.r - 8][h.c + 5] = (char)196; //'─'
            map[h.r - 8][h.c + 6] = (char)191; //'┐'
            map[h.r - 7][h.c + 3] = (char)179; //'│'
            map[h.r - 7][h.c + 4] = ' ';       //' '
            map[h.r - 7][h.c + 5] = (char)111; //'o'
            map[h.r - 7][h.c + 6] = (char)111; //'o'
            map[h.r - 7][h.c + 7] = (char)41;  //')'
            map[h.r - 6][h.c + 0] = (char)218; //'┌'
            map[h.r - 6][h.c + 1] = (char)191; //'┐'
            map[h.r - 6][h.c + 2] = ' ';       //' '
            map[h.r - 6][h.c + 3] = (char)92;  //'\'
            map[h.r - 6][h.c + 4] = (char)32;  //' '
            map[h.r - 6][h.c + 5] = (char)94;  //'^'
            map[h.r - 6][h.c + 6] = (char)47;  //'/'
            map[h.r - 6][h.c + 7] = ' ';       //' '
            map[h.r - 6][h.c + 8] = (char)218; //'┌'
            map[h.r - 6][h.c + 9] = (char)191; //'┐'
            map[h.r - 5][h.c + 0] = (char)179; //'│'
            map[h.r - 5][h.c + 1] = (char)192; //'└'
            map[h.r - 5][h.c + 2] = (char)179; //'│'
            map[h.r - 5][h.c + 3] = ' ';       //' '
            map[h.r - 5][h.c + 4] = ' ';       //' '
            map[h.r - 5][h.c + 5] = ' ';       //' '
            map[h.r - 5][h.c + 6] = ' ';       //' '
            map[h.r - 5][h.c + 7] = (char)179; //'│'
            map[h.r - 5][h.c + 8] = (char)217; //'┘'
            map[h.r - 5][h.c + 9] = (char)179; //'│'
            map[h.r - 4][h.c + 0] = (char)192; //'└'
            map[h.r - 4][h.c + 1] = (char)196; //'─'
            map[h.r - 4][h.c + 2] = (char)179; //'│'
            map[h.r - 4][h.c + 3] = ' ';       //' '
            map[h.r - 4][h.c + 4] = ' ';       //' '
            map[h.r - 4][h.c + 5] = ' ';       //' '
            map[h.r - 4][h.c + 6] = ' ';       //' '
            map[h.r - 4][h.c + 7] = (char)179; //'│'
            map[h.r - 4][h.c + 8] = (char)196; //'─'
            map[h.r - 4][h.c + 9] = (char)217; //'┘'
            map[h.r - 3][h.c + 3] = (char)92;  //'\'
            map[h.r - 3][h.c + 4] = (char)196; //'─'
            map[h.r - 3][h.c + 5] = (char)196; //'─'
            map[h.r - 3][h.c + 6] = (char)47;  //'/'
            map[h.r - 2][h.c + 3] = (char)92;  //'\'
            map[h.r - 2][h.c + 4] = (char)92;  //'\'
            map[h.r - 2][h.c + 6] = (char)92;  //'\'
            map[h.r - 2][h.c + 7] = (char)92;  //'\'
            map[h.r - 1][h.c + 3] = (char)47;  //'/'
            map[h.r - 1][h.c + 4] = (char)47;  //'/'
            map[h.r - 1][h.c + 6] = (char)47;  //'/'
            map[h.r - 1][h.c + 7] = (char)47;  //'/'
            map[h.r - 0][h.c + 2] = (char)192; //'└'
            map[h.r - 0][h.c + 3] = (char)217; //'┘'
            map[h.r - 0][h.c + 6] = (char)192; //'└'
            map[h.r - 0][h.c + 7] = (char)217; //'┘'
        }
    }
}
void hero_jumpL(char map[200][600], hero& h, counter& c)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (c.ctjump == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218; //'┌'
            map[h.r - 8][h.c + 4] = (char)196; //'─'
            map[h.r - 8][h.c + 5] = (char)196; //'─'
            map[h.r - 8][h.c + 6] = (char)191; //'┐'
            map[h.r - 7][h.c + 2] = (char)40;  //'('
            map[h.r - 7][h.c + 3] = (char)111; //'o'
            map[h.r - 7][h.c + 4] = (char)111; //'o'
            map[h.r - 7][h.c + 5] = ' ';       //' '
            map[h.r - 7][h.c + 6] = (char)179; //'│'
            map[h.r - 6][h.c + 3] = (char)92;  //'\'
            map[h.r - 6][h.c + 4] = (char)94;  //'^'
            map[h.r - 6][h.c + 5] = (char)32;  //' '
            map[h.r - 6][h.c + 6] = (char)47;  //'/'
            map[h.r - 5][h.c + 0] = (char)218; //'┌'
            map[h.r - 5][h.c + 1] = (char)196; //'─'
            map[h.r - 5][h.c + 2] = (char)179; //'│'
            map[h.r - 5][h.c + 3] = ' ';       //' '
            map[h.r - 5][h.c + 4] = ' ';       //' '
            map[h.r - 5][h.c + 5] = ' ';       //' '
            map[h.r - 5][h.c + 6] = ' ';       //' '
            map[h.r - 5][h.c + 7] = (char)179; //'│'
            map[h.r - 5][h.c + 8] = (char)196; //'─'
            map[h.r - 5][h.c + 9] = (char)191; //'┐'
            map[h.r - 4][h.c + 0] = (char)179; //'│'
            map[h.r - 4][h.c + 1] = ' ';       //' '
            map[h.r - 4][h.c + 2] = (char)179; //'│'
            map[h.r - 4][h.c + 3] = ' ';       //' '
            map[h.r - 4][h.c + 4] = ' ';       //' '
            map[h.r - 4][h.c + 5] = ' ';       //' '
            map[h.r - 4][h.c + 6] = ' ';       //' '
            map[h.r - 4][h.c + 7] = (char)179; //'│'
            map[h.r - 4][h.c + 8] = ' ';       //' '
            map[h.r - 4][h.c + 9] = (char)179; //'│'
            map[h.r - 3][h.c + 0] = (char)192; //'└'
            map[h.r - 3][h.c + 1] = (char)196; //'─'
            map[h.r - 3][h.c + 2] = ' ';       //' '
            map[h.r - 3][h.c + 3] = (char)92;  //'\'
            map[h.r - 3][h.c + 4] = (char)196; //'─'
            map[h.r - 3][h.c + 5] = (char)196; //'─'
            map[h.r - 3][h.c + 6] = (char)47;  //'/'
            map[h.r - 3][h.c + 7] = ' ';       //' '
            map[h.r - 3][h.c + 8] = (char)196; //'─'
            map[h.r - 3][h.c + 9] = (char)217; //'┘'
            map[h.r - 2][h.c + 2] = (char)47;  //'/'
            map[h.r - 2][h.c + 3] = (char)47;  //'/'
            map[h.r - 2][h.c + 5] = (char)47;  //'/'
            map[h.r - 2][h.c + 6] = (char)47;  //'/'
            map[h.r - 1][h.c + 2] = (char)92;  //'\'
            map[h.r - 1][h.c + 3] = (char)92;  //'\'
            map[h.r - 1][h.c + 5] = (char)92;  //'\'
            map[h.r - 1][h.c + 6] = (char)92;  //'\'
            map[h.r - 0][h.c + 3] = (char)192; //'└'
            map[h.r - 0][h.c + 4] = (char)217; //'┘'
            map[h.r - 0][h.c + 6] = (char)192; //'└'
            map[h.r - 0][h.c + 7] = (char)217; //'┘'
        }
        else if (c.ctjump == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218; //'┌'
            map[h.r - 8][h.c + 4] = (char)196; //'─'
            map[h.r - 8][h.c + 5] = (char)196; //'─'
            map[h.r - 8][h.c + 6] = (char)191; //'┐'
            map[h.r - 7][h.c + 2] = (char)40;  //'('
            map[h.r - 7][h.c + 3] = (char)111; //'o'
            map[h.r - 7][h.c + 4] = (char)111; //'o'
            map[h.r - 7][h.c + 5] = ' ';       //' '
            map[h.r - 7][h.c + 6] = (char)179; //'│'
            map[h.r - 6][h.c + 0] = (char)218; //'┌'
            map[h.r - 6][h.c + 1] = (char)191; //'┐'
            map[h.r - 6][h.c + 2] = ' ';       //' '
            map[h.r - 6][h.c + 3] = (char)92;  //'\'
            map[h.r - 6][h.c + 4] = (char)94;  //'^'
            map[h.r - 6][h.c + 5] = (char)32;  //' '
            map[h.r - 6][h.c + 6] = (char)47;  //'/'
            map[h.r - 6][h.c + 7] = ' ';       //' '
            map[h.r - 6][h.c + 8] = (char)218; //'┌'
            map[h.r - 6][h.c + 9] = (char)191; //'┐'
            map[h.r - 5][h.c + 0] = (char)179; //'│'
            map[h.r - 5][h.c + 1] = (char)192; //'└'
            map[h.r - 5][h.c + 2] = (char)179; //'│'
            map[h.r - 5][h.c + 3] = ' ';       //' '
            map[h.r - 5][h.c + 4] = ' ';       //' '
            map[h.r - 5][h.c + 5] = ' ';       //' '
            map[h.r - 5][h.c + 6] = ' ';       //' '
            map[h.r - 5][h.c + 7] = (char)179; //'│'
            map[h.r - 5][h.c + 8] = (char)217; //'┘'
            map[h.r - 5][h.c + 9] = (char)179; //'│'
            map[h.r - 4][h.c + 0] = (char)192; //'└'
            map[h.r - 4][h.c + 1] = (char)196; //'─'
            map[h.r - 4][h.c + 2] = (char)179; //'│'
            map[h.r - 4][h.c + 3] = ' ';       //' '
            map[h.r - 4][h.c + 4] = ' ';       //' '
            map[h.r - 4][h.c + 5] = ' ';       //' '
            map[h.r - 4][h.c + 6] = ' ';       //' '
            map[h.r - 4][h.c + 7] = (char)179; //'│'
            map[h.r - 4][h.c + 8] = (char)196; //'─'
            map[h.r - 4][h.c + 9] = (char)217; //'┘'
            map[h.r - 3][h.c + 3] = (char)92;  //'\'
            map[h.r - 3][h.c + 4] = (char)196; //'─'
            map[h.r - 3][h.c + 5] = (char)196; //'─'
            map[h.r - 3][h.c + 6] = (char)47;  //'/'
            map[h.r - 2][h.c + 2] = (char)47;  //'/'
            map[h.r - 2][h.c + 3] = (char)47;  //'/'
            map[h.r - 2][h.c + 5] = (char)47;  //'/'
            map[h.r - 2][h.c + 6] = (char)47;  //'/'
            map[h.r - 1][h.c + 2] = (char)92;  //'\'
            map[h.r - 1][h.c + 3] = (char)92;  //'\'
            map[h.r - 1][h.c + 5] = (char)92;  //'\'
            map[h.r - 1][h.c + 6] = (char)92;  //'\'
            map[h.r - 0][h.c + 3] = (char)192; //'└'
            map[h.r - 0][h.c + 4] = (char)217; //'┘'
            map[h.r - 0][h.c + 6] = (char)192; //'└'
            map[h.r - 0][h.c + 7] = (char)217; //'┘'
        }
    }
}

void hero_climb(char map[200][600], hero& h, counter& c, char action)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (c.ct == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218;
            map[h.r - 8][h.c + 4] = (char)196;
            map[h.r - 8][h.c + 5] = (char)196;
            map[h.r - 8][h.c + 6] = (char)191;
            map[h.r - 7][h.c + 0] = (char)218;
            map[h.r - 7][h.c + 1] = (char)191;
            map[h.r - 7][h.c + 2] = (char)32;
            map[h.r - 7][h.c + 3] = (char)179;
            map[h.r - 7][h.c + 4] = (char)32;
            map[h.r - 7][h.c + 5] = (char)32;
            map[h.r - 7][h.c + 6] = (char)179;
            map[h.r - 6][h.c + 0] = (char)179;
            map[h.r - 6][h.c + 1] = (char)192;
            map[h.r - 6][h.c + 2] = (char)32;
            map[h.r - 6][h.c + 3] = (char)92;
            map[h.r - 6][h.c + 4] = (char)32;
            map[h.r - 6][h.c + 5] = (char)32;
            map[h.r - 6][h.c + 6] = (char)47;
            map[h.r - 6][h.c + 7] = (char)32;
            map[h.r - 6][h.c + 8] = (char)218;
            map[h.r - 6][h.c + 9] = (char)191;
            map[h.r - 5][h.c + 0] = (char)192;
            map[h.r - 5][h.c + 1] = (char)196;
            map[h.r - 5][h.c + 2] = (char)179;
            map[h.r - 5][h.c + 3] = (char)32;
            map[h.r - 5][h.c + 4] = (char)32;
            map[h.r - 5][h.c + 5] = (char)32;
            map[h.r - 5][h.c + 6] = (char)32;
            map[h.r - 5][h.c + 7] = (char)179;
            map[h.r - 5][h.c + 8] = (char)217;
            map[h.r - 5][h.c + 9] = (char)179;
            map[h.r - 4][h.c + 2] = (char)179;
            map[h.r - 4][h.c + 3] = (char)32;
            map[h.r - 4][h.c + 4] = (char)32;
            map[h.r - 4][h.c + 5] = (char)32;
            map[h.r - 4][h.c + 6] = (char)32;
            map[h.r - 4][h.c + 7] = (char)179;
            map[h.r - 4][h.c + 8] = (char)196;
            map[h.r - 4][h.c + 9] = (char)217;
            map[h.r - 3][h.c + 3] = (char)92;
            map[h.r - 3][h.c + 4] = (char)196;
            map[h.r - 3][h.c + 5] = (char)196;
            map[h.r - 3][h.c + 6] = (char)47;
            map[h.r - 2][h.c + 3] = (char)179;
            map[h.r - 2][h.c + 4] = (char)179;
            map[h.r - 2][h.c + 5] = (char)179;
            map[h.r - 2][h.c + 6] = (char)179;
            map[h.r - 1][h.c + 3] = (char)179;
            map[h.r - 1][h.c + 4] = (char)179;
            map[h.r - 1][h.c + 5] = (char)192;
            map[h.r - 1][h.c + 6] = (char)217;
            map[h.r - 0][h.c + 3] = (char)192;
            map[h.r - 0][h.c + 4] = (char)217;
        }
        else if (c.ct == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218;
            map[h.r - 8][h.c + 4] = (char)196;
            map[h.r - 8][h.c + 5] = (char)196;
            map[h.r - 8][h.c + 6] = (char)191;
            map[h.r - 7][h.c + 3] = (char)179;
            map[h.r - 7][h.c + 4] = (char)32;
            map[h.r - 7][h.c + 5] = (char)32;
            map[h.r - 7][h.c + 6] = (char)179;
            map[h.r - 7][h.c + 7] = (char)32;
            map[h.r - 7][h.c + 8] = (char)218;
            map[h.r - 7][h.c + 9] = (char)191;
            map[h.r - 6][h.c + 0] = (char)218;
            map[h.r - 6][h.c + 1] = (char)191;
            map[h.r - 6][h.c + 2] = (char)32;
            map[h.r - 6][h.c + 3] = (char)92;
            map[h.r - 6][h.c + 4] = (char)32;
            map[h.r - 6][h.c + 5] = (char)32;
            map[h.r - 6][h.c + 6] = (char)47;
            map[h.r - 6][h.c + 7] = (char)32;
            map[h.r - 6][h.c + 8] = (char)217;
            map[h.r - 6][h.c + 9] = (char)179;
            map[h.r - 5][h.c + 0] = (char)179;
            map[h.r - 5][h.c + 1] = (char)192;
            map[h.r - 5][h.c + 2] = (char)179;
            map[h.r - 5][h.c + 3] = (char)32;
            map[h.r - 5][h.c + 4] = (char)32;
            map[h.r - 5][h.c + 5] = (char)32;
            map[h.r - 5][h.c + 6] = (char)32;
            map[h.r - 5][h.c + 7] = (char)179;
            map[h.r - 5][h.c + 8] = (char)196;
            map[h.r - 5][h.c + 9] = (char)217;
            map[h.r - 4][h.c + 0] = (char)192;
            map[h.r - 4][h.c + 1] = (char)196;
            map[h.r - 4][h.c + 2] = (char)179;
            map[h.r - 4][h.c + 3] = (char)32;
            map[h.r - 4][h.c + 4] = (char)32;
            map[h.r - 4][h.c + 5] = (char)32;
            map[h.r - 4][h.c + 6] = (char)32;
            map[h.r - 4][h.c + 7] = (char)179;
            map[h.r - 3][h.c + 3] = (char)92;
            map[h.r - 3][h.c + 4] = (char)196;
            map[h.r - 3][h.c + 5] = (char)196;
            map[h.r - 3][h.c + 6] = (char)47;
            map[h.r - 2][h.c + 3] = (char)179;
            map[h.r - 2][h.c + 4] = (char)179;
            map[h.r - 2][h.c + 5] = (char)179;
            map[h.r - 2][h.c + 6] = (char)179;
            map[h.r - 1][h.c + 3] = (char)192;
            map[h.r - 1][h.c + 4] = (char)217;
            map[h.r - 1][h.c + 5] = (char)179;
            map[h.r - 1][h.c + 6] = (char)179;
            map[h.r - 0][h.c + 5] = (char)192;
            map[h.r - 0][h.c + 6] = (char)217;
        }
    }
}

void heroR(char map[200][600], hero& h, counter& c, int& weapon, int& weapon2, int& weapon3)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (weapon == 1)
        {
            map[h.r - 6][h.c + 10] = (char)201;
            map[h.r - 6][h.c + 11] = (char)205;
            map[h.r - 6][h.c + 8] = (char)32;   // ' '
            map[h.r - 6][h.c + 9] = (char)32;   // ' '
            map[h.r - 5][h.c + 8] = (char)196;  // ─
            map[h.r - 5][h.c + 9] = (char)196;  // ─
            map[h.r - 5][h.c + 10] = (char)196; // ─
            map[h.r - 5][h.c + 11] = (char)191; // ┐
            map[h.r - 4][h.c + 8] = (char)196;  // ─
            map[h.r - 4][h.c + 9] = (char)196;  // ─
            map[h.r - 4][h.c + 10] = (char)196; // ─
            map[h.r - 4][h.c + 11] = (char)217; // ┘
        }
        else if (weapon2 == 1)
        {
            map[h.r - 6][h.c + 9] = (char)201;
            map[h.r - 6][h.c + 10] = (char)209;
            map[h.r - 6][h.c + 11] = (char)205;
            map[h.r - 5][h.c + 8] = (char)196;  // ─
            map[h.r - 5][h.c + 9] = (char)196;  // ─
            map[h.r - 5][h.c + 10] = (char)196; // ─
            map[h.r - 5][h.c + 11] = (char)191; // ┐
            map[h.r - 4][h.c + 8] = (char)196;  // ─
            map[h.r - 4][h.c + 9] = (char)196;  // ─
            map[h.r - 4][h.c + 10] = (char)196; // ─
            map[h.r - 4][h.c + 11] = (char)217; // ┘
        }
        else if (weapon3 == 1)
        {
            map[h.r - 6][h.c + 9] = (char)209;
            map[h.r - 6][h.c + 10] = (char)216;
            map[h.r - 6][h.c + 11] = (char)205;
            map[h.r - 5][h.c + 8] = (char)196;  // ─
            map[h.r - 5][h.c + 9] = (char)196;  // ─
            map[h.r - 5][h.c + 10] = (char)196; // ─
            map[h.r - 5][h.c + 11] = (char)191; // ┐
            map[h.r - 4][h.c + 8] = (char)196;  // ─
            map[h.r - 4][h.c + 9] = (char)196;  // ─
            map[h.r - 4][h.c + 10] = (char)196; // ─
            map[h.r - 4][h.c + 11] = (char)217; // ┘
        }
        else
        {
            map[h.r - 5][h.c + 8] = (char)196; // ─
            map[h.r - 5][h.c + 9] = (char)191; // ┐
            map[h.r - 4][h.c + 8] = (char)32;  // ' '
            map[h.r - 4][h.c + 9] = (char)179; // │
            map[h.r - 3][h.c + 8] = (char)196; // ─
            map[h.r - 3][h.c + 9] = (char)217; // ┘
        }
        if (c.ct == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218; // ┌
            map[h.r - 8][h.c + 4] = (char)196; // ─
            map[h.r - 8][h.c + 5] = (char)196; // ─
            map[h.r - 8][h.c + 6] = (char)191; // ┐
            map[h.r - 7][h.c + 3] = (char)179; // │
            map[h.r - 7][h.c + 4] = (char)32;  // ' '
            map[h.r - 7][h.c + 5] = (char)111; // o
            map[h.r - 7][h.c + 6] = (char)111; // o
            map[h.r - 7][h.c + 7] = (char)41;  // )
            map[h.r - 6][h.c + 3] = (char)92;  //
            map[h.r - 6][h.c + 4] = (char)32;  // ' '
            map[h.r - 6][h.c + 5] = (char)94;  // ^
            map[h.r - 6][h.c + 6] = (char)47;  // /
            map[h.r - 5][h.c + 0] = (char)218; // ┌
            map[h.r - 5][h.c + 1] = (char)196; // ─
            map[h.r - 5][h.c + 2] = (char)180; // ┤
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // │
            map[h.r - 4][h.c + 0] = (char)179; // │
            map[h.r - 4][h.c + 1] = (char)32;  // ' '
            map[h.r - 4][h.c + 2] = (char)179; // │
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // │
            map[h.r - 3][h.c + 0] = (char)192; // └
            map[h.r - 3][h.c + 1] = (char)196; // ─
            map[h.r - 3][h.c + 2] = (char)32;  // ' '
            map[h.r - 3][h.c + 3] = (char)92;  //
            map[h.r - 3][h.c + 4] = (char)196; // ─
            map[h.r - 3][h.c + 5] = (char)196; // ─
            map[h.r - 3][h.c + 6] = (char)47;  // /
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 2][h.c + 3] = (char)179; // │
            map[h.r - 2][h.c + 4] = (char)41;  // )
            map[h.r - 2][h.c + 5] = (char)32;  // ' '
            map[h.r - 2][h.c + 6] = (char)41;  // )
            map[h.r - 1][h.c + 3] = (char)179; // │
            map[h.r - 1][h.c + 4] = (char)41;  // )
            map[h.r - 1][h.c + 5] = (char)32;  // ' '
            map[h.r - 1][h.c + 6] = (char)41;  // )
            map[h.r - 0][h.c + 3] = (char)192; // └
            map[h.r - 0][h.c + 4] = (char)217; // ┘
            map[h.r - 0][h.c + 5] = (char)196; // ─
            map[h.r - 0][h.c + 6] = (char)217; // ┘
        }
        else if (c.ct == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218; // ┌
            map[h.r - 8][h.c + 4] = (char)196; // ─
            map[h.r - 8][h.c + 5] = (char)196; // ─
            map[h.r - 8][h.c + 6] = (char)191; // ┐
            map[h.r - 7][h.c + 3] = (char)124; // |
            map[h.r - 7][h.c + 4] = (char)32;  // ' '
            map[h.r - 7][h.c + 5] = (char)111; // o
            map[h.r - 7][h.c + 6] = (char)111; // o
            map[h.r - 7][h.c + 7] = (char)41;  // )
            map[h.r - 6][h.c + 3] = (char)92;  //
            map[h.r - 6][h.c + 4] = (char)32;  // ' '
            map[h.r - 6][h.c + 5] = (char)94;  // ^
            map[h.r - 6][h.c + 6] = (char)47;  // /
            map[h.r - 5][h.c + 0] = (char)218; // ┌
            map[h.r - 5][h.c + 1] = (char)196; // ─
            map[h.r - 5][h.c + 2] = (char)179; // │
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // │
            map[h.r - 4][h.c + 0] = (char)179; // │
            map[h.r - 4][h.c + 1] = (char)32;  // ' '
            map[h.r - 4][h.c + 2] = (char)179; // │
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // │
            map[h.r - 3][h.c + 0] = (char)192; // └
            map[h.r - 3][h.c + 1] = (char)196; // ─
            map[h.r - 3][h.c + 2] = (char)32;  // ' '
            map[h.r - 3][h.c + 3] = (char)92;  //
            map[h.r - 3][h.c + 4] = (char)196; // ─
            map[h.r - 3][h.c + 5] = (char)196; // ─
            map[h.r - 3][h.c + 6] = (char)47;  // /
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 2][h.c + 3] = (char)124; // |
            map[h.r - 2][h.c + 4] = (char)32;  // ' '
            map[h.r - 2][h.c + 5] = (char)47;  // /
            map[h.r - 2][h.c + 6] = (char)92;  //
            map[h.r - 1][h.c + 2] = (char)47;  // /
            map[h.r - 1][h.c + 3] = (char)32;  // ' '
            map[h.r - 1][h.c + 4] = (char)124; // |
            map[h.r - 1][h.c + 5] = (char)92;  //
            map[h.r - 1][h.c + 6] = (char)32;  // ' '
            map[h.r - 1][h.c + 7] = (char)92;  //
            map[h.r - 0][h.c + 2] = (char)92;  //
            map[h.r - 0][h.c + 3] = (char)47;  // /
            map[h.r - 0][h.c + 6] = (char)92;  //
            map[h.r - 0][h.c + 7] = (char)47;  // /
        }
        else if (c.ct == 2)
        {
            map[h.r - 8][h.c + 3] = (char)218; // ┌
            map[h.r - 8][h.c + 4] = (char)196; // ─
            map[h.r - 8][h.c + 5] = (char)196; // ─
            map[h.r - 8][h.c + 6] = (char)191; // ┐
            map[h.r - 7][h.c + 3] = (char)179; // │
            map[h.r - 7][h.c + 4] = (char)32;  // ' '
            map[h.r - 7][h.c + 5] = (char)111; // o
            map[h.r - 7][h.c + 6] = (char)111; // o
            map[h.r - 7][h.c + 7] = (char)41;  // )
            map[h.r - 6][h.c + 3] = (char)92;  //
            map[h.r - 6][h.c + 4] = (char)32;  // ' '
            map[h.r - 6][h.c + 5] = (char)94;  // ^
            map[h.r - 6][h.c + 6] = (char)47;  // /
            map[h.r - 5][h.c + 0] = (char)218; // ┌
            map[h.r - 5][h.c + 1] = (char)196; // ─
            map[h.r - 5][h.c + 2] = (char)179; // │
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // │
            map[h.r - 4][h.c + 0] = (char)179; // │
            map[h.r - 4][h.c + 1] = (char)32;  // ' '
            map[h.r - 4][h.c + 2] = (char)179; // │
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // │
            map[h.r - 3][h.c + 0] = (char)192; // └
            map[h.r - 3][h.c + 1] = (char)196; // ─
            map[h.r - 3][h.c + 2] = (char)32;  // ' '
            map[h.r - 3][h.c + 3] = (char)92;  //
            map[h.r - 3][h.c + 4] = (char)196; // ─
            map[h.r - 3][h.c + 5] = (char)196; // ─
            map[h.r - 3][h.c + 6] = (char)47;  // /
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 2][h.c + 3] = (char)92;  //
            map[h.r - 2][h.c + 4] = (char)32;  // ' '
            map[h.r - 2][h.c + 5] = (char)92;  //
            map[h.r - 2][h.c + 6] = (char)47;  // /
            map[h.r - 1][h.c + 3] = (char)47;  // /
            map[h.r - 1][h.c + 4] = (char)92;  //
            map[h.r - 1][h.c + 5] = (char)32;  // ' '
            map[h.r - 1][h.c + 6] = (char)92;  //
            map[h.r - 0][h.c + 3] = (char)92;  //
            map[h.r - 0][h.c + 4] = (char)47;  // /
            map[h.r - 0][h.c + 5] = (char)92;  //
            map[h.r - 0][h.c + 6] = (char)47;  // /
        }

    }
}

void heroL(char map[200][600], hero& h, counter& c, int& weapon, int& weapon2, int& weapon3)
{
    if (h.minr > 0 && h.maxr < 200 && h.minc > 0 && h.maxc < 600)
    {
        if (weapon == 1)
        {
            map[h.r - 6][h.c - 1] = (char)187;
            map[h.r - 6][h.c - 2] = (char)205;
            map[h.r - 5][h.c - 2] = (char)218; // '┌'
            map[h.r - 5][h.c - 1] = (char)196; // '─'
            map[h.r - 5][h.c + 0] = (char)196; // '─'
            map[h.r - 5][h.c + 1] = (char)196; // '─'
            map[h.r - 4][h.c - 2] = (char)192; // '└'
            map[h.r - 4][h.c - 1] = (char)196; // '─'
            map[h.r - 4][h.c + 0] = (char)196; // '─'
            map[h.r - 4][h.c + 1] = (char)196; // '─'
        }
        else if (weapon2 == 1)
        {
            map[h.r - 6][h.c + 0] = (char)187;
            map[h.r - 6][h.c - 1] = (char)209;
            map[h.r - 6][h.c - 2] = (char)205;
            map[h.r - 5][h.c - 2] = (char)218; // '┌'
            map[h.r - 5][h.c - 1] = (char)196; // '─'
            map[h.r - 5][h.c + 0] = (char)196; // '─'
            map[h.r - 5][h.c + 1] = (char)196; // '─'
            map[h.r - 4][h.c - 2] = (char)192; // '└'
            map[h.r - 4][h.c - 1] = (char)196; // '─'
            map[h.r - 4][h.c + 0] = (char)196; // '─'
            map[h.r - 4][h.c + 1] = (char)196; // '─'
        }
        else if (weapon3 == 1)
        {
            map[h.r - 6][h.c + 0] = (char)209;
            map[h.r - 6][h.c - 1] = (char)216;
            map[h.r - 6][h.c - 2] = (char)205;
            map[h.r - 5][h.c - 2] = (char)218; // '┌'
            map[h.r - 5][h.c - 1] = (char)196; // '─'
            map[h.r - 5][h.c + 0] = (char)196; // '─'
            map[h.r - 5][h.c + 1] = (char)196; // '─'
            map[h.r - 4][h.c - 2] = (char)192; // '└'
            map[h.r - 4][h.c - 1] = (char)196; // '─'
            map[h.r - 4][h.c + 0] = (char)196; // '─'
            map[h.r - 4][h.c + 1] = (char)196; // '─'
        }
        else
        {
            map[h.r - 3][h.c + 0] = (char)192; // └
            map[h.r - 3][h.c + 1] = (char)196; // ─
            map[h.r - 3][h.c + 2] = (char)32;  // ' '
            map[h.r - 4][h.c + 0] = (char)179; // │
            map[h.r - 4][h.c + 1] = (char)32;  // ' '
            map[h.r - 5][h.c + 0] = (char)218; // ┌
            map[h.r - 5][h.c + 1] = (char)196; // ─
        }
        if (c.ct == 0)
        {
            map[h.r - 8][h.c + 3] = (char)218; // '┌'
            map[h.r - 8][h.c + 4] = (char)196; // '─'
            map[h.r - 8][h.c + 5] = (char)196; // '─'
            map[h.r - 8][h.c + 6] = (char)191; // '┐'
            map[h.r - 7][h.c + 2] = (char)40;  // '('
            map[h.r - 7][h.c + 3] = (char)111; // 'o'
            map[h.r - 7][h.c + 4] = (char)111; // 'o'
            map[h.r - 7][h.c + 5] = (char)32;  // ' '
            map[h.r - 7][h.c + 6] = (char)179; // '│'
            map[h.r - 7][h.c + 7] = (char)32;  // ' '
            map[h.r - 6][h.c + 3] = (char)92;  // '\'
            map[h.r - 6][h.c + 4] = (char)94;  // '^'
            map[h.r - 6][h.c + 5] = (char)32;  // ' '
            map[h.r - 6][h.c + 6] = (char)47;  // '/'
            map[h.r - 6][h.c + 7] = (char)32;  // ' '
            map[h.r - 5][h.c + 2] = (char)179; // '│'
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // '│'
            map[h.r - 5][h.c + 8] = (char)196; // '─'
            map[h.r - 5][h.c + 9] = (char)191; // '┐'
            map[h.r - 4][h.c + 2] = (char)179; // '│'
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // '│'
            map[h.r - 4][h.c + 8] = (char)32;  // ' '
            map[h.r - 4][h.c + 9] = (char)179; // '│'
            map[h.r - 3][h.c + 3] = (char)92;  // '\'
            map[h.r - 3][h.c + 4] = (char)196; // '─'
            map[h.r - 3][h.c + 5] = (char)196; // '─'
            map[h.r - 3][h.c + 6] = (char)47;  // '/'
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 3][h.c + 8] = (char)196; // '─'
            map[h.r - 3][h.c + 9] = (char)217; // '┘'
            map[h.r - 2][h.c + 3] = (char)40;  // '('
            map[h.r - 2][h.c + 4] = (char)32;  // ' '
            map[h.r - 2][h.c + 5] = (char)40;  // '('
            map[h.r - 2][h.c + 6] = (char)179; // '│'
            map[h.r - 1][h.c + 2] = (char)32;  // ' '
            map[h.r - 1][h.c + 3] = (char)40;  // '('
            map[h.r - 1][h.c + 4] = (char)32;  // ' '
            map[h.r - 1][h.c + 5] = (char)40;  // '('
            map[h.r - 1][h.c + 6] = (char)179; // '│'
            map[h.r - 0][h.c + 3] = (char)192; // '└'
            map[h.r - 0][h.c + 4] = (char)196; // '─'
            map[h.r - 0][h.c + 5] = (char)192; // '└'
            map[h.r - 0][h.c + 6] = (char)217; // '┘'
        }
        else if (c.ct == 1)
        {
            map[h.r - 8][h.c + 3] = (char)218; // '┌'
            map[h.r - 8][h.c + 4] = (char)196; // '─'
            map[h.r - 8][h.c + 5] = (char)196; // '─'
            map[h.r - 8][h.c + 6] = (char)191; // '┐'
            map[h.r - 7][h.c + 2] = (char)40;  // '('
            map[h.r - 7][h.c + 3] = (char)111; // 'o'
            map[h.r - 7][h.c + 4] = (char)111; // 'o'
            map[h.r - 7][h.c + 5] = (char)32;  // ' '
            map[h.r - 7][h.c + 6] = (char)179; // '│'
            map[h.r - 6][h.c + 3] = (char)92;  // '\'
            map[h.r - 6][h.c + 4] = (char)94;  // '^'
            map[h.r - 6][h.c + 5] = (char)32;  // ' '
            map[h.r - 6][h.c + 6] = (char)47;  // '/'
            map[h.r - 6][h.c + 7] = (char)32;  // ' '
            map[h.r - 5][h.c + 2] = (char)179; // '│'
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // '│'
            map[h.r - 5][h.c + 8] = (char)196; // '─'
            map[h.r - 5][h.c + 9] = (char)191; // '┐'
            map[h.r - 4][h.c + 2] = (char)179; // '│'
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // '│'
            map[h.r - 4][h.c + 8] = (char)32;  // ' '
            map[h.r - 4][h.c + 9] = (char)179; // '│'
            map[h.r - 3][h.c + 3] = (char)92;  // '\'
            map[h.r - 3][h.c + 4] = (char)196; // '─'
            map[h.r - 3][h.c + 5] = (char)196; // '─'
            map[h.r - 3][h.c + 6] = (char)47;  // '/'
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 3][h.c + 8] = (char)196; // '─'
            map[h.r - 3][h.c + 9] = (char)217; // '┘'
            map[h.r - 2][h.c + 3] = (char)47;  // '/'
            map[h.r - 2][h.c + 4] = (char)92;  // '\'
            map[h.r - 2][h.c + 5] = (char)32;  // ' '
            map[h.r - 2][h.c + 6] = (char)124; // '|'
            map[h.r - 2][h.c + 7] = (char)32;  // ' '
            map[h.r - 1][h.c + 2] = (char)47;  // '/'
            map[h.r - 1][h.c + 3] = (char)32;  // '\'
            map[h.r - 1][h.c + 4] = (char)47;  // '/'
            map[h.r - 1][h.c + 5] = (char)92;  // '\'
            map[h.r - 1][h.c + 6] = (char)32;  // ' '
            map[h.r - 1][h.c + 7] = (char)92;  // '\'
            map[h.r - 0][h.c + 2] = (char)92;  // '\'
            map[h.r - 0][h.c + 3] = (char)47;  // '/'
            map[h.r - 0][h.c + 4] = (char)32;  // ' '
            map[h.r - 0][h.c + 5] = (char)32;  // ' '
            map[h.r - 0][h.c + 6] = (char)92;  // '\'
            map[h.r - 0][h.c + 7] = (char)47;  // '/'
            map[h.r - 0][h.c + 8] = (char)32;  // ' '
            map[h.r - 0][h.c + 9] = (char)32;  // ' '
        }
        else if (c.ct == 2)
        {
            map[h.r - 8][h.c + 3] = (char)218; // '┌'
            map[h.r - 8][h.c + 4] = (char)196; // '─'
            map[h.r - 8][h.c + 5] = (char)196; // '─'
            map[h.r - 8][h.c + 6] = (char)191; // '┐'
            map[h.r - 7][h.c + 2] = (char)40;  // '('
            map[h.r - 7][h.c + 3] = (char)111; // 'o'
            map[h.r - 7][h.c + 4] = (char)111; // 'o'
            map[h.r - 7][h.c + 5] = (char)32;  // ' '
            map[h.r - 7][h.c + 6] = (char)179; // '│'
            map[h.r - 6][h.c + 3] = (char)92;  // '\'
            map[h.r - 6][h.c + 4] = (char)94;  // '^'
            map[h.r - 6][h.c + 5] = (char)32;  // ' '
            map[h.r - 6][h.c + 6] = (char)47;  // '/'
            map[h.r - 6][h.c + 7] = (char)32;  // ' '
            map[h.r - 5][h.c + 2] = (char)179; // '│'
            map[h.r - 5][h.c + 3] = (char)32;  // ' '
            map[h.r - 5][h.c + 4] = (char)32;  // ' '
            map[h.r - 5][h.c + 5] = (char)32;  // ' '
            map[h.r - 5][h.c + 6] = (char)32;  // ' '
            map[h.r - 5][h.c + 7] = (char)179; // '│'
            map[h.r - 5][h.c + 8] = (char)196; // '─'
            map[h.r - 5][h.c + 9] = (char)191; // '┐'
            map[h.r - 4][h.c + 2] = (char)179; // '│'
            map[h.r - 4][h.c + 3] = (char)32;  // ' '
            map[h.r - 4][h.c + 4] = (char)32;  // ' '
            map[h.r - 4][h.c + 5] = (char)32;  // ' '
            map[h.r - 4][h.c + 6] = (char)32;  // ' '
            map[h.r - 4][h.c + 7] = (char)179; // '│'
            map[h.r - 4][h.c + 8] = (char)32;  // ' '
            map[h.r - 4][h.c + 9] = (char)179; // '│'
            map[h.r - 3][h.c + 3] = (char)92;  // '\'
            map[h.r - 3][h.c + 4] = (char)196; // '─'
            map[h.r - 3][h.c + 5] = (char)196; // '─'
            map[h.r - 3][h.c + 6] = (char)47;  // '/'
            map[h.r - 3][h.c + 7] = (char)32;  // ' '
            map[h.r - 3][h.c + 8] = (char)196; // '─'
            map[h.r - 3][h.c + 9] = (char)217; // '┘'
            map[h.r - 2][h.c + 3] = (char)92;  // '\\'
            map[h.r - 2][h.c + 4] = (char)47;  // '/'
            map[h.r - 2][h.c + 5] = (char)32;  // ' '
            map[h.r - 2][h.c + 6] = (char)47;  // '/'
            map[h.r - 1][h.c + 3] = (char)47;  // '/'
            map[h.r - 1][h.c + 4] = (char)32;  // ' '
            map[h.r - 1][h.c + 5] = (char)47;  // '/'
            map[h.r - 1][h.c + 6] = (char)92;  // '\\'
            map[h.r - 0][h.c + 3] = (char)92;  // '\\'
            map[h.r - 0][h.c + 4] = (char)47;  // '/'
            map[h.r - 0][h.c + 5] = (char)92;  // '\\'
            map[h.r - 0][h.c + 6] = (char)47;  // '/'
        }
    }
}
void hitbox1(char map[200][600], hero& h, enemy& e, bullet& b, counter& c, int& y, int& z, char& w)
{
    if (w == 'r')
    {
        if ((e.r >= h.minr) && (h.maxr >= e.r) && (y + z >= h.minc) && (h.maxc >= y + z))
        {
            h.health -= 10;
            z = -1;
            y = -1;
            w = ' ';
        }
    }
    else if (w == 'l')
    {
        if ((e.r >= h.minr) && (h.maxr >= e.r) && (y - z >= h.minc) && (h.maxc >= y - z))
        {
            h.health -= 10;
            z = -1;
            y = -1;
            w = ' ';
        }
    }
}
void hitbox10(char map[200][600], hero& h, enemy& e, counter& c, knife& k)
{
    if ((k.r >= h.minr) && (h.maxr >= k.r) && (k.c >= h.minc) && (h.maxc >= k.c))
    {
        h.health -= 15;
        k.pos = 19;
    }
}
void enemybullet(char map[200][600], hero& h, enemy& e, counter& c, bullet& b, int& y, int& z, char& w)
{
    if (y == -1)
    {
        y = b.c;
        z++;
        w = e.direction;
    }
    if (map[e.r - 6][y + z + 1] == (char)186)
    {
        z = -1;
        y = -1;
        w = ' ';
    }
    if (map[e.r - 6][y - z - 1] == (char)186)
    {
        z = -1;
        y = -1;
        w = ' ';
    }
    hitbox1(map, h, e, b, c, y, z, w);
    if (w == 'r')
    {
        if (y != -1)
        {
            map[e.r - 6][y + z] = (char)167;
            z += 2;
        }
        if (z == 19)
        {
            z = -1;
            y = -1;
            w = ' ';
        }
    }
    if (w == 'l')
    {
        if (y != -1)
        {
            map[e.r - 6][y - z] = (char)167;
            z += 2;
        }
        if (z == 20)
        {
            z = -1;
            y = -1;
            w = ' ';
        }
    }
}
void enemyR(char map[200][600], hero& h, enemy& e, counter& c, knife& k, bullet b[3], int& y, int& z, char& w)
{
    if (e.minr > 0 && e.maxr < 200 && e.minc > 0 && e.maxc < 600)
    {
        if (e.health == 100)
        {
            map[e.r - 9][e.c + 3] = '1';
            map[e.r - 9][e.c + 4] = '0';
            map[e.r - 9][e.c + 5] = '0';
        }
        else if (e.health == 75)
        {
            map[e.r - 9][e.c + 4] = '7';
            map[e.r - 9][e.c + 5] = '5';
        }
        else if (e.health == 50)
        {
            map[e.r - 9][e.c + 4] = '5';
            map[e.r - 9][e.c + 5] = '0';
        }
        else if (e.health == 25)
        {
            map[e.r - 9][e.c + 4] = '2';
            map[e.r - 9][e.c + 5] = '5';
        }
        if (e.health != 0)
        {
            if (c.cte[e.num] == 0 && e.type == 1)
            {
                map[e.r - 8][e.c + 3] = (char)47;
                map[e.r - 8][e.c + 4] = (char)32;
                map[e.r - 8][e.c + 5] = (char)32;
                map[e.r - 8][e.c + 6] = (char)92;
                map[e.r - 7][e.c + 2] = (char)47;
                map[e.r - 7][e.c + 3] = (char)32;
                map[e.r - 7][e.c + 4] = (char)32;
                map[e.r - 7][e.c + 5] = (char)79;
                map[e.r - 7][e.c + 6] = (char)79;
                map[e.r - 7][e.c + 7] = (char)92;
                map[e.r - 6][e.c + 2] = (char)124;
                map[e.r - 6][e.c + 3] = (char)32;
                map[e.r - 6][e.c + 4] = (char)32;
                map[e.r - 6][e.c + 5] = (char)32;
                map[e.r - 6][e.c + 6] = (char)172;
                map[e.r - 6][e.c + 7] = (char)124;

                // Arms/shoulders
                map[e.r - 5][e.c + 0] = (char)218;
                map[e.r - 5][e.c + 1] = (char)196;
                map[e.r - 5][e.c + 2] = (char)180;
                map[e.r - 5][e.c + 3] = (char)32;
                map[e.r - 5][e.c + 4] = (char)32;
                map[e.r - 5][e.c + 5] = (char)32;
                map[e.r - 5][e.c + 6] = (char)32;
                map[e.r - 5][e.c + 7] = (char)179;
                map[e.r - 5][e.c + 8] = (char)196;
                map[e.r - 5][e.c + 9] = (char)191;

                map[e.r - 4][e.c + 0] = (char)179;
                map[e.r - 4][e.c + 1] = (char)32;
                map[e.r - 4][e.c + 2] = (char)179;
                map[e.r - 4][e.c + 3] = (char)32;
                map[e.r - 4][e.c + 4] = (char)32;
                map[e.r - 4][e.c + 5] = (char)32;
                map[e.r - 4][e.c + 6] = (char)32;
                map[e.r - 4][e.c + 7] = (char)179;
                map[e.r - 4][e.c + 8] = (char)32;
                map[e.r - 4][e.c + 9] = (char)179;

                // Waist
                map[e.r - 3][e.c + 0] = (char)192;
                map[e.r - 3][e.c + 1] = (char)196;
                map[e.r - 3][e.c + 2] = (char)32;
                map[e.r - 3][e.c + 3] = (char)92;
                map[e.r - 3][e.c + 4] = (char)196;
                map[e.r - 3][e.c + 5] = (char)196;
                map[e.r - 3][e.c + 6] = (char)47;
                map[e.r - 3][e.c + 7] = (char)32;
                map[e.r - 3][e.c + 8] = (char)196;
                map[e.r - 3][e.c + 9] = (char)217;

                // Legs
                map[e.r - 2][e.c + 3] = (char)124;
                map[e.r - 2][e.c + 4] = (char)41;
                map[e.r - 2][e.c + 5] = (char)32;
                map[e.r - 2][e.c + 6] = (char)41;

                map[e.r - 1][e.c + 3] = (char)124;
                map[e.r - 1][e.c + 4] = (char)41;
                map[e.r - 1][e.c + 5] = (char)32;
                map[e.r - 1][e.c + 6] = (char)41;

                map[e.r - 0][e.c + 3] = (char)192;
                map[e.r - 0][e.c + 4] = (char)217;
                map[e.r - 0][e.c + 5] = (char)196;
                map[e.r - 0][e.c + 6] = (char)217;
                c.cte[e.num] = 1;
            }
            else if (c.cte[e.num] == 1 && e.type == 1)
            {
                // Head (rows e.r - 8 to e.r - 6)
                map[e.r - 8][e.c + 3] = (char)47;  // '/'
                map[e.r - 8][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 6] = (char)92;  // '\'
                map[e.r - 7][e.c + 2] = (char)47;  // '/'
                map[e.r - 7][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 5] = (char)79;  // 'O'
                map[e.r - 7][e.c + 6] = (char)79;  // 'O'
                map[e.r - 7][e.c + 7] = (char)92;  // '\'
                map[e.r - 6][e.c + 2] = (char)124; // '|'
                map[e.r - 6][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 6] = (char)172; // '¬'
                map[e.r - 6][e.c + 7] = (char)124; // '|'

                // Torso (rows e.r - 5 to e.r - 3)
                map[e.r - 5][e.c + 0] = (char)218; // '┌'
                map[e.r - 5][e.c + 1] = (char)196; // '─'
                map[e.r - 5][e.c + 2] = (char)179; // '│'
                map[e.r - 5][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 6] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 7] = (char)179; // '│'
                map[e.r - 5][e.c + 8] = (char)196; // '─'
                map[e.r - 5][e.c + 9] = (char)191; // '┐'
                map[e.r - 4][e.c + 0] = (char)179; // '│'
                map[e.r - 4][e.c + 1] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 2] = (char)179; // '│'
                map[e.r - 4][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 6] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 4][e.c + 8] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 9] = (char)179; // '│'
                map[e.r - 3][e.c + 0] = (char)192; // '└'
                map[e.r - 3][e.c + 1] = (char)196; // '─'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 6] = (char)47;  // '/'
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 3] = (char)124; // '|'
                map[e.r - 2][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 2][e.c + 5] = (char)47;  // '/'
                map[e.r - 2][e.c + 6] = (char)92;  // '\'
                map[e.r - 1][e.c + 2] = (char)47;  // '/'
                map[e.r - 1][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 4] = (char)124; // '|'
                map[e.r - 1][e.c + 5] = (char)92;  // '\'
                map[e.r - 1][e.c + 6] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 7] = (char)92;  // '\'
                map[e.r - 0][e.c + 2] = (char)92;  // '\'
                map[e.r - 0][e.c + 3] = (char)47;  // '/'
                map[e.r - 0][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 6] = (char)92;  // '\'
                map[e.r - 0][e.c + 7] = (char)47;  // '/'
                c.cte[e.num] = 2;
            }
            else if (c.cte[e.num] == 2 && e.type == 1)
            {
                // Head (rows e.r - 8 to e.r - 6)
                map[e.r - 8][e.c + 3] = (char)47;  // '/'
                map[e.r - 8][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 6] = (char)92;  // '\'
                map[e.r - 7][e.c + 2] = (char)47;  // '/'
                map[e.r - 7][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 5] = (char)79;  // 'O'
                map[e.r - 7][e.c + 6] = (char)79;  // 'O'
                map[e.r - 7][e.c + 7] = (char)92;  // '\'
                map[e.r - 6][e.c + 2] = (char)124; // '|'
                map[e.r - 6][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 6] = (char)172; // '¬'
                map[e.r - 6][e.c + 7] = (char)124; // '|'

                // Torso (rows e.r - 5 to e.r - 3)
                map[e.r - 5][e.c + 0] = (char)218; // '┌'
                map[e.r - 5][e.c + 1] = (char)196; // '─'
                map[e.r - 5][e.c + 2] = (char)179; // '│'
                map[e.r - 5][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 6] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 7] = (char)179; // '│'
                map[e.r - 5][e.c + 8] = (char)196; // '─'
                map[e.r - 5][e.c + 9] = (char)191; // '┐'
                map[e.r - 4][e.c + 0] = (char)179; // '│'
                map[e.r - 4][e.c + 1] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 2] = (char)179; // '│'
                map[e.r - 4][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 5] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 6] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 4][e.c + 8] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 9] = (char)179; // '│'
                map[e.r - 3][e.c + 0] = (char)192; // '└'
                map[e.r - 3][e.c + 1] = (char)196; // '─'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 7] = (char)47;  // '/'
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 3] = (char)92; // '\'
                map[e.r - 2][e.c + 4] = (char)32; // Space (fill)
                map[e.r - 2][e.c + 5] = (char)92; // '\'
                map[e.r - 2][e.c + 6] = (char)47; // '/'
                map[e.r - 1][e.c + 3] = (char)47; // '/'
                map[e.r - 1][e.c + 4] = (char)92; // '\'
                map[e.r - 1][e.c + 5] = (char)32; // Space (fill)
                map[e.r - 1][e.c + 6] = (char)92; // '\'
                map[e.r - 0][e.c + 2] = (char)32; // Space (fill)
                map[e.r - 0][e.c + 3] = (char)92; // '\'
                map[e.r - 0][e.c + 4] = (char)47; // '/'
                map[e.r - 0][e.c + 5] = (char)92; // '\'
                map[e.r - 0][e.c + 6] = (char)47; // '/'
                map[e.r - 0][e.c + 7] = (char)32; // Space (fill)
                c.cte[e.num] = 0;
            }

            if (k.state == 0 && e.type == 2)
            {
                // Small box at e.r - 8
                map[e.r - 8][e.c + 2] = (char)95; //'_'
                map[e.r - 8][e.c + 3] = (char)95; //'_'
                map[e.r - 8][e.c + 4] = (char)95; //'_'
                map[e.r - 8][e.c + 5] = (char)95; //'_'
                map[e.r - 8][e.c + 6] = (char)95; //'_'
                map[e.r - 8][e.c + 7] = (char)95; //'_'
                // Inside small box at e.r - 7
                map[e.r - 7][e.c + 2] = (char)92; //'\'
                map[e.r - 7][e.c + 3] = ' ';      //' '
                map[e.r - 7][e.c + 4] = ' ';      //' '
                map[e.r - 7][e.c + 5] = (char)48; //'0'
                map[e.r - 7][e.c + 6] = (char)48; //'0'
                map[e.r - 7][e.c + 7] = (char)47; //'/'
                // Larger enclosed area boundaries
                map[e.r - 6][e.c + 2] = (char)124; //'|'
                map[e.r - 6][e.c + 6] = (char)169; //'⌐'
                map[e.r - 6][e.c + 7] = (char)124; //'|'
                map[e.r - 6][e.c + 8] = (char)218; //'┌'
                map[e.r - 6][e.c + 9] = (char)191; //'┐'
                map[e.r - 5][e.c + 0] = (char)218; //'┌'
                map[e.r - 5][e.c + 1] = (char)196; //'─'
                map[e.r - 5][e.c + 2] = (char)179; //'│'
                map[e.r - 5][e.c + 7] = (char)179; //'│'
                map[e.r - 5][e.c + 8] = (char)217; //'┘'
                map[e.r - 5][e.c + 9] = (char)179; //'│'
                map[e.r - 4][e.c + 0] = (char)179; //'│'
                map[e.r - 4][e.c + 2] = (char)179; //'│'
                map[e.r - 4][e.c + 7] = (char)179; //'│'
                map[e.r - 4][e.c + 8] = (char)196; //'─'
                map[e.r - 4][e.c + 9] = (char)217; //'┘'
                map[e.r - 3][e.c + 0] = (char)192; //'└'
                map[e.r - 3][e.c + 1] = (char)196; //'─'
            }
            else if (k.state == 1 && e.type == 2)
            {
                // Small box at e.r - 8
                map[e.r - 8][e.c + 2] = (char)95; //'_'
                map[e.r - 8][e.c + 3] = (char)95; //'_'
                map[e.r - 8][e.c + 4] = (char)95; //'_'
                map[e.r - 8][e.c + 5] = (char)95; //'_'
                map[e.r - 8][e.c + 6] = (char)95; //'_'
                map[e.r - 8][e.c + 7] = (char)95; //'_'
                // Inside small box at e.r - 7
                map[e.r - 7][e.c + 2] = (char)92; //'\'
                map[e.r - 7][e.c + 3] = ' ';      //' '
                map[e.r - 7][e.c + 4] = ' ';      //' '
                map[e.r - 7][e.c + 5] = (char)48; //'0'
                map[e.r - 7][e.c + 6] = (char)48; //'0'
                map[e.r - 7][e.c + 7] = (char)47; //'/'
                // Middle structure at e.r - 6
                map[e.r - 6][e.c + 2] = (char)124; //'|'
                map[e.r - 6][e.c + 6] = (char)169; //'⌐'
                map[e.r - 6][e.c + 7] = (char)124; //'|'
                // Inside middle structure at e.r - 6
                map[e.r - 6][e.c + 3] = ' ';  //' '
                map[e.r - 6][e.c + 4] = ' ';  //' '
                map[e.r - 6][e.c + 5] = ' ';  //' '
                map[e.r - 6][e.c + 8] = ' ';  //' '
                map[e.r - 6][e.c + 9] = ' ';  //' '
                map[e.r - 6][e.c + 10] = ' '; //' '
                map[e.r - 6][e.c + 11] = ' '; //' '
                // Larger enclosed area boundaries
                map[e.r - 5][e.c + 0] = (char)218;  //'┌'
                map[e.r - 5][e.c + 1] = (char)196;  //'─'
                map[e.r - 5][e.c + 2] = (char)179;  //'│'
                map[e.r - 5][e.c + 7] = (char)179;  //'│'
                map[e.r - 5][e.c + 8] = (char)196;  //'─'
                map[e.r - 5][e.c + 9] = (char)196;  //'─'
                map[e.r - 5][e.c + 10] = (char)196; //'─'
                map[e.r - 5][e.c + 11] = (char)191; //'┐'
                map[e.r - 4][e.c + 0] = (char)179;  //'│'
                map[e.r - 4][e.c + 2] = (char)179;  //'│'
                map[e.r - 4][e.c + 7] = (char)179;  //'│'
                map[e.r - 4][e.c + 8] = (char)196;  //'─'
                map[e.r - 4][e.c + 9] = (char)196;  //'─'
                map[e.r - 4][e.c + 10] = (char)196; //'─'
                map[e.r - 4][e.c + 11] = (char)217; //'┘'
                map[e.r - 3][e.c + 0] = (char)192;  //'└'
                map[e.r - 3][e.c + 1] = (char)196;  //'─'
                // Inside larger enclosed area (e.r - 5 to e.r - 4)
                map[e.r - 5][e.c + 3] = ' '; //' '
                map[e.r - 5][e.c + 4] = ' '; //' '
                map[e.r - 5][e.c + 5] = ' '; //' '
                map[e.r - 5][e.c + 6] = ' '; //' '
                map[e.r - 4][e.c + 1] = ' '; //' '
                map[e.r - 4][e.c + 3] = ' '; //' '
                map[e.r - 4][e.c + 4] = ' '; //' '
                map[e.r - 4][e.c + 5] = ' '; //' '
                map[e.r - 4][e.c + 6] = ' '; //' '
                // Platform at e.r - 3
                map[e.r - 3][e.c + 3] = (char)92;  //'\'
                map[e.r - 3][e.c + 4] = (char)196; //'─'
                map[e.r - 3][e.c + 5] = (char)196; //'─'
                map[e.r - 3][e.c + 7] = (char)47;  //'/'
            }
            if (c.cte[e.num] == 0 && e.type == 2)
            {

                // Legs
                map[e.r - 2][e.c + 3] = (char)124;
                map[e.r - 2][e.c + 4] = (char)41;
                map[e.r - 2][e.c + 5] = (char)32;
                map[e.r - 2][e.c + 6] = (char)41;

                map[e.r - 1][e.c + 3] = (char)124;
                map[e.r - 1][e.c + 4] = (char)41;
                map[e.r - 1][e.c + 5] = (char)32;
                map[e.r - 1][e.c + 6] = (char)41;

                map[e.r - 0][e.c + 3] = (char)192;
                map[e.r - 0][e.c + 4] = (char)217;
                map[e.r - 0][e.c + 5] = (char)196;
                map[e.r - 0][e.c + 6] = (char)217;
                c.cte[e.num] = 1;
            }

            else if (c.cte[e.num] == 1 && e.type == 2)
            {
                // Legs and gaps between them
                map[e.r - 2][e.c + 3] = (char)92; //'\'
                map[e.r - 2][e.c + 4] = ' ';      //' '
                map[e.r - 2][e.c + 5] = (char)92; //'\'
                map[e.r - 2][e.c + 6] = (char)47; //'/'
                map[e.r - 1][e.c + 3] = (char)47; //'/'
                map[e.r - 1][e.c + 4] = (char)92; //'\'
                map[e.r - 1][e.c + 5] = ' ';      //' '
                map[e.r - 1][e.c + 6] = (char)92; //'\'
                map[e.r - 0][e.c + 3] = (char)92; //'\'
                map[e.r - 0][e.c + 4] = (char)47; //'/'
                map[e.r - 0][e.c + 5] = (char)92; //'\'
                map[e.r - 0][e.c + 6] = (char)47; //'/'
                c.cte[e.num] = 2;
            }
            else if (c.cte[e.num] == 2 && e.type == 2)
            {

                // Legs and gaps between them
                map[e.r - 2][e.c + 3] = (char)124; //'|'
                map[e.r - 2][e.c + 4] = ' ';       //' '
                map[e.r - 2][e.c + 5] = (char)47;  //'/'
                map[e.r - 2][e.c + 6] = (char)92;  //'\'
                map[e.r - 1][e.c + 2] = (char)47;  //'/'
                map[e.r - 1][e.c + 3] = ' ';       //' '
                map[e.r - 1][e.c + 4] = (char)124; //'|'
                map[e.r - 1][e.c + 5] = (char)92;  //'\'
                map[e.r - 1][e.c + 6] = ' ';       //' '
                map[e.r - 1][e.c + 7] = (char)92;  //'\'
                map[e.r - 0][e.c + 2] = (char)92;  //'\'
                map[e.r - 0][e.c + 3] = (char)47;  //'/'
                map[e.r - 0][e.c + 4] = ' ';       //' '
                map[e.r - 0][e.c + 5] = ' ';       //' '
                map[e.r - 0][e.c + 6] = (char)92;  //'\'
                map[e.r - 0][e.c + 7] = (char)47;  //'/'
                c.cte[e.num] = 0;

                if (k.pos == 0)
                {
                    k.r = e.r - 6;
                    k.c = e.c + 11;
                    map[k.r][k.c] = '/';
                    k.r--;
                    k.c += 2;
                    k.state = 1;
                }
                else if (k.pos < 10)
                {
                    map[k.r][k.c] = '/';

                    k.r--;
                    k.c += 2;
                }
                else if (k.pos < 20)
                {
                    map[k.r][k.c] = '/';

                    k.r++;
                    k.c += 2;
                }
                hitbox10(map, h, e, c, k);
                k.pos++;
                if (k.pos == 20)
                {
                    k.pos = 0;
                    k.state = 0;
                }
            }
            if (e.type == 3)
            {
                map[e.r - 6][e.c + 10] = (char)201;
                map[e.r - 6][e.c + 11] = (char)205;
                map[e.r - 6][e.c + 8] = (char)32;   // ' '
                map[e.r - 6][e.c + 9] = (char)32;   // ' '
                map[e.r - 5][e.c + 8] = (char)196;  // ─
                map[e.r - 5][e.c + 9] = (char)196;  // ─
                map[e.r - 5][e.c + 10] = (char)196; // ─
                map[e.r - 5][e.c + 11] = (char)191; // ┐
                map[e.r - 4][e.c + 8] = (char)196;  // ─
                map[e.r - 4][e.c + 9] = (char)196;  // ─
                map[e.r - 4][e.c + 10] = (char)196; // ─
                map[e.r - 4][e.c + 11] = (char)217; // ┘
                b[1].c = e.c + 12;
                enemybullet(map, h, e, c, b[1], y, z, w);
            }
        }
        if (c.cte[e.num] == 0 && e.type == 3)
        {
            map[e.r - 8][e.c + 3] = (char)218; // ┌
            map[e.r - 8][e.c + 4] = (char)196; // ─
            map[e.r - 8][e.c + 5] = (char)196; // ─
            map[e.r - 8][e.c + 6] = (char)191; // ┐
            map[e.r - 7][e.c + 3] = (char)179; // │
            map[e.r - 7][e.c + 4] = (char)32;  // ' '
            map[e.r - 7][e.c + 5] = (char)111; // o
            map[e.r - 7][e.c + 6] = (char)111; // o
            map[e.r - 7][e.c + 7] = (char)41;  // )
            map[e.r - 6][e.c + 3] = (char)92;  //
            map[e.r - 6][e.c + 4] = (char)32;  // ' '
            map[e.r - 6][e.c + 5] = (char)94;  // ^
            map[e.r - 6][e.c + 6] = (char)47;  // /
            map[e.r - 5][e.c + 0] = (char)218; // ┌
            map[e.r - 5][e.c + 1] = (char)196; // ─
            map[e.r - 5][e.c + 2] = (char)180; // ┤
            map[e.r - 5][e.c + 3] = (char)32;  // ' '
            map[e.r - 5][e.c + 4] = (char)32;  // ' '
            map[e.r - 5][e.c + 5] = (char)32;  // ' '
            map[e.r - 5][e.c + 6] = (char)32;  // ' '
            map[e.r - 5][e.c + 7] = (char)179; // │
            map[e.r - 4][e.c + 0] = (char)179; // │
            map[e.r - 4][e.c + 1] = (char)32;  // ' '
            map[e.r - 4][e.c + 2] = (char)179; // │
            map[e.r - 4][e.c + 3] = (char)32;  // ' '
            map[e.r - 4][e.c + 4] = (char)32;  // ' '
            map[e.r - 4][e.c + 5] = (char)32;  // ' '
            map[e.r - 4][e.c + 6] = (char)32;  // ' '
            map[e.r - 4][e.c + 7] = (char)179; // │
            map[e.r - 3][e.c + 0] = (char)192; // └
            map[e.r - 3][e.c + 1] = (char)196; // ─
            map[e.r - 3][e.c + 2] = (char)32;  // ' '
            map[e.r - 3][e.c + 3] = (char)92;  //
            map[e.r - 3][e.c + 4] = (char)196; // ─
            map[e.r - 3][e.c + 5] = (char)196; // ─
            map[e.r - 3][e.c + 6] = (char)47;  // /
            map[e.r - 3][e.c + 7] = (char)32;  // ' '
            map[e.r - 2][e.c + 3] = (char)179; // │
            map[e.r - 2][e.c + 4] = (char)41;  // )
            map[e.r - 2][e.c + 5] = (char)32;  // ' '
            map[e.r - 2][e.c + 6] = (char)41;  // )
            map[e.r - 1][e.c + 3] = (char)179; // │
            map[e.r - 1][e.c + 4] = (char)41;  // )
            map[e.r - 1][e.c + 5] = (char)32;  // ' '
            map[e.r - 1][e.c + 6] = (char)41;  // )
            map[e.r - 0][e.c + 3] = (char)192; // └
            map[e.r - 0][e.c + 4] = (char)217; // ┘
            map[e.r - 0][e.c + 5] = (char)196; // ─
            map[e.r - 0][e.c + 6] = (char)217; // ┘
            c.cte[e.num] = 1;
        }
        else if (c.cte[e.num] == 1 && e.type == 3)
        {
            map[e.r - 8][e.c + 3] = (char)218; // ┌
            map[e.r - 8][e.c + 4] = (char)196; // ─
            map[e.r - 8][e.c + 5] = (char)196; // ─
            map[e.r - 8][e.c + 6] = (char)191; // ┐
            map[e.r - 7][e.c + 3] = (char)124; // |
            map[e.r - 7][e.c + 4] = (char)32;  // ' '
            map[e.r - 7][e.c + 5] = (char)111; // o
            map[e.r - 7][e.c + 6] = (char)111; // o
            map[e.r - 7][e.c + 7] = (char)41;  // )
            map[e.r - 6][e.c + 3] = (char)92;  //
            map[e.r - 6][e.c + 4] = (char)32;  // ' '
            map[e.r - 6][e.c + 5] = (char)94;  // ^
            map[e.r - 6][e.c + 6] = (char)47;  // /
            map[e.r - 5][e.c + 0] = (char)218; // ┌
            map[e.r - 5][e.c + 1] = (char)196; // ─
            map[e.r - 5][e.c + 2] = (char)179; // │
            map[e.r - 5][e.c + 3] = (char)32;  // ' '
            map[e.r - 5][e.c + 4] = (char)32;  // ' '
            map[e.r - 5][e.c + 5] = (char)32;  // ' '
            map[e.r - 5][e.c + 6] = (char)32;  // ' '
            map[e.r - 5][e.c + 7] = (char)179; // │
            map[e.r - 4][e.c + 0] = (char)179; // │
            map[e.r - 4][e.c + 1] = (char)32;  // ' '
            map[e.r - 4][e.c + 2] = (char)179; // │
            map[e.r - 4][e.c + 3] = (char)32;  // ' '
            map[e.r - 4][e.c + 4] = (char)32;  // ' '
            map[e.r - 4][e.c + 5] = (char)32;  // ' '
            map[e.r - 4][e.c + 6] = (char)32;  // ' '
            map[e.r - 4][e.c + 7] = (char)179; // │
            map[e.r - 3][e.c + 0] = (char)192; // └
            map[e.r - 3][e.c + 1] = (char)196; // ─
            map[e.r - 3][e.c + 2] = (char)32;  // ' '
            map[e.r - 3][e.c + 3] = (char)92;  //
            map[e.r - 3][e.c + 4] = (char)196; // ─
            map[e.r - 3][e.c + 5] = (char)196; // ─
            map[e.r - 3][e.c + 6] = (char)47;  // /
            map[e.r - 3][e.c + 7] = (char)32;  // ' '
            map[e.r - 2][e.c + 3] = (char)124; // |
            map[e.r - 2][e.c + 4] = (char)32;  // ' '
            map[e.r - 2][e.c + 5] = (char)47;  // /
            map[e.r - 2][e.c + 6] = (char)92;  //
            map[e.r - 1][e.c + 2] = (char)47;  // /
            map[e.r - 1][e.c + 3] = (char)32;  // ' '
            map[e.r - 1][e.c + 4] = (char)124; // |
            map[e.r - 1][e.c + 5] = (char)92;  //
            map[e.r - 1][e.c + 6] = (char)32;  // ' '
            map[e.r - 1][e.c + 7] = (char)92;  //
            map[e.r - 0][e.c + 2] = (char)92;  //
            map[e.r - 0][e.c + 3] = (char)47;  // /
            map[e.r - 0][e.c + 6] = (char)92;  //
            map[e.r - 0][e.c + 7] = (char)47;  // /
            c.cte[e.num] = 2;
        }
        else if (c.cte[e.num] == 2 && e.type == 3)
        {
            map[e.r - 8][e.c + 3] = (char)218; // ┌
            map[e.r - 8][e.c + 4] = (char)196; // ─
            map[e.r - 8][e.c + 5] = (char)196; // ─
            map[e.r - 8][e.c + 6] = (char)191; // ┐
            map[e.r - 7][e.c + 3] = (char)179; // │
            map[e.r - 7][e.c + 4] = (char)32;  // ' '
            map[e.r - 7][e.c + 5] = (char)111; // o
            map[e.r - 7][e.c + 6] = (char)111; // o
            map[e.r - 7][e.c + 7] = (char)41;  // )
            map[e.r - 6][e.c + 3] = (char)92;  //
            map[e.r - 6][e.c + 4] = (char)32;  // ' '
            map[e.r - 6][e.c + 5] = (char)94;  // ^
            map[e.r - 6][e.c + 6] = (char)47;  // /
            map[e.r - 5][e.c + 0] = (char)218; // ┌
            map[e.r - 5][e.c + 1] = (char)196; // ─
            map[e.r - 5][e.c + 2] = (char)179; // │
            map[e.r - 5][e.c + 3] = (char)32;  // ' '
            map[e.r - 5][e.c + 4] = (char)32;  // ' '
            map[e.r - 5][e.c + 5] = (char)32;  // ' '
            map[e.r - 5][e.c + 6] = (char)32;  // ' '
            map[e.r - 5][e.c + 7] = (char)179; // │
            map[e.r - 4][e.c + 0] = (char)179; // │
            map[e.r - 4][e.c + 1] = (char)32;  // ' '
            map[e.r - 4][e.c + 2] = (char)179; // │
            map[e.r - 4][e.c + 3] = (char)32;  // ' '
            map[e.r - 4][e.c + 4] = (char)32;  // ' '
            map[e.r - 4][e.c + 5] = (char)32;  // ' '
            map[e.r - 4][e.c + 6] = (char)32;  // ' '
            map[e.r - 4][e.c + 7] = (char)179; // │
            map[e.r - 3][e.c + 0] = (char)192; // └
            map[e.r - 3][e.c + 1] = (char)196; // ─
            map[e.r - 3][e.c + 2] = (char)32;  // ' '
            map[e.r - 3][e.c + 3] = (char)92;  //
            map[e.r - 3][e.c + 4] = (char)196; // ─
            map[e.r - 3][e.c + 5] = (char)196; // ─
            map[e.r - 3][e.c + 6] = (char)47;  // /
            map[e.r - 3][e.c + 7] = (char)32;  // ' '
            map[e.r - 2][e.c + 3] = (char)92;  //
            map[e.r - 2][e.c + 4] = (char)32;  // ' '
            map[e.r - 2][e.c + 5] = (char)92;  //
            map[e.r - 2][e.c + 6] = (char)47;  // /
            map[e.r - 1][e.c + 3] = (char)47;  // /
            map[e.r - 1][e.c + 4] = (char)92;  //
            map[e.r - 1][e.c + 5] = (char)32;  // ' '
            map[e.r - 1][e.c + 6] = (char)92;  //
            map[e.r - 0][e.c + 3] = (char)92;  //
            map[e.r - 0][e.c + 4] = (char)47;  // /
            map[e.r - 0][e.c + 5] = (char)92;  //
            map[e.r - 0][e.c + 6] = (char)47;  // /
            c.cte[e.num] = 0;
        }
        if (e.health == 0)
        {
            e.r = 0;
            e.c = 0;
            e.maxr = 0;
            e.maxc = 0;
            e.minr = 0;
            e.minc = 0;
        }
    }
}
void enemyL(char map[200][600], hero& h, enemy& e, counter& c, knife& k, bullet b[3], int& y, int& z, char& w)
{
    if (e.minr > 0 && e.maxr < 200 && e.minc > 0 && e.maxc < 600)
    {
        if (e.health == 100)
        {
            map[e.r - 9][e.c + 1] = '1';
            map[e.r - 9][e.c + 2] = '0';
            map[e.r - 9][e.c + 3] = '0';
        }
        else if (e.health == 75)
        {
            map[e.r - 9][e.c + 2] = '7';
            map[e.r - 9][e.c + 3] = '5';
        }
        else if (e.health == 50)
        {
            map[e.r - 9][e.c + 2] = '5';
            map[e.r - 9][e.c + 3] = '0';
        }
        else if (e.health == 25)
        {
            map[e.r - 9][e.c + 2] = '2';
            map[e.r - 9][e.c + 3] = '5';
        }
        if (e.health != 0)
        {
            if (c.cte[e.num] == 0 && e.type == 1)
            {
                // Head (rows e.r - 8 to e.r - 6)
                map[e.r - 8][e.c + 1] = (char)47;  // '/'
                map[e.r - 8][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 4] = (char)92;  // '\'
                map[e.r - 7][e.c + 0] = (char)47;  // '/'
                map[e.r - 7][e.c + 1] = (char)79;  // 'O'
                map[e.r - 7][e.c + 2] = (char)79;  // 'O'
                map[e.r - 7][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 5] = (char)92;  // '\'
                map[e.r - 6][e.c + 0] = (char)124; // '|'
                map[e.r - 6][e.c + 1] = (char)169; // '⌐'
                map[e.r - 6][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 5] = (char)124; // '|'

                // Torso (rows e.r - 5 to e.r - 3)
                map[e.r - 5][e.c - 2] = (char)218; // '┌'
                map[e.r - 5][e.c - 1] = (char)196; // '─'
                map[e.r - 5][e.c + 0] = (char)179; // '│'
                map[e.r - 5][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 5] = (char)179; // '│'
                map[e.r - 5][e.c + 6] = (char)196; // '─'
                map[e.r - 5][e.c + 7] = (char)191; // '┐'
                map[e.r - 4][e.c - 2] = (char)179; // '│'
                map[e.r - 4][e.c - 1] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 0] = (char)179; // '│'
                map[e.r - 4][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 5] = (char)179; // '│'
                map[e.r - 4][e.c + 6] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 3][e.c - 2] = (char)192; // '└'
                map[e.r - 3][e.c - 1] = (char)196; // '─'
                map[e.r - 3][e.c + 1] = (char)92;  // '\'
                map[e.r - 3][e.c + 2] = (char)196; // '─'
                map[e.r - 3][e.c + 3] = (char)196; // '─'
                map[e.r - 3][e.c + 4] = (char)47;  // '/'
                map[e.r - 3][e.c + 6] = (char)196; // '─'
                map[e.r - 3][e.c + 7] = (char)217; // '┘'

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 1] = (char)40;  // '('
                map[e.r - 2][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 2][e.c + 3] = (char)40;  // '('
                map[e.r - 2][e.c + 4] = (char)179; // '│'
                map[e.r - 1][e.c + 1] = (char)40;  // '('
                map[e.r - 1][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 3] = (char)40;  // '('
                map[e.r - 1][e.c + 4] = (char)179; // '│'
                map[e.r - 0][e.c + 0] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 1] = (char)192; // '└'
                map[e.r - 0][e.c + 2] = (char)196; // '─'
                map[e.r - 0][e.c + 3] = (char)192; // '└'
                map[e.r - 0][e.c + 4] = (char)217; // '┘'
                c.cte[e.num] = 1;
            }
            else if (c.cte[e.num] == 1 && e.type == 1)
            {
                // Head (rows e.r - 8 to e.r - 6)
                map[e.r - 8][e.c + 1] = (char)47;  // '/'
                map[e.r - 8][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 4] = (char)92;  // '\'
                map[e.r - 7][e.c + 0] = (char)47;  // '/'
                map[e.r - 7][e.c + 1] = (char)79;  // 'O'
                map[e.r - 7][e.c + 2] = (char)79;  // 'O'
                map[e.r - 7][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 5] = (char)92;  // '\'
                map[e.r - 6][e.c + 0] = (char)124; // '|'
                map[e.r - 6][e.c + 1] = (char)169; // '⌐'
                map[e.r - 6][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 5] = (char)124; // '|'

                // Torso (rows e.r - 5 to e.r - 3)
                map[e.r - 5][e.c - 2] = (char)218; // '┌'
                map[e.r - 5][e.c - 1] = (char)196; // '─'
                map[e.r - 5][e.c + 0] = (char)179; // '│'
                map[e.r - 5][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 5] = (char)179; // '│'
                map[e.r - 5][e.c + 6] = (char)196; // '─'
                map[e.r - 5][e.c + 7] = (char)191; // '┐'
                map[e.r - 4][e.c - 2] = (char)179; // '│'
                map[e.r - 4][e.c - 1] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 0] = (char)179; // '│'
                map[e.r - 4][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 5] = (char)179; // '│'
                map[e.r - 4][e.c + 6] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 3][e.c - 2] = (char)192; // '└'
                map[e.r - 3][e.c - 1] = (char)196; // '─'
                map[e.r - 3][e.c + 1] = (char)92;  // '\'
                map[e.r - 3][e.c + 2] = (char)196; // '─'
                map[e.r - 3][e.c + 3] = (char)196; // '─'
                map[e.r - 3][e.c + 4] = (char)47;  // '/'
                map[e.r - 3][e.c + 6] = (char)196; // '─'
                map[e.r - 3][e.c + 7] = (char)217; // '┘'

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 1] = (char)47;  // '/'
                map[e.r - 2][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 2][e.c + 3] = (char)47;  // '/'
                map[e.r - 2][e.c + 4] = (char)124; // '|'
                map[e.r - 1][e.c + 0] = (char)47;  // '/'
                map[e.r - 1][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 2] = (char)47;  // '/'
                map[e.r - 1][e.c + 3] = (char)92;  // '\'
                map[e.r - 1][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 5] = (char)92;  // '\'
                map[e.r - 0][e.c + 0] = (char)92;  // '\'
                map[e.r - 0][e.c + 1] = (char)47;  // '/'
                map[e.r - 0][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 4] = (char)92;  // '\'
                map[e.r - 0][e.c + 5] = (char)47;  // '/'
                c.cte[e.num] = 2;
            }
            else if (c.cte[e.num] == 2 && e.type == 1)
            {
                // Head (rows e.r - 8 to e.r - 6)
                map[e.r - 8][e.c + 1] = (char)47;  // '/'
                map[e.r - 8][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 8][e.c + 4] = (char)92;  // '\'
                map[e.r - 7][e.c + 0] = (char)47;  // '/'
                map[e.r - 7][e.c + 1] = (char)79;  // 'O'
                map[e.r - 7][e.c + 2] = (char)79;  // 'O'
                map[e.r - 7][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 7][e.c + 5] = (char)92;  // '\'
                map[e.r - 6][e.c + 0] = (char)124; // '|'
                map[e.r - 6][e.c + 1] = (char)169; // '⌐'
                map[e.r - 6][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 6][e.c + 5] = (char)124; // '|'

                // Torso (rows e.r - 5 to e.r - 3)
                map[e.r - 5][e.c - 2] = (char)218; // '┌'
                map[e.r - 5][e.c - 1] = (char)196; // '─'
                map[e.r - 5][e.c + 0] = (char)179; // '│'
                map[e.r - 5][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 5][e.c + 5] = (char)179; // '│'
                map[e.r - 5][e.c + 6] = (char)196; // '─'
                map[e.r - 5][e.c + 7] = (char)191; // '┐'
                map[e.r - 4][e.c - 2] = (char)179; // '│'
                map[e.r - 4][e.c - 1] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 0] = (char)179; // '│'
                map[e.r - 4][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 4][e.c + 5] = (char)179; // '│'
                map[e.r - 4][e.c + 6] = (char)32;  // Space (fill, arm)
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 3][e.c - 2] = (char)192; // '└'
                map[e.r - 3][e.c - 1] = (char)196; // '─'
                map[e.r - 3][e.c + 1] = (char)92;  // '\'
                map[e.r - 5][e.c + 2] = (char)196; // '─'
                map[e.r - 3][e.c + 3] = (char)196; // '─'
                map[e.r - 3][e.c + 4] = (char)47;  // '/'
                map[e.r - 3][e.c + 6] = (char)196; // '─'
                map[e.r - 3][e.c + 7] = (char)217; // '┘'

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 1] = (char)47;  // '/'
                map[e.r - 2][e.c + 2] = (char)92;  // '\'
                map[e.r - 2][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 2][e.c + 4] = (char)124; // '|'
                map[e.r - 1][e.c + 0] = (char)47;  // '/'
                map[e.r - 1][e.c + 1] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 2] = (char)47;  // '/'
                map[e.r - 1][e.c + 3] = (char)92;  // '\'
                map[e.r - 1][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 5] = (char)92;  // '\'
                map[e.r - 0][e.c + 0] = (char)92;  // '\'
                map[e.r - 0][e.c + 1] = (char)47;  // '/'
                map[e.r - 0][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 3] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 4] = (char)92;  // '\'
                map[e.r - 0][e.c + 5] = (char)47;  // '/'
                c.cte[e.num] = 0;
            }

            if (k.state == 0 && e.type == 2)
            {
                // Small box at e.r - 8
                map[e.r - 8][e.c + 2] = (char)95; //'_'
                map[e.r - 8][e.c + 3] = (char)95; //'_'
                map[e.r - 8][e.c + 4] = (char)95; //'_'
                map[e.r - 8][e.c + 5] = (char)95; //'_'
                map[e.r - 8][e.c + 6] = (char)95; //'_'
                map[e.r - 8][e.c + 7] = (char)95; //'_'
                // Inside small box at e.r - 7
                map[e.r - 7][e.c + 2] = (char)92; //'\'
                map[e.r - 7][e.c + 3] = (char)48; //'0'
                map[e.r - 7][e.c + 4] = (char)48; //'0'
                map[e.r - 7][e.c + 5] = ' ';      //' '
                map[e.r - 7][e.c + 6] = ' ';      //' '
                map[e.r - 7][e.c + 7] = (char)47; //'/'
                // Larger enclosed area boundaries
                map[e.r - 6][e.c + 0] = (char)218; //'┌'
                map[e.r - 6][e.c + 1] = (char)191; //'┐'
                map[e.r - 6][e.c + 2] = (char)124; //'|'
                map[e.r - 6][e.c + 3] = (char)169; //'⌐'
                map[e.r - 6][e.c + 7] = (char)124; //'|'
                map[e.r - 5][e.c + 0] = (char)179; //'│'
                map[e.r - 5][e.c + 1] = (char)192; //'└'
                map[e.r - 5][e.c + 2] = (char)180; //'┤'
                map[e.r - 5][e.c + 7] = (char)179; //'│'
                map[e.r - 5][e.c + 8] = (char)196; //'─'
                map[e.r - 5][e.c + 9] = (char)191; //'┐'
                map[e.r - 4][e.c + 0] = (char)192; //'└'
                map[e.r - 4][e.c + 1] = (char)196; //'─'
                map[e.r - 4][e.c + 2] = (char)179; //'│'
                map[e.r - 4][e.c + 7] = (char)179; //'│'
                map[e.r - 4][e.c + 9] = (char)179; //'│'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 6] = (char)47;  // '/'
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'
            }
            else if (k.state == 1 && e.type == 2)
            {
                // Small box at e.r - 8
                map[e.r - 8][e.c + 2] = (char)95; //'_'
                map[e.r - 8][e.c + 3] = (char)95; //'_'
                map[e.r - 8][e.c + 4] = (char)95; //'_'
                map[e.r - 8][e.c + 5] = (char)95; //'_'
                map[e.r - 8][e.c + 6] = (char)95; //'_'
                map[e.r - 8][e.c + 7] = (char)95; //'_'
                // Inside small box at e.r - 7
                map[e.r - 7][e.c + 2] = (char)92; //'\'
                map[e.r - 7][e.c + 3] = (char)48; //'0'
                map[e.r - 7][e.c + 4] = (char)48; //'0'
                map[e.r - 7][e.c + 5] = ' ';      //' '
                map[e.r - 7][e.c + 6] = ' ';      //' '
                map[e.r - 7][e.c + 7] = (char)47; //'/'
                // Larger enclosed area boundaries

                map[e.r - 6][e.c + 2] = (char)124; //'|'
                map[e.r - 6][e.c + 3] = (char)169; //'⌐'
                map[e.r - 6][e.c + 7] = (char)124; //'|'

                map[e.r - 5][e.c + 2] = (char)180; //'┤'
                map[e.r - 5][e.c + 7] = (char)179; //'│'
                map[e.r - 5][e.c + 8] = (char)196; //'─'
                map[e.r - 5][e.c + 9] = (char)191; //'┐'
                map[e.r - 4][e.c + 2] = (char)179; //'│'
                map[e.r - 4][e.c + 7] = (char)179; //'│'
                map[e.r - 4][e.c + 9] = (char)179; //'│'
                // Inside larger enclosed area (e.r - 6 to e.r - 4)
                map[e.r - 6][e.c + 4] = ' ';       //' '
                map[e.r - 6][e.c + 5] = ' ';       //' '
                map[e.r - 6][e.c + 6] = ' ';       //' '
                map[e.r - 6][e.c + 8] = ' ';       //' '
                map[e.r - 6][e.c + 9] = ' ';       //' '
                map[e.r - 5][e.c - 2] = (char)218; //'┌'
                map[e.r - 5][e.c - 1] = (char)196; //'─'
                map[e.r - 5][e.c + 0] = (char)196; //'─'
                map[e.r - 5][e.c + 1] = (char)196; //'─'
                map[e.r - 5][e.c + 3] = ' ';       //' '
                map[e.r - 5][e.c + 4] = ' ';       //' '
                map[e.r - 5][e.c + 5] = ' ';       //' '
                map[e.r - 5][e.c + 6] = ' ';       //' '
                map[e.r - 4][e.c - 2] = (char)192; //'└'
                map[e.r - 4][e.c - 1] = (char)196; //'─'
                map[e.r - 4][e.c + 0] = (char)196; //'─'
                map[e.r - 4][e.c + 1] = (char)196; //'─'
                map[e.r - 4][e.c + 3] = ' ';       //' '
                map[e.r - 4][e.c + 4] = ' ';       //' '
                map[e.r - 4][e.c + 5] = ' ';       //' '
                map[e.r - 4][e.c + 6] = ' ';       //' '
                map[e.r - 4][e.c + 8] = ' ';       //' '
                // Platform at e.r - 3
                map[e.r - 3][e.c + 3] = (char)92;  //'\'
                map[e.r - 3][e.c + 4] = (char)196; //'─'
                map[e.r - 3][e.c + 5] = (char)196; //'─'
                map[e.r - 3][e.c + 6] = (char)47;  //'/'
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'
            }

            if (c.cte[e.num] == 0 && e.type == 2)
            {

                // Legs (rows e.r - 2 to e.r - 0)
                map[e.r - 2][e.c + 3] = (char)40;  // '('
                map[e.r - 2][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 2][e.c + 5] = (char)40;  // '('
                map[e.r - 2][e.c + 6] = (char)179; // '│'
                map[e.r - 1][e.c + 3] = (char)40;  // '('
                map[e.r - 1][e.c + 4] = (char)32;  // Space (fill)
                map[e.r - 1][e.c + 5] = (char)40;  // '('
                map[e.r - 1][e.c + 6] = (char)179; // '│'
                map[e.r - 0][e.c + 2] = (char)32;  // Space (fill)
                map[e.r - 0][e.c + 3] = (char)192; // '└'
                map[e.r - 0][e.c + 4] = (char)196; // '─'
                map[e.r - 0][e.c + 5] = (char)192; // '└'
                map[e.r - 0][e.c + 6] = (char)217; // '┘'
                c.cte[e.num] = 1;
            }
            else if (c.cte[e.num] == 1 && e.type == 2)
            {

                // Legs and gaps between them
                map[e.r - 2][e.c + 3] = (char)47;  //'/'
                map[e.r - 2][e.c + 4] = ' ';       //' '
                map[e.r - 2][e.c + 5] = (char)47;  //'/'
                map[e.r - 2][e.c + 6] = (char)124; //'|'
                map[e.r - 1][e.c + 2] = (char)47;  //'/'
                map[e.r - 1][e.c + 3] = ' ';       //' '
                map[e.r - 1][e.c + 4] = (char)47;  //'/'
                map[e.r - 1][e.c + 5] = (char)92;  //'\'
                map[e.r - 1][e.c + 6] = ' ';       //' '
                map[e.r - 1][e.c + 7] = (char)92;  //'\'
                map[e.r - 0][e.c + 2] = (char)92;  //'\'
                map[e.r - 0][e.c + 3] = (char)47;  //'/'
                map[e.r - 0][e.c + 4] = ' ';       //' '
                map[e.r - 0][e.c + 5] = ' ';       //' '
                map[e.r - 0][e.c + 6] = (char)92;  //'\'
                map[e.r - 0][e.c + 7] = (char)47;  //'/'
                c.cte[e.num] = 2;
            }
            else if (c.cte[e.num] == 2 && e.type == 2)
            {

                // Legs and gaps between them
                map[e.r - 2][e.c + 3] = (char)47;  //'/'
                map[e.r - 2][e.c + 4] = (char)92;  //'\'
                map[e.r - 2][e.c + 5] = ' ';       //' '
                map[e.r - 2][e.c + 6] = (char)124; //'|'
                map[e.r - 1][e.c + 2] = (char)47;  //'/'
                map[e.r - 1][e.c + 3] = ' ';       //' '
                map[e.r - 1][e.c + 4] = (char)47;  //'/'
                map[e.r - 1][e.c + 5] = (char)92;  //'\'
                map[e.r - 1][e.c + 6] = ' ';       //' '
                map[e.r - 1][e.c + 7] = (char)92;  //'\'
                map[e.r - 0][e.c + 2] = (char)92;  //'\'
                map[e.r - 0][e.c + 3] = (char)47;  //'/'
                map[e.r - 0][e.c + 4] = ' ';       //' '
                map[e.r - 0][e.c + 5] = ' ';       //' '
                map[e.r - 0][e.c + 6] = (char)92;  //'\'
                map[e.r - 0][e.c + 7] = (char)47;  //'/'
                c.cte[e.num] = 0;
                if (k.pos == 0)
                {
                    k.r = e.r - 6;
                    k.c = e.c;
                    map[k.r][k.c] = '\\';
                    k.r--;
                    k.c -= 2;
                    k.state = 1;
                }
                else if (k.pos < 10)
                {
                    map[k.r][k.c] = '\\';

                    k.r--;
                    k.c -= 2;
                }
                else if (k.pos < 20)
                {
                    map[k.r][k.c] = '\\';

                    k.r++;
                    k.c -= 2;
                }
                hitbox10(map, h, e, c, k);
                k.pos++;
                if (k.pos == 20)
                {
                    k.pos = 0;
                    k.state = 0;
                }
            }
            if (e.type == 3)
            {
                map[e.r - 6][e.c - 1] = (char)187;
                map[e.r - 6][e.c - 2] = (char)205;
                map[e.r - 5][e.c - 2] = (char)218; // '┌'
                map[e.r - 5][e.c - 1] = (char)196; // '─'
                map[e.r - 5][e.c + 0] = (char)196; // '─'
                map[e.r - 5][e.c + 1] = (char)196; // '─'
                map[e.r - 4][e.c - 2] = (char)192; // '└'
                map[e.r - 4][e.c - 1] = (char)196; // '─'
                map[e.r - 4][e.c + 0] = (char)196; // '─'
                map[e.r - 4][e.c + 1] = (char)196; // '─'
                b[1].c = e.c - 3;
                enemybullet(map, h, e, c, b[1], y, z, w);
            }
            if (c.cte[e.num] == 0 && e.type == 3)
            {
                map[e.r - 8][e.c + 3] = (char)218; // '┌'
                map[e.r - 8][e.c + 4] = (char)196; // '─'
                map[e.r - 8][e.c + 5] = (char)196; // '─'
                map[e.r - 8][e.c + 6] = (char)191; // '┐'
                map[e.r - 7][e.c + 2] = (char)40;  // '('
                map[e.r - 7][e.c + 3] = (char)111; // 'o'
                map[e.r - 7][e.c + 4] = (char)111; // 'o'
                map[e.r - 7][e.c + 5] = (char)32;  // ' '
                map[e.r - 7][e.c + 6] = (char)179; // '│'
                map[e.r - 7][e.c + 7] = (char)32;  // ' '
                map[e.r - 6][e.c + 3] = (char)92;  // '\'
                map[e.r - 6][e.c + 4] = (char)94;  // '^'
                map[e.r - 6][e.c + 5] = (char)32;  // ' '
                map[e.r - 6][e.c + 6] = (char)47;  // '/'
                map[e.r - 6][e.c + 7] = (char)32;  // ' '
                map[e.r - 5][e.c + 2] = (char)179; // '│'
                map[e.r - 5][e.c + 3] = (char)32;  // ' '
                map[e.r - 5][e.c + 4] = (char)32;  // ' '
                map[e.r - 5][e.c + 5] = (char)32;  // ' '
                map[e.r - 5][e.c + 6] = (char)32;  // ' '
                map[e.r - 5][e.c + 7] = (char)179; // '│'
                map[e.r - 5][e.c + 8] = (char)196; // '─'
                map[e.r - 5][e.c + 9] = (char)191; // '┐'
                map[e.r - 4][e.c + 2] = (char)179; // '│'
                map[e.r - 4][e.c + 3] = (char)32;  // ' '
                map[e.r - 4][e.c + 4] = (char)32;  // ' '
                map[e.r - 4][e.c + 5] = (char)32;  // ' '
                map[e.r - 4][e.c + 6] = (char)32;  // ' '
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 4][e.c + 8] = (char)32;  // ' '
                map[e.r - 4][e.c + 9] = (char)179; // '│'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 6] = (char)47;  // '/'
                map[e.r - 3][e.c + 7] = (char)32;  // ' '
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'
                map[e.r - 2][e.c + 3] = (char)40;  // '('
                map[e.r - 2][e.c + 4] = (char)32;  // ' '
                map[e.r - 2][e.c + 5] = (char)40;  // '('
                map[e.r - 2][e.c + 6] = (char)179; // '│'
                map[e.r - 1][e.c + 2] = (char)32;  // ' '
                map[e.r - 1][e.c + 3] = (char)40;  // '('
                map[e.r - 1][e.c + 4] = (char)32;  // ' '
                map[e.r - 1][e.c + 5] = (char)40;  // '('
                map[e.r - 1][e.c + 6] = (char)179; // '│'
                map[e.r - 0][e.c + 3] = (char)192; // '└'
                map[e.r - 0][e.c + 4] = (char)196; // '─'
                map[e.r - 0][e.c + 5] = (char)192; // '└'
                map[e.r - 0][e.c + 6] = (char)217; // '┘'
                c.cte[e.num] = 1;
            }
            else if (c.cte[e.num] == 1 && e.type == 3)
            {
                map[e.r - 8][e.c + 3] = (char)218; // '┌'
                map[e.r - 8][e.c + 4] = (char)196; // '─'
                map[e.r - 8][e.c + 5] = (char)196; // '─'
                map[e.r - 8][e.c + 6] = (char)191; // '┐'
                map[e.r - 7][e.c + 2] = (char)40;  // '('
                map[e.r - 7][e.c + 3] = (char)111; // 'o'
                map[e.r - 7][e.c + 4] = (char)111; // 'o'
                map[e.r - 7][e.c + 5] = (char)32;  // ' '
                map[e.r - 7][e.c + 6] = (char)179; // '│'
                map[e.r - 6][e.c + 3] = (char)92;  // '\'
                map[e.r - 6][e.c + 4] = (char)94;  // '^'
                map[e.r - 6][e.c + 5] = (char)32;  // ' '
                map[e.r - 6][e.c + 6] = (char)47;  // '/'
                map[e.r - 6][e.c + 7] = (char)32;  // ' '
                map[e.r - 5][e.c + 2] = (char)179; // '│'
                map[e.r - 5][e.c + 3] = (char)32;  // ' '
                map[e.r - 5][e.c + 4] = (char)32;  // ' '
                map[e.r - 5][e.c + 5] = (char)32;  // ' '
                map[e.r - 5][e.c + 6] = (char)32;  // ' '
                map[e.r - 5][e.c + 7] = (char)179; // '│'
                map[e.r - 5][e.c + 8] = (char)196; // '─'
                map[e.r - 5][e.c + 9] = (char)191; // '┐'
                map[e.r - 4][e.c + 2] = (char)179; // '│'
                map[e.r - 4][e.c + 3] = (char)32;  // ' '
                map[e.r - 4][e.c + 4] = (char)32;  // ' '
                map[e.r - 4][e.c + 5] = (char)32;  // ' '
                map[e.r - 4][e.c + 6] = (char)32;  // ' '
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 4][e.c + 8] = (char)32;  // ' '
                map[e.r - 4][e.c + 9] = (char)179; // '│'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 6] = (char)47;  // '/'
                map[e.r - 3][e.c + 7] = (char)32;  // ' '
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'
                map[e.r - 2][e.c + 3] = (char)47;  // '/'
                map[e.r - 2][e.c + 4] = (char)92;  // '\'
                map[e.r - 2][e.c + 5] = (char)32;  // ' '
                map[e.r - 2][e.c + 6] = (char)124; // '|'
                map[e.r - 2][e.c + 7] = (char)32;  // ' '
                map[e.r - 1][e.c + 2] = (char)47;  // '/'
                map[e.r - 1][e.c + 3] = (char)32;  // '\'
                map[e.r - 1][e.c + 4] = (char)47;  // '/'
                map[e.r - 1][e.c + 5] = (char)92;  // '\'
                map[e.r - 1][e.c + 6] = (char)32;  // ' '
                map[e.r - 1][e.c + 7] = (char)92;  // '\'
                map[e.r - 0][e.c + 2] = (char)92;  // '\'
                map[e.r - 0][e.c + 3] = (char)47;  // '/'
                map[e.r - 0][e.c + 4] = (char)32;  // ' '
                map[e.r - 0][e.c + 5] = (char)32;  // ' '
                map[e.r - 0][e.c + 6] = (char)92;  // '\'
                map[e.r - 0][e.c + 7] = (char)47;  // '/'
                map[e.r - 0][e.c + 8] = (char)32;  // ' '
                map[e.r - 0][e.c + 9] = (char)32;  // ' '
                c.cte[e.num] = 2;
            }
            else if (c.cte[e.num] == 2 && e.type == 3)
            {
                map[e.r - 8][e.c + 3] = (char)218; // '┌'
                map[e.r - 8][e.c + 4] = (char)196; // '─'
                map[e.r - 8][e.c + 5] = (char)196; // '─'
                map[e.r - 8][e.c + 6] = (char)191; // '┐'
                map[e.r - 7][e.c + 2] = (char)40;  // '('
                map[e.r - 7][e.c + 3] = (char)111; // 'o'
                map[e.r - 7][e.c + 4] = (char)111; // 'o'
                map[e.r - 7][e.c + 5] = (char)32;  // ' '
                map[e.r - 7][e.c + 6] = (char)179; // '│'
                map[e.r - 6][e.c + 3] = (char)92;  // '\'
                map[e.r - 6][e.c + 4] = (char)94;  // '^'
                map[e.r - 6][e.c + 5] = (char)32;  // ' '
                map[e.r - 6][e.c + 6] = (char)47;  // '/'
                map[e.r - 6][e.c + 7] = (char)32;  // ' '
                map[e.r - 5][e.c + 2] = (char)179; // '│'
                map[e.r - 5][e.c + 3] = (char)32;  // ' '
                map[e.r - 5][e.c + 4] = (char)32;  // ' '
                map[e.r - 5][e.c + 5] = (char)32;  // ' '
                map[e.r - 5][e.c + 6] = (char)32;  // ' '
                map[e.r - 5][e.c + 7] = (char)179; // '│'
                map[e.r - 5][e.c + 8] = (char)196; // '─'
                map[e.r - 5][e.c + 9] = (char)191; // '┐'
                map[e.r - 4][e.c + 2] = (char)179; // '│'
                map[e.r - 4][e.c + 3] = (char)32;  // ' '
                map[e.r - 4][e.c + 4] = (char)32;  // ' '
                map[e.r - 4][e.c + 5] = (char)32;  // ' '
                map[e.r - 4][e.c + 6] = (char)32;  // ' '
                map[e.r - 4][e.c + 7] = (char)179; // '│'
                map[e.r - 4][e.c + 8] = (char)32;  // ' '
                map[e.r - 4][e.c + 9] = (char)179; // '│'
                map[e.r - 3][e.c + 3] = (char)92;  // '\'
                map[e.r - 3][e.c + 4] = (char)196; // '─'
                map[e.r - 3][e.c + 5] = (char)196; // '─'
                map[e.r - 3][e.c + 6] = (char)47;  // '/'
                map[e.r - 3][e.c + 7] = (char)32;  // ' '
                map[e.r - 3][e.c + 8] = (char)196; // '─'
                map[e.r - 3][e.c + 9] = (char)217; // '┘'
                map[e.r - 2][e.c + 3] = (char)47;  // '/'
                map[e.r - 2][e.c + 4] = (char)32;  // ' '
                map[e.r - 2][e.c + 5] = (char)47;  // '/'
                map[e.r - 2][e.c + 6] = (char)124; // '|'
                map[e.r - 2][e.c + 7] = (char)32;  // ' '
                map[e.r - 1][e.c + 2] = (char)47;  // '/'
                map[e.r - 1][e.c + 3] = (char)32;  // ' '
                map[e.r - 1][e.c + 4] = (char)47;  // '/'
                map[e.r - 1][e.c + 5] = (char)92;  // '\'
                map[e.r - 1][e.c + 6] = (char)32;  // ' '
                map[e.r - 1][e.c + 7] = (char)92;  // '\'
                map[e.r - 0][e.c + 2] = (char)92;  // '\'
                map[e.r - 0][e.c + 3] = (char)47;  // '/'
                map[e.r - 0][e.c + 6] = (char)92;  // '\'
                map[e.r - 0][e.c + 7] = (char)47;  // '/'
                c.cte[e.num] = 0;
            }
        }
        if (e.health == 0)
        {
            e.r = 0;
            e.c = 0;
            e.maxr = 0;
            e.maxc = 0;
            e.minr = 0;
            e.minc = 0;
        }
    }
}

void ball(char map[200][600], enemy& e2)
{
    if (e2.minr > 0 && e2.maxr < 200 && e2.minc > 0 && e2.maxc < 600)
    {
        if (e2.health == 100)
        {
            map[e2.r - 2][e2.c - 1] = '1';
            map[e2.r - 2][e2.c] = '0';
            map[e2.r - 2][e2.c + 1] = '0';
        }
        else if (e2.health == 75)
        {
            map[e2.r - 2][e2.c] = '7';
            map[e2.r - 2][e2.c + 1] = '5';
        }
        else if (e2.health == 50)
        {
            map[e2.r - 2][e2.c] = '5';
            map[e2.r - 2][e2.c + 1] = '0';
        }
        else if (e2.health == 25)
        {
            map[e2.r - 2][e2.c] = '2';
            map[e2.r - 2][e2.c + 1] = '5';
        }
        if (e2.health != 0)
        {
            map[e2.r - 1][e2.c - 2] = '/';
            map[e2.r - 1][e2.c - 1] = '*';
            map[e2.r - 1][e2.c] = '*';
            map[e2.r - 1][e2.c + 1] = '*';
            map[e2.r - 1][e2.c + 2] = (char)92;
            map[e2.r][e2.c - 3] = '|';
            map[e2.r][e2.c - 2] = '*';
            map[e2.r][e2.c - 1] = '*';
            map[e2.r][e2.c] = '*';
            map[e2.r][e2.c + 1] = '*';
            map[e2.r][e2.c + 2] = '*';
            map[e2.r][e2.c + 3] = '|';
            map[e2.r + 1][e2.c - 2] = (char)92;
            map[e2.r + 1][e2.c - 1] = '*';
            map[e2.r + 1][e2.c] = '*';
            map[e2.r + 1][e2.c + 1] = '*';
            map[e2.r + 1][e2.c + 2] = '/';
        }
        else if (e2.health == 0)
        {
            e2.r = 0;
            e2.c = 0;
            e2.maxr = 0;
            e2.maxc = 0;
            e2.minr = 0;
            e2.minc = 0;
        }
    }
}

void hitbox(char map[200][600], hero& h, enemy& e)
{
    if (h.maxr >= e.minr && e.maxr >= h.minr && h.maxc >= e.minc && e.maxc >= h.minc && e.type != 3)
    {
        h.health--;
    }
}

void hitbox2(char map[200][600], enemy& e, bullet& b, counter& c, char& abdo, int& k)
{
    if ((b.r >= e.minr) && (e.maxr >= b.r) && (b.c + c.ct3 >= e.minc) && (e.maxc >= b.c - c.ct3))
    {
        e.health -= 25;
        abdo = ' ';
        k = 1;
        b.state = 1;
        c.ct3 = 0;
    }
}

void hitbox3(char map[200][600], int& y, int& z, char& w, enemy& e, bullet& b, counter& c, char& abdo, int& k)
{
    if ((b.r >= e.minr) && (e.maxr >= b.r) && (y + z >= e.minc) && (e.maxc >= y - z))
    {
        e.health -= 25;
        z = -1;
        y = -1;
        w = ' ';
        k = 1;
    }
}

void hitbox4(char map[200][600], char x[30], enemy& e, bullet& b, counter& c, char& abdo, int& k)
{
    if ((b.r >= e.minr) && (e.maxr >= b.r) && (b.c + c.ct3 >= e.minc) && (e.maxc >= b.c - c.ct3))
    {
        e.health -= 50;
        for (int i = 0; i < 31; i++)
        {
            x[i] = ' ';
        }
        c.ct3 = 30;
        k = 1;
    }
}
void trap1(char map[200][600], trap t)
{
    for (int i = 0; i < 2; i++)
    {
        map[t.r][t.c] = '/';
        map[t.r][t.c + 3] = (char)92;
        map[t.r - 1][t.c + 1] = '/';
        map[t.r - 1][t.c + 2] = (char)92;
        t.c += 4;
    }
}

void check_traps(hero& h, trap t[14])
{

    for (int i = 0; i < 14; i++)
    {
        if (h.r - 9 <= t[i].minr && h.r >= t[i].maxr && h.c + 6 >= t[i].minc && h.c <= t[i].maxc)
        {
            if (t[i].type == 1)
            {
                h.health--;
            }
            else if (t[i].type == 2)
            {
                h.health -= 2;
            }
            if (h.c < t[i].c + 1)
            {
                h.c = t[i].c - 8;
                if (h.c < 3)
                {
                    h.c = 3;
                }
            }
            else
            {
                h.c = t[i].c + 4;
                if (h.c + 10 > 597)
                {
                    h.c = 585;
                }
            }
        }
    }
}

void laser(char map[200][600], char x[30], hero& h, enemy e[11], bullet& b, counter& c, char action, int& weapon, int abdo2, char& abdo)
{
    b.c = abdo2;
    int k = 0;
    x[c.ct3] = '-';
    if (map[b.r][b.c + c.ct3 + 1] == (char)186)
    {
        abdo = ' ';
        c.ct3 = 30;
        k = 1;
        for (int i = 0; i < 31; i++)
        {
            x[i] = ' ';
        }
    }
    if (map[b.r][b.c - c.ct3 - 1] == (char)186)
    {
        abdo = ' ';
        c.ct3 = 30;
        k = 1;
        for (int i = 0; i < 31; i++)
        {
            x[i] = ' ';
        }
    }
    if (action == 'a' || action == 'd' || action == 'w' || action == 's')
    {
        for (int i = 0; i < 31; i++)
        {
            x[i] = ' ';
        }
        c.ct3 = 30;
        k = 1;
    }
    for (int i = 0; i < 11; i++)
    {
        hitbox4(map, x, e[i], b, c, abdo, k);
    }
    if (k == 0)
    {
        if (h.direction == 'r')
        {
            for (int i = 0; i < 30; i++)
            {
                if (x[i] == '-')
                {
                    map[b.r][b.c + i] = x[i];
                }
            }
        }
        else if (h.direction == 'l')
        {
            for (int i = 0; i < 30; i++)
            {
                if (x[i] == '-')
                {
                    map[b.r][b.c - i] = x[i];
                }
            }
        }
    }
    c.ct3++;
    if (c.ct3 == 31)
    {
        for (int i = 0; i < 31; i++)
        {
            x[i] = ' ';
        }
    }
}
void onebullet(char map[200][600], hero& h, enemy e[11], bullet& b, counter& c, char action, char direction, int& weapon, int abdo2, char& abdo)
{
    b.c = abdo2;
    int k = 0;
    if (map[b.r][b.c + c.ct3 + 1] == (char)186)
    {
        abdo = ' ';
        k = 1;
        b.state = 1;
    }
    if (map[b.r][b.c - c.ct3 - 1] == (char)186)
    {
        abdo = ' ';
        k = 1;
        b.state = 1;
    }
    for (int i = 0; i < 11; i++)
    {
        hitbox2(map, e[i], b, c, abdo, k);
    }
    if (k == 0)
    {

        if (direction == 'r')
        {
            map[b.r][b.c + c.ct3] = (char)167;
        }
        else if (direction == 'l')
        {
            map[b.r][b.c - c.ct3] = (char)167;
        }
        c.ct3++;
    }
}
void multibullet(char map[200][600], int y[20], int z[20], char w[20], hero& h, enemy e[11], bullet& b, counter& c, char action, int& weapon, int abdo2, char& abdo, int& cttt)
{
    if (action == 'r')
    {
        for (int i = 0; i < 20; i++)
        {
            if (y[i] == -1)
            {
                y[i] = b.c;
                z[i]++;
                w[i] = h.direction;
                break;
            }
        }
    }
}
void drawbullet(char map[200][600], int y[20], int z[20], char w[20], hero& h, enemy e[11], bullet& b, counter& c, char action, int& weapon, int abdo2, char& abdo, int& cttt)
{
    int k = 0;

    for (int i = 0; i < 20; i++)
    {
        if (map[b.r][y[i] + z[i] + 1] == (char)186)
        {
            z[i] = -1;
            y[i] = -1;
            w[i] = ' ';
        }
        if (map[b.r][y[i] - z[i] - 1] == (char)186)
        {
            z[i] = -1;
            y[i] = -1;
            w[i] = ' ';
        }
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                hitbox3(map, y[i], z[i], w[i], e[j], b, c, abdo, k);
            }
        }

        if (w[i] == 'r')
        {
            if (y[i] != -1)
            {
                map[b.r][y[i] + z[i]] = (char)167;
                z[i]++;
            }
            if (z[i] == 19)
            {
                z[i] = -1;
                y[i] = -1;
                w[i] = ' ';
            }
            k = 0;
        }
        if (w[i] == 'l')
        {
            if (y[i] != -1)
            {
                map[b.r][y[i] - z[i]] = (char)167;
                z[i]++;
            }
            if (z[i] == 19)
            {
                z[i] = -1;
                y[i] = -1;
                w[i] = ' ';
            }
        }
    }
}
void auto_move(char map[200][600], hero& h, enemy& e, trap t[14], int& automove)
{
    if (e.c < e.endpos && automove == 0)
    {
        e.c++;
    }
    else
    {
        automove = 1;
        e.c--;
    }

    if (e.c < e.startpos && automove == 1)
    {
        automove = 0;
    }
}

void auto_jump(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], int& i, trap t[14], bullet b[3], table tab[14], counter& c, knife& k, healer heal[8], ladd lad[12], char action, int& weapon, char abdo, char abdo1, int abdo2, int weapon2, int cttt, int weapon3, int& key)
{
    if (e[i].type == 0)
    {
        if (e[i].c + 3 < e[i].endpos && e[i].jumpstate == 0)
        {
            if (e[i].autojump < 14)
            {
                e[i].r--;
                e[i].c++;
            }
            else
            {
                e[i].r++;
                e[i].c++;
            }
            e[i].autojump++;
            if (e[i].autojump >= 28)
            {
                e[i].autojump = 0;
            }
        }
        else
        {
            e[i].jumpstate = 1;
            if (e[i].autojump < 14)
            {
                e[i].r--;
                e[i].c--;
            }
            else
            {
                e[i].r++;
                e[i].c--;
            }
            e[i].autojump++;
            if (e[i].autojump >= 28)
            {
                e[i].autojump = 0;
            }
            if (e[i].c <= e[i].startpos)
            {
                e[i].jumpstate = 0;
            }
        }
    }
}

void drawenemies(char map[200][600], hero& h, enemy e[11], counter& c, knife& k, trap t[14], bullet b[3], int y[2], int z[2], char w[2])
{
    for (int i = 0; i < 9; i++)
    {
        if (e[i].type == 1 || e[i].type == 2 || e[i].type == 3)
        {
            if (e[i].c < e[i].endpos && c.cted[i] == 0)
            {
                e[i].direction = 'r';
                enemyR(map, h, e[i], c, k, b, y[1], z[1], w[1]);
                if (e[i].c + 1 >= e[i].endpos)
                {
                    c.cted[i] = 1;
                }
            }
            else
            {
                e[i].direction = 'l';
                enemyL(map, h, e[i], c, k, b, y[1], z[1], w[1]);

                if (e[i].c < e[i].startpos)
                {
                    c.cted[i] = 0;
                }
            }
        }
        if (e[i].type == 0)
        {
            if (e[i].c < e[i].endpos && c.cted[i] == 0)
            {
                ball(map, e[i]);
                if (e[i].c + 1 >= e[i].endpos)
                {
                    c.cted[i] = 1;
                }
            }
            else
            {
                ball(map, e[i]);
                if (e[i].c < e[i].startpos)
                {
                    c.cted[i] = 0;
                }
            }
        }
    }
    for (int i = 9; i < 11; i++)
    {
        if (e[i].type == 1 || e[i].type == 2 || e[i].type == 3)
        {
            if (e[i].c < e[i].endpos && c.cted[i] == 0)
            {
                e[i].direction = 'r';
                enemyR(map, h, e[i], c, k, b, y[i - 9], z[i - 9], w[i - 9]);
                if (e[i].c + 1 >= e[i].endpos)
                {
                    c.cted[i] = 1;
                }
            }
            else
            {
                e[i].direction = 'l';
                enemyL(map, h, e[i], c, k, b, y[i - 9], z[i - 9], w[i - 9]);

                if (e[i].c < e[i].startpos)
                {
                    c.cted[i] = 0;
                }
            }
        }
        if (e[i].type == 0)
        {
            if (e[i].c < e[i].endpos && c.cted[i] == 0)
            {
                ball(map, e[i]);
                if (e[i].c + 1 >= e[i].endpos)
                {
                    c.cted[i] = 1;
                }
            }
            else
            {
                ball(map, e[i]);
                if (e[i].c < e[i].startpos)
                {
                    c.cted[i] = 0;
                }
            }
        }
    }
}
void move_ladder(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[3], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int& weapon2, int cttt, int& weapon3, int& key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    for (int i = 0; i < 12; i++)
    {
        if (action == 'w' && h.r > lad[i].minr - 1 && h.r < lad[i].maxr + 1 && h.minc > lad[i].minc && h.maxc - 2 < lad[i].maxc)
        {
            lad[i].state = 1;
            if (h.r <= lad[i].minr + 1)
            {
                lad[i].state = 0;
            }
            if (lad[i].state == 1)
            {
                h.r--;
            }
        }
        else if (action == 's' && h.r > lad[i].minr - 5 && h.r < lad[i].maxr + 1 && h.minc > lad[i].minc && h.maxc < lad[i].maxc)
        {
            lad[i].state = 1;
            if (h.r >= lad[i].maxr)
            {
                lad[i].state = 0;
            }
            if (lad[i].state == 1)
            {
                h.r++;
            }
        }
        if (lad[i].state == 1)
        {
            break;
        }
    }
}
void round(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[3], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int& weapon2, int cttt, int& weapon3, int& key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    for (int i = 0; i < 8; i++)
    {
        if (heal[i].d == 'r')
        {
            if (h.r == heal[i].r + 6 && h.c < heal[i].c + 21 && h.c > heal[i].c && action == 'f')
            {
                for (int i = 0; i < 8; i++)
                {
                    if (heal[i].draw == 0)
                    {
                        h.health += heal[i].amount;
                        heal[i].draw = 1;
                        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
                    }
                }
            }
        }
        else if (heal[i].d == 'l')
        {
            if (h.r == heal[i].r + 6 && h.c > heal[i].c - 21 && h.c < heal[i].c && action == 'f')
            {
                for (int i = 0; i < 8; i++)
                {
                    if (heal[i].draw == 0)
                    {
                        h.health += heal[i].amount;
                        heal[i].draw = 1;
                        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
                    }
                }
            }
        }
    }
    if (h.r == 78 && h.c > 228 && h.c < 242 && action == 'f')
    {
        h.r = 38;
        h.c = 254;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    else if (h.r == 38 && h.c > 251 && h.c < 267 && action == 'f')
    {
        h.r = 78;
        h.c = 230;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    if (h.r == 18 && h.c < 254 && h.c > 240 && action == 'f')
    {
        key = 1;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    if (h.r == 198 && h.c > 106 && h.c < 115 && action == 'f')
    {
        weapon = 1;
        weapon2 = 0;
        weapon3 = 0;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    if (h.r == 78 && h.c < 574 && h.c > 560 && action == 'f')
    {
        weapon2 = 1;
        weapon = 0;
        weapon3 = 0;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    if (h.r == 198 && h.c == 20 && action == 'f')
    {
        weapon3 = 1;
        weapon2 = 0;
        weapon = 0;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    if (weapon == 1)
    {
        if (c.ct3 == 14)
        {
            abdo = ' ';
            c.ct3 = 0;
            b[0].state = 1;
        }
    }
    if (action == 'r' && b[0].state == 1)
    {
        abdo = 'r';
        abdo1 = h.direction;
        abdo2 = b[0].c;
        c.ct3 = 0;
    }
    callpos(h, e, t);

    if (h.r + 1 == 10 && h.c <= 16 && h.c > 4 && action == 'f')
    {
        weapon = 1;
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    else
    {
        screen(map, h, tab, heal, lad, elv1, weapon, weapon2, weapon3, key);
    }
    for (int i = 0; i < 11; i++)
    {
        hitbox(map, h, e[i]);
    }
    if (c.ct4 == 1)
    {
        map[b[0].r][b[0].c + c.ct3] = ' ';
        map[b[0].r][b[0].c - c.ct3] = ' ';
    }
    if (h.direction == 'w' && h.c > 71 && h.c < 74 && h.r > 178 && h.r < 199)
    {
        h.jumpstate = 1;
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
        if (h.r - 1 == 177 && (h.c < 71 || h.c > 74))
        {
            h.jumpstate = 0;
        }
    }
    else if (h.direction == 's' && h.c > 71 && h.c < 74 && h.r > 160 && h.r < 199)
    {
        h.jumpstate = 1;
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
        h.jumpstate = 0;
    }
    else if (h.direction == 'w' && h.c > 141 && h.c < 144 && h.r > 178 && h.r < 199)
    {
        h.jumpstate = 1;
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
        h.jumpstate = 0;
    }
    else if (h.direction == 's' && h.c > 141 && h.c < 144 && h.r > 160 && h.r < 199)
    {
        h.jumpstate = 1;
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 400 && h.c < 403 && h.r > 178 && h.r < 199)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 400 && h.c < 403 && h.r > 160 && h.r < 199)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 2 && h.c < 5 && h.r > 158 && h.r < 179)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 2 && h.c < 5 && h.r > 150 && h.r < 179)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 2 && h.c < 5 && h.r > 118 && h.r < 139)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 2 && h.c < 5 && h.r > 110 && h.r < 139)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 380 && h.c < 383 && h.r > 138 && h.r < 159)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 380 && h.c < 383 && h.r > 130 && h.r < 159)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 585 && h.c < 588 && h.r > 118 && h.r < 139)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 585 && h.c < 588 && h.r > 110 && h.r < 139)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 200 && h.c < 203 && h.r > 98 && h.r < 119)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 200 && h.c < 203 && h.r > 90 && h.r < 119)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 420 && h.c < 423 && h.r > 98 && h.r < 119)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 420 && h.c < 423 && h.r > 90 && h.r < 119)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 530 && h.c < 533 && h.r > 78 && h.r < 99)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 530 && h.c < 533 && h.r > 70 && h.r < 99)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 21 && h.c < 24 && h.r > 58 && h.r < 79)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 21 && h.c < 24 && h.r > 50 && h.r < 79)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w' && h.c > 21 && h.c < 24 && h.r > 18 && h.r < 39)
    {
        if (action == 'w' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 'w' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 's' && h.c > 21 && h.c < 24 && h.r > 10 && h.r < 39)
    {
        if (action == 's' && c.ct == 0)
        {
            c.ct = 1;
        }
        else if (action == 's' && c.ct == 1)
        {
            c.ct = 0;
        }
        ladder(map, h, action);
        hero_climb(map, h, c, action);
    }
    else if (h.direction == 'w')
    {
        hero_jump(map, h, c);
    }
    else if (h.jumpdirection == 'r')
    {
        hero_jumpR(map, h, c);
    }
    else if (h.jumpdirection == 'l')
    {
        hero_jumpL(map, h, c);
    }
    else if (h.direction == 's')
    {
        c.ctjump = 1;
        hero_jump(map, h, c);
    }
    else if (h.direction == 'r')
    {
        if (action == 'd')
        {
            c.ct++;
        }
        heroR(map, h, c, weapon, weapon2, weapon3);
        if (c.ct > 2)
        {
            c.ct = 0;
        }
    }
    else if (h.direction == 'l')
    {
        if (action == 'a')
        {
            c.ct++;
        }
        heroL(map, h, c, weapon, weapon2, weapon3);
        if (c.ct > 2)
        {
            c.ct = 0;
        }
    }
    drawenemies(map, h, e, c, k, t, b, enemy3col, enemy3count, enemy3direction);
    for (int i = 0; i < 11; i++)
    {
        if (e[i].type != 0)
        {
            auto_move(map, h, e[i], t, c.automove[i]);
        }
        else
        {
            auto_jump(map, x, y, z, w, h, e, i, t, b, tab, c, k, heal, lad, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key);
        }
    }
    if (action == 'r' && weapon == 1)
    {
        abdo = 'r';
    }
    if (abdo == 'r' && weapon == 1)
    {

        onebullet(map, h, e, b[0], c, action, abdo1, weapon, abdo2, abdo);
        if ((map[b[0].r][b[0].c - c.ct3 - 1] == (char)186) || (map[b[0].r][b[0].c + c.ct3 + 1] == (char)186))
        {
            b[0].state = 1;
        }
        else
        {
            b[0].state = 0;
        }
    }
    if (abdo == 'r' && weapon3 == 1)
    {
        laser(map, x, h, e, b[0], c, action, weapon, abdo2, abdo);
    }
    if (action == 'r' && weapon2 == 1)
    {
        multibullet(map, y, z, w, h, e, b[0], c, action, weapon, abdo2, abdo, cttt);
        cttt++;
        action = ' ';
    }
    if (c.ct3 == 31)
    {
        abdo = ' ';
        c.ct3 = 0;
    }
    action = ' ';
    for (int i = 0; i < 14; i++)
    {
        trap1(map, t[i]);
    }
    
    drawbullet(map, y, z, w, h, e, b[0], c, action, weapon, abdo2, abdo, cttt);
    display(map, h, key);
}

void move(char map[200][600], hero& h, enemy e[3], char action)
{
    if (action == 'd' && map[h.r][h.c + 11] != (char)186)
    {
        h.c++;
    }
    else if (action == 'a' && map[h.r][h.c - 1] != (char)186)
    {
        h.c--;
    }
}

void jump(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[14], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int weapon2, int cttt, int weapon3, int key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    h.jumpstate = 1;
    for (int i = 0; i < 7; i++)
    {

        if (i == 0 && c.jumplimit == 1)
        {
            c.ctjump = 1;
        }
        if (i < 6)
        {
            
            h.r--;
            if (i != 0)
            {
                c.ctjump = 0;
            }
            if (_kbhit())
            {
                action = _getch();
                if (action == 'w' && c.jumplimit == 0)
                {
                    c.jumplimit = 1;
                    i = -1;
                }
            }
        }
        else
        {
            while (1)
            {
               
                if (map[h.r + 1][h.c] == ' ' && h.r < 198)
                {
                    if ((h.r == elv1.r - 1 || h.r == elv1.r - 2 || h.r == elv1.r) && h.minc < elv1.maxc && h.maxc > elv1.minc)
                    {
                        h.r = elv1.r - 1;
                        break;
                    }
                    h.r++;
                    c.ctjump = 1;
                    round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
                    if (_kbhit())
                    {
                        action = _getch();
                        if (action == 'w' && c.jumplimit == 0)
                        {
                            c.jumplimit = 1;
                            i = 0;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
    }
    c.ctjump = 0;
    h.jumpstate = 0;
    c.jumplimit = 0;
    h.jumpdirection = ' ';
    h.direction = 'r';
    c.ct = 0;
}

void jump_right(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[14], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int weapon2, int cttt, int weapon3, int key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    h.jumpdirection = 'r';
    h.jumpstate = 1;
    for (int i = 0; i < 8; i++)
    {
        if (i == 0 && c.jumplimit == 1)
        {
            c.ctjump = 1;
        }
        if (i < 7)
        {
            h.r--;
           
            if (i != 0)
            {
                c.ctjump = 0;
            }
            if (map[h.r][h.c + 11] != (char)186 && map[h.r][h.c + 11] != (char)222)
            {
                h.c++;
            }
            if (_kbhit())
            {
                action = _getch();
                if (action == 'e' && c.jumplimit == 0)
                {
                    c.jumplimit = 1;
                    i = -1;
                }
            }
        }
        else
        {
            while (1)
            {
                
                if (map[h.r + 1][h.c] == ' ' && h.r < 198)
                {

                    h.r++;
                    if (map[h.r][h.c + 11] != (char)186 && map[h.r][h.c + 11] != (char)222)
                    {
                        h.c++;
                    }
                    if ((h.r == elv1.r - 1 || h.r == elv1.r - 2 || h.r == elv1.r || h.r == elv1.r + 1) && h.minc < elv1.maxc && h.maxc > elv1.minc)
                    {
                        h.r = elv1.r - 1;
                        break;
                    }
                    c.ctjump = 1;
                    round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
                    if (_kbhit())
                    {
                        action = _getch();
                        if (action == 'e' && c.jumplimit == 0)
                        {
                            c.jumplimit = 1;
                            i = 0;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
    }
    c.ctjump = 0;
    h.jumpstate = 0;
    c.jumplimit = 0;
    h.jumpdirection = ' ';
    h.direction = 'r';
    c.ct = 0;
}

void jump_left(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[14], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int weapon2, int cttt, int weapon3, int key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    h.jumpdirection = 'l';
    h.direction = 'l';
    h.jumpstate = 1;
    for (int i = 0; i < 8; i++)
    {
        if (i == 0 && c.jumplimit == 1)
        {
            c.ctjump = 1;
        }
        if (i < 7)
        {
            h.r--;
            
            if (i != 0)
            {
                c.ctjump = 0;
            }
            if (map[h.r][h.c - 1] != (char)186 && map[h.r][h.c - 1] != (char)222)
            {
                h.c--;
            }
            if (_kbhit())
            {
                action = _getch();
                if (action == 'q' && c.jumplimit == 0)
                {
                    c.jumplimit = 1;
                    i = -1;
                }
            }
        }
        else
        {
            while (1)
            {
            
                if (map[h.r + 1][h.c] == ' ' && h.r < 199)
                {
                    if ((h.r == elv1.r - 1 || h.r == elv1.r - 2 || h.r == elv1.r) && h.minc < elv1.maxc && h.maxc > elv1.minc)
                    {
                        h.r = elv1.r - 1;
                        break;
                    }
                    h.r++;
                    if (map[h.r][h.c - 1] != (char)186 && map[h.r][h.c - 1] != (char)222)
                    {
                        h.c--;
                    }
                    c.ctjump = 1;
                    round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
                    if (_kbhit())
                    {
                        action = _getch();
                        if (action == 'q' && c.jumplimit == 0)
                        {
                            c.jumplimit = 1;
                            i = 0;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
    }
    c.ctjump = 0;
    h.jumpstate = 0;
    h.jumpdirection = ' ';
    h.direction = 'l';
    c.ct = 0;
}

void gravity(char map[200][600], char x[30], int y[20], int z[20], char w[20], hero& h, enemy e[11], trap t[14], bullet b[3], counter& c, table tab[14], knife& k, healer heal[8], ladd lad[12], elvator& elv1, char& action, int& weapon, char& abdo, char& abdo1, int& abdo2, int weapon2, int cttt, int weapon3, int& key, int enemy3col[2], int enemy3count[2], char enemy3direction[2])
{
    if (h.jumpstate == 0 && c.ladstate == 0 && c.elvstate == 0)
    {
        if (map[h.r + 1][h.c + 4] == ' ' && map[h.r + 1][h.c + 4] != (char)222 && h.r < 199)
        {
            h.r++;
            int pos = h.r;
            while (map[h.r + 1][h.c + 4] == ' ' /*&& map[h.r + 1][h.c + 4] != (char)222*/ && h.r + 2 < 200)
            {
                h.r++;
                round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon, abdo, abdo1, abdo2, weapon2, cttt, weapon3, key, enemy3col, enemy3count, enemy3direction);
            }
            int diff = h.r - pos;
            if (diff > 4)
            {
                h.health -= diff / 2;
            }
            h.jumpdirection = ' ';
            // h.direction = 'r';
            c.ct = 0;
        }
    }
}

int main()
{
    hero h = { 198, 2, 0, 0, 0, 0, 0, 0, 0, 30, 'r', ' ' };
    enemy e0 = { 0, 0, 38, 100, 0, 0, 0, 0, 0, 0, 100, 200, ' ', 100 };
    enemy e1 = { 1, 0, 78, 250, 0, 0, 0, 0, 0, 0, 250, 350, ' ', 100 };
    enemy e2 = { 2, 1, 198, 300, 0, 0, 0, 0, 0, 0, 300, 400, ' ', 100 };
    enemy e3 = { 3, 1, 178, 430, 0, 0, 0, 0, 0, 0, 430, 480, ' ', 100 };
    enemy e4 = { 4, 1, 138, 120, 0, 0, 0, 0, 0, 0, 120, 260, ' ', 100 };
    enemy e5 = { 5, 1, 78, 420, 0, 0, 0, 0, 0, 0, 420, 520, ' ', 100 };
    enemy e6 = { 6, 1, 58, 240, 0, 0, 0, 0, 0, 0, 240, 340, ' ', 100 };
    enemy e7 = { 7, 2, 18, 90, 0, 0, 0, 0, 0, 0, 90, 210, ' ', 100 };
    enemy e8 = { 8, 2, 118, 220, 0, 0, 0, 0, 0, 0, 220, 300, ' ', 100 };
    enemy e9 = { 9, 3, 158, 430, 0, 0, 0, 0, 0, 0, 430, 480, ' ', 100 };
    enemy e10 = { 10, 3, 98, 80, 0, 0, 0, 0, 0, 0, 80, 180, ' ', 100 };
    enemy e[11] = { e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10 };
    elvator elv1 = { 199, 25, 8, 40, 178, 0, 199, 158 };
    trap t0 = { 1, 198, 250, 0, 0, 0, 0 };
    trap t1 = { 1, 198, 270, 0, 0, 0, 0 };
    trap t2 = { 1, 178, 30, 0, 0, 0, 0 };
    trap t3 = { 1, 178, 50, 0, 0, 0, 0 };
    trap t4 = { 1, 178, 250, 0, 0, 0, 0 };
    trap t5 = { 1, 178, 270, 0, 0, 0, 0 };
    trap t6 = { 1, 158, 280, 0, 0, 0, 0 };
    trap t7 = { 1, 158, 300, 0, 0, 0, 0 };
    trap t8 = { 1, 118, 40, 0, 0, 0, 0 };
    trap t9 = { 1, 118, 60, 0, 0, 0, 0 };
    trap t10 = { 1, 138, 480, 0, 0, 0, 0 };
    trap t11 = { 1, 138, 500, 0, 0, 0, 0 };
    trap t12 = { 1, 38, 70, 0, 0, 0, 0 };
    trap t13 = { 1, 38, 90, 0, 0, 0, 0 };
    trap t[14] = { t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 };
    bullet b1 = { 0, 0, 0, 0, 0, ' ', 0, 0 };
    bullet b2 = { 0, 0, 0, 0, 0, ' ', 0, 1 };
    bullet b3 = { 0, 0, 0, 0, 0, ' ', 0, 0 };
    bullet b[3] = { b1, b2, b3 };
    counter c;
    healer h0 = { 192, 590, 3, 'l', 0 };
    healer h1 = { 172, 239, 1, 'r', 0 };
    healer h2 = { 32, 9, 3, 'r', 0 };
    healer h3 = { 72, 9, 1, 'r', 0 };
    healer h4 = { 132, 279, 3, 'r', 0 };
    healer h5 = { 132, 261, 2, 'l', 0 };
    healer h6 = { 92, 324, 1, 'r', 0 };
    healer h7 = { 92, 306, 3, 'l', 0 };
    healer h8 = { 152, 570, 2, 'l', 0 };
    healer heal[9] = { h0, h1, h2, h3, h4, h5, h6, h7, h8 };
    table tab0 = { 198, 93 };  // single bullet
    table tab1 = { 78, 583 };  // multibullet
    table tab2 = { 18, 254 };  // key
    table tab3 = { 178, 232 }; // heal level 1 1
    table tab4 = { 198, 583 }; // heal level 0 1
    table tab5 = { 38, 2 };    // heal level 8 1
    table tab6 = { 78, 2 };
    table tab7 = { 138, 272 };
    table tab8 = { 138, 254 };
    table tab9 = { 98, 317 };
    table tab10 = { 98, 299 };
    table tab11 = { 18, 583 };
    table tab[12] = { tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tab8, tab9, tab10, tab11 };
    ladd l0 = { 198, 71, 179, 71, 198, 83, 0 };
    ladd l1 = { 198, 141, 179, 141, 198, 153, 0 };
    ladd l2 = { 198, 400, 179, 400, 198, 412, 0 };
    ladd l3 = { 178, 2, 159, 2, 178, 14, 0 };
    ladd l4 = { 138, 2, 119, 2, 138, 14, 0 };
    ladd l5 = { 158, 380, 139, 380, 158, 392, 0 };
    ladd l6 = { 138, 585, 119, 585, 138, 597, 0 };
    ladd l7 = { 118, 200, 99, 200, 118, 212, 0 };
    ladd l8 = { 118, 420, 99, 420, 118, 432, 0 };
    ladd l9 = { 98, 530, 79, 530, 98, 542, 0 };
    ladd l10 = { 78, 270, 59, 21, 78, 33, 0 };
    ladd l11 = { 38, 21, 19, 21, 38, 33, 0 };
    ladd lad[12] = { l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11 };
    knife k = { 0, 0, 0 };

    char map[200][600], x[30], action = 'd', abdo = ' ', abdo1 = ' ';
    int weapon1 = 0, weapon2 = 0, weapon3 = 1, multicount = 0, abdo2 = 0, key = 0;
    int y[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, z[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    char w[20] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    int enemy3col[2] = { -1, -1 };
    int enemy3count[2] = { -1, -1 };
    char enemy3direction[2] = { ' ', ' ' };
    int displaycount = 0;
    while (true)
    {
        while (!_kbhit())
        {
            if (displaycount == 0)
            {
                nameofgame();
            }
            else if (displaycount == 1)
            {
                howtoplay();
            }
            else if (displaycount == 2)
            {
                howtowin();
            }
        }

        if (_kbhit())
        {
            action = _getch();

            if (displaycount == 0)
            {
                displaycount = 1;
            }
            else if (action == 'd' && displaycount == 1)
            {
                displaycount = 2;
            }
            else if (action == 'a' && displaycount == 2)
            {
                displaycount = 1;
            }
            else if (action == 'd' && displaycount == 2)
            {
                break;
            }
        }
    }
    while (1)
    {
        if (h.direction == 'r')
        {
            b[0].r = h.r - 6, b[0].c = h.c + 12;
        }
        if (h.direction == 'l')
        {
            b[0].r = h.r - 6, b[0].c = h.c - 3;
        }
        if (e2.direction == 'r')
        {
            b[1].r = e2.r - 6, b[1].c = e2.c + 12;
        }
        if (e2.direction == 'l')
        {
            b[1].r = e2.r - 6, b[1].c = e2.c - 3;
        }
        while (!_kbhit())
        {
            round(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon1, abdo, abdo1, abdo2, weapon2, multicount, weapon3, key, enemy3col, enemy3count, enemy3direction);
            gravity(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon1, abdo, abdo1, abdo2, weapon2, multicount, weapon3, key, enemy3col, enemy3count, enemy3direction);
            if (h.health <= 8)
            {
                gameover();
                break;
            }
        }
        if (h.health <= 8)
        {
            gameover();
            break;
        }
        if (action == 'f' && h.r <= 159 && h.minc > 580 && h.maxc < 600 && key == 1)
        {
            win();
            break;
        }
        action = _getch();

        if (action == 'w' && h.c > 71 && h.c < 74 && h.r > 178 && h.r < 199)
        {
            h.direction = 'w';
        }
        else if (action == 'f' && h.r == 158 && h.minc > 580 && h.maxc < 600 && key == 1)
        {
            win();
            break;
        }
        else if (action == 's' && h.c > 71 && h.c < 74 && h.r > 170 && h.r < 199)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 141 && h.c < 144 && h.r > 178 && h.r < 199)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 141 && h.c < 144 && h.r > 170 && h.r < 199)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 400 && h.c < 403 && h.r > 178 && h.r < 199)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 400 && h.c < 403 && h.r > 170 && h.r < 199)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 2 && h.c < 5 && h.r > 158 && h.r < 179)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 2 && h.c < 5 && h.r > 150 && h.r < 179)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 2 && h.c < 5 && h.r > 118 && h.r < 139)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 2 && h.c < 5 && h.r > 110 && h.r < 139)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 380 && h.c < 383 && h.r > 138 && h.r < 159)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 380 && h.c < 383 && h.r > 130 && h.r < 159)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 585 && h.c < 588 && h.r > 118 && h.r < 139)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 585 && h.c < 588 && h.r > 110 && h.r < 139)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 200 && h.c < 203 && h.r > 98 && h.r < 119)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 200 && h.c < 203 && h.r > 90 && h.r < 119)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 420 && h.c < 423 && h.r > 98 && h.r < 119)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 420 && h.c < 423 && h.r > 90 && h.r < 119)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 530 && h.c < 533 && h.r > 78 && h.r < 99)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 530 && h.c < 533 && h.r > 70 && h.r < 99)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 21 && h.c < 24 && h.r > 58 && h.r < 79)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 21 && h.c < 24 && h.r > 50 && h.r < 79)
        {
            h.direction = 's';
        }
        else if (action == 'w' && h.c > 21 && h.c < 24 && h.r > 18 && h.r < 39)
        {
            h.direction = 'w';
        }
        else if (action == 's' && h.c > 21 && h.c < 24 && h.r > 10 && h.r < 39)
        {
            h.direction = 's';
        }
        else if (action == 'd' && (h.r == 198 || h.r == 178 || h.r == 158 || h.r == 138 || h.r == 118 || h.r == 98 || h.r == 78 || h.r == 58 || h.r == 38 || h.r == 18))
        {
            h.direction = 'r';
            move(map, h, e, action);
        }
        else if (action == 'a' && (h.r == 198 || h.r == 178 || h.r == 158 || h.r == 138 || h.r == 118 || h.r == 98 || h.r == 78 || h.r == 58 || h.r == 38 || h.r == 18))
        {
            h.direction = 'l';
            move(map, h, e, action);
        }
        else if (action == 'e')
        {
            h.jumpdirection = 'r';
            jump_right(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon1, abdo, abdo1, abdo2, weapon2, multicount, weapon3, key, enemy3col, enemy3count, enemy3direction);
        }
        else if (action == 'q')
        {
            h.jumpdirection = 'l';
            jump_left(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon1, abdo, abdo1, abdo2, weapon2, multicount, weapon3, key, enemy3col, enemy3count, enemy3direction);
        }
        else if (action == 'w')
        {
            h.direction = 'w';
            jump(map, x, y, z, w, h, e, t, b, c, tab, k, heal, lad, elv1, action, weapon1, abdo, abdo1, abdo2, weapon2, multicount, weapon3, key, enemy3col, enemy3count, enemy3direction);
        }
        else if (action == 'r' && c.ct3 == 0)
        {
            onebullet(map, h, e, b[0], c, abdo1, action, weapon1, abdo2, abdo);
        }
        else if (action == 'r')
        {
            laser(map, x, h, e, b[0], c, action, weapon3, abdo2, abdo);
        }
        callpos(h, e, t);
        check_traps(h, t);
        if (h.health <= 8)
        {
            gameover();
            break;
        }
    }
    return 0;
}
