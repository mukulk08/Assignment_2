Name: Mukul M
USN: 1PI12IS059
Q.NO:1
Q.Title: Calculating the net profit or loss from a .csv file containing the selling price and cost price of all the items.

     The source code files that are being submitted are assn_2.c and cal.csv.
     The instructions to be followed while executing the code are 
        1) compile the program using gcc assn_2.c
        2) ./a.out -f cal.csv -l log.txt
     
     log.txt is the any log file that will be created on execution.
        The file is being processed character by character and the logic is that the characters after the first comma is encountered are stored in an array and this is converted into an integer using a standard function atoi().The next number is extracted in a similar way till the \n is encountered.This gives CP and SP .Every time the CP and SP value gets added to the previous values.Finally the values of CP and SP are subtracted to give whether it is profit or loss. 
