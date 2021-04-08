#include <iostream>
#include <functional>
using namespace std;

int main(){
    cout << [](int x, int y){return x + y;}(15, 35) << endl;

    function<int(int,int)> myCallable = [](int x, int y){return x + y;};
    cout << myCallable(3,5) << endl;
    cout << myCallable(10,10) << endl;
    cout << myCallable(150,5) << endl;
}