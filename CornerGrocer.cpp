// CornerGrocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Function to read the input file and store item frequencies in a map
map<string, int> ReadFrequencies(const string& filename) {
    map<string, int> itemFrequencies; // Map to store item frequencies
    ifstream inputFile(filename); // Open the input file
    string item;

    // Check if the file is open
    if (inputFile.is_open()) {
        // Read items from the file and update their frequencies in the map
        while (inputFile >> item) {
            itemFrequencies[item]++;
        }
        inputFile.close(); // Close the file
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }

    return itemFrequencies; // Return the map with item frequencies
}

// Function to get the frequency of a specific item from the map
void GetItemFrequency(const map<string, int>& itemFrequencies) {
    string item;
    cout << "\nEnter the item you wish to look for: ";
    cin >> item;

    auto it = itemFrequencies.find(item); // Find the item in the map
    // Check if the item is found
    if (it != itemFrequencies.end()) {
        cout << "Frequency of " << item << ": " << it->second << endl;
    }
    else {
        cout << "Item not found." << endl;
    }
    cout << endl; // Add spacing after displaying the result
}

// Function to print all item frequencies
void PrintAllFrequencies(const map<string, int>& itemFrequencies) {
    cout << endl; // Add spacing before displaying the frequencies
    // Iterate through the map and print each item and its frequency
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl; // Add spacing after displaying the frequencies
}

// Function to print a histogram of item frequencies
void PrintHistogram(const map<string, int>& itemFrequencies) {
    cout << endl; // Add spacing before displaying the histogram
    // Iterate through the map and print each item with asterisks representing its frequency
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl; // Add spacing after displaying the histogram
}

// Function to write item frequencies to a file
void WriteFrequenciesToFile(const map<string, int>& itemFrequencies, const string& filename) {
    ofstream outputFile(filename); // Open the output file
    // Check if the file is open
    if (outputFile.is_open()) {
        // Write each item and its frequency to the file
        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close(); // Close the file
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    string inputFilename = "CS210_Project_Three_Input_File.txt"; // Input file name
    // Read item frequencies from the input file
    map<string, int> itemFrequencies = ReadFrequencies(inputFilename);

    // Write frequencies to frequency.dat file for backup
    string outputFilename = "frequency.dat"; // Output file name
    WriteFrequenciesToFile(itemFrequencies, outputFilename);

    int choice;
    // Main menu loop
    do {
        // Display menu options
        cout << "Menu Options:\n";
        cout << "1. Look up frequency of a specific item\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram of item frequencies\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl; // Add spacing after user input

        // Handle menu choice
        switch (choice) {
        case 1:
            GetItemFrequency(itemFrequencies); // Get frequency of a specific item
            break;
        case 2:
            PrintAllFrequencies(itemFrequencies); // Print all item frequencies
            break;
        case 3:
            PrintHistogram(itemFrequencies); // Print histogram of item frequencies
            break;
        case 4:
            cout << "Exiting program.\n"; // Exit the program
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Handle invalid menu choice
        }
        cout << endl; // Add spacing before displaying the menu again
    } while (choice != 4); // Repeat until the user chooses to exit

    return 0;
}