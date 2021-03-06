#include "raylib.h"
#include <stdio.h>

#include "World.h"
#include "libs/raylib/src/external/stb_truetype.h"

#define SCREEN_WIDTH (640)
#define SCREEN_HEIGHT (480)


#define each(item, array, length) \
(typeof(*(array)) *p = (array), (item) = *p; p < &((array)[length]); p++, (item) = *p)




#define foreach(item, array) for(int i = 0; i < sizeof(array) * 3; i += 1) { \
                            item = array[i];                                 \
                            DrawCube((Vector){item.x,item.y,item.z},1,1,1,BLUE);                       \
}\

struct Player {
    float x;
    float y;
    float z;
} player;



int main(void)
{

    World world;
    world.generate(0,0);


    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d picking");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = { 10.0f, 10.0f, 5.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

    Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
    Vector3 cubeSize = { 2.0f, 2.0f, 7.0f };

    Ray ray = { 0 };                    // Picking line ray

    bool collision = false;

    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

//    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    Vector3 start = {0,0,0};
    Vector3 end = {0,9,0};




    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {

        camera.target = { player.x, player.z, player.y };

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);          // Update camera

//        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//        {
//            if (!collision)
//            {
//                ray = GetMouseRay(GetMousePosition(), camera);
//
//                // Check collision between ray and box
//                collision = CheckCollisionRayBox(ray,
//                                                 (BoundingBox){(Vector3){ cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2 },
//                                                               (Vector3){ cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2 }});
//            }
//            else collision = false;
//        }


//        switch (GetKeyPressed()) {
//            case KEY_A: {
//                player.x -= 1;
//                printf("A has been pressed");
//                break;
//            }
//            case KEY_W: {
//                player.y += 1;
//                break;
//            }
//            case KEY_D: {
//                player.x += 1;
//                break;
//            }
//            case KEY_S: {
//                player.y -= 1;
//                break;
//            }
//        }

        const float speed =  0.02f;
        if(IsKeyDown(KEY_W)) {
            player.x -= speed;
        }
        if(IsKeyDown(KEY_S)) {
            player.x += speed;
        }
        if(IsKeyDown(KEY_A)) {
            player.y += speed;
        }
        if(IsKeyDown(KEY_D)) {
            player.y -= speed;
        }



        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);


        DrawLine3D(start,end,BLUE);

        DrawRay(ray, MAROON);
        DrawGrid(10, 1.0f);


        DrawCube({player.x,1,player.y},1,1,1,RED);

//
//        struct Block item;
//        foreach(item, chunk.blocks)

        for(Block &bl : world.blocks) {
            DrawCube({bl.x,bl.y,bl.z},1,1,1,bl.color);
        }


        EndMode3D();

//        DrawText("Try selecting the box with mouse!", 240, 10, 20, DARKGRAY);

//        if(collision) DrawText("BOX SELECTED", (screenWidth - MeasureText("BOX SELECTED", 30)) / 2, screenHeight * 0.1f, 30, GREEN);

        DrawFPS(10, 10);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------



    // Hello World

    return 0;
}
