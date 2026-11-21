// vec2.c
#include <math.h>
#include <stdio.h>
#include "vec2.h"


Vec2 vec2_add(Vec2 a, Vec2 b) {
  Vec2 c = {a.x + b.x, a.y + b.y};
  return c;
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
  Vec2 c = {a.x - b.x, a.y - b.y};
  return c;
}

Vec2 vec2_scale(Vec2 v, double s) {
  Vec2 c = {v.x * s, v.y * s};
  return c;
}

double vec2_dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }

double vec2_length(Vec2 v) { return sqrt(vec2_dot(v, v)); }

Vec2 vec2_normalize(Vec2 v) {
  if (v.x == 0 && v.y == 0) {
    Vec2 c = {0, 0};
    return c;
  } else {
    double l = vec2_length(v);
    Vec2 c = {v.x / l, v.y / l};
    return c;
  }
}

Vec2 vec2_rotate(Vec2 v, double angle) {
  Vec2 c = {0, 0};
  angle = - angle;
  c.x = cos(angle) * v.x + sin(angle) * v.y;
  c.y = -sin(angle) * v.x + cos(angle) * v.y;
  return c;
}

void vec2_print(Vec2 v) {
  printf("(%.3f,%.3f)\n", v.x, v.y);
}
