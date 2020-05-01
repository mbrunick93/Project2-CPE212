#include "inventory.hpp"

/**
 * Inventory Constructor
 * Add the following item to the inventory
 * Item:
 *  name : "Basic Health Potion"
 *  value: 10
 *  type: POTION
 */
 Inventory::Inventory(){
    length = 0; //using to keep track of how long array is 
    items[0].name = "Basic Health Potion";
	items[0].value = 10;
	items[0].type = POTION;

 }
/**
 * AddToInventory Function
 * Function that adds items to the inventory
 */ 
     void Inventory::AddToInventory(Item i){
	length++; //when this function is called will increment length
	items[length] = i;
}
/**
 * ShowInventory Function
 * Function that shows all items in the inventory
 * @attention Make sure that you format the output string as follows:
 *  Item - <Item Name> Value: <Item Value>
 */ 
 void Inventory::ShowInventory(){
    for (int i = 0; i <=length; i ++){
	std::cout<<"Item - "<<items[i].name<<" Value: "<<items[i].value<<std::endl;}
 }