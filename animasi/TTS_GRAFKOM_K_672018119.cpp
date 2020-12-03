#include <windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <math.h>
#define M_PI 3.14

float a = 0;
float b = 0;

void lingkaran(float TITIK_LAYAR_X, float TITIK_LAYAR_Y,
               float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI)
{
    GLfloat derajat = (360.0f / JUMLAH_SUDUT) * M_PI / 180.0f;
    glBegin(GL_TRIANGLE_FAN);
        GLfloat sudut = 0.0f - ROTASI;
        for (int _k = 0; _k < JUMLAH_SUDUT; ++_k)
        {
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X * cos(sudut)), TITIK_LAYAR_Y + (LEBAR_Y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();
}

void kirby()
{
    glColor3f(0.9, 0.1, 0.2);
    lingkaran(65, 56, 13, 7, 1000,20); // kaki
    lingkaran(85, 56, 13, 7, 1000,20); // kaki
    glColor3f(1.0, 0.45, 0.60);
    lingkaran(75, 75, 18, 23, 1000, 20); //badan
    lingkaran(58, 75, 10, 7, 1000,20); // tangan
    lingkaran(93, 75, 10, 7, 1000,20); // tangan
    glColor3f(0.0, 0.0, 0.0);
    lingkaran(71, 83, 2.3, 7, 1000, 120); // mata luar
    lingkaran(81, 83, 2.3, 7, 1000, 120); // mata luar
    glColor3f(0.0, 0.3, 0.8);
    lingkaran(71, 79.8, 1.5, 3, 1000, 120); // mata bawah
    lingkaran(81, 79.8, 1.5, 3, 1000, 120); // mata bawah
    glColor3f(0.0, 0.0, 0.0);
    lingkaran(71, 83.8, 1.5, 4, 1000, 120); // mata tengah
    lingkaran(81, 83.8, 1.5, 4, 1000, 120); // mata tengah
    glColor3f(1.0, 1.0, 1.0);
    lingkaran(71, 86, 1.3, 2.8, 1000, 120); // mata atas
    lingkaran(81, 86, 1.3, 2.8, 1000, 120); // mata atas
    glColor3f(0.9, 0.2, 0.50);
    lingkaran(86, 75, 2.5, 2, 1000, 120); // pink
    lingkaran(66.3, 75, 2.5, 2, 1000, 120); // pink
    glColor3f(0,0,0);
    lingkaran(76, 69, 4, 4, 1000, 20);
    glColor3f(0.9, 0.1, 0.2);
    lingkaran(76, 68, 3, 2, 1000, 20);
    glColor3f(0,0,0);
    lingkaran(76, 69, 4, 1, 1000, 20);
    //lingkaran(50, 50, 50, 50, 1000, 120);//(kanan/kiri, atas/bawah, lebar, tinggi, biar lingkaran, ?)
}

void backgound()
{
    glPushMatrix();
    glColor3f(0.184314, 0.184314,0.309804);
    glRectf(-10.0,150.0,150.0,110.0); //kiri, atas, kanan, bawah
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.45,1.0,0.0); //halaman
    glVertex2i(-10, 110);
    glVertex2i(150, 110);
    glVertex2i(150, -10);
    glVertex2i(-10, -10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.329412, 0.329412, 0.329412);
    glVertex2i(55, 110);
    glVertex2i(145, 110);
    glVertex2i(100, 200);
    glEnd();
    glPopMatrix();
    glFlush();
    glColor3f(1,1,0);
    lingkaran(0, 145, 13, 15, 1000, 120);
}

void pohon1()
{
    glPushMatrix();
    glColor3f(0.52, 0.37, 0.26);
    glRectf(10.0,18.0,23.0,-10.0); //kiri, atas, kanan, bawah
    glColor3f(0, 0.2, 0);
    lingkaran(0, 20, 13, 16, 1000, 20);
    lingkaran(5, 35, 13, 16, 1000, 20);
    lingkaran(15, 40, 13, 16, 1000, 20);
    lingkaran(10, 15, 13, 16, 1000, 20);
    lingkaran(20, 18, 13, 16, 1000, 20);
    lingkaran(28, 33, 13, 16, 1000, 20);//(kanan/kiri, atas/bawah, lebar, tinggi, biar lingkaran, ?)
    glPopMatrix();
    glFlush();
}

void pohon2()
{
    glPushMatrix();
    glColor3f(0.52, 0.37, 0.26);
    glRectf(130.0,18.0,117.0,-10.0); //kiri, atas, kanan, bawah
    glColor3f(0, 0.2, 0);
    lingkaran(140, 20, 13, 16, 1000, 20);
    lingkaran(135, 35, 13, 16, 1000, 20);
    lingkaran(125, 40, 13, 16, 1000, 20);
    lingkaran(130, 15, 13, 16, 1000, 20);
    lingkaran(120, 18, 13, 16, 1000, 20);
    lingkaran(112, 33, 13, 16, 1000, 20);//(kanan/kiri, atas/bawah, lebar, tinggi, biar lingkaran, ?)
    glPopMatrix();
    glFlush();
}

void dadah()
{
    glPushMatrix();
    glColor3f(0, 0.2, 0);
    lingkaran(40, -5, 13, 16, 1000, 20);
    lingkaran(50, -5, 13, 16, 1000, 20);
    lingkaran(60, -5, 13, 16, 1000, 20);
    lingkaran(70, -5, 13, 16, 1000, 20);
    lingkaran(80, -5, 13, 16, 1000, 20);
    lingkaran(90, -5, 13, 16, 1000, 20);
    lingkaran(45, 0, 13, 16, 1000, 20);
    lingkaran(55, 10, 13, 16, 1000, 20);
    lingkaran(65, 5, 13, 16, 1000, 20);
    lingkaran(85, 0, 13, 16, 1000, 20);
    glPopMatrix();
    glFlush();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    backgound();
    glPushMatrix();
    glTranslated(a,b,0);
    kirby();
    glPopMatrix();
    pohon1();
    pohon2();
    dadah();
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    if(key == 'a' || key == 'A') a-=1;
    else if(key == 'd' || key == 'D') a+=1;
    else if(key == 'w' || key == 'W') b+=1;
    else if(key == 's' || key == 'S') b-=1;
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glLineWidth(5.0);
    glutCreateWindow("Kirby");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(1,timer,0);
    gluOrtho2D(-10, 150.0, -10, 150.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
