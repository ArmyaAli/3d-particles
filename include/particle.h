#ifndef PARTICLE_H
#define PARTICLE_H
#define INIT_SIZE 1000

#include "raylib.h"

typedef struct particle {
  Vector3 pos;
  Vector3 vel;
  Vector3 acc;
  Color color;
  float radius;
  int active;
} particle_t;

typedef struct particle_list {
  particle_t* data;
  int size;
} particle_list_t;

particle_list_t* init_particle_list();
void particle_list_add(particle_list_t* list, Vector3 pos, Color color);
void particle_list_clear(particle_list_t*);
void particle_list_print(particle_list_t*);

void updatePos(particle_t* p, Vector3 vel);
void updateVel(particle_t* p, Vector3 acc);

#endif
