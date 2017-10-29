//
//  main.cpp
//  h2q3
//
//  Created by SunHanbo on 10/6/16.
//  Copyright © 2016 SunHanbo. All rights reserved.

//Problem 3. One-sided Fisher’s Exact Test (10 pts)
//Write a C++ program oneSidedFastFishersExactTest.cpp, as a modified version of the fast fishers exact test presented in the class. Instead of calculating the p-value ptwo−sided(a, b, c, d) =
//output “significant” if the calculated p-value is smaller than 0.05, and “not significant” other-wise. Example runs of valid input arguments are
//case1  2 7 8 2
//significant
//case2 7 2 2 8
//not significant

//./momentStat `cat momentStat.1.args` < momentStat.test1.input > momentStat.test1.output


#include <iostream> 
#include <cmath> 
#include <cstdlib>

using namespace std;
double logHypergeometricProb(double* logFacs, int a, int b, int c, int d);
void initLogFacs(double* logFacs, int n);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    int n = a + b + c + d;
    double* logFacs = new double[n+1];
    initLogFacs(logFacs, n);
    double logpCutoff = logHypergeometricProb(logFacs,a,b,c,d);
    double pFraction = 0;
    for(int x=0; x < a; ++x)
    {
        if ( d-a+x >=0 )
        {
            double l = logHypergeometricProb(logFacs,x,a+b-x,a+c-x,d-a+x);
            pFraction += exp(l - logpCutoff);
        }
    }
    double logpValue = logpCutoff + log(pFraction);
    double pva = exp(logpValue);
    //cout << "One-sided p-value is " << pva << endl;
    if (pva<0.05)
        cout << "significant";
    else
        cout<< "not significant";
        
    delete [] logFacs;
    return 0;
}

void initLogFacs(double* logFacs, int n)
{
    logFacs[0] = 0;
    for(int i=1; i < n+1; ++i)
        logFacs[i] = logFacs[i-1] + log((double)i);
}

double logHypergeometricProb(double* logFacs, int a, int b, int c, int d)
{
    return logFacs[a+b] + logFacs[c+d] + logFacs[a+c] + logFacs[b+d] - logFacs[a] - logFacs[b] - logFacs[c] - logFacs[d] - logFacs[a+b+c+d]; }
    
    
    
    
    
    
    
    
    
    
    
