#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<string> list1 = {"hello", "world", "and", "hello", "jupiter"};

    cout << accumulate(next(list1.begin(), 1), list1.end(), *begin(list1), [](string result, string word){return result + "," + word;});
}