#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct train
{
    char Set[75];
    float bias,x,y,out;
}tSet[100];

struct in
{
    char Set[75];
    float in1,in2;
}data[50];

int main(void){
    // Your code here!
    srand(time(NULL));
    int dim,trainSet,testSet;
    int a=0;
    int i=0,j=0,k=0,m=0,n=0;
    float weight[]={0.56,0.23,0.34,0.66,0.82,0.15,0.29,0.78,0.43,0.91},w[3];
    float net,actual[100],err,val;
    char str1[35],res;
    char *pch1;

    fflush(stdin);
    scanf("%i",&dim);
    //printf("%i\n",dim);
    fflush(stdin);
    scanf("%i",&trainSet);
    //printf("%i\n",trainSet);
    fflush(stdin);
    scanf("%i",&testSet);
    //printf("%i\n",testSet);
    
    fflush(stdin);
    while(i<trainSet)
    {
        scanf("%s",&tSet[i].Set);
        //printf("%s\n",tSet[i].Set);
        tSet[i].bias=1;
        pch1=strtok(tSet[i].Set," ,"); //In this part the string is divided by spaces           
        while(pch1!=NULL)
        {
            if(a==0)
            {
                strcpy(str1,pch1);
                tSet[i].x=atof(str1);
            }
            else
                if(a==1)
                {
                    strcpy(str1,pch1);
                    tSet[i].y=atof(str1);
                }
                else
                    if(a==2)
                    {
                        strcpy(str1,pch1);
                        tSet[i].out=atof(str1);
                    }
            pch1=strtok(NULL," ,");
            a++;
        }
        a=0;
        i++;
    }
    
    while(scanf("%s",&data[k].Set)!=EOF)
    {
        pch1=strtok(data[k].Set," ,"); //In this part the string is divided by spaces           
        while(pch1!=NULL)
        {
            if(a==0)
            {
                strcpy(str1,pch1);
                data[k].in1=atof(str1);
            }
            else
                if(a==1)
                {
                    strcpy(str1,pch1);
                    data[k].in2=atof(str1);
                }
            pch1=strtok(NULL," ,");
            a++;
        }
        a=0;
        k++;
    }
    
    /*for(j=0;j<trainSet;j++)
        printf("%.1f %.1f %.1f\n",tSet[j].x,tSet[j].y,tSet[j].out);
    
    for(j=0;j<k;j++)
        printf("%.1f %.1f\n",data[j].in1,data[j].in2);*/
    
    for(j=0;j<3;j++)
        w[j]=weight[rand()%11];
    
    /*for(j=0;j<3;j++)
        printf("%.2f\t",w[j]);*/
    
    net=0;
    err=0;
    
    do
    {
        n=0;
        for(m=0;m<trainSet;m++)
        {
            net=net+w[0]*tSet[m].bias+w[1]*tSet[m].x+w[2]*tSet[m].y;
            
            if(net>=0)
                actual[m]=1;
            else
                actual[m]=0;
                
            err=tSet[m].out-actual[m];
            
            w[0]=w[0]+err*tSet[0].bias;
            w[1]=w[1]+err*tSet[1].x;
            w[2]=w[2]+err*tSet[2].y;
            
            if(actual[m]==tSet[m].out)
                n++;
        }
    }while(n!=trainSet);
    
    for(j=0;j<testSet;j++)
    {
        val=w[0]+w[1]*data[j].in1+w[2]*data[j].in2;
        if(val>=0)
            res='1';
        else
            res='0';
        printf("%c\n",res);
    }
    
    return 0;
}

