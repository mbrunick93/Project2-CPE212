
#include "mage.hpp"

/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Mage starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Staff"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Mage inventory
 *  Assign a value of 10 for the base Mage characteristic
 */
  Mage::Mage(string characterName, Race characterRace) : Character (characterName, characterRace)
{
    SetJob("Mage");
    SetHealth(50);
    Weapon starter;
    starter.name = "Simple Staff";
    starter.cost = 100;
    starter.damage = 5;
    Item i;
    i.name = starter.name;
    i.value = starter.cost;
    i.type = WEAPON;
    SetWeapon(starter);
    AddToInventory (i);
    intelligence = 10;
}
/**
 * Public method of Mage that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
  void Mage::Attack(Character * target){
     int damage = GetWeapon().damage + (intelligence/2);
     std::cout<<GetName()<<" attacks "<<target->GetName()<<" with "<<GetWeapon().name<<" for "<<damage<<" points"<<std::endl;
     target->TakeDamage(damage);
 }
/**
 * Public method of Mage that sends a Fireball at an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with a Fireball for <damage> points
 */
void Mage::Fireball(Character * target){
int damage = 10 + GetWeapon().damage + (intelligence/2);
std::cout<<GetName()<<" attacks "<<target->GetName()<<" with a Fireball for "<<damage<<" points"<<std::endl;
target->TakeDamage(damage);

}
/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
   void Mage::Status(){
     std::cout<<this->GetJob()<<" Status"<<std::endl;
     std::cout<<"Name: "<<this->GetName()<<std::endl;
     std::cout<<"Race: "<<RaceStrings[GetRace()] <<std::endl;
     std::cout<<"Level: "<<this->GetLevel()<<std::endl;
     std::cout<<"Exp: "<<this->GetExp()<<std::endl;
     std::cout<<"Health: "<<this->GetHealth()<<std::endl;
     std::cout<<"Intelligence: "<<intelligence<<std::endl;
 }