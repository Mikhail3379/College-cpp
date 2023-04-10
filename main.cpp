//
//  main.cpp
//  cpp
//
//  Created by Mikhail Bakushev on 10/04/2023.
//

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

void menu(string name);
void string_function();
void number_function();
string create_name(string username);

int main() {
    string name;
    cout << "Please enter your name: ";
    getline(cin, name);
    do {
        menu(name);
    } while (true);
    return 0;
}

void menu(string name) {
    int choice;
    cout << "Welcome " << name << ", this is the main menu." << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Generate username" << endl;
    cout << "2. Calculate factorial" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            string_function();
            break;
        case 2:
            number_function();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.clear(); // Clearing cin error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
    }
}

void string_function() {
    string user;
    cout << "Welcome to option 1." << endl;
    cout << "Please enter your first and last name: ";
    getline(cin >> ws, user);
    if (user.find(" ") != string::npos) { // Check if there is a space in the input
        string username = create_name(user);
        cout << "Your username is: " << username << endl;
    } else {
        cout << "Invalid input. Please enter your first and last name separated by a space." << endl;
    }
}

void number_function() {
    int number, count = 1, factorial = 1;
    cout << "Welcome to option 2." << endl;
    while (true) {
        cout << "Please enter a positive whole number greater than 0: ";
        double input;
        cin >> input;
        if (cin.fail() || input <= 0 || floor(input) != input) { // Check if input is positive whole number
            cin.clear(); // Clearing cin error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
            cout << "Invalid input. Please enter a positive whole number greater than 0." << endl;
        } else {
            number = static_cast<int>(input);
            cout << "Calculating factorial..." << endl;
            while (count <= number) {
                factorial *= count;
                cout << count;
                if (count < number) {
                    cout << "x";
                }
                count++;
            }
            cout << " = " << factorial << endl;
            break;
        }
    }
}




string create_name(string username) {
    string string1, string2;
    string1 = toupper(username[0]); // Convert the first character to uppercase
    unsigned long pos = username.find(" ");
    if (pos != string::npos) {  // Check if there is a space in the input string
        string2 = username.substr(pos + 1);
        pos = string2.find(" ");  // Find the next space after the first name
        if (pos != string::npos) {  // Check if there is a second space in the input string
            string2 = string2.substr(0, pos);  // Use only the first two words
        }
        string2[0] = toupper(string2[0]); // Convert the first character of the last name to uppercase
    }
    return string1 + string2;
}
