/*
 ============================================================================
 Name        : Main.c
 Author      : ZeRoKoL
 ============================================================================
 */
#include <GL/glut.h> // inclusão da biblioteca
#include <stdlib.h> // inclusão da biblioteca
// Declarações
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Inicializa o GLUT e processa qualquer parâmetro passado pela linha de comandos. Deve ser chamada antes de qualquer outra rotina GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Indica se vamos usar cores no modo RGBA ou Indexado. Também especificamos se usaremos um ou dois buffers para a geração das imagens e se vamos associar buffers de profundidade, estêncil e/ou acumulador à janela que estamos usando.
	glutInitWindowSize(150, 150); // Especifica as dimensões da janela em pixels.
	glutInitWindowPosition(100, 100); // Especifica a coordenada superior esquerda da janela
	glutCreateWindow("Desenha uma linha"); // Cria a janela e devolve um identificador único para a janela. Até que o comando glutMainLoop seja chamado, a janela não será mostrada.
	init();
	glutDisplayFunc(display); // Toda vez que o GLUT determinar que a janela tem de ser desenhada, ele chamará a função aqui determinada.
	glutKeyboardFunc(keyboard); // Determinam as funções que usaremos para ler o teclado e o mouse respectivamente.
	glutMainLoop(); // É o último comando que chamamos. Ele faz com que todas as janelas criadas sejam mostradas. Uma vez que entramos neste loop, só saímos quando o programa se encerra.
	return 0;
}
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0); // Fornece os valores para limpeza do buffer de cor no modo RGBA
	glOrtho(0, 256, 0, 256, -1, 1); // Seleciona o modo de projeção Ortogonal.
}
void display(void) {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	//Limpa toda a Janela para a cor do comando glClearColor
	glColor3f(0.0, 0.0, 0.0); // Seleciona a cor preta para a linha
	glBegin(GL_LINES);
	glVertex2i(20, 100); // Fornece as coordenadas dos pontos iniciais e finais
	glVertex2i(100, 20); // Fornece as coordenadas dos pontos iniciais e finais
	glEnd();
	glFlush(); // Este comando permite a execução em ambiente de rede
}

// A rotina a seguir termina o programa com a tecla Esc
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}
