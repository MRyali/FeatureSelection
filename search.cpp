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
// Start with an empty set of features and see how well adding a feature makes
// Crdit: Adopted form Dr. Keogh's Project 2 video
vector<int> Forward_Search(vector<vector<double>> dataSet) {
    vector<int> currFeatures; // initialize an empty set
    vector<int> bestFeatures; // initialize set to hold best features
    double totalAccuracy = 0;
    double accuracy = 0;

    for(int i = 1; i < dataSet.at(0).size(); i++) {
        vector<int> featureToAdd; // feature to add at this level
        int featureToAdd;
        double best_so_far_accuracy = 0; // best accuracy so far (from Project video)

        for (int k = 1; k < dataSet.at(0).size(); k++) {
            cout << "Consider adding the feature(s): {"
            if (!feature_Is_In(currFeatures, k)) { //only consider adding if not already added
                for(int j = 0; j < currFeatures; j++) { // display features
                    cout << currFeatures.at(j) << ",";
                }
                cout << k << "}. Accuracy is: ";

                accuracy = Leave_One_Out_Cross_Validation(dataSet, currFeatures);
                cout << accuracy << endl; // print accuracy_h
                if (accuracy > best_so_far_accuracy) {
                    best_so_far_accuracy = accuracy; // best new best accuracy
                    featureToAdd = k; // best feature to add
                }
            }
        }
        // finding best total accuracy and features
        currFeatures.push_back(featureToAdd); // add best features
        if (best_so_far_accuracy > totalAccuracy) {
            totalAccuracy = best_so_far_accuracy; // store adbsolute best accuracy_h
            bestFeatures = currFeatures; // store the best features
        }
        else { // if the accuracy is not better then it must be equal or worse so we warn. output frome sample project template
            cout << "(Warning, Accuracy has decreased! Continuing search in case of local maxima)" << endl;
            cout << "Feature set {";
            for (int i = 0; i < currFeatures.size(); i++) {
                cout << currFeatures.at(i) << ", ";
            }
            cout << "} was best, accuracy is " << (best_so_far_accuracy * 100) << "%" << endl << endl;
        }
    }
    // Forward Search is done. We can print solution. Output adopted from Project template.
    cout << "Finished search!! The best feature subset is {";
    for (int i = 0; i < bestFeatures.size(); i++) {
        cout << bestFeatures.at(i) << ",";
    }
    cout << "}, which has an accuracy of " << (totalAccuracy * 100) << "%" << endl;
    return bestFeatures; // return the set containing of best features
}
// function for backward elimination
// Start with a set of all features and see how much better removing a feature would make your result
void Backward_Elimination(vector<vector<double>>);
// function to remove features
// used in Backward_Elimination
vector<int> Remove_Feature(vector<int>, int);
