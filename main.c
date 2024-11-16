#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int WhereObj(char map[], int map_length, char obj)
{
    for (int i = 0; i < map_length; i++)
    {
        if (map[i] == obj) return i;
    }
    
    return -1;
}

int main(void)
{
    char map[] = 
    "######################\n"
    "#                    #\n"
    "#                    #\n"
    "#                    #\n"
    "#                    #\n"
    "#                 ?  #\n"
    "#                 @  #\n"
    "#                 *  #\n"
    "######################\n";

    const char plr = '@';
    const char plr_part = '*';
    const char obj = '?';

    int map_length = sizeof(map) / sizeof(map[0]);
    int where_plr = WhereObj(map, map_length, plr);
    int where_obj = WhereObj(map, map_length, obj);

    int move = where_plr - where_obj;
    int new_pos;
    char ch;

    map[where_obj] = ' ';

    // printf("%d\n", where_plr);
    // printf("%d\n", where_obj);
    // printf("%d\n", move);

    // return 0;

    while (1)
    {
        system("cls");
        printf("%s", map);
        where_plr = WhereObj(map, map_length, plr);
        if (where_plr == -1) break;

        ch = _getch();
        new_pos = where_plr;
        if (ch == 27) break;
        else if (ch == 'w') new_pos -= move;
        else if (ch == 'a') new_pos -= 1;
        else if (ch == 's' ) new_pos += move;
        else if (ch == 'd' ) new_pos += 1;


        if (map[new_pos] != '#')
        {
            map[where_plr] = ' ';
            map[new_pos] = plr;
        }
    }
    

    return 0;
}