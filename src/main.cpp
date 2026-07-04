#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);
void timer(int);

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv); // initializes glut library

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("archwindow");
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(0, timer, 0);
  init();

  glutMainLoop();
  return 0;
}

float x_position = 0.0;
float y_position = 0.0;
int x_state = 1;
int y_state = 1;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity(); // resets transformations/coordinate system

  // translate THEN draw
  glTranslatef(x_position, y_position, 0.0);
  
  // draw
  glBegin(GL_POLYGON);

  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-1.0, 1.0);
  glVertex2f(-1.0, -1.0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(1.0, -1.0);
  glVertex2f(1.0, 1.0);

  glEnd();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  // viewport
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

  // projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10, 10, -10, 10);

  glMatrixMode(GL_MODELVIEW); // should always be int the model view matrix
}

void timer(int) {
  glutPostRedisplay(); 
  glutTimerFunc(1000/60, timer, 0);
  
  if (x_state == 1) {
    if (x_position < 9) {
      x_position += 0.2;
    } else {
      x_state = -1;
    }
  } else {
    if (x_position > -9) {
      x_position -= 0.2;
    } else {
      x_state = 1;
    }
  }

  if (y_state == 1) {
    if (y_position < 9) {
      y_position += 0.3;
    } else {
      y_state = -1;
    }
  } else {
    if (y_position > -9) {
      y_position -= 0.3;
    } else {
      y_state = 1;
    }
  }
}
