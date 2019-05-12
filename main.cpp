#include <stdio.h>
#include <GL/glut.h>
#include<math.h>

int scene = 0,x=0,y=-195,opt=0 ;

int wx1[] ={-670,-150,418};
int wy1=-232;
float cx[]={-540,-150,520,-30};
float cy[]={210,130,250,250};

void options(int id){
    if(id == 1 && scene == 4)  opt = 1;
    else if(id == 2)  exit(0);
}
typedef struct stColor {
    double red, green, blue;
    double alpha;
} RgbColor;

RgbColor createColor(int red, int green, int blue, double alpha) {
    RgbColor color;
    color.red = (double) red / 256;
    color.green = (double) green / 256;
    color.blue = (double) blue / 256;
    color.alpha = (double) alpha;
    return color;
}


RgbColor color;


void DrawCircle(float cx, float cy, float cz, float r, int num_segments)
{

	int ii;
	float theta, x, y, i;
	glBegin(GL_POLYGON);
	for(ii = 0; ii < num_segments/2; ii++)
	{

		i = (float)ii/(float)num_segments;
		theta = 2.0f*3.1415926f*i;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex3f(x + cx, y + cy, cz);

	}
	glEnd();
}

void drawText(char text[], int x, int y, int z)
{

  // The color, red for me
  glColor3f(1, 1, 1);
  // Position of the text to be printer
  glRasterPos3f(x, y, z);
  for(int i = 0; text[i] != '\0'; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void printLines(char **s, int offsetY, int n, int x, int y) {
    int i = 0;
    for (; i < n; i++) {
        drawText(s[i],x, y + offsetY,0 );
        offsetY -= 35;
    }
}


void drawMainScene()
{
    glBegin(GL_QUADS);
    color = createColor(166, 73, 154, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0,350.0);
    glVertex2f(670.0,350.0);
    color = createColor(19, 13, 86, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0,-350.0);
    glVertex2f(-670.0,-350.0);
    glEnd();
  glClearColor(1.0,1.0, 1.0, 1.0);
  char h1[] = "Computer Graphics Project";
  char h2[] = "PULWAMA ATTACK";
  char h3[] = "by";
  char name1[] = "KAUSHIK K";
  char usn1[] = "4SF16CS067";
  char name2[] = "DUSHYANTH PRABHU B";
  char usn2[] = "4SF16CS047";
  char message[] = "Press 1 to start";

  drawText(h1, -110, 200, 0);
  drawText(h2, -90, 170, 0);
  drawText(h3, -5, 150, 0);
  drawText(name1, -230, 90, 0);
  drawText(usn1, -237, 70, 0);
  drawText(name2, 100, 90, 0);
  drawText(usn2, 150, 70, 0);
  drawText(message, -70, -200, 0);
}

void draw_clouds(int r){

    int i = 0;
    for(;i<4;i++){

      color = createColor(255, 255, 255, 0);
      glColor3f(color.red, color.green, color.blue);
      DrawCircle(cx[i],cy[i],0,r,200);
      DrawCircle(cx[i]+40,cy[i]+20,0,r,200);
      DrawCircle(cx[i]+70,cy[i],0,r,200);
      DrawCircle(cx[i]+100,cy[i],0,r,200);
      glBegin(GL_POLYGON);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(cx[i]-5,cy[i]);
        glVertex2f(cx[i]+40,cy[i]+45);
        glVertex2f(cx[i]+70,cy[i]);
        glVertex2f(cx[i]+100,cy[i]);
      glEnd();

    if(scene == 1){
    if(cx[i]+300>-670) cx[i]=cx[i]-0.03;
    else cx[i]=670;}
    if(scene == 2 ){
    if(cx[i]<670) cx[i]=cx[i]+0.06;
    else cx[i]=-970;}

    }
}

void drawWS(){

   int i = 0;
   for(;i<3;i++){

    color = createColor(250, 250, 255, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(wx1[i], wy1, 0);
    glVertex3f(wx1[i]+252, wy1, 0);
    glVertex3f(wx1[i]+240, wy1-10, 0);
    glVertex3f(wx1[i]-12, wy1-10, 0);
    glEnd();

    if(scene == 1){
    if(wx1[i]+252>-670) wx1[i]=wx1[i]-4;
    else wx1[i]=670;}

    if(scene == 2){
    if(wx1[i]<670) wx1[i]=wx1[i]+8;
    else wx1[i]=-992;}
    }

}

void drawStreetLight(){


    color = createColor(201, 200, 197, 0); //00,-195
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x,y, -2);
    color = createColor(0,0,0,0);;
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-8, y, -2);
    color = createColor(0,0,0, 0);

    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-8, y+255, -2);
    color = createColor(201, 200, 197, 0);

    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x, y+255, -2);
    glEnd();

    color = createColor(201, 200, 197, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x,y+257, -2);
    color = createColor(0,0,0,0);

    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-8, y+255, -2);
    color = createColor(0,0,0, 0);

    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-70, y+275, -2);
    color = createColor(201, 200, 197, 0);

    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-62, y+277, -2);
    glEnd();


    color = createColor(254, 242, 178, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-70,y+275, 0);
    glVertex3f(x-20,y+260, 0);

    color = createColor(255, 255, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(x-40,y+245, 0);
    glVertex3f(x-60,y+255, 0);
    glEnd();

    if(scene == 1){
    if(x>-670) x=x-4;
    else x=670;}

    if(scene == 2){
    if(x<670) x=x+8;
    else x=-670;}



}
void drawCandles(){

    glBegin(GL_QUADS); //candle1
    color = createColor(227, 242, 249, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(400.0,-100.0);
    glVertex2f(450.0,-100.0);
    glVertex2f(450.0,-350.0);
    glVertex2f(400.0,-350.0);
    glEnd();

    glBegin(GL_QUADS); //candle1 shadow
    color = createColor(173, 232, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(405.0,-102.0);
    glVertex2f(415.0,-102.0);
    glVertex2f(415.0,-350.0);
    glVertex2f(405.0,-350.0);
    glEnd();

    glBegin(GL_QUADS);//candle2
    color = createColor(227, 242, 249, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(460.0,-130.0);
    glVertex2f(510.0,-130.0);
    glVertex2f(510.0,-350.0);
    glVertex2f(460.0,-350.0);
    glEnd();

    glBegin(GL_QUADS);//candle2 shadow
    color = createColor(173, 232, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(465.0,-132.0);
    glVertex2f(475.0,-132.0);
    glVertex2f(475.0,-350.0);
    glVertex2f(465.0,-350.0);
    glEnd();

    glBegin(GL_QUADS);//candle3
    color = createColor(227, 242, 249, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(340.0,-150.0);
    glVertex2f(390.0,-150.0);
    glVertex2f(390.0,-350.0);
    glVertex2f(340.0,-350.0);
    glEnd();

    glBegin(GL_QUADS);//candle3 shadow
    color = createColor(173, 232, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(345.0,-152.0);
    glVertex2f(355.0,-152.0);
    glVertex2f(355.0,-350.0);
    glVertex2f(345.0,-350.0);
    glEnd();

    //drawWick
    glLineWidth(3.0);

    glColor3f(0.0,0.0,0.0); //wick1
    glBegin(GL_LINES);
    glVertex2f(425.0,-85.0);
    glVertex2f(425.0,-100.0);
    glEnd();

    glColor3f(0.0,0.0,0.0); //wick2
    glBegin(GL_LINES);
    glVertex2f(485.0,-115.0);
    glVertex2f(485.0,-130.0);
    glEnd();

    glColor3f(0.0,0.0,0.0); //wick3
    glBegin(GL_LINES);
    glVertex2f(365.0,-135.0);
    glVertex2f(365.0,-150.0);
    glEnd();
}
void drawFire(int xfire, int yfire){



    glBegin(GL_POLYGON);

    color = createColor(230, 78, 58, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(xfire,yfire+20);

    color = createColor(241, 119, 57, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire+15.0),(yfire-12.0));

    color = createColor(246, 166, 63, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire+18.5),(yfire-26.0));

    color = createColor(241, 196, 101, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire+18.0),(yfire-45.0));


    color = createColor(6, 206, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire),(yfire-77));


    color = createColor(241, 196, 101, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire-18.0),(yfire-45.0));

    color = createColor(246, 166, 63, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire-18.5),(yfire-26.0));

    color = createColor(241, 119, 57, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f((xfire-15.0),(yfire-12.0));

    glEnd();

}
void drawBG(){
    glPushMatrix();

    //road
    color = createColor(81, 81, 81, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(-670,-210, -2);
    glVertex3f(670, -210, -2);
    glVertex3f(670, -300, -2);
    glVertex3f(-670, -300, -2);
    glEnd();

    //grass
    color = createColor(86, 121, 70, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(-670,-300, -2);
    glVertex3f(670, -300, -2);
    glVertex3f(670, -350, -2);
    glVertex3f(-670, -350, -2);
    glEnd();



  //gradient BG
    glBegin(GL_POLYGON);
    color = createColor(255, 255, 255, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(-670,-210, -2);
    glVertex3f(670, -210, -2);
    color = createColor(109, 209, 241, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(670, 350, -2);
    glVertex3f(-670, 350, -2);
    glEnd();

      //drawing clouds
      draw_clouds(25);
      draw_clouds(25);
      draw_clouds(25);
      draw_clouds(25);

      //drawing white strips
      drawWS();


    //divider
    color = createColor(152, 151, 147, 0);
    glBegin(GL_POLYGON);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(-670,-195, -2);
    glVertex3f(670, -195, -2);
    glVertex3f(670, -210, -2);
    glVertex3f(-670, -210, -2);
    glEnd();

    //streetLight
    drawStreetLight();

    glPopMatrix();

}
void StoryScene(){

    glPushMatrix();
    glBegin(GL_QUADS);
    color = createColor(166, 73, 154, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0,350.0);
    glVertex2f(670.0,350.0);
    color = createColor(19, 13, 86, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0,-350.0);
    glVertex2f(-670.0,-350.0);
    glEnd();
    char *story[] = {"On 14 February 2019, a convoy of vehicles carrying security personnel on the Jammu Srinagar National Highway was attacked",
                    "by a vehicle-borne suicide bomber at Lethpora (near Awantipora) in the Pulwama district, Jammu and Kashmir, India.",
                    "The attack resulted in the deaths of 40 Central Reserve Police Force (CRPF) personnel and the attacker.",
                    "The responsibility for the attack was claimed by the Pakistan-based Islamist militant group Jaish-e-Mohammed.",
                    "The attacker was Adil Ahmad Dar, a local from Pulwama district, and a member of Jaish-e-Mohammed.",
                    "India has blamed Pakistan for the attack.  Pakistan condemned the attack and denied any connection to it."
                    };

     printLines(story, 0, 6,-600, 200);
     drawCandles();
     if(opt == 1) {drawFire(425.0,-23); drawFire(485.0,-53); drawFire(365.0,-73); }//89
     glPopMatrix();

}

void keyboardDown(unsigned char key, int x, int y) {

  switch(key) {
  case 49: //enter 1
    scene = 1;
    printf("f");
    break;
  case 50: //enter 2
    scene = 2;
    break;
  case 51: //enter 3
    scene = 3;
    break;
  case 52: //enter 4
    scene = 4;
    break;
  case 'Q':
  case 'q':
  case  27:   // ESC
    exit(0);
  }

}
void keyboardUp(unsigned char key, int x, int y) {

}

/* executed when a special key is pressed */
void keyboardSpecialDown(int k, int x, int y) {

}

/* executed when a special key is released */
void keyboardSpecialUp(int k, int x, int y) {

}

void reshape(int width, int height) {

  GLfloat fieldOfView = 90.0f;
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-662, 662, -350, 350, -450, 450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void mouseClick(int button, int state, int x, int y) {

}

/* executed when the mouse moves to position ('x', 'y') */
void mouseMotion(int x, int y) {

}


void scene1(){
    //color = createColor(109, 209, 241, 0);
    //glClearColor(color.red, color.green, color.blue, 1 );
    glPushMatrix();
    drawBG();
    glPopMatrix();
}
void scene2(){
    glPushMatrix();
    drawBG();
    glPopMatrix();

}
void scene3(){
    glPushMatrix();
    drawFire(0.0,0.0);
    glPopMatrix();
}
void scene4(){


    glPushMatrix();
    StoryScene();
    glPopMatrix();

}
void draw() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  /* render the scene here */
  switch(scene)
  {
    case 0:
      drawMainScene();
      break;
    case 1:
      scene1();
      break;
    case 2:
      scene2();
      break;
    case 3:
      scene3();
      break;
    case 4:
      scene4();
      break;

  }
  glFlush();
  glutSwapBuffers();
}

void idle() {

  glutPostRedisplay();
}


void initGL(int width, int height) {

  reshape(width, height);
  glClearColor(0.2f, 0.8f, 1.0f, 1.0f );
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);


}

int main(int argc, char** argv) {

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1244, 700);
  glutInitWindowPosition(100, 0);
  glutCreateWindow("PULWAMA ATTACK");

  // register glut call backs
  glutKeyboardFunc(keyboardDown);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(keyboardSpecialDown);
  glutSpecialUpFunc(keyboardSpecialUp);
  glutMouseFunc(mouseClick);
  glutMotionFunc(mouseMotion);
  glutReshapeFunc(reshape);
  glutDisplayFunc(draw);
  glutIdleFunc(idle);
  glutIgnoreKeyRepeat(1); // ignore keys held down



  glutCreateMenu(options);
  glutAddMenuEntry("Light candles for the Soldiers",1);
  glutAddMenuEntry("Quit",2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);



  initGL(1244, 700);
  glutMainLoop();
  return 0;
}
