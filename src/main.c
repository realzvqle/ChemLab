#include "exheaders/raylib.h"
#include "atoms/atom.h"
#include <stdio.h>




int main(){
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1920, 1080, "Chemistry Lab");

    while(!WindowShouldClose()){
        BeginDrawing();
        DrawFPS(GetScreenWidth() - 100, GetScreenHeight() - 50);
        ClearBackground(BLACK);
        Atom atom = AtInitializeAtom(5, 10, 10);
        printf("%d\n", AtGetValenceElectrons(&atom));

        DrawText(atom.element.name, 10, 10, 90, atom.element.color);
        EndDrawing();
    }
}