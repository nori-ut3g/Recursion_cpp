#include <iostream>
#include <functional>
#include <string>
using namespace std;

function<string()> lambdaHelloWorld(string randomInput) {
    cout << randomInput + " was passed in but this function always returns the same lambda function" << endl;
    return []{return "Hello World";};
}

string helloWorld() {
    return "Hello World";
}

int main() {
    cout << helloWorld() << endl;
    cout << lambdaHelloWorld("lalilulelo")() << endl;
}