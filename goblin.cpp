/**
 * goblin.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "goblin.hpp"

/**
 * Goblin Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Goblin starts with 30 health
 *  Assign the starter weapon for the Goblin
 *      Weapon
 *         name : "Pointy Stick"
 *         cost : 1
 *         damage : 3
 *  Add the weapon to the Goblins inventory
 *  Assign a value of 2 for the base Goblin characteristic
 */

 Goblin::Goblin(string characterName, Race characterRace) : Character (characterName, characterRace)
{   attack = 2;
    SetJob("Goblin");
    SetHealth(30);
    Weapon starter;
    starter.name = "Pointy Stick";
    starter.cost = 1;
    starter.damage = 3;
    Item i;
    i.name = starter.name;
    i.value = starter.cost;
    i.type = WEAPON;
    SetWeapon(starter);
    AddToInventory (i);
    
}
/**
 * Attack Function
 * Public method of Goblin that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Goblin is calculated by the weapon damage + half the attack value
 *  2. The enemy Character must take the damage dealt by the Goblin
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
 void Goblin::Attack(Character * target){
     
     int damage = GetWeapon().damage + (attack/2);
     std::cout<<GetName()<<" attacks "<<target->GetName()<<" with "<<GetWeapon().name<<" for "<<damage<<" points"<<std::endl;
     target->TakeDamage(damage);
 }
/**
 * Sneak Attack Function
 * Public method of Goblin that Sneak Attacks a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The Sneak Attack damage for a Goblin is calculated by the base damage value 20 + half the attack value plus weapon damage
 *  2. The target Character must take damage the amount dealt by the Goblin
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Sneak Attacks <Target Name> for <damage amount> points
 */
 void Goblin::SneakAttack(Character * target){    
int damage = 20 + GetWeapon().damage + (attack/2);
std::cout<<GetName()<<" Sneak Attacks "<<target->GetName()<<" for "<<damage<<" points "<<std::endl;
target->TakeDamage(damage);

 }
/**
 * Status Function
 * Public method Status that prints out the Status of the Goblin
 * @attention You MUST print out the local Goblin variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
 
  void Goblin::Status(){
     std::cout<<this->GetJob()<<" Status"<<std::endl;
     std::cout<<"Name: "<<this->GetName()<<std::endl;
     std::cout<<"Race: "<<RaceStrings[GetRace()] <<std::endl;
     std::cout<<"Level: "<<this->GetLevel()<<std::endl;
     std::cout<<"Exp: "<<this->GetExp()<<std::endl;
     std::cout<<"Health: "<<this->GetHealth()<<std::endl;
     std::cout<<"Attack: "<<attack<<std::endl;
 }