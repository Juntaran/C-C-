#include <stdio.h>

int cal_score( int *score, int *judge_type, int n )
{
    double sum  = 0;
    double sum1 = 0;
    double sum2 = 0;
    int result = 0;

    int a = 0;		//专家人数
    int b = 0;		//大众人数

    if( n && score && judge_type )
    {

        int i;
        for( i=0; i<n; i++ )
        {
            switch(judge_type[i])
            {
            case 1:
                sum1 += score[i];
                a++;
                break;
            case 2:
                sum2 += score[i];
                b++;
                break;
            }
        }
        if( a==0 )
        {
            sum = sum2/b;
        }
        else if( b==0 )
        {
            sum = sum1/a;
        }
        else
        {
            sum = 0.6*sum1/a + 0.4*sum2/b;
        }
        result = (int)(sum+0.5);			//总分取整，四舍五入
    }
	
    return result;
}

int main()
{
    int n = 4;
    int score[] = {1,2,3,4};
    int judge_type[] = {1,2,2,1};
    int ret = cal_score( score, judge_type, n );
    printf("result is %d\n",ret);
    return 0;
}