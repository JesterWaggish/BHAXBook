#include <curses.h>
#include <unistd.h>

int main()
{
	WINDOW* ablak;
	ablak = initscr();

	int x = 0;
	int y = 0;

	int mx, my;

	int xnov = 1;
	int ynov = 1;

	for(;;){

		getmaxyx ( ablak, my, mx );

		clear();

		mvprintw ( y, x, "8" );

		refresh();

		usleep( 100000 );

		x += xnov;
		y += ynov;

		if ( x >= mx-1 || x <= 0 ) xnov *= -1;
		if ( y <= 0 || y >= my-1 ) ynov *= -1;

	}
}