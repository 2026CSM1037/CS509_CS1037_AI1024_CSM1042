#include<bits/stdc++.h>
#include "csr.h"

using namespace std;

#define MAX_SIZE 500000
int OFFSET[MAX_SIZE];
int INTERMEDIATE[MAX_SIZE];
int PROPERTY[MAX_SIZE];
int POS;

void printArray(int arr[], int sz, ofstream &fout, int mainArr[], bool calledFromOtherAssignment){
    for(int i=0;i<sz;i++){
        mainArr[i] = arr[i];
        if(!calledFromOtherAssignment)
            fout<<arr[i]<<" ";
    }
    if(!calledFromOtherAssignment)
        fout<<endl;
}

void executeCSR(string fileName, bool calledFromOtherAssignment){
    cout<<"lol2"<<endl;

    ifstream fin(fileName);

    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);

    if(!fin){
        cout<<"File not found\n";
        return;
    }

    int vertices, edges;
    fin>>vertices>>edges;
    cout<<"lol3"<<endl;

    map<int, vector<pair<int,int>>> graph;

    for(int i=0;i<vertices;i++){
        int vertex,outDegree;
        fin>>vertex>>outDegree;

        for(int j=0;j<outDegree;j++){
            int neighbor,weight;
            fin>>neighbor>>weight;

            graph[vertex].push_back({neighbor,weight});
        }
    }

    fin.close();
    cout<<"lol4"<<endl;

    int offset[MAX_SIZE];
    int intermediate[MAX_SIZE];
    int property[MAX_SIZE];

    fill(offset,offset+MAX_SIZE,-1);
    fill(intermediate,intermediate+MAX_SIZE,0);
    fill(property,property+MAX_SIZE,0);

    int pos=0;

    cout<<"\nExecuting "<<fileName<<endl;

    auto blockStart=chrono::high_resolution_clock::now();

    for(int i=0;i<vertices;i++){
        offset[i] = pos;
        for(int j=0;j<graph[i].size();j++){
            intermediate[pos] = graph[i][j].first;
            property[pos] = graph[i][j].second;
            pos++;
        }
    }

    offset[vertices]=pos;

    auto blockEnd=chrono::high_resolution_clock::now();
    auto blockTime=chrono::duration<double,milli>(blockEnd-blockStart);

    POS = pos;

    if(!calledFromOtherAssignment)
        fout<<"Offset Array"<<endl;
    printArray(offset,vertices+1,fout, OFFSET, calledFromOtherAssignment);

    if(!calledFromOtherAssignment)
        fout<<"Intermediate Array"<<endl;
    printArray(intermediate,pos,fout, INTERMEDIATE, calledFromOtherAssignment);

    if(!calledFromOtherAssignment)
        fout<<"Property Array"<<endl;
    printArray(property,pos,fout, PROPERTY, calledFromOtherAssignment);

    if(!calledFromOtherAssignment){
        fout<<"CSR conversion completed in : "<<blockTime.count()<<" milliseconds"<<endl;
        cout<<"CSR conversion completed in : "<<blockTime.count()<<" milliseconds"<<endl;
    }
    cout<<"lol2"<<endl;
    fout.close();
}