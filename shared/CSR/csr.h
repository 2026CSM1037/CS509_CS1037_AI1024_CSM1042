#ifndef CSR_H
#define CSR_H

#include<bits/stdc++.h>

using namespace std;
#define MAX_SIZE 500000

extern int OFFSET[MAX_SIZE];
extern int INTERMEDIATE[MAX_SIZE];
extern int PROPERTY[MAX_SIZE];
extern int POS;

void executeCSR(string fileName, bool calledFromOtherAssignment);

#endif