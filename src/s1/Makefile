
.PHONY: cleanbin clean

CC=gcc


cleanrepo: cleanbin
	@echo ">> Removing every '*.o' and '*.dSYM' ..."
	@find . -type d -name '*.dSYM' -exec rm -rf {}  \;
	@find . -type f -name '*.o' -exec rm -f {}  \;


cleanbin:
	@echo ">> Creating dummy C program..."
	@echo 'int main() { return 0; }' > .dummy.c

	@echo ">> Compiling dummy binary..."
	@$(CC) .dummy.c -o .dummy_binary

	@echo ">> Detecting binary type..."
	@TYPE=$$(file -b .dummy_binary | cut -d',' -f1); \
	echo ">> Detected binary type: $$TYPE"; \
	echo ">> Searching and removing matching files..."; \
	find . -type f ! -name ".dummy_binary" ! -name "Makefile" -exec sh -c 'file -b "$$0" | grep -q "^'"$$TYPE"'" && echo "Removing $$0" && rm -f "$$0"' {} \;

	@echo ">> Cleaning up dummy files..."
	@rm -f .dummy.c .dummy_binary
