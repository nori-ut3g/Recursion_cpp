#include <iostream>
#include <functional>
#include <vector>
using namespace std;

vector<int> myMap(function<int(int)> f, vector<int> l) {
    vector<int> results;
    for(int i = 0; i<l.size(); i++) results.push_back(f(l[i]));
    return results;
}
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums {1,2,3,4,5,6,7};
    printArray(myMap([](int x){return x*x;}, nums) );
}