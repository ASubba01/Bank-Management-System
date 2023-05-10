/*
Ashish Subba 5/6/2023 - The Bank Management System.
This system has 2 text file create using fstream: 
1. Hold user balance.
2. Hold information to print.
*/

#include <iostream>
#include <fstream> //for read and write files.
#include <string>
#include <ctime> //for current time.

using namespace std;
void menu(); //void function
void print();

//Bank class
class Bank {
private:
    double balance; //variable
public:

    //dafault constructor.
    Bank() {  
        balance = 0; //balance value
    }
   
    //deposit function
    void deposit(double amount) {   
        ofstream file("Balance.txt"); //open Balance.txt file. 
        balance += amount; 

        file << balance << endl; //write a balance in Balance.txt file.

        cout << "Deposit successful."<<endl;
        cout << "--------------------------------------" << endl;

        file.close(); //close file.
    }

    //withdraw function
    void withdraw(int amount) {
        double line;
        ifstream file("Balance.txt"); //reading from Balance.txt file.
        file >> line;
        
        //check wether withdraw amount is higher or less then total balance.
        if (line < amount) {
            cout << "Insufficient balance. Withdrawal failed." << endl;
            cout << "--------------------------------------" << endl;
        }
        else { 
            //write on balance.txt file
            ofstream file("Balance.txt"); 
            line = line - amount;
            file << line;
            cout << "Withdrawal successful."<< endl;
            cout << "--------------------------------------" << endl;           
        }
        file.close(); //file close;    
    }
    //display function.
    void display() {  
        ifstream file("Balance.txt"); //reading from Balance.txt file.
        double line;
        file >> line;
        cout << "Balance: " << line << endl;
        cout << "--------------------------------------" << endl;
        file.close();
    }
};

//main function.
int main() 
{
    char m;

    print();

 /* <--- Debug --->
    double b = 1000;
    ofstream file ("message.txt"); //open
    cout << "Enter an balance: ";
    cin >> b; 
    b += b;
    file << b; //put in;
    b += 20;
    cout << "Total: " << b << endl;
    file.close();
*/
    //start screem.
    cout << "\tBank Management System" << endl;
    cout << "\t----------------------" << endl;
    cout << "\t\tMenu" << endl;
    cout << "\t----------------------" << endl;
    
    menu(); //calling menu funcation.


    //loop unit user press 'm'.
    do {
        // Prompt user if they want to continue.
        cout << "Press Menu('M')/Quit('X')";
        cin >> m;
        cout << "\t----------------------" << endl;

        if (m == 'm' || m ==' M') {
            menu();
        }
        else if (m == 'x'|| m == 'X') {
            cout << "Thank you for using the bank management system!" << endl;
            // Use the exit() function to exit the program.
            exit(0);
        }
        else {
            // If the user input is neither 'm' nor 'x', display an error message.
            cout << "Invalid input! Please enter 'M' to continue or 'X' to quit." << endl;
        }
    } while (m == 'm' || m == 'M');


    system("pause");
    return 0;
}

//menu function
void menu() {
    Bank b;
    int choice;
    double amount;

    //diplay menu option.
    cout << "\t1. Deposit" << endl;
    cout << "\t2. Withdraw" << endl;
    cout << "\t3. Display balance" << endl;
    cout << "\t4. Print receipt" << endl;
    cout << "\t5. Exit" << endl;
    cout << "\tEnter your choice: ";
    cin >> choice;

    //promts a statement according to user input.
    switch (choice) {
    case 1:
        cout << "Enter amount to deposit: ";
        cin >> amount;
        b.deposit(amount); //pass deposit amount.
        break;
    case 2:
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        b.withdraw(amount); //pass withdraw amount.
        break;
    case 3:
        b.display(); //class display function.
        break;
    case 4:
        print(); //call printFile function
        break;
    case 5:
        cout << "Exiting program..." << endl; //exit if user press 5.
        break;
    default:
        cout << "Invalid choice. Try again." << endl; //default error message.
    }
}

//print function.
void print() {
    Bank b; //class bank.
    double line; //hold a value recieved from Balance.txt file.

    // Get the current time
    time_t now = time(nullptr);

    // Convert the current time to local time
    tm localTime;
    localtime_s(&localTime, &now);

    // Get the year, month, and day from the local time
    int year = localTime.tm_year + 1900;
    int month = localTime.tm_mon + 1;
    int day = localTime.tm_mday;

    // Format the time string
    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%I:%M:%S", &localTime);

    //open balance.txt file.
    ifstream file2("Balance.txt");
    file2 >> line; //declase file2 value equal to line;

    //write print.txt file.
    ofstream file("print.txt");
    if (file.is_open()) //if print.txt is open.
    {
        file << "The Bank Management System" <<
            "\n--------------------------------" <<
            "\nDate:\t\t" << month << "-" << day << "-" << year <<
            "\nTime:\t\t" << timeStr << 
            "\nTotal Balance:\t"<< line<<
            "\n\nThank you for using the bank management system."<<
            "\nFor question, call 1-234-567-8910."<< endl;
        file.close();
    }
    else {
        cout << "Unbale to open file";
    }
}

