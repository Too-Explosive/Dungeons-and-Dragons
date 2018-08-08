#pragma once
#include <string>
#define SLASHING "slashing"
#define PIERCING "piercing"
#define BLUDGEONING	"bludgeoning"
#define SCIMITAR weapon(0, 25, SLASHING, 1, 6, 3, true)
#define CLUB weapon(0, 1, BLUDGEONING, 1, 4, 2)
#define DAGGER weapon(60, 2, PIERCING, 1, 4, 1, true)
#define GREATCLUB weapon(0, 2, BLUDGEONING, 1, 8, 10)
#define HANDAXE weapon(60, 5, SLASHING, 1, 6, 2)
#define JAVELIN weapon(120, 5, PIERCING, 1, 6, 2)
#define LIGHT_HAMMER weapon(60, 2, BLUDGEONING, 1, 4, 2)
#define MACE weapon(0, 5, BLUDGEONING, 1, 6, 4)
#define WHIP weapon(0, 2, SLASHING, 1, 4, 3, true)
#define QUARTERSTAFF weapon(0, 2, BLUDGEONING, 1, 6, 4, false, false, false, true)
#define SICKLE weapon(0, 1, SLASHING, 1, 4, 2)
#define HEAVY_CROSSBOW weapon(400, 50, PIERCING, 1, 10, 18, false, true)
#define SPEAR weapon(60, 1, PIERCING, 1, 6, 3, false, false, false, true)
#define LIGHT_CROSSBOW weapon(320, 25, PIERCING, 1, 8, 5, false, false, true)
#define DART weapon(60, 5, PIERCING, 1, 4, .25, true)
#define WAR_PICK weapon(0, 5, PIERCING, 1, 8, 2)
#define WARHAMMER weapon(0, 15, BLUDGEONING,1, 8, 2, false, false, false, true)
#define SHORTBOW weapon(320, 25, PIERCING, 1, 6, 2, false, false, true)
#define SLING weapon(120, 1, BLUDGEONING, 1, 4, 0)
#define BATTLEAXE weapon(0, 10, SLASHING, 1, 8, 4, false, false, false, true)
#define FLAIL weapon(0, 10, BLUDGEONING, 1, 8, 2)
#define BLOWGUN weapon(100, 10, PIERCING, 1, 1, 1)
#define TRIDENT weapon(60, 5, PIERCING, 1, 6, 4, false, false, false, true)
#define GLAIVE weapon(0, 20, SLASHING, 1, 10, 6, false, true, true)
#define GREATAXE weapon(0, 30, SLASHING, 1, 12, 7, false, true)
#define GREATSWORD weapon(0, 50, SLASHING, 2, 6, 6, false, true, true)
#define HALBERD weapon(0, 20, SLASHING, 1, 10, 6, false, true, true)
#define LONGSWORD weapon(0, 15, SLASHING, 1, 8, 3, false, false, false, true)
#define MAUL weapon(0, 10, BLUDGEONING, 2, 6, 10, false, true, true)
#define MORNINGSTAR weapon(0, 15, PIERCING, 1, 8, 4)
#define RAPIER weapon(0, 25, PIERCING, 1, 8, 2, true)
#define SHORTSWORD weapon(0, 10, PIERCING, 1, 6, 2, true)
#define PIKE weapon(0, 5, PIERCING, 1, 10, 18, false, true, true)
#define HAND_CROSSBOW weapon(120, 75, PIERCING, 1, 6, 3)
#define LONGBOW weapon(600, 50, PIERCING, 1, 8, 2, false, true, true)

class weapon
{
private:
	int range;
	int cost;
	std::string damage;
	int numDice;
	int diceType;
	float weight;
	bool finesse;
	bool heavy;
	bool twoHanded;
	bool versatile;
public:
	weapon()
	{
		range = 0;
		cost = 0;
		damage = "";
		numDice = 0;
		diceType = 0;
		weight = 0;
		finesse = heavy = twoHanded = versatile = false;
	}
	weapon(int Range, int Cost, std::string Damage, int NumDice, int DiceType, float Weight, bool Finesse = false, bool Heavy = false, bool TwoHanded = false, bool Versatile = false)
	{
		range = Range;
		cost = Cost;
		damage = Damage;
		numDice = NumDice;
		diceType = DiceType;
		weight = Weight;
		finesse = Finesse;
		heavy = Heavy;
		twoHanded = TwoHanded;
		versatile = Versatile;
	}
	bool operator== (const weapon &weap)
	{
		if (this->range != weap.range || this->cost != weap.cost || this->damage != weap.damage || this->numDice != weap.numDice || this->diceType != weap.diceType || this->weight != weap.weight || this->finesse != weap.finesse || this->heavy != weap.heavy || this->twoHanded != weap.twoHanded || this->versatile != weap.versatile)
			return false;
		return true;
	}

	//Gives a weapon's range
	//Return: The range of the weapon as an int
	int getRange()
	{
		return range;
	}

	//Tells if a weapon has finesse
	//Return: A boolean with true if the weapon has finesse
	bool getFinesse()
	{
		return finesse;
	}

	//Gives a name specific to each weapon
	//Return: The name of the weapon as a std::string
	std::string toString()
		{
			if (FLAIL == *this)
				return "Flail";
			if (WAR_PICK == *this)
				return "War Pick";
			if (SHORTSWORD == *this)
				return "Shortsword";
			if (PIKE == *this)
				return "Pike";
			if (SPEAR == *this)
				return "Spear";
			if (SCIMITAR == *this)
				return "Scimitar";
			if (GREATSWORD == *this)
				return "Greatsword";
			if (BLOWGUN == *this)
				return "Blowgun";
			if (WARHAMMER == *this)
				return "Warhammer";
			if (SICKLE == *this)
				return "Sickle";
			if (SPEAR == *this)
				return "Spear";
			if (CLUB == *this)
				return "Club";
			if (LONGBOW == *this)
				return "Longbow";
			if (HEAVY_CROSSBOW == *this)
				return "Heavy Crossbow";
			if (TRIDENT == *this)
				return "Trident";
			if (HAND_CROSSBOW == *this)
				return "Hand Crossbow";
			if (MAUL == *this)
				return "Maul";
			if (RAPIER == *this)
				return "Rapier";
			if (HALBERD == *this)
				return "Halberd";
			if (DAGGER == *this)
				return "Dagger";
			if (GREATCLUB == *this)
				return "Greatclub";
			if (MACE == *this)
				return "Mace";
			if (WHIP == *this)
				return "Whip";
			if (HANDAXE == *this)
				return "Handaxe";
			if (JAVELIN == *this)
				return "Javelin";
			if (LIGHT_HAMMER == *this)
				return "Light Hammer";
			if (LIGHT_CROSSBOW == *this)
				return "Light Crossbow";
			if (DART == *this)
				return "Dart";
			if (SHORTBOW == *this)
				return "Shortbow";
			if (SLING == *this)
				return "Sling";
			if (BATTLEAXE == *this)
				return "Battleaxe";
			if (GLAIVE == *this)
				return "Glaive";
			if (MORNINGSTAR == *this)
				return "Morningstar";
			if (LONGSWORD == *this)
				return "Longsword";
			if (GREATAXE == *this)
				return "Greataxe";
			return "Quarterstaff";
		}

	std::string getDamage()
	{
		return damage;
	}

	std::pair<int, int> Damage()
	{
		if (versatile)
		{
			int roll1, roll2;
			roll1 = rand() % ((numDice * diceType) - numDice) + numDice;
			roll2 = rand() % ((numDice * (diceType + 2)) - numDice) + numDice;
			return std::make_pair(roll1, roll2);
		}
		return std::make_pair(rand() % ((numDice * diceType) - numDice) + numDice, INT_MIN);
	}
};

//Gives the proper weapon for a given weapon name
//Param: A std::string of the weapon name
//Return: The weapon associated with the given name. The function returns weapon(NULL, NULL, "", NULL, NULL, NULL) if there is no matching weapon.
weapon toWeapon(std::string name)
{
	if (name == "greataxe")
		return GREATAXE;
	if (name == "hand crossbow" || name == "hand_crossbow")
		return HAND_CROSSBOW;
	if (name == "heavy crossbow" || name == "heavy_crossbow")
		return HEAVY_CROSSBOW;
	if (name == "blowgun")
		return BLOWGUN;
	if (name == "rapier")
		return RAPIER;
	if (name == "glaive")
		return GLAIVE;
	if (name == "halberd")
		return HALBERD;
	if (name == "war pick" || name == "war_pick")
		return WAR_PICK;
	if (name == "shortsword")
		return SHORTSWORD;
	if (name == "morningstar")
		return MORNINGSTAR;
	if (name == "greatsword")
		return GREATSWORD;
	if (name == "pike")
		return PIKE;
	if (name == "warhammer")
		return WARHAMMER;
	if (name == "longsword")
		return LONGSWORD;
	if (name == "flail")
		return FLAIL;
	if (name == "scimitar")
		return SCIMITAR;
	if (name == "spear")
		return SPEAR;
	if (name == "sickle")
		return SICKLE;
	if (name == "quarterstaff")
		return QUARTERSTAFF;
	if (name == "mace")
		return MACE;
	if (name == "light crossbow" || name == "light_crossbow")
		return LIGHT_CROSSBOW;
	if (name == "dart")
		return DART;
	if (name == "whip")
		return WHIP;
	if (name == "trident")
		return TRIDENT;
	if (name == "shortbow")
		return SHORTBOW;
	if (name == "sling")
		return SLING;
	if (name == "battleaxe")
		return BATTLEAXE;
	if (name == "light hammer" || name == "light_hammer")
		return LIGHT_HAMMER;
	if (name == "javelin")
		return JAVELIN;
	if (name == "handaxe")
		return HANDAXE;
	if (name == "greatclub")
		return GREATCLUB;
	if (name == "dagger")
		return DAGGER;
	if (name == "club")
		return CLUB;
	if (name == "longbow")
		return LONGBOW;
	if (name == "maul")
		return MAUL;
	return weapon(NULL, NULL, "", NULL, NULL, NULL);
}