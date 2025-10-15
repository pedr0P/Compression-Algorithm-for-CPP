# Compression-Algorithm-for-CPP
This is a algorithm made to compress a `.cpp` file based on the Huffman Algorithm.


## How it Works
Every character in c++ has 8 bit of size by default. The objective of this algorithm is to reduce this:

The algorithm is going to read the file entered and check the most frequent words of the code. Then, it will give a codification based of the huffman algorithm: The more frequent words are going to have a smaller amount of bits, and this will help to compress the file!

Example: You probably always use the word `return` in your code. Any character of this word has 8 bits, so the entire word has 48 bits! But compressed, this 48 bits are going to turn into 2 or 3.

By: Theo Henrique da Silva Borges e Pedro Vinícius Barbosa Pereira
