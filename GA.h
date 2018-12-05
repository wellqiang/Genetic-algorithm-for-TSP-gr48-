#pragma once

const int Numgene = 48; //基因位数
const int Numpop = 200;  //种群个数
const double Pc = 0.6;
const double Pm = 0.1;
const int Elite = 10;
const int Iter = 2000;

struct individual
{
	int cities[Numgene + 1] = { 0 };
	double fitness = 0;
};

class GA{

public:
    /*读取数据集并且初始化种群*/
    void init();

    /*选择下一代*/
    void selection();

    /*交叉*/
	void cycleCrossover();

    /*变异*/
	void mutationForNorepeAll();

	/*对种群进行局部搜索*/
	void GA::localSearchAll();

	/*打印结果*/
	void resultPrint();

private:

    /*计算种群适应度*/
    void fitness(individual *indi);

	/*精英选择*/
	void eliteChoose();

	/*轮盘赌*/
	void rouletteChoose(individual *populations, int sizeofPop, int *pool, int sizeofSelect);

	/*局部搜索*/
	void localSearchIndiPro(individual *indi);

	/*无重复实数编码变异方法*/
	void mutationForNoRepe(individual *indi);

private:
	individual populations[Numpop + 1]; //种群个体
	individual offspring[4 * Numpop + 1]; //子代所有个体
	int numOfOffspring = 0; //子代个体数目
	individual optimalIndividual;//最优个体
	
	int gr48[50][50] = { 0 }; //gr48数据集
};

