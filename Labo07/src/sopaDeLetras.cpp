#include "sopaDeLetras.h"

vector<vector<char>> armarPalabrasDesde(vector<vector<char>> s, int f, int c){
    vector<vector<char>> palabrasFormadas;
    vector<char> palabraHorizontal;
    vector<char> palabraVertical;

    if(f > s.size()-4){
        /* Caso de las ultimas 3 filas donde solo voy a poder formar palabras horizontales */
        for(int columna = c; columna < c+4; columna++){
            palabraHorizontal.push_back(s[f][columna]);
        }
        palabrasFormadas.push_back(palabraHorizontal);
    } else if(c > s.size()-4){
        /* Caso cualquier otra fila pero el caracter comienza en alguna de las ultimas 3 columnas. Solo voy a poder formar palabras verticales */
        for(int fila = f; fila < f+4; fila++){
            palabraVertical.push_back(s[fila][c]);
        }
        palabrasFormadas.push_back(palabraVertical);
    } else {
        /* Cualquier otro caso busca palabras horizntales y verticales */
        for(int columna = c; columna < c+4; columna++){
            palabraHorizontal.push_back(s[f][columna]);
        }
        palabrasFormadas.push_back(palabraHorizontal);

        for(int fila = f; fila < f+4; fila++){
            palabraVertical.push_back(s[fila][c]);
        }
        palabrasFormadas.push_back(palabraVertical);
    }
    return palabrasFormadas;
}

int sopaDeLetras(vector<vector<char>> m){
    int aparicionesSopa;
    char sopa[5] = "sopa";

    if(m.size() < 4){
        /* En todas las matrices de dimension menor a 4x4 no entra la palabra "sopa" */
        aparicionesSopa = 0;
    } else {
        /* Caso de matrices con dimensiones mayores o iguales a 4x4 */
        for(int fila = 0; fila < m.size(); fila++){
            for(int columna = 0; columna < m[fila].size(); columna++){
                if(!((fila > m.size()-4) && (columna > m[fila].size()-4))){
                    /* Caracteres que voy a considerar */
                    vector<vector<char>> palabrasHorizontalesVerticales = armarPalabrasDesde(m,fila,columna);
                    for(int i = 0; i < palabrasHorizontalesVerticales.size(); i++){
                        int j = 0;
                        while((j < 4) && (strcmp(&palabrasHorizontalesVerticales[i][j], &sopa[j]) == 0)){
                            j++;
                        }
                        if(j == 4){
                            aparicionesSopa++;
                        }
                    }
                }
                /* Caso contrario, no voy a considerarlos porque quedan en una matriz de 3x3 */
            }
        }
    }
    return aparicionesSopa;
}

// sopaso pad
// osdsds dsd
// phghjh jhj
// asdsop ads
// dubled fdf
// dadsdd sds
// auhjhj *yuu
// iywwed *fdg
// vcbfbg *sdv

