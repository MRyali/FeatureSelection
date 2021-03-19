//
//  main.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "search.cpp"
#include "accuracy.cpp"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Credit for opening file in c++ : https://www.cplusplus.com/doc/tutorial/files/
int main(int argc, const char * argv[]) {
    string fileName; // variable to store the name of the file
    string inputLine; // variable to store each line in file
    vector<vector<double> > dataSet; // set for features from file

    int searchNum = 0; // variable to store feature selection search algorithm

    cout << "Welcome to Mayur Ryali's (862076991) Feature Selection Program." << endl;
    cout << " Enter the name of the file you want to test: ";

    cin >> fileName; // store user input for file name

    // hard coded input
    //ifstream testFile("/Users/mayurryali/Downloads/CS170_largetestdata_72.txt"); // open file

    ifstream testFile(fileName);

    if (testFile.is_open()) { // check if the file opened properly
        while (getline(testFile, inputLine)) {
            vector<double> dataLine; // set for each line of features
            stringstream lStream(inputLine);
            double val; // each individual feature
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
    while (searchNum != 1 && searchNum != 2) {
        cin >> searchNum; // user input for search algorithm
    }

    // print total features and instances in the set
    cout << endl << "This dataset has " << dataSet.at(0).size() - 1 << " features (not including the class attribute), with " << dataSet.size() << " instances." << endl << endl;

    // print accuracy of running nearest neighbor on all features
    vector<int> temp;
    for(int i = 1; i < dataSet.at(0).size(); i++) {
        temp.push_back(i);
    }
    cout << "Running nearest neighbor with all " << dataSet.at(0).size() - 1 << " features, using “leaving-one-out” evaluation, I get an accuracy of " << Leave_One_Out_Cross_Validation(dataSet, temp, false, 1) * 100 << "%." << endl << endl;

    // begin search algorithm
    cout << "Beginning search: " << endl << endl;

    if (searchNum == 1) {
        ForwardSearch(dataSet);
    }
    else if (searchNum == 2) {
        BackwardsElimination(dataSet);
    }
    else {
        cout << "Error. Invalid input." << endl;
    }

    return 0;
}
