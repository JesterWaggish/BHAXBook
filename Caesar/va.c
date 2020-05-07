#include <stdarg.h>
#include <stdio.h>
 
double average ( int num, ... ) {
    
    va_list arguments;                     
    double sum = 0;
 
    va_start ( arguments, num );           

    for ( int x = 0; x < num; x++ ) 
        sum += va_arg ( arguments, double ); 
    
    va_end ( arguments );
 
    return sum / num;                      
}
 
int main() {
    
    printf( "%f\n", average ( 3, 12.2, 22.3, 4.5 ) );
    
    printf( "%f\n", average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) );

    return 0;
}