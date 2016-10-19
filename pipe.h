#ifndef PIPE_H_
#define PIPE_H_

typedef struct {
  float x, y;
  float height, width;
} Pipe;

typedef struct {
  Pipe p1, p2;
  float speed;
} Pair;

void update_pair(Pair* pair, float next_x);
void render_pair(const Pair* pair);
Pair create_pair(float x, float y, float width, float speed);

#endif
