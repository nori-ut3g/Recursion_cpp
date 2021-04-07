#include <iostream>
#include <functional>
#include <string>
#include <time.h>
using namespace std;

int main() {
    auto capitalizeDecorator = [](){
        return [](arg){
            return f(arg)
        }
    }
}