# cache_test
one way to check how big your L1D in bytes is

Now only support single one thread, that said, only one logical processor's L1D cache is tested.

The theory is that once the working set size is bigger than L1D cache, the performance jumps sharply.

This tool is based on Ulrich Drepper's paper What Every Programmer Should Know About Memory chapter 3.3.2

file cache_test2 is the code to check what the L1D associativity is and its L1D size. The theory is that we traverse a linked list, each element  size is 64 bytes, the number of element varies from 2 to 16, also the distance between elements varies from 2 to 128, a distance of 2 means that the next element's address is 128 bytes after the previous one. during running, L1D cache conflict misses  happen, and you will see tick counts grows sharply. 
