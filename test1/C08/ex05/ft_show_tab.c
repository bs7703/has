
void ft_show_tab(struct s_strock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
	}
}
