/*
USN: 1PI12IS059,1PI12IS069
Q.NO:1
Q.Title: Calculating the net profit or loss from a .csv file containing the selling price and cost price of all the items.

  Functions: 
  				getopt()
            	fgetc()
  				gettime()
             	atoi()
             	
  Parameters: argval1 and argval2 are the two parameters that are accepted from the user which are the .csv and log files.
*/


 // header files
#include <stdio.h>
#include<time.h>
#include<unistd.h>
char timebuf[50];
int gettime();


// main function


int main (int argc,char *argv[])
{
   int k;
   char *argval1=NULL;
   char *argval2=NULL;
   while((k=getopt(argc,argv,"f:l:"))!=-1)
   switch(k)
    {
      case 'f': argval1=optarg;
                 break;
      case 'l': argval2=optarg;
                 break;

       default:
              printf(" INVALID ARGUMENTS \n");
               return 1;
     }
   	FILE *logfile = fopen(argval2, "a" );
    FILE *fp;
   	int c;
   	int ret;
   	char buf[30];
	int cp, sp,i,j;
	int tot_cp=0;
	int tot_sp=0;
	char co[99],so[99];
	char char1;
	int result;
		if(argc != 1)
		{
          printf( "Filename: %s \n", argval1 );
        }
    	
    	
    	
   fp = fopen(argval1,"r");
   if(fp == NULL)
   {
      printf("Error in opening file \n");
      return(-1);
   }
while(1)
{
	c = fgetc(fp);
	if(c==EOF)
	break;
	if(c==',')
	{	
		i=0;
  		do{
      		   c = fgetc(fp);
      	       	   co[i]=c;
		   i++;
    		   } while(c!=',');		
      			
      			cp=atoi(co);
				tot_cp=tot_cp+cp;		
		
                j=0;
  		do
  		{
      		 c = fgetc(fp);
      		 so[j]=c;
		  	 j++;
    	 }while(c!='\n');
    	 		
      		   sp=atoi(so);
    		   tot_sp=tot_sp+sp;	
		
	}

}


/**checking if its profit **/


if(tot_sp > tot_cp)
	{
	  	ret=gettime();
		
		   FILE *fp1;
         fp1=fopen(argval1,"r");
          while(1)
           {
             char1=fgetc(fp1);
             if(char1==EOF)
               {
                 break;
                }
              fprintf(logfile,"%c",char1);
           }		
		fprintf(logfile, "%s net profit = %d \n\n\n\n\n\n", timebuf, tot_sp-tot_cp);
		printf("net profit = %d \n", tot_sp-tot_cp);
		
	}
	
	
	
/** checking if its loss **/


else if(tot_cp>tot_sp)
	{
  	ret=gettime();
         FILE *fp1;
         fp1=fopen(argval1,"r");
          while(1)
           {
             char1=fgetc(fp1);
             if(char1==EOF)
               {
                 break;
                }
              fprintf(logfile,"%c",char1);
            }

		fprintf(logfile, "%s net loss = %d \n\n\n\n\n\n", timebuf, tot_cp-tot_sp);
		printf(" net loss = %d \n", tot_cp-tot_sp);
	 }
		else
        {
   	 		ret=gettime();
			fprintf(logfile, "%s net loss or profit= %d\n\n\n\n\n\n", timebuf, tot_cp-tot_sp);
			printf(" net loss or profit = %d", tot_cp-tot_sp);
        }
	
      
   fclose(fp);
   return(0);
}


/** function to get the system's local time  by using <time.h> **/


        	int gettime()
        	{	
    			time_t timer;
    			struct tm* tm_info;
   				time(&timer);
    			tm_info = localtime(&timer);
    			strftime(timebuf, 25, "[%d:%m:%Y %H:%M:%S]", tm_info);
    			return 0;
   		    }
