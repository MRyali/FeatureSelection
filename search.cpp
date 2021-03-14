//
//  search.cpp
//  FeatureSelection
//
//  Created by Mayur Ryali on 3/10/21.
//

#include "search.h"

using namespace std;

// function to check if feature is already in current set. Used in Forward and Backward functions
bool feature_Is_In(vector<int> currSet, int num) {
    for (int i = 0; i < currSet.size(); i++) {
        if (currSet.at(i) == num) { // feature exists in current set
            return true;
        }
    }
    return false; //feature was not found in current set
}
// function for forward search
// Crddit: Adopted form Dr. Keogh's Project 2 video
vector<int> Forward_Search(vector<vector<double>> dataSet) {
    vector<int> currFeatures; // initialize an empty
    double totalAccuracy = 0;
    double accuracy = 0;

    for(int i = 1; i < dataSet.at(0).size(); i++) {
        vector<int> featureToAdd; // feature to add at this level
        int featureToAdd;
        double best_so_far_accuracy = 0;

        for (int k = 1; k < dataSet.at(0).size(); k++) {
            cout << "Consider adding the feature(s): {"
            if (!feature_Is_In(currFeatures, k)) { //only consider adding if not already added
                for(int j = 0; j < currFeatures; j++) { // display features
                    cout << currFeatures.at(j) << ",";
                }
                cout << k << "}. Accuracy is: ";
            }
            accuracy = Leave_One_Out_Cross_Validation(dataSet, currFeatures)
        }
    }


}
// function for backward elimination
void Backward_Elimination(vector<vector<double>>);
// function to remove features to allow for us to progress through the iteration
// used in Backward_Elimination
vector<int> Remove_Feature(vector<int>, int);
