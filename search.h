//
//  search.h
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#ifndef search_h
#define search_h

#include "accuracy.h"

#include <vector>
#include <iostream>

using namespace std;

// function to check if feature is already in current set. Used in Forward and Backward functions
bool feature_Is_In(vector<int>, int);

// function for forward search
// Start with an empty set of features and see how well adding a feature makes
// Crdit: Adopted form Dr. Keogh's Project 2 video
void ForwardSearch(vector<vector<double> >);

// function for backward elimination
// Start with a set of all features and see how much better removing a feature would make your result
// Credit: Adopted from Dr. Keough's Project 2 video
void BackwardsElimination(vector<vector<double> >);

// function to remove features
// used in Backward_Elimination
// Credit: https://www.cplusplus.com/reference/vector/vector/erase/
vector<int> Remove_Feature(vector<int>, int);

#endif /* search_h */
