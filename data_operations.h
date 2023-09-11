#ifndef DATA_OPERATIONS_H
#define DATA_OPERATIONS_H

#include <vector>   // Include the vector header to work with vectors.
#include <string>   // Include the string header for string manipulation.

// Function to read data from a file and store it in a 2D vector.
std::vector<std::vector<int>> readDataFromFile(const std::string& filename);

// Function to write data from a 2D vector to a file.
void writeDataToFile(const std::string& filename, const std::vector<std::vector<int>>& data);

// Function to find an integer in the 2D vector and get its position.
int findInteger(const std::vector<std::vector<int>>& data, int target, int& rowIndex, int& colIndex);

// Function to modify an integer in the 2D vector at a specific position.
int modifyInteger(std::vector<std::vector<int>>& data, int rowIndex, int colIndex, int newValue, int& oldValue);

// Function to add a new integer to the end of the 2D vector.
void addInteger(std::vector<std::vector<int>>& data, int newValue);

// Function to replace or remove an integer at a specific position in the 2D vector.z
void replaceOrRemove(std::vector<std::vector<int>>& data, int rowIndex, int colIndex, int newValue);

#endif // DATA_OPERATIONS_H
