#include "main.h"
/**
 * _printf - printf function that supports %c and %s conversions.
 *
 * @format: A format string containing zero or more conversion specifiers.
 *          %c - Character
 *          %s - String
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	
        int count_char = 0;

	va_start(args, format);
        while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(args, int);

					_putchar(c);
					count_char++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char*);

					while (*s)
					{
						_putchar(*s);
						s++;
						count_char++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count_char++;
					break;
				}
				default:
					_putchar('%');
					count_char++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count_char++;
		}

		format++;
	}

	va_end(args);

	return (count_char);
}
