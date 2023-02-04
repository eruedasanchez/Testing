#ifndef LABO_TESTING_FILASQUESUMAN_H
#define LABO_TESTING_FILASQUESUMAN_H

#include <vector>
#include <tuple>
#include <iostream>
#include <string>

using namespace std;

int sumarElementos(vector<vector<int>> m, int f);
vector<int> armarVector(vector<vector<int>>& m, int f);
vector<int> concatenar(vector<vector<int>> t);
vector<int> filasQueSumanN(vector<vector<int>> m, int n);

int sumarElementosEnSubconjunto(vector<vector<int>> matriz, int f, int desde, int hasta);
vector<int> armarSubVector(vector<vector<int>> m, int f, int desde, int hasta);
int apariciones(vector<tuple<vector<int>, int>> filaubic, int numberfila, int desde, int hasta);
vector<int> filasDondeAlgunosSumanN(vector<vector<int>> m, int n);

#endif //LABO_TESTING_FILASQUESUMAN_H
