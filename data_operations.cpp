#include "data_operations.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std; 

/// This function reads data from a file and stores it in a 2D vector.
std::vector<std::vector<int>> readDataFromFile(const std::string& filename) {
    ifstream file(filename);  // We open the file for reading.
    std::vector<std::vector<int>> data;  // This is where we'll store the data.

    if (!file.is_open()) {  // If we couldn't open the file:
        cerr << "Failed to open the file: " << filename << endl;  // Print an error message.
        return data;  // Return an empty data vector.
    }

    int value;
    for (int i = 0; i < 10; i++) {  // We read 10 rows of data.
        std::vector<int> row;
        for (int j = 0; j < 10; j++) {  // In each row, we read 10 integers.
            if (file >> value) {
                row.push_back(value);  // We add each integer to the row.
            }
            else {
                cerr << "Error reading data from the file." << endl;  // Print an error message.
                file.close();  // Close the file.
                return data;  // Return whatever data we have (might be incomplete).
            }
        }
        data.push_back(row);  // We add the row to our 2D data vector.
    }

    file.close();  // We're done with the file, so we close it.
    return data;   // We return the complete data.
}

// This function writes data from a 2D vector to a file.
void writeDataToFile(const std::string& filename, const std::vector<std::vector<int>>& data) {
    ofstream file(filename);  // We open the file for writing.

    if (!file.is_open()) {  // If we couldn't open the file:
        cerr << "Failed to open the file for writing: " << filename << endl;  // Print an error message.
        return;
    }

    for (const std::vector<int>& row : data) {  // For each row of data:
        for (int value : row) {  // For each integer in the row:
            file << value << ' ';  // Write the integer followed by a space.
        }
        file << '\n';  // After each row, we add a newline character.
    }

    file.close();  // We're done writing, so we close the file.
}

// This function checks if an integer exists in the 2D vector and gets its index.
int findInteger(const std::vector<std::vector<int>>& data, int target, int& rowIndex, int& colIndex) {
    for (int i = 0; i < data.size(); i++) {  // We go through each row.
        for (int j = 0; j < data[i].size(); j++) {  // We go through each column in the row.
            if (data[i][j] == target) {  // If we find the target integer:
                rowIndex = i + 1;  // We record its row index (starting from 1).
                colIndex = j + 1;  // We record its column index (starting from 1).
                return 1;  // We return 1 to indicate that we found it.
            }
        }
    }
    return 0;  // If we didn't find the integer, we return 0.
}

// This function modifies an integer in the 2D vector at a specific position.
int modifyInteger(std::vector<std::vector<int>>& data, int rowIndex, int colIndex, int newValue, int& oldValue) {
    try {
        // Adjust indices to start at 0 (because our data is 0-based).
        rowIndex--;
        colIndex--;

        if (rowIndex >= 0 && rowIndex < data.size() && colIndex >= 0 && colIndex < data[rowIndex].size()) {
            oldValue = data[rowIndex][colIndex];  // We record the old value.
            data[rowIndex][colIndex] = newValue;  // We update the data with the new value.

            // Update the file with the new data.
            writeDataToFile("data.txt", data);
            return data[rowIndex][colIndex];  // We return the new value.
        }
        else {
            oldValue = -1;  // Indicate that the modification failed.
            return -1;      // Indicate that the modification failed.
        }
    }
    catch (const std::exception& ex) {
        cerr << "An error occurred while modifying the integer: " << ex.what() << endl;
        return -1;  // Indicate that the modification failed.
    }
}


void addInteger(std::vector<std::vector<int>>& data, int newValue) {
    try {
        data.back().push_back(newValue);
        // Update the file with the new data
        writeDataToFile("data.txt", data);
    }
    catch (const std::exception& ex) {
        cerr << "An error occurred while adding the new integer: " << ex.what() << endl;
    }
}

void replaceOrRemove(std::vector<std::vector<int>>& data, int rowIndex, int colIndex, int newValue) {
    try {
        // Adjust indices to start from 0-based indexing
        rowIndex--; // Decrement row index by 1
        colIndex--; // Decrement column index by 1

        if (rowIndex >= 0 && rowIndex < data.size()) {
            if (colIndex >= 0 && colIndex < data[rowIndex].size()) {
                if (newValue == 0) {
                    data[rowIndex].erase(data[rowIndex].begin() + colIndex);
                }
                else {
                    data[rowIndex][colIndex] = newValue;
                }
                // Update the file with the new data
                writeDataToFile("data.txt", data);
            }
            else {
                throw std::out_of_range("Column index out of range.");
            }
        }
        else {
            throw std::out_of_range("Row index out of range.");
        }
    }
    catch (const std::exception& ex) {
        cerr << "An error occurred while replacing or removing the integer: " << ex.what() << endl;
    }
}
