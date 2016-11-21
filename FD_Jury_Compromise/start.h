#pragma once
/************************************************************
Problem: Jury Compromise
Author: CHEN FANGDA
Version: 1.0
Date: 2016/11/09
Description: In Frobnia, a far-away country, the verdicts in court trials are determined by a jury consisting of members of the general public. Every time a trial is set to begin, a jury has to be selected, which is done as follows. First, several people are drawn randomly from the public. For each person in this pool, defence and prosecution assign a grade from 0 to 20 indicating their preference for this person. 0 means total dislike, 20 on the other hand means that this person is considered ideally suited for the jury. 
Based on the grades of the two parties, the judge selects the jury. In order to ensure a fair trial, the tendencies of the jury to favour either defence or prosecution should be as balanced as possible. The jury therefore has to be chosen in a way that is satisfactory to both parties. 
We will now make this more precise: given a pool of n potential jurors and two values di (the defence's value) and pi (the prosecution's value) for each potential juror i, you are to select a jury of m persons. If J is a subset of {1,..., n} with m elements, then D(J ) = sum(dk) k belong to J 
and P(J) = sum(pk) k belong to J are the total values of this jury for defence and prosecution. 
For an optimal jury J , the value |D(J) - P(J)| must be minimal. If there are several jurys with minimal |D(J) - P(J)|, one which maximizes D(J) + P(J) should be selected since the jury should be as ideal as possible for both parties. 
You are to write a program that implements this jury selection process and chooses an optimal jury given a set of candidates. 

Function List: // ñ«é©ùŞ?ĞàĞìÍíÒö
1. -------

History: // ?ŞÈáóËÇ??
***********************************************************/

typedef struct Cand
{
	int n1;
	int n2;
	int index;
}Cand;

typedef struct Comp
{
	int sum;
	int sub;
	int index;
}Comp;
struct NodeCmp
{
	bool operator()(Comp &na, Comp &nb)
	{
		if (na.sub != nb.sub)
			return na.sub >= nb.sub;
		else
			return na.sum <= nb.sum;
	}
};