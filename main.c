#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int WhereObj(char map[], int map_length, char obj)
{
    for (int i = 0; i < map_length; i++)
    {
        if (map[i] == obj) return i;
    }
    
    return -1;
}

int RandomInRange(int min, int max) 
{
    return rand() % (max - min + 1) + min;
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
    const char food = '$';

    int map_length = sizeof(map) / sizeof(map[0]);
    int where_plr = WhereObj(map, map_length, plr);
    int where_obj = WhereObj(map, map_length, obj);

    int move = where_plr - where_obj;
    int new_pos;
    char ch;

    int how_many_food = 0;
    const int max_food = 5;

    map[where_obj] = ' ';

    for (int i = 0; i < max_food; i++)
    {
        while (1) 
        {
            int rand_loc = RandomInRange(0, map_length - 1);
            if (map[rand_loc] == ' ') 
            {
                map[rand_loc] = food;
                break;
            }
        }
    }


    while (1)
    {
        system("cls");
        printf("money: %d%c\n", how_many_food, food);
        printf("%s", map);
        where_plr = WhereObj(map, map_length, plr);
        if (where_plr == -1 || how_many_food == max_food) break;

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
            how_many_food = map[new_pos] == food ? how_many_food + 1 : how_many_food;
            map[new_pos] = plr;
        }
    }
    

    return 0;
}