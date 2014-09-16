/*
USN: 1PI12IS059,1PI12IS069
Q.NO:1
Q.Title: Calculating the net profit or loss from a .csv file containing the selling price and cost price of all the items.

  Functions: gettime()
             getopt()
             fgetc()
             atoi()
  Parameters: argval1 and argval2 are the two parameters that are accepted from the user which are the .csv and log files.
*/


/** header files **/


#include <stdio.h>
#include<time.h>
#include<unistd.h>
char timebuf[50];
int gettime();

/** main function **/

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
int cp,sp;
int used_cp, used_sp,unused_cp, unused_sp,i,j,z;
int tot_used_cp=0;
int tot_unused_cp=0;
int tot_used_sp=0;
int tot_unused_sp=0;
char co[99],so[99],ty[999];
char char1;
int result;
		if(argc != 1)
		{
        		 printf( "Filename: %s \n", argval1 );
    	        }
    	
    	
    	
   fp = fopen(argval1,"r");
   if(fp == NULL)
   {
      printf("Error in opening file");
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
  			do
  			{
      		   c = fgetc(fp);
      	       	   co[i]=c;
		   			i++;
    		   }while(c!=',');	
    		   	
      		cp=atoi(co);		
                j=0;
                
  		do
  		{
      		   c = fgetc(fp);
      		   so[j]=c;
		  	    j++;
    	}while(c!=',');	
    		
      		   sp=atoi(so);
                z=0;
                
                   do
                   {
      		   			c = fgetc(fp);
      		   			ty[z]=c;
		   				z++;
    		   	    }while(c!='\n');
    		   	    		
      		   if(ty[2]=='s')
                    {
                       used_cp=cp;
                       used_sp=sp;
    		        	tot_used_cp=tot_used_cp+used_cp;
                        tot_used_sp=tot_used_sp+used_sp;
                    }
                    else if(ty[2]=='n')
                    {
                       unused_cp=cp;
                       unused_sp=sp;
    		        	tot_unused_cp=tot_unused_cp+unused_cp;
                        tot_unused_sp=tot_unused_sp+unused_sp;
                    }
                    	
		
	}

}

/** checking for profit in the case of used items **/

if(tot_used_sp > tot_used_cp)
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
		fprintf(logfile, "%s net profit of used items = %d \n\n\n", timebuf, tot_used_sp-tot_used_cp);
		printf("net profit of used items = %d \n", tot_used_sp-tot_used_cp);
		
	}
	
/** checking for loss in the case of used items **/
	
 if(tot_used_cp>tot_used_sp)
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

	fprintf(logfile, "%s net loss = %d \n\n\n", timebuf, tot_used_cp-tot_used_sp);
	printf(" net loss = %d \n", tot_used_cp-tot_used_sp);
	}
 if(tot_used_cp==tot_used_sp)
       {
   	 ret=gettime();
	fprintf(logfile, "%s net loss or profit of the used items= %d\n\n\n\n", timebuf, tot_used_cp-tot_used_sp);
	printf(" net loss or profit of the used items= %d", tot_used_cp-tot_used_sp);
       }
	
/** checking for profit in the case of un-used items **/


    if(tot_unused_sp > tot_unused_cp)
	{
	  	ret=gettime();
		
		   FILE *fp2;
         fp2=fopen(argval1,"r");
      //    while(1)
        //   {
        //     char1=fgetc(fp2);
       //      if(char1==EOF)
       //        {
      //           break;
      //          }
      //        fprintf(logfile,"%c",char1);
       //    }		
		fprintf(logfile, "%s net profit of brand new items= %d \n\n\n\n\n\n", timebuf, tot_unused_sp-tot_unused_cp);
		printf("net profit of brand new items = %d \n", tot_unused_sp-tot_unused_cp);
		
	}
	
/** checking for loss in the case of un-used items **/


 if(tot_unused_cp>tot_unused_sp)
	{
  	ret=gettime();
         FILE *fp2;
         fp2=fopen(argval1,"r");
     //      while(1)
       //    {
         //    char1=fgetc(fp2);
         //    if(char1==EOF)
         //      {
         //        break;
         //       }
        //      fprintf(logfile,"%c",char1);
       //    }

	fprintf(logfile, "%s net loss of brand new items = %d \n\n\n\n\n\n", timebuf, tot_unused_cp-tot_unused_sp);
	printf(" net loss of brand new items = %d \n", tot_unused_cp-tot_unused_sp);
	}
 if(tot_unused_cp==tot_unused_sp)
       {
   	 ret=gettime();
	fprintf(logfile, "%s net loss or profit of the unused items= %d\n\n\n\n\n\n", timebuf, tot_unused_cp-tot_unused_sp);
	printf(" net loss or profit of the unused items= %d", tot_unused_cp-tot_unused_sp);
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
