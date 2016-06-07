#include <stdio.h>
double cal(int num1, char op, int num2);//Input1.
int main (void)
{
	int num1, num2;
	double res[50];
	double sto;//값 저장공간
	char op;//연산기호

	int ch;
	int i;
	printf("I am 도형\n");
	ch = getchar();//수식입력
	char op2 [100] = {"ch"};
	char res2 [50] = {"ch2"};//연산자 저장공간
	int a = -1;//res2 []안 숫자
	int a2 = -1;//res []안 숫자
	char left [50];//연산자 좌항
    char right [50];//연산자 우항

	for(i=0;i<100;i++)
	{
		switch(op2[i])
		{
			case '+':
				{
					res2[a+=1]='+';
					left[a+=1]='op2[i-1]'+48;
					right[a+=1]='op2[i+1]'+48;
					//?
					op2[i-1], op[i+1] = '\0';
				}
					break;
			case '-':
				{
					res2[a+=1]='-';
					left[a+=1]='op2[i-1]'+48;
					right[a+=1]='op2[i+1]'+48;
					op2[i-1], op[i+1] = '\0';
				}
					break;
			case '*':
				{
					res2[a+=1]='*';
					left[a+=1]='op2[i-1]'+48;
					right[a+=1]='op2[i+1]'+48;
					op2[i-1], op[i+1] = '\0';
				}
					break;
			case '/':
				{
					res2[a+=1]='/';
					left[a+=1]='op2[i-1]'+48;
					right[a+=1]='op2[i+1]'+48;
					op2[i-1], op[i+1] = '\0';
				}
					break;
			case '%':
				{
					res2[a+=1]='%';
					left[a+=1]='op2[i-1]'+48;
					right[a+=1]='op2[i+1]'+48;
					op2[i-1], op[i+1] = '\0';
				}
					break;

		}//입력된 수식 내 연산자 순서대로 저장(res2) = cal 함수 실행 횟수
		 //연산자의 좌항 우항 구함.
	}
//_______________________________________________________________
	for(i=0;i<50;i++)
{
	switch(res2[i])
	{
		case '*': 
			{
			    res2[i] = '\0';
			    res[a2+=1] = cal(left[i],*,right[i]);break;
			}
		case '/': 
			{
			    res2[i] = '\0';
			    res[a2+=1] = cal(left[i],*,right[i]);break;
			}
		case '%': 
			{
			    res2[i] = '\0';
			    res[a2+=1] = cal(left[i],*,right[i]);break;
			}
	}
}


	return 0;
}
//___________________________________________________________
//
//Input 1 함수
//___________________________________________________________
double cal(int num1, char op, int num2)
{
	int res;

	switch(op)//문자열을 수식으로 변환
	{
		case '+': res = num1 + num2; break;
		case '-': res = num1 - num2; break;
	    case '*': res = num1 * num2; break;
	    case '/': res = num1 / num2; break;
	    case '%': res = num1 % num2; break;
	    //default : res = ;
	}

	return res;
}
