#include<stdio.h>

void knapsack(int,float[],float[],float[],int);

int main()
{
    float weight[20],profit[20],ratio[20],temp;
    int capacity,num;

    printf("Enter the number of objects:\n");
    scanf("%d",&num);

    printf("Enter the weight and the respecive profit of the objects:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%f%f",&weight[i],&profit[i]);
    }

    printf("Enter the capacity of the knapsack:");
    scanf("%d",&capacity);

    for(int i=0;i<num;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }



    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;
                
                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;
            }
        }
    }

    knapsack(num,weight,profit,ratio,capacity);

    return 0;
}

void knapsack(int num,float weight[num],float profit[num],float ratio[num],int capacity)
{
    float prf=0.0,x[num];
    int i;

    for (i = 0; i < num; i++)
      x[i] = 0.0;

    for(i=0;i<num;i++)
    {
        if(weight[i]>capacity)
        break;
        else
        {
            x[i]=1;
            capacity=capacity-weight[i];
            prf=prf + profit[i];
        }
    }
    if(i<num)
    {
        x[i]=capacity/weight[i];
        
    }
    prf = prf + (x[i]*profit[i]);

    printf("The result vector is:\n");
    for(i=0;i<num;i++)
    {
        printf("%f\t",x[i]);
    }

    printf("\nThe maximum profit is: %f",prf);
    
}