#include <iostream>
#include <functional>
#include <string>
using namespace std;

int main() {
    auto simpleDecorator = [](function <string()> f) {
        return [=]{
            cout << "Running f......" << endl;
            return f();
        };
    };
    function <string()> helloWorld = []{return "Hello World";};
    function <string()> newFunc1 = simpleDecorator(helloWorld);
    cout << newFunc1() << endl;
}