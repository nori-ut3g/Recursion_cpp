#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}
int main() {
    vector<vector<int>> list1 = {{2,3,4,5},{5,22,34,4,5},{12,13,45,67,84}};
    printArray(accumulate(next(list1.begin(), 1), list1.end(), *list1.begin(), [](vector<int> result, vector<int> oneDList){
        result.insert(result.end(), oneDList.begin(), oneDList.end());
        return result;
    }));

    //reduceもあるが、executionが必要
    printArray(reduce(next(list1.begin(), 1), list1.end(), *list1.begin(), [](vector<int> result, vector<int> oneDList){
        result.insert(result.end(), oneDList.begin(), oneDList.end());
        return result;
    }));


}