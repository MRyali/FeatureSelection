//
//  accuracy.h
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#ifndef accuracy_h
#define accuracy_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// function to find euclidean distance between two elements using their features
double Euclidean_Distance(vector<double>, vector<double>, vector<int>, bool, int);

// function for Leave_One_Out_Cross_Validation
double Leave_One_Out_Cross_Validation(vector<vector<double> >, vector<int>, bool, int);

#endif /* accuracy_h */
