#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

int main() {
    function<void()> printFinish = []{
        cout << "Finish!" << endl;
    };

    function<void(function<void()>, int)> runAfterXMs = [](function<void()> f,int ms) {
        cout << "running the function ....." << endl;
        thread th1(f);
        this_thread::sleep_for(chrono::milliseconds(ms));
//        thread th1(f);
        th1.join();
    };

    function<void(function<void()>, int)> tickTack = [](function<void()> f,int ms) {
        cout << "running the function .";
        for(int i=0; i < int(ms/500); i++){
            thread time([]{cout << "."; });
            time.join();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout<<endl;
        thread th1(f);
        th1.join();
        this_thread::sleep_for(chrono::milliseconds(ms%500));

    };
    runAfterXMs(printFinish, 5000);
    tickTack(printFinish, 5000);

}