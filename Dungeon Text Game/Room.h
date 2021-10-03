#ifndef Room_h
#define Room_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
//#include "main.cpp"

using namespace std; 




class Room
{
public:
	string name;
	int id;
	int surroundingRoomIDs[4];
	Object objects[10];
	Enemy enemy[5];
	string exitArray[4];//are there exits to the north, south, east and west directions
	Object doorArray[4];
	//string doorArray[4]; //are there doors or locked doors at the exits
	string briefRoomDescription;
	string roomDescription[4];//detailed room description, then exits, then set room objects (like sounds or weapons on the floor), then dropped objects
							  //for the dropped objects string just say "Items1, ... ItemsN lie on the floor." so that when more objects are dropped it just adds to the string
	string roomExitString;
	
	Room();
	Room(int number);
	string setExits(string exitArray[4]);
	void changeRoom(Room &currentRoom, string changeToBeCompleted, int index);
	void printRoomDescription(Room currentRoom);
	
private:

};

Room::Room()
{

}
Room::Room(int number)
{
	Enemy nullEnemy("null", 1, false, "null", 0.0);
	Object nullDoor("null", "null", false, "null", "null");
	Object noDoor("none", "none", true, "none", "none");
	for (int i = 0; i < 5; i++)
	{
		enemy[i] = nullEnemy;
	}

	Object nullObject("null", "null");

	for (int n = 0; n < 10; n++)
	{
		objects[n] = nullObject;//sets all objects to null to make sure the memory is set up
	}

	if (number == 0)
	{
		name = "null";
		id = 0;
		briefRoomDescription = "";
		//add exits for room 1
		string exits2[4] = { "none", "none", "none", "none" };
		Object doors[4] = { nullDoor, nullDoor, nullDoor, nullDoor };
		int surroundingRoomIDs2[4] = {0, 0, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doors[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 0
		for (int n = 0; n < 10; n++)
		{
			objects[n] = nullObject;//sets all objects to null to make sure the memory is set up
		}



		string room2Description[4] = { "Null\n", roomExitString, "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 1)
	{
		name = "Starting Room";
		id = 1;
		
		briefRoomDescription = "It's pitch black in here. But if I remember correctly, I think this is where you started.";
		//add exits for room 1
		string exits1[4] = {"north", "none", "none", "none" };
		

		//Object northDoor("door", "door", false, "key", "north");
		Object doorArray1[4] = { noDoor, noDoor, noDoor, noDoor };
		int surroundingRoomIDs1[4] = { 2, 0, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			exitArray[i] = exits1[i];
			doorArray[i] = doorArray1[i];
			surroundingRoomIDs[i] = surroundingRoomIDs1[i];
		}
		//roomExitString = setExits(exitArray);
		
		//add objects for room 1
		string wakingSlabDescription = "By touch you can tell that the slab is made of some sort of stone. It's too dark to see anything more. To determine\nthe slab's shape, you move your hands around all the edges and faces. After a few minutes, you decide that the slab\nmust be a simple rectangular block atop a cylindrical pedistal. Both the pedistal and slab are as smooth as silk.";
		Object wakingSlab("Waking Slab","slab", "furniture", wakingSlabDescription, false, "");
		Object stockSword("Dull Dagger", "sword");
		Object broadSword("Iron Broadsword", "broadsword");
		

		
		objects[0] = wakingSlab;
		objects[1] = stockSword;
		//objects[2] = broadSword;

		

		string room1Description[4] = {"Looking around yields no information because you can't see anything. The air seems cold and stale - as if it hasn't\nmoved around for ages. As you walk around the room, the 'clink clang' of your footsteps is the only sound in an\notherwise silent, mysterious room.\n\nFeeling around the room you find ", "an exit leading to the NORTH.", "","\n\nJust before you make your way back to the SLAB, you bang your foot on some small object. Kneeling down it seems\nto be some sort of SWORD."};
		for (int i = 0; i < 4; i++)
		{
				roomDescription[i] = room1Description[i];
		}

	}
	else if (number == 2)
	{
		name = "Hallway 1";
		id = 2;
		briefRoomDescription = "A long, dimly lit hallway greets you. Water drips from cracks in the ceiling onto the gray stone floor.";
		//add exits for room 1
		string exits2[4] = { "north", "south", "none", "none" };
		int surroundingRoomIDs2[4] = { 3, 1, 0, 0 };
		Object doorArray1[4] = { noDoor, noDoor, noDoor, noDoor };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			doorArray[i] = doorArray1[i];
			exitArray[i] = exits2[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2
		//Enemy skele("Skeleton", 1, true, "none");
		//enemy[0] = skele;
		
		string torchDescription = "Upon further inspection the torches seem to be locked in their holders. It's no use trying to force them out -\nthey won't budge.";
		Object torch("Torch","torches", "Light", torchDescription, false, "");
		objects[0] = torch;

		

		string room2Description[4] = { "TORCHES line the walls and it's eerily silent. There are ", roomExitString, "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 3)
	{
		name = "Pit Room 1";
		id = 3;
		briefRoomDescription = "You come into a room with a massive circular PIT at its center. A stream of water coming from the hallway to the south\nflows into it.";
		//add exits for room 1
		string exits2[4] = { "north", "south", "east", "none" };
		int surroundingRoomIDs2[4] = { 5, 2, 4, 0 };

		Object eastDoor("door", "door", false, "none", "east");//change condition back to 'key' later
		Object northDoor("door", "door", false, "none", "east");
		Object doorArray1[4] = { northDoor, noDoor, eastDoor, noDoor };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doorArray1[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2
		string pitDescription = "You carefully lean over the gaping hole. The lighting in the room is decently bright, but the bottom lies in shadow ...\nif there even is a bottom.";
		Object pit("Pit","pit","Pit" ,pitDescription , false, "");
		objects[0] = pit;
		
		//Enemy skele("Skeleton", 1, true, "none", 0.0); //uncomment later
		//enemy[0] = skele;
		
		string room2Description[4] = { "The massive circular PIT takes up about half the area of the room. Moss lines the walls and the air is damp,\nbut significantly less stuffy. There are ", roomExitString, "" , ""};
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 4)
	{
		name = "Hallway 2";
		id = 4;
		briefRoomDescription = "A short narrow hallway greets you. The only light filters in from the rooms behind and in front of you.";
		//add exits for room 1
		string exits2[4] = { "none", "south", "east", "west" };
		int surroundingRoomIDs2[4] = { 0, 11, 6, 3};
		Object southDoor("door", "door", false, "none", "south"); //change to key condition later
		Object doorArray1[4] = { noDoor, southDoor, noDoor, noDoor };

		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doorArray1[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2

		string room2Description[4] = { "The walls are made of stone brick. On your left side, the stone's nearly crumbling. There's nothing else of interest in this hallway.\n\nThere are ", roomExitString, "" , ""};
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
		//Enemy skele("Skeleton", 1, true, "none");
		//enemy[0] = skele;
	}
	else if (number == 5)
	{
		name = "Small Chamber 1";
		id = 5;
		briefRoomDescription = "You enter a tiny, cramped room that isn't even big enough to swing a sword. There's a pedistal in the middle of the\nroom.";
		//add exits for room 1
		string exits2[4] = { "none", "south", "none", "none" };
		Object southDoor("door", "door", true, "none", "east");
		Object doorArray1[4] = { noDoor, southDoor, noDoor, noDoor };
		int surroundingRoomIDs2[4] = { 0, 3, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doorArray1[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2
		string keyDescription = "The key is made out of pure copper. It's rusted so much that it's nearly green in color. Hopefully it will still\nwork when you use it.";
		Object rustyKey("Rusty Key", "key", "key", keyDescription, true, "rusty key");

		objects[0] = rustyKey;

		//Enemy skele("Skeleton", 1, true, "none");
		//enemy[0] = skele;

		string room2Description[4] = { "There are ", roomExitString, "" , " A small rusty KEY lies on the pedistal."};
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 6)
	{
		name = "Stairway 1";
		id = 6;
		briefRoomDescription = "A small staircase goes up towards the east. Each step is stubby, short, and high.";
		//add exits for room 1
		string exits2[4] = { "none", "none", "east", "west" };
		int surroundingRoomIDs2[4] = { 0,0, 7, 4 };
		Object eastDoor("door", "door", false, "none", "east");
		Object doorArray1[4] = { noDoor, noDoor, eastDoor,noDoor };

		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doorArray1[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2

		string room2Description[4] = { "The center of each stair is worn down. This place must have had a lot of foot traffic at some point in the past. You\ncan't help but wonder why the builders of the staircase decided to make it so steep. Why didn't they put a spiral\nstaircase here instead?\n\nThere are ", roomExitString, "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 7)
	{
		name = "Statue Hall (Floor 1)";
		id = 7;
		briefRoomDescription = "A massive circular hall stands before you. Upon a raised platform at the center of the\nroom, lies a STATUE of a great King sitting in his throne while a Knight, on his knees, pledges fealty to\nhim. The King is illuminated by a bright light coming from the ceiling.";
		//add exits for room 1
		string exits2[4] = { "north", "south", "east", "west" };
		int surroundingRoomIDs2[4] = { 11,10, 8, 6 };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2
		string grandStatueDescription = "Upon closer inspection, the Kings robes seem to be fashioned out of pure gold. The King strokes his long\nbeard with his hand. His eyes are aimed directly at the knight pledging fealty and his mouth seems to be\nconfused as to whether it's grinning or locked in contemplation. Three feet to the south the statue of the\nKnight made of pure iron. He has one knee to the floor and the other provides a support for his arm.\nThe knight is fully clad in dark gray armor, but his faceguard is raised. The knight's sword is firmly\nplanted with its tip into the ground. A PLAQUE upon a pedistal sits in front of the scene.";
		string domeDescription = "The dome is thousands of feet above you, so in order to see what the murals show, you have to squint and\ntry your best to make out figures from a blurry image. The murals seems to depict some sort of great\nbattle that likely happened more than a millenia ago. The great King from the statue at the center of the\nroom is the largest figure of the mural and is depicted slaying a Great Beast of Shadow with a sword\nshining with the light of the sun. Behind the King lies a massive army in the process of charging. Behind\nthe Great Beast, a dark army stands their ground in a coordinated shield wall.";
		string plaqueDescription = "The text on the plaque is so worn that nothing can be made out. However, you suspect this was an\nimportant historical moment. ";
		Object dome("Dome","dome", "furniture", domeDescription, false, "");
		Object grandStatue("Grand Statue","statue", "furniture", grandStatueDescription, false, "");
		Object plaque("Plaque","plaque", "furniture", plaqueDescription, false, "");


		objects[0] = dome;
		objects[1] = grandStatue;
		objects[2] = plaque;

		string room2Description[4] = { "The walls are lined with tall, crimson stone columns. Looking upward the columns rise for stories upon\nstories until they reach a massive, muraled DOME. From the dome's center comes an intense stream of light\nwhich grows and grows in width until it reaches the golden statue of the King.\n\nAbout one-hundred feet above you a balcony protrudes from the wall. Higher up there seems like there might\nbe additionally balconies and floors, but it doesn't look like there's anyway to get up there here.But\nperhaps some passageway will lead there.\n\nA large, golden door lies to the EAST. A stairway downwards lies to the WEST. ","", "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 8)
	{

	}
	else if (number == 9)
	{
		name = "Stairway 2";
		id = 9;
		briefRoomDescription = "";
		//add exits for room 1
		string exits2[4] = { "north", "south", "none", "none" };
		int surroundingRoomIDs2[4] = { 7,10, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2



		string room2Description[4] = { "There are ", roomExitString, "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 10)
	{
		name = "Small Chamber 2";
		id = 10;
		briefRoomDescription = "Coming from the Statue Hall the room is underwhelming. It's just a small side room with a stone COFFIN\nat it's center.";
		//add exits for room 1
		string exits2[4] = { "north", "none", "none", "none" };
		int surroundingRoomIDs2[4] = { 9,0, 0,0 };
		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 10
		string coffinDescription = "The coffin is closed but has a large crack in its lid. There used to be an inscription\nbut it's too worn to see much of anything. You vaguely can make out the date '439 KE' but your not sure if it's correct.";
		Object coffin("Coffin", "coffin", "furniture", coffinDescription, false, "");

		string soundDescription = "As you edge toward the dark corner the sound becomes louder. The closer you get the more it sounds like a weird\nrattling.";
		Object sound("Enemy Growl", "sound", "noise", soundDescription, false, "");
		objects[0] = coffin;
		objects[1] = sound;

		Enemy basicEnemy("Skeleton", 2, false, "examine sound", 100); 
		enemy[0] = basicEnemy;

		string room2Description[4] = { "There are ", roomExitString, " You hear a strange SOUND coming from a dark corner of the room." , ""};
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
	else if (number == 11)
	{
		name = "Riddle Room 1";
		id = 11;
		briefRoomDescription = "You enter a room with a circular POND at its center. A lone PLAQUE sits in front of the pond.";
		//add exits for room 1
		string exits2[4] = { "north", "none", "none", "none" };
		int surroundingRoomIDs2[4] = { 4,0, 0, 0 };
		Object northDoor("door", "door", true, "none", "east");
		Object doorArray1[4] = { northDoor, noDoor, noDoor,noDoor };

		for (int i = 0; i < 4; i++)
		{
			surroundingRoomIDs[i] = surroundingRoomIDs2[i];
			exitArray[i] = exits2[i];
			doorArray[i] = doorArray1[i];
		}
		roomExitString = setExits(exitArray);

		//add objects for room 2
		string pondDescription = "The water in the pond is still and cold and looks like it's been that way for a long time. You can't tell what they are,\nbut there are some strange glowing RUNES at the bottom of the pond.";
		Object pond("Pond", "pond", "surroundings", pondDescription, false, "");
		objects[0] = pond;

		string plaqueDescription = "There's an inscription carved into the light gray stone face of the plaque.";
		Object plaque("Plaque", "plaque", plaqueDescription, "easy");
		objects[1] = plaque;

		string runesDescription = "You stare at the runes for a long time. How much time you cannot tell. There's just something about them that seems\nfamiliar. The only portions that you can make out read 'Uloni respa --- mes-- valrora.'";
		Object runes("Runes", "runes", "surroundings", runesDescription, false, "");
		objects[2] = runes;


		string room2Description[4] = { "Besides the POND and the PLAQUE, the air is damp but very cold. The stone around the pond is slippery with moss and\nlichen. The only light in the room comes from a faint glow at the center of the pond.\n\nThere are ", roomExitString, "", "" };
		for (int i = 0; i < 4; i++)
		{
			roomDescription[i] = room2Description[i];
		}
	}
}
string Room::setExits(string exitArray[4])//it's probably better to not use this function and to just do it manually
{
	string output = "exits to the ";
	for (int i = 0; i < 4; i++)
	{
		if (exitArray[i] != "none")
		{
			if (i == 0)
			{
				output += "NORTH";
			}
			if (i == 1)
			{
				if (output == "exits to the NORTH")
				{
					output += ", ";
				}
				output += "SOUTH";
			}
			if (i == 2)
			{
				if ((output == "exits to the NORTH")||(output == "exits to the NORTH, SOUTH"))
				{
					output += ", ";
				}
				output += "EAST";
			}
			if (i == 3)
			{
				if ((output == "exits to the NORTH") || (output == "exits to the NORTH, SOUTH") || (output == "exits to the NORTH, SOUTH, EAST"))
				{
					output += ", ";
				}
				output += "WEST";
			}
		}
	}
	output += ".";
	return output;
}
void Room::printRoomDescription(Room currentRoom)
{

	
	for (int i = 0; i < 4; i++)
	{
		cout << currentRoom.roomDescription[i];
	}
}

void Room::changeRoom(Room &currentRoom, string changeToBeCompleted, int index) 
{
	Enemy nullEnemy("null", 1, false, "null", 0.0);
	Object nullObject("null", "null");
	//this function is going to need to get a lot more complicated...
	// it will be called when the player picks up or drops and object, when the player defeats an enemy or basically whenever a room is 
	// changed from its starting state
	if (changeToBeCompleted == "deleteObject")
	{
		currentRoom.objects[index] = nullObject;
	}
	if (changeToBeCompleted == "createObject")
	{

	}
	if (changeToBeCompleted == "enemyDefeated")
	{
		
		currentRoom.enemy[index] = nullEnemy;
	}
	



	if (currentRoom.id == 1)
	{
		for (int i = 0; i < 3; i++)
		{

			if ((i == 2) && (currentRoom.objects[1].name == "null"))
			{
				currentRoom.roomDescription[i] = "";
			}
		}
	}
	if (currentRoom.id == 5)
	{
		for (int i = 0; i < 3; i++)
		{

			if ((i == 0) && (currentRoom.objects[0].name == "null"))
			{
				currentRoom.roomDescription[i] = "There are ";
			}
		}
	}
}
#endif
