SRC := main.c uuid.c
TGT := a.out

run: $(TGT)
	./$(TGT)

$(TGT): $(SRC)
	gcc -o $@ $<
