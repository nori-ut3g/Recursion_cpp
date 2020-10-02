#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string existsWithinList(vector<int> listL, int dataY) {
    unordered_map<int, int> hashMap;

    for (int i = 0; i < sizeof(listL); i++) {
        hashMap[listL[i]] = listL[i];
    }

    return hashMap[dataY] != 0 ? "true" : "false";
}


int main() {
    vector<int> sampleList = { 3,10,23,3,4,50,2,3,4,18,6,1,-2 };
    cout << existsWithinList(sampleList, 23) << endl;
    cout << existsWithinList(sampleList, -2) << endl;
    cout << existsWithinList(sampleList, 100) << endl;
}
