#pragma once
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Armors.h"
#include "Weapons.h"
#include <vector>
#include <algorithm>
#include <iostream>
#define FIGHTER "FIGHTER"
#define BATTLE_MASTER "BATTLEMASTER"
#define STRENGTH "strength"
#define DEXTERITY "dexterity"
#define CONSTITUTION "constitution"
#define INTELLIGENCE "intelligence"
#define WISDOM "wisdom"
#define CHARISMA "charisma"
#define ACROBATICS "acrobatics"
#define ANIMAL_HANDLING "animal handling"
#define ARCANA "arcana"
#define ATHLETICS "athletics"
#define DECEPTION "deception"
#define HISTORY "history"
#define INSIGHT "insight"
#define INTIMIDATION "intimidation"
#define INVESTIGATION "investigation"
#define MEDICINE "medicine"
#define NATURE "nature"
#define PERCEPTION "perception"
#define PERSUASION "persuasion"
#define RELIGION "religion"
#define SLEIGHT "sleight of hand"
#define STEALTH "stealth"
#define SURVIVAL "survival"
#define PERFORMANCE "performance"

std::ofstream fout;
std::ifstream fin;

std::string WeaponString(std::vector<weapon>);
std::vector<std::string> split(std::string);
std::string VectorString(std::vector<std::string>);
void cleanProfs(std::vector<std::string>*);

class Character
{
	protected: 
		int constitution;
		int strength;
		int dexterity;
		int intelligence;
		int wisdom;
		int charisma;
		int copper;
		int silver;
		int electrum;
		int gold;
		int platinum;
		int currentHP;
		int totalHP;
		int tempHP;
		int speed;
		int level;
		int AC;
		int proBonus = 2;
		std::string name;
		Armor armor;
		int deathFails = 0;
		int deathSuccesses = 0;
		std::vector<weapon> weapons;
		std::vector<std::string> proficiencies;
		bool longRest;
	public:
		Character()
		{
			constitution = strength = dexterity = intelligence = wisdom = charisma = copper = silver = electrum = 0;
			platinum = currentHP = totalHP = tempHP = proBonus = speed = level = AC = 0;
			name = "";
			armor = PADDED;
		}
		int getBonus(int skill) const
		{
			return floor((skill - 10) / 2);
		}
		int Acrobatics(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), ACROBATICS) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), ACROBATICS) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int AnimalHandling(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), ANIMAL_HANDLING) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), ANIMAL_HANDLING) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Arcana(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), ARCANA) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), ARCANA) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Athletics(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
						roll = rand() % 20 + 1 + getBonus(strength);
			if (std::find(proficiencies.begin(), proficiencies.end(), ATHLETICS) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(strength);
			if (std::find(proficiencies.begin(), proficiencies.end(), ATHLETICS) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Deception(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), DECEPTION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), DECEPTION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int History(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), HISTORY) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), HISTORY) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Insight(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), INSIGHT) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), INSIGHT) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Intimidation(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), INTIMIDATION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), INTIMIDATION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Investigation(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), INVESTIGATION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), INVESTIGATION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Medicine(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), MEDICINE) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), MEDICINE) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Nature(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), NATURE) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), NATURE) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Perception(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERCEPTION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERCEPTION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Performance(bool advantage = false, bool disadvantage = false)
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERFORMANCE) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERFORMANCE) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Persuasion(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERSUASION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), PERSUASION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Religion(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), RELIGION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), RELIGION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int SleightOfHand(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), SLEIGHT) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), SLEIGHT) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Stealth(bool advantage = false, bool disadvantage = false) const
		{
			if (armor.givesDisadvantage())
				disadvantage == true;
			int roll;
			roll = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), STEALTH) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), STEALTH) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Survival(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), SURVIVAL) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), SURVIVAL) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Strength(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(strength);
			if (std::find(proficiencies.begin(), proficiencies.end(), STRENGTH) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(strength);
			if (std::find(proficiencies.begin(), proficiencies.end(), STRENGTH) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Dexterity(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), DEXTERITY) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(dexterity);
			if (std::find(proficiencies.begin(), proficiencies.end(), DEXTERITY) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Constitution(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(constitution);
			if (std::find(proficiencies.begin(), proficiencies.end(), CONSTITUTION) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(constitution);
			if (std::find(proficiencies.begin(), proficiencies.end(), CONSTITUTION) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Intelligence(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), INTELLIGENCE) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(intelligence);
			if (std::find(proficiencies.begin(), proficiencies.end(), INTELLIGENCE) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Wisdom(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), WISDOM) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(wisdom);
			if (std::find(proficiencies.begin(), proficiencies.end(), WISDOM) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int Charisma(bool advantage = false, bool disadvantage = false) const
		{
			int roll;
			roll = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), CHARISMA) != proficiencies.end())
				roll += proBonus;
			if (!advantage && !disadvantage)
				return roll;
			int roll2 = rand() % 20 + 1 + getBonus(charisma);
			if (std::find(proficiencies.begin(), proficiencies.end(), CHARISMA) != proficiencies.end())
				roll2 += proBonus;
			if (!disadvantage && roll2 > roll)
				return roll2;
			return roll;
		}
		int getStrength() const
		{
			return strength;
		}
		int getAC() const
		{
			return AC;
		}	
		std::string getName()
		{
			return name;
		}
		virtual void save() const = 0
		{
			fout.open(name + ".CHAR", std::ios_base::app);
			fout << name << '\n' << strength << '\n' << wisdom << '\n' << dexterity << '\n' << constitution << '\n' << intelligence << '\n' << charisma << '\n' << level << '\n' << armor << std::endl << totalHP << std::endl << currentHP << std::endl << tempHP << std::endl << platinum << std::endl << copper << std::endl << electrum << std::endl << gold << std::endl << silver << std::endl << WeaponString(weapons) << std::endl << VectorString(proficiencies);
			fout.close();
		}
		std::vector<weapon> getWeapons()
		{
			return weapons;
		}
		int getGold() const
		{
			return gold;
		}
		Armor getArmor() const
		{
			return armor;
		}
		virtual void attack(weapon* blade, bool advantage = false, bool disadvantage = false, int roll1 = INT_MIN) const = 0
		{
			int roll = roll1;
			if (blade->getFinesse() && roll == INT_MIN)
				{
					if (getBonus(strength) > getBonus(dexterity))
						roll = Strength(advantage, disadvantage);
					else
						roll = Dexterity(advantage, disadvantage);
				}
			if (blade->getRange() == 0 && roll == INT_MIN)
				roll = Strength(advantage, disadvantage);
			else if (roll == INT_MIN)
				roll = Dexterity(advantage, disadvantage);
			std::cout << name << " rolls a " << roll << " against the enemy's armor class! If the attack beats the enemy's armor class, then " + name + " does ";
			std::pair<int, int> dam = blade->Damage();
			std::cout << dam.first << ' ' << blade->getDamage() + " damage.";
			if (dam.second != INT_MIN)
				std::cout << " Unless " + name + " uses both hands. Then " + name + " deals " << dam.second << blade->getDamage() + " damage.";
		}
};

class Fighter : public Character
{
	protected:
		int totalHitDice;
		int remHitDice;
		std::string style;
		bool secondWind;
	public:
		Fighter(std::string Name, int str, int wis, int dex, int con, int Int, int Char, int Level, Armor Armor, std::vector<weapon> weap, std::vector<std::string> profs, std::string fightStyle, int totalHealth=INT_MIN, int currentHealth=INT_MIN, int tempHealth = 0, int plat=0, int cop=0, int elec=0, int Gold=30, int silv = 0, bool secWind = true)
		{
			style = fightStyle;
			secondWind = secWind;
			proficiencies = profs;
			name = Name;
			strength = str;
			wisdom = wis;
			dexterity = dex;
			constitution = con;
			intelligence = Int;
			charisma = Char;
			remHitDice = totalHitDice = level = Level;
			armor = Armor;
			
			int sum = 0;
			if (totalHealth == INT_MIN)
			{
				for (int i = 0; i < level; i++)
					sum += rand() % 10 + 1 + getBonus(constitution);
				totalHP = sum;
			}
			else
				totalHP = totalHealth;
			if (currentHealth == INT_MIN)
				currentHP = totalHP;
			else
				currentHP = currentHealth;
			tempHP = tempHealth;
			speed = 30;
			copper = cop;
			silver = silv;
			electrum = elec;
			platinum = plat;
			gold = Gold;
			if (armor.getWeight() == "light")
				AC = armor.getAC() + getBonus(dexterity);
			else if (armor.getWeight() == "medium")
			{
				if (getBonus(dexterity) < 2)
					AC = armor.getAC() + getBonus(dexterity);
				else
					AC = armor.getAC() + 2;
			}
			else
				AC = armor.getAC();
			if (style == "defense")
				AC++;
			if (level >= 5)
				proBonus = 3;
			if (level >= 9)
				proBonus = 4;
			if (level >= 13)
				proBonus = 5;
			if (level >= 17)
				proBonus = 6;
			weapons = weap;
		}
		void save() const
		{
			fout.open(name + ".CHAR");
			fout << "FIGHTER" << std::endl;
			fout.close();
			Character::save();
			fout.open(name + ".CHAR", std::ios_base::app);
			fout << std::endl << style;
			fout.close();
		}
		Fighter()
		{
			totalHitDice = remHitDice = 0;
			constitution = strength = dexterity = intelligence = wisdom = charisma = copper = silver = electrum = 0;
			platinum = currentHP = totalHP = tempHP = proBonus = speed = level = AC = 0;
			name = "";
			armor = PADDED;
		}
		void attack(weapon* blade, bool advantage = false, bool disadvantage = false, int roll1 = INT_MIN) const
		{
			return;
		}
};

class BattleMaster : public Fighter
{
private:
	int Save;
	int totalSuperDice;
	int remSuperDice;
	int superDiceType;
	std::vector<void*> maneuvers;
public:
	BattleMaster(std::string Name, int str, int wis, int dex, int con, int Int, int Char, int Level, Armor Armor, std::vector<weapon> weap, std::vector<std::string> profs, std::string fightStyle, std::vector<std::string> mans, int superDice, int totalHealth = INT_MIN, int currentHealth = INT_MIN, int tempHealth = 0, int plat = 0, int cop = 0, int elec = 0, int Gold = 30, int silv = 0, bool secWind = true)
	{
		style = fightStyle;
		secondWind = secWind;
		proficiencies = profs;
		name = Name;
		strength = str;
		wisdom = wis;
		dexterity = dex;
		constitution = con;
		intelligence = Int;
		charisma = Char;
		remHitDice = totalHitDice = level = Level;
		armor = Armor;

		int sum = 0;
		if (totalHealth == INT_MIN)
		{
			for (int i = 0; i < level; i++)
				sum += rand() % 10 + 1 + getBonus(constitution);
			totalHP = sum;
		}
		else

			totalHP = totalHealth;
		if (currentHealth == INT_MIN)
			currentHP = totalHP;
		else
			currentHP = currentHealth;
		tempHP = tempHealth;
		speed = 30;
		copper = cop;
		silver = silv;
		electrum = elec;
		platinum = plat;
		gold = Gold;
		if (armor.getWeight() == "light")
			AC = armor.getAC() + getBonus(dexterity);
		else if (armor.getWeight() == "medium")
		{
			if (getBonus(dexterity) < 2)
				AC = armor.getAC() + getBonus(dexterity);
			else
				AC = armor.getAC() + 2;
		}
		else
			AC = armor.getAC();
		if (style == "defense")
			AC++;
		if (level >= 5)
			proBonus = 3;
		if (level >= 9)
			proBonus = 4;
		if (level >= 13)
			proBonus = 5;
		if (level >= 17)
			proBonus = 6;
		weapons = weap;
		if (getBonus(strength) > getBonus(dexterity))
			Save = 8 + proBonus + getBonus(strength);
		else
			Save = 8 + proBonus + getBonus(dexterity);
		if (level >= 18)
			superDiceType = 12;
		else if (level >= 10)
			superDiceType = 10;
		else
			superDiceType = 8;
		if (level >= 15)
			totalSuperDice = 6;
		else if (level >= 7)
			totalSuperDice = 5;
		else
			totalSuperDice = 4;
		remSuperDice = superDice;
		if (remSuperDice > totalSuperDice)
			remSuperDice = totalSuperDice;
	}
	void attack(weapon* blade, bool advantage = false, bool disadvantage = false, int roll1 = INT_MIN) const
	{
		if (getBonus(strength) > getBonus(dexterity))
		{
			Character::attack(blade, advantage, disadvantage, Strength());
			return;
		}
		Character::attack(blade, advantage, disadvantage, Dexterity());
	}
	void save() const
	{
		Fighter::save();
		fout.open(name + ".CHAR", std::ios_base::app);
		fout << BATTLE_MASTER << "\ndisarm" << std::endl << 5;
		fout.close();
	}
};

Character* loadIn(std::string file)
{
	fin.open(file);
	std::string armor, name, Class;
	getline(fin, Class);
	if (Class == FIGHTER)
	{
		getline(fin, name);
		int str, wis, dex, con, Int, Char, Level, totalHP, currentHP, tempHP, plat, cop, elec, Gold, silv;
		fin >> str >> wis >> dex >> con >> Int >> Char >> Level;
		fin.ignore();
		std::getline(fin, armor);
		Armor armore = whichArmor(armor);
		fin >> totalHP >> currentHP >> tempHP >> plat >> cop >> elec >> Gold >> silv;
		std::vector<weapon> wea;
		std::string currWeap;
		fin.ignore();
		getline(fin, currWeap);
		std::vector<std::string> weaps = split(currWeap);
		for (int i = 0; i < weaps.size(); i++)
			wea.push_back(toWeapon(weaps.at(i)));
		getline(fin, currWeap);
		std::vector<std::string> profs = split(currWeap);
		cleanProfs(&profs);
		getline(std::cin, currWeap);
		if (Level >= 3)
		{
			std::string subclass, maneuver;
			getline(std::cin, subclass);
			if (subclass == BATTLE_MASTER)
			{
				getline(std::cin, maneuver);
				std::vector<std::string> mans = split(maneuver);
				int superDice;
				std::cin >> superDice;
				return new BattleMaster(name, str, wis, dex, con, Int, Char, Level, armore, wea, profs, currWeap, mans, superDice, totalHP, currentHP, tempHP, plat, cop, elec, Gold, silv);
			}
		}
		return new Fighter(name, str, wis, dex, con, Int, Char, Level, armore, wea, profs, currWeap, totalHP, currentHP, tempHP, plat, cop, elec, Gold, silv);
	}
	fin.close();
}

std::string WeaponString(std::vector<weapon> stuff)
{
	std::string val = "";
	for (int i = 0; i < stuff.size(); i++)
	{
		if (stuff.at(i).toString().find(' ') != -1)
			val += stuff[i].toString().substr(0, stuff[i].toString().find(' ')) + '_' + stuff[i].toString().substr(stuff[i].toString().find(' ') + 1);
		else
			val += stuff[i].toString() + ' ';
	}
	return val;
}

std::vector<std::string> split(std::string x)
{
	int index = 0;
	std::vector<std::string> val;
	while (x.find(' ') != -1)
	{
		val.push_back(x.substr(index, x.find(' ') - index));
		index = x.find(' ') + 1;
		x = x.substr(index);
	}
	return val;
}

std::string replaceChars(std::string str, char original, char New)
{
	std::string x = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != original)
			x += str[i];
		else
			x += New;
	}
	return x;
}

std::string VectorString(std::vector<std::string> strVec)
{
	std::string a = "";
	for (int i = 0; i < strVec.size(); i++)
		a += replaceChars(strVec[i], ' ', '_') + ' ';
	return a;
}

void cleanProfs(std::vector<std::string>* a)
{
	if (a->size() == 0)
		return;
	for (int i = 0; i < a->size(); i++)
	{
		while (a->at(i).find(' ') != -1)
			a->at(i) = replaceChars(a->at(i), '_', ' ');
	}
}