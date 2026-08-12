#include <bits/stdc++.h>
#include "betweennessCentrality.h"

using namespace std;

int main(){

    int choice;

    cout<<"1. Execute one test file"<<endl;
    cout<<"2. Execute all test files"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;

    if(choice==1){

        int testNo;

        cout<<"Enter test case number (any between 1-6): ";
        cin>>testNo;

        string fileName="graph_test_0"+to_string(testNo)+".txt";

        executeBetweennessCentrality(fileName);
    }
    else if(choice==2){

        int testNo=1;

        while(1){
            string fileName="graph_test_0"+to_string(testNo)+".txt";
            ifstream fin(fileName);
            if(!fin)
                break;
            fin.close();
            executeBetweennessCentrality(fileName);
            testNo++;
        }
    }
    else{
        cout<<"Invalid Choice"<<endl;
    }

    return 0;
}