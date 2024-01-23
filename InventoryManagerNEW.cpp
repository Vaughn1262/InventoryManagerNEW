// InventoryManagerNEW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>


int main()
{
    while (true) {
        cout << "Inventory Manager: Please select an option\n";
        int menuanswer;
        string item;
        int quantity;
        int value;
        vector<string> names;
        vector<int> quantities;
        vector<int> values;
        cout << "1. Add an item\n2. Drop an item\n3. View Inventory\n4. Quick Sell an item\n5.Exit\n"; // Type a number and press enter
        cin >> menuanswer; // Get user input from the keyboard
        switch (menuanswer) {
        case 1:
        {
            cout << "What is the name of the item you would like to add?\n";
            cin >> item;
            cout << item;
            cout << "How many did you pick up?\n";
            cin >> quantity;
            cout << "How much is it worth?\n";
            cin >> value;
            names.emplace(names.begin(), item);
            cout << names[0];
            quantities.emplace_back(quantity);
            values.emplace_back(value);
            break;
        }

        case 2:
            break;
        case 3:
            cout << "Inventory contains: \n";
            cout << names.size();
            for (int i = 0; i < names.size(); i++) {
                cout << "\n";
                cout << names[i];
            }


            break;
        case 4:
            break;
        case 5:
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
