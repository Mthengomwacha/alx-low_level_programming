#include "main.h"
/**
*error_wr - detect error in write or read
*@fdr: result of open file to read
*@fdw: result of open file to write
*@file_from: file from copy
*@file_to: file to copy
*/
void error_wr(int fdr, int fdw, char *file_from, char *file_to)
{
	ssize_t r, w;
	char buf[NBYTES];

	do {
		r = read(fdr, buf, NBYTES);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}
		if (r)
		{
			w = write(fdw, buf, r);
			if (w != r)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
				exit(99);
			}
		}
	} while (r);
}
/**
 * main - copy content of one file into another
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success or exit with error number.
 */
int main(int argc, char *argv[])
{
	char *file_from, *file_to;
	int fdr, fdw;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);

