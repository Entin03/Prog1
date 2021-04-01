/*
	g++ Ch16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o Ch `fltk-config --ldflags --use-images`
*/


#include "Lines_window.h"
#include "Graph.h"

int main()
{
	Lines_window win {Point{100,100}, 1920, 1080, "Lines"};
	
	return gui_main();
}
