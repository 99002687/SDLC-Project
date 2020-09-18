SRC = unity/unity.c\
src/Prime.c\
test/test_prime.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = Prime.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation

clean:
	rm -f $(PROJECT_NAME) 
