CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
DIR_OUT=../s21_string/
SRCS = s21_exp.c \
		s21_floor.c \
		s21_fmod.c \
		s21_log.c \
		s21_pow.c \
		s21_abs.c \
		s21_fabs.c \
		s21_acos.c \
		s21_asin.c \
		s21_atan.c \
		s21_sqrt.c \
		s21_sin.c \
		s21_cos.c \
		s21_ceil.c \
		s21_tan.c
OBJS = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report


all: s21_math.a gcov_report test

test: $(OBJS) ./tests/*.c main.c
	$(CC) $(CFLAGS) $(CHECK_FLAGS) ./tests/*.c main.c $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) *.o *.gcno *.gcda *.info *.a $(REPORT_NAME) $(NAME) check_res finish

s21_math.a: $(OBJS)
	ar rc s21_math.a $(OBJS) 
	ranlib s21_math.a

gcov_report: ./tests/*.c main.c
#   checkmk test.check > ./tests/*.c main.c
	$(CC) -o $(NAME) $(SRCS) ./tests/*.c main.c $(ALL_FLAGS) 
	./$(NAME)
	geninfo *.gcda *.gcno -b . -o check_res 
	genhtml check_res -o finish
