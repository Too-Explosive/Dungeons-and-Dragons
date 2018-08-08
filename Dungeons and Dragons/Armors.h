#pragma once
#include <string>
#define PADDED Armor("light", 5, 11, true, 8)
#define LEATHER Armor("light", 10, 11, false, 10)
#define STUDDED Armor("light", 45, 12, false, 13)
#define HIDE Armor("medium", 10, 12, false, 12)
#define CHAIN_SHIRT Armor("medium", 50, 13, false, 20)
#define SCALE Armor("medium", 50, 14, true, 45)
#define BREASTPLATE Armor("medium", 400, 14, false, 20)
#define HALF_PLATE Armor("medium", 750, 15, true, 40)
#define RING_MAIL Armor("heavy", 30, 14, true, 40)
#define CHAIN_MAIL Armor("heavy", 75, 16, true, 55, 13)
#define SPLINT Armor("heavy", 200, 17, true, 60, 15)
#define PLATE Armor("heavy", 1500, 18, true, 65, 15)
#define NONE Armor("", NULL, NULL, NULL, NULL, NULL)

class Armor
{
	private:
		std::string weightClass;
		int cost;
		int AC;
		bool disadvantage;
		int pounds;
		int strength;
	public:
		int getPounds() const
		{
			return pounds;
		}
		int getAC() const
		{
			return AC;
		}
		bool givesDisadvantage() const
		{
			return disadvantage;
		}
		int getStrength() const
		{
			return strength;
		}
		int getCost() const
		{
			return cost;
		}
		Armor(std::string weight, int price, int Class, bool Disadvantage, int pound, int str = INT_MIN)
		{
			weightClass = weight;
			cost = price;
			AC = Class;
			pounds = pound;
			disadvantage = Disadvantage;
			strength = str;
		}
		std::string getWeight() const
		{
			return weightClass;
		}
		Armor()
		{
			weightClass = "";
			cost = 0;
			AC = 0;
			disadvantage = false;
			pounds = 0;
			strength = INT_MIN;
		}
		bool operator==(const Armor &armor2) const
		{
			if (this->AC != armor2.getAC() || this->weightClass != armor2.getWeight() || this->cost != armor2.getCost() || this->disadvantage != armor2.givesDisadvantage() || this->pounds != armor2.getPounds() || this->strength != armor2.getStrength())
				return false;
			return true;
		}
		bool operator !=(const Armor &armor) const
		{
			return !(*this == armor);
		}
	    friend std::ostream &operator<< (std::ostream &output, const Armor &armor)
		{
			if (armor == Armor("light", 5, 11, true, 8))
				output << "Padded";
			else if (armor == Armor("light", 10, 11, false, 10))
				output << "Leather";
			else if (armor == Armor("light", 45, 12, false, 13))
				output << "Studded Leather";
			else if (armor == Armor("medium", 10, 12, false, 12))
				output << "Hide";
			else if (armor == Armor("medium", 50, 13, false, 20))
				output << "Chain Shirt";
			else if (armor == Armor("medium", 50, 14, true, 45))
				output << "Scale Mail";
			else if (armor == Armor("medium", 400, 14, false, 20))
				output << "Breastplate";
			else if (armor == Armor("medium", 750, 15, true, 40))
				output << "Half Plate";
			else if (armor == Armor("heavy", 30, 14, true, 40))
				output << "Ring Mail";
			else if (armor == Armor("heavy", 75, 16, true, 55, 13))
				output << "Chain Mail";
			else if (armor == Armor("heavy", 200, 17, true, 60, 15))
				output << "Splint";
			else
				output << "Plate";
			return output;
		}
};

Armor whichArmor(std::string name) 
{
	if (name == "padded")
		return PADDED;
	if (name == "leather")
		return LEATHER;
	if (name == "studded eather")
		return STUDDED;
	if (name == "hide")
		return HIDE;
	if (name == "chain shirt")
		return CHAIN_SHIRT;
	if (name == "scale mail")
		return SCALE;
	if (name == "breastplate")
		return BREASTPLATE;
	if (name == "half plate")
		return HALF_PLATE;
	if (name == "splint")
		return SPLINT;
	if (name == "ring mail")
		return RING_MAIL;
	if (name == "chain mail")
		return CHAIN_MAIL;
	if (name == "plate")
		return PLATE;
	return NONE;
}