#ifndef GUI_GAMEFRAME_C
#define GUI_GAMEFRAME_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <pthread.h>
#include <math.h> 
#include <signal.h>

#include "types.h"
#include "util.h"
#define GUI_WIDGET
#include "gui.h"
#undef GUI_WIDGET
#include "gui_stats.h"

////////////////////////////////////////////////////////////////////////////////

void Stats_Draw(widget_t *w)
{
  //stats_gui_t *gf = (stats_gui_t*)w->wd;
  char buf[1024];

  // Draw the xp info:
  Yellow();
  sprintf(buf,"XP:");
  glRasterPos2f(0.1f, 0.1f);
  printGLf(w->glw->font,"%s",buf);
  sprintf(buf,"%.1lf",Statec->player.xp);
  glRasterPos2f(0.4f, 0.1f);
  printGLf(w->glw->font,"%s",buf);

  // Draw the mana info:
  Purple();
  sprintf(buf,"Mana:");
  glRasterPos2f(0.1f, 0.2f);
  printGLf(w->glw->font,"%s",buf);
  sprintf(buf,"%.1lf /",Statec->player.mana);
  glRasterPos2f(0.4f, 0.2f);
  printGLf(w->glw->font,"%s",buf);
  sprintf(buf,"%.0lf",Statec->player.base_mana);
  glRasterPos2f(0.4f, 0.3f);
  printGLf(w->glw->font,"%s",buf);

  // Draw the wave info:
  Green();
  sprintf(buf,"Wave:");
  glRasterPos2f(0.1f, 0.4f);
  printGLf(w->glw->font,"%s",buf);
  sprintf(buf,"%lu",Statec->wave);
  glRasterPos2f(0.4f, 0.4f);
  printGLf(w->glw->font,"%s",buf);

  // Outline
  Yellow();
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.0f,0.0f);
  glVertex2f(0.0f,1.0f);
  glVertex2f(1.0f,1.0f);
  glVertex2f(1.0f,0.0f);
  glEnd();
}

#endif // !GUI_STATS_C
