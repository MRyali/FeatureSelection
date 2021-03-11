//
//  accuracy.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "accuracy.h"

using namespace std;

// function to find euclidean distance between two elements using their features
// Euclidean formula: https://www.geeksforgeeks.org/program-calculate-distance-two-points/
double Euclidean_Distance(vector<double> vecA, <vector<double> vecB, vector<int> currFeatures) {
    double distance = 0;

    for(int i = 0; i < currSet.size(); i++) {
        distance += (pow(vecA.at(currFeatures.at(i)) - vecB.at(currFeatures.at(i)), 2));
    }
    return sqrt(distance);
}
// function for Leave_ One_Out_Cross_Validation
double Leave_One_Out_Cross_Validation(vector<vector<double>> dataSet, vector<int> currFeatures) {
    // write codde
}
