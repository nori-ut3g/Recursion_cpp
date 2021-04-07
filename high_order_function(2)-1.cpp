#include <iostream>
#include <functional>
#include <math.h>
using namespace std;

int summation(function<int(int)> g, int a, int b) {
    if(b < a) return 0;
    return g(b) + summation(g, a, b-1);
}

int pPi(function<int(int)> g, int a, int b) {
    if(b < a) return 1;
    return g(b) * pPi(g, a, b-1);
}

int main() {
    function<int(int)> identity = [](int i){return i;};
    cout << summation(identity, 1, 10) << endl;
    cout << summation([](int i){return 10;}, 1, 100) << endl;

    cout << pPi(identity, 1, 10) << endl;
    cout << pPi([](int i){return 5;}, 1, 10) << endl;
}