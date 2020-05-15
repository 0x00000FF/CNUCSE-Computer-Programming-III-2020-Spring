#include <stdio.h>
#include <unistd.h>
#include <termios.h>

char getchar_direct()
{
    struct termios old_attr;
    struct termios new_attr;
    char c;

    tcgetattr( STDIN_FILENO, &old_attr );
    new_attr = old_attr;
    new_attr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &new_attr );

    c = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &old_attr );

    if ( c >= 0x20 )     // if character is not control sequence 
        printf("%c", c); //echo input

    return c;
}