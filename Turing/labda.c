#include <curses.h>
#include <unistd.h>

int
main ( void )
{
    WINDOW *ablak;
    ablak = initscr ();

    int x = 0;
    int y = 0;

    int xnov = 1;
    int ynov = 1;

    int mx;
    int my;

    for ( ;; ) {

        getmaxyx ( ablak, my , mx );

        clear();

        mvprintw ( y, x, "<3" );

        refresh ();
        usleep ( 100000 );

        x += xnov;
        y += ynov;

        if ( x>=mx-1 || x<=0 ) xnov *= -1;
        if ( y<=0 || y>=my-1) ynov *= -1;

    }

    return 0;

}