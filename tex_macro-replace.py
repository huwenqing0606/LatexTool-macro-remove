# -*- coding: utf-8 -*-
"""
Created on Thu May 24 19:39:16 2018

@author: Wenqing Hu (Missouri S&T)

the file is to illustrate the structure of the code, with explicit comments
in practice we translate this to C file and obtain exe files to work
"""

#The replace table is below
replace=[['\\play','\\displaystyle'],
         ['\\diag','\\text{diag}']]

import os

old = open('test1.txt','rb')    #open the file to read in binary mode
new = open('test2.txt','w')     #open the file to write

oldpointer=old.read(1)  #oldpointer points to the beginning of the old file 
indicator=0             #the indicator indicates whether we have a latex command starting with \...

while (oldpointer.decode()!=''):        #if the oldpointer is not pointing to the end of the old file
    if (oldpointer.decode()=='\\' and indicator==0):     #check if oldpointer is pointing to a latex command, note that this must happen when a prior latex command is finished (indiactor=0)
        indicator=1                     #if yes, then indicator is turned on to 1
        oldword='\\'                    #starting to record this command
        oldpointer=old.read(1)          
    if (indicator==1):                  #if the command indicator is on
        if  ((ord(oldpointer.decode())>=65 and ord(oldpointer.decode())<=90) 
                or (ord(oldpointer.decode())>=97 and ord(oldpointer.decode())<=122)):
            oldword+=oldpointer.decode()    #if the command is not finished, keep writing it into oldword
        else:
            indicator=0         #otherwise the command is finished, so we turn off the command indicator to 0
            newword=''          #initialize the newword that is to replace the old word
            for macrosearch in replace: #browse the replace table and see if the command with oldword is in the table
                if (macrosearch[0]==oldword):   #if yes, then write the corresponding newword into text2.txt 
                    newword=macrosearch[1]
                    new.write(newword)          
            if (newword==''):       #if no such correapondence is found in the replace table
                new.write(oldword)  #simply write the old command into text2.txt 
            old.seek(-1,os.SEEK_CUR) #move the oldpointer back 1 step to initialize the consequtive reading of text1.txt
    else: #if the command indicator is off at 0, that means we are working with a character that is not in a latex command
        if (oldpointer.decode()!='\n'): #if not end of a line
            new.write(oldpointer.decode()) #simply write the character pointed by the oldpointer (decode it from binary) into text2.txt 
    oldpointer=old.read(1) #oldpointer moves to the next position in text1.txt   
    
new.write(oldword)

old.close() #close old
new.close() #close new
