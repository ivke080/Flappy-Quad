#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>
#include "globals.h"
#include "player.h"
#include "pipe.h"

static Player player;
static Pair pair[2];

void input(unsigned char key, int x, int y);
void render(void);
void tick(int id);

int main(int argc, char* argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-WINDOW_WIDTH) / 2,
                     (glutGet(GLUT_SCREEN_HEIGHT)-WINDOW_HEIGHT)/2);
  glutCreateWindow("Flappy Quad v1.0");

  srand(time(NULL));

  glutKeyboardFunc(input);
  glutDisplayFunc(render);
  glutTimerFunc(TIMER_INTERVAL, tick, TIMER_ID);

  /* player initialization */
  player.size = 20;
  player.x = WINDOW_WIDTH/2-player.size/2;
  player.y = WINDOW_HEIGHT/2-player.size/2;
  player.yvel = player.xvel = 0;
  player.jump = -6.5;
  player.alive = 1;


  /* pipes initialization */
  pair[0] = create_pair(300, 0, 50, 1.5);
  pair[1] = create_pair(pair[0].p1.x+PIPE_DISTANCE, 0, 50, 1.5);


  glClearColor(1, 1, 1, 0);
  glEnable(GL_DEPTH_TEST);

  glutMainLoop();

  return 0;
}
void input(unsigned char key, int x, int y) {

  switch (key) {
    case 27:
      /* escape character - exit game */
      exit(0);
      break;
    case 32:
      /* space character - jump */
      player.yvel = player.jump;
      break;
  }
}

void render(void) {

  int i;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);

  render_player(&player);
  for (i = 0; i < 2; i++)
    render_pair(&pair[i]);




  glutSwapBuffers();
}
void tick(int id) {
  if(player.alive) {
    int i;

    if (id != TIMER_ID) return;

    update_player(&player);
    for (i = 0; i < 2; i++) {
      update_pair(&pair[i],pair[(i+1)%2].p1.x);
      if (collision_pair(&player, &pair[i]))
        player.alive = 0;
    }
  }
  else {
    dead_for += glutGet(GLUT_ELAPSED_TIME);
    if (dead_for > 200000) // 2 seconds
    {
      exit(1);
    }
  }
  glutPostRedisplay();
  glutTimerFunc(TIMER_INTERVAL, tick, TIMER_ID);
}
