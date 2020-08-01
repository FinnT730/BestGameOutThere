#include <stdio.h>
#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)



struct {

    int xpos;
    int ypos;

    int width;
    int height;

} player;



int main() {

    player.xpos = 150;
    player.ypos = 150;

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Hello World");



    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        ClearBackground(RAYWHITE);


        BeginDrawing();
        if(IsKeyDown(' ')) {
            DrawRectangle(150, 150, 50, 50, RED);
        }
        EndDrawing();

    }


    CloseWindow();


    return 0;
}
