#include<stdio.h>

static long p7();
static float formula2(float start, float end, int num, float limit);
int main(int argc,char* argvs[])
{
	printf("%ld\n", p7());
	system("PAUSE");
	return 0;
}

static float formula(float estimate, int num)
{
	return (estimate*estimate) - num;
}

//ÊÇ·ñÂú×ãÌõ¼þ£¬ÈôÂú×ã£¬·µ»Ø£¬²»Âú×ã¼ÌÐøÅÐ¶Ï
static float formula2(float start, float end, int num, float limit)
{
	float delta = 0, estimate = 0;
	estimate = (start + end) / 2;
	delta = formula(estimate, num);
	if (delta > 0) {
		if (delta < limit) { return estimate; }
		else { return formula2(start, (start + end) / 2, num, limit); }
	}
	else if (delta == 0){
		return estimate;
	}
	else {
		if (delta>-limit) { return estimate; }
		else {  return formula2((start + end) / 2, end, num, limit); }
	}
}

static int isprime(long *array,int len,long num)
{
	int i = 0,bd = 0;
	bd = (int)(formula2(1, num, num, 0.01)) + 1;
	if (bd >= array[len - 1]) {
		while (i < len){
			if (num%array[i] == 0){
				return 0;
			}
			i = i + 1;
		}
	}
	else {
		while (array[i] <= bd){
			if (num%array[i] == 0){
				return 0;
			}
			i = i + 1;
		}
	}
	return 1;
}

static long p7()
{
	int i = 3,len = 1;
	long array[10002] = { 0 };
	printf("%d\n", array[10002]);
	system("PAUSE");
	array[0] = 2;
	len = 1;
	while (len <= 10001) {
		if (isprime(array, len, i) == 1){
			array[len] = i;
			len = len + 1;
		}
		i = i + 1;
	}
	return array[10000];
}

static int p6()
{
	int i = 1, j = i + 1, pd = 0;
	while (i <= 100) {
		while (j <= 100) {
			pd = pd + i*j;
			j = j + 1;
		}
		i = i + 1;
		j = i + 1;
	}
	printf("%d\n", pd << 1);
}