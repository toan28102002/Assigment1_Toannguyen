#include <iostream>
#include "data_operations.h"

using namespace std; // Add this line to use the std namespace

int main() {
    vector<vector<int>> data = readDataFromFile("data.txt"); // We read data from a file and store it in 'data'.

    if (data.empty()) {
        return 1; // If we couldn't read data, we return 1 to indicate an error.
    }

    int choice;
    do {
        // Display a menu for the user to choose from.
        cout << "1. Check if an integer exists and get its index" << endl;
        cout << "2. Modify the value of an integer" << endl;
        cout << "3. Add a new integer to the end" << endl;
        cout << "4. Replace or remove an integer" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice; // We get the user's choice.

        switch (choice) {
        case 1: { // If the user chooses option 1:
            int target, rowIndex, colIndex;
            cout << "Enter the integer to search for: ";
            cin >> target; // We ask for the number to find.

            // We call the 'findInteger' function to search for the number.
            if (findInteger(data, target, rowIndex, colIndex)) {
                cout << "Integer " << target << " found at index (" << rowIndex << ", " << colIndex << ")." << endl;
            }
            else {
                cout << "Integer " << target << " not found in the array." << endl;
            }
            break;
        }
        case 2: { // If the user chooses option 2:
            int rowIndex, colIndex, newValue, oldValue;
            cout << "Enter the row index: ";
            cin >> rowIndex; // We ask for the row index.
            cout << "Enter the column index: ";
            cin >> colIndex; // We ask for the column index.
            cout << "Enter the new value: ";
            cin >> newValue; // We ask for the new number.

            // We call the 'modifyInteger' function to change a number.
            if (modifyInteger(data, rowIndex, colIndex, newValue, oldValue) != -1) {
                cout << "Old value: " << oldValue << ", New value: " << newValue << endl;

                // We update the file with the new data.
                writeDataToFile("data.txt", data);
                cout << "File updated with the modified data." << endl;
            }
            else {
                cout << "Invalid indices. Modification failed." << endl;
            }
            break;
        }
        case 3: { // If the user chooses option 3:
            int newValue;
            cout << "Enter the new integer to add: ";
            cin >> newValue; // We ask for the new number.

            // We call the 'addInteger' function to add the new number.
            addInteger(data, newValue);

            // We update the file with the new data.
            writeDataToFile("data.txt", data);
            cout << "File updated with the new data." << endl;
            break;
        }
        case 4: { // If the user chooses option 4:
            int rowIndex, colIndex, newValue;
            cout << "Enter the row index: ";
            cin >> rowIndex; // We ask for the row index.
            cout << "Enter the column index: ";
            cin >> colIndex; // We ask for the column index.
            cout << "Enter the new value (enter 0 to remove): ";
            cin >> newValue; // We ask for the new number.

            // We call the 'replaceOrRemove' function to change or remove a number.
            replaceOrRemove(data, rowIndex, colIndex, newValue);

            // We update the file with the new data.
            writeDataToFile("data.txt", data);
            cout << "File updated with the modified data." << endl;
            break;
        }
        case 0: // If the user chooses option 0:
            cout << "Goodbye!" << endl; // We say goodbye and exit the program.
            break;
        default: // If the user enters an invalid choice:
            cout << "Invalid choice. Please try again." << endl; // We tell them to try again.
        }
    } while (choice != 0); // We keep doing this until the user chooses to quit.

    return 0; // We exit the program, indicating success.
