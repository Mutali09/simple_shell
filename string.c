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
/**
 * str_cmp - function to compare two strings
 * @str1: the first string
 * @str2: the second string
 * @n: the number of characters to compare
 * 
 * Return: 0 if the strings are equal
*/
int str_cmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i] || *str1 == '\0' || *str2 == '\0')
		{
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}
	}
	return (0);
}