// C++で開発しましょう。
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

void printDuplicates(vector<int>inputList){
    unordered_map<int, int> hashmap;
    vector<int> keyList;
    for(int i = 0; i < inputList.size(); i++){
        if(hashmap[inputList[i]] == 0){
            hashmap[inputList[i]] = 1;
        }else{
            hashmap[inputList[i]] = hashmap[inputList[i]] + 1;
        }
    }
    //keyの出力
    auto iterator = hashmap.begin();
    while(iterator != hashmap.end()){
        keyList.push_back(iterator->first);
        ++iterator;
    }
    printArray(keyList);
    //<unordered_map>は順序が保持されない
    for(int i = 0; i < keyList.size(); i++){
        cout << to_string(keyList[i]) + "has " + to_string(hashmap[keyList[i]]) + " duplicates." << endl;
    }

}


int main(){
    printDuplicates({1,1,1,1,1,2,2,2,2,2,2,3,3,3,4,5,6,6,6,6,7,8,8,8,9,9,9});
    printDuplicates({7,7,6,6,3,5,3,9,2,5,5,4,6,4,1,4,1,7,2});
}
