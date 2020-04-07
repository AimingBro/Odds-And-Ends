#include <stdio.h>

int gcd(int a, int b);                          //최대공약수 구하는 함수
int lcm(int a, int b);                          //최소공배수 구하는 함수

int main(void)
{
	printf("gcd is :%d\n", gcd(365, 146));
	printf("lcm is :%d\n", lcm(365, 146));
	return 0;
}

int gcd(int a, int b)
{
	printf("gcd(%d, %d)\n", a, b);
	if(b <= 0)
		return a;
	else return gcd(b, a % b);                  //반복되는 작업이므로 재귀를 통해 해결한다.
}

int lcm(int a, int b)
{
	return a*b / gcd(a, b);                     //두수의 곱을 최대공약수로 나누면 최소공배수가 된다.
}
