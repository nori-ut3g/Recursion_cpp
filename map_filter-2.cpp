#include <iostream>
#include <functional>
#include <vector>
using namespace std;

vector<int> myFilter(function<bool(int)> predicateF, vector<int> l) {
    vector<int> results;
    for(int i = 0; i<l.size(); i++) {
        if(predicateF(l[i])) results.push_back(l[i]);
    }
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
    vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    printArray(myFilter([](int x){return x%2 != 0;}, nums) );
}