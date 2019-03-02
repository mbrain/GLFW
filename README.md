# OpenGL

 * http://www.informit.com/articles/article.aspx?p=328646&seqNum=6
 * http://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Introduction.html

Windows VS
 * Download from glfw.org
 * Link: glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib
 * Include: $(SolutionDir)Dependencies\GLFW\include;
 * Libs: $(SolutionDir)Dependencies\GLFW\lib-vc2015;

Linux
 * apt-get install libglfw3-dev
 * pkg-config --libs --cflags glfw3
 * gcc Example01.c -o example01 -lglfw -lGL
