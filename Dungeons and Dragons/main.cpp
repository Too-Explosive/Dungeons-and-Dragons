#include <algorithm>
#include <iostream>
#include "Character.h"
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <fstream>

namespace fs = std::experimental::filesystem;

//Naming of functions
std::vector<std::string> getCharacterSaves();
void printCharacterSaves();
void printStartCommands();
std::string lower(std::string);
Character* createNewCharacter();
std::string upper(std::string);
void listArmors();
void listWeapons();
void printWeaponVector(std::vector<weapon>, std::string sep);
void listClasses();
bool isValidProficiency(std::string);
void listProficiencies();
void printProficiencyVector(std::vector<std::string>, std::string);

int main()
{
	std::vector<void(* )()> funcs;
	funcs.push_back(listClasses);
	funcs.at(0);
	char wat;
	std::cin >> wat;
	srand(time(0));
	std::string a;
	Character* player;
	bool chosen = false;
	std::cout << "Welcome to the Dungeons and Dragons unofficial assistant!\n";
	//Introduction and choosing of player
	while (!chosen)
	{
		std::cout << "To begin, enter a command. Enter \"?\" for a list of currently available commands: ";
		getline(std::cin, a);
		if (a == "?")
			printStartCommands();
		else if (lower(a) == "list")
			printCharacterSaves();
		else if (lower(a).find("load ") == 0)
		{
			if (a.length() > 5 && fs::exists(a.substr(5) + ".CHAR"))
			{
				player = loadIn(a.substr(5) + ".CHAR");
				chosen = true;
			}
			else
				std::cout << "\nThat is an invalid character name. Make sure the name is spelled correctly. Enter \"list\" to see the names of saved characters or enter \"create\" to create a new character.";
		}
		else if (lower(a) == "create")
		{
			player = createNewCharacter();
			chosen = true;
			player->save();
		}
		else
			std::cout << "Invalid Input.\n";
	}
	player->save();
	std::cin >> a;
	return 1;
}
//Looks through files for any previously saved characters
//Return: a vector of strings containing the names of the saved characters
std::vector<std::string> getCharacterSaves()
{
	std::string path("C:\\Users\\profc\\Documents\\Visual Studio 2017\\Projects\\Dungeons and Dragons\\Dungeons and Dragons\\");
	std::string ext(".CHAR");
	std::string name;
	std::vector<std::string> saves;
	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (p.path().extension() == ext)
		{
			name = p.path().filename().string();
			name.erase(name.find_first_of('.'), std::string::npos);
			saves.push_back(name);
		}
	}
	return saves;
}

//Prints the names of saved characters
void printCharacterSaves()
{
	std::cout << std::endl;
	for (int i = 0; i < getCharacterSaves().size(); i++)
		std::cout << getCharacterSaves().at(i) << std::endl;
}

//Prints the commands available at the begining of program execution.
void printStartCommands()
{
	std::cout << "\nlist\tOutputs a list of saved characters.\ncreate\tCreates a new character\nload\tLoads a saved character. The characters name must come after the command, separated with a single space.\n?\tOutputs a list of commands currently possible.\n\n";
}

//Turns every character of a string to its lowercase version
//Param: The string to be changed
//Return: A string with every character of the original in its lowercase form
std::string lower(std::string a)
{
	std::string b = "";
	for (int i = 0; i < a.length(); i++)
		b += tolower(a.at(i));
	return b;
}

//Creates a copy of a string with every character in uppercase
//Param: The string to be changed
//Return: A string with every character of the original in its uppercase form
std::string upper(std::string a)
{
	std::string b = "";
	for (int i = 0; i < a.length(); i++)
		b += toupper(a.at(i));
	return b;
}


//Creates a new playable character from user input
//Return: A pointer to a character created from user input
Character* createNewCharacter()
{
	std::string name, Class, armorName, currProf, subClass;
	bool choosing = true, invalidArmor = true, choosingWeapon = true, addingProfs = true;
	while (choosing)
	{
		std::cout << "Enter \"?\" for a list of available classes. Enter the character's class: ";
		std::cin >> Class;
		if (upper(Class) == "FIGHTER")
		{
			std::string style;
			std::cout << "Enter the character's name: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, name);
			int str, wis, dex, con, Int, Char, Level, totalHealth, currentHealth, tempHealth, plat, elec, gold, silv, cop;
			std::vector<weapon> weapons;
			std::vector<std::string> profs;
			Armor armor;
			std::cout << "Enter " + name + "'s strength: ";
			while (!(std::cin >> str))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s wisdom: ";
			while (!(std::cin >> wis))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s dexterity: ";
			while (!(std::cin >> dex))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s constitution: ";
			while (!(std::cin >> con))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s intelligence: ";
			while (!(std::cin >> Int))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s charisma: ";
			while (!(std::cin >> Char))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s level: ";
			while (!(std::cin >> Level))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s total hit points: ";
			while (!(std::cin >> totalHealth))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s current hit points: ";
			while (!(std::cin >> currentHealth))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "Enter " + name + "'s temporary hit points: ";
			while (!(std::cin >> tempHealth))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "How much platinum does " + name + " have? ";
			while (!(std::cin >> plat))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "How much copper does " + name + " have? ";
			while (!(std::cin >> cop))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "How much electrum does " + name + " have? ";
			while (!(std::cin >> elec))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "How much gold does " + name + " have? ";
			while (!(std::cin >> gold))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cout << "How much silver does " + name + " have? ";
			while (!(std::cin >> silv))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			while (invalidArmor)
			{

				std::cout << std::endl << "Enter \"?\" for a list of available armors. What armor does " + name + " wear? ";
				getline(std::cin, armorName);
				if (whichArmor(lower(armorName)) != NONE)
				{
					armor = whichArmor(lower(armorName));
					break;
				}
				else if (armorName == "?")
					listArmors();
				else
					std::cout << "That is an invalid armor name.";
			}
			while (choosingWeapon)
			{
				std::string weaponName;
				std::cout << "Enter " + name + "'s weapons. Press the Enter key after each weapon. Enter \"?\" for a list of available weapons. Enter \"DONE\" once all weapons have been entered. ";
				getline(std::cin, weaponName);
				if (weaponName == "?")
					listWeapons();
				else if (weaponName == "DONE")
					break;
				else if (toWeapon(lower(weaponName)) == weapon(NULL, NULL, "", NULL, NULL, NULL))
					std::cout << "That is an invalid weapon.\n";
				else
					weapons.push_back(toWeapon(lower(weaponName)));
			}
			while (addingProfs)
			{
				std::cout << "Enter " + name + "'s proficiencies. Enter \"?\" for a list of valid proficiencies. Press the \"Enter\" key after each skill: Enter \"DONE\" to finish: ";
				getline(std::cin, currProf);
				if (currProf == "?")
					listProficiencies();
				else if (isValidProficiency(lower(currProf)))
					profs.push_back(lower(currProf));
				else if (currProf == "DONE")
					break;
				else
					std::cout << "That is not a valid skill.\n";
			}
			while (invalidArmor)
			{
				std::cout << "What is " + name + "'s fighting style? Enter \"?\" for a list of valid fighting styles. ";
				getline(std::cin, style);
				if (style == "?")
					std::cout << "Defense     Two-Weapon Fighting     Protection     Great Weapon Fighting     Dueling     Archery\n";
				else if (lower(style) != "defense" && lower(style) != "two-weapon fighting" && lower(style) != "archery" && lower(style) != "dueling" && lower(style) != "great weapon fighting" && lower(style) != "protection")
					std::cout << "Invalid fighting style.\n";
				else
					break;
			}
			if (Level >= 3)
			{
				while (invalidArmor)
				{
					std::cout << "Enter " + name + "'s subclass. Enter \"?\" for a list of available subclasses. ";
					getline(std::cin, subClass);
					if (subClass == "?")
						std::cout << "Battle Master     Eldritch Knight     Champion\n";
					else if (lower(subClass) == "battle master")
					{
						bool cont = true;
						while (cont)
						{
							std::cout << "\nName:\t\t" + name + "\nClass:\t\t" + (char)toupper(Class[0]) + Class.substr(1) + "\nTotal HP:\t" << totalHealth << "\nCurrent HP:\t" << currentHealth << "\nTemporary HP:\t" << tempHealth << "\nDexterity:\t" << dex << "\nConstitution:\t" << con << "\nStrength:\t" << str << "\nWisdom:\t\t" << wis << "\nIntelligence:\t" << Int << "\nCharisma:\t" << Char << "\nArmor:\t\t" << armor << "\nElectrum:\t" << elec << "\nGold:\t\t" << gold << "\nSilver:\t\t" << silv << "\nCopper:\t\t" << cop << "\nPlatinum:\t" << plat << "\nWeapons:\t";
							printWeaponVector(weapons, ", ");
							std::cout << "\nProficiencies:\t";
							printProficiencyVector(profs, ", ");
							std::cout << std::endl << "Fighting Style:\t";
							std::cout << (char)toupper(style.at(0)) << style.substr(1) << "\nSubclass:\tBattle Master";
							return new BattleMaster(name, str, wis, dex, con, Int, Char, Level, armor, weapons, profs, style, std::vector<std::string>(0), 5, totalHealth, currentHealth, tempHealth, plat, cop, elec, gold, silv);
						}
					}
				}
			}
			std::cout << "\nName:\t\t" + name + "\nClass:\t\t" + (char)toupper(Class[0]) + Class.substr(1) + "\nTotal HP:\t" << totalHealth << "\nCurrent HP:\t" << currentHealth << "\nTemporary HP:\t" << tempHealth << "\nDexterity:\t" << dex << "\nConstitution:\t" << con << "\nStrength:\t" << str << "\nWisdom:\t\t" << wis << "\nIntelligence:\t" << Int << "\nCharisma:\t" << Char << "\nArmor:\t\t" << armor << "\nElectrum:\t" << elec << "\nGold:\t\t" << gold << "\nSilver:\t\t" << silv << "\nCopper:\t\t" << cop << "\nPlatinum:\t" << plat << "\nWeapons:\t";
			printWeaponVector(weapons, ", ");
			std::cout << "\nProficiencies:\t";
			printProficiencyVector(profs, ", ");
			std::cout << std::endl << "Fighting Style:\t";
			std::cout << (char)toupper(style.at(0)) << style.substr(1);
			bool Continue = true;
			while (Continue)
			{
				std::cout << "\nAre " + name + "'s statistics and equipment correct? Enter \"YES\" or \"NO\": ";
				std::string okay;
				getline(std::cin, okay);
				if (upper(okay) == "YES")
					return new Fighter(name, str, wis, dex, con, Int, Char, Level, armor, weapons, profs, style, totalHealth, currentHealth, tempHealth, plat, cop, elec, gold, silv);
				else if (upper(okay) != "NO")
					std::cout << "\nInvalid input.";
				else
					Continue = false;

			}
		}
		else if (Class == "?")
			listClasses();
		else
			std::cout << "Invalid class." << std::endl;
	}
}

//Lists the valid armors to the user
void listArmors()
{
	std::cout << PADDED << "     " << LEATHER << "     " << STUDDED << "     " << HIDE << "     " << CHAIN_SHIRT << "     " << SCALE << "     " << BREASTPLATE << "     " << HALF_PLATE << "     " << RING_MAIL << "     " << CHAIN_MAIL << "     " << SPLINT << "     " << PLATE << std::endl;
}

//Lists the valid weapons to the user
void listWeapons()
{
	std::cout << LONGBOW.toString() << "     " << HEAVY_CROSSBOW.toString() << "     " << HAND_CROSSBOW.toString() << "     " << BLOWGUN.toString() << "     " << WHIP.toString() << "     " << WARHAMMER.toString() << "     " << WAR_PICK.toString() << "     " << TRIDENT.toString() << "     " << SHORTSWORD.toString() << "     " << RAPIER.toString() << "     " << PIKE.toString() << "     " << MORNINGSTAR.toString() << "     " << MAUL.toString() << "     " << LONGSWORD.toString() << "     " << HALBERD.toString() << "     \n" << GREATSWORD.toString() << "     " << GREATAXE.toString() << "     " << GLAIVE.toString() << "     " << FLAIL.toString() << "     " << BATTLEAXE.toString() << "     " << SCIMITAR.toString() << "     " << CLUB.toString() << "     " << DAGGER.toString() << "     " << GREATCLUB.toString() << "     " << HANDAXE.toString() << "     " << JAVELIN.toString() << "     " << LIGHT_HAMMER.toString() << "     " << MACE.toString() << "     " << QUARTERSTAFF.toString() << "     " << SICKLE.toString() << "     " << SPEAR.toString() << '\n' << LIGHT_CROSSBOW.toString() << "     " << DART.toString() << "     " << SHORTBOW.toString() << "     " << SLING.toString() << std::endl;
}

//Lists the elements of a vector of type weapon, with a separator between each element.
//Param: The vector of weapons to be printed
//Param: The separator to go between each element
void printWeaponVector(std::vector<weapon> vec, std::string sep)
{
	if (vec.size() == 0)
		return;
	for (int i = 0; i < vec.size() - 1; i++)
		std::cout << vec.at(i).toString() + sep;
	std::cout << vec.at(vec.size() - 1).toString();
}

//Lists the proficiency vector to the user
void printProficiencyVector(std::vector<std::string> prof, std::string sep)
{
	if (prof.size() == 0)
		return;
	for (int i = 0; i < prof.size() - 1; i++)
		std::cout << std::string(1, toupper(prof[i][0])) + prof[i].substr(1) + sep;
	std::cout << std::string(1,toupper(prof[prof.size() - 1][0])) + prof[prof.size() - 1].substr(1);
}

//Lists the currently available classes to the user
void listClasses()
{
	std::cout << "Fighter\n";
}

//Tells if a std::string is a valid skill
//Param: The std::string to be tested
//Return: A boolean telling if the value is valid or not
bool isValidProficiency(std::string input)
{
	if (input == STRENGTH || input == DEXTERITY || input == CONSTITUTION || input == INTELLIGENCE || input == WISDOM || input == CHARISMA || input == ACROBATICS || input == ANIMAL_HANDLING || input == ARCANA || input == ATHLETICS || input == DECEPTION || input == HISTORY || input == INSIGHT || input == INTIMIDATION || input == INVESTIGATION || input == MEDICINE || input == NATURE || input == PERCEPTION || input == PERFORMANCE || input == PERSUASION || input == RELIGION || input == SLEIGHT || input == STEALTH || input == SURVIVAL)
		return true;
	return false;
}

//Lists the available proficiencies
void listProficiencies()
{
	std::cout << "Strength     Dexterity     Constitution     Intelligence     Wisdom     Charisma     Acrobatics     Animal Handling     Arcana     Deception     History     Insight     Intimidation     Investigation     Medicine     Nature     Perception     Performance     Persuasion     Religion     Sleight of Hand     Stealth     Survival\n";
}