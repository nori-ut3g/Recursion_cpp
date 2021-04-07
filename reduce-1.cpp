#include <iostream>
#include <functional>
#include <math.h>
#include <vector>
#include <numeric>
using namespace std;

int myReduce(function<int(int,int)> reduceCallback, vector<int> l, int initial) {
    int lastResult = initial;
    for(int i=0; i<l.size(); i++) {
        int result = reduceCallback(l[i], lastResult);
        lastResult = result;
    }
    return lastResult;
}

int main() {
    vector<int> list1 {1,2,3};
    vector<int> list2 {1,2,3,4,5,6,7,8,9,10};

    cout << myReduce([](int total, int x){return total*x;}, list1, 1) << endl;

    cout << myReduce([](int total, int x){return total*x;}, list2, 1) << endl;

    cout << accumulate(list2.begin(), list2.end(), 1, [](int total, int x){return total * x;});


}