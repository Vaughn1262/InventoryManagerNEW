// InventoryManagerNEW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <vector>
#include <iomanip>


int main()
{
    vector<string> names; // sets up vectors and gold
    vector<int> quantities;
    vector<int> values;
    int gold = 0;
    while (true) {

        cout << "Inventory Manager: Please select an option\n";
        int menuanswer; //sets up needed variables
        string item;
        int quantity;
        int value;
        cout << "1. Add an item\n2. Drop an item\n3. View Inventory\n4. Quick Sell an item\n5. Display Gold\n6. Buy an item\n7. Exit\n"; // Type a number between 1-7 and press enter
        cin >> menuanswer; // Get user input from the keyboard
        switch (menuanswer) {
        case 1: // Adds the item,quantity, and value to their respective vectors
        {
            cout << "What is the name of the item you would like to add?\n";  // Gets user inputs
            cin >> item;
            cout << "How many did you pick up?\n";
            cin >> quantity;
            cout << "How much is it worth?\n";
            cin >> value;
            names.emplace_back(item);              // places names, quantities, and values in their respective vectors
            quantities.emplace_back(quantity);
            values.emplace_back(value);
            break;
        }

        case 2:
        {

            string delitem;
            if (names.size() == 0) {        // checks if inventory is empty
                cout << "Inventory is empty\n";
                break;
            };
            cout << "What item would you like to drop?\n";    // asks user what item they would like to drop
            cin >> delitem;
            if (find(names.begin(), names.end(), delitem) != names.end()) {
                auto deleteind = find(names.begin(), names.end(), delitem);
                int delind = distance(names.begin(), deleteind);
                names.erase(deleteind);                          //gets rid of name, quantity, and value at the speciified place in those vectors
                quantities.erase(quantities.begin() + delind);
                values.erase(values.begin() + delind);
                break;
            }
            else {
                cout << "Could not find item.\n";  // covers if the user types in an invalid item
                break;
            };
            
        }
        case 3:
            cout << "\n";
            cout << "Inventory contains: \n";
            cout << "Name      Amount  Value     \n";
            if (names.size() == 0) {
                cout << "The inventory is empty\n\n";   // displays that the inventory is empty
            };
            for (int i = 0; i < names.size(); i++)
                cout << left << setw(10) << names[i] << left << setw(8) << quantities[i] << left << values[i]<< "\n"; // displays all items in inventory along with values and quantities
            break;

        case 4: 
        {
            string sellitem;
            if (names.size() == 0) {       // Checks if there are items to sell in the inventory
                cout << "Nothing to sell\n";
                break;
            }
            cout << "What item would you like to sell?\n";    //asks user what they want to sell
            cin >> sellitem;
            if (find(names.begin(), names.end(), sellitem) != names.end()) {
                auto sellind = find(names.begin(), names.end(), sellitem);
                int valueind = distance(names.begin(), sellind);
                gold = values[valueind]*quantities[valueind] + gold; //add value to users gold ammount based on quantity of items.
                names.erase(sellind);        //get rid of name, quantity, and value
                quantities.erase(quantities.begin() + valueind);
                values.erase(values.begin() + valueind);
                

            }
            else {
                cout << "Item not found\n"; // displays if user enters something that can't be sold or they don't have
                break;
            }
            break;
        }
        case 5:
        {
            cout << gold << "\n";  // displays users gold to the screen
            break;
        }
        case 6: {
            int itemnumber;
            string item;
            int value;
            int quantity;
            if (gold <= 0) {
                cout << "You have no money\n"; // checks if the user has money to buy things
                break;
            }
            cout << "What Item would you like to buy?\n1. Sword - 50\n2. Shield - 25\n3. Boots -2\n4. Custom\n";  //Asks user what item they want to buy
            cin >> itemnumber;
            cout << "How many would you like to buy?\n";  // asks user how many items they want to buy
            cin >> quantity;
            switch (itemnumber) { // switch statement to determine item selected. 
            case 1:
                item = "Sword";
                value = 50;
                break;
            case 2:
                item = "Shield";
                value = 25;
                break;
            case 3:
                item = "Boots";
                value = 20;
                break;
            case 4:
                cout << "What is the name of what you would like to buy?\n";  // gets user input for a custom item
                cin >> item;
                cout << "How much does it cost?\n";
                cin >> value;
                break;

            }

            if (gold >= value * quantity) {  // If user has enough gold, adds item to their inventory
                 gold = gold - value * quantity;
                 names.emplace_back(item);
                 quantities.emplace_back(quantity);
                 values.emplace_back(value);
                 cout << "Item successfully purchased!!\n"; // displays a message if user was able to buy item 
                 break;
                }

            else{                                          // if user doesn't have enough gold, it doesn't add to inventory
                cout << "Not enough money for purchase\n"; // displays if the user doesn't have enough gold
                break;
            }


            break;
        }
        case 7:
            return 0;
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
