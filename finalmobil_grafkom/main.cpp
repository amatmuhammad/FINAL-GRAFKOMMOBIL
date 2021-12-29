#include <windows.h> /*di push oleh rahmat */
#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>
#include <string.h>

/* ASCII code for the escape key. */
#define ESCAPE 27

GLint window;
GLint window2;
GLint Xsize=1000;
GLint Ysize=800;
float i,theta;
GLint nml=0,day=1;

char name3[]="PROJECT:  3D CAR  ANIMATION";

GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;   /* x,y,z translation */
GLfloat tx=295,ty=62;
GLfloat xs=1.0,ys=1.0,zs=1.0;

GLfloat xangle=0.0,yangle=0.0,zangle=0.0,angle=0.0;   /* axis angles */

GLfloat r=0,g=0,b=1;
GLint light=1;
int count=1,flg=1;
int view=0;
int flag1=0,aflag=1;            //to switch car driving mode
int flag2=0,wheelflag=0;   //to switch fog effect
GLUquadricObj *t;

static void SpecialKeyFunc( int Key, int x, int y );

/* Simple  transformation routine */
GLvoid Transform(GLfloat Width, GLfloat Height)
{
  glViewport(0, 0, Width, Height);              /* Set the viewport */
  glMatrixMode(GL_PROJECTION);                  /* Select the projection matrix */
  glLoadIdentity();    /* Reset The Projection Matrix */
  gluPerspective(45.0,Width/Height,0.1,100.0);  /* Calculate The Aspect Ratio Of The Window */
  glMatrixMode(GL_MODELVIEW);                   /* Switch back to the modelview matrix */
}


/* A general OpenGL initialization function.  Sets all of the initial parameters. */
GLvoid InitGL(GLfloat Width, GLfloat Height)
{

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glLineWidth(2.0);              /* Add line width,   ditto */
  Transform( Width, Height ); /* Perform the transformation */
  //newly added
  t=gluNewQuadric();
        gluQuadricDrawStyle(t, GLU_FILL);

glEnable(GL_LIGHTING);

glEnable(GL_LIGHT0);

// Create light components
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat position[] = { 1.5f, 1.0f, 4.0f, 1.0f };

// Assign created components to GL_LIGHT0
glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
glLightfv(GL_LIGHT0, GL_POSITION, position);

}

/* The function called when our window is resized  */
GLvoid ReSizeGLScene(GLint Width, GLint Height)
{
  if (Height==0)     Height=1;                   /* Sanity checks */
  if (Width==0)      Width=1;
  Transform( Width, Height );                   /* Perform the transformation */
}

void init()
{
    glClearColor(0,0,0,0);
 glPointSize(5.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);
 glutPostRedisplay();   // request redisplay
}


/* The main drawing function

   In here we put all the OpenGL and calls to routines which manipulate
   the OpenGL state and environment.

   This is the function which will be called when a "redisplay" is requested.
*/

void display_string(int x, int y, char *string, int font)
{
    int len,i;
 glColor3f(0.8,0.52,1.0);
 glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
 if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
 if(font==3)
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
 if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
 }

}

/*bagian ebi*/



/*bagian eto*/


/*bagian hikmah*/


/*bagian lisa */


/*bagian sarman*/


/*bagian kak muhaimin*/
void myMenu(int id)
{
  if (id==1)
 {
  flag1=0;
  wheelflag=0;
 glutPostRedisplay();

 }
 if(id ==2)
 {
  flag1=1;
  flag2=0;
  wheelflag=0;
  xangle += 5.0;
  glutPostRedisplay();
 }
 if(id==3)
 {
  flag2=1;
  wheelflag=0;
  xangle += 5.0;
  glutPostRedisplay();
 }
 if (id==4)
 {
   wheelflag=1;
   glutPostRedisplay();
 }
 if (id==5)
 {
               if(day)
                {

  if(light)
  {
   count++;
   glDisable(GL_LIGHTING);
   glDisable(GL_LIGHT0);
   light=0;
  }
  else
  {
   count--;
   light=1;
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
  }
  glutPostRedisplay();
                }
               else
                {

                  if(nml==0 && flag2==2)
                     {
                       flag2=0;
                       nml=1;
                     }
                   else
                     {
                         flag2=2;
                 nml=0;

                 aflag=0;
                 day=0;

          glClearColor(0.1,0.1,0.1,0);
          GLfloat fogcolour[4]={0.0,0.0,0.0,1.0};

                 glFogfv(GL_FOG_COLOR,fogcolour);              /* Define the fog colour */
                 glFogf(GL_FOG_DENSITY,0.5);                   /* How dense */
                 glFogi(GL_FOG_MODE,GL_EXP);                   /* exponential decay */
                         /* end */
                glHint(GL_FOG_HINT, GL_FASTEST);              /* compute per vertex */
                glEnable(GL_FOG);


         glutPostRedisplay();
                 }
             }

 }


       if(id==12)
 {
 aflag=1;
        day=1;
 glClearColor(1,1,1,1);
 glDisable(GL_FOG);
 glutPostRedisplay();
 }

 if(id==13)
 {
 aflag=0;
        day=0;
 flag2=2;
 glClearColor(0.1,0.1,0.1,0);
 GLfloat fogcolour[4]={0.0,0.0,0.0,1.0};

  glFogfv(GL_FOG_COLOR,fogcolour);              /* Define the fog colour */
  glFogf(GL_FOG_DENSITY,0.5);                   /* How dense */
  glFogi(GL_FOG_MODE,GL_EXP);                   /* exponential decay */
                         /* end */
  glHint(GL_FOG_HINT, GL_FASTEST);              /* compute per vertex */
  glEnable(GL_FOG);

  glutPostRedisplay();
       }
}



//*bagian kak farhan*/
void colorMenu(int id)
{
  if (id==6)
 {
  r=g=0;
  b=1;
 glutPostRedisplay();

 }
 if(id ==7)
 {
  r=0.8;
  b=g=0;
  glutPostRedisplay();
 }
 if(id==8)
 {
     g=1;
  r=b=0;
  glutPostRedisplay();
 }
 if (id==9)
 {
   r=b=g=0;
   glutPostRedisplay();
 }
 if(id==10)
 {
  b=0;
  r=g=1;
        glutPostRedisplay();
 }
 if(id==11)
 {
  b=r=g=.7;
        glutPostRedisplay();
 }

}

void myreshape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w<=h)
                glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
        else
                glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
        glMatrixMode(GL_MODELVIEW);
        glutPostRedisplay();
}


//*************************** Main ***************************************************************

int main(int argc, char **argv)
{

/* Initialisation and window creation */

  glutInit(&argc, argv);               /* Initialize GLUT state. */

  glutInitDisplayMode(GLUT_RGBA |      /* RGB and Alpha */
                      GLUT_DOUBLE|     /* double buffer */
                      GLUT_DEPTH);     /* Z buffer (depth) */

  glutInitWindowSize(Xsize,Ysize);     /* set initial window size. */
  glutInitWindowPosition(0,0);         /* upper left corner of the screen. */

  glutCreateWindow("3D CAR ANIMATION"); /* Open a window with a title. */

/* Now register the various callback functions */

  glutReshapeFunc(myreshape);
  glutDisplayFunc(DrawGLScene);        /* Function to do all our OpenGL drawing. */
  glutReshapeFunc(ReSizeGLScene);
  glutKeyboardFunc(NormalKey);         /*Normal key is pressed */
  glutSpecialFunc( SpecialKeyFunc );
  InitGL(Xsize,Ysize);
  int submenu=glutCreateMenu(colorMenu);
  glutAddMenuEntry("blue", 6);
 glutAddMenuEntry("red", 7);
 glutAddMenuEntry("green",8);
 glutAddMenuEntry("black",9);
 glutAddMenuEntry("yellow",10);
 glutAddMenuEntry("grey",11);
  glutCreateMenu(myMenu);
 glutAddMenuEntry("car model mode", 1);
 glutAddMenuEntry("car driving mode", 2);
 glutAddMenuEntry("fog effect",3);
 glutAddMenuEntry("wheel effect",4);
 glutAddMenuEntry("toggle light",5);
 glutAddSubMenu("car colors",submenu);
 glutAddMenuEntry("daymode",12);
 glutAddMenuEntry("Night mode",13);
 glutAttachMenu(GLUT_RIGHT_BUTTON);

  /* Now drop into the event loop from which we never return */

  glutMainLoop();                      /* Start Event Processing Engine. */
  return 1;
}






