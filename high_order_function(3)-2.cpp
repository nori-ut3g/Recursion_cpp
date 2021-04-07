#include <iostream>
#include <functional>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>
using namespace std;

int main() {
    auto weightFormulaByPlanet = [](string planet) {
        map<string, double> planets;
        planets["mercury"] = 3.7;
        planets["venus"] = 8.87;
        planets["earth"] = 9.807;
        planets["mars"] = 3.711;
        planets["jupiter"] = 24.79;
        planets["saturn"] = 10.44;
        planets["uranus"] = 8.87;
        planets["neptune"] = 11.15;
        transform(planet.begin(), planet.end(), planet.begin(), ::tolower);

        double gravity = planets[planet];
        return [gravity](double kgMass){return kgMass * gravity;};
    };

    function<double(double)> getWeightOnEarth = weightFormulaByPlanet("earth");
    cout << getWeightOnEarth(50.0) << endl;
    cout << getWeightOnEarth(90.0) << endl;

    function<double(double)> getWeightOnJupiter = weightFormulaByPlanet("jupiter");
    cout << getWeightOnJupiter(50.0) << endl;
    cout << getWeightOnJupiter(90.0) << endl;

    cout << weightFormulaByPlanet("neptune")(50.0) << endl;
}
