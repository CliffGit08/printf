#include <unistd.h>



/**

  * _putchar - writes the charector c to the stdout

  *@c: input charexctor to print

  *

  *Return: 1 on success

  */

int _putchar(char c)

{

	return (write(1, &c, 1));

