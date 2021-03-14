//
//  main.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "accuracy.h"
#include "search.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Credit for opening file in c++ : https://www.cplusplus.com/doc/tutorial/files/
int main(int argc, const char * argv[]) {
    string fileName; // variable to store the name of the file
    string inputLine; // variable to store each line in file
    vector<vector<double>> dataSet; // set for features from file
    vector<double> dataLine; // set for each line fo features
    double val; // each individual feature

    int searchNum = 0; // variable to store feature selection search algorithm

    cout << "Welcome to Mayur Ryali's (862076991) Feature Selection Program." << endl;
    cout << " Enter the name of the file you want to test: ";

    cin >> fileName; // store user input for file name

    ifstream testFile(fileName); // open file
    if (testFile.is_open()) { // check if the file opened properly
        while (getline(testFile, inputLine)) {
            stringstream lStream(inputLine);
            while(lStream >> val) {
                dataLine.push_back(val); // store entire line of features
            }
            dataSet.push_back(dataLine); // store entire line
        }
        testFile.close(); //close file after reading
    }
    else {
        cout << "Error. Unable to open test file." << endl;
        return 0; // end program upon reaching error of not opening file
    }

    cout << "Enter your choice of algorithm: " << endl;
    cout << "(1) Forward Selection" << endl;
    cout << "(2) Backward Elimination" << endl;

    // repeat until proper inputn is given
    while (searchNum != 1 || searchNum != 2) {
        cin >> searchNum; // user input for search algorithm
    }

    cout << "Beginning search: " << endl << endl;

    if (searchNum == 1) {
        Forward_Search(dataSet);
    }
    else if (searchNum == 2) {
        Backward_Elimination(dataSet);
    }
    else {
        cout << "Error. Invalid input." << endl;
    }

    return 0;
}
