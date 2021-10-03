#ifndef Enemy_h
#define Enemy_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Object.h"
using namespace std;

class Enemy
{
public:
	string name;
	float health;
	float maxHealth;
	float stamina;
	float maxStamina;
	float defense;
	bool aggro;
	string aggroCondition;
	Object mainWeapon;
	Object equipedArmor[4]; //helmet, chestplate, leggings, boots
	Object inventory[10]; //the current inventory (where items drop from upon death)
	int dropRates[10]; //the drop rates for each inventory item
	//add in drop percentages here
	Enemy();
	Enemy(string enemyName, int level, bool inputAggro, string inputAggroCondition, float dropKeyRate);
};

Enemy::Enemy()
{

}
Enemy::Enemy(string enemyName, int level, bool inputAggro, string inputAggroCondition, float dropKeyRate)//something weird is going on here and I don't know why
{
	//initialize enemies 

	//set objects for the enemies
	Object dullDagger("Dull Dagger", "none", "weapon", "", true, 3, "melee", "dull dagger");
	Object broadSword("Iron Broadsword", "broadsword");
	Object ironHelmet("Iron Helmet", "helmet");
	Object ironChestplate("Iron Chestplate", "chestplate");
	Object ironLeggings("Iron Leggings", "leggings");
	Object ironBoots("Iron Boots", "boots");
	Object leatherHelmet("Leather Helmet", "helmet");
	Object leatherChestplate("Leather Chestplate", "chestplate");
	Object leatherLeggings("Leather Leggings", "leggings");
	Object leatherBoots("Leather Boots", "boots");
	Object noArmor[4];

	string keyDescription = "The key is made out of pure copper. It's rusted so much that it's nearly green in color. Hopefully it will still\nwork when you use it.";
	Object rustyKey("Rusty Key", "key", "key", keyDescription, true, "rusty key");
	string ironKeyDescription = "It's a perfectly average key made out of pure iron.";
	Object ironKey("Iron Key", "key", "key", ironKeyDescription, true, "iron key");

	Object minorhealingPotion("Minor Healing Potion", "healing potion");
	Object majorhealingPotion("Major Healing Potion", "healing potion");

	Object emptyInventory[10];
	Object nullObject("null", "null");
	for (int i = 0; i < 4; i++)
	{
		noArmor[i] = nullObject;
	}
	for (int i = 0; i < 10; i++)
	{
		emptyInventory[i] = nullObject;
		dropRates[i] = 0;
	}
	aggro = inputAggro;
	aggroCondition = inputAggroCondition;
	

	for (int i = 0; i < 4; i++)
	{
		equipedArmor[i] = nullObject;
	}
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = nullObject;
	}
	
	//initialize skeletons
	if (enemyName == "Skeleton")
	{
		name = "Skeleton";
		defense = 0;//starts at 0 ... increases based on the armor worn

		for (int i = 0; i < 4; i++)
		{
			equipedArmor[i] = noArmor[i];
		}
		for (int i = 0; i < 10; i++)
		{
			inventory[i] = emptyInventory[i];
		}

		if (level == 1)
		{
			
			health = random(3, 6);
			maxHealth = health;
			stamina = random(7,10);
			maxStamina = stamina;
			mainWeapon = dullDagger;
			inventory[0] = ironKey;
			dropRates[0] = dropKeyRate;//always drops an iron key
			inventory[1] = minorhealingPotion;
			dropRates[1] = 50;//drops a healing potion half of the time
		}
		else if (level == 2)
		{
			health = random(7,10);
			maxHealth = health;
			stamina = random(18,21);
			maxStamina = stamina;
			mainWeapon = broadSword;
			inventory[0] = ironKey;
			inventory[1] = minorhealingPotion;
			inventory[2] = leatherChestplate;
			inventory[3] = leatherLeggings;
			inventory[4] = leatherBoots;
			inventory[5] = majorhealingPotion;
			dropRates[0] = dropKeyRate;
			dropRates[1] = 50;
			dropRates[2] = 1;
			dropRates[3] = 1;
			dropRates[4] = 2;
			dropRates[5] = 10;
			equipedArmor[0] = leatherHelmet;
			equipedArmor[1] = leatherChestplate;
			for (int i = 0; i < 4; i++)
			{
				defense += equipedArmor[i].defense;
			}
		}
		else if (level == 3)
		{
			health = random(10,15);
			maxHealth = health;
			stamina = random(27,32);
			maxStamina = stamina;
			mainWeapon = broadSword;
			inventory[0] = ironKey;
			inventory[1] = majorhealingPotion;
			dropRates[0] = dropKeyRate;
			dropRates[1] = 50;
			equipedArmor[0] = ironHelmet;
			equipedArmor[1] = ironChestplate;
			equipedArmor[2] = ironLeggings;
			equipedArmor[3] = ironBoots;
			for (int i = 0; i < 4; i++)
			{
				defense += equipedArmor[i].defense;
			}
		}
	}
	
	if (enemyName == "null")
	{
		health = 0;
		maxHealth = 0;
		defense = 0;
		name = "";
		mainWeapon = nullObject;
		for (int i = 0; i < 4; i++)
		{
			equipedArmor[i] = nullObject;
		}
		for (int i = 0; i < 10; i++)
		{
			inventory[i] = nullObject;
		}
	}
}
#endif

