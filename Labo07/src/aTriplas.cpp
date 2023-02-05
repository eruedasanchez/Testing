#include "aTriplas.h"

tuple<tuple<int, int>, vector<tuple<int, int, int>>> aTriplas(vector<vector<int> > m){
    /* Creacion de la tupla con la cantidad de filas y columnas de la matriz */
        int filasMatriz = m.size();
        int columnasMatriz = m[0].size();
        tuple<int, int> filasYColumnas = make_tuple(filasMatriz, columnasMatriz);

        /* A continuacion, se arma el vector con los elementos distintos de cero detallando sus coordenadas */
        vector<tuple<int, int, int>> distintosCero;
        for(int fila = 0; fila < m.size(); fila++){
            for(int columna = 0; columna < m[fila].size(); columna++){
                if(m[fila][columna] != 0){
                    tuple<int, int, int> elemYCoordenadas = make_tuple(m[fila][columna], fila, columna);
                    distintosCero.push_back(elemYCoordenadas);
                }
            }
        }

        /* Finalmente, se arma la tupla con ambos resultados */
        tuple<tuple<int, int>, vector<tuple<int, int, int>>> resultado = make_tuple(filasYColumnas, distintosCero);
        return resultado;
}