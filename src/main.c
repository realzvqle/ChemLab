#include "exheaders/raylib.h"
#include "atoms/atom.h"
#include <math.h>
#include <stdio.h>
#include "UI/ui.h"


bool active;

int main(){
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(100, 100, "Chemistry Lab");
    int width = round(GetMonitorWidth(0) / 1.8);
    int height = round(GetMonitorHeight(0) / 2.09);
    printf("Width: %d, Height: %d\n", width, height);
    SetWindowSize(width, height);
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawFPS(GetScreenWidth() - 100, GetScreenHeight() - 50);
        ClearBackground(BLACK);
        Rectangle box = {90, 90, 900, 30};
        char text[512];
        UiDrawTextBox(box, text, 512,&active, RED);
        Element elm = AtReturnElementFromElementName(text);
        if(elm.name == NULL){
            EndDrawing();
            continue;
        } 
        AtReturnElementNameFromProtonNumber(-1);
        char buffer[512];
        sprintf(buffer, "Number: %d -- Valence Electron: %d\n", elm.protons, elm.valence);
        DrawText(buffer, 80, 80, 20, WHITE);
        EndDrawing();
    }
}