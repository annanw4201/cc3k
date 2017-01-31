#include <iostream>
#include <sstream>
#include "floor.h"
#include "MoveControl.h"
#include <string>
#include <ncurses.h>

using namespace std;

int main(int argc, char *argv[]) {
    string mapname;
    if (argc > 1) {
        mapname = argv[1];
    }
    ifstream map{mapname}; // load the map file
    if (!map.is_open()) {
        cerr << mapname << "No map available. Please choose a map to set up the game. " << endl;
        return 1;
    }
    else {
        bool restart = true;
        bool quitgame = false;
        bool enemy_freeze = false;
        bool EnableWASD = false;
        
        string input;
        cout << "Would you like to use WASD (yes/no)?  " << endl;
        
        while (cin >> input) {
            if (input == "yes") {
                EnableWASD = true;
                break;
            }
            else if (input == "no") {
                break;
            }
            else {
                cout << "Invalid Input" << endl;
            }
        }
        
        if (!EnableWASD) {
            while (restart) {
                
                floor f;
                f.init(mapname); // initialize the the floor
/*************************************************When Map is Default*************************************************/
                if (f.isEmptyMap()) {
                    cout << "Welcome to the game, enjoy your time! " << endl;
                    cout << "Please choose your race. The race will be defaulted as Shade if you input other words. " << endl;
                    cout << "s: Shade" << endl << "d: Drow" << endl << "v: Vampire" << endl;
                    cout << "t: Troll" << endl << "g: Goblin" << endl;
                    
                    cin >> input;
                    if (input == "q") {
                        quitgame = true;
                        break;
                    }
                    if (input == "s" || input == "d" || input == "v" || input == "t" || input == "g") {
                        f.SpawnPlayer(input);
                    }
                    else {
                        f.SpawnPlayer("s");
                    }
                    f.SpawnStair("/");
                    f.SpawnPotion("P");
                    f.SpawnGold("G");
                    f.SpawnEnemy();
                }
/*************************************************When Map is Default*************************************************/
                else if (!f.isEmptyMap()) {
                    cout << "You used the customized map. The race has been set. " << endl;
                }
                cout << f; // refresh the map status
                
/*********************************************************During the game*********************************************************/
                cout << "Please enter [no, so, ea, we, nw, ne, sw, se] to move the PC. " << endl;
                string command;
                while (cin >> command) {
                    input = MoveControl(command); // To get the full direction or command information
                    if (command == "f") {
                        enemy_freeze ? enemy_freeze = false : enemy_freeze = true;
                        if (enemy_freeze) {
                            input = "FreezeEnemy";
                        }
                        else {
                            input = "UnfreezeEnemy";
                        }
                    } // PC can freeze the Enemies or unfreeze them
                    
                    f.move_pc(input); // PC moves
                    if (f.Won()) {
                        cout << "You win! You have reached the end of all of floor. " << endl;
                        cout << "Your score is " << f.getScore() << "." << endl;
                        cout << "Do you want to play again? (yes/no) " << endl;
                        while (cin >> input) {
                            if (input == "yes") {
                                command = "r";
                                break;
                            }
                            else if (input == "no") {
                                command = "q";
                                break;
                            }
                            else {
                                cout << "Invalid input. " << endl;
                            }
                        }
                    } // Valid command after User won
                    if (command == "u") {
                        cin >> input;
                        f.pc_usePotion(MoveControl(input));
                    } // PC tries to use the item on the specified direction
                    if (command == "a") {
                        cin >> input;
                        f.pc_attack(MoveControl(input));
                    } // PC tries to attack the enemy on the specified direction
                    
                    f.Enemy_move(enemy_freeze); // the enemies turn to react accordingly
                    
                    if (!f.pc_alive()) {
                        cout << f;
                        cout << "You died! Your score is " << f.getScore() << "." << endl;
                        cout << "Do you want to play again? (yes/no) " << endl;
                        while (cin >> input) {
                            if (input == "yes") {
                                command = "r";
                                break;
                            }
                            else if (input == "no") {
                                command = "q";
                                break;
                            }
                            else {
                                cout << "Invalid input. " << endl;
                            }
                        }
                    } // end of valid command after PC died
                    if (command == "r") {
                        restart = true;
                        break;
                    } // User tries to restart the game
                    if (command == "q") {
                        restart = false;
                        cout << "Thank you for playing, hope you enjoy it. " << endl;
                        break;
                    } // User quits the game while playing the game
                    
                    cout << f; // refresh the map status
                    
                } // end of user command
/*********************************************************During the game*********************************************************/
                
                if (restart) {
                    continue;
                } // User to restart the game
                
            } // end of non-restart command
            if (quitgame) {
                cout << "Thank you for playing. " << endl;
            } // the user enter "q" at the race prompt
        } // no use of ncurses
        
/*******************************************************Use WASD*******************************************************/
        
        if (EnableWASD) {
            useNcurses();
            char input;
            while (restart) {
                floor f;
                f.init(mapname); // initialize the the floor
                clear();
                if (f.isEmptyMap()) {
                    attron(COLOR_PAIR(2));
                    printw ("Welcome to the game, enjoy your time!\n");
                    printw ("Please choose your race. The race will be defaulted as Shade if you input other words.\n" );
                    printw ("s: Shade\nd: Drow\nv: Vampire\nt: Troll\ng: Goblin\n");
                    string race;
                    input = getch();
                    if (input == 'q') {
                        quitgame = true;
                    }
                    if (input == 's') { race = "Shade";}
                    else if (input == 'd') {race = "Drow";}
                    else if (input == 'v') {race = "Vampire";}
                    else if (input == 't') {race = "Troll";}
                    else if (input == 'g') {race = "Goblin";}
                    else {race ="s";}
                    f.SpawnPlayer(race);
                    printw(("You just chose " + race + " as your character.\n").c_str());
                    f.SpawnStair("/");
                    f.SpawnPotion("P");
                    f.SpawnGold("G");
                    f.SpawnEnemy();
				} // When Map is Default
                else if (!f.isEmptyMap()) {
                    attron(COLOR_PAIR(2));
					printw ("You used the customized map. The race has been set.\n");
					printw ("Press any key to continue.\n");
					input = getch();
                } // when map is customized
                attron(COLOR_PAIR(1));
				f.ncursesView();
/*********************************************************During the game*********************************************************/
                attron(COLOR_PAIR(2));
				printw ("Please enter [w,a,s,d] to move the PC.\n");
				attron (COLOR_PAIR(1));
				string read;
                char command;
                while (true) {
                    command = getch();
                    read = MoveControl(command);
                    if (command == 'f') {
                        enemy_freeze ? enemy_freeze = false : enemy_freeze = true;
                        if (enemy_freeze) {
                            read = "FreezeEnemy";
                        }
                        else {
                            read = "UnfreezeEnemy";
                        }
                    }
                    f.move_pc(read);
                    if (f.Won()) {
                        clear();
                        ostringstream score;
                        score << f.getScore();
                        printw ("You win! You have reached the end of all of floor.\n");
                        printw (("Your score is " + score.str() + ".\n").c_str());
                        printw ("Do you want to play again? (y/n)\n ");
                        while (true) {
                            command = getch();
                            if (command == 'y') {
                                command = 'r';
                                break;
                            }
                            else if (command == 'n') {
                                command = 'q';
                                break;
                            }
                            else {
                                printw ("Invalid input.\n ");
                                break;
                            }
                        }
                    } // Valid command after User won
                    if (command == 'u') {
                        string direction;
                        int i = 0;
                        while (i < 2) {
                            command = getch();
                            direction.push_back(command);
                            ++i;
                        }
                        f.pc_usePotion (MoveControl(direction));
                    }
                    if (command == 'j') {
                        string direction;
                        int i = 0;
                        while (i < 2) {
                            command = getch();
                            direction.push_back(command);
                            ++i;
                        }
                        f.pc_attack(MoveControl(direction));
                    } // PC attack
                    
                    f.Enemy_move(enemy_freeze); // Enemy moves
                    
                    if (!f.pc_alive()) {
                        f.ncursesView();
                        ostringstream score;
                        score << f.getScore();
                        printw (("You died! Your score is " + score.str() + ".\n").c_str());
                        printw ("Do you want to play again? (y/n)\n");
                        while (true) {
                            command = getch();
                            if (command == 'y') {
                                restart = true;
                                command = 'r';
                                break;
                            }
                            else if (command == 'n') {
                                command = 'q';
                                break;
                            }
                            else {
                                printw ("Invalid input.\n");
                            }
                        }
                    } // Valid input if PC died
                    if (command == 'r') {
                        restart = true;
                        break;
                    }
                    if (command == 'q') {
                        clear();
                        quitgame = true;
                        restart = false;
                        printw ("Thank you for playing, hope you enjoy it.\n ");
                        endwin();
                        break;
                    }
                    f.ncursesView(); // refresh the map status
                } // end of in game session
                if (restart) {
                    continue;
                }
            } // end of restart
            if (quitgame) {
                clear();
                printw ("Thank you for playing, hope you enjoy it.\n ");
                endwin();
            }
/*********************************************************During the game*********************************************************/
        } // end of WASD loop
    } // end of the game
}
