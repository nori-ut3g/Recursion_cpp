#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
bool linearSearchExists(vector<int> haystack, int needle){
    //cout << sizeof(haystack) << endl;
    for(int i = 0; i < haystack.size() ; i++){
        if(haystack[i] == needle){
            return true;
        }
    }
    return false;
}

vector<int> listIntersection(vector<int> targetList, vector<int> searchList){
    vector<int> results;
    for(int i = 0; i < searchList.size(); i++){
        if(linearSearchExists(targetList, searchList[i])){
            results.push_back(searchList[i]);
        }
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

int main(){
    printArray(listIntersection({1,2,3,4,5,6},{1,4,4,5,8,9,10,11}));
    printArray(listIntersection({3,4,5,10,2,20,4,5},{4,20,22,2,2,2,10,1,4}));
    printArray(listIntersection({2,3,4,54,10,5,9,11},{3,10,23,10,0,5,9,2}));
}
