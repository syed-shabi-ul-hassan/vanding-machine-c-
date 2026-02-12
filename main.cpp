#include <iostream>
#include <iomanip>
using namespace std;
// Description  :Simulates a vending machine where users can select items, insert money, and receive change.
const int SIZE = 8;
// Function to display vending machine menu
void displayMenu(string items[], int prices[], int stock[])

{
    cout << "\t\tSMART VENDING MACHINE" << endl;
    cout << left
         << setw(8)  << "ItemNo"
         << setw(20) << "Item Name"
         << setw(10) << "Price"
         << setw(12) << "Stock" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << left
             << setw(8)  << i + 1
             << setw(20) << items[i]
             << setw(10) << prices[i];
        if (stock[i] == 0)
            cout << setw(12) << "Out";
        else
            cout << setw(12) << stock[i];
        cout << endl;
    }
    cout << setw(8) << "0" << "Exit\n";
    cout << setw(8) << "9" << "Admin Refill\n";
}

// Function to handle purchase
void purchaseItem(string items[], int prices[], int stock[], int choice)
{
    int amount, quantity;
    cout << "\nYou selected: " << items[choice - 1] << endl;
    cout << "Price per item: Rs." << prices[choice - 1] << endl;
    cout << "Enter quantity: ";
    cin >> quantity;
    if (quantity <= 0 || quantity > stock[choice - 1])
    {
        cout << " .^. Invalid quantity or insufficient stock!\n";
        return;
    }
    int totalPrice = prices[choice - 1] * quantity;
    cout << "Total price: Rs." << totalPrice << endl;
    cout << "Insert amount (Rs): ";
    cin >> amount;
    if (amount >= totalPrice)
    {
        stock[choice - 1] -= quantity;
        cout << "\n.^. Transaction Successful!\n";
        cout << "Item: " << items[choice - 1] << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Change Returned: Rs." << amount - totalPrice << endl;
    }
    else
    {
        cout << "\n.^. Insufficient amount. Transaction cancelled!\n";
    }
}

// NEW FUNCTION: Refill System
void refillStock(string items[], int stock[])
{
    string password;
    cout << "\n========== ADMIN REFILL MODE ==========\n";
    cout << "Enter admin password: ";
    cin >> password;
    
    // Simple password check
    if (password != "admin123")
    {
        cout << ".^. Wrong password! Access denied.\n";
        return;
    }
    
    cout << "\n.^. Access granted!\n\n";
    
    // Show current stock
    cout << "CURRENT STOCK STATUS:\n";
    cout << left << setw(8) << "ItemNo" << setw(20) << "Item Name" << setw(12) << "Stock" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << setw(8) << i + 1 << setw(20) << items[i];
        if (stock[i] == 0)
            cout << setw(12) << "Out";
        else
            cout << setw(12) << stock[i];
        cout << endl;
    }
    
    // Refill options
    cout << "\n--- REFILL OPTIONS ---\n";
    cout << "1. Refill specific item\n";
    cout << "2. Refill all items to maximum (50)\n";
    cout << "0. Go back\n";
    cout << "Enter choice: ";
    
    int refillChoice;
    cin >> refillChoice;
    
    if (refillChoice == 1)
    {
        // Refill specific item
        int itemNum, addQuantity;
        cout << "Enter item number to refill (1-8): ";
        cin >> itemNum;
        
        if (itemNum < 1 || itemNum > SIZE)
        {
            cout << ".^. Invalid item number!\n";
            return;
        }
        
        cout << "Current stock of " << items[itemNum - 1] << ": " << stock[itemNum - 1] << endl;
        cout << "Enter quantity to add: ";
        cin >> addQuantity;
        
        if (addQuantity <= 0)
        {
            cout << ".^. Invalid quantity!\n";
            return;
        }
        
        stock[itemNum - 1] += addQuantity;
        cout << "\n.^. Successfully added " << addQuantity << " units!\n";
        cout << "New stock of " << items[itemNum - 1] << ": " << stock[itemNum - 1] << endl;
    }
    else if (refillChoice == 2)
    {
        // Refill all items
        cout << "\nRefilling all items to 50...\n";
        for (int i = 0; i < SIZE; i++)
        {
            stock[i] = 50;
        }
        cout << ".^. All items refilled to maximum stock (50)!\n";
    }
    else if (refillChoice == 0)
    {
        cout << "Returning to main menu...\n";
    }
    else
    {
        cout << ".^. Invalid choice!\n";
    }
}

int main()
{
    string items[SIZE] = {
        "Chips", "Chocolate", "Cold Drink", "Juice",
        "Biscuit", "Water Bottle", "Energy Drink", "Candy"
    };
    int prices[SIZE] = {50, 120, 80, 70, 40, 30, 150, 20};
    int stock[SIZE]  = {10, 8, 15, 12, 20, 25, 5, 30};
    int choice;
    char repeat;
    
    do
    {
        displayMenu(items, prices, stock);
        cout << "\nEnter item number: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= SIZE)
        {
            if (stock[choice - 1] > 0)
                purchaseItem(items, prices, stock, choice);
            else
                cout << ".^. Sorry! Item is out of stock.\n";
        }
        else if (choice == 0)
        {
            cout << "\nThank you for using Smart Vending Machine!\n";
            break;
        }
        else if (choice == 9)
        {
            // NEW: Call refill function
            refillStock(items, stock);
        }
        else
        {
            cout << ".^. Invalid selection! Try again.\n";
        }
        
        cout << "\nDo you want to buy another item? (y/n): ";
        cin >> repeat;
        
    } while (repeat == 'y' || repeat == 'Y');
    
    cout << "\n============= PROGRAM ENDED =============\n";
    return 0;
}