#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//-------------------------------------
// FUNCTION PROTOTYPES
//-------------------------------------

void drawLine(int n, char symbol);
void rules();

//-------------------------------------
// MAIN ENTRY POINT
//-------------------------------------

int main()
{
    //-------------------------------------
    // VARIABLE DECLARATIONS
    //-------------------------------------

    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;

    //-------------------------------------
    // INPUT PHASE
    //-------------------------------------

    // Seed the random generator.
    srand(time(0));

    // Call function to draw line.
    drawLine(60,'-');

    // Print title.
    cout << "\n\n\n\t\tJackpot Number Quest\n";
    cout << "\t\t Unleash Your Luck!\n\n\n";

    // Call function to draw line.
    drawLine(60,'-');

    // Prompt user to enter name.
    cout << "\n\n\tEnter Your Name : ";

    // Retrieve input from user.
    getline(cin, playerName);

    // Prompt user to enter amount to deposit.
    cout << "\n\n\tDeposit Currency : $";

    // Retrieve deposit amount.
    cin >> amount;

    //-------------------------------------
    // PROCESSING & OUTPUT PHASE
    //-------------------------------------

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";

		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);

		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! Should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }

        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
        } else {
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> choice;
        }
    }while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');

    return 0;
}

//-------------------------------------
// FUNCTION DEFINITIONS
//-------------------------------------

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
    {
        cout << symbol;
    }
    cout << "\n";
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

//-------------------------------------
// END OF FILE
//-------------------------------------
