#include <stdio.h>

int main()
{
	const int l1 = 3, l2 = 2;
	int edge[l1][l2] = { {1, 2}, {3, 4}, {5,6} };
	
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			printf("%d,%d,%d;\n", edge[i][j],i,j);
		}
	}

	return 0;
}