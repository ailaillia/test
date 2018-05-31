#include<stdio.h>
#include<stdlib.h>


static int get_numofbit(int num);
static int create_PI_TT(int nVars);

static int truth_table[5] = {0x0000FFFF,0x00FF00FF,0x0F0F0F0F,0x33333333,0x55555555 };

int main(int argc,char*argvs[])
{
	//printf("%d\n",get_numofbit(128));
create_PI_TT(9);
    return 0;
}

static int get_numofbit(int num)
{
	int i = 0,res = 0;
	while(i < 5) {
		//the truth_table[i] is not use for truth,it is just a mask in this place
		if((truth_table[i]&num) == 0){
			res = (res << 1)|0x01;
		}
		else {
			res = res << 1;
		}
		i = i + 1;
	}
	return res;
}

static int set_zero(int *PI_truth,int len)
{
	int a = 0,i = 0;
	while(i<len) {
		PI_truth[i] = a;
		i = i + 1;
	}
	return 0;
}

static int set_one(int *PI_truth,int len)
{
	int a = 0,i = 0;
	while(i<len) {
		PI_truth[i] = ~a;
		i = i + 1;
	}
	return 0;
}

static int set_value(int *PI_truth,int len,int cycle)
{
	//int num = get_numofbit(cycle);
	int num = cycle - 1;
	int i = 0,tmp = 0;
	if(num<=5) {
		i = 0;
		while(i<len) {
			PI_truth[i] = truth_table[5 - num];
			i = i + 1;
		}
	}
	else {
		i = 0;
		tmp = 1 << (num - 5 - 1);
		while(i<len) {
			set_zero(&(PI_truth[i]),tmp);
			i = i + tmp;
			set_one(&(PI_truth[i]),tmp);
			i = i + tmp;
		}	
	}
	return 0;
}

static int** create_array(int nVars,int len)
{
	int *PI_truth = NULL,**PIs=NULL,i=1;
	PIs = (int**)malloc(sizeof(int*)*nVars);
	while(i<=nVars) {
		PIs[i-1] = (int*)malloc(sizeof(int)*len);
		set_value(PIs[i-1],len,i+1);//10 as the bitth of cycle
		i = i + 1;
	}
	return PIs;
}

static int show(int **PIs,int nVars,int len)
{
	int i = 0,j = 0;
	while(j<nVars) {
		while(i<len) {
			printf("%08x",PIs[j][i]);
			i = i + 1;
		}
		printf("\n");
		i = 0;
		j = j + 1;
	}
	return 0;
}

static int free_PIs(int **PIs,int nVars)
{
	int i=0,j=0;
	while(i<nVars) {
		free(PIs[i]);
		i = i + 1;
	}
	free(PIs);
	return 0;
}

static int create_PI_TT(int nVars)
{
	int tmp = 0,i = 0,j = 0;
	int **PIs=NULL;
	if(nVars > 5){
		tmp = 1 << nVars;
		tmp = tmp >> 5;
	}
	else {
		tmp = 1;
	}
	PIs = create_array(nVars,tmp);
	show(PIs,nVars,tmp);
	free_PIs(PIs,nVars);
    return 0;
}
