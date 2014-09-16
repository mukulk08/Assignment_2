Name: Mukul M
USN: 1PI12IS059
Q.NO:1
Q.Title: Calculating the net profit or loss from a .csv file containing the selling price and cost price of all the items based on either used or unused.(modified)

     The source code files that are being submitted are assn_2.c and cal.csv.
     The instructions to be followed while executing the code are 
        1) compile the program using gcc assn_2.c
        2) ./a.out -f call.csv -l log.txt
     
     log.txt is the any log file that will be created on execution.
        The file is being processed character by character and the logic is that the characters after the first comma is encountered are stored in an array and this is converted into an integer using a standard function atoi().The next number is extracted in a similar way till the next comma is encountered.This gives CP and SP .After this the next word is taken into an array of characters.Then the second letter in used or unused is compared with either 's' if used or 'n' if unused.Based on the comparison ,the computation is done differently.Every time the CP and SP value gets added to the previous values in their respective used or unused blocks.Finally the values of CP and SP are subtracted to give whether it is profit or loss. 
