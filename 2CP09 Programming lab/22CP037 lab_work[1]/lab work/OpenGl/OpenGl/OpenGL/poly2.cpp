#include "glut.h"
GLfloat cube[8][3]={{-100,-100,100},{100,-100,100},{100,100,100},{-100,100,100},
{-100,-100,-100},{100,-100,-100},{100,100,-100},{-100,100,-100}};
GLint indic[6][4]={{0,1,2,3},{4,7,6,5},{0,3,7,4},{1,5,6,2},{3,2,6,7},{0,4,5,1}};
// int  indic1[24]={0,1,2,3,4,5,6,7,0,3,7,4,1,2,6,5,3,2,6,7,0,1,5,4};
int i,rotate;
GLint angle=30,anglex=30;
void init(void)
{
	glClearColor(0,0,0,0);
    
	glEnableClientState(GL_VERTEX_ARRAY);

	glPolygonMode(GL_FRONT,GL_LINE);
	glPolygonMode(GL_BACK,GL_LINE);
}
void reshape(int w,int h)
{
glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-320,320,-240,240,-200,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void mydisp(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	
	glRotatef(angle,0,1,0);
	glRotatef(anglex,1,0,0);
     


	//glBegin(GL_TRIANGLES);
	//glVertex2i(100,150);
	//glVertex2i(150,67);
	//glVertex2i(180,170);
	//glEnd();
	
	glVertexPointer(3,GL_FLOAT,0,cube);
	
//	glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
	for(i=0;i<6;i++)
	{
		 glVertex3fv(&cube[indic[i][0]][0]);
         glVertex3fv(&cube[indic[i][1]][0]);
		 glVertex3fv(&cube[indic[i][2]][0]);
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
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keyb);
    glutMouseFunc(mouse);
	glutMainLoop();
}