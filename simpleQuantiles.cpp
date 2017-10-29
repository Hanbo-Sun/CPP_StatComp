//
//  main.cpp

//  h2q1 Problem 1 - Compute Simple Quantiles (10 pts)

//Suppose that values x1, . . . , xn have been realized from a random variable X. Simple estimators of the quantiles for X can be obtained from the order statistics: i.e. the data arranged in numerically ascending order. If x(1) ≤ . . . ≤ x(n) denote the order statistics, the uth quantile (0 ≤ u ≤ 1) is defined to be
//x(nu), if nu is a positive integer x(⌊nu⌋+1) , otherwise

//Write a C++ program simpleQuantiles.cpp to compute a number of uth quantiles of a sequence of input numbers. Which quantiles to be computed are specified using the program augment list argv. Your program should obtain the input numbers using cin from one line in the console. Your program should print the quantile values separated by white spaces in a new line. No error handling for malformed argument is needed. Example runs of valid input arguments are


#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;

void mergeSort(std::vector<double>& a, int p, int r);
void merge(std::vector<double>& a, int p, int q, int r);
void printArray(std::vector<double>& A);
int main(int argc, char** argv)
{
    int m = argc - 1;
    vector<double> u;
    for (int i = 0; i<m; i++)
    {
        u.push_back(atof(argv[i+1]));
    }
    vector<double> v;
    double tok;
    while (std::cin >> tok)
    {
        v.push_back(double(tok));
    }
    int n = v.size();
    mergeSort(v, 0, n-1);
    //printArray(v);
    
    
    //cout << int(2.5) << int(2.1) << int(2.7) << int(2.0) << int(1.9999999999999999999) << endl;
    int uu[m];
    for (int i = 0; i < m; i++)
    {
        u[i] = u[i] * n;
        if (abs(floor(u[i]) - u[i]) > 1e-6)
        {//can use cell function as well
            uu[i] = floor(u[i]) + 1;
            //cout<<uu[i];
        }
        else
        {
            uu[i] = int(u[i]);
            //cout<<"!"<<u[i]<<".."<<i<<endl;
        }

    }
    
    for (int i=0; i< m; i++)
    {
        if (uu[i]==0)
            cout << v[0]<<" ";
        else
            cout<<v[uu[i]-1]<<" ";
    }
    
    return 0;
}



void mergeSort(std::vector<double>& a, int p, int r)
{
    if ( p < r ) {
        int q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}


void merge(std::vector<double>& a, int p, int q, int r)
{
    std::vector<double> aL, aR;
    for(int i=p; i <= q; ++i)
        aL.push_back(a[i]);
    for(int i=q+1; i <= r; ++i)
        aR.push_back(a[i]);
    aL.push_back(INT_MAX);
    aR.push_back(INT_MAX);
    for(int k=p, i=0, j=0; k <= r; ++k)
    {
        if ( aL[i] <= aR[j] )
        {
            a[k] = aL[i]; ++i;
        }
        else
        {
            a[k] = aR[j]; ++j;
        }
    }
}

void printArray(std::vector<double>& A)
{
    for(int i=0; i < A.size(); ++i)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

//case2 0.25 0.5 0.75
//-1.86 0.38 0.16 0.16 -0.48 1.07 0.55 0.61 0.76
//0.16 0.38 0.61













