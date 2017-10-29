#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;  //if the number of inputs is even, then there is not error eg:compare 1 1 1 1 and 1 1 1 1 1

int main(int argc, char* argv[]){ //argc remember directly input with ./
    double ave = 0.0;
    double squ = 0.0;
    double ske = 0.0;
    double kur = 0.0;
    
    //###sort x
    
    vector<double> x;
    //cout<<argc<<endl;
    int n = argc - 1;
    for (int i=0;i<n;i++)
    {
        x.push_back(atof(argv[i+1]));
    }
    
    //double tok;
    //while (cin>>tok)
        //x.push_back(tok);
    
    //"west" for "ave" "squ"
    ave = x[0];
    double tt = 0.0;
    for (int i = 1; i < n; i++)
    {
        tt = (x[i] - ave);
        squ = squ + pow(tt, 2)*i/(i+1);
        ave = ave + tt / (i+1);
    }
    
    squ = squ/ (n - 1);
    
    double std=sqrt(squ);
    
    //ske and kur
    double t = 0.0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        // if squ=0
        if (abs(squ - 0) < 1e-307)
        {
            flag = 1;
            break;
        }
        t = (x[i] - ave)/std;
        
        ske = ske + pow(t,3);   //squ/ske/kur use "long double are also fine
        
        kur = kur + pow(t,4);
        
        //cout<<"kuri"<<kur<<endl;
    }
    
    ske=ske/n;
    kur = kur / n - 3;
  

    cout <<setprecision(8)<<ave << endl;
    cout << squ << endl;
    
    if (flag==0)
    {
        cout <<ske << endl;
        cout <<kur << endl;
    }
    
    return 0;
}
