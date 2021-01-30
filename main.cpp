#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<cstdio>

# define PI           3.14159265358979323846

GLfloat riverLinePosition = 0.0f;
GLfloat shipPosition = 0.0f;
GLfloat shipPosition2 = 0.0f;
GLfloat boatM = 0.0f;
GLfloat boatM2 = 0.0f;
GLfloat boatM3 = 0.0f;
GLfloat boatM4 = 0.0f;
GLfloat boatM5 = 0.0f;
GLfloat position =0.0f;
GLfloat i=0;
GLfloat trainMovement = 0.0f;
GLfloat trainSpeed = 0.02f;
GLfloat cloudMovement = 0.0f;
GLfloat cloudMovement2 = 0.0f;
GLfloat rainMovementX = 0.0f;
GLfloat rainMovementY = 0.0f;

//
GLfloat car1Position = 0.0f;
GLfloat car1Speed = 0.05f;

GLfloat car2Position = 0.0f;
GLfloat car2Speed = 0.07f;


bool day = true , night = false,isRaining = false;
bool isStopped = false;
bool isSound = false;

//PROTOTYPE
void handleKeypress(unsigned char key, int x, int y);
void handleMouse(int button, int state, int x, int y);
void SpecialInput(int key, int x, int y);
void update(int value);
void Idle();
void display();
void scene();
void river();
void ship();
void ship2();
void boat();
void boat2();
void riverSideRoadGrass();
void train();
void trainTrack();
void rain();
//

void road();
void roadStripe();
void field();
void hill();
void hillLong();
void hut();
void circle();
void roadStripe();
void car1();
void car2();
void Cloud();
void cow();
void scene();
void sky();
void moon();
void school();
void tree();
void soundShip();
void soundNull();
void soundRain();
//PROTOTYPE END

void Idle(){
    glutPostRedisplay();
}

void soundShip()
{

    PlaySound("shipSound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void soundRain()
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void soundNull()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {


    case 'n':
        night = true;
        day = false;
    break;
    case 'd':
        night = false;
        day = true;
    break;

    case 'r':
        if(isRaining)
        {
            if(!isSound)
            {
                soundNull();

            }
            else
            {
                soundShip();
            }
            isRaining = false;
        }
        else
        {
            isRaining = true;
            soundRain();
        }
    break;

    case 'p':
        isSound = true;
        if(!isRaining)
        {
            soundShip();
        }
    break;
    case 's':
            isSound = false;
            soundNull();
    break;

    }

    glutPostRedisplay();

}
void handleMouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON)
        {

            isStopped = false;
        }
        if (button == GLUT_RIGHT_BUTTON)
        {
            isStopped = true;
        }
	glutPostRedisplay();

}
void SpecialInput(int key, int x, int y){
    switch(key)
    {
        case GLUT_KEY_UP:

        if(car1Speed<=2)
        {
            car1Speed += 0.02;

        }

        if(car2Speed<=2)
        {
            car2Speed += 0.02;
        }

        break;
        case GLUT_KEY_DOWN:

         if(car1Speed>=0.02)
        {
            car1Speed -= 0.02;

        }

        if(car2Speed>=0.02)
        {
            car2Speed -= 0.02;
        }


        break;
        case GLUT_KEY_LEFT:
        if(trainSpeed>.02f)
        {
            trainSpeed=trainSpeed-0.02;
        }
            break;

        case GLUT_KEY_RIGHT:
        if(trainSpeed<.08f)
        {
            trainSpeed=trainSpeed+0.02;
        }
        break;
    }
glutPostRedisplay();
}
void update(int value){

    if(!isStopped)
    {
        cloudMovement += 0.002f;
    if(cloudMovement>=1.9)
    {
        cloudMovement = -1.6f;
    }

    cloudMovement2 += 0.002f;
    if(cloudMovement2>=2.9)
    {
        cloudMovement2 = -2.6;
    }

    if(car1Position>=2)
        {car1Position = -1.5;}

    car1Position+=car1Speed;

    if(car2Position<=-2)
        {car2Position = 1.5;}

    car2Position-=car2Speed;

    //
    if(riverLinePosition<=1.0f)
    {
        riverLinePosition += 0.01f;
    }
    else
    {
        riverLinePosition = 0.0f;
    }

    if(shipPosition>-1.8f)
    {
        shipPosition -= 0.01;
    }
    else
    {
        shipPosition = 1.5;
    }

    if(shipPosition2<1.8f)
    {
        shipPosition2 += 0.01;
    }
    else
    {
        shipPosition2 =- 1.0;
    }

    if(boatM <= 1.0)
    {
        boatM+= 0.019;

    }
    else
    {
        boatM = -1.3f;
    }

    if(boatM2 >= -1.8)
    {
        boatM2-= 0.019;

    }
    else
    {
        boatM2 = 1.3f;
    }

    if(boatM3<=1.1f)
    {
        boatM3 += .01f;
    }
    else
    {
        boatM3 = -1.6f;
    }

    boatM4 += .03;
    if(boatM4>=1.9f)
    {
        boatM4 = -1.5f;
    }

    boatM5 -= 0.015;
    if(boatM5<=-1.0)
    {
        boatM5 = +1.9;
    }


    if(trainMovement<=2.0f)
    {
        trainMovement += trainSpeed;
    }
    else
    {
        trainMovement = -1.9f;
    }


    i+=2;


    rainMovementX  -=0.002f;
    rainMovementY -=0.009f;

    if(rainMovementX<1.0f)
    {
        rainMovementX = 0.0f;
    }

    if(rainMovementY<-1.0f)
    {
        rainMovementY = 0.0f;
    }

    }



	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

void riverSideRoadGrass()
{
    glBegin(GL_QUADS); //field

    if(night)
    {
        glColor3f(0.223, 0.584, 0.156);
    }
    else
    {
        glColor3f(0.435, 0.839, 0.360);
    }

    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();
}


void rain()
{

    int i=0,j=0;
    float x,y;
    x=-1.0f;
    y=2.0f;

    while(j<=100)
    {
        x = -1.0f;
        while(i<=100)
        {
            glBegin(GL_LINES);
            glColor3f(0.313, 0.560, 0.713);
            glVertex2f(x,y);
            glVertex2f(x-0.02f,y-0.07f);
            glEnd();

            x=x+0.03f;
            i++;
        }
        y = y-0.05f;
        j++;
        i=0;
    }


}

void circle(float a, float b, float c, float m, float n, float o)
{
    int i;

	GLfloat x=a; GLfloat y=b; GLfloat radius =c;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(m,n,o);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void roadStripe()
{
    //ROAD

    //MAIN ROAD BELOW

    //END OF MAIN ROAD BELOW

    glBegin(GL_QUADS);
    glColor3f(0.270, 0.270, 0.270);
    glVertex2f(-1,.3);
    glVertex2f(-1,.1);
    glVertex2f(1,.1);
    glVertex2f(1,.3);
    glEnd();


    //ROAD LINE
    glBegin(GL_QUADS);
    glColor3f(0.917, 0.749, 0.211);

    glVertex2f(-1,.21);
    glVertex2f(-1,.19);
    glVertex2f(-.75,.19);
    glVertex2f(-.75,.21);

    glVertex2f(-.5,.21);
    glVertex2f(-.5,.19);
    glVertex2f(-.25,.19);
    glVertex2f(-.25,.21);


    glVertex2f(0,.21);
    glVertex2f(.0,.19);
    glVertex2f(.25,.19);
    glVertex2f(.25,.21);

    glVertex2f(.5,.21);
    glVertex2f(.5,.19);
    glVertex2f(.75,.19);
    glVertex2f(.75,.21);

    /*
    glVertex2f(.9,.21);
    glVertex2f(.9,.19);
    glVertex2f(1,.19);
    glVertex2f(1,.21);
    */
    glEnd();
}

void car1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.164, 0.333, 0.666); //body
    glVertex2f(-.04,.2);
    glVertex2f(-.02,0);
    glVertex2f(.7,0);
    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glEnd();

    glBegin(GL_POLYGON); //window body
    glVertex2f(.2,.3);
    glVertex2f(0,.2);
    glVertex2f(.55,.2);
    glVertex2f(.4,.3);
    glEnd();

    glBegin(GL_POLYGON);//window
    glColor3f(0,0,0);
    glVertex2f(.2,.28);
    glVertex2f(0.04,.2);
    glVertex2f(.51,.2);
    glVertex2f(.4,.28);
    glEnd();

    glBegin(GL_TRIANGLES);//lights

    if(night)
    {
        glColor3f(1,1,1);
    }
    if(day)
    {
        glColor3f(0,0,0);
    }
    glVertex2f(.7,.15);
    glVertex2f(.6,.2);
    glVertex2f(.6,.15);
    glEnd();

    //wheels
    circle(.13,0,.1,0, 0, 0);
    circle(.55,0,.1,0, 0, 0);

}

void car2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.725, 0.745, 0.745); //body
    glVertex2f(-.04,.2);
    glVertex2f(-.02,0);
    glVertex2f(.7,0);
    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glEnd();

    glBegin(GL_POLYGON); //window body
    glVertex2f(.2,.3);
    glVertex2f(0,.2);
    glVertex2f(.55,.2);
    glVertex2f(.4,.3);
    glEnd();

    glBegin(GL_POLYGON);//window
    glColor3f(0,0,0);
    glVertex2f(.2,.28);
    glVertex2f(0.04,.2);
    glVertex2f(.51,.2);
    glVertex2f(.4,.28);
    glEnd();

    glBegin(GL_TRIANGLES);//lights

    if(night)
    {
        glColor3f(1,1,1);
    }
    if(day)
    {
        glColor3f(0,0,0);
    }
    glVertex2f(.7,.15);
    glVertex2f(.6,.2);
    glVertex2f(.6,.15);
    glEnd();

    circle(.13,0,.1,0, 0, 0);
    circle(.55,0,.1,0, 0, 0);

}

void road()
{
    roadStripe();
    //ROAD DIVIDER

    glBegin(GL_QUADS);
    glColor3f(0.435, 0.839, 0.360);
    glVertex2f(-1,.1);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,.1);
    glEnd();

    //END OF ROAD DIVIDER
    glTranslatef(0,-.3,0);
    roadStripe();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(car1Position,0,0);
    glTranslatef(-.8,-.05,0);
    glScalef(.4,.3,1);
    car1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car2Position,0,0);
    glTranslatef(.7,.16,0);
    glScalef(-.4,.3,1);
    car2();
    glLoadIdentity();
    glPopMatrix();

    ////////////////////

    //LAMP
 float xLamp= -0.8f; float yLamp = 0.06f;

    for(int i =0;i<=9;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(0.525, 0.372, 0.133);
        glVertex2f(xLamp,yLamp);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp+.01,yLamp+0.1);
        glVertex2f(xLamp+.01,yLamp);


        glColor3f(0,0,0);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp,yLamp+0.09);
        glVertex2f(xLamp+0.03,yLamp+0.09);
        glVertex2f(xLamp+0.03,yLamp+0.1);

        glEnd();

        glBegin(GL_POLYGON);

        if(night)
        {
            glColor3f(1,1,1);
        }
        else
        {
            glColor3f(0.337, 0.345, 0.333);
        }

        glVertex2f(xLamp+0.02,yLamp+.09);
        glVertex2f(xLamp+0.01,yLamp+0.07);
        glVertex2f(xLamp+0.03,yLamp+0.07);
        glVertex2f(xLamp+0.02,yLamp+.09);

        glEnd();

        xLamp = xLamp+.2;

    }


}
void hill()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();

    glScalef(.7,.7,1);
    glTranslatef(.2,0,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();
    glLoadIdentity();
}
void hillLong()
{
    float x=-1.3;
    for(int i=0;i<10;i++)
    {
        glTranslatef(x,.6,0);
        hill();
        glLoadIdentity();
        x+=.25;
    }
}


void hut()
{
    //body();
    glBegin(GL_POLYGON); //front
    glColor3f(0.572, 0.329, 0.207);

    glVertex2f(.45,.4);
    glVertex2f(.0,.0);
    glVertex2f(.0,-.4);
    glVertex2f(.75,-.35);
    glVertex2f(.75,.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.666, 0.380, 0.235);

    glVertex2f(0,0); //side
    glVertex2f(-.65,0);
    glVertex2f(-.65,-.35);
    glVertex2f(0,-.4);
    glEnd();

    glTranslatef(.35,-.38,0);
    glBegin(GL_QUADS);//door
    glColor3f(0.309, 0.176, 0.109);

    glVertex2f(0,0);
    glVertex2f(.18,.01);
    glVertex2f(.18,.39);
    glVertex2f(0,.4);
    glEnd();

    glTranslatef(-.35,.38,0);
    //bar();
    glBegin(GL_QUADS);
    glColor3f(0.309, 0.176, 0.109);

    glVertex2f(0,.1);
    glVertex2f(0,-.4);
    glVertex2f(.02,-.4);
    glVertex2f(.02,.1);
    glEnd();

    //roof();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0,0);
    glVertex2f(.5,.4);
    glVertex2f(-.2,.3);
    glVertex2f(-.7,.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(.5,.4);
    glVertex2f(.45,.4);
    glVertex2f(.75,.0);
    glVertex2f(.8,.0);
    glEnd();
    glLoadIdentity();
}

void cow()
{
    glBegin(GL_QUADS); //body
    glColor3f(0.756, 0.549, 0.062);
    glVertex2f(0.1,.2);
    glVertex2f(0.1,0.05);
    glVertex2f(.4,0.05);
    glVertex2f(.4,.2);
    glEnd();

    glBegin(GL_QUADS); // leg behind
    glColor3f(0.756, 0.549, 0.062);
    glVertex2f(0.1,.1);
    glVertex2f(0.1,-.05);
    glVertex2f(.12,-.05);
    glVertex2f(.15,.1);
    glEnd();

    glBegin(GL_QUADS); //leg front
    glColor3f(0.756, 0.549, 0.062);
    glVertex2f(0.35,.1);
    glVertex2f(0.38,-.05);
    glVertex2f(.4,-.05);
    glVertex2f(.4,.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(.35,.2);
    glVertex2f(.5,.15);
    glVertex2f(.55,.2);
    glVertex2f(.45,.25);
    glEnd();

    glBegin(GL_TRIANGLES); // horns
    glVertex2f(.43,.23);
    glVertex2f(.45,.25);
    glVertex2f(.3,.3);
    glEnd();
}

void Cloud()
{

    GLfloat x=.0f; GLfloat y=.8f; GLfloat radius =.1f;
	int i;
	int triangleAmount  = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.686, 0.866, 0.933);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x = -0.1;
	y = .82;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x = 0.0;
	y = .85;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	x = 0.1;
	y = .82;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



	x = 0.0;
	y = .75;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.921, 0.980, 0.996);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void tree()
{
    float vTree = -0.95f;
    float zTree = 0.55f;

    float vTree2 = vTree+.05f;
    float zTree2 = zTree -.05f;

        glBegin(GL_QUADS);
        glColor3f(0.482, 0.215, 0.078);
        glVertex2f(vTree,zTree+.15);
        glVertex2f(vTree,zTree);
        glVertex2f(vTree+.005,zTree);
        glVertex2f(vTree+.005,zTree+.15);

        glVertex2f(vTree2,zTree2+.15);
        glVertex2f(vTree2,zTree2);
        glVertex2f(vTree2+.005,zTree2);
        glVertex2f(vTree2+.005,zTree2+.15);


        glEnd();
        vTree = vTree + .0025;
        vTree2 = vTree2 + .0025;
        glBegin(GL_TRIANGLES);
        glColor3f(0.250, 0.529, 0.070);

        glVertex2f(vTree,zTree+.18);
        glVertex2f(vTree-.03,zTree+.12);
        glVertex2f(vTree+.03,zTree+.12);

        glVertex2f(vTree,zTree+.14);
        glVertex2f(vTree-.03,zTree+.08);
        glVertex2f(vTree+.03,zTree+.08);


        glVertex2f(vTree2,zTree2+.18);
        glVertex2f(vTree2-.03,zTree2+.12);
        glVertex2f(vTree2+.03,zTree2+.12);

        glVertex2f(vTree2,zTree2+.14);
        glVertex2f(vTree2-.03,zTree2+.08);
        glVertex2f(vTree2+.03,zTree2+.08);

        glEnd();

        vTree = vTree+0.3;
        vTree2 = vTree2 + 0.3;

}


// FUNCTION

void school()
{
    glBegin(GL_QUADS); //body
    glColor3f(0.788, 0.788, 0.788);
    glVertex2f(0,0);
    glVertex2f(0,-.2);
    glVertex2f(.5,-.2);
    glVertex2f(.5,0);
    glEnd();

    glColor3f(0.0,0.0,0.0);

    char c[]= "VILLAGE DIARY FARM";

    glRasterPos2f(0.15,-.08);

    for(int j=0;c[j]!='\0';j++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,c[j]);
    }



    glBegin(GL_QUADS); //top bar
    glColor3f(0,0,0);
    glVertex2f(-.01,0);
    glVertex2f(-.01,-.01);
    glVertex2f(.51,-.01);
    glVertex2f(.51,0);
    glEnd();

    glBegin(GL_QUADS); //door
    glColor3f(0,0,0);
    glVertex2f(0.2,-.1);
    glVertex2f(0.2,-.2);
    glVertex2f(.3,-.2);
    glVertex2f(.3,-.1);
    glEnd();



}

void field()
{
    glBegin(GL_QUADS); //field

    if(night)
    {
        glColor3f(0.223, 0.584, 0.156);
    }
    else
    {
        glColor3f(0.435, 0.839, 0.360);
    }


    glVertex2f(-1,.6);
    glVertex2f(-1,.24);
    glVertex2f(1,.24);
    glVertex2f(1,.6);
    glEnd(); //field Ends

    //////////////////////
    //elements
    glTranslatef(-.5,.5,0);
    glScalef(.2,.2,1);
    hut();
    glLoadIdentity();

    glTranslatef(-.8,.4,0);
    glScalef(.2,.2,1);
    hut();
    glLoadIdentity();

    glTranslatef(.8,.45,0);
    glScalef(-.2,.2,1);
    hut();
    glLoadIdentity();

    glTranslatef(-.05,.65,0);
    glScalef(1,1,1);
    school();
    glLoadIdentity();

    /////////////////////////////////////cow
    if(night)
    {
        glTranslatef(-.7,.3,0);
    }
    else
    {
        glTranslatef(-.3,.3,0);
    }
    glScalef(.35,.35,1);
    cow();
    glLoadIdentity();


    if(night)
    {
        glTranslatef(.9,.35,0);
    }
    else
    {
        glTranslatef(.55,.35,0);
    }
    glScalef(-.35,.35,1);
    cow();
    glLoadIdentity();

    /////////////////////////trees
    glTranslatef(0,-.05,0);
    tree();
    glLoadIdentity();

    glTranslatef(.7,-.08,0);
    tree();
    glLoadIdentity();

    glTranslatef(1.5,-.2,0);
    tree();
    glLoadIdentity();

    glTranslatef(1.85,-.02,0);
    tree();
    glLoadIdentity();
}

void moon()
{
    circle(0.6,0.7,0.15, 1,1,1);//moon
    circle(0.65,0.75,0.15, 0.164, 0.180, 0.239);//moon
}

void sky()
{

    if(day)
    {
        circle(0.25,0.84,0.1, 1, 0.733, 0.2);//sun
    }
    if(night)
    {
        glTranslatef(-.2,.35,0);
        glScalef(.7,.7,1);
        moon();
        glLoadIdentity();
    }

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.3,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(.7,.4,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();


    //
    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.3,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(.7,.4,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();


}





///////



void river()
{
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.886, 0.968); //Water color
    if(night)
    {
        glColor3f(0.133, 0.207, 0.211);
    }

    glVertex2f(-1,-.3);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.3);
    glEnd();

}

void riverLine()
{

    glBegin(GL_LINES);
    GLfloat x=-1.8;
    glColor3f(0.615, 0.941, 0.945);//River Line Color
    if(night)
    {
       glColor3f(0.133, 0.207, 0.211);
    }
    for(int i=0;i<=20;i++)
    {
        glVertex2f(x,-.3);
        glVertex2f(x,-1);
        x= x+.4;
    }
    glEnd();
}

void ship()
{

    //MAIN DECK
    glBegin(GL_POLYGON);
    glColor3f(0, 0.172, 0.345);
    glVertex2f(-.15,-.7);
    glVertex2f(-.05,-.85);
    glVertex2f(.55,-.85);
    glVertex2f(.65,-.7);
    glEnd();

    //MAIN DECK

    //MAIN DECK ROUND WINDOW
    GLfloat xCircle=0.01f; GLfloat yCircle=-.78f; GLfloat radius =.03f;

    int triangleAmount = 20;

    GLfloat twicePi = 2.0f * PI;
    for(int i=0;i<5;i++)
    {

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
            glVertex2f(xCircle, yCircle);
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + ((radius-.003) * cos(i *  twicePi / triangleAmount)),
                    yCircle + ((radius-.003) * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        xCircle = xCircle + .12;

    }
    //MAIN DECK ROUND WINDOW END

    glBegin(GL_QUADS);
    glColor3f(0.066, 0.349, 0.635); //MAin deck roof
    glVertex2f(-0.15,-.7);
    glVertex2f(-0.15,-.68);
    glVertex2f(.65,-.68);
    glVertex2f(.65,-.7);

    glEnd();

    //MAIN DECK END

    //BTM UPPER DECK

    glBegin(GL_QUADS);
    glColor3f(0.494, 0.494, 0.494);
    glVertex2f(-0.05,-.68);
    glVertex2f(-0.05,-.6);
    glVertex2f(.55,-.6);
    glVertex2f(.55,-.68);
    glEnd();


    //Inner window
    xCircle=0.05f; yCircle=-.645f; radius =.025f;
    for(int i=0;i<5;i++)
    {

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
            glVertex2f(xCircle, yCircle);
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + ((radius-.003) * cos(i *  twicePi / triangleAmount)),
                    yCircle + ((radius-.003) * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        xCircle = xCircle + .1;

    }
    //END OF INNER WINDOW
    //BTM UPPER DECK END

    //TOP UPPER DECK
    glBegin(GL_POLYGON);

    glVertex2f(-0.03,-.55);
    glVertex2f(-0.03,-.6);
    glVertex2f(.53,-.6);
    glVertex2f(.5,-.55);



    glEnd();


    //TOP UPPER DECK END

    //Smoke

    //SmOKE 1
    glBegin(GL_QUADS);

    glColor3f(0.572, 0.149, 0.184); //Body COlor
    glVertex2f(.1,-.45);
    glVertex2f(.1,-.55);
    glVertex2f(.15,-.55);
    glVertex2f(.15,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.1,-.43);
    glVertex2f(.1,-.45);
    glVertex2f(.15,-.45);
    glVertex2f(.15,-.43);
    glEnd();

    //SMOKE 2
    glBegin(GL_QUADS);

    glColor3f(0.572, 0.149, 0.184); //Body COlor
    glVertex2f(.2,-.45);
    glVertex2f(.2,-.55);
    glVertex2f(.25,-.55);
    glVertex2f(.25,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.2,-.43);
    glVertex2f(.2,-.45);
    glVertex2f(.25,-.45);
    glVertex2f(.25,-.43);
    glEnd();


    //SMOKE 3
    glBegin(GL_QUADS);

    glColor3f(0.572, 0.149, 0.184); //Body COlor
    glVertex2f(.3,-.45);
    glVertex2f(.3,-.55);
    glVertex2f(.35,-.55);
    glVertex2f(.35,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.3,-.43);
    glVertex2f(.3,-.45);
    glVertex2f(.35,-.45);
    glVertex2f(.35,-.43);
    glEnd();
    //SMOKE END

    if(night)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(-0.05,-.68);
        glVertex2f(-0.65,-.72);
        glVertex2f(-0.65,-.86);


        glEnd();
    }



}

void ship2()
{

    //MAIN DECK
    glBegin(GL_POLYGON);
    glColor3f(0.023, 0.007, 0.003);
    glVertex2f(-.15,-.7);
    glVertex2f(-.05,-.85);
    glVertex2f(.55,-.85);
    glVertex2f(.65,-.7);
    glEnd();

    //MAIN DECK

    //MAIN DECK ROUND WINDOW
    GLfloat xCircle=0.01f; GLfloat yCircle=-.78f; GLfloat radius =.03f;

    int triangleAmount = 20;

    GLfloat twicePi = 2.0f * PI;
    for(int i=0;i<5;i++)
    {

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
            glVertex2f(xCircle, yCircle);
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + ((radius-.003) * cos(i *  twicePi / triangleAmount)),
                    yCircle + ((radius-.003) * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        xCircle = xCircle + .12;

    }
    //MAIN DECK ROUND WINDOW END

    glBegin(GL_QUADS);
    glColor3f(0.219, 0.219, 0.219); //MAin deck roof
    glVertex2f(-0.15,-.7);
    glVertex2f(-0.15,-.68);
    glVertex2f(.65,-.68);
    glVertex2f(.65,-.7);

    glEnd();

    //MAIN DECK END

    //BTM UPPER DECK

    glBegin(GL_QUADS);
    glColor3f(0.945, 0.537, 0.007);
    glVertex2f(-0.05,-.68);
    glVertex2f(-0.05,-.6);
    glVertex2f(.55,-.6);
    glVertex2f(.55,-.68);
    glEnd();


    //Inner window
    xCircle=0.05f; yCircle=-.645f; radius =.025f;
    for(int i=0;i<5;i++)
    {

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
            glVertex2f(xCircle, yCircle);
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + ((radius-.003) * cos(i *  twicePi / triangleAmount)),
                    yCircle + ((radius-.003) * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        xCircle = xCircle + .1;

    }
    //END OF INNER WINDOW
    //BTM UPPER DECK END

    //TOP UPPER DECK
    glBegin(GL_POLYGON);

    glVertex2f(-0.03,-.55);
    glVertex2f(-0.03,-.6);
    glVertex2f(.53,-.6);
    glVertex2f(.5,-.55);



    glEnd();


    //TOP UPPER DECK END

    //Smoke

    //SmOKE 1
    glBegin(GL_QUADS);

    glColor3f(0.807, 0.776, 0.756); //Body COlor
    glVertex2f(.1,-.45);
    glVertex2f(.1,-.55);
    glVertex2f(.15,-.55);
    glVertex2f(.15,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.1,-.43);
    glVertex2f(.1,-.45);
    glVertex2f(.15,-.45);
    glVertex2f(.15,-.43);
    glEnd();

    //SMOKE 2
    glBegin(GL_QUADS);

    glColor3f(0.807, 0.776, 0.756); //Body COlor
    glVertex2f(.2,-.45);
    glVertex2f(.2,-.55);
    glVertex2f(.25,-.55);
    glVertex2f(.25,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.2,-.43);
    glVertex2f(.2,-.45);
    glVertex2f(.25,-.45);
    glVertex2f(.25,-.43);
    glEnd();


    //SMOKE 3
    glBegin(GL_QUADS);

    glColor3f(0.807, 0.776, 0.756); //Body COlor
    glVertex2f(.3,-.45);
    glVertex2f(.3,-.55);
    glVertex2f(.35,-.55);
    glVertex2f(.35,-.45);


    glColor3f(1, 1, 1); //Head Color
    glVertex2f(.3,-.43);
    glVertex2f(.3,-.45);
    glVertex2f(.35,-.45);
    glVertex2f(.35,-.43);
    glEnd();
    //SMOKE END


    //LIGHT
    if(night)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.968, 0.968, 0.788);

        glVertex2f(0.65,-0.7);
        glVertex2f(0.95,-0.75);
        glVertex2f(0.95,-0.88);

        glEnd();
    }


    //END OF LIGHT

}


void boat()
{
    glBegin(GL_POLYGON);
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.06,0);
    glVertex2f(0.075,0);
    glVertex2f(0.075,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.08,0);
    glVertex2f(0.125,0);
    glVertex2f(.08,0.1);

    glEnd();

    if(night)
    {
        //LIGHT

        glBegin(GL_TRIANGLES);
        glColor3f(0.968, 0.968, 0.788);

        glVertex2f(0.19,-0.01);
        glVertex2f(0.28,-0.02);
        glVertex2f(0.27,-0.05);

        glEnd();

        //END OF LIGHT

    }



}

void boat2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.11,0);
    glVertex2f(0.095,0);
    glVertex2f(0.095,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.09,0);
    glVertex2f(0.045,0);
    glVertex2f(.09,0.1);

    glEnd();
    if(night)
    {
    //LIGHT

    glBegin(GL_TRIANGLES);
    glColor3f(0.968, 0.968, 0.788);

    glVertex2f(0.01,-0.01);
    glVertex2f(-0.1,-0.02);
    glVertex2f(-0.08,-0.05);

    glEnd();

    //END OF LIGHT
    }
}

void trainTrack()
{
    glBegin(GL_LINES);
    glColor3f(0.392, 0.113, 0.047);
    glVertex2f(-1,-.205);
    glVertex2f(1,-.205);

    glVertex2f(-1,-.12);
    glVertex2f(1,-.12);

    GLfloat x=-1.5,y=-.12;

    while(x<1.5)
    {
        glVertex2f(x,y);
        glVertex2f(x,y-.085);
        x = x+0.02;
    }

    glEnd();
}


void train()
{


    //Wheel

    GLfloat xCircle=-.65f; GLfloat yCircle=-0.18f; GLfloat radius =.02f;

     GLfloat triangleAmount = 20;

     GLfloat twicePi = 2.0f * PI;
    while(xCircle<=.42)
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0, 0, 0);
            glVertex2f(xCircle, yCircle); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + (radius * cos(i *  twicePi / triangleAmount)),
                    yCircle + (radius * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.521, 0.517, 0.509);
            glVertex2f(xCircle, yCircle); // center of circle
            for(int i = 0; i <= triangleAmount;i++) {
                glVertex2f(
                        xCircle + ((radius-.003) * cos(i *  twicePi / triangleAmount)),
                    yCircle + ((radius-.003) * sin(i * twicePi / triangleAmount))
                );
            }
        glEnd();

        xCircle = xCircle + .05;

    }






    //END OF WHEEL

    glBegin(GL_QUADS);
    glColor3f(0.109, 0.282, 0.505); //Color of Whole Train
    glVertex2f(-.7,-.05);
    glVertex2f(-.7,-.18);
    glVertex2f(.45,-.18);
    glVertex2f(.45,-.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);

    glVertex2f(.4,-.02);
    glVertex2f(.4,-.03);
    glVertex2f(.41,-.05);
    glVertex2f(.43,-.05);
    glVertex2f(.44,-.03);
    glVertex2f(.44,-.02);



    glEnd();




    glBegin(GL_QUADS);





    //TRAIN BODY LINE
    glColor3f(0.713, 0.6, 0.439);
    glVertex2f(-.7,-.171);
    glVertex2f(-.7,-.178);
    glVertex2f(.45,-.178);
    glVertex2f(.45,-.171);

    glVertex2f(-.7,-.06);
    glVertex2f(-.7,-.07);
    glVertex2f(.45,-.07);
    glVertex2f(.45,-.06);

    //WINDOW
    glVertex2f(-.7,-.09);
    glVertex2f(-.7,-.15);
    glVertex2f(.25,-.15);
    glVertex2f(.25,-.09);


    //WINDOW and DOOR
     GLfloat x1 = -0.69; GLfloat y1 = -0.09;
     GLfloat y2 = -.13;
    while (x1<=.1)
    {

        glColor3f(0, 0, 0);
        glVertex2f(x1,y1);
        glVertex2f(x1,y2);
        glVertex2f(x1+.03,y2);
        glVertex2f(x1+.03,y1);

        glVertex2f(x1+0.04,y1);
        glVertex2f(x1+0.04,y2);
        glVertex2f(x1+.07,y2);
        glVertex2f(x1+.07,y1);

        glVertex2f(x1+0.08,y1);
        glVertex2f(x1+0.08,y2);
        glVertex2f(x1+0.11,y2);
        glVertex2f(x1+0.11,y1);

        glVertex2f(x1+0.12,y1);
        glVertex2f(x1+0.12,y2);
        glVertex2f(x1+0.15,y2);
        glVertex2f(x1+0.15,y1);

        glVertex2f(x1+0.17,y1+.04);
        glVertex2f(x1+0.17,y2-.04);
        glVertex2f(x1+0.195,y2-.04);
        glVertex2f(x1+0.195,y1+.04);



        x1 = x1+.25;
    }


    //End of Boggy
    //Engine Room

    glVertex2f(.27,-.6);
    glVertex2f(.27,-.78);
    glVertex2f(0.275,-.78);
    glVertex2f(0.275,-.6);

    glVertex2f(.295,y1+.04);
    glVertex2f(.295,y2-.04);
    glVertex2f(0.34,y2-.04);
    glVertex2f(0.34,y1+.04);

    glVertex2f(.35,y1+.02);
    glVertex2f(.35,y2+.02);
    glVertex2f(.365,y2+.02);
    glVertex2f(.365,y1+.02);

    glVertex2f(.375,y1+.02);
    glVertex2f(.375,y2+.02);
    glVertex2f(.39,y2+.02);
    glVertex2f(.39,y1+.02);



    glEnd();

    if(night)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(0.45,-0.11);
        glVertex2f(0.45,-0.17);
        glVertex2f(0.7,-0.17);
        glEnd();

    }


}


void windmill()
{
     //VILLAGE MILL

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(.1,.47);
    glVertex2f(.1,.32);
    glVertex2f(.11,.32);
    glVertex2f(.11,.47);


    glEnd();

    //ANIMATION

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack,
    glTranslatef(0.105,.47,0.0);
    glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
    glBegin(GL_TRIANGLES);
    glColor3f(0.188, 0.188, 0.188);

    glVertex2f(.0,.0);
    glVertex2f(.02,.11);
    glVertex2f(.04,.12);

    glVertex2f(.0,.0);
    glVertex2f(-.02,-.11);
    glVertex2f(-.04,-.12);

    glVertex2f(.0,.0);
    glVertex2f(-.11,.02);
    glVertex2f(-.12,.04);


    glVertex2f(.0,.0);
    glVertex2f(.11,-.02);
    glVertex2f(.12,-.04);









    glEnd();
    glPopMatrix();//glPopMatrix pops the top matrix off the stack
    //i=i+.1=.2


    //ANIMATION END

    //CIRCLE OF FAN
    GLfloat xMoon=0.105f; GLfloat  yMoon=.47f; GLfloat moonRadius =.02f;
    GLfloat moonTwicePi = 2.0f * PI;
    int moonTriangleAmount = 20;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.188, 0.188, 0.188);
            glVertex2f(xMoon, yMoon); // center of circle
            for(int i = 0; i <= moonTriangleAmount;i++) {
                glVertex2f(
                        xMoon + (moonRadius * cos(i *  moonTwicePi /moonTriangleAmount )),
                    yMoon + (moonRadius * sin(i * moonTwicePi / moonTriangleAmount))
                );
            }
        glEnd();

    //CIRCLE OF FAN

}

void scene(){


    sky();

    hillLong();
    field();

    glScalef(1,.7,1);
    glTranslatef(0,.05,0);
    road();
    glLoadIdentity();

    /////////////////////////////////////////////////

    //WIND MILLS
    riverSideRoadGrass();
    glTranslatef(0,-.02,0);
    glScalef(1.0,0.8,0.0);
    trainTrack();
    glLoadIdentity();

    glScalef(1.0,0.8,0.0);
    glTranslatef(trainMovement,0.0,0.0);
    glTranslatef(0,-.02,0);
    train();
    glLoadIdentity();

    glTranslatef(-.9,-.6,0);
    windmill();
    glLoadIdentity();

    glTranslatef(-.6,-.6,0);
    windmill();
    glLoadIdentity();


    glTranslatef(-.3,-.6,0);
    windmill();
    glLoadIdentity();


    glTranslatef(-.0,-.6,0);
    windmill();
    glLoadIdentity();

    glTranslatef(.3,-.6,0);
    windmill();
    glLoadIdentity();

    glTranslatef(.6,-.6,0);
    windmill();
    glLoadIdentity();

    //WIND MILLS


    river();
    glPushMatrix();
    glTranslatef(riverLinePosition,0.0,0.0);
    riverLine();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shipPosition2,0,0);
    glTranslatef(-.4,.02,0);
    glScalef(.5,.5,0.0);
    ship2();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM,0.0,0);
    glTranslatef(0.0,-.4,0);
    boat();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM2,0.0,0);
    glTranslatef(0.6,-.5,0);
    glScalef(1.1,1.1,0);
    boat2();
    glLoadIdentity();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(boatM4,0.0,0.0);
    glTranslatef(-0.6,-.5,0);
    glScalef(1.4,1.4,0);
    boat();
    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(boatM3,0.0,0.0);
    glTranslatef(0.2,-.6,0);
    glScalef(1.5,1.5,0);
    boat();
    glLoadIdentity();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(shipPosition,0,0);
    ship();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM5,0.0,0.0);
    glTranslatef(-0.6,-.8,0);
    glScalef(1.7,1.7,0);
    boat2();
    glLoadIdentity();
    glPopMatrix();


    if(isRaining)
    {
        glTranslatef(rainMovementX,rainMovementY,0);
        rain();
        glLoadIdentity();
    }




}
void display(){

    if(night)
    {
        glClearColor(0.164f, 0.180f, 0.239f, 1.0f);
    }
    else
    {
        glClearColor(0.552f, 0.733f, 0.839f, 1.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    scene();



    glFlush();

}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Computer Graphics Project");
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}






