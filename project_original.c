#include <stdio.h>
#include <stdlib.h>
char num[12][50], dec[12][9];
int i, d = -1;
int order = 0;
int ord;
int r1, r2, r3 = 11;
int sh, dh, k;
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
void input(int order){
	if(order % 2 == 0){
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
	else
		scanf("%c ", &num[order][0]);
}
void put_back(int ord, int ip, int dp){
	if(dp == 10){
		for(r1 = 10; r1 >= 9; r1--){
			k = 0;
			for(int sh = 50 - ip; sh <= 50; sh++){
				num[r1][sh] = num[ord-1][k];
				k++;
			}
			if(r1 == 10)
				ord += 2;
			if(r1 == 9)
				ord -= 2;
		}}
	else{
		for(r1 = 10; r1 >= 9; r1--){
			k = 0;
			for(int sh = 50 - ip; sh <= 50; sh++){
				num[r1][sh] = num[ord-1][k];
				k++;
			}
			k = 0;
			for(int dh = 10 - dp; dh <= 10; dh++){
				dec[r1][dh] = dec[ord-1][k];
				k++;
			}
			if(r1 == 10)
				ord += 2;
			if(r1 == 9)
				ord -= 2;
		}}
}
int int_place(int ord){
	int l = 0, p = 1;
	while(p <= 49){
		if(num[ord][l] == ' ' || num[ord][l] == '\n' || num[ord][l] == '.')
			break;
		p++;
		l++;
	}
	return p;
}
int dec_place(int ord){
	int l, c = 1;
	while(c <= 9){
		if(dec[ord][l] == ' ' || dec[ord][l] == '\n')
			break;
		c++;
		l++;
	}
	return c;
}

void put_again(int ord, int ip, int dp){
	for(sh = 49; sh >= 0; sh--){
		int i = 0;
		num[ord-1][i] = num[r3][sh];
		num[ord+1][i] = num[r3][sh];
		i++;
	}
	for(dh = 10; dh >= 0; dh--){
		int d = 0;
		dec[ord-1][d] = dec[r3][dh];
		dec[ord+1][d] = dec[r3][dh];
		d++;
	}
}
void addition(int ord, int ip, int dp){
	for(sh = 49; sh >= 0; sh--){
		num[r3][sh] = (num[10][sh] + num[9][sh]) % 10;
		num[r3][sh-1] += (num[10][sh] + num[9][sh]) / 10;
	}
	for(dh = 0; dh < 9; dh++){
		dec[r3][dh] = (dec[ord-1][dh] + dec[ord+1][dh]) % 10;
		if(dh == 0)
			num[r3][49] += (dec[ord-1][0] + dec[ord+1][0]) / 10;
		else
			dec[r3][dh-1] += (dec[ord-1][dh] + dec[ord+1][dh]) / 10;
	}
}		
int main()
{
	printf("(input) ");
	for(order = 0; order < 9; order++){
		input(order);
			printf("%d %d\n", int_place(order), dec_place(order));
		if(d < 0 && num[order][i] == '\n'){
			break;
		}
		else if(dec[order][d] == '\n'){
			break;
		}
	}
	for(ord = 1; ord <= order; ord += 2){
		if(ord > order)
			break;
		switch(num[ord][0]){
			case '+':
				put_back(ord, int_place(ord-1), dec_place(ord-1));
				addition(ord, int_place(ord-1), dec_place(ord-1));
				put_again(ord, int_place(ord-1), dec_place(ord-1));
				break;
			default :
				printf("ERROR\n");
				break;
		}
	}
	printf("= ");
	return 0;
}
