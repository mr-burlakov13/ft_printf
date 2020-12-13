/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:43:41 by lhayward          #+#    #+#             */
/*   Updated: 2020/12/09 13:05:16 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define ALL_SYMBOLS	"0123456789diuscpnfgexX%lh-+.*# "

typedef struct		s_list
{
	int				minus;
	int				zero;
	int				shirina;
	int				tochnost;
	int				pos;
	int				n_sim;
	int				shirina_2;
	int				tochnost_2;
	int				real_minus;
	int				pointer;
	int				null_p;
	int				plus;
	int				space;
	int				grill;
	int				regist_grill;
	int				tochn_float;
	int				len;
	int				len2;
	int				len3;
	int				okrug;
	int				kontr;
	int				zaza;
	int				llhh;
	int				bukva_b;
	int				ost_b;
}					t_list;
int					ft_printf(const char *format, ...);
int					main_parse(const char *format, t_list *list, va_list ap);
void				converse_parse(char const *format,
		t_list *list, va_list ap);
void				converse_parse_2(char const *format,
		t_list *list, va_list ap);
void				converse_parse_3(char const *format, t_list *list);
void				obnul_list(t_list *list);
void				mod_flags(char const *format, t_list *list, va_list ap);
void				flags(char const *format, t_list *list);
void				tochnost(char const *format, t_list *list, va_list ap);
void				shirina(char const *format, t_list *list, va_list ap);
void				print_integer(t_list *list, va_list ap);
void				print_str(t_list *list, va_list ap);
void				print_sym(t_list *list, va_list ap);
void				print_point(t_list *list, va_list ap);
void				print_uint(t_list *list, va_list ap);
void				print_hex(t_list *list, va_list ap, char ch);
void				print_proc(t_list *list, char c);
void				convert(t_list *list, int len);
void				left_print(t_list *list, char *str, int i);
void				right_print(t_list *list, char *str, int i);
void				convert_pointer(t_list *list, int len);
void				obnul_flags(t_list *list);
char				*itoa_base_mod(unsigned long long i,
		unsigned long long b, char reg);
char				*ft_strchr(const char *s, int ch);
int					ft_atoi(const char *str);
int					ft_chet(size_t i, size_t j, size_t k, const char *mas);
size_t				ft_strlen(const char *str);
void				print_bonus_plus(t_list *list, va_list ap);
void				convert_plus(t_list *list, int len);
void				left_print_plus(t_list *list, char *str, int len);
void				right_print_plus(t_list *list, char *str, int len);
void				convert_bon_hex(t_list *list, int len);
void				left_pri_grill(t_list *list, char *str, int len);
void				right_pri_grill(t_list *list, char *str, int len);
void				print_hex_grill(t_list *list, va_list ap, char c);
void				convert_int(t_list *list, int len);
void				left_print_int(t_list *list, char *str, int len);
void				right_print_int(t_list *list, char *str, int len);
void				con_flag_float(t_list *list);
void				con_flag_float_shirina(t_list *list);
void				left_print_float(t_list *list, char *str);
void				right_print_float(t_list *list, char *str);
int					len_2(t_list *list, long long int b);
char				*prebor(t_list *list, long long int a, long long int b);
char				*prebor2(char *str, long long int a, int len);
char				*prebor3(t_list *list, int b2, char *str);
char				*itoa_float(double i, t_list *list);
void				print_float(t_list *list, va_list ap);
void				print_float_plus(t_list *list, va_list ap);
void				con_flag_float_shir_bon(t_list *list);
void				left_print_float_bon(t_list *list, char *str);
void				right_print_float_bon(t_list *list, char *str);
void				print_g(t_list *list, va_list ap);

#endif
