#include <stdio.h>
#include <stdlib.h>
char num[11][50], dec[11][9];
int i, d = -1;
int order = 0;
int or;
int r1, r2, r3;
void comma(int i, int d, int order){//真 真 真
	int k, x;
	for(k = 0; k <= 49; k++){//真 真 真  真
		printf("%c", num[order][k]);
		if((i - k) % 3 == 1 && k < i-2)
			printf(",");
	}
	if(d > 0){//真 真 真 真
		for(x = 0; x <= 8; x++){
			printf("%c", dec[order][x]);
			if(x % 3 == 2 && x < d-1)
				printf(",");
		}
	}
}
void input(int order){//真 真
	if(order % 2 == 0){//真 真 真
		for(i = 0; i <= 50; i++){
			scanf("%c", &num[order][i]);
			if(num[order][i] == '.'){//真� 真 真
				for(d = 0; d <= 9; d++){
					scanf("%c", &dec[order][d]);
					if(dec[order][d] == ' ' || dec[order][d] == '\n')
						break;
				}
				break;
			}
			if(num[order][i] == ' ' || num[order][i] == '\n')//真� 真真�
				break;
		}
	}
	else//真� 真
		scanf("%c ", &num[order]);
}
int main()
{
	printf("(input) ");
	for(order = 0; order < 9; order++){
		input(order);
		if(order % 2 == 0)
			comma(i, d, order);
		if(d < 0 && num[order][i] == '\n'){
			break;
		}
		else if(dec[order][d] == '\n'){
			break;
		}
	}
	printf("= ");
	return 0;

}
