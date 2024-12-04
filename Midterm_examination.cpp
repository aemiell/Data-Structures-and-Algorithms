#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Data structure
struct Item {
    string name;
    double price;
    int quantity;
};

// Vector para sa pag store ng guitar items
vector<Item> items;

// CRUD 

// Add a new guitar item
void addItem() {
    Item newItem;
    
    cout << "Enter guitar brand name: ";
    cin.ignore(); 
    getline(cin, newItem.name); 
    
    cout << "Enter item price: ";
    cin >> newItem.price;
    cin.ignore(); 
    
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;
    cin.ignore(); 
    
    items.push_back(newItem);
    cout << "Guitar/item added successfully!\n";
}

// Read - Display all guitar items
void displayItems() {
    if (items.empty()) {
        cout << "No items found.\n";
        return;
    }

    cout << "\nAvailable Guitar Item:\n";
    for (const auto& item : items) {
        cout << "Item: " << item.name << "\nPrice: " << item.price 
             << "\nQuantity: " << item.quantity << "\n";
        cout << "--------------------\n";
    }
}

// Buy - Purchase a guitar item if available (kasama na po rito yung user's name)
void buyItem() {
    string userName, itemName;
    int quantityToBuy;

    // THe user need to enter his/her name before buying
    cout << "Enter your name: ";
    cin.ignore(); // Clear input buffer before taking string input
    getline(cin, userName); // Use getline for name input
    
    cout << "Enter guitar brandname to buy: ";
    getline(cin, itemName); // Use getline for item name
    
    cout << "Enter quantity to buy: ";
    cin >> quantityToBuy;
    cin.ignore(); // I-ignore yung newline sa cin

    for (auto& item : items) {
        if (item.name == itemName) {
            if (item.quantity >= quantityToBuy) {
                item.quantity -= quantityToBuy;
                cout << "Purchase successful! " << quantityToBuy << " " << item.name << "(s) bought by " << userName << ".\n";
            } else {
                cout << "Not enough stock. Available quantity: " << item.quantity << ".\n";
            }
            return;
        }
    }
    cout << "Item not found.\n";
}

// Update an existing guitar item
void updateItem() {
    string itemName;
    cout << "Enter the name of the guitar brand to update: ";
    cin.ignore();
    getline(cin, itemName); // Use getline for item name

    for (auto& item : items) {
        if (item.name == itemName) {
            cout << "Updating " << itemName << "...\n";
            cout << "Enter new price: ";
            cin >> item.price;
            cin.ignore(); 
            cout << "Enter new quantity: ";
            cin >> item.quantity;
            cin.ignore(); 
            cout << "Guitar item updated successfully!\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

// Delete - Remove a guitar item
void deleteItem() {
    string itemName;
    cout << "Enter the name of the guitar/item to delete: ";
    cin.ignore(); // Clear input buffer before taking string input
    getline(cin, itemName); // Use getline for item name

    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == itemName) {
            items.erase(it);
            cout << "Guitar/item deleted successfully!\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

// Menu 
void menu() {
    int choice;
    
    do {
        cout << "\n1. Add Guitar/Item\n2. Display Guitars/Items\n3. Update Guitar/Item\n4. Delete Guitar/Item\n5. Buy Guitar/Item\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                buyItem();
                break;
            case 6:
                cout << "Thank you for visiting/purchasing!!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    menu(); // Start menu
    return 0;
}
