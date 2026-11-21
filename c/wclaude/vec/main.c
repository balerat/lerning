// main.c
#include "vec2.h"
#include <math.h>
#include <stdio.h>
int main(void) {
  double pi = acos(-1.0);
  Vec2 a = {1, 2};
  Vec2 b = {3, 4};
  vec2_print(vec2_add(a, b));
  vec2_print(vec2_sub(a, b));
  Vec2 c = {1, -2};
  vec2_print(vec2_scale(c, 3));
  printf("%.3f\n", vec2_dot(a, b));
  printf("%.3f\n", vec2_length(b));
  printf("%.3f\n", vec2_length(vec2_normalize(b)));
  Vec2 zero = {0, 0};
  printf("%.3f\n", vec2_length(vec2_normalize(zero)));
  Vec2 X = {1, 0};
  vec2_print(vec2_rotate(X, pi / 2));
  vec2_print(vec2_rotate(X, pi));
  return 0;
}
