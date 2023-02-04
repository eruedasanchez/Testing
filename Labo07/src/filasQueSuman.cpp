#include "filasQueSuman.h"

int sumarElementos(vector<vector<int>> m, int f){
    int suma = 0;
    for(int columna = 0; columna < (m[f]).size(); columna++){
        suma = suma + m[f][columna];
    }
    return suma;
}

vector<int> armarVector(vector<vector<int>>& m, int f){
    vector<int> vec;
    for(int columna = 0; columna < m[f].size(); columna++){
        vec.push_back(m[f][columna]);
    }
    return vec;
}

vector<int> concatenar(vector<vector<int>> t){
    vector<int> res;
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < t.size(); j++){
            res.push_back(t[i][j]);
        }
    }
    return res;
}

vector<int> filasQueSumanN(vector<vector<int>> m, int n){
    vector<int> elementosFilas;
    vector<vector<int>> filas;

    for(int fila = 0; fila < m.size(); fila++){
        int sumatoriaFilaActual = sumarElementos(m, fila);
        if(sumatoriaFilaActual == n){
            vector<int> filaActual;
            filaActual = armarVector(m,fila);
            filas.push_back(filaActual);
        }
    }
    elementosFilas = concatenar(filas);
    return elementosFilas;
}


int sumarElementosEnSubconjunto(vector<vector<int>> matriz, int f, int desde, int hasta){
    int suma = 0;
    for(int i = desde; i <= hasta; i++){
        suma = suma + matriz[f][i];
    }
    return suma;
}

vector<int> armarSubVector(vector<vector<int>> matriz, int f, int desde, int hasta){
    vector<int> vec;
    for(int columna = desde; columna <= hasta; columna++){
        vec.push_back(matriz[f][columna]);
    }
    return vec;
}

int apariciones(vector<tuple<vector<int>, int>> filaubic, int numberfila, int desde, int hasta){
    int ap = 0;
    for(int k = desde; k < hasta; k++){
        int numberFilaActual = get<1>(filaubic[k]);
        if(numberFilaActual == numberfila){
            ap++;
        }
    }
    return ap;
}

vector<int> filasDondeAlgunosSumanN(vector<vector<int>> m, int n){
    vector<int> elementosFilasSinRepetidas;
    vector<tuple<vector<int>, int>> subFilaActualYNumero;
    vector<int> subfilaActual;

    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            int sumatoriaSubconjuntoFila = sumarElementosEnSubconjunto(m,fila,0,columna);
            if(sumatoriaSubconjuntoFila == n){
                int numeroFila = fila;
                subfilaActual = armarSubVector(m,fila,0,columna);
                tuple<vector<int>, int> filaYUbicacion = make_tuple(subfilaActual,numeroFila);
                subFilaActualYNumero.push_back(filaYUbicacion);
            }
        }
    }
    /* Finalmente se quitan aquellas subconjuntos que se encuentran en la misma fila */
    for(int i = 0; i < subFilaActualYNumero.size(); i++){
        int numFila = get<1>(subFilaActualYNumero[i]);
        if(apariciones(subFilaActualYNumero,numFila,0,i) == 0){
            /* Primera aparicion del subconjunto en la fila. Se colocan los elementos en el vector */
            vector<int> subconjuntoActual = get<0>(subFilaActualYNumero[i]);
            for(int j = 0; j < subconjuntoActual.size(); j++){
                elementosFilasSinRepetidas.push_back(subconjuntoActual[j]);
            }
        }
    }
    return elementosFilasSinRepetidas;
}
