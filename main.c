#include <stdio.h>
#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)



struct {

    float xpos;
    float ypos;
    float width;
    float height;


    float moveSpeed;

} player;



int main() {

    player.xpos = 150;
    player.ypos = 150;
    player.moveSpeed = 6;

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Hello World");



    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        ClearBackground(RAYWHITE);


        BeginDrawing();



        DrawRectangle(player.xpos, player.ypos, 50, 50, RED);


        if(IsKeyDown('A')) {
            player.xpos -= 16 * GetFrameTime() * player.moveSpeed;
        }
        if(IsKeyDown('D')) {
            player.xpos += 16 * GetFrameTime() * player.moveSpeed;
        }
        if(IsKeyDown('W')) {
            player.ypos -= 16 * GetFrameTime() * player.moveSpeed;
        }
        if(IsKeyDown('S')) {
            player.ypos += 16 * GetFrameTime() * player.moveSpeed;
        }


        EndDrawing();

    }


    CloseWindow();


    return 0;
}
