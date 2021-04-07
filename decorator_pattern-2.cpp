#include <iostream>
#include <functional>
#include <string>
#include <time.h>
using namespace std;

int main() {
    auto timeDecorator = [](function<int(int)> f) {
        return [f](int arg){
            clock_t start = clock();
            int result = f(arg);
            clock_t end = clock();
            cout << "This function took:"<< (int)(end - start) << "ms" << endl;
            return result;
        };
    };

    cout << timeDecorator([](int x){return x*2;})(2424) << endl;

    cout << timeDecorator([](int x){
        int finalResult = 1;
        for(int i=1; i<x; i++) {
            int result = i;
            for(int j=1; j<i; j++) {
                result += j;
            }
            finalResult += result;
        }
        return finalResult;
    })(1000);
}