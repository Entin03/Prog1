/*

 g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images`
 
*/


#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	
	//FELADAT 1
	Simple_window win (Point{100, 100}, 800, 1000, "CH13");
	
	
	//FELADAT 2
	int gird_size=800;
	int onesquare=100;
	
	Lines gird;
	for (int i = onesquare; i <= gird_size; i+=onesquare)
	{
		gird.add(Point{i,0}, Point{i, gird_size});
	}

	for (int j = onesquare; j <= gird_size; j+=onesquare)
	{
		gird.add(Point{0,j}, Point{gird_size, j});
	}

	win.attach(gird);
	
	//FELADAT 3
	for (int i = 0; i < 8; i++)
	{
	   for (int j=0; j < 8; i++)
	   {
	      if (i==j)
	      {
	         Rectangle * rec = new Rectangle {Point{i*100, j*100}, onesquare, onesquare};
	         rec->set_color(Color::red);
	         win.attach(*rec);
	      }
	   }
	}

	//FELADAT 4
	
	Image pic1{Point{300,0}, "200x200.jpg"};
	Image pic2{Point{0,500}, "200x200.jpg"};
	Image pic3{Point{300,600}, "200x200.jpg"};
	
	win.attach(pic1);
	win.attach(pic2);
	win.attach(pic3);
	
	//FELADAT 5
	
	for (int i = 0; i<gird_size; i+=onesquare)
	{
	   for (int j = 0; j < gird_size; j+=onesquare)
	   {
	   	Image pic4{Point{j,i}, "100x100.jpg"};
	   	win.attach(pic4);
	   	win.wait_for_button();
	   }
	}
	
	
	
}
