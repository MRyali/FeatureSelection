//
//  accuracy.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "accuracy.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// function to find euclidean distance between two elements using their features
// Euclidean formula: https://www.geeksforgeeks.org/program-calculate-distance-two-points/
double Euclidean_Distance(vector<double> vecA, vector<double> vecB, vector<int> currFeatures) {
    double distance = 0;

    for(int i = 0; i < currFeatures.size(); i++) {
        distance += (pow(vecA.at(currFeatures.at(i)) - vecB.at(currFeatures.at(i)), 2));
    }
    return sqrt(distance);
}
// function for Leave_ One_Out_Cross_Validation
// Credit: Adopted from Dr. Keogh's Slides on cross validation
double Leave_One_Out_Cross_Validation(vector<vector<double>> dataSet, vector<int> currFeatures) {
    // number of instances in data
    double instances = (double)dataSet.size();
    // number of correct classifications
    double correct = 0;

    for(int i = 0; i < dataSet.size(); i++) {
        vector<double> testData = dataSet.at(i);
        double nn_dist = INT_MAX; // distance to nearest neighbor
        int nn_location = INT_MAX; // location of nearest neighbor
        vector<double> nn_neighbor; // nearest neighbor

        // find nearest neighbors
        for (int k = 0; k < dataSet.size(); k++) {
            // find distance between test and current data
            if (k != i) {
                double distance = Euclidean_Distance(testData, dataSet.at(k), currFeatures);
                if (distance < nn_dist) { // found new nearest neighbor
                    nn_dist = distance;
                    nn_location = k;
                    nn_neighbor = dataSet.at(k);
                }
            }
        }

        // check for correct classifications among nearest neighbors
        if (nn_neighbor.at(0) == 1 && testData.at(0) == 1) {
            correct += 1;
        }
        else if (nn_neighbor.at(0) == 2 && testData.at(0) == 2) {
            correct += 1;
        }
    }
    // calculate accuracy
    return correct / instances;
}
