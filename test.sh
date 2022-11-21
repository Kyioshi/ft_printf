#printf

make libftprintf.a

#gcc -Werror -Wextra -Wall -o test_printf test.c libftprintf.a

gcc  -Werror -Wextra -Wall -o test_printf test.c libftprintf.a

./test_printf
#./test_ft_printf >> test_ft_printf.txt


#diff test_printf.txt test_ft_printf.txt 
#cmp test_printf.txt test_ft_printf.txt 

#rm test_printf test_ft_printf test_printf.txt test_ft_printf.txt

make clean


