//
//  main.cpp
//  qq3
//
//  Created by SunHanbo on 9/22/16.
//  Copyright © 2016 SunHanbo. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
    
    const int K=5;
    int n= argc-1;
    vector<double> x;
    
    for (int i=0;i<n;i++)
    {
        
        x.push_back(atof(argv[i+1]));
    }
    
    double sum_x=0.0;
    for (int i=0;i<n;i++)
        sum_x=sum_x+x[i];

    double p[5]={0};
    double c=0.0;
    
    for (int i=0;i<K;i++)
    {
        double sum=0;
        
        for (int j=0;j<n;j++)
        {
            sum=sum+pow(2,abs(i-j))*x[j];
        }
        if (n>5 && sum_x>2e-3)
        {
            p[i] = exp(pow(2,(-i-1))+sum-pow(2,n-1));
        }
        else
        {
            p[i] = exp(pow(2,(-i-1))+sum);
        }
            
        c=c+p[i];
    }
    
    for (int i=0; i<K;i++)
        cout<<setprecision(8)<<p[i]/c<<endl;
    return 0;
}
