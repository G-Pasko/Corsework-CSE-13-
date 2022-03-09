CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: business

business: business.c
	$(CC) $(CLFAGS) business.c -o businessdb
clean:
	rm -f business

format:
	clang-format -i -style=file *.[ch]

