#include <stdio.h>
#include <string.h>

int main(void)
{
	char num1_1[1024]={0},num2_1[1024]={0};
	char num1_2[1024]={0},num2_2[1024]={0};
	char num3[1024]={0};
	int len,i,plus=0,tmp;
	int cnt1=0,cnt2=0;

	printf("첫번째입력:");
	scanf("%s", num1_1);
	printf("두번째입력:");
	scanf("%s", num2_1);

	for(i=0;num1_1[i]!='\0';i++)
		cnt1++;

	for(i=0;num2_1[i]!='\0';i++)
		cnt2++;

	if(cnt1>cnt2)
		len=cnt1;
	else
		len=cnt2;
	//헤이 모두들 안녕 내가 누군지아늬?동유늬다!동유늬다!
	//난 소프트웨어에서 가장 빛나는별 ★
	for(i=0;i<cnt1;i++)
	{
		num1_2[cnt1-1-i]=num1_1[i];
	}

	for(i=0;i<cnt2;i++)
	{
		num2_2[cnt2-1-i]=num2_1[i];
	}

	for(i=0;i<cnt1;i++)
	{
		if(num1_2[i]==0)
				num1_2[i]=0;
		else num1_2[i]-='0';
	}

	for(i=0;i<cnt2;i++)
	{
		if(num2_2[i]==0)
			num2_2[i]=0;
		else
			num2_2[i]-='0';
	}

	for(i=0;i<=len;i++)
	{
		num3[i]=(num1_2[i]+num2_2[i]+plus)%10;
		num3[i]+='0';


		if((num1_2[i]+num2_2[i]+plus)>9)
			plus=1;

		else
			plus=0;
	}

	if(num3[len]=='0')
		num3[len]=0;
		printf("%c",num3[i]);

	return 0;
}
				

