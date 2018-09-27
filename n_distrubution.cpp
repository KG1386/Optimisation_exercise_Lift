//
// Created by zeiselt on 21/09/18.
//
#include <iostream>
#include <random>
#include "misc.h"
using namespace std;

int getPersonWeight(double avWeight, double dist, double minWeight, double maxWeight)
{
    const int nrolls=10;  // number of tries

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(avWeight,dist);

    double acc = 0;
    double number = 0;

    for (int i=0; i<nrolls; ++i) {
        number = distribution(generator);
        cout << number << endl;
        if ((number > minWeight) && (number < maxWeight)){
            //acc += number;
            return number;
        }
    }
    return acc/10.0;

}