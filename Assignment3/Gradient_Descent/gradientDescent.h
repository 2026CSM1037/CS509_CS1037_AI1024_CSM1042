#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include <bits/stdc++.h>

using namespace std;

struct GradientDescentInput {
    int degree;
    vector<double> coefficients;

    double initialX;
    double learningRate;
    double tolerance;
    int maxIterations;
};

struct GradientDescentResult {
    double finalX;
    double finalValue;
    int iterations;
    bool converged;
    double executionTime;
};

bool readGradientDescentInput(string fileName, GradientDescentInput &input);

double evaluatePolynomial(
    const vector<double> &coefficients,
    double x
);

double evaluateDerivative(
    const vector<double> &coefficients,
    double x
);

GradientDescentResult executeGradientDescent(
    const GradientDescentInput &input
);

void printGradientDescentResult(
    string fileName,
    const GradientDescentInput &input,
    const GradientDescentResult &result
);

#endif