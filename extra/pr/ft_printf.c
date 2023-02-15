#include <stdarg.h>
#include <unistd.h>



void ft_putnbr(long dig, int len, char *sign, int total) 
{
	if (dig >= len)
		ft_putnbr(dig/len, len, sign, total);
	write(1, &sign[dig % len], 1);
	total++;
	return (total);
}

int ft_puthex(unsigned dig, unsigned len, char *sign, int total)
{
	int total;

	if (dig >= len)
		ft_puthex(dig/len, len, sign, total);
	write(1, &sign[dig % len], 1);
	total++;
	return (total);
}

int ft_printf(const char *format, ...)
{
	int	total;
	va_list ap;
	va_start(ap, format);

	total = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len]) 
					len++;
				total += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long d = va_arg(ap, int);
				if (d < 0)
				{
					write(1, "-", 1);
					total++;
					d = -d;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				int x = va_arg(ap, int);
				ft_puthex(x, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			total += write(1, format++, 1);
	}
	va_end(ap);
	return(total);
}
