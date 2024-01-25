// InventoryManagerNEW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <vector>
#include <iomanip>


int main()
{
    vector<string> names;
    vector<int> quantities;
    vector<int> values;
    int gold = 0;
    while (true) {

        cout << "Inventory Manager: Please select an option\n";
        int menuanswer;
        string item;
        int quantity;
        int value;


        cout << "1. Add an item\n2. Drop an item\n3. View Inventory\n4. Quick Sell an item\n5. Display Gold\n6. Buy an item\n7. Exit\n"; // Type a number and press enter
        cin >> menuanswer; // Get user input from the keyboard
        switch (menuanswer) {
        case 1:
        {
            cout << "What is the name of the item you would like to add?\n";
            cin >> item;
            cout << "How many did you pick up?\n";
            cin >> quantity;
            cout << "How much is it worth?\n";
            cin >> value;
            names.emplace_back(item);
            quantities.emplace_back(quantity);
            values.emplace_back(value);
            break;
        }

        case 2:
        {

            string delitem;
            int delitemint;
            if (names.size() == 0) {
                cout << "Inventory is empty\n";
                break;
            };
            cout << "What item would you like to drop?\n";
            cin >> delitem;
            if (find(names.begin(), names.end(), delitem) != names.end()) {
                auto deleteind = find(names.begin(), names.end(), delitem);
                int delind = distance(names.begin(), deleteind);
                //delitemint = quantities[delind];
                //auto deleteind1 = find(names.begin(), names.end(), delitemint);
                names.erase(deleteind);
                quantities.erase(quantities.begin() + delind);
                values.erase(values.begin() + delind);
                break;
            }
            else {
                cout << "Could not find item.\n";
                break;
            };
            
        }
        case 3:
            cout << "\n";
            cout << "Inventory contains: \n";
            cout << "Name      Amount  Value     \n";
            if (names.size() == 0) {
                cout << "The inventory is empty\n";
            };
            for (int i = 0; i < names.size(); i++)
                cout << left << setw(10) << names[i] << left << setw(8) << quantities[i] << left << values[i]<< "\n";
            break;
        case 4: 
        {
            string sellitem;
            if (names.size() == 0) {
                cout << "Nothing to sell\n";
                break;
            }
            cout << "What item would you like to sell?\n";
            cin >> sellitem;
            if (find(names.begin(), names.end(), sellitem) != names.end()) {
                auto sellind = find(names.begin(), names.end(), sellitem);
                int valueind = distance(names.begin(), sellind);
                gold = values[valueind]*quantities[valueind] + gold;
                names.erase(sellind);
                quantities.erase(quantities.begin() + valueind);
                values.erase(values.begin() + valueind);
                

            }
            else {
                cout << "Item not found\n";
                break;
            }
            break;
        }
        case 5:
        {
            cout << gold << "\n";
            break;
        }
        case 6: {
            int itemnumber;
            string item;
            int value;
            int quantity;
            if (gold <= 0) {
                cout << "You have no money\n";
                break;
            }
            cout << "What Item would you like to buy?\n1. Sword - 50\n2. Shield - 25\n3. Boots -2\n4. Custom\n";
            cin >> itemnumber;
            cout << "How many would you like to buy?\n";
            cin >> quantity;
            switch (itemnumber) {
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
                cout << "What is the name of what you would like to buy?\n";
                cin >> item;
                cout << "How much does it cost?\n";
                cin >> value;
                break;

            }

            if (gold >= value * quantity) {
                 gold = gold - value * quantity;
                 names.emplace_back(item);
                 quantities.emplace_back(quantity);
                 values.emplace_back(value);
                 cout << "Item successfully purchased!!\n";
                 break;
                }

            else{
                cout << "Not enough money for purchase\n";
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
