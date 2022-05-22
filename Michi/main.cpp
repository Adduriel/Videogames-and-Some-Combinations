#include <iostream>
#include <stdio.h>

using namespace std;

bool turnodeX = false;


char tablero[][3] = {{'_','_','_'},
                      {'_','_','_'},
                      {'_','_','_'}
};

char Ganador(){
    //Val. Horizontal
    for(int i=0 ; i<3 ; i++){
        if(tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]){
        return tablero[i][0];
       }
    }
    //Val. Vertical
    for(int i=0 ; i<3 ; i++){
        if(tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]){
        return tablero[0][i];
       }
    }
    //Val. Diagonal Izquierda
     if(tablero[0][0] != '_' && tablero[0][1] == tablero[1][1] && tablero[1][1] == tablero[2][2]){
        return tablero[0][0];
       }
    //Val Diagonal Derecha
     if(tablero[0][2] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]){
        return tablero[0][2];
       }
}

bool Empate(){
    for (int i = 0; i<3; i++){
        for(int j = 0; j<3 ; j++){
            if(tablero[i][j]=='_'){
                return false;
            }
        }
    }
    return true;
}

void mostrarTablero(){
    char jugador = turnodeX ? 'X' : 'O';
    int fila = 0;
    int columna = 0;
    for (int i = 0; i<3; i++){
        for(int j = 0; j<3 ; j++){
            cout<<tablero[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Es el turno de  "<<jugador<<endl;
    cout<<"¿En que fila deseas jugar? ";
    cin>>fila;
    cout<<"¿En que columna deseas jugar? ";
    cin>>columna;
    tablero[fila][columna] = jugador;
    char hayganador = Ganador();
    if(hayganador != '_'){
        cout<<" Usted Ha Ganado, Felicidades "<< hayganador;
        exit(0);
    }
    if(Empate()){
        cout<<" Hay Empate "<< endl;
        exit(0);
    }
    turnodeX = !turnodeX;
}

int main(){
    while(true){
        mostrarTablero();
    }
}