#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    auto reduceMap = [](function<int(int)> f, vector<int> list) {
        return accumulate(list.begin(), list.end(), vector<int>(), [&f](vector<int> newList, int num){
            newList.push_back(f(num));
            return newList;
        });
    };
    auto reduceFilter = [](function<bool(int)> preficateF, vector<int> list) {
        return accumulate(list.begin(), list.end(), vector<int>(), [&preficateF](vector<int> newList, int num){
            if(preficateF(num)) newList.push_back(num);
            return newList;
        });
    };

    vector<int> list1 = {1,2,3,4,5,6,7,8,9,10};
    printArray(reduceMap([](int x){return x*x;}, list1));
    printArray(reduceFilter([](int x){return x%2 != 0;}, list1));

}