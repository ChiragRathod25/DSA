#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
// #include <gl/GL.h>
// #include <gl.h>


static int animationPeriod = 4; //animation speed
static int isAnimate = 0;   // flag to check if animation is on or off

const int fact = 2; //dinosour property scaling factor
const int x = 10; //offset of dinosour from left
const double DEG2RAD = 3.1415926535897932384/180;

static double w = 200;  //width of dinosour body
static int flag = 0;  //flag to check if dinosour is jumping
static int walk = 0; //flag to check if dinosour is walking
static int x_ = 2500; //x position of dinosour
using namespace std; 

void animate(int value){
    if(isAnimate){
        glutPostRedisplay();
        //  the window's display callback will be invoked at the next iteration of glutMainLoop.
        
        glutTimerFunc(animationPeriod, animate, 1); 
        //This is another OpenGL function that sets a timer. After 'animationPeriod' milliseconds, the specified function 'animate' will be called with the value 1. This is used to create a loop that updates the animation after a certain period of time.
    } 
}

void keyInput(unsigned char key , int x, int y){
    // two integers x and y which typically represent the mouse position at the time the key was pressed.
    switch(key){
    // This case corresponds to the ESC key (ASCII value 27). If the ESC key is pressed, the program will terminate due to the exit(0)
    case 27:
        exit(0);
    
    //This case corresponds to the spacebar key. If the spacebar is pressed, the code inside this case will execute.
    case ' ':
        if(isAnimate) isAnimate = 0;
        else{
            isAnimate = 1;
            animate(1);
        }
        break;

    }
}

// len is the scaling factor which is used to scale the height of the tree
// collision function checks if the dinosour has collided with the tree, if it has collided, it returns 1, else it returns 0
// The function works by checking the distance between the dinosaur and the tree. If the distance is less than or equal to the sum of the widths of the dinosaur and the tree, then a collision might have occurred.

// In this function, 157 + x is the rightmost x-coordinate of the dinosaur,
// x_ + x + 50 is the leftmost x-coordinate of the tree, 
//100 + x is the sum of the widths of the dinosaur and the tree,
// 5 * fact + w is the height of the dinosaur, 
// 650 * len is the height of the tree.
bool collision(double len){
    // Check if the distance between the dinosaur and the tree is less than or equal to the sum of the widths of the dinosaur and the tree
    if(abs(157 + x - (x_ + x + 50)) <= 100 + x){
        // check if the height of the dinosaur is less than or equal to the height of the tree
        if(5 * fact + w <= 650 * len) return 1;
        return 0;
    }
    return 0;
}

// If the up arrow key is pressed and the flag is 0, the flag is set to 1, which indicates that the dinosaur is jumping.
void specialKeyInput(int key , int x , int y ){
    if( key == GLUT_KEY_UP && flag==0 && w <= 200.0){
        flag  = 1;
    }
    glutPostRedisplay();
}


// This function is used to draw a circle. It takes the following parameters:
// theta: the angle of the circle
// inner_radius: the inner radius of the circle
// outer_radius: the outer radius of the circle
// x: the x-coordinate of the center of the circle
// y: the y-coordinate of the center of the circle
// sin_sign: the sign of the sin function   
// cos_sign: the sign of the cos function
// The function uses the glBegin() and glEnd() functions to draw the circle. It uses the glColor3f() function to set the color of the circle. It then uses a for loop to draw the circle by calculating the x and y coordinates of each point on the circle using the sin and cos functions.
// The function uses the glVertex2f() function to draw each point on the circle.
// The function uses the glEnd() function to end the drawing of the circle.
void draw_circle(double theta, double inner_radius, double outer_radius, int x, int y, int sin_sign = 1, int cos_sign = 1){
    glBegin(GL_POINTS);
    glColor3f(0.0/ 255.0, 0.0/ 255.0, 0.0/ 255.0);
    for(double r = outer_radius; r >= inner_radius; r -= 3.0){
          for(double i = 0; i < theta ; i++){
             double degInRad = i * DEG2RAD;
             glVertex2f( cos_sign * cos(degInRad) * r + x , sin_sign * sin(degInRad) * r + y  );
         }
    }
    glEnd();
}

void generate_tree(int x_, double len){
    int x = 30; //width of tree
    glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0); //color of tree
    
    //draw the tree trunk using GL_POLYGON 
    glBegin(GL_POLYGON); 
        glVertex2f(x_, 250 * len);
        glVertex2f(x_ + x, 250 * len);
        glVertex2f(x_ + x, 650 * len);
        glVertex2f(x_, 650 * len);
    glEnd();

    //draw the tree leaves using draw_circle function
    draw_circle(180.0, 0.0, x / 2, x_ + x / 2, 650 * len);

    //draw the tree leaves using GL_POLYGON, it is used to draw branch of the tree
    glBegin(GL_POLYGON);
        glVertex2f(x_ + x + 25, 400 * len);
        glVertex2f(x_ + x + 50, 400 * len);
        glVertex2f(x_ + x + 50, 600 * len);
        glVertex2f(x_ + x + 25, 600 * len);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 600 * len);

    // another branch of the tree
    glBegin(GL_POLYGON);
        glVertex2f(x_ - 25, 400 * len);
        glVertex2f(x_ - 50, 400 * len);
        glVertex2f(x_ - 50, 600 * len);
        glVertex2f(x_ - 25, 600 * len);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 600 * len);
    draw_circle(90.0, 25, 50, x_ + x, 400 * len, -1);
    draw_circle(90.0, 25, 50, x_, 400 * len, -1, -1);
}

void reset(){
    w = 200;
    flag = 0;
    walk = 0;
    x_ = 2500;
    animationPeriod = 4;  
    isAnimate = 0;    
}


void render( void ){
    glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
    glPointSize(2); //set the point size to 2
    glBegin(GL_POINTS); //begin drawing points
        glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
        for(int i = 0; i < 100; i++){
            glVertex2f(rand() % 2000, 200); 
            glVertex2f((rand() + 31) % 2000, 150);
        }
    glEnd();

    generate_tree(x_, 1.0);

    //  to check x_ value :  If it's not, it sets x_ to a random value between 2000 and 2399. This could be used to move the tree across the screen from right to left.
    if(x_>= 0)
        x_ -= 5;
    else{
        x_ = 2000 + rand()%400;
    }
    glLineWidth(2);

    // horizontal line ground
    glBegin(GL_LINES);
        glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
        glVertex2f(0, 250);
        glVertex2f(2000, 250);
    glEnd();

    glLineWidth(10);

    glBegin(GL_LINES);
        glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);

        glVertex2f(10 + x, 75 * fact + w);
        glVertex2f(10 + x, 45 * fact + w);
        glVertex2f(15 + x, 65 * fact + w);
        glVertex2f(15 + x, 40 * fact + w);
        glVertex2f(20 + x, 60 * fact + w);
        glVertex2f(20 + x, 35 * fact + w);
        glVertex2f(25 + x, 55 * fact + w);
        glVertex2f(25 + x, 35 * fact + w);
        glVertex2f(30 + x, 55 * fact + w);
        glVertex2f(30 + x, 35 * fact + w);
        glVertex2f(35 + x, 55 * fact + w);
        glVertex2f(35 + x, 25 * fact + w);
        glVertex2f(40 + x, 60 * fact + w);
        glVertex2f(40 + x, 5 * fact + w-walk);
        glVertex2f(45 + x, 65 * fact + w);
        glVertex2f(45 + x, 15 * fact + w);
        glVertex2f(45 + x, 10 * fact + w-walk);
        glVertex2f(45 + x, 5 * fact + w-walk);
        glVertex2f(50 + x, 10 * fact + w-walk);
        glVertex2f(50 + x, 5 * fact + w-walk);
        glVertex2f(55 + x, 10 * fact + w-walk);
        glVertex2f(55 + x, 5 * fact + w-walk);
        glVertex2f(50 + x, 65 * fact + w);
        glVertex2f(50 + x, 20 * fact + w);
        glVertex2f(55 + x, 70 * fact + w);
        glVertex2f(55 + x, 25 * fact + w);
        glVertex2f(63 + x, 75 * fact + w);
        glVertex2f(63 + x, 20 * fact + w);
        glVertex2f(70 + x, 115 * fact + w);
        glVertex2f(70 + x, 5 * fact + w+walk);
        glVertex2f(78 + x, 120 * fact + w);
        glVertex2f(78 + x, 25 * fact + w);
        glVertex2f(78 + x, 10 * fact + w+walk);
        glVertex2f(78 + x, 5 * fact + w+walk);
        glVertex2f(85 + x, 10 * fact + w+walk);
        glVertex2f(85 + x, 5 * fact + w+walk);
        glVertex2f(87 + x, 120 * fact + w);
        glVertex2f(87 + x, 115 * fact + w);
        glVertex2f(87 + x, 110 * fact + w);
        glVertex2f(87 + x, 30 * fact + w);
        glVertex2f(95 + x, 120 * fact + w);
        glVertex2f(95 + x, 35 * fact + w);
        glVertex2f(103 + x, 120 * fact + w);
        glVertex2f(103 + x, 75 * fact + w);
        glVertex2f(103 + x, 65 * fact + w);
        glVertex2f(103 + x, 60 * fact + w);
        glVertex2f(110 + x, 65 * fact + w);
        glVertex2f(110 + x, 60 * fact + w);
        glVertex2f(118 + x, 65 * fact + w);
        glVertex2f(118 + x, 55 * fact + w);
        glVertex2f(112 + x, 120 * fact + w);
        glVertex2f(112 + x, 85 * fact + w);
        glVertex2f(112 + x, 80 * fact + w);
        glVertex2f(112 + x, 75 * fact + w);
        glVertex2f(120 + x, 120 * fact + w);
        glVertex2f(120 + x, 85 * fact + w);
        glVertex2f(120 + x, 80 * fact + w);
        glVertex2f(120 + x, 75 * fact + w);
        glVertex2f(126 + x, 120 * fact + w);
        glVertex2f(126 + x, 85 * fact + w);
        glVertex2f(126 + x, 80 * fact + w);
        glVertex2f(126 + x, 75 * fact + w);
        glVertex2f(135 + x, 120 * fact + w);
        glVertex2f(135 + x, 85 * fact + w);
        glVertex2f(135 + x, 80 * fact + w);
        glVertex2f(135 + x, 75 * fact + w);
        glVertex2f(142 + x, 120 * fact + w);
        glVertex2f(142 + x, 85 * fact + w);
        glVertex2f(150 + x, 120 * fact + w);
        glVertex2f(150 + x, 85 * fact + w);
        glVertex2f(157 + x, 115 * fact + w);
        glVertex2f(157 + x, 85 * fact + w);

    glEnd();

    if(collision(1.0)){
        reset();
    }
    // If the flag is 1, the dinosaur is jumping. The height of the dinosaur is increased by 20 units.
    // If the height of the dinosaur is greater than or equal to 200, the flag is set to 0, which indicates that the dinosaur has landed.
    // If the flag is 0, the dinosaur is walking. The width of the dinosaur is increased by 8 units.
    // This could be used to animate the character's legs while walking.
    if( w <=200){
        if(walk==-20 )
            walk = 20;
        // If the character's height w is greater than 200 (meaning the character is in the air), it sets walk to 0, stopping the walking animation.
        else{
            walk = -20;
        }
    }
    else{
        walk = 0;
    }

    if(flag==1){
        if(w<=1000 ){
            w = w + 8;
        }
        else {
            flag = 0;
        }
    }
    else if(w >= 200 )
        w = w - 8;
    glFlush();
}


void setup(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2000, 0.0, 2000);
}

int main( int argc , char** argv ){
    srand(time(NULL));
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowSize( 1230, 650 );
    glutInitWindowPosition( 50 , 0 );
    glutCreateWindow("Dinosaur!!");
    setup();
    glutDisplayFunc(render);

    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);

    glutMainLoop();
}