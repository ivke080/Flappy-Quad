#ifndef PLAYER_H_
#define PLAYER_H_
#include "pipe.h"

typedef struct {
  float x, y; /* coordinates of the player */
  float xvel, yvel; /* x and y velocity */
  float jump; /* jump velocity */
  float size;
} Player;

void update_player(Player *player);
void render_player(const Player *player);
int collision_pipe(const Player* player, const Pipe* pipe);
int collision_pair(const Player* player, const Pair* pair);

#endif
