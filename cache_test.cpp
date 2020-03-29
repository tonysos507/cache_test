// cache_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <emmintrin.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <intrin.h>

#define NPAD 7

struct l
{
	struct l *n;
	long long pad[NPAD];
};


int main()
{
	size_t los = sizeof(struct l);
	printf("\neach element size : %u bytes\n", los);


	for (int exponet = 10; exponet <= 30; exponet++)
	{
//		srand(time(NULL));
		int som = pow(2, exponet);
		if ((som % los))
			continue;

		printf("exp : %d, size : %d bytes", exponet, som);

		struct l * phl = (struct l *)malloc(som);
		memset(phl, 0, som);
		int numofelm = som / los;
		for (int i = 0; i < numofelm; i++)
		{
			struct l * ptmpl = phl + i;

			if (i == (numofelm - 1))
			{
				ptmpl->n = phl;
			}
			else
			{
				ptmpl->n = ptmpl + 1;
			}
//			for (int j = 0; j < NPAD; j++)
//				ptmpl->pad[j] = rand();
		}


/***************************************************/
		struct l * phl1 = (struct l *)malloc(som);
		for (int i = 0; i < numofelm; i++)
		{
			struct l * ptmpl = phl1 + i;
			struct l * pg = ptmpl->n;
			long long a = ptmpl->pad[0];
		}

/**************************************************/


		printf(" count %d ", numofelm);
		struct l * tmp = phl;

		int loopcountdown = 468435456;
		long long a = 0;
		unsigned __int64 ts;
		unsigned __int64 te;
		ts = __rdtsc();
		while (loopcountdown--)
		{
//			for (int j = 0; j < NPAD; j++)
//				a = tmp->pad[j];
			tmp = tmp->n;
//			printf("\n%x", tmp);
		}
		te = __rdtsc();
		printf_s(" %I64d - %I64d = %I64d ticks ", te, ts, te - ts);

		if (phl1)
			free(phl1);
//		DebugBreak();
		if (phl)
			free(phl);


		printf("\n");
	}

	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
