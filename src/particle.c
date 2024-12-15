#include "particle.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

particle_list_t* init_particle_list() {
  particle_list_t* list = (particle_list_t*)malloc(sizeof(particle_list_t));
  list->data = (particle_t*)malloc(sizeof(particle_t) * INIT_SIZE);
  list->size = 0;
  return list;
}

void particle_list_add(particle_list_t* list, Vector3 pos, Color color) {
  particle_t p;
  p.pos = pos;
  p.vel = (Vector3){0,0,0};
  p.acc = (Vector3){0,0,0};
  p.radius = 1 + rand() % 25;
  p.color = color;
  p.active = 1;

  int size = list->size;
  list->data[size] = p;
  ++list->size;
}

void updatePos(particle_t* p, Vector3 vel) {
  p->pos.x += vel.x;
  p->pos.y += vel.y;
  p->pos.z += vel.z;
}

void updateVel(particle_t* p, Vector3 acc) {
  p->vel.x += acc.x;
  p->vel.y += acc.y;
  p->vel.z += acc.z;
}

void particle_list_clear(particle_list_t* list) {
  for(int i = 0; i < list->size; ++i) {
    list->data[i].active = 0;
  }
}
void particle_list_print(particle_list_t* list) {
  printf("BEGIN: LIST_SIZE=%d\n", list->size);
  for(int i = 0; i < list->size; ++i) {
    printf("i=%d\n", i);
  }
  printf("END: LIST_SIZE=%d\n", list->size);
}
