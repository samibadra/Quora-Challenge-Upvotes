/*
 Copyright 2015 Sami Badra
 
 DISCLAIMER: Any unauthorized use, including but not limited to, copying or
 redistributing any chunk of the source code (or an entire file) will result in
 punishment by law. I, Sami Badra,own all rights to the files and their contents.
 
 P.S. This source code has already been submitted to Quora, so it is in your best
 interest NOT to copy ANY of the source code you see here. Quora checks for code
 similarities from previously submitted version.You will be noticed and punished.
 
 upvotes.cpp
 Quora_Challenge_Upvotes
 
 Created by Sami Badra on 5/16/15.
 Copyright (c) 2015 Sami Badra. All rights reserved.
 */

#include <iostream>

int totalDays, window;
int *voteCount;

using namespace std;

/* stores input */
void storeInput() {
    cin >> totalDays >> window;
    voteCount = (int *)calloc(totalDays, sizeof(int));
    for (int i=0; i < totalDays; i++)
        cin >> voteCount[i];
}

/* determines how many "non-decresing" subranges there are by passing in the index of start of window */
int strictlyIncreasing(int windowStart) {
    int count = 0;
    int start = windowStart;        //points to start of window
    int limit = windowStart + window - 1;   //window limit
    for (start; start < limit; start++)     //increment start pointer
        for (int end = limit; end > start; end--) {
            //calculations for each subwindow
            bool increasing = true;
            for (int i = start; i < end; i++)   //check if subrange is ALWAYS increasing
                if (voteCount[i] > voteCount[i+1]) {
                    increasing = false;  //set to false if an decreasing range was found
                    break;
                }
            if (increasing)  //subrange was always increasing
                count++;
        }
    return count;
}

/* determines how many "non-increasing" subranges there are by passing in the index of start of window */
int strictlyDecreasing(int windowStart) {
    int count = 0;
    int start = windowStart;        //points to start of window
    int limit = windowStart + window - 1;   //window limit
    for (start; start < limit; start++)     //increment start pointer
        for (int end = limit; end > start; end--) {     //
            //calculations for each subwindow
            bool decreasing = true;
            for (int i = start; i < end; i++)   //check if subrange is ALWAYS decreasing
                if (voteCount[i] < voteCount[i+1]) {
                    decreasing = false;  //set to false if an increasing range was found
                    break;
                }
            if (decreasing)  //subrange was always decreasing
                count++;
        }
    return count;
}

int main(int argc, const char * argv[]) {
    storeInput();
    for (int i=0; i < (totalDays-window+1); i++)
        cout << strictlyIncreasing(i)-strictlyDecreasing(i) << endl;
    
    return 0;
}
