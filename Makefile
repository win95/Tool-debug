all: tool.c
	gcc -o run tool.c
	rm -f *~

dns : tool.c
	gcc -o run tool.c
	
clean:
	rm -f *~
	rm -f run