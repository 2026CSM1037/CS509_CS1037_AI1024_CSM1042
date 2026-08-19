#include <bits/stdc++.h>
#include "gradientDescent.h"

using namespace std;

int main(){
    int choice;

    cout << "1. Execute one test file" << endl;
    cout << "2. Execute all test files" << endl;
    cout << "Enter choice : ";

    cin >> choice;

    if(choice == 1){
        int testNo;
        cout << "Enter test case number (any between 1-5): ";
        cin >> testNo;

        if(testNo < 1 || testNo > 5){
            cout << "Invalid test case number" << endl;
            return 0;
        }

        string fileName =
            "gd_0" + to_string(testNo) + ".txt";

        GradientDescentInput input;

        if(!readGradientDescentInput(fileName, input)){
            return 0;
        }

        GradientDescentResult result =
            executeGradientDescent(input);

        printGradientDescentResult(fileName, input, result);
    }

    else if(choice == 2){
        for(int testNo = 1; testNo <= 5; testNo++){

            string fileName =
                "gd_0" + to_string(testNo) + ".txt";

            GradientDescentInput input;

            if(!readGradientDescentInput(fileName, input)){
                break;
            }

            GradientDescentResult result =
                executeGradientDescent(input);

            cout << "\n========================================\n";

            cout << "Test File: "
                 << fileName << endl;

            printGradientDescentResult(fileName, input, result);
        }
    }

    else{
        cout << "Invalid Choice" << endl;
    }

    return 0;
}