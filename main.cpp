#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> readMaze(string filename) {
    // Open the text file
    ifstream inputFile(filename);
    
    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        exit;
    }
    
    // Define a vector of vectors to store the content of the file
    vector<vector<char>> matrix;
    
    // Read the content of the file and store it in the matrix
    string line;
    while (getline(inputFile, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        if (!row.empty()) { // Check if the row is not empty
            matrix.push_back(row);
        }
    }
    
    // Close the file
    inputFile.close();

    return matrix;
}

void printMaze(vector<vector<char>> maze) {
    // Print the matrix
    for (const auto& row : maze) {
        for (char element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    string filename = "maze.txt";
    vector<vector<char>> maze = readMaze(filename);
    printMaze(maze);
    return 0;
}
