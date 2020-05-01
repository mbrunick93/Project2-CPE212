
#include "warrior.hpp"
/**
 * Warrior Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Warrior starts with 150 health
 *  Assign the starter weapon for the Warrior
 *      Weapon
 *         name : "Starter Longsword"
 *         cost : 100
 *         damage : 10
 *  Add the weapon to the Warriors inventory
 *  Assign a value of 10 for the base Warrior characteristic
 */
Warrior::Warrior(string characterName, Race characterRace) : Character (characterName, characterRace)
{
    SetJob("Warrior");
    SetHealth(150);
    Weapon starter;
    starter.name = "Starter Longsword";
    starter.cost = 100;
    starter.damage = 10;
    Item i;
    i.name = starter.name;
    i.value = starter.cost;
    i.type = WEAPON;
    SetWeapon(starter);
    AddToInventory (i);
    strength = 10;
}
/**
 * Public method of Warrior that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Warrior is calculated by the weapon damage + half the strength value
 *  2. The enemy Character must take the damage dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
 void Warrior::Attack(Character * target){
     int damage = GetWeapon().damage + (strength/2);
     std::cout<<GetName()<<" attacks "<<target->GetName()<<" with "<<GetWeapon().name<<" for "<<damage<<" points"<<std::endl;
     target->TakeDamage(damage);

 }
/**
 * Public method of Warrior that deals a Power Attack to a target Character
 * @param target Pointer to the Character to be attacked
 * @attention Follow these instructions:
 *  1. The damage for a Power Attack is calculated by the health / 100 * (weapon damage + half the strength value)
 *  2. The target Character must take damage the amount dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Power Attacks <Target Name> for <damage amount> points
 */
 void Warrior::PowerAttack(Character * target){
     int damage = (GetHealth() / 100) * (GetWeapon().damage + (strength/2));
     std::cout<<GetName()<<" attacks "<<target->GetName()<<" with a Power Attack for "<<damage<<" points"<<std::endl;
    target->TakeDamage(damage);
    
 }
/**
 * Public method Status that prints out the Status of the Warrior
 * @attention You MUST print out the local Warrior variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
 void Warrior::Status(){
     std::cout<<this->GetJob()<<" Status"<<std::endl;
     std::cout<<"Name: "<<this->GetName()<<std::endl;
     std::cout<<"Race: "<<RaceStrings[GetRace()] <<std::endl;
     std::cout<<"Level: "<<this->GetLevel()<<std::endl;
     std::cout<<"Exp: "<<this->GetExp()<<std::endl;
     std::cout<<"Health: "<<this->GetHealth()<<std::endl;
     std::cout<<"Strength: "<<strength<<std::endl;
 }