#include <stdio.h>
#include <GL/glut.h>
#include "globals.h"
#include "player.h"
#include "pipe.h"

int collision_pipe(const Player* player, const Pipe* pipe) {
   if (player->x < pipe->x + pipe->width &&
       player->x + player->size > pipe->x &&
       player->y < pipe->y + pipe->height &&
       player->y + player->size > pipe->y) {
      
      return 1;   
   }
   return 0;
}
int collision_pair(const Player* player, const Pair* pair) {
  if (collision_pipe(player, &(pair->p1))) return 1;
  if (collision_pipe(player, &(pair->p2))) return 1;
  return 0;
}
void update_player(Player* player) {
  
  
  player->yvel += GRAVITY;
  player->y += player->yvel;
  
  
  if (player->y + player->size >= WINDOW_HEIGHT) {
    player->yvel = 0;
    player->y = WINDOW_HEIGHT - player->size;
  }
  if (player->y < 0) {
    player->yvel = 0;
    player->y = 0;
  }
  
}
void render_player(const Player *player) {
  
  glColor3f(1, 0, 0);
  
  glBegin(GL_POLYGON);
    glVertex3f(player->x, player->y, 0);
    glVertex3f(player->x+player->size,player->y, 0);
    glVertex3f(player->x+player->size,player->y+player->size, 0);
    glVertex3f(player->x,player->y+player->size, 0);
  glEnd();
  
}





















