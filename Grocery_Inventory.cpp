#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> inventory = {"apples", "bananas", "oranges", "pears"};
    vector<string> shipment = {"kiwis", "bananas", "grapes"};
    vector<string> soldOutItems = {"apples", "oranges"};
    
    cout << "Current Inventory: [";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << inventory[i];
        if (i < inventory.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
        cout << "Shipment: [";
    for (size_t i = 0; i < shipment.size(); ++i) {
        cout << shipment[i];
        if (i < shipment.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
        cout << "Sold-out items: [";
    for (size_t i = 0; i < soldOutItems.size(); ++i) {
        cout << soldOutItems[i];
        if (i < soldOutItems.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    for (const string& item : soldOutItems) {
        auto it = find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
        }
    }
    
    for (const string& item : shipment) {
        if (find(inventory.begin(), inventory.end(), item) == inventory.end()) {
            inventory.push_back(item);
        }
    }

    cout << "Updated Inventory: [";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << inventory[i];
        if (i < inventory.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
