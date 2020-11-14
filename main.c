#include "raylib.h"

#define SCREEN_WIDTH (640)
#define SCREEN_HEIGHT (480)

struct {

    float xpos;
    float ypos;
    float width;
    float height;


    float moveSpeed;

} player;


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d picking");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
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
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);          // Update camera

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (!collision)
            {
                ray = GetMouseRay(GetMousePosition(), camera);

                // Check collision between ray and box
                collision = CheckCollisionRayBox(ray,
                                                 (BoundingBox){(Vector3){ cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2 },
                                                               (Vector3){ cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2 }});
            }
            else collision = false;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        if (collision)
        {
            DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED);
            DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, MAROON);

            DrawCubeWires(cubePosition, cubeSize.x + 0.2f, cubeSize.y + 0.2f, cubeSize.z + 0.2f, GREEN);
        }
        else
        {
            DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, GRAY);
            DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, DARKGRAY);
        }

        if(IsKeyPressed(' ')) {
            end.x += 10;
        }

        DrawLine3D(start,end,BLUE);

        DrawRay(ray, MAROON);
        DrawGrid(10, 1.0f);


        EndMode3D();

        DrawText("Try selecting the box with mouse!", 240, 10, 20, DARKGRAY);

        if(collision) DrawText("BOX SELECTED", (screenWidth - MeasureText("BOX SELECTED", 30)) / 2, screenHeight * 0.1f, 30, GREEN);

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
