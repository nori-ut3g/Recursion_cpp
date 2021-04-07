#include <iostream>
#include <functional>
#include <math.h>
using namespace std;

function<string()> helloFn() {
    return []{return "hello world";};
}

function<int(int)> constantMultiplication(int x) {
    return [x](int y){return y * x;};
}

int main() {
    function<string()> outputF = helloFn();
    cout << outputF() << endl;
    cout << "Running a function that was generated...." + outputF() << endl;

    function<int(int)> multiplyBy4 = constantMultiplication(4);

    cout << multiplyBy4(3) << endl;
    cout << multiplyBy4(10) << endl;
    cout << multiplyBy4(5) << endl;
}