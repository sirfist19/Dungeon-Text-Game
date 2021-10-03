#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Player.h"
#include "Room.h"
#include "Object.h"
using namespace std;

void menuScreen();
void startGame();
void clear();
void wait(long seconds);
int random(int start, int end);
void nl(int amount); //prints a set number of newlines
void printDash(int amount);
void printMinus(int amount);
void printSpace(int amount);
void printTilda(int amount);
void printFancyPlusLine();
void input(string &input, string desiredOutput[], const int size, string incorrectResponse);
void generalInput(string inputVerb, string inputObject, string incorrectResponse);
void printTips(string tip);
void battleLoop(Enemy &opponent, string callingLocation, bool &escaped);
void battleInput(Enemy& opponent, string inputVerb, string inputObject, string incorrectResponse, bool &escaped);
void checkEnemyAggro(string callingLocation);
void printAttackingInfo(Enemy& opponent);
void changeDroppedString();
void updatePlayerStuff();
void inventory();
void printInventoryOnly();
void inventoryInput(string inputVerb, string inputObject, string incorrectResponse);
void clearScreenAndPrintBriefDescription();
void goToNextRoom(string inputVerb, string inputObject);
void playerAttacking(string playerAttackType, int enemyAttackNumb, Enemy& opponent);
void enemyAttacking(string playerAttackType, int enemyAttackNumb, Enemy& opponent);
void riddleInput(Object& inputRiddle);
bool tips = true;

bool quit;
int a = 120; //controls the amount of dashes printed
string incorrectResponse = "Can't understand response. Please try again.";

Player player;
Object nullObject("None", "None");
Enemy nullEnemy("null", 1, false, "null", 0.0);
const int amountOfRooms = 12;
Room roomArray[amountOfRooms];

int main()
{
	srand(time(NULL));
	menuScreen();
	startGame();

	player.currentLocation = roomArray[1];//set player's location for debugging purposes (could possibly be used for a save system at some point)

	while ((player.health > 0)&&(quit == false))//super basic game loop
	{
		string input1, input2;
		generalInput(input1, input2, incorrectResponse);

	}
	if ((player.health < 0)||(player.health == 0))
	{
		printDash(a);
		nl(1);
		cout << endl<<"GAME OVER!!! You have died and failed to discover your purpose within the Dungeon." << endl;
	}
	else if (quit == true)
		cout << "You quit the game." << endl;
}


//Game sections
void menuScreen()
{
	
	string startInput = "";
	
	printFancyPlusLine();
	nl(1);
	printSpace(41);
	cout << "Welcome to DUNGEON CRAWLER TEXT!";
	nl(2);
	printSpace(36);
	cout << "A text-base adventure game made by Aidan Cini.";
	nl(1);
	printFancyPlusLine();
	nl(2);
	wait(1);
	
	
	cout << "To start type 'start' and press enter. If you want to start with no tips type 'start_no_tips'.";
	nl(2);
	//cout << "To quit type 'Quit' and press enter.";
	while ((startInput != "Start")&& (startInput != "start")&&(startInput != "start_no_tips"))
	{
		cout << ">";
		cin >> startInput;
		if (startInput == "start_no_tips")
			tips = false;
		nl(1);
		if ((startInput != "Start") && (startInput != "start") && (startInput != "start_no_tips"))
		{
			cout << "Do you want to start the game or not? If you do type 'Start' or 'start'.";
			nl(1);
		}
		
	
	}
	
	nl(1);
	cout << "Starting game in ... ";
	//wait(1);
	cout << "3 ... ";
	wait(1);
	cout << "2 ... ";
	wait(1);
	cout << "1 ... ";
	wait(1);
	clear();
}
void startGame()
{
	for (int i = 0; i < amountOfRooms; i++)//initializes the rooms
	{
		roomArray[i] = Room(i);
	}
	//Room startingRoom = Room(1);
	//Room hallway1 = Room(2);
	player.currentLocation = roomArray[1];//sets current location to the startingRoom
	string playerName = "";

	

	string examineTip = "Tip: To examine an object type 'examine' and then the object name. Object names will always show up as all uppercase \nletters.";
	string lookAroundTip = "Tip: To look around a room type 'look'.";
	string helpTip = "Tip: To get a list of available commands type 'help'.";
	printDash(a);
	nl(2);
	wait(1);
	cout << "You open your eyes. It's pitch black. \n\t'Where am I?' you wonder.'How did I get here? And what was my name again?'\n";
	nl(1);
	cout << "Enter your name." << endl<<endl;
	cout << ">";
	while (playerName == "")
	{
		while (playerName == "")
		{
			getline(cin, playerName);
		}

		nl(1);
		printDash(a);
		nl(2);
		cout << "Are you sure your name is " << playerName << "?" << endl << endl << ">";
		string confirmation;
		string desiredConfirmation[4] = { "yes", "no", "Yes", "No" };
		while ((confirmation != "yes") && (confirmation != "no"))
		{
			getline(cin, confirmation);
			if ((confirmation != "yes") && (confirmation != "no"))
			{
				nl(1);
				cout << "Type 'yes' or 'no' to confirm or deny the choice of name." << endl << endl << ">";
			}
			
		}
		
		if (confirmation == "no")
		{
			nl(1);
			printDash(a);
			nl(2);
			cout << "What do you want your name to be then?" << endl << endl << ">";
			playerName = "";
		}
	}
	
	nl(1);
	printDash(a);
	nl(2);
	cout << "Yes, yes, " << playerName << " does seem to be the right name.";
	player.name = playerName;
	wait(15);
	clear();
	printDash(a);
	nl(1);
	cout << player.currentLocation.name << ": " << endl << endl;
	cout<<"You rub your eyes, but it's no use. You can't even see your hand a foot away from your face.\n\nYou sit up. Underneath you is a cold, flat SLAB.\n\t'How long have I been sleeping here?' you wonder. But no answer comes to you.";
	nl(1);
	printDash(a);
	wait(1);
	
	printTips(helpTip);
}

//Game Functions
void clear()
{
	system("cls");
}
void wait(long seconds)
{
	//Sleep(seconds );
	long topBounds = 75000000;
	int b = 1;
	for (long y = 0; y < (seconds*topBounds); y++)//250 million times of repeating nothing
	{
		b++;
		b--;
		//the value of repeating the loop 225000000 times is about 1 second
	}
}
void nl(int amount)//newline fxn
{
	for (int i = 0; i < amount; i++)
	{
		cout << endl;
	}
	
}
void printDash(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout <<"_";
	}

}
void printMinus(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << "-";
	}

}
void printSpace(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << " ";
	}

}
void printTilda(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << "~";
	}

}
void printTips(string tip)
{
	if (tips == true)
	{
		nl(2);
		cout << tip;
		nl(1);
	}
	
}
void printFancyPlusLine()
{
	cout << "+";
	//printMinus(118);
	//printDash(118);
	printTilda(118);
	cout << "+";
}

//General input Fxn.s
void input(string &input, string desiredOutput[], const int size, string incorrectResponse)//for specific input when a desired input is wanted
{
	int n = -1;
	bool loopEnder = false;
	do
	{
		nl(1);
		cout << ">";
		cin >> input;
		for (int i = 0; i < size; i++)
		{
			if ((input != desiredOutput[i])&&(loopEnder == false))
			{

			}
			else if(input == desiredOutput[i])
			{
				n = 0;
				loopEnder = true;
			}
			
		}
		if (loopEnder == false)
		{
			printDash(a);
			nl(1);

			cout << incorrectResponse;
		}
		
	} while (n == -1);
	
	
	
}
void generalInput(string inputVerb, string inputObject, string incorrectResponse)//this fxn will handle general input including verbs syntax and all that
{
	//at some point this function should be used generally for all (or at least most) inputs 
	//the function should read in 2 strings: one is the verb phrase and the second is the object that the verb refers to

	//Verb phrases that should be implemented include examine, pickup, go (as in go north or go south or go up or go down), attack

	//the object refered to should be accessed through checking the room the player is in and then finding the desired object within
	//that room
	bool inputRecognized = false;
	//cout << "a";
	do
	{
		nl(1);
		cout << ">";
		cin >> inputVerb;
		char space = getchar();
		if (space == ' ')
			getline(cin, inputObject);

		if (inputVerb == "look")
		{
			printDash(a);
			nl(2);

			player.currentLocation.printRoomDescription(player.currentLocation);
			inputRecognized = true;
			nl(1);
		}
		else if (inputVerb == "hello")
		{
			printDash(a);
			nl(2);

			cout << "Hello there! How do you do?";
			nl(2);
			wait(2);
			cout << "Oh wait, I'm not supposed to respond to questions. I'm the omniscient narrator after all; I could give something\naway ... ";
			wait(22);
			cout << "by accident.";
			wait(3);
			cout << " That would be bad.";
			//wait(5);
			nl(2);
			cout << "Get back to the task at hand! Enter another response...";
			nl(1);

		}
		else if (inputVerb == "jump")
		{
			if ((player.currentLocation.id == 3) && ((inputObject == "pit") || (inputObject == "into pit") || (inputObject == "in pit")))
			{
				printDash(a);
				cout << "\n\nYou lean over the edge of the pit and with all the force that you can muster, jump off. The wind rushes past you\nand you quickly are enveloped by darkness. After a little while you wonder if this pit is truly bottomless.\nBut soon after wondering you enter a huge cavern and see the ground underneath you. You die quickly and with much splat.\n";
				player.health = 0;
			}
			else
			{
				cout << "You want to jump high up into the air, but you can only get a few feet off the ground.\n";
			}
			inputRecognized = true;
		}
		else if (inputVerb == "help")
		{
			
			//print a list of commands
			printDash(a);
			nl(2);
			cout << "When typing a command always use the syntax 'verb' then space, then 'object'. For example in the command 'examine key',\n'examine' is the verb and 'key' is the object. Objects within each room with be given in all uppercase letters.\n";
			cout << "To find out more information about any verb bellow type 'info' and then the verb you want to know\nmore information about.";
			nl(2);
			cout << "List of all valid verbs: " << endl;
			cout << "1.go" << endl;
			cout << "2.examine" << endl;
			cout << "3.look" << endl; 
			cout << "4.pickup" << endl;
			cout << "5.drop" << endl;
			cout << "6.inventory" << endl; 
			cout << "7.quit" << endl; 
			cout << "8.info" << endl;
			cout << "9.clear" << endl;
			cout << "10.open" << endl;
			cout << "11.jump" << endl;
			printDash(a);
			nl(2);

		}
		else if (inputVerb == "info")
		{
			printDash(a);
			nl(2);
			if (inputObject == "go") {
				cout << "1.go" << endl << "Moves the player to the next room by taking the exit in the direction given." << endl << "\tExample: go north" << endl;
			}
			else if (inputObject == "examine")
			{
				cout << "2.examine" << endl << "Gives a detailed description of the specified object." << endl << "\tExample: examine door" << endl;
			}
			else if (inputObject == "look")
			{
				cout << "3.look" << endl << "Gives a detailed description of the current room including the general setting, \nthe objects within it, and the room's exits. NOTE: LOOK REQUIRES NO OBJECT." << endl << "\tExample: look" << endl;
			}
			else if (inputObject == "pickup")
			{
				cout << "4.pickup" << endl << "Pickup an object and place it into the player's inventory." << endl << "\tExample: pickup sword" << endl;
			}
			else if (inputObject == "drop")
			{
				cout << "5.drop" << endl << "Drops an object from the player's inventory into the current room." << endl << "\tExample: drop iron armor" << endl;
			}
			else if (inputObject == "inventory")
			{
				cout << "6.inventory" << endl << "Displays the player's inventory including health, weapons, armor, and general items. NOTE: INVENTORY REQUIRES NO OBJECT." << endl;
			}
			else if (inputObject == "quit")
			{
				cout << "7.quit" << endl << "Quits the game. Your progress will not be saved. NOTE: QUIT REQUIRES NO OBJECT." << endl;
			}
			else if (inputObject == "info")
			{
				cout << "8.info" << endl << "Why do you need more info about info when you just used the info function properly!\n Just kidding ... the info verb accesses information about each verb's function." << endl;
			}
			else if (inputObject == "clear")
			{
				cout << "9.clear" << endl << "Clears the text on the screen. Use this if there's so much text on the screen that it's overwhelming." << endl;
			}
			else if (inputObject == "hello")
			{
				cout << "That's a secret verb. I can't tell you what that one does." << endl;
			}
			else
				cout << "Input verb not recognized." << endl;


		}//may want to place the info function within the help function ... that way the player won't always be able to access the hints
		else if (inputVerb == "clear")
		{
			clear();
			printDash(a);
			//printFancyPlusLine();
			cout << endl << player.currentLocation.name << ": " << endl;
			cout << player.currentLocation.briefRoomDescription << endl;
			printDash(a);
			//printFancyPlusLine();
			nl(2);
		}
		else if (inputVerb == "examine")
		{
			
			//cin >> inputObject;
			 
			for (int i = 0; i < 10; i++)
			{
				if ((player.currentLocation.objects[i].activationName != "null")&&(inputObject == player.currentLocation.objects[i].activationName))
				{
					printDash(a);
					nl(2);
					cout << player.currentLocation.objects[i].description<<endl;
					inputRecognized = true;

					//for activating riddles
					if (player.currentLocation.objects[i].type == "riddle")
					{
						riddleInput(player.currentLocation.objects[i]);
					}

					//for activating enemies
					for (int n = 0; n < 5; n++)
					{
						string aggroCheck = "examine " + inputObject;
						if (player.currentLocation.enemy[n].aggroCondition == aggroCheck)
						{
							int id = player.currentLocation.id;
							roomArray[id].enemy[n].aggro = true;

							//add in line later so that the aggroObject is deleted and the line of text in the room that prompted the activation is gone
							if (player.currentLocation.objects[i].type == "noise")
							{
								
								roomArray[id].objects[i] = nullObject;

								if (id == 10)
								{
									roomArray[id].roomDescription[2] = "";
								}
							}
							player.currentLocation = roomArray[id];//set the player's current location to reflect the changes
						}
					}
					checkEnemyAggro("examine");
				}
			}
			if ((inputRecognized == false)&&(inputObject == ""))
			{
				printDash(a);
				nl(2);
				cout << "You can't examine nothing. Be sure to type what you want to examine after typing 'examine'." << endl;
			}
			else if (inputRecognized == false)
			{
				printDash(a);
				nl(2);
				cout << "Unrecognized object. Type the entire phrase again." << endl;
			}
		}
		else if (inputVerb == "open")
		{

			if ((inputObject == "door") || (inputObject == "door with key")|| (inputObject == "north door") || (inputObject == "north door with key") || (inputObject == "south door") || (inputObject == "south door with key") || (inputObject == "west door") || (inputObject == "west door with key") || (inputObject == "east door") || (inputObject == "east door with key"))
			{
				string direction = "";
				int i = -1;
				printDash(a);

				if ((inputObject == "north door") || (inputObject == "north door with key"))
				{
					direction = "north";
					if (inputObject == "north door")
						inputObject = "door";
					else if (inputObject == "north door with key")
						inputObject = "door with key";
				}
				else if ((inputObject == "south door") || (inputObject == "south door with key"))
				{
					direction = "south";
					if (inputObject == "south door")
						inputObject = "door";
					else if (inputObject == "south door with key")
						inputObject = "door with key";
				}
				else if ((inputObject == "west door") || (inputObject == "west door with key"))
				{
					direction = "west";
					if (inputObject == "west door")
						inputObject = "door";
					else if (inputObject == "west door with key")
						inputObject = "door with key";
				}
				else if ((inputObject == "east door") || (inputObject == "east door with key"))
				{
					direction = "east";
					if (inputObject == "east door")
						inputObject = "door";
					else if (inputObject == "east door with key")
						inputObject = "door with key";
				}
				
				
				
				while (i == -1)
				{
					nl(2);
					if (direction == "")
					{
						cout << "Which door do you want to open?" << endl << endl;
						cout << ">";
						getline(cin, direction);
					}
					
					if (direction == "north")
					{
						if (player.currentLocation.doorArray[0].name == "none")
						{
							cout << "There's no door in that direction.";
							direction = "";
							i = -2;
						}	
						else
							i = 0;
					}
					else if (direction == "south")
					{
						if (player.currentLocation.doorArray[1].name == "none")
						{
							cout << "There's no door in that direction.";
							direction = "";
							i = -2;
						}
							
						else
							i = 1;
					}
					else if (direction == "east")
					{
						if (player.currentLocation.doorArray[2].name == "none")
						{
							cout << "There's no door in that direction.";
							direction = "";
							i = -2;
						}
							
						else
							i = 2;
					}
					else if (direction == "west")
					{
						if (player.currentLocation.doorArray[3].name == "none")
						{
							cout << "There's no door in that direction.";
							direction = "";
							i = -2;
						}
						else
							i = 3;
					}
					else
					{
						cout << "That's not a direction. Try again.";
						direction = "";
					}
						
				}

				if (player.currentLocation.doorArray[i].name != "none")
				{
					if (player.currentLocation.doorArray[i].open == true)
					{
						cout << "The door is already open!";
					}
					else if ((inputObject == "door") && (player.currentLocation.doorArray[i].openCondition == "none"))
					{
						player.currentLocation.doorArray[i].open = true;
						cout << "The door creaks open.";
					}
					else if ((inputObject == "door") && (player.currentLocation.doorArray[i].openCondition == "key"))
					{
						cout << "The door doesn't open because it's locked.";
					}
					else if ((inputObject == "door with key") && (player.currentLocation.doorArray[i].openCondition == "key"))
					{
						if (player.numberOfKeys > 0)
						{
							player.currentLocation.doorArray[i].open = true;
							player.numberOfKeys--;
							cout << "You push the key into the hole and turn slowly. You hear a click and the key retreats into the door away\nfrom your grasp. The door creaks open.";
							
						}
						else
							cout << "You don't have any keys to open the door with!";

					}
					nl(1);
					printDash(a);
					nl(1);
				}
			}
			else
			{
				cout << "Unrecognized object.\n\n";
			}
			inputRecognized = true;
		
		}
		else if (inputVerb == "go")
		{
			bool goToNextRoom = false;
				//cin >> inputObject;
				for (int i = 0; i < 4; i++)
				{
					if ((inputObject == player.currentLocation.exitArray[i]) && (inputObject != "none"))
					{
						printDash(a);
						nl(2);

						if (i == 0)//going to the North
						{
							if (player.currentLocation.doorArray[i].open == true)
							{
								cout << "You walk through the North exit.";
								goToNextRoom = true;
							}
							else if (player.currentLocation.doorArray[i].open == false)
							{
								cout << "A closed door stands in your way.\n";
							}
						}
						else if (i == 1)
						{
							if (player.currentLocation.doorArray[i].open == true)
							{
								cout << "You walk through the South exit.";
								goToNextRoom = true;
							}
							else if (player.currentLocation.doorArray[i].open == false)
							{
								cout << "A closed door stands in your way.\n";
							}
						}
						else if (i == 2)
						{
							if (player.currentLocation.doorArray[i].open == true)
							{
								cout << "You walk through the East exit.";
								goToNextRoom = true;
							}
							else if (player.currentLocation.doorArray[i].open == false)
							{
								cout << "A closed door stands in your way.\n";
							}
						}
						else if (i == 3)
						{
							if (player.currentLocation.doorArray[i].open == true)
							{
								cout << "You walk through the West exit.";
								goToNextRoom = true;
							}
							else if (player.currentLocation.doorArray[i].open == false)
							{
								cout << "A closed door stands in your way.\n";
							}
						}

						if (goToNextRoom == true)
						{
							//go to the room with the given ID
							roomArray[player.currentLocation.id] = player.currentLocation;
							int newRoomID = player.currentLocation.surroundingRoomIDs[i];
							player.currentLocation = roomArray[newRoomID];

							wait(1);
							cout << ".";
							wait(1);
							cout << ".";
							wait(1);
							cout << ".";
							clear();
							printDash(a);
							cout << endl << player.currentLocation.name << ": " << endl;
							cout << player.currentLocation.briefRoomDescription << endl;

							checkEnemyAggro("go");
						}
					
						inputRecognized = true;
					}
				}
				if ((inputRecognized == false) && (inputObject == ""))
				{
					cout << "You can't go nowhere. Be sure to type where you want to go after typing 'go'." << endl;
				}
				else if ((inputRecognized == false)&&((inputObject == "north")|| (inputObject == "south") || (inputObject == "east") || (inputObject == "west")))
				{
					cout << "There is no exit in the direction. Type the entire phrase again." << endl;
				}
				else if (inputRecognized == false)
				{
					cout << "Unrecognized direction. Type the entire phrase again." << endl;
				}
			
		}
		else if ((inputVerb == "pickup")||(inputVerb == "take"))
		{
			inputRecognized = true;
			printDash(a);
			nl(2);
			bool setObject = false;
			bool b = false;
			for (int i = 0; i < 10; i++)
			{
				
				if ((player.currentLocation.objects[i].activationName != "null") && ((inputObject == player.currentLocation.objects[i].activationName)||(inputObject == player.currentLocation.objects[i].droppedActivationName)))
				{
					if (player.currentLocation.objects[i].pickupAble == true)
					{
						cout << "You pick up the " << player.currentLocation.objects[i].name << "!" << endl;
						
						for (int n = 0; n < 10; n++)
						{
							if ((player.inventory[n].name == "None")&&(setObject == false))
							{
								//place the object in the player's inventory
								if (player.currentLocation.objects[i].type == "weapon")
								{
									string input1;
									string desiredInput[2] = { "yes", "no" };
									cout << "Do you want to equip " << player.currentLocation.objects[i].name << " as your Main Weapon?" << endl;
									input(input1, desiredInput, 2, "Equiping string not recognized");

									if (input1 == "yes")
									{
										if ((player.mainWeapon.name != "None")&&(player.mainWeapon.name != "Fists"))
										{
											player.inventory[n] = player.mainWeapon;
										}
										player.mainWeapon = player.currentLocation.objects[i];
										printDash(a);
										nl(2);
										cout << player.mainWeapon.name << " equiped!";
										nl(1);
									}
									else if (input1 == "no")
									{
										player.inventory[n] = player.currentLocation.objects[i];//place into inventory
										printDash(a);
										nl(2);
										cout << player.inventory[n].name << " has been placed in your general inventory.";
										nl(1);
									}
								}
								else if (player.currentLocation.objects[i].type == "key")
								{
									player.numberOfKeys++;
								}
								else
								{
									player.inventory[n] = player.currentLocation.objects[i];
								}
								
								//player.currentLocation.objects[i] = nullObject;
								changeDroppedString();
								int roomId = player.currentLocation.id;
								roomArray[roomId].objects[i] = nullObject;
								roomArray[roomId].roomDescription[2] = "";//the third string will always be used to refer to objects in the room
								player.currentLocation = roomArray[roomId];//updates the rooms description based on picking up the object
								
								setObject = true;
							}
						}
						changeDroppedString();
					}
					else
					{
						cout << "You cannot pick up that object." << endl;
						b = true;
					}
					
					inputRecognized = true;

				}

			}
			if ((setObject == false)&&(b == false))
			{
				cout << "Object not recognized." << endl;
			}
		}
		else if (inputVerb == "drop")
		{
		printDash(a);
		nl(2);
		cout << "You can only drop objects from within your inventory";
		nl(1);
		}
		else if (inputVerb == "inventory")
		{
			inventory();
			inputRecognized = true;
		}
		else if (inputVerb == "quit")
		{
			quit = true;
			inputRecognized = true;
		}
		else
		{
			printDash(a);
			nl(2);
			cout << incorrectResponse;
			nl(1);
		}
	} while (inputRecognized == false);
}

//Attacking Fxn.s
void printAttackingInfo(Enemy& opponent)
{
	cout << opponent.name << ": " << endl;
	cout << "    Health: " << opponent.health << "/ " << opponent.maxHealth << endl;
	cout << "    Defense: " << opponent.defense << endl;
	cout << "    Stamina: " << opponent.stamina << "/ " << opponent.maxStamina << endl;
	cout << "    Weapon: " << opponent.mainWeapon.name << endl << endl;



	cout << player.name << endl;
	cout << "    Health: " << player.health << "/ " << player.maxHealth << endl;
	cout << "    Defense: " << player.defense << endl;
	cout << "    Stamina: " << player.stamina << "/ " << player.maxStamina << endl;
	cout << "    Weapon: " << player.mainWeapon.name << endl << endl;

}
void checkEnemyAggro(string callingLocation)
{
	for (int i = 0; i < 5; i++)
	{
		if (player.currentLocation.enemy[i].aggro == true)
		{
			nl(1);
			printDash(a);
			nl(2);
			bool escaped = false;
			battleLoop(player.currentLocation.enemy[i], callingLocation, escaped);
			if ((player.health > 0)&&(escaped == false))
			{
				int roomId = player.currentLocation.id;
				if (player.currentLocation.enemy[i].name == "Skeleton")
				{
					roomArray[roomId].roomDescription[2] += "\n\nBones are scattered all over the floor.";
					player.currentLocation.roomDescription[2] += "\n\nBones are scattered all over the floor.";
				}
				//drop the objects on killing enemy - go through enemy inventory and drop the item in the first open slot of the room
				
				string droppedItems1 = "";
				int numbDropped = 0;
				for (int z = 0; z < 10; z++)//for each object in the dead enemies inventory
				{
					bool setObject = false;
					bool chance = false;
					int randNum = random(1, 100);
					cout << randNum << endl;
					if ((player.currentLocation.enemy[i].dropRates[z] >= randNum)&&(player.currentLocation.enemy[i].dropRates[z] != 0))
					{
						chance = true;
					}
					if ((chance == true)&&(player.currentLocation.enemy[i].inventory[z].name != "null") && (player.currentLocation.enemy[i].inventory[z].name != "None"))
					{
						for (int n = 0; n < 10; n++)//putting the object into the room
						{
							if (((player.currentLocation.objects[n].name == "None")|| (player.currentLocation.objects[n].name == "null")) && (setObject == false))
							{
								numbDropped++;
								if (numbDropped == 1)
								{
									droppedItems1 += player.currentLocation.enemy[i].inventory[z].name;
								}
								else
								{
									droppedItems1 += ", " + player.currentLocation.enemy[i].inventory[z].name;
								}
									

								player.currentLocation.enemy[i].inventory[z].dropped = true;
								player.currentLocation.objects[n] = player.currentLocation.enemy[i].inventory[z];
								roomArray[player.currentLocation.id] = player.currentLocation;
								//cout <<  " dropped your " << player.inventory[i].name << endl;
								player.currentLocation.enemy[i].inventory[z] = nullObject;
								changeDroppedString();
								//cout << player.currentLocation.objects[n].name;
								setObject = true;
							}
						}
					}
				}
				if (numbDropped != 0)
				{
					cout << endl <<"The "<< player.currentLocation.enemy[i].name << " dropped " << droppedItems1 << "!" << endl;
				}
				else if (numbDropped == 0)
				{
					cout << endl <<"The "<< player.currentLocation.enemy[i].name << " didn't drop anything."<< endl;
				}
				


				//change the room to not have the enemy in it anymore after the player defeats an enemy
				roomArray[roomId].enemy[i] = nullEnemy;
				player.currentLocation = roomArray[roomId];//reset the player's current room to the new one
			}
		}
	}
}
void battleLoop(Enemy &opponent, string callingLocation, bool &escaped)
{
	if (callingLocation == "go")
	{
		cout << "A " << opponent.name << " lies in waiting and as soon as you enter the room it attacks you!" << endl << endl;
	}
	else if (callingLocation == "examine")
	{
		cout << "A " << opponent.name << " lies in waiting and attacks you!" << endl << endl;
	}
	

	bool firstEnter = false;
	
	while ((opponent.health > 0) && (player.health > 0))
	{
		printAttackingInfo(opponent);
	
		string inputVerb, inputObject;
		battleInput(opponent, inputVerb, inputObject, incorrectResponse, escaped);
	}

	player.stamina = player.maxStamina;

	if ((opponent.health < 0)||(opponent.health == 0)&&(escaped == false))
	{
		if (opponent.name == "Skeleton")
		{
			cout << "The Skeleton shatters into a million pieces leaving the bones all over the floor." << endl;
		}
		else 
		{
			cout << "You defeated the " << opponent.name << "!" << endl;
		}
		
	}
}
void battleInput(Enemy& opponent, string inputVerb, string inputObject, string incorrectResponse, bool &escaped)
{
	bool placeHolder1 = false;
	bool placeHolder2 = false;
	bool inputRecognized = false;
	do 
	{
		nl(1);
		cout << "Options:\n    1.Attack\n    2.Inventory\n    3.Run\n\n";
		cout << ">";
		cin >> inputVerb;
		char space = getchar();
		if (space == ' ')
			getline(cin, inputObject);
		
		if (player.stamina < 0)
		{
			player.stamina = 0;
		}

		if ((inputVerb == "attack")||(inputVerb == "1"))
		{
			string attackType;
			printDash(a);
			cout << "\nHow do you want to attack?" << endl;
			cout << "    1.SLASH\n    2.LUNGE\n    3.BLOCK\n\n>";
			getline(cin, attackType);
			bool AI_Picking = false;
			int enemyAttack;

			while (AI_Picking == false)
			{//makes sure the enemy doesn't pick a move that will give them 0 or under 0 stamina
				enemyAttack = random(1, 3);
				cout << enemyAttack;

				if ((enemyAttack == 1)&&(opponent.stamina - (.5 * opponent.mainWeapon.damage) > 0))
				{
					AI_Picking = true;
				}
				else if ((enemyAttack == 2) && (opponent.stamina - (opponent.mainWeapon.damage) > 0))
				{
					AI_Picking = true;
				}
				else if (enemyAttack == 3)
				{
					AI_Picking = true;
				}
			}
			
			if (((attackType == "slash") || (attackType == "1")) && (player.stamina - (.5 * player.mainWeapon.damage) <= 0))
			{
				placeHolder1 = true;
				cout << "You don't have enough stamina for that attack." << endl;
				attackType = "";
				wait(5);
			}
			else if (((attackType == "lunge")||(attackType == "2") )&& (player.stamina - (player.mainWeapon.damage) <= 0))
			{
				placeHolder2 = true;
				cout << "You don't have enough stamina for that attack." << endl;
				attackType = "";
				wait(5);
			}
			else
			{
				placeHolder1 = false;
				placeHolder2 = false;
			}
			
			if ((placeHolder1 == false) && (placeHolder2 == false))
			{
				clearScreenAndPrintBriefDescription();

				if ((player.health > 0) && (opponent.health > 0) && (player.stamina > opponent.stamina))//the player attacks first
				{
					playerAttacking(attackType, enemyAttack, opponent);

					if (opponent.health > 0)
					{
						enemyAttacking(attackType, enemyAttack, opponent);
						nl(1);
					}
				}
				else if ((opponent.health > 0) && (player.health > 0) && (player.stamina < opponent.stamina))//the opponent attacks first
				{
					enemyAttacking(attackType, enemyAttack, opponent);

					if (player.health > 0)
					{
						playerAttacking(attackType, enemyAttack, opponent);
						nl(1);
					}

				}
				else if ((opponent.health > 0) && (player.health > 0) && (player.stamina == opponent.stamina))//speed tie
				{
					int randomNumb = random(1, 2);
					//cout << randomNumb;
					if (randomNumb == 1)//player attacks first
					{
						playerAttacking(attackType, enemyAttack, opponent);

						if (opponent.health > 0)
						{
							enemyAttacking(attackType, enemyAttack, opponent);
							nl(1);
						}
					}
					else if (randomNumb == 2)//opponent attacks first
					{
						enemyAttacking(attackType, enemyAttack, opponent);

						if (player.health > 0)
						{
							playerAttacking(attackType, enemyAttack, opponent);
							nl(1);
						}
					}
				}
			}
			if ((placeHolder1 == false) && (placeHolder2 == false))
			{
				wait(2);
				inputRecognized = true;
			}
			
		}
		else if ((inputVerb == "inventory")||(inputVerb == "2"))
		{
			inventory();
			printAttackingInfo(opponent);
		}
		else if ((inputVerb == "run") || (inputVerb == "3"))
		{
			cout << "\nWhich direction do you want to run?" << endl;
			cout << ">";
			getline(cin, inputObject);
			string inputVerb = "go";

			//cout << "You successfully escaped!\n";

			opponent.stamina = opponent.maxStamina;
			roomArray[player.currentLocation.id] = player.currentLocation;//set the enemy so that when entering the escaped room the enemy doesn't respawn with full health

			
			goToNextRoom(inputVerb, inputObject);
			
			inputRecognized = true;
			escaped = true;
			
			
		}
		else
		{
			printDash(a);
			nl(2);
			cout << "Unrecognized input. Type 'attack' to attack." << endl;
		}
	} 
	while (inputRecognized == false);
	
}
void playerAttacking(string playerAttackType, int enemyAttackNumb, Enemy& opponent)
{
	int numb = 5;// controls wait time length
	//1 corresponds to slashing
	//2 corresponds to lunging 
	//3 corresponds to blocking
	if (playerAttackType == "1")
	{
		playerAttackType = "slash";
	}
	else if (playerAttackType == "2")
	{
		playerAttackType = "lunge";
	}
	else if (playerAttackType == "3")
	{
		playerAttackType = "block";
	}

	
	
	//player slashes
	if (((playerAttackType == "slash")&&(enemyAttackNumb == 1))||((playerAttackType == "slash") && (enemyAttackNumb == 2)))
	{//outcome if the player slashes and the enemy either slashes or lunges
		opponent.health = opponent.health - (1 / ((.1) * (opponent.defense) + 1)) * player.mainWeapon.damage;//player attacks
		player.stamina -= .5*player.mainWeapon.damage;
		wait(numb);
		cout << "You slash at the " << opponent.name << " with your " << player.mainWeapon.name;
		cout << " and land your blow." << endl;
	}
	else if ((playerAttackType == "slash") && (enemyAttackNumb == 3))
	{//if the player slashes and the enemy blocks the attack
		player.stamina -= .5 * player.mainWeapon.damage;
		wait(numb);
		cout<<"You slash at the "<< opponent.name << " with your " << player.mainWeapon.name;
		cout << " but the " << opponent.name << " blocks it." << endl;
	}


	//player lunges
	if (((playerAttackType == "lunge") && (enemyAttackNumb == 1)) || ((playerAttackType == "lunge") && (enemyAttackNumb == 2)))
	{//outcome if the player lunges and the enemy either slashes or lunges
		opponent.health = opponent.health - (1.5 / ((.1) * (opponent.defense) + 1)) * player.mainWeapon.damage;//player attacks with 1.5 times the damage
		player.stamina -= player.mainWeapon.damage;
		wait(numb);
		cout << "You lunge at the " << opponent.name << " with your " << player.mainWeapon.name;
		cout << " and land your blow." << endl;
	}
	else if ((playerAttackType == "lunge") && (enemyAttackNumb == 3))
	{//if the player lunges and the enemy blocks the attack
		player.stamina -= player.mainWeapon.damage;
		wait(numb);
		cout << "You lunge at the " << opponent.name << " with your " << player.mainWeapon.name;
		cout << " but the " << opponent.name;

		int hurtChance = random(1, 2);
		if (hurtChance == 1)
		{//the enemy gets hurt a little bit from the blow
			cout << " fails to completely block and stumbles backward." << endl;
			opponent.health = opponent.health - (.25 / ((.1) * (opponent.defense) + 1)) * player.mainWeapon.damage;//the enemy is hurt by 1/4th of slash damage
		}
		else if (hurtChance == 2)
		{//the enemy successfully blocks
			cout << " successfully blocks it." << endl;
		}
	}

	//player blocks
	if (((playerAttackType == "block") && (enemyAttackNumb == 1)) || ((playerAttackType == "block") && (enemyAttackNumb == 3)))
	{//outcome if the player blocks and the enemy either slashes or blocks
		wait(numb);
		cout << "You block with your " << player.mainWeapon.name<<"."<<endl; 
	}
	else if ((playerAttackType == "block") && (enemyAttackNumb == 2))
	{//if the player blocks and the enemy lunges
		wait(numb);
		cout << "You block with your " << player.mainWeapon.name <<"."<< endl;
		//the rest should be implemented in the enemyAttacking fxn
		
	}

	opponent.health = round(opponent.health);
	
}
void enemyAttacking(string playerAttackType, int enemyAttackNumb, Enemy& opponent)
{
	int numb = 5;// controls wait time length
	//1 corresponds to slashing
	//2 corresponds to lunging 
	//3 corresponds to blocking
	if (playerAttackType == "1")
	{
		playerAttackType = "slash";
	}
	else if (playerAttackType == "2")
	{
		playerAttackType = "lunge";
	}
	else if (playerAttackType == "3")
	{
		playerAttackType = "block";
	}

	//enemy slashes
	if ((enemyAttackNumb == 1)&&((playerAttackType == "lunge" )||(playerAttackType == "slash")))
	{
		wait(numb);
		opponent.stamina -= .5*opponent.mainWeapon.damage;
		player.health = player.health - (1 / ((.1) * (player.defense) + 1)) * opponent.mainWeapon.damage;//enemy attacks
		cout << "The " << opponent.name << " slashes at you with a " << opponent.mainWeapon.name;
		cout << " and lands the blow." << endl;
	}
	else if ((enemyAttackNumb == 1) && (playerAttackType == "block"))
	{
		opponent.stamina -= .5 * opponent.mainWeapon.damage;
		wait(numb);
			cout << "The " << opponent.name << " slashes at you with a " << opponent.mainWeapon.name;
			cout << " but you block the attack." << endl;
	}

	//enemy lunges
	if ((enemyAttackNumb == 2) && ((playerAttackType == "lunge") || (playerAttackType == "slash")))
	{
		wait(numb);
		opponent.stamina -=  opponent.mainWeapon.damage;
		player.health = player.health - (1.5 / ((.1) * (player.defense) + 1)) * opponent.mainWeapon.damage;//enemy attacks
		cout << "The " << opponent.name << " lunges at you with a " << opponent.mainWeapon.name;
		cout << " and lands the blow." << endl;
	}
	else if ((enemyAttackNumb == 2) && (playerAttackType == "block"))
	{//the player blocks the enemies lunge
		wait(numb);
		opponent.stamina -= .5 * opponent.mainWeapon.damage;
		cout << "The " << opponent.name << " lunges at you with a " << opponent.mainWeapon.name;

		int hurtChance = random(1, 2);
		if (hurtChance == 1)
		{//the player gets hurt a little bit from the blow
			cout << ", but you fail to completely block and stumble backward." << endl;
			player.health = player.health - (.25 / ((.1) * (player.defense) + 1)) * opponent.mainWeapon.damage;//the enemy is hurt by 1/4th of slash damage
		}
		else if (hurtChance == 2)
		{//the player successfully blocks
			cout << " and you successfully block it." << endl;
		}
	}

	//enemy blocks
	if (((enemyAttackNumb == 3) && (playerAttackType == "slash")) || ((playerAttackType == "block") && (enemyAttackNumb == 3)))
	{//outcome if the enemy blocks and the player either slashes or blocks
		wait(numb);
		cout << "The " << opponent.name << " blocks with a " << opponent.mainWeapon.name << "." << endl;
	}
	else if ((enemyAttackNumb == 3)&&(playerAttackType == "lunge"))
	{//if the enemy blocks and the player lunges
		wait(numb);
		cout << "The " << opponent.name << " blocks with a " << opponent.mainWeapon.name << "." << endl;
		//the rest should be implemented here or elsewhere

	}
	player.health = round(player.health);
}


//Inventory fxns.
void inventory()
{
	printInventoryOnly();
	string a, b = "";
	inventoryInput(a, b, incorrectResponse);
}
void printInventoryOnly()
{
	clear();
	printDash(a);
	nl(2);
	cout << player.name << "'s Inventory: " << endl << endl;
	cout << "Health: " << player.health << "/ " << player.maxHealth << endl;
	cout << "Stamina: " << player.stamina << "/ " << player.maxStamina << endl;
	cout << "Defense: " << player.defense << endl;
	cout << "Keys: " << player.numberOfKeys;
	nl(2);
	cout << "Main Weapon: " << player.mainWeapon.name << endl;
	cout << "Equiped Armor: " << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			cout << "     Helmet: " << player.equipedArmor[i].name << endl;
		}
		else if (i == 1)
		{
			cout << "     Chestplate: " << player.equipedArmor[i].name << endl;
		}
		if (i == 2)
		{
			cout << "     Leggings: " << player.equipedArmor[i].name << endl;
		}
		else if (i == 3)
		{
			cout << "     Boots: " << player.equipedArmor[i].name << endl;
		}
	}

	cout << endl << "General Items (10 items max): " << endl;
	bool noItemsInInventory = true;
	for (int i = 0; i < 10; i++)
	{

		if (player.inventory[i].name != "None")
		{
			cout << "- " << player.inventory[i].name << endl;
			noItemsInInventory = false;
		}


	}
	if (noItemsInInventory == true)
	{
		cout << "No items in general inventory." << endl;
	}
	string tipInventory = "TIP: Type 'help' to get a list of verbs used within the inventory.";
	printTips(tipInventory);
}
void inventoryInput(string inputVerb, string inputObject, string incorrectResponse)
{
	bool inputRecognized = false;
	
	do
	{
		//cout << "d";
		nl(1);
		cout << ">";
		cin >> inputVerb;
		char space = getchar();
		if (space == ' ')
			getline(cin, inputObject);

		if (inputVerb == "back")
		{
			clearScreenAndPrintBriefDescription();
			//string a, b;
			//generalInput(a, b, incorrectResponse);
			inputRecognized = true;
		}
		else if (inputVerb == "drop")
		{

			printDash(a);
			nl(2);
			//cout << "Function not implemented yet." << endl;
			//char space = getchar();
			//getline(cin, inputObject);
			int isItemInInventoryCode = 0;
			bool setObject = false;
			if ((inputObject == player.mainWeapon.droppedActivationName) && (inputObject != "None"))
			{

				for (int n = 0; n < 10; n++)
				{
					if (((player.currentLocation.objects[n].name == "null") || (player.currentLocation.objects[n].name == "None")) && (setObject == false))
					{
						if (inputObject == "fists")
						{
							cout << "You can't drop your fists. What do you want to do, chop your hands off or something?!" << endl;
							setObject = true;
						}
						else
						{
							Object fists("Fists", "fists");
							player.mainWeapon.dropped = true;
							player.currentLocation.objects[n] = player.mainWeapon;
							roomArray[player.currentLocation.id] = player.currentLocation;
							cout << "You dropped your " << player.mainWeapon.name << endl;
							player.mainWeapon = fists;
							changeDroppedString();
							setObject = true;

						}


					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if ((inputObject == player.equipedArmor[i].droppedActivationName) && (inputObject != ""))
				{
					for (int n = 0; n < 10; n++)
					{
						if ((player.currentLocation.objects[n].name == "null") && (setObject == false))
						{
							player.equipedArmor[i].dropped = true;
							player.currentLocation.objects[n] = player.equipedArmor[i];
							roomArray[player.currentLocation.id] = player.currentLocation;
							cout << "You dropped your " << player.equipedArmor[i].name << endl;
							player.equipedArmor[i] = nullObject;
							changeDroppedString();
							setObject = true;
						}
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if ((inputObject == player.inventory[i].droppedActivationName) && (inputObject != ""))
				{
					for (int n = 0; n < 10; n++)
					{
						if ((player.currentLocation.objects[n].name == "None") && (setObject == false))
						{
							player.inventory[i].dropped = true;
							player.currentLocation.objects[n] = player.inventory[i];
							roomArray[player.currentLocation.id] = player.currentLocation;
							cout << "You dropped your " << player.inventory[i].name << endl;
							player.inventory[i] = nullObject;
							changeDroppedString();

							setObject = true;
						}
					}
				}
			}
			
			if (setObject == false)
			{
				cout << "That object is not in your inventory." << endl << endl;
			}
			else
			{
				updatePlayerStuff();
				wait(7);
				printInventoryOnly();
			}
				

		}
		else if (inputVerb == "help")
		{

			//print a list of commands
			printDash(a);
			nl(2);
			cout << "Within the inventory you can only do specific actions such as equiping items or getting info on items held." << endl;
			cout << "Type 'info' and then the verb you want to know about to learn how it works.";
			nl(2);
			cout << "List of all valid verbs within the inventory: " << endl;
			cout << "1.back" << endl;
			cout << "2.drop" << endl;
			cout << "3.info" << endl;
			cout << "4.equip" << endl;
			cout << "5.unequip" << endl;
			cout << "6.drink" << endl;
			cout << "7.clear" << endl;
			printDash(a);
			nl(2);

		}
		else if (inputVerb == "equip")
		{
			bool setObject = false;
			bool ipz = false;

			for (int i = 0; i < 10; i++)
			{
				if (inputObject == player.inventory[i].droppedActivationName)//where dropped activation name is just the name in lowercase
				{
					if (player.inventory[i].type == "weapon")
					{

						for (int n = 0; n < 10; n++)
						{
							if ((player.inventory[n].name == "None") && (setObject == false))
							{
								if (player.mainWeapon.name != "Fists")
								{
									player.inventory[n] = player.mainWeapon;//puts the already used main weapon into the inventory

								}
								setObject = true;
							}
						}
						player.mainWeapon = player.inventory[i];
						player.inventory[i] = nullObject;
					}
					else if (player.inventory[i].type == "armor")
					{
						if (player.inventory[i].armorType == "helmet")
						{
							for (int n = 0; n < 10; n++)
							{
								if ((player.inventory[n].name == "None") && (setObject == false))
								{
									player.inventory[n] = player.equipedArmor[0];//puts the already used main weapon into the inventory
									setObject = true;
								}
							}
							player.equipedArmor[0] = player.inventory[i];
						}
						if (player.inventory[i].armorType == "chestplate")
						{
							for (int n = 0; n < 10; n++)
							{
								if ((player.inventory[n].name == "None") && (setObject == false))
								{
									player.inventory[n] = player.equipedArmor[1];//puts the already used main weapon into the inventory
									setObject = true;
								}
							}
							player.equipedArmor[1] = player.inventory[i];
						}
						if (player.inventory[i].armorType == "leggings")
						{
							for (int n = 0; n < 10; n++)
							{
								if ((player.inventory[n].name == "None") && (setObject == false))
								{
									player.inventory[n] = player.equipedArmor[2];//puts the already used main weapon into the inventory
									setObject = true;
								}
							}
							player.equipedArmor[2] = player.inventory[i];
						}
						if (player.inventory[i].armorType == "boots")
						{
							for (int n = 0; n < 10; n++)
							{
								if ((player.inventory[n].name == "None") && (setObject == false))
								{
									player.inventory[n] = player.equipedArmor[3];//puts the already used main weapon into the inventory
									setObject = true;
								}
							}
							player.equipedArmor[3] = player.inventory[i];
						}

						updatePlayerStuff();
						player.inventory[i] = nullObject;
					}
					else
					{
						cout << "You can only equip weapons or armor." << endl;
						setObject = true;
						ipz = true;
					
					}
						
				}
			}
			if ((setObject == false)&&(ipz == false))
			{
				cout << "That object is not in your inventory." << endl << endl;
			}
			else if ((setObject == true)&&(ipz == false))
			{
				wait(3);
				printInventoryOnly();
			}
		}
		else if (inputVerb == "unequip")
		{
			cout << "Function not implemented yet." << endl;
		}
		else if (inputVerb == "drink") //for drinking potions
		{
			bool drinkPotion = false;
			Object minorhealingPotion("Minor Healing Potion", "minor healing potion");
			Object majorhealingPotion("Major Healing Potion", "major healing potion");

			if (inputObject == "")
			{
				cout << "You can't drink nothing. Be sure to type an object after 'drink'." << endl;
				drinkPotion = true;
			}
			if ((inputObject == minorhealingPotion.droppedActivationName)||(inputObject == majorhealingPotion.droppedActivationName))
			{
				for (int i = 0; i < 10; i++)
				{
					if ((inputObject == player.inventory[i].droppedActivationName)&&(drinkPotion == false))
					{
						if (player.health < player.maxHealth)
						{
							player.health += 5;
							if (player.health > player.maxHealth)
							{
								player.health = player.maxHealth;
							}
							player.inventory[i] = nullObject;
							drinkPotion = true;
							cout << "You used a healing potion!" << endl;
							wait(5);
							printInventoryOnly();
						}
						else
						{
							cout << "The potion will have no effect because you are already at full health." << endl;
							drinkPotion = true;
						}
					}
				}
				if (drinkPotion == false)
				{
					drinkPotion = true;
					cout << "There is no potion in your inventory." << endl;
				}
			}
			if (drinkPotion == false)
			{
				cout << "Unrecognized object." << endl;
			}
		
			
			
		}
		else if (inputVerb == "clear")
		{
			clear();
			printInventoryOnly();

		}
		else if (inputVerb == "info")
		{
			cout << "Function not implemented yet." << endl;
		}
		else
		{
			printDash(a);
			nl(2);
			cout << incorrectResponse;
			nl(1);
		}
	} while (inputRecognized == false);
}

//Puzzle and riddle fxns
void riddleInput(Object& inputRiddle) 
{
	Object nullObject("null", "null");
	Object leatherHelmet("Leather Helmet", "helmet");
	Object leatherChestplate("Leather Chestplate", "chestplate");
	Object leatherLeggings("Leather Leggings", "leggings");
	Object leatherBoots("Leather Boots", "boots");

	Object minorhealingPotion("Minor Healing Potion", "healing potion");
	Object majorhealingPotion("Major Healing Potion", "healing potion");

	Object broadSword("Iron Broadsword", "broadsword");

	
	Object easyDrops[2] = { nullObject, nullObject };
	Object mediumDrops[3] = { nullObject, nullObject, nullObject};
	Object hardDrops[4] = { nullObject, nullObject , nullObject, nullObject };

	bool inputRecognized = false;
	string inputAnswer;
	bool exit = false;
	if (inputRiddle.solved == true)
	{
		inputRecognized = true;
		cout << "\nYou already solved this riddle!\n";
		printDash(a);
		nl(1);
	}
	else
		cout << "\nEnter thy response here:\n";

	while (inputRecognized == false)
	{
		nl(1);
		cout << ">";
		getline(cin, inputAnswer);

		if (inputAnswer == "back")
		{
			clearScreenAndPrintBriefDescription();
			inputRecognized = true;
			exit = true;
		}

		for (int i = 0; i < 5; i++)
		{
			if ((inputAnswer != "")&&(inputAnswer == inputRiddle.answers[i]))
			{
				printDash(a);
				nl(2);
				cout << "Correct! Here is your reward...\n\n";//add in drops here based on the difficulty of the riddle
				
				
				inputRecognized = true;
				inputRiddle.solved = true;

				if (inputRiddle.difficulty == "easy")
				{
					easyDrops[0] = minorhealingPotion;

					int randomized = random(1, 10);

					if (randomized < 9)
					{
						if (randomized == 1 || randomized == 2)
						{
							easyDrops[1] = leatherBoots;
						}
						if (randomized == 3 || randomized == 4)
						{
							easyDrops[1] = leatherHelmet;
						}
						if (randomized == 5 || randomized == 6)
						{
							easyDrops[1] = leatherChestplate;
						}
						if (randomized == 7 || randomized == 8)
						{
							easyDrops[1] = leatherChestplate;
						}
					}
					else if (randomized >= 9)
					{
						easyDrops[1] = broadSword;
					}

					easyDrops[0].dropped = true;
					easyDrops[1].dropped = true;
					

					for (int i = 0; i < 2; i++)//for each object in easyDrops
					{
						bool setObject = false;
						for (int n = 0; n < 10; n++)
						{
							if ((player.currentLocation.objects[n].name == "null") &&(setObject == false))
							{
								player.currentLocation.objects[n] = easyDrops[i];
								setObject = true;
							}
						}
					}

					roomArray[player.currentLocation.id] = player.currentLocation;
					cout <<"A "<< easyDrops[0].name << " and " << easyDrops[1].name << " appear on the ground next to you.\n";
					changeDroppedString();
					printDash(a);
					nl(1);
					
				}
			}
		}

		if ((exit == false) && (inputRiddle.solved == false))
		{
			cout << "Incorrect answer. Type 'back' to exit. Or type another answer to try again.\n\n";
		}
	} 
}

//Miscelaneous
void changeDroppedString() 
{
	string a, b, c, d,e, f;
	a = "\n\nA";
	b = " lies on the floor.";
	c = " lie on the floor.";
	d = " and";
	e = ", ";
	f = " ";

	int id = player.currentLocation.id;
	int numberOfDroppedObjects = 0;
	string itemNames = "";

	for (int i = 0; i < 10; i++)
	{
		if ((roomArray[id].objects[i].name != "null") && (roomArray[id].objects[i].name != "None") && (roomArray[id].objects[i].dropped == true))
		{
			numberOfDroppedObjects++;
			if (numberOfDroppedObjects == 1)
			{
				itemNames += " ";
				itemNames += roomArray[id].objects[i].name;
			}
			else
				itemNames += e + roomArray[id].objects[i].name;
		}
		
	}
	if (numberOfDroppedObjects > 1)
	{
		roomArray[id].roomDescription[3] =  a + itemNames + c;
		player.currentLocation = roomArray[id];
	}
	else if (numberOfDroppedObjects == 1)
	{
		roomArray[id].roomDescription[3] =  a + itemNames + b;
		player.currentLocation = roomArray[id];
	}
	else if (numberOfDroppedObjects == 0)
	{
		roomArray[id].roomDescription[3] = "";
		player.currentLocation = roomArray[id];
	}
	
}
void clearScreenAndPrintBriefDescription()
{
	wait(1);
	clear();
	//printFancyPlusLine();
	printDash(a);
	cout << endl << player.currentLocation.name << ": " << endl;
	cout << player.currentLocation.briefRoomDescription << endl;
	//printFancyPlusLine();
	printDash(a);
	nl(2);
}
void updatePlayerStuff()
{
	player.defense = 0;
	for (int z = 0; z < 4; z++)
	{
		player.defense += player.equipedArmor[z].defense;
	}
}
void goToNextRoom(string inputVerb, string inputObject)//used when running in battles
{
	if (inputVerb == "go")
	{
		bool inputRecognized = false;
		for (int i = 0; i < 4; i++)
		{
			if ((inputObject == player.currentLocation.exitArray[i]) && (inputObject != "none"))
			{
				wait(6); 
				printDash(a);
				nl(2);
				//cout << "There is an exit in that direction." << endl;
				int newRoomID = player.currentLocation.surroundingRoomIDs[i];
				player.currentLocation = roomArray[newRoomID];

				//go to the room with the given ID
				if (i == 0)
				{
					cout << "You walk through the North exit.";
				}
				else if (i == 1)
				{
					cout << "You walk through the South exit.";
				}
				else if (i == 2)
				{
					cout << "You walk through the East exit.";
				}
				else if (i == 3)
				{
					cout << "You walk through the West exit.";
				}
				wait(1);
				cout << ".";
				wait(1);
				cout << ".";
				wait(1);
				cout << ".";
				clear();
				printDash(a);
				cout << endl << player.currentLocation.name << ": " << endl;
				cout << player.currentLocation.briefRoomDescription << endl;

				checkEnemyAggro("go");

				inputRecognized = true;
			}
		}

		if (inputRecognized == false)
		{
			if ((inputObject == "north") || (inputObject == "south") || (inputObject == "east") || (inputObject == "west"))
			{
				cout << "\nThere is no exit in that direction. Type the direction you want to go in again." << endl;
			}
			else
				cout << "\nUnrecognized direction. Type the direction you want to go in again." << endl;
			cout << ">";
			getline(cin, inputObject);
			goToNextRoom("go", inputObject);
		}
	}
}
