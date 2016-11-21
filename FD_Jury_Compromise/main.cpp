#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include "start.h"
#pragma warning( disable : 4996) 
using namespace std;

Cand* best;
//seek the worst case's index
void set_best(int num, Cand* cands, Cand next)
{
	int i;
	int all1 = 0, all2 = 0;
	int temp1, temp2;
	int sum, sub;
	Comp* compare;
	Comp top;
	compare = (Comp*)malloc(sizeof(Comp)*(num + 1));
	//Cand top;
	priority_queue<Comp, vector<Comp>, NodeCmp> pri_cand;

	//for (i = 0; i < num1; i++)
	//{
	//	pri_cand.push(cands[i]);
	//}
	//top = pri_cand.top();
	//printf("worst case is £¨%d,%d£©\n", top.n1, top.n2);
	//return top.index;
	//initialization best array
	for (i = 0; i < num; i++)
	{
		all1 += cands[i].n1;
		all2 += cands[i].n2;
	}
	sum = all1 + all2;
	sub = abs (all1 - all2);
	printf("sum is %d,sub is %d\n", sum, sub);

	//initial status
	compare[0].index = -1;
	compare[0].sum = sum;
	compare[0].sub = sub;

	//instead steps
	for (i = 0; i < num; i++)
	{
		//delete the data of cands[index] and add next
		temp1 = all1 - cands[i].n1 + next.n1;
		temp2 = all2 - cands[i].n2 + next.n2;
		sum = temp1 + temp2;
		sub = abs(temp1 - temp2);

		compare[i + 1].index = i;
		compare[i + 1].sum = sum;
		compare[i + 1].sub = sub;
		printf("instead index %d, sum is %d, sub is %d\n", i, sum, sub);
	}
//	printf("round %d\n", next.index - num);

	//for (i = 0; i < num + 1; i++)
		pri_cand.push(compare[0]);

	//top = pri_cand.top();
	//printf("worst case is index %d\n", top.index);
	free(compare);
}

int main()
{
	//int cand_num;
	//int jury_num;
	int num1, num2;
	/*int temp1, temp2;*/
	Cand *cands;
	FILE *fp;

	fp = fopen("candidates.txt", "r");
	if (fp == NULL)
		exit(0);
	else
		printf("there is such a file\n");

	fscanf(fp, "%d %d", &num1, &num2);
	//printf("The first two numbers are %d %d\n", num1, num2);
	cands = (Cand*)malloc(num1*sizeof(Cand));
	for (int i = 0; i < num1; i++)
	{
		fscanf(fp, "%d %d", &cands[i].n1, &cands[i].n2);
		cands[i].index = i;
	}
	//initial the best case
	best = (Cand*)malloc(num2*sizeof(Cand));
	for (int i = 0; i < num2; i++)
	{
		best[i].index = i;
		best[i].n1 = cands[i].n1;
		best[i].n2 = cands[i].n2;
	}
	//for (int i = num2; i < num1; i++)
	{
		set_best(num2, best, cands[num2]);
	}
	fclose(fp);
	getchar();
	getchar();
	
	return 0;
}
