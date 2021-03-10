//
//  search.h
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#ifndef search_h
#define search_h

#include "accuracy.h"

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

// function to check if feature is already in current set. Used in Forward and Backward functions
bool featue_Is_In(vector<int>, int);
// function for forward search
vector<int> Forward_Search(vector<vector<double>>);
// function for backward elimination
void Backward_Elimination(vector<vector<double>>);
// function to remove features to allow for us to progress through the iteration
// used in Backward_Elimination
vector<int> Remove_Feature(vector<int>, int);

#endif /* search_h */
