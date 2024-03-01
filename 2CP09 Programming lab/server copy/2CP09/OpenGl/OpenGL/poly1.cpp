#include "glut.h"
#include <windows.h> 
#include <math.h>
#include "bmp.h"
#include "bmp.cpp"

GLfloat cube[8][3]={{-100,-100,100},{100,-100,100},{100,100,100},{-100,100,100},
{-100,-100,-100},{100,-100,-100},{100,100,-100},{-100,100,-100}};
GLint indic[6][4]={{0,1,2,3},{4,7,6,5},{0,3,7,4},{1,5,6,2},{3,2,6,7},{0,4,5,1}};
GLfloat normal[8][3]={{-0.3,-0.3,0.3},{0.3,-0.3,0.3},{0.3,0.3,0.3},{-0.3,0.3,0.3},{-0.3,-0.3,-0.3},{0.3,-0.3,-0.3},{0.3,0.3,-0.3},{-0.3,0.3,-0.3}};
// int  indic1[24]={0,1,2,3,4,5,6,7,0,3,7,4,1,2,6,5,3,2,6,7,0,1,5,4};
int i,rotate;
GLint angle=30,anglex=30;
GLubyte *bits;
BITMAPINFO *info;
static GLuint texName;
#define XMIN -100
#define XMAX 100
#define YMIN -100
#define YMAX 100
//void MapCoordinates(GLfloat x,GLfloat y, GLfloat z, int mapping) 
//{
//  glTexCoord2f((x-XMIN)/(XMAX-XMIN),(y-YMIN)/(YMAX-YMIN));
//}
void init(void)
{
	glClearColor(0,0,0,0);
    
	glEnableClientState(GL_VERTEX_ARRAY);
	glViewport(0,640,0,480);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT,GL_FILL);
   // glPolygonMode(GL_FRONT,GL_LINE);
	glPolygonMode(GL_BACK,GL_FILL);
	//glPolygonMode(GL_FRONT,GL_LINE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                   GL_NEAREST);



   bits = ReadBitmap("checktexture.bmp", &info);
   glTexImage2D(GL_TEXTURE_2D, 0,3, info->bmiHeader.biWidth, 
                info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, 
                bits);

   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   GLfloat light_position[] = { 400,10,400,1 };
   GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   glShadeModel (GL_SMOOTH);

}
void mydisp(void)
{
	GLfloat x,y,z;
	int mapping=1;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-320,320,-240,240,-200,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	glRotatef(angle,0,1,0);
	glRotatef(anglex,1,0,0);
     


	//glBegin(GL_TRIANGLES);
	//glVertex2i(100,150);
	//glVertex2i(150,67);
	//glVertex2i(180,170);
	//glEnd();
	

	glVertexPointer(3,GL_FLOAT,0,cube);
	/*glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-3.0, 0.0, 0.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(-3.0, 1.0, 0.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(-2.0, 0.0, 0.0);
   glEnd();

   glTranslatef(-3.,1.5,-1.5);
	*/
//	glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
	for(i=0;i<6;i++)
	{    
		
		x=cube[indic[i][0]][0];
		y=cube[indic[i][0]][1];
		z=cube[indic[i][0]][2];
		//MapCoordinates(x,y,z,mapping);
		/*glNormal3fv(&normal[indic[i][0]][0]);
		glNormal3fv(&normal[indic[i][0]][1]);
		glNormal3fv(&normal[indic[i][0]][2]);
		glnormal3fv(&normal[indic[i][0]][3]);*/
         x=cube[indic[i][1]][0];
		y=cube[indic[i][1]][1];
		z=cube[indic[i][1]][2];
		//MapCoordinates(x,y,z, mapping);
        /*glNormal3fv(&normal[indic[i][1]][0]);
		glNormal3fv(&normal[indic[i][1]][1]);
		glNormal3fv(&normal[indic[i][1]][2]);
		glnormal3fv(&normal[indic[i][1]][3]);*/
		x=cube[indic[i][2]][0];
		y=cube[indic[i][2]][1];
		z=cube[indic[i][2]][2];
		//MapCoordinates(x,y,z, mapping);
		/*glNormal3fv(&normal[indic[i][2]][0]);
		glNormal3fv(&normal[indic[i][2]][1]);
		glNormal3fv(&normal[indic[i][2]][2]);
		glnormal3fv(&normal[indic[i][2]][2]);*/
		x=cube[indic[i][3]][0];
		y=cube[indic[i][3]][1];
		z=cube[indic[i][3]][2];
		//MapCoordinates(x,y,z, mapping);
glNormal3fv(&normal[indic[i][0]][0]);
		glNormal3fv(&normal[indic[i][1]][0]);
		glNormal3fv(&normal[indic[i][2]][0]);
		glNormal3fv(&normal[indic[i][3]][0]);
    glTexCoord2f(0.0, 0.0); 
glVertex3fv(&cube[indic[i][0]][0]);
   glTexCoord2f(0.0, 1.0); 
glVertex3fv(&cube[indic[i][1]][0]);

   glTexCoord2f(1.0, 1.0); 
   glVertex3fv(&cube[indic[i][2]][0]);
   glTexCoord2f(1.0, 0.0);
 
         
		 
		 glVertex3fv(&cube[indic[i][3]][0]);

	}
   glEnd();
	//	glDrawElements(GL_QUADS,24,GL_UNSIGNED_INT,indic1);
	glFlush();
}

void keyb(unsigned char key, int x, int y){
  if(key==49){
    angle=angle+10;
	angle=angle%360;
	glutPostRedisplay();

  }else if(key==50){
    rotate=2;
  }  
  else if(key==51){
	  rotate=3;
  }
  else
{ rotate = 0; }
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN)
							  anglex=anglex+10;
		anglex=anglex%360;                    
		glutPostRedisplay();
		
		break;
	default : break;
	}
}

void main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first");
	//glEnable(GL_DEPTH_TEST);
    init();
	glutDisplayFunc(mydisp);
	glutKeyboardFunc(keyb);
    glutMouseFunc(mouse);
	glutMainLoop();
}