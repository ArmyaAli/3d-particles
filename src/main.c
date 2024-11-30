#include "global.h"
#include "raylib.h"
#include <stdio.h>

void Init();
void Update();
void Draw();

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  Init();

  // Camera init
  // Define the camera to look into our 3d world
  Camera camera = { 0 };
  camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

  float x = 1.0;
  while(!WindowShouldClose()) {
    Vector2 mouse = GetMousePosition();
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);
    ClearBackground(RAYWHITE);
    BeginDrawing();
    BeginMode3D(camera);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      printf("x: %f, y: %f\n", mouse.x, mouse.y);
      particle_list_add(PARTICLE_BUFFER, (Vector3){2.0f,2.0f,1.0f}, RED);
      printf("Added to the list\n");
    }
    Update();
    DrawSphere((Vector3){1.0f, 1.0f, x}, 1.0f, RED);
    x += 0.1f;
    DrawGrid(10, 1.0f);
    Draw();
    EndMode3D();
    EndDrawing();
    particle_list_print(PARTICLE_BUFFER);
  }
}

void Init() {
  SetTargetFPS(60); // 60 FPS
   DisableCursor();
  // let's init our particle list
  PARTICLE_BUFFER = init_particle_list();
}

void Update() {

}

void Draw() {
    for(int i = 0; i < PARTICLE_BUFFER->size; ++i) {
      particle_t entry = PARTICLE_BUFFER->data[i];
      if(entry.active) { 
        DrawSphere(entry.pos, entry.radius, entry.color);
      }
    }
    DrawGrid(10, 1.0f);
}
