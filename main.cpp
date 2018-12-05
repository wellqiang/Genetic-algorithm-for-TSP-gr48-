#include <iostream>
#include <ctime>

#include "GA.h"

using namespace std;

int main() 
{
	int It = Iter;
	
    GA ga;

	srand((unsigned)time(NULL));
	
	clock_t clockStart = clock();
	for (int i = 1; i <= 15; i++) 
	{
		It = Iter;
		ga.init(); //读取数据集以及种群初始化

		while (It--)
		{
			ga.cycleCrossover();//循环交叉

			ga.mutationForNorepeAll();//变异

			ga.localSearchAll(); //局部搜索

			ga.selection();//选择下一代
		}
	}
	clock_t clockEnd = clock();
	cout << "Run time is :" << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
    return 0;
}