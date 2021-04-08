#include <iostream>
#include <thread>

using namespace std;


void printHello(int num) {
    cout << "Hello " << num << " times" << endl;
}

int main() {
    thread th1(printHello, 1);

    th1.join();

    auto func = [](string message) {
        cout << "thread id = " << this->get_id() << " " << message << endl;
    };

    thread th2(func, "Hello, World!");
    cout << "thread id = " << th2.get_id() << " " << message << endl;
}