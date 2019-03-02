#include <GLFW/glfw3.h>
#include <math.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void) {

	GLFWwindow* window;

	if (!glfwInit()) return -1;

	GLFWmonitor *mon;
	mon = NULL; // glfwGetPrimaryMonitor();
	if (!(window = glfwCreateWindow(640, 480, "OpenGL / GLFW", mon, NULL))) { glfwTerminate(); return -1; }

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	
	float x, y, z;
	x = -0.5;
	y = 0.5;
	z = 0.5f;

	int xdir = 1;
	int ydir = 0;

	float change = 0.01f;
	float r = 0.0f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		if (1) {
			if (xdir == 1) x += change;
			else if (xdir == 0) x -= change;
			if (ydir == 1) y += change;
			else if (ydir == 0) y -= change;

			if (x >= 0.5) { x -= change; xdir = 0; }
			else if (x <= -0.5) { x += change; xdir = 1; }
			if (y >= 0.5) { y -= change; ydir = 0; }
			else if (y <= -0.5) { y += change; ydir = 1; }

			glBegin(GL_POLYGON);
			if(x<0) glColor3f(1.f, 0.5f, 0.0f);
			else glColor3f(0.f, 0.5f, 1.0f);
			glVertex2f(x, -0.5f);
			glVertex2f(0.0f, z);
			glVertex2f(y, -0.5f);
		}

		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}
