CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
DIR_OUT=../s21_string/
SRCS = s21_exp.c \
		s21_fmod.c \
		s21_log.c \
		s21_pow.c 

OBJS = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report


all: s21_math.a gcov_report test

test: $(OBJS) s21_math_test.c
	$(CC) $(CFLAGS) $(CHECK_FLAGS) s21_math_test.c $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) *.o *.gcno *.gcda *.info *.a $(REPORT_NAME) $(NAME) check_res finish

s21_math.a: $(OBJS)
	ar rc s21_math.a $(OBJS) 
	ranlib s21_math.a

gcov_report: s21_math_test.c
#   checkmk test.check > s21_math_test.c
	$(CC) -o $(NAME) $(SRCS) s21_math_test.c $(ALL_FLAGS) 
	./$(NAME)
	geninfo *.gcda *.gcno -b . -o check_res 
	genhtml check_res -o finish
