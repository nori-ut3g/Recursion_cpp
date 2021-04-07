#include <iostream>
#include <functional>
#include <string>
using namespace std;

string greeting(string name) {
    return "Hello there " + name;
}

string nameGenerator() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string name;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int index = rand() % alphabet.size();
        name += alphabet.at(index);
    }
    return name;
}

string multiCall(function<string(string)> f, function<string()> fInputF, string message) {
    return f(fInputF()) + "......" + message;
}



int main() {
    cout << multiCall(greeting, nameGenerator, "Thank you") << endl;
}