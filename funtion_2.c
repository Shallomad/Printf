int print_str_cus(va_list args)
{
	char s = va_arg(args, char);
	int count = 0;

	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar((*s / 16) < 10 ? '0' + (*s / 16) : 'A' + (*s / 16) - 10);
			_putchar((*s % 16) < 10 ? '0' + (*s % 16) : 'A' + (*s % 16) - 10);
			count += 4;
		}
		else
		{
			_putchar(*s);
			count++;
		}
		s++;
	}

	return (count);
}

/**
 * print_p - Print a pointer address in hexadecimal format.
 */
int print_p(va_list args)
{
	void ptr = va_arg(args, void);
	unsigned long int addr = (unsigned long int)ptr;
	int count = 0;
	char hex_chars[] = "0123456789abcdef";
	char hex[16];
	int i = 0;

	/* Convert the address to hexadecimal */
	while (addr > 0)
	{
		hex[i] = hex_chars[addr % 16];
		addr /= 16;
		i++;
	}

	/* Print the pointer address in hexadecimal */
	_putchar('0');
	_putchar('x');
	count += 2;

	if (i == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (i > 0)
		{
			_putchar(hex[i - 1]);
			count++;
			i--;
		}
	}

	return (count);
}
