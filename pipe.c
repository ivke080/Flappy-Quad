#include <GL/glut.h>
#include <math.h>
#include "pipe.h"
#include "globals.h"

void update_pair(Pair* pair, float next_x) {
  
  pair->p1.x -= pair->speed;
  pair->p2.x -= pair->speed;
  
  /* if pipe is out of screen, move it to the right */
  if (pair->p1.x + pair->p1.width < 0) {
    pair->p1.x = pair->p2.x = next_x + PIPE_DISTANCE ;
    pair->p1.height = rand()%(TOP_PIPE-BOTTOM_PIPE) + BOTTOM_PIPE;
    pair->p2.y = pair->p1.height + PIPE_GAP;
    pair->p2.height = WINDOW_HEIGHT - pair->p2.y;
    
  }
}
void render_pair(const Pair* pair) {
  
  glColor3f(0, 0, 1);
  
  glBegin(GL_POLYGON);
    glVertex3f(pair->p1.x, pair->p1.y, 0);
    glVertex3f(pair->p1.x+pair->p1.width,pair->p1.y, 0);
    glVertex3f(pair->p1.x+pair->p1.width,pair->p1.y+pair->p1.height, 0);
    glVertex3f(pair->p1.x,pair->p1.y+pair->p1.height, 0);
  glEnd();
  
  glBegin(GL_POLYGON);
    glVertex3f(pair->p2.x, pair->p2.y, 0);
    glVertex3f(pair->p2.x+pair->p2.width,pair->p2.y, 0);
    glVertex3f(pair->p2.x+pair->p2.width,pair->p2.y+pair->p2.height, 0);
    glVertex3f(pair->p2.x,pair->p2.y+pair->p2.height, 0);
  glEnd();
}
Pair create_pair(float x, float y, float width, float speed) {
  Pair pair;
  pair.p1.x = x;
  pair.p1.y = y;
  pair.p1.width = width;
  pair.p1.height = rand()%(TOP_PIPE-BOTTOM_PIPE) + BOTTOM_PIPE;
  
  pair.p2.x = x;
  pair.p2.y = pair.p1.height + PIPE_GAP;
  pair.p2.width = width;
  pair.p2.height = WINDOW_HEIGHT - pair.p2.y;
  
  pair.speed = speed;
  
  return pair;
}












