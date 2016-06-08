#include <stdio.h>
#include <stdlib.h>
char num[10][50], dec[10][9];
int i, d = -1;
int order = 0;
int or;
void comma(int i, int d, int order){//콤마 찍는 함수
	int k, x;
	for(k = 0; k <= 49; k++){//정수 부분 콤마 찍는 방법
		printf("%c", num[order][k]);
		if((i - k) % 3 == 1 && k < i-2)
			printf(",");
	}
	if(d > 0){//소수 부분 콤마 찍는 방법
		for(x = 0; x <= 8; x++){
			printf("%c", dec[order][x]);
			if(x % 3 == 2 && x < d-1)
				printf(",");
		}
	}
}
void input(int order){//입력 함수
	if(order % 2 == 0){//숫자를 받게 하는 부분
		for(i = 0; i <= 50; i++){
			scanf("%c", &num[order][i]);
			if(num[order][i] == '.'){
				for(d = 0; d <= 9; d++){
					scanf("%c", &dec[order][d]);
					if(dec[order][d] == ' ' || dec[order][d] == '\n')
						break;
				}
				break;
			}
			if(num[order][i] == ' ' || num[order][i] == '\n')
				break;
		}
	}
	else//연산자를 받게 하는 부분
		scanf("%c ", &num[order][0]);
}
int main()
{
	printf("(input) ");
	for(order = 0; order < 10; order++){
		input(order);
		if(d < 0 && num[order][i] == '\n'){
			break;
		}
		else if(dec[order][d] == '\n'){
			break;
		}
	}
	for(or = 0; or <= order; or += 2){
		switch(num[order][0]){
			case '+':
				addition(or);
				break;
			case '-':
				subtraction(or);
				break;
			case '*':
				multiple(or);
				break;
			case '/':
				division(or);
				break;
			case '%':
				remain(or);
				break;
			default :
				break;
		}
	printf("= ");
	comma(i, d, order);
	return 0;
}
}
