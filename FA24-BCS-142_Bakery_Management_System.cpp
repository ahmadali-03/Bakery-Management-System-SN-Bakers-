
// Semester 1 – Programming Fundamentals
// Project title:
//              "BAKERY MANAGEMENT SYSTEM"

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<thread>
#include<chrono>
using namespace std;

// Structure for inventory
struct Item
{
    string itemId;
    string itemName;
    float price;
    int quantity;
};

// Structure for order    
struct OrderItem
{
    string itemId;
    string itemName;
    int quantity;
    float price;
};

// Structure for customer feedback
struct Feedback
{
    string customerName;
    int itemId;
    string feedbackText;
    float serviceRating;
};

// Structure for Employees
struct Employee
{
    string employeeId;
    string employeeName;
    string employeeRole;
    float employeeWorkHours;
    double employeeSalary;
    string employeeContact;
};

// Structure for Discount
struct Discount
{
    string itemId;
    float discountPercentage;
    int discountValidityPeriod;
};

// Structure for daily sales
struct SalesItem
{
    string soldItemId;
    string soldItemName;
    int soldQuantity;
    float soldItemPrice;
};

// Structure for Expense
struct Expense
{
    string expenseDescription;
    float expenseAmount;
    string expenseDate;
};


//Global arrays and variables
// Global array and variable for inventory
Item inventory[100];
int inventoryCount = 0;

// Global arrays and variables for customer management
int orderCapacity = 1;
OrderItem* orders = new OrderItem[orderCapacity];
int orderCount = 0;
Feedback feedbacks[100];
int feedbackCount = 0;

// Global array and variable for employees
Employee employees[100];
int  employeeCount = 0;

// Global array and variable for Discount
Discount discounts[30];
int discountCount = 0;

// Global array and variable for daily sales
int salesCapacity = 1;
SalesItem* sales = new SalesItem[salesCapacity];
int salesCount = 0;

// Global array and variable for expense data
Expense expenses[100];
int expenseCount = 0;


// Functions prototypes
// Function prototypes for inventory management
void manageInventory();
void addItem();
void updateItem();
void removeItem();
void displayInventory();
void saveInventoryToFile();
void loadInventoryFromFile();


// Function prototypes for customer management
void customerService();
void viewItems();
void placeOrder();
void printBill();
void takeFeedback();


// Function protoypes for feedback
void manageFeedback();
void displayFeedback();
float calculateAverageRating();
void saveFeedbackToFile();
void loadFeedbackFromFile();


// Function prototypes for employee management
void manageEmployee();
void addEmployee();
void viewEmployees();
void updateEmployee();
void removeEmployee();
void searchEmployee();
void saveEmployeesToFile();
void loadEmployeesFromFile();


// Function prototypes for daily sales
void manageSalesReport();
void recordSale();
void viewSalesReport();
void generateDailySalesReport();


// Function prototypes for expense management
void manageExpenses();
void addExpense();
void viewExpenses();
void calculateTotalExpenses();


// Function protoypes for dicount
void manageDiscount();
float applyDiscount(float totalAmount);
float applyDiscountOnItem(float& totalAmount);


// Function to change text color
void setTextColor(int color)
{
    cout << "\033[" << color << "m";
}

// Function to display colorful animation
void displayStartupAnimation()
{
    system("cls");

    const string art[] = {
        "",
        "  SSSSS    N   N             BBBBB    AAAAA   K   K   EEEEE   RRRRR   SSSSS  ",
        " S         NN  N             B    B  A     A  K  K    E       R   R   S      ",
        "  SSSSS    N N N             BBBBB   AAAAAAA  KKK     EEEE    RRRRR   SSSSS  ",
        "      S    N  NN             B    B  A     A  K  K    E       R  R        S  ",
        " SSSSS     N   N             BBBBB   A     A  K   K   EEEEE   R   R   SSSSS  ",
        ""
    };

    const int colors[] = { 33, 32, 31, 36, 35, 34 };

    for (int i = 0; i < 3; ++i)
    {
        setTextColor(colors[i % 6]);

        for (int j = 0; j < 7; ++j)
        {
            cout << art[j] << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
        }

        this_thread::sleep_for(chrono::milliseconds(500));
        if (i < 2) 
        {
            system("cls");
        }
    }

    setTextColor(36);
    cout << "\n Welcome to S.N Bakers! Your Happiness, Our Recipe!\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main()
{
    displayStartupAnimation();

    cout << "Press Enter to proceed to the menu...";
    cin.get();

    int choice;

    do
    {
        cout << "\n--- S.N Bakers Management System ---" << endl;
        cout << "1. Manage Inventory" << endl;
        cout << "2. Customer Service" << endl;
        cout << "3. Manage Discounts" << endl;
        cout << "4. Manage Feedbacks" << endl;
        cout << "5. Manage Employees" << endl;
        cout << "6. Generate Sales Report" << endl;
        cout << "7. Track Expenses" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            manageInventory();
            break;
        case 2:
            customerService();
            break;
        case 3:
            manageDiscount();
            break;
        case 4:
            manageFeedback();
            break;
        case 5:
            manageEmployee();
            break;
        case 6:
            manageSalesReport();
            break;
        case 7:
            manageExpenses();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default: 
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}

// Definitions of inventory functions
// Inventory Menu
void manageInventory()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Inventory Management ---" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Update Item" << endl;
        cout << "3. Remove Item" << endl;
        cout << "4. Display Inventory" << endl;
        cout << "5. Save Inventory to File" << endl;
        cout << "6. Load Inventory from File" << endl;
        cout << "7. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem(); 
            break;
        case 2: 
            updateItem(); 
            break;
        case 3:
            removeItem();
            break;
        case 4: 
            displayInventory();
            break;
        case 5:
            saveInventoryToFile(); 
            break;
        case 6: 
            loadInventoryFromFile(); 
            break;
        case 7:
            cout << "Returning to Main Menu..." << endl;
            system("cls");
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 7);
}

// Function to add item to inventory
void addItem()
{
    if (inventoryCount >= 100)
    {
        cout << "Inventory is full! Cannot add more items." << endl;
        return;
    }

    string newItemId;
    bool itemIdExists;

    cout << "\nEnter Item Details:" << endl;

    do
    {
        itemIdExists = false;
        cout << "Item ID: ";
        cin >> newItemId;

        for (int i = 0; i < inventoryCount; i++)
        {
            if (inventory[i].itemId == newItemId)
            {
                cout << "Item ID already exists! Please enter another item ID." << endl;
                itemIdExists = true;
                break;
            }
        }
    } while (itemIdExists);

    cin.ignore();
    inventory[inventoryCount].itemId = newItemId;
    cout << "Item Name: ";
    getline(cin, inventory[inventoryCount].itemName);
    cout << "Item Price: ";
    cin >> inventory[inventoryCount].price;
    cout << "Item Quantity: ";
    cin >> inventory[inventoryCount].quantity;

    inventoryCount++;
    
    cout << "Item added successfully!" << endl;
}

// Function to update item in inventory
void updateItem()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is empty! No items to update." << endl;
        return;
    }
    string itemId;

    cout << "\nEnter the ID of the item to update: ";
    cin >> itemId;

    for (int i = 0; i < inventoryCount; i++)
    {
        if (inventory[i].itemId == itemId)
        {
            string newName;

            cout << "Updating details for " << inventory[i].itemName << ":" << endl;
            cout << "New Name (leave blank to keep current): ";
            cin.ignore();
            getline(cin, newName);

            if (newName != "")
            {
                inventory[i].itemName = newName;
            }

            cout << "New Price: ";
            cin >> inventory[i].price;
            cout << "New Quantity: ";
            cin >> inventory[i].quantity;
            cout << "Item updated successfully!" << endl;

            return;
        }
    }

    cout << "Item with ID " << itemId << " not found." << endl;
}

// Function to remove item in inventory
void removeItem()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is empty! No items to remove." << endl;
        return;
    }
    string itemId;

    cout << "\nEnter the ID of the item to remove: ";
    cin >> itemId;

    for (int i = 0; i < inventoryCount; i++)
    {
        if (inventory[i].itemId == itemId)
        {
            for (int j = i; j < inventoryCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            inventoryCount--;

            cout << "Item removed successfully!" << endl;

            return;
        }
    }

    cout << "Item with ID " << itemId << " not found." << endl;
}

// Function to display inventory
void displayInventory()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is empty. No items to display" << endl;
        return;
    }

    cout << "\n--- Inventory ---" << endl;
    cout << left << setw(10) << "Item ID" << setw(25) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < inventoryCount; i++)
    {
        cout << left << setw(10) << inventory[i].itemId << setw(25) << inventory[i].itemName << setw(10) << inventory[i].price << setw(10) << inventory[i].quantity << endl;
    }
}

// Function to save inventory
void saveInventoryToFile()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is empty! No items to save." << endl;
        return;
    }

    ofstream outputFile("inventory.txt");

    if (!outputFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outputFile << inventoryCount << endl;

    for (int i = 0; i < inventoryCount; i++)
    {
        outputFile << inventory[i].itemId << "," << inventory[i].itemName << "," << inventory[i].price << "," << inventory[i].quantity << endl;;
    }
    outputFile.close();

    cout << "Inventory saved to file successfully!" << endl;
}

// Function to load inventory
void loadInventoryFromFile()
{
    ifstream inFile("inventory.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    inFile >> inventoryCount;
    inFile.ignore();

    string line;
    for (int i = 0; i < inventoryCount; i++)
    {
        getline(inFile, line);
        stringstream ss(line);

        string temp;

        getline(ss, temp, ',');
        inventory[i].itemId = temp;

        getline(ss, inventory[i].itemName, ',');

        getline(ss, temp, ',');
        inventory[i].price = stod(temp);

        getline(ss, temp, ',');
        getline(ss, inventory[i].itemId, ',');

        getline(ss, temp, ',');
        inventory[i].quantity = stoi(temp);
    }

    inFile.close();
    cout << "Inventory loaded from file successfully!" << endl;
}

// Definitions of customer management functions
// Customer menu
void customerService()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Customer Order and Feedback ---" << endl;
        cout << "1. View Items" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Print Bill" << endl;
        cout << "4. Give Feedback" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            viewItems();
            break;
        case 2: 
            placeOrder();
            break;
        case 3: 
            printBill();
            break;
        case 4: 
            takeFeedback(); 
            break;
        case 5:
            cout << "Returning to Main Menu..." << endl;
            system("cls");
            break;
        default: 
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 5);
}

// Function to view items
void viewItems()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is Empty! No items to view." << endl;
        return;
    }

    cout << "\n--- Available Items ---" << endl;
    cout << left << setw(10) << "Item ID" << setw(25) << "Item Name" << setw(10) << "Price" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < inventoryCount; i++)
    {
        cout << left << setw(10) << inventory[i].itemId << setw(25) << inventory[i].itemName << setw(10) << inventory[i].price << endl;
    }
}

// Function to place orders
void placeOrder()
{
    if (inventoryCount == 0)
    {
        cout << "Inventory is Empty! You cannot place an order." << endl;
        return;
    }

    if (orderCount >= orderCapacity)
    {
        orderCapacity++;
        OrderItem* newOrders = new OrderItem[orderCapacity];

        for (int i = 0; i < orderCount; i++)
        {
            newOrders[i] = orders[i];
        }

        delete[] orders;
        orders = newOrders;
    }

    cout << "\n--- Place Order ---" << endl;

    viewItems();

    string itemId;
    int orderQuantity;
    int itemIndex = -1;

    do
    {
        cout << "Enter the ID of item you want to order: ";
        cin >> itemId;

        for (int i = 0; i < inventoryCount; i++)
        {
            if (inventory[i].itemId == itemId)
            {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1)
        {
            cout << "Invalid Item ID! Try again." << endl;
        }
    } while (itemIndex == -1);

    cout << "Enter Quantity: ";
    cin >> orderQuantity;

    if (orderQuantity > inventory[itemIndex].quantity)
    {
        cout << "Insufficient stock! Only " << inventory[itemIndex].quantity << " available." << endl;
        return;
    }

    inventory[itemIndex].quantity -= orderQuantity;

    orders[orderCount].itemId = inventory[itemIndex].itemId;
    orders[orderCount].itemName = inventory[itemIndex].itemName;
    orders[orderCount].quantity = orderQuantity;
    orders[orderCount].price = inventory[itemIndex].price;
    orderCount++;

    bool itemFoundInSales = false;

    for (int i = 0; i < salesCount; i++)
    {
        if (sales[i].soldItemId == inventory[itemIndex].itemId)
        {
            sales[i].soldQuantity += orderQuantity;
            itemFoundInSales = true;
            break;
        }
    }

    if (salesCount >= salesCapacity)
    {
        salesCapacity++;
        SalesItem* newSales = new SalesItem[salesCapacity];

        for (int i = 0; i < salesCount; i++)
        {
            newSales[i] = sales[i];
        }

        delete[] sales;
        sales = newSales;
    }

    if (!itemFoundInSales)
    {
        sales[salesCount].soldItemId = inventory[itemIndex].itemId;
        sales[salesCount].soldItemName = inventory[itemIndex].itemName;
        sales[salesCount].soldItemPrice = inventory[itemIndex].price;
        sales[salesCount].soldQuantity = orderQuantity;
        salesCount++;
    }

    cout << "Order placed successfully!" << endl;
}

// Function to print bill
void printBill()
{
    if (orderCount == 0)
    {
        cout << "No items in the order to print a bill." << endl;
        return;
    }

    float total = 0.0;

    cout << "\n--- Bill ---" << endl;
    cout << left << setw(30) << "Item Name" << setw(10) << "Quantity" << setw(10) << "Price" << "Total" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < orderCount; i++)
    {
        float itemTotal = orders[i].quantity * orders[i].price;
        total += itemTotal;

        cout << left << setw(30) << orders[i].itemName << setw(10) << orders[i].quantity << setw(10) << orders[i].price << itemTotal << endl;
    }

    applyDiscountOnItem(total);
    float discountAmount = applyDiscount(total);
    float finalTotal = total - discountAmount;

    cout << "----------------------------------------------------" << endl;
    cout << "Total: " << finalTotal << endl;
}

// Function to take feedback from customer
void takeFeedback()
{
    if (feedbackCount >= 100)
    {
        cout << "Feedback storage is full! Cannot accept more feedback." << endl;
        return;
    }

    cout << "\n--- Provide Feedback ---" << endl;
    cin.ignore();
    cout << "Enter your name (optional, press Enter to skip): ";
    getline(cin, feedbacks[feedbackCount].customerName);

    if (feedbacks[feedbackCount].customerName == "")
    {
        feedbacks[feedbackCount].customerName = "Anonymous";
    }

    cout << "Enter the item ID: ";
    cin >> feedbacks[feedbackCount].itemId;
    cin.ignore();
    cout << "Enter your feedback: ";
    getline(cin, feedbacks[feedbackCount].feedbackText);

    do
    {
        cout << "Rate our service (1-5): ";
        cin >> feedbacks[feedbackCount].serviceRating;

        if (feedbacks[feedbackCount].serviceRating >= 1 && feedbacks[feedbackCount].serviceRating <= 5)
        {
            break;
        }

        cout << "Invalid rating! Enter number between 1-5" << endl;

    } while (feedbacks[feedbackCount].serviceRating < 1 || feedbacks[feedbackCount].serviceRating > 5);
    feedbackCount++;

    cout << "Thank you for your feedback!" << endl;
}

// Functions to manage and add discounts
// Function to add discount
void manageDiscount()
{
    system("cls");
    if (discountCount >= 30)
    {
        cout << "Discount list is full! You cannot add more discounts." << endl;
        return;
    }

    Discount newDiscount;
    bool itemExists = false;

    cout << "\n--- Add Discount ---" << endl;
    cout << "Enter Item ID on which discount should be applied: ";
    cin >> newDiscount.itemId;

    for (int i = 0; i < inventoryCount; i++)
    {
        if (inventory[i].itemId == newDiscount.itemId)
        {
            itemExists = true;
            break;
        }
    }

    if (!itemExists)
    {
        cout << "Item ID not found in inventory!" << endl;
        return;
    }

    cout << "Enter Discount Percentage: ";
    cin >> newDiscount.discountPercentage;
    cout << "Enter Validity (Number of times discount can be applied): ";
    cin >> newDiscount.discountValidityPeriod;
    cout << "Discount added successfully for item ID: " << newDiscount.itemId << endl;
    
    system("cls");
    discounts[discountCount++] = newDiscount;
}

// Function to apply discount based on item
float applyDiscountOnItem(float& totalAmount)
{
    float totalDiscount = 0.0;
    bool discountApplied = false, discountExpired = false;

    cout << "\n--- Discounts ---" << endl;

    for (int i = 0; i < orderCount; i++)
    {

        for (int j = 0; j < discountCount; j++)
        {
            discountExpired = false;
            if (discounts[j].itemId == orders[i].itemId)
            {
                if (discounts[j].discountValidityPeriod > 0)
                {
                    float itemTotal = orders[i].price * orders[i].quantity;
                    float discountAmount = itemTotal * (discounts[j].discountPercentage / 100);

                    totalDiscount += discountAmount;
                    discounts[j].discountValidityPeriod--;

                    cout << "Discount of " << discounts[j].discountPercentage << "% applied to item '"
                        << orders[i].itemId << "'. Discount: " << discountAmount << endl;

                    discountApplied = true;
                    break;
                }
                else
                {
                    cout << "Discount expired for item ID " << orders[i].itemId << " (" << orders[i].itemName << ")" << endl;
                    discountExpired = true;
                    break;
                }
            }
        }

        if (!discountApplied && !discountExpired)
        {
            cout << "No discount available for item " << orders[i].itemId << " (" << orders[i].itemName << ")" << endl;
        }
    }

    totalAmount -= totalDiscount;
    return totalDiscount;
}

// Function to apply discount based on total price
float applyDiscount(float totalAmount)
{
    float discountRate = 0.0;

    if (totalAmount >= 5000)
    {
        discountRate = 0.20;
    }
    else if (totalAmount >= 2000)
    {
        discountRate = 0.15;
    }
    else if (totalAmount >= 1000)
    {
        discountRate = 0.10;
    }

    if (discountRate > 0)
    {
        float discountAmount = totalAmount * discountRate;
        cout << "----------------------------------------------------" << endl;
        cout << "Discount Applied based on total amount: " << discountAmount << endl;
        return discountAmount;
    }
    else
    {
        cout << "No Discount Applied based on total amount" << endl;
        return 0;
    }
}


// Definitions of feedback mamnagement
// Feedback menu
void manageFeedback()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Feedback Management ---" << endl;
        cout << "1. Display Feedback" << endl;
        cout << "2. Calculate Average Service Rating" << endl;
        cout << "3. Save Feedback to File" << endl;
        cout << "4. Load Feedback from File" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            displayFeedback(); 
            break;
        case 2:
        {
            int avgRating = calculateAverageRating();
            if (avgRating != 0.0)
            {
                cout << "\nAverage Service Rating: " << setprecision(2) << calculateAverageRating() << "/5" << endl;
            }
            break;
        }
        case 3:
            saveFeedbackToFile();
            break;
        case 4: 
            loadFeedbackFromFile();
            break;
        case 5:
            cout << "Returning to Main Menu..." << endl;
            system("cls");
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 5);
}

// Function to display feedback
void displayFeedback()
{
    if (feedbackCount == 0)
    {
        cout << "No feedback available." << endl;
        return;
    }

    cout << "\n--- Customer Feedback ---" << endl;
    for (int i = 0; i < feedbackCount; i++)
    {
        cout << "Customer Name: " << feedbacks[i].customerName << endl;
        cout << "Item ID: " << feedbacks[i].itemId << endl;
        cout << "Feedback: " << feedbacks[i].feedbackText << endl;
        cout << "Service Rating: " << feedbacks[i].serviceRating << "/5" << endl;
        cout << "-------------------------------------" << endl;
    }
}

// Function to calculate average rating
float calculateAverageRating()
{
    if (feedbackCount == 0)
    {
        cout << "No feedbacks available to calculate an average rating." << endl;
        return 0.0;
    }

    int totalRating = 0;

    for (int i = 0; i < feedbackCount; i++)
    {
        totalRating += feedbacks[i].serviceRating;
    }

    return float(totalRating) / feedbackCount;
}


// Function to save feedbacks to file
void saveFeedbackToFile()
{
    if (feedbackCount == 0)
    {
        cout << "No feedbacks available to save." << endl;
        return;
    }

    ofstream outputFile("feedback.txt");

    if (!outputFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outputFile << feedbackCount << endl;

    for (int i = 0; i < feedbackCount; i++)
    {
        outputFile << feedbacks[i].customerName << "|" << feedbacks[i].itemId << "|" << feedbacks[i].feedbackText << "|" << feedbacks[i].serviceRating << endl;
    }
    outputFile.close();

    cout << "Feedback saved to file successfully!" << endl;
}

// Function to load feedbacks
void loadFeedbackFromFile()
{
    ifstream inFile("feedback.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    inFile >> feedbackCount;
    inFile.ignore();

    string line;
    for (int i = 0; i < feedbackCount; i++)
    {
        getline(inFile, line);
        stringstream ss(line);
        string temp;

        getline(ss, feedbacks[i].customerName, '|');

        getline(ss, temp, '|');
        feedbacks[i].itemId = stoi(temp);

        getline(ss, feedbacks[i].feedbackText, '|');

        getline(ss, temp, '|');
        feedbacks[i].serviceRating = stof(temp);
    }

    inFile.close();
    cout << "Feedback loaded from file successfully!" << endl;
}


// Definitions of employee managemnt functions
// Employee management menu
void manageEmployee()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Employee Management ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. View Employees" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Remove Employee" << endl;
        cout << "5. Save Employees to File" << endl;
        cout << "6. Search Employee by ID" << endl;
        cout << "7. Load Employees from File" << endl;
        cout << "8. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2: 
            viewEmployees();
            break;
        case 3: 
            updateEmployee();
            break;
        case 4: 
            removeEmployee();
            break;
        case 5:
            saveEmployeesToFile();
            break;
        case 6:
            searchEmployee(); 
            break;
        case 7:
            loadEmployeesFromFile();
            break;
        case 8:
            cout << "Returning to Main Menu..." << endl; 
            system("cls");
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 8);
}

// Function to add employees
void addEmployee()
{
    if (employeeCount >= 100)
    {
        cout << "Employee database is full! You cannot add any employee." << endl;
        return;
    }

    Employee newEmployee;
    bool employeeIdExists;

    cout << "\n--- Add Employee ---" << endl;

    do
    {
        employeeIdExists = false;
        cout << "Enter Employee ID: ";
        cin >> newEmployee.employeeId;
        cin.ignore();

        for (int i = 0; i < employeeCount; i++)
        {
            if (employees[i].employeeId == newEmployee.employeeId)
            {
                employeeIdExists = true;
                cout << "An employee with this ID already exists. Enter another ID.\n";
                break;
            }
        }
    } while (employeeIdExists);

    cout << "Enter Employee Name: ";
    getline(cin, newEmployee.employeeName);
    cout << "Enter Role of employee: ";
    getline(cin, newEmployee.employeeRole);
    cout << "Enter Work Hours: ";
    cin >> newEmployee.employeeWorkHours;
    cout << "Enter Salary: ";
    cin >> newEmployee.employeeSalary;
    cin.ignore();
    cout << "Enter Contact Number: ";
    getline(cin, newEmployee.employeeContact);
    cout << "Employee added successfully!" << endl;

    employees[employeeCount++] = newEmployee;
}

// Function to view employees
void viewEmployees()
{
    if (employeeCount == 0)
    {
        cout << "No employees to display." << endl;
        return;
    }

    cout << "\n--- Employee List ---" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Role" << setw(10) << "Hours" << setw(15) << "Salary" << setw(15) << "Contact" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < employeeCount; i++)
    {
        cout << left << setw(10) << employees[i].employeeId << setw(20) << employees[i].employeeName << setw(20) << employees[i].employeeRole << setw(10) << fixed << setprecision(2) << employees[i].employeeWorkHours << setw(15)  << employees[i].employeeSalary << setw(15) << employees[i].employeeContact << endl;
    }
}

// Function to update employees
void updateEmployee()
{
    if (employeeCount == 0)
    {
        cout << "No employees to update." << endl;
        return;
    }

    string employeeId;

    cout << "\nEnter the Employee ID to update: ";
    cin >> employeeId;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeId == employeeId)
        {
            cout << "Enter updated details for Employee ID " << employeeId << ":" << endl;
            cin.ignore();
            cout << "Enter Employee Name: ";
            getline(cin, employees[i].employeeName);
            cout << "Enter Role of employee: ";
            getline(cin, employees[i].employeeRole);
            cout << "Enter Work Hours: ";
            cin >> employees[i].employeeWorkHours;
            cout << "Enter Salary: ";
            cin >> employees[i].employeeSalary;
            cin.ignore();
            cout << "Enter Contact Number: ";
            getline(cin, employees[i].employeeContact);
            cout << "Employee updated successfully!" << endl;

            return;
        }
    }

    cout << "Employee with ID " << employeeId << " not found." << endl;
}

// Function to remove employees
void removeEmployee()
{
    if (employeeCount == 0)
    {
        cout << "No employees to remove." << endl;
        return;
    }

    string employeeId;

    cout << "\nEnter the Employee ID to remove: ";
    cin >> employeeId;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeId == employeeId)
        {
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            employeeCount--;

            cout << "Employee removed successfully!" << endl;

            return;
        }
    }

    cout << "Employee with ID " << employeeId << " not found." << endl;
}

// Function to search employees by ID
void searchEmployee()
{
    if (employeeCount == 0)
    {
        cout << "No employees to search." << endl;
        return;
    }

    string searchId;
    cout << "\nEnter the Employee ID to search: ";
    cin >> searchId;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeId == searchId)
        {
            cout << "\n--- Employee Found ---" << endl;
            cout << "ID: " << employees[i].employeeId << endl;
            cout << "Name: " << employees[i].employeeName << endl;
            cout << "Role: " << employees[i].employeeRole << endl;
            cout << "Work Hours: " << employees[i].employeeWorkHours << endl;
            cout << "Salary: " << employees[i].employeeSalary << endl;
            cout << "Contact: " << employees[i].employeeContact << endl;
            return;
        }
    }

    cout << "Employee with ID " << searchId << " not found." << endl;
}

// Function to save employees
void saveEmployeesToFile()
{
    if (employeeCount == 0)
    {
        cout << "No employees to save!" << endl;
        return;
    }

    ofstream outFile("employees.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outFile << employeeCount << "\n";

    for (int i = 0; i < employeeCount; i++)
    {
        outFile << employees[i].employeeId << "," << employees[i].employeeName << "," << employees[i].employeeRole << "," 
            << employees[i].employeeWorkHours << "," << employees[i].employeeSalary << "," << employees[i].employeeContact << "\n";
    }

    outFile.close();
    cout << "Employees saved to file successfully!" << endl;
}


// Function to load employees
void loadEmployeesFromFile()
{
    ifstream inFile("employees.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    inFile >> employeeCount;
    inFile.ignore();

    string line;
    for (int i = 0; i < employeeCount; i++)
    {
        if (!getline(inFile, line))
        {
            cout << "Error reading employee data from file (line " << i + 2 << ")." << endl;
            break;
        }

        stringstream ss(line);
        string temp;

        getline(ss, employees[i].employeeId, ',');
        getline(ss, employees[i].employeeName, ',');
        getline(ss, employees[i].employeeRole, ',');

        getline(ss, temp, ',');
        employees[i].employeeWorkHours = stof(temp);

        getline(ss, temp, ',');
        employees[i].employeeSalary = stof(temp);

        getline(ss, employees[i].employeeContact, ',');
    }

    inFile.close();
    cout << "Employees loaded from file successfully!" << endl;
}


// Definition of daily sales functions
// Sales report menu
void manageSalesReport()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Daily Sales Report ---" << endl;
        cout << "1. Record a Sale" << endl;
        cout << "2. View Sales Report" << endl;
        cout << "3. Generate Daily Sales Report" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            recordSale();
            break;
        case 2: 
            viewSalesReport(); 
            break;
        case 3:
            generateDailySalesReport();
            break;
        case 4: 
            cout << "Returning to Main Menu..." << endl;
            system("cls");
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 4);
}

// Function to record sales
void recordSale()
{
    if (salesCount >= 100)
    {
        cout << "Sales list is full! You cannot record any sales." << endl;
        return;
    }

    SalesItem newSale;

    if (salesCount >= salesCapacity)
    {
        salesCapacity++;
        SalesItem* newSales = new SalesItem[salesCapacity];

        for (int i = 0; i < salesCount; i++)
        {
            newSales[i] = sales[i];
        }

        delete[] sales;
        sales = newSales;
    }

    for (int i = 0; i < inventoryCount; i++)
    {
        if (inventory[i].itemId == newSale.soldItemId)
        {
            newSale.soldItemName = inventory[i].itemName;
            break;
        }
    }


    cout << "\n--- Record a Sale ---" << endl;
    cin.ignore();
    cout << "Enter Item ID: ";
    getline(cin, newSale.soldItemId);
    cout << "Enter Quantity Sold: ";
    cin >> newSale.soldQuantity;
    cout << "Enter Price per Item: ";
    cin >> newSale.soldItemPrice;

    float totalSale = newSale.soldQuantity * newSale.soldItemPrice;
    sales[salesCount++] = newSale;

    cout << "Total Sale for " << newSale.soldItemId << ": " << totalSale << endl;
    cout << "Sale recorded successfully!" << endl;
}

// Function to view sales report
void viewSalesReport()
{
    if (salesCount == 0)
    {
        cout << "No sales to display." << endl;
        return;
    }

    cout << "\n--- Sales Report ---" << endl;
    cout << left << setw(10) << "Item ID" << setw(20) << "Item Name" << setw(20) << "Quantity Sold" << setw(10) << "Price" << setw(15) << "Total Sale" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (int i = 0; i < salesCount; i++)
    {
        cout << left << setw(10) << sales[i].soldItemId << setw(20) << sales[i].soldItemName << setw(20) << sales[i].soldQuantity << setw(10) << sales[i].soldItemPrice << setw(15) << sales[i].soldQuantity * sales[i].soldItemPrice << endl;
    }
}

// Function to generate daily sales reports
void generateDailySalesReport()
{
    if (salesCount == 0)
    {
        cout << "No sales recorded today." << endl;
        return;
    }

    float totalRevenue = 0;
    int mostSoldIndex = 0;

    cout << "\n--- Daily Sales Report ---" << endl;

    for (int i = 0; i < salesCount; i++)
    {
        totalRevenue += sales[i].soldQuantity * sales[i].soldItemPrice;

        if (sales[i].soldQuantity > sales[mostSoldIndex].soldQuantity)
        {
            mostSoldIndex = i;
        }
    }

    cout << "Total Revenue: " << totalRevenue << endl;
    cout << "\n---Item-Wise Sales Count---" << endl;
    cout << left << setw(20) << "ItemName" << setw(10) << "Item ID" << "Quantity Sold" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < salesCount; i++)
    {
        cout << left << setw(20) << sales[i].soldItemName << setw(10) << sales[i].soldItemId << sales[i].soldQuantity << endl;
    }

    cout << "\nMost Purchased Item: " << sales[mostSoldIndex].soldItemId << " (Quantity: " << sales[mostSoldIndex].soldQuantity << ")" << endl;
}

// Definitions of expense management functions
// Manage expense menu
void manageExpenses()
{
    system("cls");
    int choice;

    do
    {
        cout << "\n--- Daily Expense Management ---" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View All Expenses" << endl;
        cout << "3. Calculate Total Expenses" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addExpense();
            break;
        case 2:
            viewExpenses();
            break;
        case 3: 
            calculateTotalExpenses();
            break;
        case 4:
            cout << "Returning to Main Menu..." << endl;
            system("cls");
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    } while (choice != 4);
}

// Function to add expenses
void addExpense()
{
    if (expenseCount >= 100)
    {
        cout << "Expense list is full! You cannot add any more expenses." << endl;
        return;
    }

    Expense newExpense;

    cout << "\n--- Add Expense ---" << endl;
    cin.ignore();
    cout << "Enter Description of Expense: ";
    getline(cin, newExpense.expenseDescription);
    cout << "Enter Amount Spent: ";
    cin >> newExpense.expenseAmount;
    cin.ignore();
    cout << "Enter Date (dd mmm yyyy): ";
    getline(cin, newExpense.expenseDate);
    cout << "Expense added successfully!" << endl;

    expenses[expenseCount++] = newExpense;
}

// Function to view expenses
void viewExpenses()
{
    if (expenseCount == 0)
    {
        cout << "No expenses to display." << endl;
        return;
    }

    cout << "\n--- All Expenses ---" << endl;
    cout << left << setw(25) << "Description" << setw(10) << "Amount" << "Date" << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < expenseCount; i++)
    {
        cout << left << setw(25) << expenses[i].expenseDescription << setw(10) << expenses[i].expenseAmount << expenses[i].expenseDate << endl;
    }
}

// Function to calculate total expense
void calculateTotalExpenses()
{
    if (expenseCount == 0)
    {
        cout << "No expenses recorded to calculate total." << endl;
        return;
    }

    float total = 0.0;

    for (int i = 0; i < expenseCount; i++)
    {
        total += expenses[i].expenseAmount;
    }

    cout << "\n--- Total Expenses ---" << endl;
    cout << "Total Amount Spent: " << total << endl;
}