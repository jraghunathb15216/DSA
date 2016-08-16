#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(int argc,char *argv[ ])
{
	int i, j;
	int row, col;
	printf("done\n");
	if(argv[1][0]=='1')                                   //ROW AND COLUMN SELECTION USING COMMAND LINE ARGUEMENT
    {
    	row =198;
    	col=200;
    }
    else if(argv[1][0]=='2')
    {
    	row=1920;
    	col=1200;
    }
    else if(argv[1][0]=='3')
    {
    	row=10967;
    	col=10004;
    }
    printf("row=%d\tcol=%d\n",row,col);               // 2-D ARRAY ALLOCATION
    int **array;
    array=(int* *)malloc(row*sizeof(int *));
    int m=0;
    for(m=0;m<row;m++)
    	array[m]=(int *)malloc(col*sizeof(int));
	printf("printing the values\n");			
	FILE *fp;
	FILE *result;
	result = fopen("result1.dat","w");                  // FILE POINTER INTIALIAZATION
	int temp;
	double t=clock();
	printf("Reading the input data .........\n");
	fp = fopen(argv[1],"r");
	i=0;j=0;
	long int freq[256]={0};                          // READING AND STORAGE OF ELEMENT IN 2-D ARRAY
	while(fscanf(fp,"%d",&temp)==1)
	{
		freq[temp]++;
		array[i][j]=temp;
        j++;
        if(j==col)
        {
        	j=0;
        	i++;
        }
    }
	t=clock()-t;
	double time_taken = t / CLOCKS_PER_SEC;
	printf("Data read in %f ms\n", time_taken);          //READING FROM FILE DONE 
	int k=0;
	long int cummulative[256]={0};
	long int sum=0;
	for(i=0;i<256;i++)                                 //
	{
		printf("%ld\n",freq[i]);

	}
	for(i=0;i<256;i++)
	{
		sum=sum+freq[i]*i;
	}
	long int cum=0;
	for(i=0;i<256;i++)
	{
       cum=cum+freq[i];
       cummulative[i]=cum;

	}
	t=clock();
    long double mean_a=0,mean_b=0,dev_a=0,dev_b=0;  //THRESHOLDING THROUGH HISTOGRAM STARTS
    for(i=1;i<256;i++)
    {
    	int j;

    	for(j=0;j<=i;j++)
    	{
    		mean_a=mean_a+freq[i]*i;
    		mean_a=mean_a/cummulative[i];

    	}
    	for(j=i+1;j<=255;j++)
    	{
    		mean_b=mean_b+freq[i]*i;
    		mean_b=mean_b/(cummulative[255]-cummulative[i]);
    	}
    	for(j=0;j<=i;j++)
    	{
           dev_a=dev_b+(freq[i]*i-mean_a)*(freq[i]*i-mean_a);
           dev_a=dev_a/cummulative[i];
    	}
    	dev_a=sqrt(dev_a);
    	for(j=i+1;j<=255;j++)
    	{
           dev_b=dev_b+(long double)(i-mean_a)*(long double)(i-mean_a)*(long double)freq[i];
           dev_b=dev_b/(cummulative[255]-cummulative[i]);
    	}
    	dev_b=sqrt(dev_b);
        //printf("mean_a=%Lf\t\tmean_b=%Lf\n",mean_a,mean_b);
        long double dis=0;
        dis=fabsl(mean_a-mean_b)/sqrt(dev_a*dev_a+dev_b*dev_b);
        long double n=0;
        n=(double)cummulative[i]/(cummulative[255]-cummulative[i]);
        printf("np=%Lfmean_a=%Lfmean_b=%Lfdis=%Lf\n",n,mean_a,mean_b,dis);
        if(!(cummulative[255]-cummulative[i]))
        	dis=-1,n=-1;
        fprintf(result,"%d\t%Lf\t%Lf\n",i,dis,n);
    }
    t=t-clock();
    time_taken=t/CLOCKS_PER_SEC;
    printf("Data read in %f ms\n", time_taken); //THRESHOLDING THROUGH HISTOGRAM DONE 
    fclose(result);
    fclose(fp);
    FILE *gnuplot;
    gnuplot=popen("gnuplot -persistent","w");
    char *cmd[ ]={"set term postscript ","set ouput 'a.eps'","set output 'b.eps'","set output 'c.eps'","plot 'result.txt' using 1:2 with lines","plot 'result.txt' 1:3 with lines","plot 'result.txt' 2:3 with lines"};
    fprintf(gnuplot,"%s",cmd[0]);
    fprintf(gnuplot,"%s",cmd[1]);
    fprintf(gnuplot,"%s",cmd[4]);
    fprintf(gnuplot,"%s",cmd[2]);
    fprintf(gnuplot,"%s",cmd[5]);
    fprintf(gnuplot,"%s",cmd[3]);
    fprintf(gnuplot,"%s",cmd[6]);
	printf("done\n");
}