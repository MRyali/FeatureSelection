//
//  search.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "search.h"

using namespace std;

// function to check if feature is already in current set. Used in Forward and Backward functions
bool featue_Is_In(vector<int> currSet, int num) {
    for (int i = 0; i < currSet.size(); i++) {
        if (currSet.at(i) == num) { // feature exists in current set
            return true;
        }
    }
    return false; //feature was not found in current set
}
// function for forward search
vector<int> Forward_Search(vector<vector<double>>);
// function for backward elimination
void Backward_Elimination(vector<vector<double>>);
// function to remove features to allow for us to progress through the iteration
// used in Backward_Elimination
vector<int> Remove_Feature(vector<int>, int);
