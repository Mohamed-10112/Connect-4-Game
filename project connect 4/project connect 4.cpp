#include <bits/stdc++.h>
#include <Windows.h>
#define loopi(x) for(int i=0 ; i < x;i++)
#define loopj(y) for(int j=0 ; j < y;j++)
#define color(c) SetConsoleTextAttribute(m, c)
#define Mohamed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
char board[8][8];
bool game_end = 0, end_game = 0;
int player = 1, row_index = 7, wrong = 0, choice, num, x;
char start, mo1;
string input;
void print() {
    if (wrong == 0) {
        system("cls");
        color(2); cout << "\t\t\t\t\t      **** ";
        color(14); cout << "Welcome in connect 4";
        color(2); cout << " ****\n\n";
        color(8);
        cout << "\t\t\t\t      --1-- --2-- --3-- --4-- --5-- --6-- --7-- --8-- \n";
        loopi(8)
        {
            loopj(9)
            {
                if (j != 8) {
                    color(11);
                    if (j == 0)
                        cout << "                                   ";
                    cout << "  |  ";
                    if (board[i][j] == 'X') {
                        color(2);
                        cout << board[i][j];
                    }
                    else { color(14); cout << board[i][j]; }
               }
                else { color(11); cout << "  |"; }
            }
            if (i != 7)  cout << "\n\t\t\t\t     |     |     |     |     |     |     |     |     |\n";
        }
        color(13); cout << "\n\t\t\t\t      ----- ----- ----- ----- ----- ----- ----- -----\n";
    }
    else { color(4); cout << "\t\t\t\t      Wrong input!\n"; }
}
//===============================================================================================================
void play(int num) {
    wrong = 0;
    if (row_index >= 0) {
        if (board[row_index][num] == 'X' || board[row_index][num] == 'O') {
            row_index--;
            play(num);
        }
        else {
            if (player == 1 && choice == 2) {
                board[row_index][num] = 'X';
            }
            else if (player == 2 && choice == 2) {
                board[row_index][num] = 'O';

            }
            else if (player == 1 && choice == 1) {
                if (mo1 == 'o' || mo1 == 'O') {
                     board[row_index][num] = 'O';
                }
                else {
                    board[row_index][num] = 'X';
                }
            }
            else if (player == 2 && choice == 1) {
                if (mo1 == 'o' || mo1 == 'O') {
                    board[row_index][num] = 'X';
                }
                else {
                    board[row_index][num] = 'O';
                }
            }

            row_index = 7;
        }
    }
    else {
        wrong++;
        player == 1 ? player = 2 : player = 1;
        row_index = 7;
    }
}
//================================================================================================================
int c = 0;
void print_win() {
    print();
    if (choice == 1)
    {
        if (player == 1) {
            mo1 == 'x' || mo1 == 'X' ? color(2) : color(14);
            cout << "\n\t\t\t\t\t\t     ***  YOU WIN! ***\n\n";
            PlaySound(TEXT("mo1.wav"), NULL, SND_SYNC);
        }
        else {
            color(4);  cout << "\n\t\t\t\t\t\t     *** YOU LOSE! ***\n\n";
            PlaySound(TEXT("mo3.wav"), NULL, SND_SYNC);
        }
    }
    else {
        if (player == 1) {
            color(2);
            cout << "\n\t\t\t\t\t\t  **player " << player << " is winner!**\n\n";
            PlaySound(TEXT("mo1.wav"), NULL, SND_SYNC);

        }
        else {
            color(14);
            cout << "\n\t\t\t\t\t\t  **player " << player << " is winner!**\n\n";
            PlaySound(TEXT("mo1.wav"), NULL, SND_SYNC);
        }
    }
    game_end = 1;
    c++;
}
//================================================================================================================
void winner() {
    c = 0;
    // horizontal
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X') { print_win(); }
            else if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' && board[i][j + 3] == 'O') { print_win(); }
        }
    }
    // vertical
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 7; j++) {
            if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X') { print_win(); }
            else if (board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O' && board[i + 3][j] == 'O') { print_win(); }
        }
    }
    // left diagonal
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X') { print_win(); }
            else if (board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O' && board[i + 3][j + 3] == 'O') { print_win(); }
        }
    }
    // right diagonal
    for (int i = 0; i <= 4; i++) {
        for (int j = 3; j <= 7; j++) {
            if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X' && board[i + 3][j - 3] == 'X') { print_win(); }
            else if (board[i][j] == 'O' && board[i + 1][j - 1] == 'O' && board[i + 2][j - 2] == 'O' && board[i + 3][j - 3] == 'O') { print_win(); }
        }
    }
}
//================================================================================================================
void game_ended() {
    color(14); cout << "\n\t\t\t\t\t   *********** Game Ended! ***********\n\n";
    color(7);
}
//================================================================================================================
int draw = 0;
void check_draw() {
    draw = 0;
    if (c == 0) {
        loopi(8) {
            loopj(8) {
                if (board[i][j] != 'X' && board[i][j] != 'O') { draw++; }
            }
        }
        if (draw == 0) {
            print();
            color(11); cout << "\n\t\t\t\t\t   *********** Game is draw! ***********\n\n";
            game_end = 1;
        }
    }
}
//================================================================================================================
void ai(int x) {   
    srand(time(0));
    x = rand() % 8;
    play(x);
}
//================================================================================================================
void start_game() {
    end_game = 0;
    cout << "\t\t\t  ";
    loopi(71) {
        if (i % 2 == 0) { color(14); cout << "-"; }
        else { color(10); cout << "-"; }
    }
    color(13); cout << "\n\t\t\t |\t\t\t\t\t\t\t\t\t |\n"; cout << "\t\t\t |";
    color(11); cout << "    ---------------------------------------------------------------    ";
    color(13); cout << "|\n"; cout << "\t\t\t |   |\t\t\t\t\t\t\t\t     |   |\n"; cout << "\t\t\t |   |";
    color(10); cout << "         W E L C O M E * T O * T H E * G A M E * O F . . .     ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(11); cout << "---------------------------------------------------------------";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "     ####    ###    #    #  #    #  ########    ####  #######  ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "   ##      #     #  ##   #  ##   #  #         ##         #     ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "  ##      #       # #  # #  #  # #  #####    ##          #     ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "   ##      #     #  #   ##  #   ##  #         ##         #     ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "     ####    ###    #    #  #    #  ########    ####     #     ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                               ##                              ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                              ###                              ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                             ####                              ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                            ## ##                              ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                           ########                            ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(14); cout << "                               ##                              ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(11); cout << "---------------------------------------------------------------";
    color(13); cout << "|   |\n"; cout << "\t\t\t |   |";
    color(10); cout << "               E N J O Y * W I T H * P L A Y I N G             ";
    color(13); cout << "|   |\n"; cout << "\t\t\t |";
    color(11); cout << "    ---------------------------------------------------------------    ";
    color(13); cout << "|\n"; cout << "\t\t\t |\t\t\t\t\t\t\t\t\t |\n"; cout << "\t\t\t  ";

    loopi(71) {
        if (i % 2 == 0) { color(14); cout << "-"; }
        else { color(10); cout << "-"; }
    }
    color(11); cout << "\n\t\t\t\t\t\t      *------------*\n\t\t\t\t\t\t      |";
    color(9); cout << " START -> S ";
    color(11); cout << "|\n"; cout << "\t\t\t\t\t\t      *------------*\n";
    cout << "\t\t\t\t\t       Press any key to end game...\n";
    cout << "\t\t\t\t\t       => ";
    PlaySound(TEXT("mo2.wav"), NULL, SND_SYNC);
    color(9); cin >> start;
  
    start != 'S' && start != 's' ? end_game = 1 : end_game = 0;
}
//================================================================================================================
void print_choose() {
    system("cls");
    color(2); cout << "\t\t\t\t\t       **";
    color(14); cout << "Choose from two options";
    color(2); cout << "**\n\n";
    color(11); cout << "\t\t\t\t     *------------*                    *------------*\n\t\t\t\t     |";
    color(9); cout << "1 Player-> 1";
    color(11); cout << "|                    |";
    color(9); cout << "2 Player-> 2";
    color(11); cout << "|\n\t\t\t\t     *------------*                    *------------*\n";
    cout << "\t\t\t\t     Press any key to end game...\n\t\t\t\t     => ";
    color(9); cin >> choice;
    if (choice == 1) {
        while (mo1 != 'o' && mo1 != 'O' && mo1 != 'x' && mo1 != 'X') {
            system("cls");
            color(2); cout << "\t\t\t\t\t  **";
            color(14); cout << "Choose a character to play with X or O"; color(2); cout << "**\n";
            color(11); cout << "\t\t\t\t\t\t    -----\t      -----\n"; cout << "\t\t\t\t\t\t   |"; color(9); cout << "  X  ";
            color(11); cout << "|\t     |"; color(9); cout << "  O  "; color(11); cout << "|\n";
            cout << "\t\t\t\t\t\t    -----\t      -----\n";
            cout << "\t\t\t\t\t\t    => "; color(9); cin >> mo1;
        }

    }
}
//=================================================================================================================
char ans;
void restart_game() {
    end_game = 0;
    color(11); cout << "\t\t\t\t\t\t      *-------------*\n\t\t\t\t\t\t      |";
    color(9); cout << "RESTART ==> R";
    color(11); cout << "|\n\t\t\t\t\t\t      *-------------*\n";
    cout << "\t\t\t\t\t        Press any key to end game...\n\t\t\t\t\t        => ";
    color(9); cin >> ans;
    ans == 'r' || ans == 'R' ? game_end = 0 : end_game = 1;
    mo1 = 'l';
}
bool restart = 1;
int main()
{
    Mohamed;
    start_game();
    if (end_game == 1) { game_ended(); return 0; }
    while (restart) {
        player = 1;
        loopi(8)
            loopj(8)
            board[i][j] = ' ';
        print_choose();
        if (choice == 2) {
            while (!game_end) {
                print();
                player == 1 ? color(2) : color(14);
                cout << "\t\t\t\t      Player " << player << ": ";
                cin >> input;
                while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8") {
                    color(4); cout << "\t\t\t\t      Wrong input!\n";
                    player == 1 ? color(2) : color(14); cout << "\t\t\t\t      Player " << player << ": "; cin >> input;
                }
                stringstream st;
                st << input;
                st >> num;
                play(num - 1);
                winner();
                check_draw();
                player == 1 ? player = 2 : player = 1;
            }
        }
        else if (choice == 1) {
            while (!game_end) {
                print();
                if (mo1 == 'x' || mo1 == 'X') { color(2); cout << "\t\t\t\t      Position :"; }
                else if (mo1 == 'o' || mo1 == 'O') { color(14); cout << "\t\t\t\t      Position :"; }
                if (player == 1) {
                    cin >> input;
                    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8") {
                        color(4); cout << "\t\t\t\t      Wrong input!\n";
                        mo1 == 'x' || mo1 == 'X' ? color(2) : color(14); cout << "\t\t\t\t      Position :"; cin >> input;
                    }
                    stringstream st; st << input; st >> num;
                    play(num - 1);
                    winner();
                    check_draw();
                }
                else if (player == 2) {
                    ai(x);
                    winner();
                    check_draw();
                }
                player == 1 ? player = 2 : player = 1;
            }
        }
        else { game_ended(); return 0; }
        restart_game();
        if (end_game == 1) { game_ended(); return 0; }
    }
}