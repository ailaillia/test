#include<stdio.h>
#include<time.h>

static int condition_a(int c, int *max);
int main(int argc, char *argvs[])
{
	clock_t start, end;
	int c = 334, a = 1, b = 1, max = 1;
	start = clock();
	while (c < 500){
		condition_a(c, &max);
		c = c + 1;
	}
	printf("%d\n", max);
	end = clock();
	printf("time=%f\n", ((double)(end - start)) / CLK_TCK);
	system("PAUSE");
	return 0;
}

static int condition_b(int a,int c,int mul_c,int *max)
{
	int b = 1000 - c - a;
	int product;
	if ((c > a) && (c > b)){
		if ((a*a + b*b) == mul_c){
			product = a*b*c;
			if (*max < product){
				*max = product;
			}
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

static int condition_a(int c,int *max)
{
	int a = 1, b = 1, tmp = 1000 - c, tmp1,tmp2;
	tmp1 = ((tmp % 2) == 1) ? ((tmp / 2) + 1):(tmp/2);
	tmp2 = c*c;
	while (a<tmp1) {
		condition_b(a, c, tmp2, max);
		a = a + 1;
	}
	return 0;
}