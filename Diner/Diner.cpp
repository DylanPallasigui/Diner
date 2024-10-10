#include <iostream>
#include <iomanip>
using namespace std;

// Declare menu item prices here as const floats 
const float moonRockBurgerPrice = 3.00;
const float meteorPizzaPrice = 8.00;
const float quantumTacosPrice = 4.50;
const float nebulaNachosPrice = 5.00;

const float supernovaSodaPrice = 1.50;
const float spacedustSeltzerPrice = 2.50;
const float antigravityCocktailPrice = 4.00;
const float waterPrice = 0.50;

const float zeroGravitySteakPrice = 8.00;
const float antimatterPastaPrice = 5.50;
const float blackHoleMedleyPrice = 10.00;
const float saladPrice = 5.00;

const char LUNCH = 'L';
const char DINNER = 'D';


// Name: AddMore
// Parameters: None
// Return: bool, true if they want to add to their order, otherwise false
// Ask user whether or not they want to add more to current order
bool AddMore()
{
    char more;
    cout << "Would you like to add more?\n";
    cout << "Enter y for yes and n for no.\n";
    cin >> more;
    if (more == 'y') {
        return true;
    } else if (more == 'n'){
        return false;
    } else {
        cout << "Invalid input\n";
    }
    return 0;
}

// Name: AddFoodCost
// Parameters: const char menuType, const int foodChoice, float &cost
// Return: void 
// Take in the menu type (lunch or dinner) and the menu item
// Using one or more switch statements, set cost to the cost of menu item 
void AddFoodCost(const char menuType, const int foodchoice, float &cost)
{
    if (menuType == 'L'||'l') {
        switch(foodchoice){
            case 1:
            cost = cost + 3.00;
            case 2:
            cost = cost + 8.00;
            case 3:
            cost = cost + 4.50;
            case 4:
            cost = cost + 5.00;
        }
    } else if (menuType == 'D'||'d') {
        switch(foodchoice) {
            case 5:
            cost = cost + 8.00;
            case 6:
            cost = cost + 5.50;
            case 7:
            cost = cost + 10.00;
            case 8:
            cost = cost + 5.00;
        }
    } else {
        cout << "Invalid input\n";
    }
}

// Name: AddDrinkCost
// Parameters: const int drinkChoice
// Return: float
// Using a switch statement, set the cost of drink item in a local variable and return it
float AddDrinkCost(const int drinkChoice)
{
    float drinkCost;
    switch(drinkChoice) {
        case 1:
        drinkCost = drinkCost + 1.50;
        case 2:
        drinkCost = drinkCost + 2.50;
        case 3:
        drinkCost = drinkCost + 4.00;
        case 4:
        drinkCost = drinkCost + 0.50;
    }
    
    return drinkCost;
}

// Name: GetLunch
// Parameters: float &foodCost
// Return: None
// Prompt user with lunch menu and store their food selection in a local variable.
// Call AddFoodCost with the menuType (LUNCH), foodChoice, and foodCost to get the
// foodCost updated
void GetLunch(float &foodCost)
{
    int foodChoice;
    cout << "\nHere are our out of the world lunch options!\n";
    cout << "1) Moon Rock Burger    $3.00\n"
         << "2) Meteor Pizza        $8.00\n"
         << "3) Quantum Tacos       $4.50\n"
         << "4) Nebula Nachos       $5.00\n"
         << "0) No meal\n\n";

    cout << "Enter your food choice: ";
    cin >> foodChoice;

    AddFoodCost(LUNCH, foodChoice, foodCost);
}

// Name: GetDinner
// Parameters: float &foodCost
// Return: None
// Prompt user with dinner menu and store their food selection in a local variable.
// Call AddFoodCost with the menuType (DINNER), foodChoice, and foodCost to get the
// foodCost updated
void GetDinner(float &foodcost)
{
    int foodchoice;
    cout << "\nHere are our out of the world dinner options!\n";
    cout << "5) Zero Gravity Steak      $8.00\n";
    cout << "6) Anti Matter Pasta       $5.00\n";
    cout << "7) Black Hole Medley       $10.00\n";
    cout << "8) Salad                   $5.00\n";
    cout << "0) No meal\n\n";

    cout << "Enter your food choice: ";
    cin >> foodchoice;

    //AddFoodCost(LUNCH, foodChoice, foodCost);
    AddFoodCost(DINNER, foodchoice, foodcost);
}

// Name: GetDrink
// Parameters: None
// Return: drink selection
// Prompt user with drink menu and store their selection in a local variable
int GetDrink()
{
    int drinkchoice;
    cout << "\nHere are our out of the world drink options!\n";
    cout << "1) Supernova Soda          $1.50\n";
    cout << "2) Spacedust Seltzer       $2.50\n";
    cout << "3) Antigravity Cocktail    $4.00\n";
    cout << "4) Water                   $0.50\n";
    cout << "0) No drink\n\n";

    cout << "Enter your food choice: ";
    cin >> drinkchoice;
    
    return drinkchoice;
}

// Name: GetValidMenuType
// Parameters: None
// Return: char for menu (either 'L'/'l' for lunch, or 'D'/'d' for dinner)
// Prompt user with with menu they want, lunch or dinner and return the value
char GetValidMenuType()
{
    char menuChoice;
    cout << "What type of menu would you like, lunch or dinner?\n\n";
    cout << "Enter L or l for lunch or D or d for dinner.\n\n";
    
    if (menuChoice == 'L' || 'l'){
        return LUNCH;
    } else if (menuChoice == 'D' || 'd'){
        return DINNER;
    } else {
        cout << "Invalid input\n";
    }
    return menuChoice;
}

// Name: IsLunch
// Parameters: const char menuType
// Return: true or false
// Checks whether or not the menuType is lunch or dinner
bool IsLunch(const char menuType)
{
    if (menuType == 'L'||'l') {
        return true;
    } else if (menuType == 'D'||'d'){
        return false;
    } else {
        cout << "Invalid input";
    }
}

// Name: GetTip
// Parameters: const float mealCost
// Return: tip amount
// Prompt user for a tip percentage as a decimal value. Calculate tip amount 
// (tip percentage * mealCost) and return it
float GetTip(const float mealCost)
{
    cout << "What percent would you like to tip?\n";
    float tip;
    cin >> tip;
    tip = mealCost * tip / 100;
    return tip;
}

// Name: PrintBill
// Parameters: const float mealCost, const float tipAmount
// Return: None
// Print out the amount of the meal, the amount of the tip, and the
// total amount that the customer owes
void PrintBill(const float mealCost, const float tipAmount)
{
    cout << "\nThank you for coming to MyRestaurant! Your meal cost is: $" 
        << setprecision(2) << fixed << mealCost << endl
        << "Thank you for your tip of $" << tipAmount << endl
        << "Your total bill is: $" << mealCost+tipAmount << endl;
}

int main()
{
    float tipAmount = 0.00;
    float mealCost = 0.00;
    char menuType;
    int drinkChoice = 0;
    
    // prompt user for a valid menu type (lunch or dinner)
    menuType = GetValidMenuType(); 

    // while user wants to add more items, prompt for food items
    do{
        // If menu chosen is lunch, show lunch menu and get cost value
        // else, show dinner menu and set cost of the food
        if (IsLunch(menuType))
        {
            GetLunch(mealCost);
        }
        else
        {
            GetDinner(mealCost);
        }

        // show drink menu and add drink costs
        drinkChoice = GetDrink();
        mealCost = mealCost + AddDrinkCost(drinkChoice);
    }while(AddMore());


    // calculate tip and then print bill
    tipAmount = GetTip(mealCost);

    PrintBill(mealCost, tipAmount);
    return 0;
}