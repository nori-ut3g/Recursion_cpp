#include <iostream>
#include <functional>
#include <string>

using namespace std;

int main() {
    double mutableTaxRate = 0.3;

    auto taxLambda = [&mutableTaxRate](double stateTaxRate, string state){
        return [&mutableTaxRate, state, stateTaxRate](int income){
            double taxRate = mutableTaxRate + stateTaxRate;
            cout << "Computing taxes for state..." + state << endl;
            return income - (int)(income * taxRate) ;
        };
    };

    function <int(int)> californiaF = taxLambda(0.0725, "California");
    function <int(int)> texasF = taxLambda(0.0625, "Texas");
    function <int(int)> hawaiiF = taxLambda(0.04, "Hawaii");

    int income1 = 40000;
    cout << "------Calculating income1 using lambdas------" << endl;
    cout << californiaF(income1) << endl;
    cout << texasF(income1) << endl;
    cout << hawaiiF(income1) << endl;

    mutableTaxRate = 0.1;

    cout << "------Calculating income1 using lambdas------" << endl;
    cout << californiaF(income1) << endl;
    cout << texasF(income1) << endl;
    cout << hawaiiF(income1) << endl;
};