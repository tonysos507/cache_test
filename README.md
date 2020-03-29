# cache_test
one way to check how big your L1D in bytes is
Now only support single one thread, that said, only one logical processor's L1D cache is tested.

The theory is that once the working set size is bigger than L1D cache, the performance jumps sharply.

This tool is based on Ulrich Drepper's paper <<What Every Programmer Should Know About Memory>> chapter 3.3.2
