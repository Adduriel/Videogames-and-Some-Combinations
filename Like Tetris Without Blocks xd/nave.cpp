#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main(){
    
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = 4;
    dwPos.Y = 5;

    SetConsoleCursorPosition(hCon, dwPos);
    printf("*");
    return 0;
}