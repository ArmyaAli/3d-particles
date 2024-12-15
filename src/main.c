#include "global.h"
#include "raylib.h"
#include <util.h>
#include <stdlib.h>
#include <logger.h>

void Init();
void Update();
void Draw();


int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  Init();


  logger_t Logger; 
  logger_init(&Logger, INFO);
  log(&Logger, INFO, "Setting up Camera"); 

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

    Update();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      float x_rand = rand() % 799;
      float y_rand = rand() % 399;
      float z_rand = rand() % 399;
      print_vector3((Vector3){x_rand, y_rand, z_rand});

      particle_list_add(PARTICLE_BUFFER, (Vector3){x_rand, y_rand, z_rand}, GREEN);

      log(&Logger, INFO, "Mouse button pressed. New Particle added to the list");
    }

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
  // Draw all our particles
  for(int i = 0; i < PARTICLE_BUFFER->size; ++i) {
    particle_t entry = PARTICLE_BUFFER->data[i];
    if(entry.active) { 
      DrawSphere(entry.pos, entry.radius, entry.color);
    }
  }
  // Draw the grid for debugging
  DrawGrid(10, 1.0f);
}
