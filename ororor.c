#include <stdio.h>
#include <stdlib.h>
char num[11][50], dec[11][9];
int i, d = -1;
int order = 0;
int or;
int r1, r2, r3 = 11;
int sh, dh, k;
void comma(int i, int d, int order){//¿¿ ¿¿ ¿¿
	int k, x;
	for(k = 0; k <= 49; k++){//¿¿ ¿¿ ¿¿  ¿¿
		printf("%c", num[order][k]);
		if((i - k) % 3 == 1 && k < i-2)
			printf(",");
	}
	if(d > 0){//¿¿ ¿¿ ¿¿ ¿¿
		for(x = 0; x <= 8; x++){
			printf("%c", dec[order][x]);
			if(x % 3 == 2 && x < d-1)
				printf(",");
		}
	}
}
void input(int order){//¿¿ ¿¿
	if(order % 2 == 0){//¿¿ ¿¿ ¿¿
		for(i = 0; i <= 50; i++){
			scanf("%c", &num[order][i]);
			if(num[order][i] == '.'){//¿¿¿ ¿¿ ¿¿
				for(d = 0; d <= 9; d++){
					scanf("%c", &dec[order][d]);
					if(dec[order][d] == ' ' || dec[order][d] == '\n')
						break;
				}
				break;
			}
			if(num[order][i] == ' ' || num[order][i] == '\n')//¿¿¿ ¿¿¿¿¿
				break;
		}
	}
	else//¿¿¿ ¿¿
		scanf("%c ", &num[order][0]);
}
void addition(int or){
	for(r1 = 10; r1 >= 9; r1--){
		for(int sh = 50; sh >= 0; sh--){
			num[r1][sh] = num[or-1][k];
			k++;
		}
		for(int dh = 10; dh >= 0; dh--){
			dec[r1][dh] = dec[or-1][k];
			k++;
		}
		if(r1 == 10)
			or += 2;
	}
	for(sh = 50; sh >= 0; sh--){
		num[r3][sh] = (num[10][sh] + num[9][sh]) % 10;
		num[r3][sh-1] += (num[10][sh] + num[9][sh]) / 10;
	}
	for(dh = 10; dh >= 0; dh--){
		dec[r3][dh] = (dec[or-1][dh] + dec[or+1][dh]) % 10;
		if(dh = 10)
			num[r3][49] += (dec[or-1][dh] + dec[or+1][dh]) / 10;
		if(dh < 10)
			dec[r3][dh-1] += (dec[or-1][dh] + dec[or+1][dh]) / 10;
	}

	or -= 2;
	for(sh = 50; sh >= 0; sh--){
		int i = 0;
		num[or-1][i] = num[r3][sh];
		num[or+1][i] = num[r3][sh];
		i++;
	}
	for(dh = 10; dh >= 0; dh--){
		int d = 0;
		dec[or-1][d] = dec[r3][dh];
		dec[or+1][d] = dec[r3][dh];
		d++;
	}
}
int main()
{
	printf("(input) ");
	for(order = 0; order < 9; order++){
		input(order);
		if(d < 0 && num[order][i] == '\n'){
			break;
		}
		else if(dec[order][d] == '\n'){
			break;
		}
	}
	for(or = 1; or <= order; or += 2){
		if(or > order)
			break;//¿¿¿¿ ¿¿
		switch(num[or][0]){
			case '+':
				addition(or);
				break;
			default :
				break;
		}
	}
	printf("= ");
	comma(i, d, order);
	return 0;
}
