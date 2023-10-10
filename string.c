#include "shell.h"
/**
* _atoi - function for converting a str to int
* @s: String for conversion
* Return: int converted
*/
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int found_digit = 0;

	while (*s)
	{
		if (*s == '-' || *s == '+')
		{
			if (*s == '-')
				sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			found_digit = 1;
		}
		else if (found_digit)
		{
			break;
		}
		s++;
	}
	return (result * sign);
}
