#include <iostream>
#include <functional>
#include <string>

using namespace std;

//std::function
string functionalInputTest(function<string()> f) {
    return  f() + ".... called from functionalInputTest!";
}

//template
template<class F> string templateInputTest(F f) {
    return string(f()) + ".... called from templateInputTest!";
}

//pointer String
string poiterInputTest(const char* (*f)()) {
    return string(f()) + ".... called from poiterInputTest!";
}

int main() {
    auto f = []{return "hello world";};

    cout << functionalInputTest(f) << endl;
    cout << templateInputTest(f) << endl;
    cout << poiterInputTest(f) << endl;

    function<string()> g = []{return "hello mars";};
    const char* (*h)() = []{return "hello jupiter";};
    string (*i)() = []{return string("hello jupiter");};

    cout << "-----------" << endl;
    cout << functionalInputTest(g) << endl;
    cout << templateInputTest(g) << endl;
    cout << poiterInputTest(h) << endl;
    cout << templateInputTest(h) << endl;

    cout << functionalInputTest(i) << endl;
    cout << templateInputTest(i) << endl;
}