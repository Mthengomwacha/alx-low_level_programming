#include main.h

/**
 * _islower- function that checks lower case
 * @c: single letter input
 * Return: 1 if int c is lowercase, o if otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
