#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLAUX.H>
#include<gl/gltexture.h>
#include <cmath>
#include<texture.h>
#include<gl/Model_3DS.h>
#include"camera.h"
#include<iostream>
#include<fstream>
#include<string>
# include <deque>
# include <string>
# include <sstream>


using namespace std;


///////////////
Model_3DS trafficlight1, tree1;
Model_3DS chairs23;
Model_3DS Container1;
Camera mycamera;
int ints[5];
string myArray[5];
float m = 0.1;
///////////////


HDC			hDC = NULL;
HGLRC		hRC = NULL;
HWND		hWnd = NULL;
HINSTANCE	hInstance;

bool	keys[256];
bool	active = TRUE;
bool	fullscreen = FALSE;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 2.0, 8000.0);//This fixes the whole see-through walls problem


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int rock, sand, grass, street, stW;

int sun, up;
int  road, street1, mallt, roof, floor1, parking, park, P, white, logo, thedoor, building, cashier, cashiertabel, pic, pic1, pic2, flagImg;
int stand1, stand2, stand3, box,  cooler1, cooler2, mcooler1, mcooler2, mcooler3, mcoolercover, fp1, fp2, fp3, fp4, fp5, fp6, coffee;
int ad1, ad2, ad3, ad4, tsellertabel, seet, down, screen, wood, elevatormetal;
int treeBark, treeLeaves;
GLTexture glass, out, body, stone, leaf, vasa, chair1, chair22, metal, tabel1, bodywomen, bodywomen2, boybody, girlbody, lampp, yello;
Model_3DS* car, * cashier1, * plant, * chair, * chair2, * tabel, * women, * women2, * boy, * girl, * lamp;
int mol;
int mall1, glassDoor, wall, wallCach, whitedoor, shop, shop2;
GLTexture mal11, mal12, mal13, mal14;
Model_3DS* mal1, * mal2, * mal3, * ch1, * mal4, * man, * woman;
GLfloat LightPos[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat LightPos1[] = { 0.0f,100.0f,500.0f,1.0f };
GLfloat LightAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightAmb1[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat LightDiff[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightDiff1[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat LightSpec[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightSpec1[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat LightSpec2[] = { 1.0f,1.0f,0.0f,1.0f };
GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat MatShn[] = { 128.0f };

float secen_Ambient[] = { 0, 0, 0, 1 };
float secen_Specular[] = { 0, 0, 0, 1 };
float secen_Diffuse[] = { 0, 0, 0, 1 };
float secen_Position[] = { 0, 0, 0, 0 };
int sky;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{



	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);

	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); // Use less-equal depth function
	glPolygonOffset(1.0, 1.0); // Offset polygons
	glEnable(GL_POLYGON_OFFSET_FILL);
	glClearDepth(1.0f); // Clear depth buffer
	sky = LoadTexture((char*)"sky.bmp", 255);

	///
	glDisable(GL_TEXTURE_2D);
	///
	///
	rock = LoadTexture((char*)"rock.bmp", 255);
	sand = LoadTexture((char*)"Metal G6.bmp", 255);
	grass = LoadTexture((char*)"grass1.bmp", 255);
	street = LoadTexture((char*)"st.bmp", 255);
	/*trafficlight1 = Model_3DS();
	trafficlight1->Load("untitled.3ds");
	stW = LoadTexture((char*)"stW.bmp", 255);
	trafficlight1.Materials[0].tex.Load((char*)"st.bmp");*/
	///
	///



	///

	////

	////
	street1 = LoadTexture("street.bmp");
	mol = LoadTexture("m2.bmp");
	mallt = LoadTexture("mall.bmp");
	roof = LoadTexture("roof.bmp");
	floor1 = LoadTexture("floor.bmp");
	parking = LoadTexture("parking.bmp");
	park = LoadTexture("park.bmp");
	P = LoadTexture("P.bmp");
	logo = LoadTexture("logo.bmp");
	white = LoadTexture("white.bmp");
	thedoor = LoadTexture("thedoor.bmp");
	building = LoadTexture("Build6.bmp");
	cashier = LoadTexture("cashier.bmp");
	cashiertabel = LoadTexture("cashiertabel.bmp");
	stand1 = LoadTexture("stand1.bmp");
	stand2 = LoadTexture("stand 2.bmp");
	box = LoadTexture("wooden_crate.bmp");
	stand3 = LoadTexture("stand3.bmp");
	cooler1 = LoadTexture("drinks1.bmp");
	cooler2 = LoadTexture("drinks2.bmp");
	mcooler1 = LoadTexture("meet1.bmp");
	mcooler2 = LoadTexture("meet.bmp");
	mcooler3 = LoadTexture("meet2.bmp");
	mcoolercover = LoadTexture("meetcover.bmp");
	pic = LoadTexture("new-year-2024.bmp");
	pic1 = LoadTexture("pic1.bmp");
	flagImg = LoadTexture("flag.bmp");
	pic2 = LoadTexture("pic2.bmp");
	fp1 = LoadTexture("food-products1.bmp");
	fp2 = LoadTexture("food-products2.bmp");
	fp3 = LoadTexture("food-products3.bmp");
	fp4 = LoadTexture("food-products4.bmp");
	fp5 = LoadTexture("food-products5.bmp");
	fp6 = LoadTexture("food-products6.bmp");
	ad1 = LoadTexture("Hangoverposter.bmp");
	ad2 = LoadTexture("themother.bmp");
	ad3 = LoadTexture("jumanji.bmp");
	ad4 = LoadTexture("frozen.bmp");
	tsellertabel = LoadTexture("poster.bmp");
	seet = LoadTexture("seet.bmp");
	down = LoadTexture("down.bmp");
	screen = LoadTexture("screen.bmp");
	wood = LoadTexture("Wood.bmp");
	coffee = LoadTexture("coffee.bmp");
	elevatormetal = LoadTexture("Metal.bmp");

	//car
	car = new Model_3DS;
	car->Load("Car.3DS");
	glass.LoadBMP("Glass.bmp");
	out.LoadBMP("car.bmp");
	car->Materials[0].tex = out;
	car->Materials[1].tex = glass;
	//cashier
	cashier1 = new Model_3DS;
	cashier1->Load("Man N291113.3DS");
	body.LoadBMP("SBP01_01.bmp");
	cashier1->Materials[0].tex = body;
	//plant
	plant = new Model_3DS;
	plant->Load("Grass in box N220216.3DS");
	vasa.LoadBMP("Wood.bmp");
	leaf.LoadBMP("leaf.bmp");
	stone.LoadBMP("ground.bmp");
	plant->Materials[0].tex = vasa;
	plant->Materials[1].tex = leaf;
	plant->Materials[2].tex = stone;
	//chair
	chair = new Model_3DS;
	chair->Load("Chair N140911.3DS");
	chair1.LoadBMP("Wood.bmp");
	chair->Materials[0].tex = chair1;
	//chair2
	chair2 = new Model_3DS;
	chair2->Load("Chair bar RESTORATION HARDWARE 1920 AMERCIAN FACTORY N050919.3DS");
	metal.LoadBMP("Metal.bmp");
	chair22.LoadBMP("cashiertabel.bmp");
	chair2->Materials[0].tex = chair22;
	chair2->Materials[1].tex = metal;
	//tabel
	tabel = new Model_3DS;
	tabel->Load("Table round.3DS");
	tabel1.LoadBMP("Wood.bmp");
	tabel->Materials[0].tex = tabel1;
	//women
	women = new Model_3DS;
	women->Load("Woman sitting 1 N120814.3DS");
	bodywomen.LoadBMP("BWom0001.bmp");
	women->Materials[0].tex = bodywomen;
	//boy
	boy = new Model_3DS;
	boy->Load("Boy sitting N260814.3DS");
	boybody.LoadBMP("CBoy0005.bmp");
	boy->Materials[0].tex = boybody;
	//girl
	girl = new Model_3DS;
	girl->Load("Girl N090814.3DS");
	girlbody.LoadBMP("BWom0009.bmp");
	girl->Materials[0].tex = girlbody;
	//women2
	women2 = new Model_3DS;
	women2->Load("Woman sitting 2 N120814.3DS");
	bodywomen2.LoadBMP("BWom0009.bmp");
	women2->Materials[0].tex = bodywomen2;
	//lamp
	lamp = new Model_3DS;
	lamp->Load("lamp-post2.3DS");
	lampp.LoadBMP("Metal.bmp");
	yello.LoadBMP("yello.bmp");
	lamp->Materials[0].tex = lampp;
	lamp->Materials[1].tex = yello;
	//
	mal1 = new Model_3DS();
	mal1->Load((char*)"Rack market 2 N280817.3DS");
	mal1->Materials[0].tex.Load((char*)"Dirt bl.bmp");
	mal1->Materials[1].tex.Load((char*)"Dirt_map.bmp");
	mal1->Materials[2].tex.Load((char*)"fiz_wood.bmp");//
	mal1->Materials[3].tex.Load((char*)"leda oli.bmp");
	mal1->Materials[4].tex.Load((char*)"leda roz.bmp");
	mal1->Materials[5].tex.Load((char*)"leda whe.bmp");
	mal1->Materials[6].tex.Load((char*)"leda yel.bmp");
	mal1->Materials[7].tex.Load((char*)"metal.bmp");//
	mal2 = new Model_3DS();
	mal2->Load((char*)"Rack shirts N131213.3DS");//
	mal2->Materials[0].tex.Load((char*)"shirt_climb hard.bmp");
	mal2->Materials[1].tex.Load((char*)"shirt_climb hard_spec.bmp");
	mal2->Materials[2].tex.Load((char*)"shirt_rocker.bmp");
	mal2->Materials[3].tex.Load((char*)"shirt_tag.bmp");
	mal3 = new Model_3DS();
	mal3->Load((char*)"dress1.3ds");//
	mal3->Materials[0].tex.Load((char*)"dressTex1.bmp");
	mal3->Materials[1].tex.Load((char*)"dressTex2.bmp");
	mal3->Materials[2].tex.Load((char*)"dressTex3.bmp");
	//table
	ch1 = new Model_3DS();
	ch1->Load((char*)"Reception N180209.3DS");//
	ch1->Materials[0].tex.Load((char*)"w64.bmp");
	man = new Model_3DS();
	man->Load((char*)"girl2.3DS");//
	man->Materials[0].tex.Load((char*)"girl2.bmp");
	woman = new Model_3DS();
	woman->Load((char*)"girl2.3DS");//
	woman->Materials[0].tex.Load((char*)"girl2.bmp");

	Container1 = Model_3DS();
	Container1.Load((char*)"Conteiner shipping N290612.3ds");
	Container1.Materials[0].tex.Load((char*)"F1000W1.bmp");

	tree1 = Model_3DS();
	tree1.Load((char*)"tree11.3ds");
	tree1.Materials[0].tex.Load((char*)"bark_loo.bmp");
	tree1.Materials[1].tex.Load((char*)"bark_loo.bmp");
	tree1.Materials[2].tex.Load((char*)"blatt1.bmp");
	tree1.Materials[3].tex.Load((char*)"bark_loo.bmp");
	tree1.Materials[4].tex.Load((char*)"blatt1.bmp");

	chairs23 = Model_3DS();
	chairs23.Load((char*)"Bench.3ds");
	chairs23.Materials[0].tex.Load((char*)"4_2_11_b.bmp");
	chairs23.Materials[1].tex.Load((char*)"leather_reflect.bmp");
	chairs23.Materials[2].tex.Load((char*)"leather_reflect.bmp");
	return TRUE;										// Initialization Went OK
}

void malican() {
	glPushMatrix();
	man->pos.x = 70;
	man->pos.y = -229.5;
	man->pos.z = 220;
	man->scale = 0.2;
	man->Draw();
	glPopMatrix();
	mal1->pos.x = 65;
	mal1->pos.y = -200;
	mal1->pos.z = 260;
	mal1->scale = 0.005;
	mal1->Draw();
	ch1->pos.x = 80;
	ch1->pos.y = -229.5;
	ch1->rot.y = 90;
	ch1->pos.z = 220;
	ch1->scale = 0.7;
	ch1->Draw();
}
void SecondStage(int womanRotY, int chRotY, int posZ) {
	woman->pos.x = 70;
	woman->pos.y = -229;
	woman->pos.z = posZ;
	woman->rot.y = womanRotY;
	woman->scale = 0.2;
	woman->Draw();
	ch1->rot.y = chRotY;
	ch1->pos.x = 70;
	ch1->pos.y = -229.5;
	ch1->pos.z = 275;
	ch1->scale = 0.7;
	ch1->Draw();
	mal3->pos.x = 0;
	mal3->pos.y = -216;
	mal3->pos.z = 291;
	mal3->scale = 0.05;
	mal3->Draw();//rotate this
	mal2->pos.x = 20;
	mal2->pos.y = -224.15;
	mal2->pos.z = 290;
	mal2->scale = 0.5;
	mal2->Draw();

	//Back1
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(100, -228, 250);//v5
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 300);//v6
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 300);//v7
	//glTexCoord2d(0, 1);
	//glVertex3d(100, -160, 250);//v8
	//glEnd();
	////Left1
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(0, -228, 250);//v1
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 250);//v5
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 250);//v8
	//glTexCoord2d(0, 1);
	//glVertex3d(0, -160, 250);//v4
	//glEnd();
	////R
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(0, -228, 300);//v1
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 300);//v5
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 300);//v8
	//glTexCoord2d(0, 1);
	//glVertex3d(0, -160, 300);//v4
	//glEnd();
	//R
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(0, -228, 250);//v5
	//glTexCoord2d(1, 0);
	//glVertex3d(0, -228, 300);//v6
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -220, 300);//v4
	//glTexCoord2d(0, 1);
	//glVertex3d(100, -228, 250);//v5
	//glEnd();
}
void SecondStag2() {
	malican();
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(50, -228, 200);//v2
	//glTexCoord2d(1, 0);
	//glVertex3d(50, -228, 300);//v6
	//glTexCoord2d(1, 1);
	//glVertex3d(50, -160, 300);//v7
	//glTexCoord2d(0, 1);
	//glVertex3d(50, -160, 200);//v3
	//glEnd();
	////Back1
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(100, -228, 200);//v5
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 300);//v6
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 300);//v7
	//glTexCoord2d(0, 1);
	//glVertex3d(100, -160, 200);//v8
	//glEnd();
	////Left1
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(50, -228, 200);//v1
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 200);//v5
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 200);//v8
	//glTexCoord2d(0, 1);
	//glVertex3d(50, -160, 200);//v4
	//glEnd();
	////R
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(50, -228, 300);//v1
	//glTexCoord2d(1, 0);
	//glVertex3d(100, -228, 300);//v5
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -160, 300);//v8
	//glTexCoord2d(0, 1);
	//glVertex3d(50, -160, 300);//v4
	//glEnd();
	////R
	//glBindTexture(GL_TEXTURE_2D, mol);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(50, -228, 200);//v5
	//glTexCoord2d(1, 0);
	//glVertex3d(50, -228, 300);//v6
	//glTexCoord2d(1, 1);
	//glVertex3d(100, -220, 300);//v4
	//glTexCoord2d(0, 1);
	//glVertex3d(100, -228, 200);//v5
	//glEnd();
}
void model()
{
	//car
	glPushMatrix();
	car->pos.x = -35;
	car->pos.y = -347;
	car->pos.z = 180;
	car->scale = 0.6;
	car->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(100, 0, 0);
	car->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-100, 0, -100);
	car->Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(530, 60, 90);
	glRotated(90, 0, 1, 0);
	glRotated(180, 0, 1, 0);
	car->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(330, 60, 50);
	car->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(410, 60, 50);
	car->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(480, 60, 50);
	car->Draw();
	glPopMatrix();
	//cashier
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	cashier1->pos.x = -170;
	cashier1->pos.y = -330;
	cashier1->pos.z = -150;
	cashier1->scale = 0.9;
	cashier1->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	cashier1->pos.x = -270;
	cashier1->pos.y = -185;
	cashier1->pos.z = 90;
	cashier1->scale = 0.7;
	cashier1->Draw();
	glPopMatrix();
	//plant
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	plant->pos.x = 315;
	plant->pos.y = -288;
	plant->pos.z = 150;
	plant->scale = 0.1;
	plant->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	plant->pos.x = 315;
	plant->pos.y = -288;
	plant->pos.z = 50;
	plant->scale = 0.1;
	plant->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	plant->pos.x = 315;
	plant->pos.y = -288;
	plant->pos.z = -40;
	plant->scale = 0.1;
	plant->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	plant->pos.x = 315;
	plant->pos.y = -288;
	plant->pos.z = -160;
	plant->scale = 0.1;
	plant->Draw();
	glPopMatrix();
	//chair
	glPushMatrix();
	glTranslated(-440, 0, 90);
	glRotated(90, 0, 1, 0);
	chair->pos.x = -180;
	chair->pos.y = -145;
	chair->pos.z = 250;
	chair->scale = 0.04;
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-390, 0, 100);
	glRotated(90, 0, 1, 0);
	chair->pos.x = -180;
	chair->pos.y = -145;
	chair->pos.z = 250;
	chair->scale = 0.04;
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-340, 0, 75);
	glRotated(90, 0, 1, 0);
	chair->pos.x = -180;
	chair->pos.y = -145;
	chair->pos.z = 250;
	chair->scale = 0.04;
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-290, 0, 95);
	glRotated(90, 0, 1, 0);
	chair->pos.x = -180;
	chair->pos.y = -145;
	chair->pos.z = 250;
	chair->scale = 0.04;
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(10, 0, 0);
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(60, 0, 8);
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(150, 0, 8);
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-350, 0, 535);
	glRotated(180, 0, 1, 0);
	chair->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-255, 0, 520);
	glRotated(180, 0, 1, 0);
	chair->Draw();
	glPopMatrix();
	//chair2
	glPushMatrix();
	chair2->pos.x = -185;
	chair2->pos.y = -145;
	chair2->pos.z = 235;
	chair2->scale = 0.4;
	chair2->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(30, 0, 0);
	chair2->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(60, 0, 0);
	chair2->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(90, 0, 0);
	chair2->Draw();
	glPopMatrix();
	//tabel
	glPushMatrix();
	tabel->pos.x = -170;
	tabel->pos.y = -147;
	tabel->pos.z = 270;
	tabel->scale = 0.08;
	tabel->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(50, 0, 10);
	tabel->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(100, 0, -15);
	tabel->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(150, 0, 10);
	tabel->Draw();
	glPopMatrix();
	//women
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women->pos.x = 0;
	women->pos.y = -135;
	women->pos.z = -30;
	women->scale = 0.28;
	women->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women->pos.x = 40;
	women->pos.y = -135;
	women->pos.z = -30;
	women->scale = 0.28;
	women->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women->pos.x = 80;
	women->pos.y = -135;
	women->pos.z = -30;
	women->scale = 0.28;
	women->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women->pos.x = 120;
	women->pos.y = -135;
	women->pos.z = -30;
	women->scale = 0.28;
	women->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women->pos.x = 160;
	women->pos.y = -135;
	women->pos.z = -30;
	women->scale = 0.28;
	women->Draw();
	glPopMatrix();
	//boy
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	boy->pos.x = 45;
	boy->pos.y = -145;
	boy->pos.z = -60;
	boy->scale = 40;
	boy->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	boy->pos.x = 85;
	boy->pos.y = -145;
	boy->pos.z = -60;
	boy->scale = 40;
	boy->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	boy->pos.x = 125;
	boy->pos.y = -145;
	boy->pos.z = -60;
	boy->scale = 40;
	boy->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	boy->pos.x = 165;
	boy->pos.y = -145;
	boy->pos.z = -60;
	boy->scale = 40;
	boy->Draw();
	glPopMatrix();
	//girl
	glPushMatrix();
	girl->pos.x = -100;
	girl->pos.y = -160;
	girl->pos.z = 200;
	girl->scale = 0.8;
	girl->Draw();
	glPopMatrix();
	glPushMatrix();
	girl->pos.x = 85;
	girl->pos.y = -160;
	girl->pos.z = 240;
	girl->scale = 0.8;
	girl->Draw();
	glPopMatrix();
	//women2
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women2->pos.x = 40;
	women2->pos.y = -150;
	women2->pos.z = -80;
	women2->scale = 0.2;
	women2->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women2->pos.x = 80;
	women2->pos.y = -150;
	women2->pos.z = -80;
	women2->scale = 0.2;
	women2->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women2->pos.x = 120;
	women2->pos.y = -150;
	women2->pos.z = -80;
	women2->scale = 0.2;
	women2->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	women2->pos.x = 160;
	women2->pos.y = -150;
	women2->pos.z = -80;
	women2->scale = 0.2;
	women2->Draw();
	glPopMatrix();
	//lamp

	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);
	lamp->pos.x = -90;
	lamp->pos.y = -255;
	lamp->pos.z = 700;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();



	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);
	lamp->pos.x = -90;
	lamp->pos.y = -255;
	lamp->pos.z = 400;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(700, 0, 483);
	glRotated(-90, 0, 1, 0);
	lamp->pos.x = -90;
	lamp->pos.y = -255;
	lamp->pos.z = 500;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(700, 0, 483);
	glRotated(-90, 0, 1, 0);
	lamp->pos.x = -90;
	lamp->pos.y = -255;
	lamp->pos.z = 200;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);///////////////////
	lamp->pos.x = 70;
	lamp->pos.y = -255;
	lamp->pos.z = 380;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);///////////////////////////////////////////////
	lamp->pos.x = 200;
	lamp->pos.y = -255;
	lamp->pos.z = 380;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);///////////////////
	lamp->pos.x = 70;
	lamp->pos.y = -255;
	lamp->pos.z = -100;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(300, 0, 483);
	glRotated(-90, 0, 1, 0);///////////////////////////////////////////////
	lamp->pos.x = 200;
	lamp->pos.y = -255;
	lamp->pos.z = -100;
	lamp->scale = 0.8;
	lamp->Draw();
	glPopMatrix();

}

GLfloat k = 0, c = 0;
int mouseX = 0, mouseY = 0;
bool isClicked = false, isRClicked = false;
void mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
	if (isClicked) k = float((mouseX - c) * 10) / 640;
	if (isRClicked) k = float((mouseX + c) * 10) / 640;
	c += 10;
}

double movX, movY = 1, movZ = -25;
double lX, lY;

//void Camera()
//{
//	gluLookAt(movX, movY, movZ, lX, lY,-5, 0, 1, 0);
//	if (keys['D'])
//		movX +=2;
//	if (keys['A'])
//		movX -= 2;
//	if (keys['W'])
//		movY += 2;
//	if (keys['S'])
//		movY -= 2;
//	if (keys['Z'])
//		movZ += 2;
//	if (keys['X'])
//		movZ -= 2;
//	if (keys[VK_LEFT])
//		lX -= 2;
//	if (keys[VK_RIGHT])
//		lX += 2;
//	if (keys[VK_UP])
//		lY += 2;
//	if (keys[VK_DOWN])
//		lY -= 2;
//}

void flag() {
	// Flag
	glBindTexture(GL_TEXTURE_2D, flagImg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(50, -100, 700);
	glTexCoord2d(1, 0);
	glVertex3d(150, -100, 700);
	glTexCoord2d(1, 1);
	glVertex3d(150, -50, 700);
	glTexCoord2d(0, 1);
	glVertex3d(50, -50, 700);
	glEnd();

	// Pole for the flag
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3d(150, -300, 700);
	glTexCoord2d(1, 0);
	glVertex3d(155, -300, 700);
	glTexCoord2d(1, 1);
	glVertex3d(155, -50, 700);
	glTexCoord2d(0, 1);
	glVertex3d(150, -50, 700);


	glTexCoord2d(0, 0);
	glVertex3d(150, -300, 695);
	glTexCoord2d(1, 0);
	glVertex3d(155, -300, 695);
	glTexCoord2d(1, 1);
	glVertex3d(155, -50, 695);
	glTexCoord2d(0, 1);
	glVertex3d(150, -50, 695);


	glTexCoord2d(0, 0);
	glVertex3d(150, -300, 700);
	glTexCoord2d(1, 0);
	glVertex3d(150, -300, 695);
	glTexCoord2d(1, 1);
	glVertex3d(150, -50, 695);
	glTexCoord2d(0, 1);
	glVertex3d(150, -50, 700);


	glTexCoord2d(0, 0);
	glVertex3d(155, -300, 700);
	glTexCoord2d(1, 0);
	glVertex3d(155, -300, 695);
	glTexCoord2d(1, 1);
	glVertex3d(155, -50, 695);
	glTexCoord2d(0, 1);
	glVertex3d(155, -50, 700);


	glTexCoord2d(0, 0);
	glVertex3d(150, -50, 700);
	glTexCoord2d(1, 0);
	glVertex3d(155, -50, 700);
	glTexCoord2d(1, 1);
	glVertex3d(155, -50, 695);
	glTexCoord2d(0, 1);
	glVertex3d(150, -50, 695);


	glTexCoord2d(0, 0);
	glVertex3d(150, -300, 700);
	glTexCoord2d(1, 0);
	glVertex3d(155, -300, 700);
	glTexCoord2d(1, 1);
	glVertex3d(155, -300, 695);
	glTexCoord2d(0, 1);
	glVertex3d(150, -300, 695);
	glEnd();


}
void storeFront() {

	glBindTexture(GL_TEXTURE_2D, mol);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(100, -228, 0);//v2
	glTexCoord2d(-1, 0);
	glVertex3d(100, -228, 300);//v6
	glTexCoord2d(-1, 1);
	glVertex3d(100, -160, 300);//v7
	glTexCoord2d(0, 1);
	glVertex3d(100, -160, 0);//v3
	glEnd();

}
void mall()
{
	//GF
	//Front1
	//1
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -300, 300);//v 1
	glTexCoord2d(0, 0.35);
	glVertex3d(-200, -230, 300);//v 2
	glTexCoord2d(0.2, 0.35);
	glVertex3d(-125, -230, 300);//v 7
	glTexCoord2d(0.2, 0);
	glVertex3d(-125, -300, 300);//v8 
	//2
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -300, 300);//v 1
	glTexCoord2d(0, 0.35);
	glVertex3d(-75, -230, 300);//v 2
	glTexCoord2d(0.25, 0.35);
	glVertex3d(75, -230, 300);//v 7
	glTexCoord2d(0.25, 0);
	glVertex3d(75, -300, 300);//v8 
	glEnd();
	//3
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(125, -300, 300);//v 1
	glTexCoord2d(0, 0.35);
	glVertex3d(125, -230, 300);//v 2
	glTexCoord2d(0.175, 0.35);
	glVertex3d(200, -230, 300);//v 7
	glTexCoord2d(0.175, 0);
	glVertex3d(200, -300, 300);//v8 
	//4
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-125, -245, 300);//v 1
	glTexCoord2d(0, 0.1);
	glVertex3d(-125, -230, 300);//v 2
	glTexCoord2d(0.14, 0.1);
	glVertex3d(-75, -230, 300);//v 7
	glTexCoord2d(0.14, 0);
	glVertex3d(-75, -245, 300);//v8 
	//5
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75, -245, 300);//v 1
	glTexCoord2d(0, 0.1);
	glVertex3d(75, -230, 300);//v 2
	glTexCoord2d(0.14, 0.1);
	glVertex3d(125, -230, 300);//v 7
	glTexCoord2d(0.14, 0);
	glVertex3d(125, -245, 300);//v8 

	//6
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -175, 300);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-200, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(-120, -50, 300);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(-120, -175, 300);//v8 

	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-120, -175, 300);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-120, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(-40, -50, 300);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(-40, -175, 300);//v8 

	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-40, -175, 300);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-40, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(40, -50, 300);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(40, -175, 300);//v8 

	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(40, -175, 300);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(40, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(120, -50, 300);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(120, -175, 300);//v8 

	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(120, -175, 300);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(120, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(200, -50, 300);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(200, -175, 300);//v8 


	//Back1
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -300, 0);//v5
	glTexCoord2d(1, 0);
	glVertex3d(200, -300, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -230, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(-200, -230, 0);//v8
	glEnd();
	//Left1
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -300, 300);//v1
	glTexCoord2d(1, 0);
	glVertex3d(-200, -300, 0);//v5
	glTexCoord2d(1, 1);
	glVertex3d(-200, -230, 0);//v8
	glTexCoord2d(0, 1);
	glVertex3d(-200, -230, 300);//v4
	glEnd();
	//Right1
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(200, -300, 300);//v2
	glTexCoord2d(1, 0);
	glVertex3d(200, -300, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -230, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(200, -230, 300);//v3
	glEnd();
	//down1
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -300, 300);//v1
	glTexCoord2d(5, 0);
	glVertex3d(-200, -300, 0);//v5
	glTexCoord2d(5, 5);
	glVertex3d(200, -300, 0);//v6
	glTexCoord2d(0, 5);
	glVertex3d(200, -300, 300);//v2
	glEnd();
	//1
	//Front2
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3d(-200, -230, 300);//v1
	glTexCoord2f(1, 0);
	glVertex3d(200, -230, 300);//v2
	glTexCoord2f(1, 1);
	glVertex3d(200, -50, 300);//v3
	glTexCoord2f(0, 1);
	glVertex3d(-200, -50, 300);//v4
	glEnd();
	//Back2
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -230, 0);//v5
	glTexCoord2d(1, 0);
	glVertex3d(200, -230, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -160, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(-200, -160, 0);//v8
	glEnd();
	//Left2
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -230, 300);//v1
	glTexCoord2d(1, 0);
	glVertex3d(-200, -230, 0);//v5
	glTexCoord2d(1, 1);
	glVertex3d(-200, -160, 0);//v8
	glTexCoord2d(0, 1);
	glVertex3d(-200, -160, 300);//v4
	glEnd();
	//Right2
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(200, -230, 300);//v2
	glTexCoord2d(1, 0);
	glVertex3d(200, -230, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -160, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(200, -160, 300);//v3
	glEnd();
	//down2
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -230, 300);//v1
	glTexCoord2d(5, 0);
	glVertex3d(-200, -230, 0);//v5
	glTexCoord2d(5, 5);
	glVertex3d(101, -230, 0);//v6
	glTexCoord2d(0, 5);
	glVertex3d(101, -230, 300);//v2
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(101, -230, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3d(200, -230, 50);//v5
	glTexCoord2d(1, 4);
	glVertex3d(200, -230, 300);//v6
	glTexCoord2d(0, 4);
	glVertex3d(101, -230, 300);//v2
	glEnd();
	//2
	//Front3
	/*
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(1.0f,1.0f,1.0f,0.3f);
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -160,300);//v1
	glTexCoord2d(1, 0);
	glVertex3d(200, -160,300);//v2
	glTexCoord2d(1, 1);
	glVertex3d(200, -90,300);//v3
	glTexCoord2d(0, 1);
	glVertex3d(-200, -90,300);//v4
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
	*/
	//Back3
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -160, 0);//v5
	glTexCoord2d(1, 0);
	glVertex3d(200, -160, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -50, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(-200, -50, 0);//v8
	glEnd();
	//Left3
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -160, 300);//v1
	glTexCoord2d(1, 0);
	glVertex3d(-200, -160, 0);//v5
	glTexCoord2d(1, 1);
	glVertex3d(-200, -50, 0);//v8
	glTexCoord2d(0, 1);
	glVertex3d(-200, -50, 300);//v4
	glEnd();
	//Right3
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(200, -160, 300);//v2
	glTexCoord2d(1, 0);
	glVertex3d(200, -160, 0);//v6
	glTexCoord2d(1, 1);
	glVertex3d(200, -50, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3d(200, -50, 300);//v3
	glEnd();

	//top3
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -50, 300);//v4
	glTexCoord2d(5, 0);
	glVertex3d(-200, -50, 0);//v8
	glTexCoord2d(5, 5);
	glVertex3d(200, -50, 0);//v7
	glTexCoord2d(0, 5);
	glVertex3d(200, -50, 300);//v3
	glEnd();

	//down3
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -160, 300);//v1
	glTexCoord2d(5, 0);
	glVertex3d(-200, -160, 0);//v5
	glTexCoord2d(5, 5);
	glVertex3d(101, -160, 0);//v6
	glTexCoord2d(0, 5);
	glVertex3d(101, -160, 300);//v2
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(101, -160, 50);//v1
	glTexCoord2d(4, 0);
	glVertex3d(101, -160, 300);//v5
	glTexCoord2d(4, 1);
	glVertex3d(200, -160, 300);//v6
	glTexCoord2d(0, 1);
	glVertex3d(200, -160, 50);//v2a
	glEnd();
	//mallname
	glBindTexture(GL_TEXTURE_2D, logo);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100, -160, 300);//v1
	glTexCoord2d(0, 1);
	glVertex3d(-100, -75, 300);//v2
	glTexCoord2d(1, 1);
	glVertex3d(100, -75, 300);//v7
	glTexCoord2d(1, 0);
	glVertex3d(100, -160, 300);//v8
	glEnd();
}
void externaldoor()
{
	//door
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-125, -299, 325);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-125, -240, 325);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(-125, -240, 275);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(-125, -299, 275);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -299, 325);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-75, -240, 325);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(-75, -240, 275);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(-75, -299, 275);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(125, -299, 325);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(125, -240, 325);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(125, -240, 275);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(125, -299, 275);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75, -299, 325);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(75, -240, 325);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(75, -240, 275);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(75, -299, 275);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, mallt);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-125, -240, 325);//v 1
	glTexCoord2d(1, 0);
	glVertex3d(-125, -240, 275);//v 2
	glTexCoord2d(1, 1);
	glVertex3d(-75, -240, 275);//v 7
	glTexCoord2d(0, 1);
	glVertex3d(-75, -240, 325);//v8 
	glEnd();
	//roof
	//glBindTexture(GL_TEXTURE_2D, mallt);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(200, -50, 300);//v 1
	//glTexCoord2d(1, 0);
	//glVertex3d(200, -50, -50);//v 2
	//glTexCoord2d(1, 1);
	//glVertex3d(-200, -50, -50);//v 7
	//glTexCoord2d(0, 1);
	//glVertex3d(-200, -50, 300);//v8 
	//glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);

}
double x = 0;
void door()
{
	glPushMatrix();
	glTranslated(100, -247, 300);
	glRotated(x, 0, 1, 0);
	x += 0.01;//This changes the speed at which the front doors rotate at
	glBindTexture(GL_TEXTURE_2D, thedoor);
	auxSolidCylinder(1, 52);
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25, 2, 0);//v 1
	glTexCoord2d(2, 0);
	glVertex3d(-25, -53, 0);//v 2
	glTexCoord2d(2, 2);
	glVertex3d(-1, -53, 0);//v 7
	glTexCoord2d(0, 2);
	glVertex3d(-1, 2, 0);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25, 2, 0);//v 3
	glTexCoord2d(2, 0);
	glVertex3d(25, -53, 0);//v 4
	glTexCoord2d(2, 2);
	glVertex3d(1, -53, 0);//v 5
	glTexCoord2d(0, 2);
	glVertex3d(1, 2, 0);//v 6
	glEnd();//////////////
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25, 2, 0);//v 1
	glTexCoord2d(2, 0);
	glVertex3d(-25, -53, 0);//v 2
	glTexCoord2d(2, 2);
	glVertex3d(-1, -53, 0);//v 7
	glTexCoord2d(0, 2);
	glVertex3d(-1, 2, 0);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25, 2, 0);//v 3
	glTexCoord2d(2, 0);
	glVertex3d(25, -53, 0);//v 4
	glTexCoord2d(2, 2);
	glVertex3d(1, -53, 0);//v 5
	glTexCoord2d(0, 2);
	glVertex3d(1, 2, 0);//v 6
	glEnd();
	glPopMatrix();
	glPopMatrix();
	////2
	glPushMatrix();
	glTranslated(-100, -247, 300);
	glRotated(x, 0, 1, 0);
	x += 0.5;
	auxSolidCylinder(1, 52);
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25, 2, 0);//v 1
	glTexCoord2d(2, 0);
	glVertex3d(-25, -53, 0);//v 2
	glTexCoord2d(2, 2);
	glVertex3d(-1, -53, 0);//v 7
	glTexCoord2d(0, 2);
	glVertex3d(-1, 2, 0);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25, 2, 0);//v 3
	glTexCoord2d(2, 0);
	glVertex3d(25, -53, 0);//v 4
	glTexCoord2d(2, 2);
	glVertex3d(1, -53, 0);//v 5
	glTexCoord2d(0, 2);
	glVertex3d(1, 2, 0);//v 6
	glEnd();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25, 2, 0);//v 1
	glTexCoord2d(2, 0);
	glVertex3d(-25, -53, 0);//v 2
	glTexCoord2d(2, 2);
	glVertex3d(-1, -53, 0);//v 7
	glTexCoord2d(0, 2);
	glVertex3d(-1, 2, 0);//v8 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, thedoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25, 2, 0);//v 3
	glTexCoord2d(2, 0);
	glVertex3d(25, -53, 0);//v 4
	glTexCoord2d(2, 2);
	glVertex3d(1, -53, 0);//v 5
	glTexCoord2d(0, 2);
	glVertex3d(1, 2, 0);//v 6
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
void Parking_un()
{
	//un
	//Front0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -360, 300);//v1
	glTexCoord2d(2, 0);
	glVertex3d(200, -360, 300);//v2
	glTexCoord2d(2, 2);
	glVertex3d(200, -300, 300);//v3
	glTexCoord2d(0, 2);
	glVertex3d(-200, -300, 300);//v4
	glEnd();
	//Back0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -360, 0);//v5
	glTexCoord2d(2, 0);
	glVertex3d(200, -360, 0);//v6
	glTexCoord2d(2, 2);
	glVertex3d(200, -300, 0);//v7
	glTexCoord2d(0, 2);
	glVertex3d(-200, -300, 0);//v8
	glEnd();
	//Left0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -360, 300);//v1
	glTexCoord2d(2, 0);
	glVertex3d(-200, -360, 0);//v5
	glTexCoord2d(2, 2);
	glVertex3d(-200, -300, 0);//v8
	glTexCoord2d(0, 2);
	glVertex3d(-200, -300, 300);//v4
	glEnd();
	//Right0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(200, -360, 300);//v2
	glTexCoord2d(2, 0);
	glVertex3d(200, -300, 300);//v3
	glTexCoord2d(2, 2);
	glVertex3d(200, -300, 100);//v7
	glTexCoord2d(0, 2);
	glVertex3d(200, -360, 100);//v6
	glEnd();

	//top0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -301, 300);//v4
	glTexCoord2d(2, 0);
	glVertex3d(-200, -301, 0);//v8
	glTexCoord2d(2, 2);
	glVertex3d(200, -301, 0);//v7
	glTexCoord2d(0, 2);
	glVertex3d(200, -301, 300);//v3
	glEnd();

	//down0
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -360, 300);//v1
	glTexCoord2d(2, 0);
	glVertex3d(-200, -360, 0);//v5
	glTexCoord2d(2, 2);
	glVertex3d(200, -360, 0);//v6
	glTexCoord2d(0, 2);
	glVertex3d(200, -360, 300);//v2
	glEnd();
	//outparking
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(200, -360, 100);//v6
	glTexCoord2d(2, 0);
	glVertex3d(200, -360, 0);//v6
	glTexCoord2d(2, 2);
	glVertex3d(300, -300, 0);//v6
	glTexCoord2d(0, 2);
	glVertex3d(300, -300, 100);//v7
	glEnd();
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(300, -300, 0);
	glTexCoord2d(2, 0);
	glVertex3d(300, -300, 100);
	glTexCoord2d(2, 2);
	glVertex3d(400, -300, 100);
	glTexCoord2d(0, 2);
	glVertex3d(400, -300, 0);
	glEnd();
	///parking
	//Front
	glBindTexture(GL_TEXTURE_2D, park);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(201, -300, 300);//v1
	glTexCoord2d(2, 0);
	glVertex3d(500, -300, 300);//v2
	glTexCoord2d(2, 2);
	glVertex3d(500, -270, 300);//v3
	glTexCoord2d(0, 2);
	glVertex3d(201, -270, 300);//v4
	glEnd();
	//Back
	glBindTexture(GL_TEXTURE_2D, park);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(201, -300, 290);//v5
	glTexCoord2d(2, 0);
	glVertex3d(500, -300, 290);//v6
	glTexCoord2d(2, 2);
	glVertex3d(500, -270, 290);//v7
	glTexCoord2d(0, 2);
	glVertex3d(201, -270, 290);//v8
	//Left
	glBindTexture(GL_TEXTURE_2D, park);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(201, -300, 300);//v1
	glTexCoord2d(1, 0);
	glVertex3d(201, -300, 290);//v5
	glTexCoord2d(1, 1);
	glVertex3d(201, -270, 290);//v8
	glTexCoord2d(0, 1);
	glVertex3d(201, -270, 300);//v4
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, park);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(500, -300, 300);//v2
	glTexCoord2d(0, 0);
	glVertex3d(500, -300, 290);//v6
	glTexCoord2d(0, 1);
	glVertex3d(500, -270, 290);//v7
	glTexCoord2d(1, 1);
	glVertex3d(500, -270, 300);//v3
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, park);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(201, -270, 300);//v4
	glTexCoord2d(1, 0);
	glVertex3d(500, -270, 300);//v3
	glTexCoord2d(1, 1);
	glVertex3d(500, -270, 290);//v7
	glTexCoord2d(0, 1);
	glVertex3d(201, -270, 290);//v8
	glEnd();

}
void MyCube() {
	glBindTexture(GL_TEXTURE_2D, building);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(400, -300, -250);
	glTexCoord2d(1, 0);
	glVertex3d(300, -300, -250);
	glTexCoord2d(1, 1);
	glVertex3d(300, -100, -250);
	glTexCoord2d(0, 1);
	glVertex3d(400, -100, -250);
	glEnd();
	//Back
	glBindTexture(GL_TEXTURE_2D, building);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(400, -300, -450);
	glTexCoord2d(1, 0);
	glVertex3d(300, -300, -450);
	glTexCoord2d(1, 1);
	glVertex3d(300, -100, -450);
	glTexCoord2d(0, 1);
	glVertex3d(400, -100, -450);
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, building);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(300, -300, -450);
	glTexCoord2d(1, 0);
	glVertex3d(300, -300, -250);
	glTexCoord2d(1, 1);
	glVertex3d(300, -100, -250);
	glTexCoord2d(0, 1);
	glVertex3d(300, -100, -450);
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, building);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(400, -100, -250);
	glTexCoord2d(0, 0);
	glVertex3d(300, -100, -450);
	glTexCoord2d(0, 1);
	glVertex3d(300, -100, -450);
	glTexCoord2d(1, 1);
	glVertex3d(400, -100, -250);
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(300, -100, -250);
	glTexCoord2d(1, 0);
	glVertex3d(400, -100, -250);
	glTexCoord2d(1, 1);
	glVertex3d(400, -100, -450);
	glTexCoord2d(0, 1);
	glVertex3d(300, -100, -450);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, building);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(400, -300, -450);
	glTexCoord2d(1, 0);
	glVertex3d(400, -300, -250);
	glTexCoord2d(1, 1);
	glVertex3d(400, -100, -250);
	glTexCoord2d(0, 1);
	glVertex3d(400, -100, -450);
	glEnd();
}
void Elevator()
{
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 255);
	//Frontgf
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(170, -299.8, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(170, -230, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -230, 50);//v4
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(130, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -299.8, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(101, -230, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(130, -230, 50);//v4
	glEnd();
	//3
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -240, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -240, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(101, -230, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -230, 50);//v4
	glEnd();
	//Front1
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -230, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(170, -230, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(170, -160, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -160, 50);//v4
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(130, -230, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -230, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(101, -160, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(130, -160, 50);//v4
	glEnd();
	//3
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -170, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -170, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(101, -160, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -160, 50);//v4
	glEnd();
	//Front2
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -160, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(170, -160, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(170, -50, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -50, 50);//v4
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(130, -160, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -160, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(101, -50, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(130, -50, 50);//v4
	glEnd();
	//3
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -100, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(100, -100, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(100, -50, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(199, -50, 50);//v4
	glEnd();
	//Back
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -299.8, 2);//v5
	glTexCoord2d(1, 0);
	glVertex3f(101, -299.8, 2);//v6
	glTexCoord2d(1, 1);
	glVertex3f(101, -50, 2);//v7
	glTexCoord2d(0, 1);
	glVertex3f(199, -50, 2);//v8
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(101, -299.8, 50);//v2
	glTexCoord2d(1, 0);
	glVertex3f(101, -50, 50);//v3
	glTexCoord2d(1, 1);
	glVertex3f(101, -50, 2);//v7
	glTexCoord2d(0, 1);
	glVertex3f(101, -299.8, 2);//v6
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(199, -50, 50);//v4
	glTexCoord2d(1, 1);
	glVertex3f(199, -50, 2);//v8
	glTexCoord2d(0, 1);
	glVertex3f(199, -299.8, 2);//v5
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, elevatormetal);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -50, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -50, 50);//v4
	glTexCoord2d(1, 1);
	glVertex3f(101, -50, 2);//v8
	glTexCoord2d(0, 1);
	glVertex3f(199, -50, 2);//v5
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
}
double z = 0, y = 0, t = 0;
void ElevatorRdoor()
{
	glPushMatrix();
	glTranslated(z, 0, 0);
	if (keys['P'] && z < 20)
	{
		z += 0.25;
	}
	if (keys['O'] && z > 0)
	{
		z -= 0.25;
	}
	if (keys['H']) {
		cout << mycamera.position[0] << "\t" << mycamera.position[1] << "\t" << mycamera.position[2] << "\t";
	}
	//gf
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(170, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(150, -299.8, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(150, -240, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(170, -240, 50);//v4
	glEnd();
	//1
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(170, -230, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(150, -230, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(150, -170, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(170, -170, 50);//v4
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(170, -160, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(150, -160, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(150, -100, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(170, -100, 50);//v4
	glEnd();
	glPopMatrix();
}
void ElevatorLdoor()
{
	glPushMatrix();
	glTranslated(y, 0, 0);
	if (keys['O'] && y < 0)	//add a condition to make the door close at a certain point
	{
		y += 0.25;
	}
	if (keys['P'] && y > -20)//same here
	{
		y -= 0.25;
	}
	//gf
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(150, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(130, -299.8, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(130, -240, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(150, -240, 50);//v4
	glEnd();
	//1
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(150, -230, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(130, -230, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(130, -170, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(150, -170, 50);//v4
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(150, -160, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(130, -160, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3f(130, -100, 50);//v3
	glTexCoord2d(0, 1);
	glVertex3f(150, -100, 50);//v4
	glEnd();
	glPopMatrix();
}
void Elevatordown()
{
	glPushMatrix();
	glTranslated(0, t, 0);
	if (keys['L'] && t < 139)
	{
		t += 0.8;
	}
	if (keys['K'] && t > 0)
	{
		t -= 0.8;
	}
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199, -299.8, 50);//v1
	glTexCoord2d(1, 0);
	glVertex3f(101, -299.8, 50);//v2
	glTexCoord2d(1, 1);
	glVertex3d(101, -299.8, 0);//v7
	glTexCoord2d(0, 1);
	glVertex3f(199, -299.8, 0);//v5
	glEnd();
	glPopMatrix();
}
void supermarket()
{
	//stand
	//1
	//Front
	glBindTexture(GL_TEXTURE_2D, stand1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-140, -270, 10);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-140, -240, 10);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-180, -240, 10);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-180, -240, 10);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-180, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-180, -270, 0);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-140, -270, 10);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(-140, -240, 10);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-140, -240, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-140, -270, 0);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-140, -240, 10);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-180, -240, 10);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-180, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-140, -240, 0);//v 7
	glEnd();
	//down
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-180, -270, 10);//v 1
	glTexCoord2d(0, 0);
	glVertex3f(-140, -270, 10);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(-140, -270, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-180, -270, 0);//v 2
	glEnd();
	//2
	//Front
	glBindTexture(GL_TEXTURE_2D, stand2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-110, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-70, -270, 10);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-70, -240, 10);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-110, -240, 10);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-110, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-110, -240, 10);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-110, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-110, -270, 0);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-70, -270, 10);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(-70, -240, 10);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-70, -240, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-70, -270, 0);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-110, -240, 10);//v 4
	glTexCoord2d(1, 0);
	glVertex3f(-70, -240, 10);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-70, -240, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-110, -240, 0);//v 8
	glEnd();
	//down
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-110, -270, 10);//v 1
	glTexCoord2d(0, 0);
	glVertex3f(-70, -270, 10);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(-70, -270, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-110, -270, 0);//v 5
	glEnd();
	//3
	//Front
	glBindTexture(GL_TEXTURE_2D, stand3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(0, -270, 10);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(0, -240, 10);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-40, -240, 10);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -270, 10);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-40, -270, 0);//v 5
	glTexCoord2d(1, 1);
	glVertex3f(-40, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-40, -240, 10);//v 4
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(0, -270, 10);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(0, -270, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(0, -240, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(0, -240, 10);//v 3
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(0, -240, 10);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-40, -240, 10);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-40, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(0, -240, 0);//v 7
	glEnd();
	//down
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-40, -270, 10);//v 1
	glTexCoord2d(0, 0);
	glVertex3f(-40, -270, 0);//v 5
	glTexCoord2d(0, 1);
	glVertex3f(0, -270, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(0, -270, 10);//v 2
	glEnd();
	//cooler
	//1
	//Front
	glBindTexture(GL_TEXTURE_2D, cooler1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(15, -299, 20);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(40, -299, 20);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(40, -240, 20);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(15, -240, 20);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(15, -299, 20);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(15, -299, 0);//v 5
	glTexCoord2d(1, 1);
	glVertex3f(15, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(15, -240, 20);//v 4
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(40, -299, 20);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(40, -299, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(40, -240, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(40, -240, 20);//v 3
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(40, -240, 20);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(15, -240, 20);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(15, -240, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(40, -240, 0);//v 7
	glEnd();
	//2
	//Front
	glBindTexture(GL_TEXTURE_2D, cooler2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(60, -299, 20);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(90, -299, 20);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(90, -250, 20);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(60, -250, 20);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(60, -299, 20);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(60, -299, 0);//v 5
	glTexCoord2d(1, 1);
	glVertex3f(60, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(60, -250, 20);//v 4
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(80, -299, 20);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(80, -299, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(80, -250, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(80, -250, 20);//v 3
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(90, -250, 20);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(60, -250, 20);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(60, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(90, -250, 0);//v 7
	glEnd();
	//meetcooler
	glPushMatrix();
	glTranslated(-199, 0, 50);
	glRotated(90, 0, 1, 0);
	//1
	//Front
	glBindTexture(GL_TEXTURE_2D, mcooler1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-130, -299, 15);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-130, -250, 15);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-180, -250, 15);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-180, -250, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-180, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-180, -299, 0);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-130, -299, 15);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(-130, -250, 15);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-130, -250, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-130, -299, 0);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-130, -250, 15);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-180, -250, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-180, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-130, -250, 0);//v 7
	glEnd();
	//2
	//Front
	glBindTexture(GL_TEXTURE_2D, mcooler2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-110, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-60, -299, 15);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-60, -250, 15);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-110, -250, 15);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-110, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-110, -250, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-110, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-110, -299, 0);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-60, -299, 15);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(-60, -250, 15);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-60, -250, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-60, -299, 0);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-60, -250, 15);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-110, -250, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-110, -250, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-60, -250, 0);//v 7
	glEnd();
	//3
	//Front
	glBindTexture(GL_TEXTURE_2D, mcooler3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-20, -299, 15);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-20, -260, 15);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-40, -260, 15);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -299, 15);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-40, -260, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-40, -260, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-40, -299, 0);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, mcoolercover);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-20, -299, 15);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(-20, -260, 15);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(-20, -260, 0);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(-20, -299, 0);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-20, -260, 15);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-40, -260, 15);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-40, -260, 0);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-20, -260, 0);//v 7
	glEnd();
	glPopMatrix();
	//foodproducts
	//1
	glPushMatrix();
	glTranslated(-40, 0, 0);
	//Front
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -299, 200);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-80, -299, 200);//v 2
	glTexCoord2d(1, 2);
	glVertex3f(-80, -240, 200);//v 3
	glTexCoord2d(0, 2);
	glVertex3f(-100, -240, 200);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -299, 50);//v 5
	glTexCoord2d(1, 0);
	glVertex3f(-80, -299, 50);//v 6
	glTexCoord2d(1, 2);
	glVertex3f(-80, -240, 50);//v 7
	glTexCoord2d(0, 2);
	glVertex3f(-100, -240, 50);//v 8
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, fp1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -299, 200);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-100, -240, 200);//v 4
	glTexCoord2d(2, 1);
	glVertex3f(-100, -240, 50);//v 8
	glTexCoord2d(2, 0);
	glVertex3f(-100, -299, 50);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, fp2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-80, -299, 200);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(-80, -240, 200);//v 3
	glTexCoord2d(2, 1);
	glVertex3f(-80, -240, 50);//v 7
	glTexCoord2d(2, 0);
	glVertex3f(-80, -299, 50);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, white);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-80, -240, 200);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-100, -240, 200);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-100, -240, 50);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-80, -240, 50);//v 7
	glEnd();
	//2
   //Front
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -299, 200);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(-20, -299, 200);//v 2
	glTexCoord2d(1, 2);
	glVertex3f(-20, -240, 200);//v 3
	glTexCoord2d(0, 2);
	glVertex3f(-40, -240, 200);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-40, -299, 50);//v 5
	glTexCoord2d(1, 0);
	glVertex3f(-20, -299, 50);//v 6
	glTexCoord2d(1, 2);
	glVertex3f(-20, -240, 50);//v 7
	glTexCoord2d(0, 2);
	glVertex3f(-40, -240, 50);//v 8
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, fp3);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-40, -299, 200);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(-40, -240, 200);//v 4
	glTexCoord2d(0, 1);
	glVertex3f(-40, -240, 50);//v 8
	glTexCoord2d(0, 0);
	glVertex3f(-40, -299, 50);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, fp4);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-20, -299, 200);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-20, -240, 200);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-20, -240, 50);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(-20, -299, 50);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, white);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-20, -240, 200);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-40, -240, 200);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-40, -240, 50);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(-20, -240, 50);//v 7
	glEnd();
	//3
	//Front
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(20, -299, 200);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(40, -299, 200);//v 2
	glTexCoord2d(1, 2);
	glVertex3f(40, -240, 200);//v 3
	glTexCoord2d(0, 2);
	glVertex3f(20, -240, 200);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, pic2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(20, -299, 50);//v 5
	glTexCoord2d(1, 0);
	glVertex3f(40, -299, 50);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(40, -240, 50);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(20, -240, 50);//v 8
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, fp5);
	glBegin(GL_QUADS);
	glTexCoord2d(2, 0);
	glVertex3f(20, -299, 200);//v 1
	glTexCoord2d(2, 1);
	glVertex3f(20, -240, 200);//v 4
	glTexCoord2d(0, 1);
	glVertex3f(20, -240, 50);//v 8
	glTexCoord2d(0, 0);
	glVertex3f(20, -299, 50);//v 5
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, fp6);
	glBegin(GL_QUADS);
	glTexCoord2d(2, 0);
	glVertex3f(40, -299, 200);//v 2
	glTexCoord2d(2, 1);
	glVertex3f(40, -240, 200);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(40, -240, 50);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(40, -299, 50);//v 6
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, white);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(40, -240, 200);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(20, -240, 200);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(20, -240, 50);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(40, -240, 50);//v 7
	glEnd();
	glPopMatrix();
	//cashier
	glPushMatrix();
	glTranslated(400, 0, 0);
	glRotated(-90, 0, 1, 0);
	//Front
	glBindTexture(GL_TEXTURE_2D, cashier);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(199.9, -299.8, 250);//v 1
	glTexCoord2d(0, 0);
	glVertex3f(120, -299.8, 250);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(120, -260, 250);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(199.9, -260, 250);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(120, -299.8, 250);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(120, -260, 250);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(120, -260, 210);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(120, -299.8, 210);//v 7
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(199.9, -299.8, 250);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(199.9, -260, 250);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(199.9, -260, 210);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(199.9, -299.8, 210);//v 8
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(120, -260, 250);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(199.9, -260, 250);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(199.9, -260, 235);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(120, -260, 235);//v 7
	glEnd();
	glPopMatrix();
	//pic
	glPushMatrix();
	glTranslated(400, 0, -80);
	glRotated(-90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, pic);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(130, -260, 200);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(200, -260, 200);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(200, -230, 200);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(130, -230, 200);//v 8
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(400, 0, 60);
	glRotated(-90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, pic1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(150, -260, 200);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(200, -260, 200);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(200, -235, 200);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(150, -235, 200);//v 8
	glEnd();
	glPopMatrix();
}
void cinema()
{
	//cinema
	//front
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -160, 170);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(-198, -50, 170);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(25, -50, 170);//v 3
	glTexCoord2d(0, 0);
	glVertex3f(25, -160, 170);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -160, 0);//v 5
	glTexCoord2d(0, 1);
	glVertex3f(-198, -50, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(25, -50, 0);//v 7
	glTexCoord2d(1, 0);
	glVertex3f(25, -160, 0);//v 8
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -160, 170);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-198, -50, 170);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-198, -50, 0);//v 6
	glTexCoord2d(1, 0);
	glVertex3f(-198, -160, 0);//v 5
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(25, -160, 130);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(25, -50, 130);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(25, -50, 0);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -160, 0);//v 8
	glEnd();
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(25, -100, 170);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(25, -50, 170);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(25, -50, 130);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -100, 130);//v 8
	glEnd();
	//down
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(5, 0);
	glVertex3f(-198, -160, 170);//v 1
	glTexCoord2d(5, 5);
	glVertex3f(-198, -160, 0);//v 2
	glTexCoord2d(0, 5);
	glVertex3f(25, -160, 0);//v 6
	glTexCoord2d(0, 0);
	glVertex3f(25, -160, 170);//v 5
	glEnd();
	//classes
	//1
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -120, 0);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -120, 25);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -120, 25);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -120, 0);//v 8
	glEnd();
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -120, 25);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -130, 25);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -130, 25);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -120, 25);//v 8
	glEnd();
	//2
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -130, 25);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -130, 50);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -130, 50);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -130, 25);//v 8
	glEnd();
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -130, 50);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -140, 50);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -140, 50);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -130, 50);//v 8
	glEnd();
	//3
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -140, 50);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -140, 75);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -140, 75);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -140, 50);//v 8
	glEnd();
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -140, 75);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -150, 75);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -150, 75);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -140, 75);//v 8
	glEnd();
	//4
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -150, 75);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -150, 100);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -150, 100);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -150, 75);//v 8
	glEnd();
	glBindTexture(GL_TEXTURE_2D, seet);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -150, 100);//v 6
	glTexCoord2d(1, 1);
	glVertex3f(-198, -160, 100);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(25, -160, 100);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -150, 100);//v 8
	glEnd();
	//screen
	glBindTexture(GL_TEXTURE_2D, screen);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-137, -130, 160);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(-137, -100, 160);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(-47, -100, 160);//v 3
	glTexCoord2d(0, 0);
	glVertex3f(-47, -130, 160);//v 4
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-137, -130, 160);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(-137, -100, 160);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(-137, -100, 170);//v 6
	glTexCoord2d(0, 0);
	glVertex3f(-137, -130, 170);//v 5
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-47, -130, 160);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(-47, -100, 160);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-47, -100, 170);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(-47, -130, 170);//v 8
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-137, -100, 160);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-47, -100, 160);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(-47, -100, 170);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(-137, -100, 170);//v 6
	glEnd();
	//door
	glPushMatrix();
	glTranslated(-114, 0, 67);
	glRotated(45, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(25, -100, 170);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(25, -160, 170);//v 3
	glTexCoord2d(0, 1);
	glVertex3f(25, -160, 130);//v 7
	glTexCoord2d(0, 0);
	glVertex3f(25, -100, 130);//v 6
	glEnd();
	glPopMatrix();
	//ticket seller
	//Front
	glBindTexture(GL_TEXTURE_2D, tsellertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(50, -160, 250);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(50, -130, 250);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(100, -130, 250);//v 3
	glTexCoord2d(0, 0);
	glVertex3f(100, -160, 250);//v 4
	glEnd();
	//Left
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(50, -160, 250);//v 2
	glTexCoord2d(1, 0);
	glVertex3f(50, -130, 250);//v 3
	glTexCoord2d(1, 1);
	glVertex3f(50, -130, 280);//v 6
	glTexCoord2d(0, 1);
	glVertex3f(50, -160, 280);//v 7
	glEnd();
	//Right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(100, -160, 250);//v 1
	glTexCoord2d(1, 0);
	glVertex3f(100, -130, 250);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(100, -130, 280);//v 7
	glTexCoord2d(0, 1);
	glVertex3f(100, -160, 280);//v 8
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(50, -130, 250);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(100, -130, 250);//v 4
	glTexCoord2d(1, 1);
	glVertex3f(100, -130, 260);//v 8
	glTexCoord2d(0, 1);
	glVertex3f(50, -130, 260);//v 7
	glEnd();
}
void poster()
{
	//1
	glPushMatrix();
	glTranslated(150, -130, 130);
	glRotated(45, 0, 1, 0);
	auxSolidCylinder(1, 30);
	glBindTexture(GL_TEXTURE_2D, ad1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(15, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-15, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-15, 30, 0);
	glTexCoord2d(0, 1);
	glVertex3d(15, 30, 0);
	glEnd();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(150, -130, 170);
	glRotated(45, 0, 1, 0);
	auxSolidCylinder(1, 30);
	glBindTexture(GL_TEXTURE_2D, ad2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(15, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-15, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-15, 30, 0);
	glTexCoord2d(0, 1);
	glVertex3d(15, 30, 0);
	glEnd();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslated(150, -130, 210);
	glRotated(45, 0, 1, 0);
	auxSolidCylinder(1, 30);
	glBindTexture(GL_TEXTURE_2D, ad3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(15, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-15, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-15, 30, 0);
	glTexCoord2d(0, 1);
	glVertex3d(15, 30, 0);
	glEnd();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslated(150, -130, 250);
	glRotated(45, 0, 1, 0);
	auxSolidCylinder(1, 30);
	glBindTexture(GL_TEXTURE_2D, ad4);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(15, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-15, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-15, 30, 0);
	glTexCoord2d(0, 1);
	glVertex3d(15, 30, 0);
	glEnd();
	glPopMatrix();

}
void cafeteria()
{
	//left
	glBindTexture(GL_TEXTURE_2D, coffee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -160, 300);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-198, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-198, -50, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-198, -160, 175);//v 4
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, coffee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(25, -160, 300);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(25, -50, 300);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(25, -50, 225);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(25, -160, 225);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, coffee);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-198, -160, 175);//v 1
	glTexCoord2d(1, 1);
	glVertex3f(-198, -50, 175);//v 2
	glTexCoord2d(0, 1);
	glVertex3f(25, -50, 175);//v 3
	glTexCoord2d(0, 0);
	glVertex3f(25, -160, 175);//v 4
	glEnd();
	//reception
	//front
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -160, 220);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-198, -125, 220);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -125, 220);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -160, 220);//v 4
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -160, 205);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-198, -125, 205);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -125, 205);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -160, 205);//v 4
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-198, -125, 220);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-198, -125, 205);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -125, 205);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -125, 220);//v 4
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-50, -160, 220);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-50, -125, 220);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -125, 205);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -160, 205);//v 4
	glEnd();
	//shelf
	//
	glBindTexture(GL_TEXTURE_2D, cooler1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -160, 180);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-180, -100, 180);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-140, -100, 180);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-140, -160, 180);//v 4
	glEnd();
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -160, 175);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-180, -100, 175);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-140, -100, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-140, -160, 175);//v 4
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -100, 180);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-180, -100, 175);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-140, -100, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-140, -100, 180);//v 4
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-140, -160, 180);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-140, -100, 180);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-140, -100, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-140, -160, 175);//v 4
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, cashiertabel);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-180, -160, 180);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-180, -100, 180);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-180, -100, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-180, -160, 175);//v 4
	glEnd();
	///////////////////////////////////////
	glBindTexture(GL_TEXTURE_2D, stand1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -120, 178);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-100, -90, 178);//v 2
	glTexCoord2d(2, 1);
	glVertex3f(-50, -90, 178);//v 3
	glTexCoord2d(2, 0);
	glVertex3f(-50, -120, 178);//v 4
	glEnd();
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -120, 175);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-100, -90, 175);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -90, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -120, 175);//v 4
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -90, 178);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-100, -90, 175);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -90, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -90, 178);//v 4
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-50, -120, 178);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-50, -90, 178);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-50, -90, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-50, -120, 175);//v 4
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, floor1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-100, -120, 178);//v 1
	glTexCoord2d(0, 1);
	glVertex3f(-100, -90, 178);//v 2
	glTexCoord2d(1, 1);
	glVertex3f(-100, -90, 175);//v 3
	glTexCoord2d(1, 0);
	glVertex3f(-100, -120, 175);//v 4
	glEnd();

}
void CenterMouse(HWND hwnd)
{
	RECT windowRect;
	GetClientRect(hwnd, &windowRect);
	POINT centerPos = { (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
	ClientToScreen(hwnd, &centerPos);

	SetCursorPos(centerPos.x, centerPos.y);
}

void KeepMouseCentered(HWND hwnd) {

	RECT windowRect;
	GetClientRect(hwnd, &windowRect);
	POINT centerPos = { (windowRect.right - windowRect.left) / 2, (windowRect.bottom - windowRect.top) / 2 };
	ClientToScreen(hwnd, &centerPos);

	SetCursorPos(centerPos.x, centerPos.y);

}

void camera() {
	mycamera.Render();
	if (keys['S'])
		mycamera.MoveForward(-5);
	if (keys['W'])
		mycamera.MoveForward(5);
	if (keys['A'])
		mycamera.MoveRight(5);
	if (keys['D'])
		mycamera.MoveRight(-5);
	if (keys['Q']) {
		mycamera.MoveUpward(5);
	}
	if (keys['E']) {

		mycamera.MoveUpward(-5);
	}
	if (keys['C']) {

		mycamera.SetRotateX(0);
	}
	if (keys[VK_DOWN]) {
		mycamera.RotateX(2);
	}
	if (keys[VK_UP]) {
		mycamera.RotateX(-2);
	}
	if (keys[VK_RIGHT]) {
		mycamera.RotateY(-2);
	}
	if (keys[VK_LEFT]) {
		mycamera.RotateY(2);
	}
	if (keys['M']) {
		mycamera.RotateZ(2);
	}
	if (keys['N']) {
		mycamera.RotateZ(-2);
	}
}
int choice = 0;
void skybox()
{
	glScaled(8, 3, 8);

	//DRAW SKY
	glPushMatrix();
	//sky
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25 * 3, 0, -25 * 3);
	glTexCoord2d(1, 0);
	glVertex3d(25 * 3, 0, -25 * 3);
	glTexCoord2d(1, 1);
	glVertex3d(25 * 3, 0, 25 * 3);
	glTexCoord2d(0, 1);
	glVertex3d(-25 * 3, 0, 25 * 3);
	glEnd();
	glPopMatrix();
	//up
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25 * 3, -100, 25 * 3);
	glTexCoord2d(1, 0);
	glVertex3d(25 * 3, -100, 25 * 3);
	glTexCoord2d(1, 1);
	glVertex3d(25 * 3, 0, 25 * 3);
	glTexCoord2d(0, 1);
	glVertex3d(-25 * 3, 0, 25 * 3);
	glEnd();
	glPopMatrix();
	//left
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25 * 3, -100, -25 * 3);
	glTexCoord2d(1, 0);
	glVertex3d(-25 * 3, -100, 25 * 3);
	glTexCoord2d(1, 1);
	glVertex3d(-25 * 3, 0, 25 * 3);
	glTexCoord2d(0, 1);
	glVertex3d(-25 * 3, 0, -25 * 3);
	glEnd();
	glPopMatrix();
	//right
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25 * 3, -100, -25 * 3);
	glTexCoord2d(1, 0);
	glVertex3d(25 * 3, -100, 25 * 3);
	glTexCoord2d(1, 1);
	glVertex3d(25 * 3, 0, 25 * 3);
	glTexCoord2d(0, 1);
	glVertex3d(25 * 3, 0, -25 * 3);
	glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25 * 3, -100, -25 * 3);
	glTexCoord2d(1, 0);
	glVertex3d(25 * 3, -100, -25 * 3);
	glTexCoord2d(1, 1);
	glVertex3d(25 * 3, 0, -25 * 3);
	glTexCoord2d(0, 1);
	glVertex3d(-25 * 3, 0, -25 * 3);
	glEnd();
	glPopMatrix();
}
int integer = 0;

void drawBox(int boxnum, int y) {
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 2.5, -99.5 + y, -13);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13 - 4);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 2.5, -99.5 + y, -13 - 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13 - 4);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13 - 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -99.5 + y, -13 - 4);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13 - 4);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13 - 4);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13 - 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -99.5 + y, -13);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -99.5 + y, -13 - 4);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 4.5, -99.5 + y, -13);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 4.5, -89.5 + y, -13 - 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13 - 4);
	glTexCoord2d(0, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -99.5 + y, -13);
	glTexCoord2d(1, 1);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13);
	glTexCoord2d(1, 0);
	glVertex3f(boxnum * 2.5 - 0.5, -89.5 + y, -13 - 4);
	glEnd();
	glPopMatrix();
}
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);






	glLoadIdentity();

	glTranslated(260, 250, -200);

	camera();
	if (integer == 0) {
		mycamera.SetRotateX(0);
		mycamera.RotateY(90);
		integer++;
	}
	//mouse ( mouseX, mouseY, isClicked, isRClicked);

	glTranslatef(k, 0.0, 0.0);
	glPushMatrix();
	skybox();
	glPopMatrix();
	glPushMatrix();







	glScaled(8, 3, 8);
	///


	//DRAW CARS
	glPushMatrix();
	int carnum = -50, carnum1 = -60, carnum2 = 3, carnum3 = 3;
	int j = 0;
	while (j < ints[2]) {
		glPushMatrix();
		if (j < 3) {
			glScaled(1, 2.5, 1);
			glTranslated(0, 60, 0);
			car->pos.x = -16;
			car->pos.y = -98.5;
			car->pos.z = carnum;
			car->scale = 0.06;
			car->Draw();
			carnum = carnum + 50;
		}



		else if ((j >= 3) && (j < 7)) {
			glScaled(1, 2.5, 1);
			glTranslatef(-23.5, 60, 130);
			glRotated(180, 0, 1, 0);
			car->pos.x = -16;
			car->pos.y = -98.5;
			car->pos.z = carnum;
			car->scale = 0.06;
			car->Draw();
			carnum = carnum + 50;
		}
		glPopMatrix();

		j++;

	}


	///
	//DRAW BOXES

	int boxnum = -18, boxnum1 = -18, boxnum2 = -18, boxnum3 = -18;
	int m = 0;

	while (m < ints[3]) {
		glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, box);
		if (m < 3) {
			drawBox(boxnum, 0);
			boxnum = boxnum + 3;
		}



		if ((m >= 3) && (m < 6)) {
			drawBox(boxnum1, 10);
			boxnum1 += 3;
		}
		if ((m >= 6) && (m < 9)) {
			drawBox(boxnum2, 20);
			boxnum2 += 3;
		}

		glPopMatrix();

		m++;

	}

	//DRAW TREES
	///
	int treenum = 3, treenum1 = 3, treenum2 = 3, treenum3 = 3;
	int i = 0;
	while (i < ints[1]) {
		glPushMatrix();

		if (i < 3) {
			tree1.pos.x = treenum;
			tree1.pos.y = -100;
			tree1.pos.z = -50;
			tree1.Draw();
			treenum = treenum + 15;
		}



		if ((i >= 3) && (i < 8)) {
			if (i == 7)
				tree1.pos.x = treenum1 + 7.5;
			else
				tree1.pos.x = treenum1;

			tree1.pos.y = -100;
			tree1.pos.z = -25;
			tree1.Draw();
			treenum1 += 15;
		}
		if ((i >= 8) && (i < 13)) {
			if (i == 12)
				tree1.pos.x = treenum2 + 7.5;
			else
				tree1.pos.x = treenum2;

			tree1.pos.y = -100;
			tree1.pos.z = 12;
			tree1.Draw();
			treenum2 += 15;
		}
		if ((i >= 13) && (i <= 17)) {
			if (i == 17)
				tree1.pos.x = treenum3 + 7.5;
			else
				tree1.pos.x = treenum3;

			tree1.pos.y = -100;
			tree1.pos.z = 32;
			tree1.Draw();
			treenum3 += 15;
		}
		glPopMatrix();

		i++;

	}
	glPopMatrix();

	//DRAW CHAIR 

	glScaled(1, 2, 1);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(25, -48, 4 * 3);
	glRotated(-90, 1, 0, 0);
	glRotated(90, 0, 0, 1);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(10 * 1, -48, 4 * 3);
	glRotated(-90, 1, 0, 0);
	glRotated(90, 0, 0, 1);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(40, -48, 4 * 3);
	glRotated(-90, 1, 0, 0);
	glRotated(90, 0, 0, 1);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(10 * 4, -48, -27);
	glRotated(-90, 1, 0, 0);
	glRotated(270, 0, 0, 1);
	//glRotated(180, 0, 1, 0);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(10 * 1, -48, -27);
	glRotated(-90, 1, 0, 0);
	glRotated(270, 0, 0, 1);
	//glRotated(180, 0, 1, 0);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(25, -48, -27);
	glRotated(-90, 1, 0, 0);
	glRotated(270, 0, 0, 1);
	//glRotated(180, 0, 1, 0);
	chairs23.scale = 0.005;
	chairs23.Draw();
	glPopMatrix();

	glScalef(1, 0.5, 1);



	glPushMatrix();
	if (myArray[0] == "rocky")
		glBindTexture(GL_TEXTURE_2D, rock);
	else  if (myArray[0] == "grassy")
		glBindTexture(GL_TEXTURE_2D, grass);

	else  if (myArray[0] == "sandy")
		glBindTexture(GL_TEXTURE_2D, sand);
	else {
		glBindTexture(GL_TEXTURE_2D, grass);
	}
	if (keys['I'])
		glBindTexture(GL_TEXTURE_2D, grass);
	if (keys['O'])
		glBindTexture(GL_TEXTURE_2D, rock);
	if (keys['P'])
		glBindTexture(GL_TEXTURE_2D, sand);
	//GROUND

	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3d(-16 * 3 - 2, -100, -25 * 3);
	glTexCoord2d(5 * 3, 0);
	glVertex3d(25 * 3, -100, -25 * 3);
	glTexCoord2d(5 * 3, 5 * 3);
	glVertex3d(25 * 3, -100, 25 * 3);
	glTexCoord2d(0, 5 * 3);
	glVertex3d(-16 * 3 - 2, -100, 25 * 3);
	glEnd();

	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3f(-21 * 3 + 0.5, -100, -25 * 3);
	glTexCoord2d(2 * 3, 0);
	glVertex3f(-25 * 3, -100, -25 * 3);
	glTexCoord2d(2 * 3, 2 * 3);
	glVertex3f(-25 * 3, -100, 25 * 3);
	glTexCoord2d(0, 2 * 3);
	glVertex3f(-21 * 3 + 0.5, -100, 25 * 3);

	glEnd();

	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3f(-16 * 3 - 2, -100, -25 * 3);
	glTexCoord2d(3, 0);
	glVertex3f(-21 * 3 + 0.5, -100, -25 * 3);
	glTexCoord2d(3, 3);
	glVertex3f(-21 * 3 + 0.5, -100, -9 * 3 + 2);
	glTexCoord2d(0, 3);
	glVertex3f(-16 * 3 - 2, -100, -9 * 3 + 2);

	glEnd();

	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3f(-16 * 3 - 2, -100, 25 * 3);
	glTexCoord2d(2 * 3, 0);
	glVertex3f(-21 * 3 + 0.5, -100, 25 * 3);
	glTexCoord2d(2 * 3, 2 * 3);
	glVertex3f(-21 * 3 + 0.5, -100, -5 * 3 + 2.5);
	glTexCoord2d(0, 2 * 3);
	glVertex3f(-16 * 3 - 2, -100, -5 * 3 + 2.5);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, parking);
	glBegin(GL_TRIANGLES);

	glTexCoord2d(0, 0);
	glVertex3f(-21 * 3 + 0.5, -100, -4 * 3 - 0.5);
	glTexCoord2d(2 * 3, 0);
	glVertex3f(-21 * 3 + 0.5, -120, -4 * 3 - 0.5);
	glTexCoord2d(0, 2 * 3);
	glVertex3f(-21 * 3 + 0.5, -100, -8 * 3 - 1);

	glEnd();

	glBegin(GL_TRIANGLES);

	glTexCoord2d(0, 0);
	glVertex3f(-17 * 3 + 1, -100, -4 * 3 - 0.5);
	glTexCoord2d(2 * 3, 0);
	glVertex3f(-17 * 3 + 1, -120, -4 * 3 - 0.5);
	glTexCoord2d(0, 2 * 3);
	glVertex3f(-17 * 3 + 1, -100, -8 * 3 - 1);

	glEnd();

	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, street); //main street
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);  glVertex3d(-1 * 3, 1 * -99.9, -25 * 3);
	glTexCoord3d(1, 0, 0);  glVertex3d(-7 * 3, 1 * -99.9, -25 * 3);
	glTexCoord3d(1, 0, 0); 	glVertex3d(-7 * 3, 1 * -99.9, 25 * 3);
	glTexCoord3d(0, 0, 0); 	glVertex3d(-1 * 3, 1 * -99.9, 25 * 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, street); //street 1
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);  glVertex3d(-1 * 3, 1 * -99.9, -15 * 3);
	glTexCoord3d(0, 0, 1);  glVertex3d(25 * 3, 1 * -99.9, -15 * 3);
	glTexCoord3d(1, 0, 1); 	glVertex3d(25 * 3, 1 * -99.9, -10 * 3);
	glTexCoord3d(1, 0, 0); 	glVertex3d(-1 * 3, 1 * -99.9, -10 * 3);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, street); // street 2
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);  glVertex3d(-1 * 3, 1 * -99.9, 5 * 3);
	glTexCoord3d(0, 0, 1);  glVertex3d(25 * 3, 1 * -99.9, 5 * 3);
	glTexCoord3d(1, 0, 1); 	glVertex3d(25 * 3, 1 * -99.9, 10 * 3);
	glTexCoord3d(1, 0, 0); 	glVertex3d(-1 * 3, 1 * -99.9, 10 * 3);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	//
	//DRAW VIRTUAL BUILD
	///
	int build = 0;
	while (build < ints[4]) {
		if (build < 1) {
			glPushMatrix();
			glTranslated(120, 0, 250);
			MyCube();
			glPopMatrix();
		}

		if ((build >= 1) && (build < 2)) {
			glPushMatrix();
			glTranslated(120, 0, 700);
			MyCube();
			glPopMatrix();
		}
		if ((build >= 2) && (build < 3)) {
			glPushMatrix();
			glTranslated(120, 0, -130);
			MyCube();
			glPopMatrix();
		}
		if ((build >= 3) && (build < 4)) {
			glPushMatrix();
			glTranslated(-620, 0, 800);
			MyCube();
			glPopMatrix();
		}
		build++;
	}
	glPushMatrix();
	glTranslated(-500, 0, 100);
	glRotated(90, 0, 1, 0);
	mall();
	model();
	storeFront();
	flag();
	externaldoor();
	door();
	Parking_un();
	Elevator();
	ElevatorRdoor();
	ElevatorLdoor();
	Elevatordown();
	supermarket();
	poster();
	cinema();
	cafeteria();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-500, 0, 100);
	glRotated(90, 0, 1, 0);
	SecondStage(90, 180, 280);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-750, 0, 100);
	glRotated(90, 0, 1, 0);
	SecondStage(-90, 0, 260);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-750, 0, 250);
	glRotated(90, 0, 1, 0);
	SecondStage(-90, 0, 260);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-500, 0, 250);
	glRotated(90, 0, 1, 0);
	SecondStage(90, 180, 280);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-550, 0, 350);
	glRotated(90, 0, 1, 0);
	SecondStag2();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-650, 0, 350);
	glRotated(90, 0, 1, 0);
	SecondStag2();
	glPopMatrix();
	if (keys['1'])
	{
		glLightfv(GL_LIGHT1, GL_POSITION, LightPos1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec2);
	}
	if (keys['2'])
	{
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec1);
	}
	if (keys['3'])
	{
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
		glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	}
	//glFlush();											// Done Drawing The Quad	
	//SwapBuffers(hDC);
	return TRUE;
}
GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static bool isCursorRecentered = false;  // Flag to skip re-centered WM_MOUSEMOVE
	static bool isFirstMouse = true;  // Flag for first mouse movement
	float mouseSensitivity = 0.1f;  // Adjust as needed

	static POINT lastMousePos = { 0, 0 }; // Store the previous mouse position
	POINT currentMousePos;               // Store the current mouse position
	switch (uMsg)  // Check for Windows Messages
	{
	case WM_MOUSEMOVE:
	{
		// Get the current mouse position
		GetCursorPos(&currentMousePos);

		// Calculate the mouse movement (delta)
		int deltaX = currentMousePos.x - lastMousePos.x;
		int deltaY = currentMousePos.y - lastMousePos.y;

		// Update the last mouse position
		lastMousePos = currentMousePos;

		// Rotate the camera based on mouse movement
		mycamera.RotateY(-deltaX * 0.1f); // Adjust the sensitivity multiplier
		mycamera.RotateX(deltaY * 0.1f);

		// Lock cursor back to the center of the window
		RECT rect;
		GetClientRect(hWnd, &rect);
		POINT center = { (rect.right - rect.left) / 2, (rect.bottom - rect.top) / 2 };
		//ClientToScreen(hWnd, &center);
		//SetCursorPos(center.x, center.y);
	}
	break;

	case WM_LBUTTONUP:
		isClicked = false;
		break;

	case WM_RBUTTONUP:
		isRClicked = false;
		break;

	case WM_LBUTTONDOWN:
		isClicked = true;
		break;

	case WM_RBUTTONDOWN:
		isRClicked = true;
		break;

	case WM_ACTIVATE:  // Watch For Window Activate Message
	{
		if (!HIWORD(wParam))  // Check Minimization State
		{
			active = TRUE;  // Program Is Active
			ShowCursor(FALSE);  // Hide the cursor when active
		}
		else
		{
			active = FALSE;  // Program Is No Longer Active
			ShowCursor(TRUE);  // Show the cursor when inactive
		}

		return 0;  // Return to the message loop
	}

	case WM_SYSCOMMAND:  // Intercept System Commands
	{
		switch (wParam)  // Check system calls
		{
		case SC_SCREENSAVE:  // Screensaver trying to start?
		case SC_MONITORPOWER:  // Monitor trying to enter powersave?
			return 0;  // Prevent from happening
		}
		break;  // Exit
	}

	case WM_CLOSE:  // Did we receive a close message?
	{
		PostQuitMessage(0);  // Send a quit message
		return 0;  // Jump back
	}

	case WM_KEYDOWN:  // Is a key being held down?
	{
		keys[wParam] = TRUE;  // If so, mark it as TRUE
		return 0;  // Jump back
	}

	case WM_KEYUP:  // Has a key been released?
	{
		keys[wParam] = FALSE;  // If so, mark it as FALSE
		return 0;  // Jump back
	}

	case WM_SIZE:  // Resize the OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;  // Jump back
	}
	}

	// Pass all unhandled messages to DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	char t[] = "Mall Program";
	if (!CreateGLWindow(t, 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	while (!done)									// Loop That Runs While done=FALSE
	{
		//SetCursorPos(320, 240);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			//if (keys[VK_F1])						// Is F1 Being Pressed?
			//{
			//	keys[VK_F1] = FALSE;					// If So Make Key FALSE
			//	KillGLWindow();						// Kill Our Current Window
			//	fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
			//	// Recreate Our OpenGL Window
			//	if (!CreateGLWindow(t, 640, 480, 16, fullscreen))
			//	{
			//		return 0;						// Quit If Window Was Not Created
			//	}
			//}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);
}

bool startswith(const std::string& str, const std::string& cmp) {
	return str.compare(0, cmp.length(), cmp) == 0;
}
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	string input;
	int environment;
	int trees;
	int cars;
	int boxes;
	int buildings;

	for (int i = 0; i <= 4; i++) {
		if (i == 0) {
			while (true) {
				cout << "Choose the environment type (0:sandy, 1:rocky, 2:grassy)\n";
				cin >> input;
				try {
					environment = stoi(input);
				}
				catch (exception e) {
					cout << "\nEnter a number next time.\n\n";
					continue;
				}
				if (environment>=0 && environment<=2) {
					if(environment==0)
					myArray[0] = "sandy";
					else if (environment == 1)
						myArray[0] = "rocky";
					else if (environment == 2)
						myArray[0] = "grassy";
					break;
				}
				cout << "\nYou have to choose either 0, 1 or 2\n\n";
			}
		}
		else if (i == 1) {
			while (true) {
				cout << "\nChoose the number of trees you want (Max 18)\n";
				cin >> input;
				try {
					trees = stoi(input);
				}
				catch (exception e) {
					cout << "\nEnter a number next time.\n\n";
					continue;
				}
				if (trees >= 0 && trees < 19) {
					ints[1] = trees;
					break;
				}
				cout << "\nYou have to choose a number between 0 and 18.\n\n";
			}
		}
		else if (i == 2) {
			while (true) {
				cout << "\nChoose the number of cars you want (Max 6)\n";
				cin >> input;
				try {
					cars = stoi(input);
				}
				catch (exception e) {
					cout << "\nEnter a number next time.\n\n";
					continue;
				}
				if (cars >= 0 && cars < 7) {
					ints[2] = cars;
					break;
				}
				cout << "\nYou have to choose a number between 0 and 6.\n\n";
			}
		}
		else if (i == 3) {
			while (true) {
				cout << "\nChoose the number of boxes you want (Max 9)\n";
				cin >> input;
				try {
					boxes = stoi(input);
				}
				catch (exception e) {
					cout << "\nEnter a number next time.\n\n";
					continue;
				}
				if (boxes >= 0 && boxes < 10) {
					ints[3] = boxes;
					break;
				}
				cout << "\nYou have to choose a number between 0 and 9.\n\n";
			}
		}
		else if (i == 4) {
			while (true) {
				cout << "\nChoose the number of buildings you want (Max 4)\n";
				cin >> input;

				try {
					buildings = stoi(input);
				}
				catch (exception e) {
					cout << "\nEnter a number next time.\n\n";
					continue;
				}

				if (buildings >= 0 && buildings < 5) {
					ints[4] = buildings;
					break;
				}
				cout << "\nYou have to choose a number between 0 and 4.\n\n";
			}
			cout << std::endl;
		}
	}

	//for (int i = 1; i < 5; ++i) {
	//	//ints[i] = atoi(myArray[i].c_str());
	//	cout << "AHJSIFNIASNFF\t" +ints[i];
	//	cout << endl;
	//}
	
	cout << "Environment Type: " << myArray[0] << "\n";// choose of the  environment
	cout << "Number of Trees: " << ints[1] << "/18 " << "\n";
	cout << "Number of Cars: " << ints[2] << "/6 " << "\n";
	cout << "Number of Boxes: " << ints[3] << "/9 " << "\n";
	cout << "Number of Virtual Buildings: " << ints[4] << "/4" << "\n";


	return WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);;
}