// 惑星を表す文字列を受け取り、質量を受け取り、惑星の重量をニュートンで計算する関数を返します。
function weightFormulaByPlanet(planet){

    // 利用可能な惑星を検索します。デフォルトは地球です。
    const planets = {
            "mercury": 3.7,
            "venus": 8.87,
            "earth": 9.807,
            "mars": 3.711,
            "jupiter": 24.79,
            "saturn": 10.44,
            "uranus": 8.87,
            "neptune": 11.15,
    };

    planet = planet.toLowerCase();
    let gravity = planets[planet] !== undefined ? planets[planet] : planets["earth"];
    return function(kgMass){ return kgMass * gravity};
}

// 質量kgを取り込み、地球上の重量をニュートンで返す関数を作成します。
let getWeightOnEarth = weightFormulaByPlanet("earth");
console.log(getWeightOnEarth(50)); //490.35 N
console.log(getWeightOnEarth(90)); //882.63 N

let getWeightOnJupiter = weightFormulaByPlanet("jupiter");
console.log(getWeightOnJupiter(50)); //1239.5 N
console.log(getWeightOnJupiter(90)); //2231.1 N

console.log(weightFormulaByPlanet("neptune")(50)); //557.5 N

// 高階関数を使用して天王星(uranus)、金星、水星におけるあなたの体重を計算してください。