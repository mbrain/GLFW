/* OpenGL (GLFW) Example02
 *
 * Drawing primitives
 *
 * http://www.informit.com/articles/article.aspx?p=328646&seqNum=6
 * http://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Introduction.html
 *
 * Link: glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib
 * Include: $(SolutionDir)Dependencies\GLFW\include;
 * Libs: $(SolutionDir)Dependencies\GLFW\lib-vc2015;
 */

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
	glfwSetWindowSizeLimits(window, 640, 480, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwSetWindowPos(window, 150, 150); // GLFW_DONT_CARE

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);
		glColor3f(1.f, 0.0f, 0.0f);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();
	return 0;

}
