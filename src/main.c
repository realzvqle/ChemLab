#include "exheaders/raylib.h"
#include "atoms/atom.h"
#include <stdio.h>
#include "UI/ui.h"


bool active;

int main(){
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1920, 1080, "Chemistry Lab");

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
        DrawText(buffer, 90, 90, 20, WHITE);
        EndDrawing();
    }
}