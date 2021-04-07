#include <iostream>
#include <functional>
#include <math.h>
using namespace std;

int summation(function<int(int)> g, int a, int b) {
    if(b < a) return 0;
    return g(b) + summation(g, a, b-1);
}


int main() {

    function<int(int)> identity = [](int i){return i*i;};
    cout << summation(identity, 1, 25) << endl;

    function<int(int)> identity2 = [](int i){return 3 * i * (i + 3);};
    cout << summation(identity2, 1, 10) << endl;

    function<int(int)> identity3 = [](int i){return 3 * i * (i + 3);};
    cout << summation(identity3, 1, 10) << endl;

    //lambda関数ver
    function<int(function<int(int)>, int, int)> pPi = [&pPi](function<int(int)> g, int a, int b){
        if(b < a) return 1;
        return g(b) * pPi(g, a, b-1);
    };

    function<int(int)> identity4 = [](int k){return 7 - k;};
    cout << pPi(identity4, 1, 6) << endl;

    function<int(int)> identity5 = [](int i){return i * i + 3;};
    cout << pPi(identity5, 3, 5) << endl;
}