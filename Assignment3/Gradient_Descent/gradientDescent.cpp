#include <bits/stdc++.h>
#include "gradientDescent.h"

using namespace std;

bool readGradientDescentInput(string fileName,GradientDescentInput& input){
    ifstream fin(fileName);

    if(!fin){
        cout<<"File not found\n";
        return false;
    }

    string label;
    fin>>label;

    if(label!="DEGREE"){
        cout<<"Invalid input: DEGREE expected\n";
        return false;
    }

    fin>>input.degree;

    if(input.degree<1){
        cout<<"Invalid degree\n";
        return false;
    }

    fin>>label;

    if(label!="COEFFICIENTS"){
        cout<<"Invalid input: COEFFICIENTS expected\n";
        return false;
    }

    input.coefficients.resize(input.degree+1);

    for(int i=0;i<=input.degree;i++){
        if(!(fin>>input.coefficients[i])){
            cout<<"Invalid coefficient count\n";
            return false;
        }
    }

    fin>>label;

    if(label!="INITIAL_X"){
        cout<<"Invalid input: INITIAL_X expected\n";
        return false;
    }

    fin>>input.initialX;

    fin>>label;

    if(label!="LEARNING_RATE"){
        cout<<"Invalid input: LEARNING_RATE expected\n";
        return false;
    }

    fin>>input.learningRate;

    if(input.learningRate<=0){
        cout<<"Invalid learning rate\n";
        return false;
    }

    fin>>label;

    if(label!="TOLERANCE"){
        cout<<"Invalid input: TOLERANCE expected\n";
        return false;
    }

    fin>>input.tolerance;

    if(input.tolerance<=0){
        cout<<"Invalid tolerance\n";
        return false;
    }

    fin>>label;

    if(label!="MAX_ITERATIONS"){
        cout<<"Invalid input: MAX_ITERATIONS expected\n";
        return false;
    }

    fin>>input.maxIterations;

    if(input.maxIterations<=0){
        cout<<"Invalid maximum iterations\n";
        return false;
    }

    fin.close();

    return true;
}

double evaluatePolynomial(const vector<double>& coefficients,double x){
    double result=0.0;
    for(int i=(int)coefficients.size()-1;i>=0;i--)
        result=result*x+coefficients[i];

    return result;
}

double evaluateDerivative(const vector<double>& coefficients,double x){
    double result=0.0;

    int degree=coefficients.size()-1;

    for(int i=degree;i>=1;i--)
        result=result*x+i*coefficients[i];

    return result;
}

GradientDescentResult executeGradientDescent(const GradientDescentInput& input){
    GradientDescentResult result;

    double x=input.initialX;
    int iterations=0;
    bool converged=false;

    auto start=chrono::high_resolution_clock::now();

    while(iterations<input.maxIterations){
        double derivative=evaluateDerivative(input.coefficients,x);

        if(abs(derivative)<=input.tolerance){
            converged=true;
            break;
        }

        x=x-input.learningRate*derivative;
        iterations++;
    }

    double finalDerivative=evaluateDerivative(input.coefficients,x);

    if(abs(finalDerivative)<=input.tolerance)
        converged=true;

    auto end=chrono::high_resolution_clock::now();
    double executionTime=chrono::duration<double,milli>(end-start).count();

    result.finalX=x;
    result.finalValue=evaluatePolynomial(input.coefficients,x);
    result.iterations=iterations;
    result.converged=converged;
    result.executionTime=executionTime;

    return result;
}

void printGradientDescentResult(string fileName,const GradientDescentInput& input,const GradientDescentResult& result){
    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);

    cout<<"\nAlgorithm: Gradient Descent\n";
    cout<<"Degree: "<<input.degree<<endl;
    cout<<fixed<<setprecision(10);
    cout<<"Final x: "<<result.finalX<<endl;
    cout<<"Final f(x): "<<result.finalValue<<endl;
    cout<<"Iterations: "<<result.iterations<<endl;
    cout<<"Converged: "<<(result.converged?"true":"false")<<endl;
    cout<<"Execution time: "<<result.executionTime<<" ms"<<endl;

    fout<<"\nAlgorithm: Gradient Descent\n";
    fout<<"Degree: "<<input.degree<<endl;
    fout<<fixed<<setprecision(10);
    fout<<"Final x: "<<result.finalX<<endl;
    fout<<"Final f(x): "<<result.finalValue<<endl;
    fout<<"Iterations: "<<result.iterations<<endl;
    fout<<"Converged: "<<(result.converged?"true":"false")<<endl;
    fout<<"Execution time: "<<result.executionTime<<" ms"<<endl;

    fout.close();
}