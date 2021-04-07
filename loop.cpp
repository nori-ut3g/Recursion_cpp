#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int loopDifferent() {
    vector<int> l {3,4,5,6,6,10};
    int counter = 0;

    function<void(function<void(int)>)> forEach = [l](function<void(int)> f){
        for(int i = 0; i<l.size(); i++) {
            f(l[i]);
        }
    };

    forEach([&counter](int x){
        counter += x*x;
    });

    return counter;
}

int main() {
    cout << loopDifferent() << endl;

}