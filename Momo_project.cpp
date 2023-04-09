#include <iostream>

using namespace std;

// Default pin and balance
int default_pin = 0000;
int default_balance = 1000;

// Function for checking the user balance
void check_balance(int balance) {
  cout << "Your balance is: " << balance << endl;
}

// Function for resetting/changing the user pin
void reset_pin(int& pin) {
  int new_pin;
  cout << "Enter new pin: ";
  cin >> new_pin;
  pin = new_pin;
  cout << "Pin has been updated to: " << pin << endl;
}

// Function for exiting the program
void exit_program() {
  cout << "Thanks for using our Mobile Money Service. Goodbye!" << endl;
  exit(0);
}

// Function for authenticating the user
bool authenticate(int& remaining_attempts) {
  int pin;
  cout << "Enter your pin: ";
  cin >> pin;
  if (pin == default_pin) {
    return true;
  }
  else {
    remaining_attempts--;
    if (remaining_attempts == 0) {
      cout << "Maximum number of attempts reached. Goodbye!" << endl;
      exit(1);
    }
    else {
      cout << "Incorrect pin. You have " << remaining_attempts << " attempts left." << endl;
      return false;
    }
  }
}

// Function for sending money to another account
void send_money(int& balance) {
  int amount;
  cout << "Enter amount: ";
  cin >> amount;
  if (amount <= balance) {
    balance -= amount;
    cout << "You have sent " << amount << " to the receiver. Your new balance is " << balance << endl;
  }
  else {
    cout << "Not enough balance." << endl;
  }
}

int main() {
  int choice;
  int remaining_attempts = 3;
  int balance = default_balance;
  
  while (true) {
    cout << "Welcome to Mobile Money Service! Please select an option:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Send Money" << endl;
    cout << "3. Reset/Change Pin" << endl;
    cout << "4. Exit" << endl;

    cin >> choice;
    switch(choice) {
      case 1:
        if (authenticate(remaining_attempts)) {
          check_balance(balance);
        }
        break;
      case 2:
        if (authenticate(remaining_attempts)) {
          send_money(balance);
        }
        break;
      case 3:
        if (authenticate(remaining_attempts)) {
          reset_pin(default_pin);
        }
        break;
      case 4:
        exit_program();
      default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }
  }

  return 0;
}