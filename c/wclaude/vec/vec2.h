// vec2.h
#ifndef VEC2_H

#define VEC2_H


typedef struct {
  double x;
  double y;
} Vec2;

Vec2 vec2_add(Vec2 a, Vec2 b);

Vec2 vec2_sub(Vec2 a, Vec2 b);

Vec2 vec2_scale(Vec2 v, double s);

double vec2_dot(Vec2 a, Vec2 b);

double vec2_length(Vec2 v);

Vec2 vec2_normalize(Vec2 v);

Vec2 vec2_rotate(Vec2 v, double angle);

void vec2_print(Vec2 v);

#endif
