#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

class LambdaMachine {
public:
    vector<function<int(int, int)>> lambdaStorage;

    map<string, int> handlers;
    int counter;

    LambdaMachine() {
        this->lambdaStorage;
        this->handlers;
        this->counter = 0;
        srand( time(NULL) );
    }

    void insert(string key, function<double(int, int)> lambda) {
        if(this->handlers.find(key) == this->handlers.end()){
            this->lambdaStorage.push_back(lambda);
            this->handlers[key] = this->lambdaStorage.size()-1;
        }else{
            this->lambdaStorage[this->handlers[key]] = lambda;
        }
    }

    function<double(int, int)> retrieve(string key) {
        int l = this->lambdaStorage.size();
        if((this->lambdaStorage.size() <= 0) && (this->handlers.find(key) == this->handlers.end())){
            return nullptr;
        }else{
            return this->lambdaStorage[this->handlers[key]];
        }
    }

    function<double(int, int)> roundRobinRetrieve() {
        int l = this->lambdaStorage.size();
        if(l == 0) return nullptr;
        int index = this->counter % l;
        cout << "Round-Robin retrieval at index: " + to_string(index) << endl;

        this->counter++;
        return this->lambdaStorage[index];
    }

    function<double(int, int)> randomRetrieve() {
        int l = this->lambdaStorage.size();
        if(l == 0) return nullptr;
        int index = rand () % l;
        cout << "Random retrieval at index: " + to_string(index) << endl;
        return this->lambdaStorage[index];
    }
};

int main() {
    LambdaMachine lambdaMachine;
    lambdaMachine.insert("pythagora", [](int x, int y){return sqrt(x*x + y*y);});
    lambdaMachine.insert("addition", [](int x, int y){return x + y;});
    lambdaMachine.insert("subtraction", [](int x, int y){return x - y;});
    lambdaMachine.insert("multiplication", [](int x, int y){return x * y;});
    lambdaMachine.insert("division", [](int x, int y){return x / y;});
    lambdaMachine.insert("noises", [](int x, int y){return sqrt(x + y);});

    cout << lambdaMachine.retrieve("pythagora")(3,4) << endl;
    cout << lambdaMachine.retrieve("multiplication")(4,10) << endl;

    int x = 1;
    int y = 10;

    cout << lambdaMachine.randomRetrieve()(x,y) << endl;
    cout << lambdaMachine.randomRetrieve()(x,y) << endl;
    cout << lambdaMachine.randomRetrieve()(x,y) << endl;

    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;
    cout << lambdaMachine.roundRobinRetrieve()(x,y) << endl;



}