		else if (*format.str == 's')
				ft_putstr_fd(va_arg(format.argptr, char *), 1);
			else if (*format.str == 'd' || *format.str == 'i')
				ft_putnbr_fd(va_arg(format.argptr, int), 1);
			else if (*format.str == 'c')
				ft_putchar_fd(va_arg(format.argptr, int), 1);
			else if (*format.str == 'x')
				ft_hexa(va_arg(format.argptr, size_t));
			else if (*format.str == 'X')
				ft_hexamayus(va_arg(format.argptr, size_t));
			else if (*format.str == '%')
				ft_putchar_fd('%', 1);
			else if (*format.str == 'u')
				ft_unsigned_fd(va_arg(format.argptr, unsigned int), 1);
			else if (*format.str == 'p')
				ft_memorypointer(va_arg(format.argptr, char *));