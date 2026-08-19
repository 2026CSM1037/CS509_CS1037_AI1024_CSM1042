#include<bits/stdc++.h>
#include "maxflow.h"

using namespace std;

int main(){

    int choice;

    cout<<"1. Execute one test file"<<endl;
    cout<<"2. Execute all test files"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;

    if(choice==1){

        int testNo;
        cout<<"Enter test case number (1-5): ";
        cin>>testNo;

        string fileName="maxflow_"+to_string(testNo)+".txt";
        executeMaxflowMincut(fileName);
    }
    else if(choice==2){

        int testNo=1;
        while(true){
            string fileName="maxflow_"+to_string(testNo)+".txt";
            ifstream fin(fileName);

            if(!fin){
                break;
            }

            fin.close();
            executeMaxflowMincut(fileName);
            testNo++;
        }
    }
    else{
        cout<<"Invalid Choice"<<endl;
    }

    return 0;
}