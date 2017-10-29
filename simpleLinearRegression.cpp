#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
    vector<double> y;
    int n = argc - 1;
    
    for (int i=0;i<n;i++)
    {
        y.push_back(atof(argv[i+1]));
    }
    
    double y_ave=0;
    double x_ave=(double)(n+1)/(2*n); //cast type.
    //cout<<setprecision(8)<<endl<<x_ave<<endl<<endl;
    
    for (int i=0;i<n;i++)
    {
        y_ave=y_ave+y[i];
    }
    y_ave=y_ave/n;
    //cout<<setprecision(8)<<endl<<y_ave<<endl<<endl;

    
    double beta1_u=0.0;
    double beta1_d=0.0;
    for (int i=0;i<n;i++)
    {
        beta1_u=beta1_u+((double)(i+1)/n-x_ave)*(y[i]-y_ave); //float- large error
        beta1_d=beta1_d+pow((double)(i+1)/n-x_ave,2);
    }
    double beta1=beta1_u/beta1_d;
    double beta0=y_ave-beta1*x_ave;
    if (abs(beta0-0)<1e-15)
        beta0=0;
    cout<<setprecision(8)<<beta0<<" "<<beta1<<endl;
     return 0;
}
