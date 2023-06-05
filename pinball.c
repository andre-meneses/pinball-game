#include <GL/glut.h>
#include <math.h>
int windowWidth = 760;
int windowHeight = 760;

//int leftBarX = windowWidth * 0.3;

int rightBarX = 660;

void drawBumper(float x, float y, float radius, float r, float g, float b) 
{
    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    int num_segments = 50;

    for (int i = 0; i <= num_segments; i++) {

        float angle = i * 2.0f * 3.14159f / num_segments;

        float dx = radius * cosf(angle);

        float dy = radius * sinf(angle);

        glVertex2f(x + dx, y + dy);

    }

    glEnd();
}

void display()
{
    // Limpa o buffer de cores

    glClear(GL_COLOR_BUFFER_BIT);



    // Define a matriz de projeção

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, windowWidth, 0, windowHeight);



    // Define a matriz de model-view

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();



    // Desenha a borda superior com a cor branca

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(16.0f);

    glBegin(GL_LINES);

    glVertex2f(0, windowHeight);

    glVertex2f(windowWidth, windowHeight);

    glEnd();



    // Desenha as bordas laterais com a cor branca

    glLineWidth(16.0f);

    glBegin(GL_LINES);

    glVertex2f(0, windowHeight * 0.4);

    glVertex2f(0, windowHeight);

    glVertex2f(windowWidth, windowHeight * 0.4);

    glVertex2f(windowWidth, windowHeight);

    glEnd();



    // Desenha as bordas diagonais com a cor branca

    glLineWidth(12.0f);

    glBegin(GL_LINES);

    glVertex2f(0, windowHeight * 0.4);

    glVertex2f(windowWidth * 0.3, 32);

    glVertex2f(windowWidth, windowHeight * 0.4);

    glVertex2f(windowWidth * 0.7, 32);

    glEnd();



    // Desenha os bumpers

    drawBumper(windowWidth * 0.3, 200, 50, 1, 0, 1); // bumper esquerdo

    drawBumper(windowWidth * 0.7, 200, 50, 1, 0, 1); // bumper direito

    drawBumper(windowWidth * 0.5, 330, 32, 1, 0, 1); // bumper mid

    drawBumper(windowWidth * 0.2, 400, 34, 1, 0, 1); // bumper mid esquerdo

    drawBumper(windowWidth * 0.8, 400, 30, 1, 0, 1); // bumper mid direito

    drawBumper(windowWidth * 0.15, 600, 30, 1, 0, 1); // bumper top esquerdo

    drawBumper(windowWidth * 0.85, 600, 36, 1, 0, 1); // bumper top direito

    drawBumper(windowWidth * 0.35, 500, 30, 1, 0, 1); // bumper top mid esquerdo

    drawBumper(windowWidth * 0.65, 500, 36, 1, 0, 1); // bumper top mid direito


    // Define a cor dos flippers para amarelo

    glColor3f(1.0f, 1.0f, 0.0f);


    // Desenha a barra esquerda

    glBegin(GL_TRIANGLES);

    glVertex2f(windowWidth * 0.3, 32);

    glVertex2f(windowWidth * 0.3, 12);

    glVertex2f(windowWidth * 0.3 + 120, 32);

    glEnd();


    // Desenha a barra direita

    glBegin(GL_TRIANGLES);

    glVertex2f(windowWidth * 0.7, 32);

    glVertex2f(windowWidth * 0.7, 12);

    glVertex2f(windowWidth * 0.7 - 120, 32);

    glEnd();


    // Define a cor da esfera para vermelho

    glColor3f(1.0f, 0.0f, 0.0f);


    // Desenha a esfera na posição (400, 200) com raio 20

    glPushMatrix();

    glTranslatef(400.0f, 200.0f, 0.0f);

    glutSolidSphere(20, 16, 16);

    glPopMatrix();


    // Mostra o resultado na tela

    glutSwapBuffers();

}

int main(int argc, char ** argv)
{
    // Inicializa o GLUT

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Cria a janela do jogo

    glutInitWindowSize(windowWidth, windowHeight);

    glutCreateWindow("Pinball");


    // Define a função de renderização

    glutDisplayFunc(display);

    // Define a cor de fundo da janela para preto

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Entra no loop principal do jogo

    glutMainLoop();

    return 0;

}
