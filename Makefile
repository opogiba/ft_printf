# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izelensk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:17:24 by izelensk          #+#    #+#              #
#    Updated: 2017/03/10 18:02:44 by opogiba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FOLDER = libft/
FOLDER2 = printf/

SRC1 = $(FOLDER)ft_bzero.c $(FOLDER)ft_memset.c $(FOLDER)ft_memcpy.c \
$(FOLDER)ft_strcmp.c $(FOLDER)ft_strncmp.c $(FOLDER)ft_atoi.c \
$(FOLDER)ft_strnew.c $(FOLDER)ft_strdel.c $(FOLDER)ft_strclr.c \
$(FOLDER)ft_memcmp.c $(FOLDER)ft_strlen.c $(FOLDER)ft_strdup.c \
$(FOLDER)ft_strcpy.c $(FOLDER)ft_strncpy.c $(FOLDER)ft_strcat.c \
$(FOLDER)ft_strrchr.c $(FOLDER)ft_strstr.c $(FOLDER)ft_strnstr.c \
$(FOLDER)ft_memccpy.c $(FOLDER)ft_memmove.c $(FOLDER)ft_memchr.c \
$(FOLDER)ft_strncat.c $(FOLDER)ft_strlcat.c $(FOLDER)ft_strchr.c \
$(FOLDER)ft_isalpha.c $(FOLDER)ft_isdigit.c $(FOLDER)ft_isalnum.c \
$(FOLDER)ft_isascii.c $(FOLDER)ft_isprint.c $(FOLDER)ft_toupper.c \
$(FOLDER)ft_tolower.c $(FOLDER)ft_memalloc.c $(FOLDER)ft_memdel.c \
$(FOLDER)ft_striter.c $(FOLDER)ft_striteri.c $(FOLDER)ft_strmap.c \
$(FOLDER)ft_strmapi.c $(FOLDER)ft_strequ.c $(FOLDER)ft_strnequ.c \
$(FOLDER)ft_strsub.c $(FOLDER)ft_strjoin.c $(FOLDER)ft_strtrim.c \
$(FOLDER)ft_itoa.c $(FOLDER)ft_putchar.c $(FOLDER)ft_putstr.c \
$(FOLDER)ft_putendl.c $(FOLDER)ft_putnbr.c $(FOLDER)ft_putchar_fd.c \
$(FOLDER)ft_putstr_fd.c $(FOLDER)ft_putendl_fd.c $(FOLDER)ft_putnbr_fd.c \
$(FOLDER)ft_lstnew.c $(FOLDER)ft_lstdelone.c $(FOLDER)ft_lstdel.c \
$(FOLDER)ft_lstadd.c $(FOLDER)ft_lstiter.c $(FOLDER)ft_lstmap.c \
$(FOLDER)ft_strsplit.c $(FOLDER)ft_swap.c $(FOLDER)ft_sqrt.c \
$(FOLDER)ft_sort_integer_table.c \
$(FOLDER)ft_print_params.c \
$(FOLDER)ft_strrev.c $(FOLDER)ft_iterative_factorial.c \
$(FOLDER)ft_sort_wordtab.c $(FOLDER)ft_foreach.c \
$(FOLDER)ft_rrange.c $(FOLDER)ft_realloc.c $(FOLDER)ft_abs.c\
$(FOLDER)ft_pow.c $(FOLDER)ft_itoa_base.c $(FOLDER)ft_clean_2d.c \
$(FOLDER)ft_clean_str.c $(FOLDER)ft_join_char.c


SRC2 = printf/ft_handle_specifier.c printf/utilites/ft_cust.c printf/print/ft_print_int.c \
printf/ft_printf.c printf/utilites/ft_utoa_base.c printf/utilites/ft_join_symbols.c \
printf/print/ft_print_string.c printf/print/ft_print_char.c printf/print/ft_print_float.c \
printf/parssing/ft_parsing_accuracy.c printf/parssing/ft_parsing_width.c \
printf/parssing/ft_parsing_flags.c printf/parssing/ft_parsing_length.c \
printf/parssing/ft_parsing_specifier.c printf/utilites/ft_join_prefix.c \
printf/utilites/ft_print.c printf/utilites/ft_wchar.c printf/utilites/ft_join_symbol.c printf/utilites/ft_clean.c printf/print/ft_print_memory.c printf/parssing/ft_parsing_brace.c printf/utilites/ft_convert_time.c printf/utilites/ft_put_apostrophe.c printf/print/ft_print_time.c libft/ft_clean_str.c printf/print/ft_print_nonprintable.c printf/utilites/ft_choose_color.c \
printf/utilites/ft_choose_fd.c libft/ft_clean_2d.c printf/utilites/ft_change_list.c printf/print/ft_pointer_to_int.c printf/utilites/ft_check_inf.c printf/utilites_for_double/ft_round.c printf/utilites_for_double/ft_handler_double.c libft/ft_join_char.c printf/print/ft_print_exponent.c printf/utilites_for_double/ft_parsing_znak_double.c printf/utilites_for_double/ft_handle_g.c printf/print/ft_print_double.c printf/print/ft_print_float_or_exponent.c


SRC = $(SRC1) $(SRC2)

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

OPTIONS = -I ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o:
	gcc $(FLAGS) $(OPTIONS) -c $<  -o $@

clean:
	/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all
