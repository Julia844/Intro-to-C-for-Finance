#include <iostream>
using namespace std;

#include "inequalities.hpp";
#include "Inequalities.cpp";

int main(){
    double d1, d2;
    cout << "First Number:";
    cin >> d1;
    cout << "Second Number:";
    cin >> d2;
    char c;
    cout << "Which function?";
    cin >> c;
    if (c == 1){
        cout << "Max value is: " << Max(d1, d2) << endl;
    }
    else
        {
        cout << "Min value is: " << Min(d1, d2) << endl;
    }
    double dA = 1.0; double dB = 2.0; double dC = 3.0;
    cout << "\ n\ nMax and min of three numbers: " << endl;
    cout << "Max value is: " << Max(dA, dB, dC) << endl;
    cout << "Min value is: " << Min(dA, dB, dC) << endl;
return 0;
}
