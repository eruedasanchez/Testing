#include "contarPicos.h"

bool esPico(vector <vector <int > > m, int f, int c){
    bool pico = true;
    if(f == 0){
        /* Caso 1. Primer fila de la matriz */
        if(c == 0){
            /* Caso 1.a. Primer fila y primer columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else if(c == m.size()-1){
            /* Caso 1.b Primer fila y ultima columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else {
            /* Caso 1.c Primer fila y columnas del "medio" */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        }
    } else if(f == m.size()-1){
        /* Caso 2 Ultima fila de la matriz */
        if(c == 0){
            /* Caso 2.a Ultima fila y primer columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else if(c == m.size() - 1){
            /* Caso 2.b Ultima fila y ultima columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else {
            /* Caso 2.c Ultima fila y columnas del "medio" */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        }
        /* Casos de filas del medio */
    } else if(c == 0){
        /* Caso 3.a Cualquier fila del medio y primera columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
            for(int columna = c; columna <= c+1; columna++){
                if(m[fila][columna] > m[f][c]){
                    pico = false;
                    break;
                }
            }
        }
    } else if (c == m.size()-1){
        /* Caso 3.b Cualquier fila del medio y ultima columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
            for(int columna = c-1; columna <= c; columna++){
                if(m[fila][columna] > m[f][c]){
                    pico = false;
                    break;
                }
            }
        }
    } else {
        /* Caso 4 Cualquier otro valor que no se encuentra en los bordes de la matriz */
        for(int fila = f-1; fila <= f+1 ; fila++){
            for(int columna = c-1; columna <= c+1; columna++){
                if(m[fila][columna] > m[f][c]){
                    pico = false;
                    break;
                }
            }

        }
    }
    return pico;
}

int contarPicos(vector <vector <int > > m){
    int cantPicos = 0;
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            if(esPico(m,fila,columna)){
                cantPicos++;
            }
        }
    }
    return cantPicos;
}

