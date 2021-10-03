#ifndef Object_h
#define Object_h
#include <string>
using namespace std;

int random(int start, int end);

class Object
{
public:
	//for general objects
	string name;
	string activationName;
	string droppedActivationName;
	bool dropped;
	string type; //possible types include weapon, armor, potionHealing, key, door, healthUp, furniture
	string description;
	bool pickupAble;

	//for weapons
	float damage;
	string weaponType;

	//for armor
	float defense;
	string armorType;

	//for potions
	string potionType;
	//damage is used as the damage healed

	//for doors
	bool open;
	string openCondition;
	string direction;

	//for riddle plaques and puzzles
	string answers[5];
	string difficulty;//"easy" "medium" or "hard"
	bool solved;
	
	Object();
	Object(string inputObjectName, string inputActivationName);
	Object(string inputObjectName, string inputActivationName, bool inputOpen, string inputOpenCondition, string inputDirection);//for doors
	Object(string inputObjectName, string inputActivationName, string inputPreliminaryDescription, string inputDifficulty); //for riddles
	Object(string inputName, string inputActivationName, string inputType, string description, bool inputPickupAble, string inputDroppedActivationName);
	Object(string inputName, string inputActivationName, string inputType, string inputDescription, bool inputPickupAble, float inputDamage, string inputWeaponType, string inputDroppedActivationName);
};
int random(int start, int end)//picks a random number from the start to the end number
{
	int range = (end - start) + 1;
	int a = -1;
	a = rand() % range + start;
	return a;
}
Object::Object()
{

}
Object::Object(string inputObjectName, string inputActivationName)
{
	dropped = false;
	//Armor sets
		//Leather armor set (2/3 rds of damage)
		if (inputObjectName == "Leather Helmet")
		{
			string leatherHelmetDescription = "A finely crafted helmet made of leather.";
			droppedActivationName = "leather helmet";
			name = "Leather Helmet";
			activationName = inputActivationName;
			type = "armor";
			description = leatherHelmetDescription;
			pickupAble = true;
			defense = 1.;
			armorType = "helmet";
		}
		else if (inputObjectName == "Leather Chestplate")
		{
			string leatherChestplateDescription = "A finely crafted chestplate made of leather.";
			droppedActivationName = "leather chestplate";
			name = "Leather Chestplate";
			activationName = inputActivationName;
			type = "armor";
			description = leatherChestplateDescription;
			pickupAble = true;
			defense = 2.;
			armorType = "chestplate";
		}
		else if (inputObjectName == "Leather Leggings")
		{
			string leatherLeggingsDescription = "A finely crafted pair of leggings made of leather.";
			name = "Leather Leggings";
			droppedActivationName = "leather leggings";
			activationName = inputActivationName;
			type = "armor";
			description = leatherLeggingsDescription;
			pickupAble = true;
			defense = 1.;
			armorType = "leggings";
		}
		else if (inputObjectName == "Leather Boots")
		{
			string leatherBootsDescription = "A finely crafted pair of boots made of pure leather.";
			name = "Leather Boots";
			droppedActivationName = "leather boots";
			activationName = inputActivationName;
			type = "armor";
			description = leatherBootsDescription;
			pickupAble = true;
			defense = 1.;
			armorType = "boots";
		}

		//Iron armor set (1/2 of damage)
		if (inputObjectName == "Iron Helmet")
		{
			string ironHelmetDescription = "A finely crafted helmet made of pure iron.";
			name = "Iron Helmet";
			droppedActivationName = "iron helmet";
			activationName = inputActivationName;
			type = "armor";
			description = ironHelmetDescription;
			pickupAble = true;
			defense = 2.;
			armorType = "helmet";
		}
		else if (inputObjectName == "Iron Chestplate")
		{
			string ironChestplateDescription = "A finely crafted chestplate made of pure iron.";
			name = "Iron Chestplate";
			activationName = inputActivationName;
			droppedActivationName = "iron chestplate";
			type = "armor";
			description = ironChestplateDescription;
			pickupAble = true;
			defense = 4.;
			armorType = "chestplate";
		}
		else if (inputObjectName == "Iron Leggings")
		{
			string ironLeggingsDescription = "A finely crafted pair of leggings made of pure iron.";
			name = "Iron Leggings";
			activationName = inputActivationName;
			droppedActivationName = "iron leggings";
			type = "armor";
			description = ironLeggingsDescription;
			pickupAble = true;
			defense = 2.;
			armorType = "leggings";
		}
		else if (inputObjectName == "Iron Boots")
		{
			string ironBootsDescription = "A finely crafted pair of boots made of pure iron.";
			name = "Iron Boots";
			activationName = inputActivationName;
			droppedActivationName = "iron boots";
			type = "armor";
			description = ironBootsDescription;
			pickupAble = true;
			defense = 2.;
			armorType = "leggings";
		}

		//Steel armor set (1/3 of damage)
		if (inputObjectName == "Steel Helmet")
		{
			string steelHelmetDescription = "A finely crafted helmet made of pure steel.";
			name = "Steel Helmet";
			activationName = inputActivationName;
			droppedActivationName = "steel helmet";
			type = "armor";
			description = steelHelmetDescription;
			pickupAble = true;
			defense = 5.;
			armorType = "helmet";
		}
		else if (inputObjectName == "Steel Chestplate")
		{
			string steelChestplateDescription = "A finely crafted chestplate made of pure steel.";
			name = "Steel Chestplate";
			droppedActivationName = "steel chestplate";
			activationName = inputActivationName;
			type = "armor";
			description = steelChestplateDescription;
			pickupAble = true;
			defense = 6.;
			armorType = "chestplate";
		}
		else if (inputObjectName == "Steel Leggings")
		{
			string steelLeggingsDescription = "A finely crafted pair of leggings made of pure steel.";
			name = "Steel Leggings";
			activationName = inputActivationName;
			droppedActivationName = "steel leggings";
			type = "armor";
			description = steelLeggingsDescription;
			pickupAble = true;
			defense = 5.;
			armorType = "leggings";
		}
		else if (inputObjectName == "Steel Boots")
		{
			string steelBootsDescription = "A finely crafted pair of boots made of pure steel.";
			name = "Steel Boots";
			activationName = inputActivationName;
			droppedActivationName = "steel boots";
			type = "armor";
			description = steelBootsDescription;
			pickupAble = true;
			defense = 4.;
			armorType = "leggings";
		}

		//Mythrilium armor set (1/4 of damage)
		if (inputObjectName == "Mythrilium Helmet")
		{
			string mythriliumHelmetDescription = "A helmet crafted from the rare, ancient ore, Mythrilium. It's a helmet that only Kings deserve.";
			name = "Mythrilium Helmet";
			droppedActivationName = "mythrilium helmet";
			activationName = inputActivationName;
			type = "armor";
			description = mythriliumHelmetDescription;
			pickupAble = true;
			defense = 6.;
			armorType = "helmet";
		}
		else if (inputObjectName == "Mythrilium Chestplate")
		{
			string mythriliumChestplateDescription = "A chestplate crafted from the rare, ancient ore, Mythrilium. It's a chestplate that only Kings deserve.";
			name = "Mythrilium Chestplate";
			droppedActivationName = "mythrilium chestplate";
			activationName = inputActivationName;
			type = "armor";
			description = mythriliumChestplateDescription;
			pickupAble = true;
			defense = 10.;
			armorType = "chestplate";
		}
		else if (inputObjectName == "Mythrilium Leggings")
		{
			string mythriliumLeggingsDescription = "A pair of leggings crafted from the rare, ancient ore, Mythrilium. It's pair of leggings that only Kings deserve..";
			name = "Mythrilium Leggings";
			droppedActivationName = "mythrilium leggings";
			activationName = inputActivationName;
			type = "armor";
			description = mythriliumLeggingsDescription;
			pickupAble = true;
			defense = 8.;
			armorType = "leggings";
		}
		else if (inputObjectName == "Mythrilium Boots")
		{
			string mythriliumBootsDescription = "A pair of leggings crafted from the rare, ancient ore, Mythrilium. It's a pair of boots that only Kings deserve.";
			name = "Mythrilium Boots";
			droppedActivationName = "mythrilium boots";
			activationName = inputActivationName;
			type = "armor";
			description = mythriliumBootsDescription;
			pickupAble = true;
			defense = 6.;
			armorType = "leggings";
		}

	//Weapons
		if (inputObjectName == "Fists")
		{
			string fistsDescription = "It's just you and your bare hands against the world!";
			name = "Fists";
			activationName = inputActivationName;
			droppedActivationName = "fists";
			type = "weapon";
			description = fistsDescription;
			pickupAble = true;
			damage = 1;
			weaponType = "melee";
		}
		if (inputObjectName == "Dull Dagger")
		{
			string stockSwordDescription = "The sword is little more than a dull dagger, but it will do.";
			name = "Dull Dagger";
			droppedActivationName = "dull dagger";
			activationName = inputActivationName;
			type = "weapon";
			description = stockSwordDescription;
			pickupAble = true;
			damage = 3;
			weaponType = "melee";
		}
		if (inputObjectName == "Iron Broadsword")
		{
			string broadswordDescription = "It's golden hilt shines in the light. Testing it's sharpness you cut your finger on the blade meant for proper Knights.";
			name = "Iron Broadsword";
			droppedActivationName = "iron broadsword";
			activationName = inputActivationName;
			type = "weapon";
			description = broadswordDescription;
			pickupAble = true;
			damage = 6;
			weaponType = "melee";
		}


	//Potions
		if (inputObjectName == "Minor Healing Potion")
		{
			string healingPotionDescription = "A red liquid in a glass bottle that apparently heals you.";
			name = "Minor Healing Potion";
			activationName = inputActivationName;
			droppedActivationName = "minor healing potion";
			type = "potion";
			description = healingPotionDescription;
			pickupAble = true;
			damage = 5;//also the health healed
			potionType = "healing";
		}
		if (inputObjectName == "Major Healing Potion")
		{
			string healingPotionDescription = "An extremely red liquid in a glass bottle that apparently heals you quite a bit.";
			name = "Major Healing Potion";
			activationName = inputActivationName;
			droppedActivationName = "major healing potion";
			type = "potion";
			description = healingPotionDescription;
			pickupAble = true;
			damage = 10;//also the health healed
			potionType = "healing";
		}
	//Null objects
		if (inputObjectName == "null")
		{
			name = "null";
			activationName = "null";
			droppedActivationName = "";
			type = "null";
			description = "null";
			pickupAble = false;
			damage = 0;
			weaponType = "null";
			armorType = "null";
			defense = 0;
		}
		else if (inputObjectName == "None")
		{
			name = "None";
			activationName = "None";
			type = "null";
			description = "null";
			pickupAble = false;
			droppedActivationName = "";
			damage = 0;
			defense = 0;
			weaponType = "null";
			armorType = "null";
		}
}
Object::Object(string inputObjectName, string inputActivationName, bool inputOpen, string inputOpenCondition, string inputDirection)
{//constructor for doors and gateways
	name = inputObjectName;
	activationName = inputActivationName;
	open = inputOpen;
	openCondition = inputOpenCondition;
	direction = inputDirection;
}
Object::Object(string inputObjectName, string inputActivationName, string inputPreliminaryDescription, string inputDifficulty)
{//constructor for riddles and puzzles
	name = inputObjectName;
	activationName = inputActivationName;
	solved = false;
	difficulty = inputDifficulty;
	type = "riddle";
	pickupAble = false;
	int pickRiddle;

	description = inputPreliminaryDescription;

	//riddles and their data go here
	if (difficulty == "easy")
	{
		pickRiddle = random(1, 3);
		description += " The inscription reads:\n\n";

		if (pickRiddle == 1)
		{
			description += "I'm marked for life unlike any other, yet I have all the power. I can make people do what I want by simply waving my\nhand, yet I never can tell apart those who tell the truth from those who manipulate my every move. One day I may end\nup with a dagger in my back, if only I tread the wrong path.";
			answers[0] = "king";
			answers[1] = "leader";
			answers[2] = "the king";
			answers[3] = "a king";
			answers[4] = "";
		}
		else if (pickRiddle == 2)
		{
			description += "What always runs in circles, never getting tired. That glows, but doesn't produce it's own light. That's always there,\nbut is hidden half of the time?";
			answers[0] = "the moon";
			answers[1] = "moon";
			answers[2] = "";
			answers[3] = "";
			answers[4] = "";
		}
		else if (pickRiddle == 3)
		{
			description += "What is beautiful that can be heard, but not be seen directly? It has many forms, yet comes from few elements. It\ncommunicates what words cannot express and has cords that never get tangled.";
			answers[0] = "music";
			answers[1] = "";
			answers[2] = "";
			answers[3] = "";
			answers[4] = "";
		}
		

		
	}
	
}
Object::Object(string inputName, string inputActivationName, string inputType, string inputDescription, bool inputPickupAble, string inputDroppedActivationName)
{
	//initialization of normal objects
	name = inputName;
	activationName = inputActivationName;
	type = inputType;
	description = inputDescription;
	pickupAble = inputPickupAble;
	dropped = false;
	droppedActivationName = inputDroppedActivationName;

}
Object::Object(string inputName, string inputActivationName, string inputType, string inputDescription, bool inputPickupAble, float inputDamage,  string inputWeaponType, string inputDroppedActivationName)
{
	//initialization of weapons
	name = inputName;
	activationName = inputActivationName;
	type = inputType;
	description = inputDescription;
	pickupAble = inputPickupAble;
	damage = inputDamage;
	weaponType = inputWeaponType;
	dropped = false;
	droppedActivationName = inputDroppedActivationName;

}



#endif
