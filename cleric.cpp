
#include "cleric.hpp"

/**
 * Cleric Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Cleric starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Wand"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Clerics inventory
 *  Assign a value of 10 for the base Cleric characteristic
 */
Cleric::Cleric(string characterName, Race characterRace) : Character (characterName, characterRace)
{
  SetJob("Cleric");
    willpower = 10;
    SetHealth(50);
    Weapon starter;
    starter.name = "Simple Wand";
    starter.cost = 100;
    starter.damage = 5;
    Item i;
    i.name = starter.name;
    i.value = starter.cost;
    i.type = WEAPON;
    SetWeapon(starter);
    AddToInventory (i);
    
}
/**
 * Status Function
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
 void Cleric::Status(){
     std::cout<<this->GetJob()<<" Status"<<std::endl;
     std::cout<<"Name: "<<this->GetName()<<std::endl;
     std::cout<<"Race: "<<RaceStrings[GetRace()] <<std::endl;
     std::cout<<"Level: "<<this->GetLevel()<<std::endl;
     std::cout<<"Exp: "<<this->GetExp()<<std::endl;
     std::cout<<"Health: "<<this->GetHealth()<<std::endl;
     std::cout<<"Willpower: "<<willpower<<std::endl;
 }
/** 
 * Attack Function
 * Public method of Cleric that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Cleric is calculated by the weapon damage + half the willpower value
 *  2. The enemy Character must take the damage dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
 void Cleric::Attack(Character * target){
     int damage = GetWeapon().damage + (willpower/2);
     std::cout<<GetName()<<" attacks "<<target->GetName()<<" with "<<GetWeapon().name<<" for "<<damage<<" points"<<std::endl;
     target->TakeDamage(damage);
 }
/** 
 * Heal Function
 * Public method of Cleric that heals a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The heal amount for a Cleric is calculated by the base heal value 10 + half the willpower value
 *  2. The target Character must heal the amount dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> heals <Target Name> for <heal amount> points
 */
 void Cleric::Heal(Character * target){
     int heal = 10 + (willpower/2);
     std::cout<<GetName()<<" heals "<<target->GetName()<<" for "<<heal<<" points"<<std::endl;
     target->SetHealth(heal);
   
 }