#ifndef Player_h
#define Player_h

#include <string>
#include "Room.h"
#include "Object.h"
using namespace std;

class Player
{
public:
	float health;
	float maxHealth;
	float stamina;
	float maxStamina;


	float defense;
	int numberOfKeys;
	//const int inventorySize;
	string name;
	Room currentLocation;
	Object mainWeapon;
	Object equipedArmor[4]; //helmet, chestplate, leggings, boots
	Object inventory[10]; //the current inventory
	Player();
	//Player(int ihealth, int imaxHealth, int idefense, Object imainWeapon, Object iarmor[], Object iinventory[]);
	//Player(string enemyName, int level);
};
Player::Player()
{
	Object nullObject("None", "null");
	Object fists("Fists", "fists");
	Object mythriliumHelm("Mythrilium Helmet", "mythrilium helmet");

	health = 20.0;
	maxHealth = 20;
	stamina = 15.0;
	maxStamina = 15;
	defense = 0;
	numberOfKeys = 0;
	mainWeapon = fists;
	for (int i = 0; i < 4; i++)
	{
		equipedArmor[i] = nullObject;
	}
	//equipedArmor[0] = mythriliumHelm;

	for (int i = 0; i < 4; i++)
	{
		defense += equipedArmor[i].defense;
	}

	for (int i = 0; i < 10; i++)
	{
		inventory[i] = nullObject;
	}
	

}
/*
Player::Player(int ihealth, int imaxHealth, int idefense, Object imainWeapon, Object iarmor[], Object iinventory[])
{
	health = ihealth;
	imaxHealth = maxHealth;
	defense = idefense;
	mainWeapon = imainWeapon;
	for (int i = 0; i < 4; i++)
	{
		equipedArmor[i] = iarmor[i];
	}
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = iinventory[i];
	}
}*/
/*Player::Player(string enemyName, int level)//something weird is going on here and I don't know why
{
	//initialize enemies 

	//set objects for the enemies
	Object dullDagger("Dull Dagger", "none", "weapon", "", true);
	Object noArmor[4];
	string keyDescription = "The key is made out of pure copper. It's rusted so much that it's nearly green in color. Hopefully it will still\nwork when you use it.";
	Object rustyKey("Rusty Key", "key", "key", keyDescription, true);
	Object emptyInventory[10];
	Object nullObject("null", "null", "null", "null", false);
	//for (int i = 0; i < 4; i++)
	//{
	//	noArmor[i] = nullObject;
	//}
	//for (int i = 0; i < 10; i++)
	//{
	//	emptyInventory[i] = nullObject;
	//}
	health = 0;
	maxHealth = 0;
	defense = 0;
	name = "";
	numberOfKeys = 0;
	mainWeapon = nullObject;
	currentLocation = Room(0);

	for (int i = 0; i < 4; i++)
	{
		equipedArmor[i] = nullObject;
	}
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = nullObject;
	}

	if ((enemyName == "Skeleton")&&(level == 1))
	{
		name = "Skeleton";
		health = 5;
		maxHealth = 5;
		numberOfKeys = 0;
		currentLocation = Room(0);
		defense = 0;
		mainWeapon = dullDagger;
		for (int i = 0; i < 4; i++)
		{
			equipedArmor[i] = noArmor[i];
		}
		for (int i = 0; i < 10; i++)
		{
			inventory[i] = emptyInventory[i] ;
		}
		inventory[0] = rustyKey;
		
		
	}
}*/

#endif

