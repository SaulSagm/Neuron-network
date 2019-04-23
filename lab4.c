#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct train    //Structure for the training Set with its bias, two inputs and
{               //the output desired
    char Set[75];
    float bias,x,y,out;
}tSet[100];

struct in       //Structure with the testing input data.
{
    char Set[75];
    float in1,in2;
}data[50];

int main(void){
    // Your code here!
    srand(time(NULL));  //Random initialization
    int dim,trainSet,testSet;   //Input variables
    int a=0;
    int i=0,j=0,k=0,m=0,n=0,res,epoch;    //Counters
    float weight[]={0.56,0.23,0.34,0.66,0.82,0.15,0.29,0.78,0.43,0.91},w[3];    //Weights
    float net,actual[100],err,val;  //Variables for calculations
    char str1[35];
    char *pch1;

    fflush(stdin);      //Input variables for dimensionality, training Set
    scanf("%i",&dim);   //and testing Set
    fflush(stdin);
    scanf("%i",&trainSet);
    fflush(stdin);
    scanf("%i",&testSet);

    fflush(stdin);
    while(i<trainSet)
    {
        scanf("%s",&tSet[i].Set);
        //printf("%s\n",tSet[i].Set);
        tSet[i].bias=1;
        pch1=strtok(tSet[i].Set," ,;");  //In this part the string is divided by            
        while(pch1!=NULL)               //comas and spaces so each input and    
        {                               //output is saved separately
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
            pch1=strtok(NULL," ,;");
            a++;
        }
        a=0;
        i++;
    }
    
    while(scanf("%s",&data[k].Set)!=EOF)    
    {
        pch1=strtok(data[k].Set," ,;");  //In this part the string is divided by           
        while(pch1!=NULL)               //comas and spaces so each input and
        {                               //output is saved separately
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
            pch1=strtok(NULL," ,;");
            a++;
        }
        a=0;
        k++;
    }
    
    for(j=0;j<3;j++)
        w[j]=weight[rand()%10]; //Initialize randomly the value of the weights
    
    net=0;
    err=0;
    epoch=0;
    
    do  //Training function
    {
        n=0;
        for(m=0;m<trainSet;m++)
        {
            net=net+w[0]*tSet[m].bias+w[1]*tSet[m].x+w[2]*tSet[m].y;    //Sum
            
            if(net>=0)
                actual[m]=1;
            else
                actual[m]=0;
                
            err=tSet[m].out-actual[m];
            
            w[0]=w[0]+err*tSet[0].bias; //Correction of the weight
            w[1]=w[1]+err*tSet[1].x;
            w[2]=w[2]+err*tSet[2].y;
            
            if(actual[m]==tSet[m].out)  //When the desired output is right
                n++;                    //it'll sum 
        }
        epoch++;
    }while(n!=trainSet && epoch<=300);    //It'll stop when the sum is equal to the train Set orwhen it had
                                                              //reached a certain number of repetition so it won't be trapped
    if(epoch>=300 && n!=trainSet)         //in an infinite loop
    {
        printf("no solution found\n");
    }
    else
    {
        for(j=0;j<testSet;j++)
        {
            val=w[0]+w[1]*data[j].in1+w[2]*data[j].in2; //Evaluating the inputs
            if(val>=0)
                res=1;  //If its positive the output is 1
            else
                res=0;  //If its negative the output is 0
            printf("%i\n",res);
        }
    }
    printf("%.3f %.3f %.3f\n",w[0],w[1],w[2]);
    
    return 0;

}
