// CODIGO-FONTE BASICO PARA ANIMACAO 2D
// VERSAO 2 - GLAUCIUS DECIO DUARTE - 02 out. 2018
// glaucius@pelotas.ifsul.edu.br

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <string.h>


using namespace std;

#define TAMJANELA 600
#define POSJANELA 50


int movex=0;
int movey=0;
int tx_om;
int ty_om=0;
int direcao=1;
int velocidade=5;
bool keyDown;
double tempo;
int score=0;

char texto[50];
char aux[50];

int inimigo;

unsigned char pixelColisao1[4];
unsigned char pixelColisao2[4];
unsigned char pixelColisao3[4];
unsigned char pixelColisao4[4];
unsigned char pixelColisao5[4];
unsigned char pixelColisao6[4];
unsigned char pixelColisao7[4];

bool mainMenuFlag =true;
bool endGameFlag = false;
//==========================================
int posicaoAleatoria(int menor, int maior) {

	int aleatorio=rand()%(maior-menor)+menor;
	return aleatorio;
	
}
//==========================================
#pragma region Funções de Texto
void escreveTexto(int posx, int posy, char ns[20]){
  glColor3f(.5,.5,.5);
  glRasterPos2i (posx, posy);
  char *p= (char*) ns;
  while (*p!= '\0')
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
void escreveTextoMenu(int posx, int posy, char ns[30]){
  glColor3f(.2,0,.2);
  glRasterPos2i (posx, posy);
  char *p= (char*) ns;
  while (*p!= '\0')
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
#pragma endregion

//================== Funções de Desenho

#pragma region Desenha Inimigos
void MoveObjetoMovel(int passo) {

	if(direcao == 1) {
			tx_om-=velocidade;
			if(tx_om <= -(TAMJANELA)-50) {
					tx_om=1000;
          inimigo = posicaoAleatoria(1,4);
				}
      
  }
		// } else
    //   if(direcao == 0) {
    //     tx_om+=velocidade;
    //     if(ty_om >= 0) {
    //       direcao=1;
    //       tx_om=posicaoAleatoria(menor,maior);
    //     }
    //   }
      
	glutPostRedisplay();
	glutTimerFunc(1,MoveObjetoMovel,1);

}
void DesenhaPiramide(void) {
  #pragma region Contorno
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(235+tx_om, 228+ty_om);
      glVertex2i(269+tx_om, 272+ty_om);
      glVertex2i(271+tx_om, 272+ty_om);
      glVertex2i(304+tx_om, 228+ty_om);
      glVertex2i(235+tx_om, 228+ty_om);
    glEnd();
    
  #pragma endregion
  #pragma region Corpo do Piramide
    glColor3f(.8 ,.8,0);
    glBegin(GL_POLYGON);
      glVertex2i(240+tx_om, 230+ty_om);
      glVertex2i(270+tx_om, 270+ty_om);
      glVertex2i(300+tx_om, 230+ty_om);
      glVertex2i(240+tx_om, 230+ty_om);
    glEnd();
    glColor3f(.6,.5,0);
    glBegin(GL_POLYGON);
      glVertex2i(240+tx_om, 230+ty_om);
      glVertex2i(270+tx_om, 270+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
      glVertex2i(240+tx_om, 230+ty_om);
    glEnd();
  #pragma endregion
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
      glVertex2i(270+tx_om, 272+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
    glEnd();
}
void DesenhaJacare(void) {
  glColor3f(0,0,1);

      glBegin(GL_POLYGON);
          glVertex2i(190+tx_om, 245+ty_om);
          glVertex2i(290+tx_om, 245+ty_om);
          glVertex2i(290+tx_om, 223+ty_om);
          glVertex2i(190+tx_om, 223+ty_om);
      glEnd();
  #pragma region Contorno
  glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(198+tx_om, 228+ty_om);
      glVertex2i(198+tx_om, 242+ty_om);
      glVertex2i(205+tx_om, 237+ty_om);
      glVertex2i(210+tx_om, 242+ty_om);
      glVertex2i(215+tx_om, 237+ty_om);
      glVertex2i(220+tx_om, 242+ty_om);
      glVertex2i(225+tx_om, 237+ty_om);
      glVertex2i(228+tx_om, 245+ty_om);
      glVertex2i(272+tx_om, 230+ty_om);
      glVertex2i(272+tx_om, 228+ty_om);
    glEnd();
    glBegin(GL_POLYGON);
      glVertex2i(228+tx_om, 245+ty_om);
      glVertex2i(225+tx_om, 240+ty_om);
      glVertex2i(220+tx_om, 245.5+ty_om);
      glVertex2i(215+tx_om, 240+ty_om);
      glVertex2i(210+tx_om, 250.5+ty_om);
      glVertex2i(205+tx_om, 245.5+ty_om);
      glVertex2i(198+tx_om, 257+ty_om);
      glVertex2i(240+tx_om, 247+ty_om);
      glVertex2i(242.5+tx_om, 257+ty_om);
      glVertex2i(247+tx_om, 254.5+ty_om);
      glVertex2i(244.5+tx_om, 252+ty_om);
      glVertex2i(272+tx_om, 230+ty_om);
    glEnd();
    #pragma endregion
  #pragma region Corpo
    glColor3f(.6,1,0);
    glBegin(GL_POLYGON);
      glVertex2i(200+tx_om, 230+ty_om);
      glVertex2i(200+tx_om, 240+ty_om);
      glVertex2i(205+tx_om, 235+ty_om);
      glVertex2i(210+tx_om, 240+ty_om);
      glVertex2i(215+tx_om, 235+ty_om);
      glVertex2i(220+tx_om, 240+ty_om);
      glVertex2i(225+tx_om, 235+ty_om);
      glVertex2i(230+tx_om, 245+ty_om);
      glVertex2i(270+tx_om, 230+ty_om);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
      glVertex2i(230+tx_om, 245+ty_om);
      glVertex2i(225+tx_om, 242+ty_om);
      glVertex2i(220+tx_om, 247.5+ty_om);
      glVertex2i(215+tx_om, 242+ty_om);
      glVertex2i(210+tx_om, 252.5+ty_om);
      glVertex2i(205+tx_om, 247.5+ty_om);
      glVertex2i(200+tx_om, 255+ty_om);
      glVertex2i(240+tx_om, 245+ty_om);
      glVertex2i(242.5+tx_om, 255+ty_om);
      glVertex2i(245+tx_om, 242.5+ty_om);
      glVertex2i(242.5+tx_om, 250+ty_om);
      glVertex2i(270+tx_om, 230+ty_om);
    glEnd();
      
  #pragma endregion  
}
void DesenhaDuasPiramideS(void) {
  #pragma region Contorno
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(235+tx_om, 228+ty_om);
      glVertex2i(269+tx_om, 272+ty_om);
      glVertex2i(271+tx_om, 272+ty_om);
      glVertex2i(304+tx_om, 228+ty_om);
      glVertex2i(235+tx_om, 228+ty_om);
    glEnd();
    
  #pragma endregion
  #pragma region Corpo do Piramide
    glColor3f(.8 ,.8,0);
    glBegin(GL_POLYGON);
      glVertex2i(240+tx_om, 230+ty_om);
      glVertex2i(270+tx_om, 270+ty_om);
      glVertex2i(300+tx_om, 230+ty_om);
      glVertex2i(240+tx_om, 230+ty_om);
    glEnd();
    glColor3f(.6,.5,0);
    glBegin(GL_POLYGON);
      glVertex2i(240+tx_om, 230+ty_om);
      glVertex2i(270+tx_om, 270+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
      glVertex2i(240+tx_om, 230+ty_om);
    glEnd();
  #pragma endregion
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
      glVertex2i(270+tx_om, 272+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
    glEnd();

    //
    #pragma region Contorno
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(285+tx_om, 248+ty_om);
      glVertex2i(309+tx_om, 292+ty_om);
      glVertex2i(311+tx_om, 292+ty_om);
      glVertex2i(344+tx_om, 228+ty_om);
      glVertex2i(275+tx_om, 228+ty_om);
    glEnd();
    
  #pragma endregion
  #pragma region Corpo do Piramide
    glColor3f(.8 ,.8,0);
    glBegin(GL_POLYGON);
      glVertex2i(280+tx_om, 230+ty_om);
      glVertex2i(310+tx_om, 290+ty_om);
      glVertex2i(340+tx_om, 230+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
    glEnd();
    glColor3f(.6,.5,0);
    glBegin(GL_POLYGON);
      glVertex2i(280+tx_om, 230+ty_om);
      glVertex2i(310+tx_om, 290+ty_om);
      glVertex2i(320+tx_om, 230+ty_om);
      glVertex2i(280+tx_om, 230+ty_om);
    glEnd();
  #pragma endregion
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
      glVertex2i(310+tx_om, 292+ty_om);
      glVertex2i(320+tx_om, 230+ty_om);
    glEnd();
}
#pragma endregion

#pragma region Desenha Objetos 
void DesenhaObjetoControlado(void) {
  #pragma region Contorno
  //Contorno
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(248+movex, 248+movey);
    glVertex2i(228+movex, 278+movey);
    glVertex2i(228+movex, 282+movey);
    glVertex2i(278+movex, 282+movey);
    glVertex2i(278+movex, 302+movey);
    glVertex2i(302+movex, 302+movey);
    glVertex2i(302+movex, 248+movey);
    glVertex2i(248+movex, 248+movey);
  glEnd();

  //Bico
	glBegin(GL_POLYGON);
    glVertex2i(300+movex, 297+movey);
    glVertex2i(312+movex, 297+movey);
    glVertex2i(312+movex, 288+movey);
    glVertex2i(307+movex, 288+movey);
    glVertex2i(307+movex, 283+movey);
    glVertex2i(298+movex, 283+movey);
    glVertex2i(300+movex, 295+movey);
  glEnd();

  //Crista
	glBegin(GL_POLYGON);
    glVertex2i(283+movex, 302+movey);
    glVertex2i(283+movex, 307+movey);
    glVertex2i(288+movex, 307+movey);
    glVertex2i(288+movex, 312+movey);
    glVertex2i(297+movex, 312+movey);
    glVertex2i(302+movex, 312+movey);
    glVertex2i(302+movex, 307+movey);
    glVertex2i(302+movex, 302+movey);
  glEnd();

  
  #pragma endregion
  #pragma region Corpo
  //Corpo
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    glVertex2i(250+movex, 250+movey);
    glVertex2i(230+movex, 280+movey);
    glVertex2i(280+movex, 280+movey);
    glVertex2i(280+movex, 300+movey);
    glVertex2i(300+movex, 300+movey);
    glVertex2i(300+movex, 250+movey);
    glVertex2i(250+movex, 250+movey);
  glEnd();
  //Bico
  glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(300+movex, 295+movey);
    glVertex2i(310+movex, 295+movey);
    glVertex2i(310+movex, 290+movey);
    glVertex2i(305+movex, 290+movey);
    glVertex2i(305+movex, 285+movey);
    glVertex2i(300+movex, 285+movey);
    glVertex2i(300+movex, 295+movey);
  glEnd();
  //Crista
  glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(285+movex, 300+movey);
    glVertex2i(285+movex, 305+movey);
    glVertex2i(290+movex, 305+movey);
    glVertex2i(290+movex, 310+movey);
    glVertex2i(295+movex, 310+movey);
    glVertex2i(300+movex, 310+movey);
    glVertex2i(300+movex, 305+movey);
    glVertex2i(300+movex, 300+movey);
  glEnd();
  //Asa
  glColor3f(.7,.7,.7);
	glBegin(GL_POLYGON);
        glVertex2i(245+movex, 275+movey);
        glVertex2i(280+movex, 275+movey);
        glVertex2i(280+movex, 255+movey);
        glVertex2i(245+movex, 275+movey);
  glEnd();
  
  #pragma endregion
}
#pragma region Animação das Patas
void AnimaPata1(void){
    #pragma region Contorno
  //Pé E1
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(263+movex, 250+movey);
      glVertex2i(272+movex, 250+movey);
      glVertex2i(272+movex, 233+movey);
      glVertex2i(276+movex, 233+movey);
      glVertex2i(277+movex, 228+movey);
      glVertex2i(263+movex, 228+movey);
      glVertex2i(263+movex, 250+movey);
    glEnd();
    //Pé D1
    glBegin(GL_POLYGON);
      glVertex2i(283+movex, 250+movey);
      glVertex2i(292+movex, 250+movey);
      glVertex2i(292+movex, 243+movey);
      glVertex2i(296+movex, 243+movey);
      glVertex2i(296+movex, 238+movey);
      glVertex2i(283+movex, 238+movey);
      glVertex2i(283+movex, 250+movey);
      glEnd();
      
  #pragma endregion
    #pragma region Corpo
  //Pé E1
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
      glVertex2i(265+movex, 250+movey);
      glVertex2i(270+movex, 250+movey);
      glVertex2i(270+movex, 235+movey);
      glVertex2i(270+movex, 235+movey);
      glVertex2i(275+movex, 230+movey);
      glVertex2i(265+movex, 230+movey);
      glVertex2i(265+movex, 250+movey);
    glEnd();
    //Pé D1
    glBegin(GL_POLYGON);
      glVertex2i(285+movex, 250+movey);
      glVertex2i(290+movex, 250+movey);
      glVertex2i(290+movex, 245+movey);
      glVertex2i(290+movex, 245+movey);
      glVertex2i(295+movex, 240+movey);
      glVertex2i(285+movex, 240+movey);
      glVertex2i(285+movex, 250+movey);
    glEnd();
    #pragma endregion
}

void AnimaPata2(void){
  #pragma region Contorno
//Pé E1
  glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(263+movex, 250+movey);
    glVertex2i(272+movex, 250+movey);
    glVertex2i(272+movex, 243+movey);
    glVertex2i(276+movex, 243+movey);
    glVertex2i(277+movex, 238+movey);
    glVertex2i(263+movex, 238+movey);
    glVertex2i(263+movex, 250+movey);
  glEnd();
  //Pé D1
  glBegin(GL_POLYGON);
    glVertex2i(283+movex, 250+movey);
    glVertex2i(292+movex, 250+movey);
    glVertex2i(292+movex, 233+movey);
    glVertex2i(296+movex, 233+movey);
    glVertex2i(296+movex, 228+movey);
    glVertex2i(283+movex, 228+movey);
    glVertex2i(283+movex, 250+movey);
    glEnd();
    
#pragma endregion
  #pragma region Corpo
//Pé E1
  glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(265+movex, 250+movey);
    glVertex2i(270+movex, 250+movey);
    glVertex2i(270+movex, 245+movey);
    glVertex2i(270+movex, 245+movey);
    glVertex2i(275+movex, 240+movey);
    glVertex2i(265+movex, 240+movey);
    glVertex2i(265+movex, 250+movey);
  glEnd();
  //Pé D1
  glBegin(GL_POLYGON);
    glVertex2i(285+movex, 250+movey);
    glVertex2i(290+movex, 250+movey);
    glVertex2i(290+movex, 235+movey);
    glVertex2i(290+movex, 235+movey);
    glVertex2i(295+movex, 230+movey);
    glVertex2i(285+movex, 230+movey);
    glVertex2i(285+movex, 250+movey);
  glEnd();
  #pragma endregion
}
#pragma endregion
void DesenhaChao(void){
  glColor3f(1,1,0);
  glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(0,240);
    glVertex2i(TAMJANELA, 245);
    glVertex2i(TAMJANELA, 0);
    glVertex2i(0,0);
  glEnd();
}
#pragma endregion

#pragma region Desenha Telas
void DesenhaMenu(void) {
  
  glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    glVertex2i(122.5, 245);
    glVertex2i(279, 505);
    glVertex2i(281, 505);
    glVertex2i(441.5, 245);
  glEnd();
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
    glVertex2i(430, 250);
    glVertex2i(130, 250);
    glVertex2i(280, 500);
  glEnd();
  glColor3f(1,.4,0);
  glBegin(GL_POLYGON);
    glVertex2i(130, 250);
    glVertex2i(280, 500);
    glVertex2i(330, 250);
  glEnd();
  glColor3f(0,0,0);
  glLineWidth(3);
  glBegin(GL_LINE_STRIP);
    glVertex2i(280, 500);
    glVertex2i(330, 250);
  glEnd();
}
void DesenhaFimDaPartida(){
  glColor3f(1,1,1);
  
  glBegin(GL_POLYGON);  
    glVertex2i(245, 320);
    glVertex2i(230, 310);
    glVertex2i(210, 330);
    glVertex2i(230, 350);
    glVertex2i(250, 330);
    glVertex2i(290, 400);
    glVertex2i(310, 380);
  glEnd();
  glBegin(GL_POLYGON);
    glVertex2i(260, 280);
    glVertex2i(240, 300);
    glVertex2i(250, 330);
    glVertex2i(270, 310);
    glEnd();
  
  glColor3f(.8,.52,.24);
  glBegin(GL_POLYGON);
    glVertex2i(285, 400);
    glVertex2i(285, 445);
    glVertex2i(295, 520);
    glVertex2i(360, 540);
    glVertex2i(410, 490);
    glVertex2i(420, 430);
    glVertex2i(370, 390);
    glVertex2i(310, 380);
    glVertex2i(300, 370);
    glVertex2i(300, 385);
    glVertex2i(285, 380);
    glVertex2i(280, 380);
  glEnd();
}
#pragma endregion

//==================================

#pragma region Tratamento de Colisão
void PrintColliderPoints(){
  printf("Pixel %d: %d %d %d\n", 1, pixelColisao1[0], pixelColisao1[1], pixelColisao1[2]);
  printf("Pixel %d: %d %d %d\n", 2, pixelColisao2[0], pixelColisao2[1], pixelColisao2[2]);
  printf("Pixel %d: %d %d %d\n", 3, pixelColisao3[0], pixelColisao3[1], pixelColisao3[2]);
  printf("Pixel %d: %d %d %d\n", 4, pixelColisao4[0], pixelColisao4[1], pixelColisao4[2]);
  printf("Pixel %d: %d %d %d\n", 5, pixelColisao5[0], pixelColisao5[1], pixelColisao5[2]);
  printf("Pixel %d: %d %d %d\n", 6, pixelColisao6[0], pixelColisao6[1], pixelColisao6[2]);
  printf("Pixel %d: %d %d %d\n", 7, pixelColisao7[0], pixelColisao7[1], pixelColisao7[2]);
}
void CollideHit(){
  if((pixelColisao1[0] != 128 && pixelColisao1[0] != 255) || (pixelColisao1[1]!= 102 && pixelColisao1[1] != 255)||(pixelColisao1[2]!= 255 && pixelColisao1[2] != 0)){
    endGameFlag=true;
  }
  if((pixelColisao2[0] != 128 && pixelColisao2[0] != 255) || (pixelColisao2[1]!= 102 && pixelColisao2[1] != 255)||(pixelColisao2[2]!= 255 && pixelColisao2[2] != 0)){
      endGameFlag=true;(1);
  }
  if((pixelColisao3[0] != 128) && (pixelColisao3[1]!= 102&& pixelColisao3[2]!= 255)){
    endGameFlag=true;  }
  if((pixelColisao4[0] != 128) && (pixelColisao4[1]!= 102&& pixelColisao4[2]!= 255)){
    endGameFlag=true;  }
  if((pixelColisao5[0] != 128) && (pixelColisao5[1]!= 102&& pixelColisao5[2]!= 255)){
    endGameFlag=true;  }
  if((pixelColisao6[0] != 128) && (pixelColisao6[1]!= 102&& pixelColisao6[2]!= 255)){
    endGameFlag=true;  }
  if((pixelColisao7[0] != 128) && (pixelColisao7[1]!= 102&& pixelColisao7[2]!= 255)){
    endGameFlag=true;  }
}
//
void Collider(int animN){
  if(animN == 1){
    //pé esquerdo baixo
      glReadPixels(270, 227+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao1);
    //Pé Direito alto
      glReadPixels(290, 237+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao2);
  }
  if (animN == 2){
    //Pé direito alto
      glReadPixels(270, 237+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao1);
    //Pé Direito baixo
      glReadPixels(290, 227+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao2);
   }

  //Atrás baixo
    glReadPixels(248, 247+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao3);
  //Atrás, alto
    glReadPixels(233, 268+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao4);

  //frente baixo
    glReadPixels(302, 247+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao5);
  //frente meio
    glReadPixels(302, 260+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao6);
  //frente alto
    glReadPixels(302, 270+movey, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColisao7);

  if(score>3)
  CollideHit();
}
#pragma endregion

//=================

#pragma region Funções de I/O
void Mouse(int botao, int estado, int xmouse, int ymouse) {

  if (botao == GLUT_LEFT_BUTTON){
    if(mainMenuFlag)
        mainMenuFlag=false;
      else
        keyDown = (estado == GLUT_DOWN);
    
  }

  if (botao == GLUT_MIDDLE_BUTTON)
    if (estado == GLUT_DOWN)
      velocidade=0;

  glutPostRedisplay();
  
}
void Teclado2(unsigned char tecla, int xmouse, int ymouse) {

  switch (tecla) {
  
  	// Tecla [Esc]
  	case 27: exit(0);
             break;
    
    case 82:
    case 114:
      if(endGameFlag){
        score=0;
        endGameFlag=false;
        velocidade =5;
      }
      break;
  }
  glutPostRedisplay();
  
}                       
 #pragma endregion

//==============================================

void Inicializa(void) 
  {
    glClearColor(.5, .4, 1, 0);
    glColor3f(1,0,0);
    tx_om=1200;
    inimigo =  3;
  }



void Desenha(void){
  glClear(GL_COLOR_BUFFER_BIT);
  #pragma region EndGame
    if(endGameFlag){
      glPushMatrix();
      DesenhaFimDaPartida();
      strcpy(texto, "GameOver");
      escreveTextoMenu((TAMJANELA/5),(TAMJANELA/3),texto);
      strcpy(texto, "Pontuacao: ");
      sprintf(aux, "%d", score*10);
      strcat(texto,aux);
      escreveTextoMenu((TAMJANELA/5),(TAMJANELA/3)-50,texto);
      strcpy(texto, "Para Reiniciar, aperte R");
      escreveTextoMenu((TAMJANELA/5),(TAMJANELA/3)-100,texto);
    }
    else{
  #pragma endregion
  #pragma region Main Menu
    if(mainMenuFlag)
    {
      glPushMatrix();
     // DesenhaFimDaPartida();
      DesenhaMenu();

      strcpy(texto, "the");
      escreveTextoMenu((TAMJANELA/2.2),(TAMJANELA/2)+15,texto);
      strcpy(texto, "JUMPING ADVENTURES");
      escreveTextoMenu((TAMJANELA/3.5),(TAMJANELA/2),texto);
      strcpy(texto, "of");
      escreveTextoMenu((TAMJANELA/2.2),(TAMJANELA/2)-15,texto);
      strcpy(texto, "MAGICAL CHICKEN");
      escreveTextoMenu((TAMJANELA/2.8),(TAMJANELA/2)-30,texto);
      strcpy(texto, "Press Mouse Button to Start");
      escreveTextoMenu((TAMJANELA/3.5),(TAMJANELA/2)-75,texto);

        glPopMatrix();
      glutSwapBuffers();

    }
  #pragma endregion
    else{
        #pragma region Animação de pulo e queda
          if(keyDown == true){
            if(movey<150)
              movey+= 5;
            else
              keyDown = false;
          }
          else{
            if(movey>0)
              movey-= 6.5;
          }
          if(movey<0)
            movey=0;
        #pragma endregion
          //Score
          if (time(0)> tempo){
            tempo = time(0);
            score ++;
            if((score*10)%100 == 0 )
            {
              velocidade+=3;
              printf("Velocidade: %d\n",velocidade);
             }
          }
          //Imprime Score
          strcpy(texto, "Score: ");
          sprintf(aux, "%d", score*10);
          strcat(texto,aux);
          escreveTexto(10,TAMJANELA-20,texto);  //no topo esquerdo da janela
          //Aumenta Velocidade
          
          // glColor3f(1,0,0);
          // glPointSize(9);
          // glBegin(GL_POINTS);
          //   glVertex2i(270 , 260);
          // glEnd();

          DesenhaChao();
          DesenhaObjetoControlado();
          glPushMatrix();
          if(inimigo  == 1){
            DesenhaPiramide();
           // printf("Inimigo: Piramide\n");
          }
          if(inimigo == 2){
            DesenhaJacare();
          //  printf("Inimigo: Jacare\n");
          }
          if(inimigo == 3){
            DesenhaDuasPiramideS();
          //  printf("Inimigo: Duas Piramides\n");
          }
          #pragma region Animação das Patas
            if(score%2 == 0){
            AnimaPata1();
            Collider(1);
            }
            else{
              Collider(2);
              AnimaPata2();
            }
          #pragma endregion 
          glPopMatrix();
          }
    }

  glutSwapBuffers();
  
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) { 
  if(h == 0)
    h = 1;
  
  glViewport(0, 0, w, h);
     
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
     
  if (w <= h)
    gluOrtho2D(0, TAMJANELA, 0, TAMJANELA*h/w);
  else
    gluOrtho2D(0, TAMJANELA*w/h, 0, TAMJANELA);
} 

int main(int argc, char** argv) {
	srand((unsigned)time(0));
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(TAMJANELA, TAMJANELA);
  glutInitWindowPosition(10,10);
  glutCreateWindow("OpenGL - Jump Chiken");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutTimerFunc(1,MoveObjetoMovel,1);

  setbuf(stdin,NULL);
  tempo = time(0);
  glutKeyboardFunc(Teclado2);
  glutMouseFunc(Mouse);
  


  Inicializa();
  
  glutMainLoop();
  return 0;
}
