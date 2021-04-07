#include <iostream>
#include <functional>
#include <string>
using namespace std;

int synchronousFn(function<int(int)> f, int x) {
    int results = f(10);
    return f(x) + f(x*x) + results;
}

int main() {
    cout << synchronousFn([](int x){
        cout << "Call on " + to_string(x) << endl;
        return x/2;
    }, 254)
         << endl;
}