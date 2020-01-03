# -*- coding: utf-8 -*-
"""
Created on Thu May 24 19:39:16 2018

@author: huwenqing
"""
#The replace table is below
replace=[['\\play','\\displaystyle'],
         ['\\li','\\limits'],
         ['\\pt','\\partial'],
         ['\\ra','\\rightarrow'],
         ['\\da','\\downarrow'],
         ['\\Prob','\\mathbf{P}'],
         ['\\E','\\mathbf{E}'],
         ['\\Var','\\mathbf{Var}'],
         ['\\Cov','\\mathbf{Cov}'],
         ['\\al','\\alpha'],
         ['\\bt','\\beta'],
         ['\\gm','\\gamma'],
         ['\\Gm','\\Gamma'],
         ['\\dt','\\delta'],
         ['\\Dt','\\Delta'],
         ['\\ve','\\varepsilon'],
         ['\\tht','\\theta'],
         ['\\Tht','\\Theta'],
         ['\\ththat','\\widehat{\\theta}_n'],
         ['\\kp','\\kappa'],
         ['\\lb','\\lambda'],
         ['\\Lb','\\Lambda'],
         ['\\sm','\\sigma'],
         ['\\Sm','\\Sigma'],
         ['\\om','\\omega'],
         ['\\Om', '\\Omega'],
         ['\\zt','\\zeta'],
         ['\\A','\\mathbb{A}'],
         ['\\C','\\mathbb{C}'],
         ['\\Half','\\mathbb{H}'],
         ['\\N','\\mathbb{N}'],
         ['\\R','\\mathbb{R}'],
         ['\\T','\\mathbb{T}'],
         ['\\Z','\\mathbb{Z}'],
         ['\\cA','\\mathcal{A}'],
         ['\\cB','\\mathcal{B}'],
         ['\\cC','\\mathcal{C}'],
         ['\\cD','\\mathcal{D}'],
         ['\\cE','\\mathcal{E}'],
         ['\\cF','\\mathcal{F}'],
         ['\\cG','\\mathcal{G}'],
         ['\\cH','\\mathcal{H}'],
         ['\\cI','\\mathcal{I}'],
         ['\\cK','\\mathcal{K}'],
         ['\\cL','\\mathcal{L}'],
         ['\\cM','\\mathcal{M}'],
         ['\\cN','\\mathcal{N}'], 
         ['\\cO','\\mathcal{O}'],
         ['\\cP','\\mathcal{P}'],
         ['\\cQ','\\mathcal{Q}'],
         ['\\cR','\\mathcal{R}'],
         ['\\cS','\\mathcal{S}'],
         ['\\cT','\\mathcal{T}'],
         ['\\cU','\\mathcal{U}'],
         ['\\cV','\\mathcal{V}'],
         ['\\cW','\\mathcal{W}'],
         ['\\cX','\\mathcal{X}'],
         ['\\cY','\\mathcal{Y}'],
         ['\\cZ','\\mathcal{Z}'],
         ['\\cu','\\mathcal{u}'],
         ['\\rH','\\mathscr{H}'],
         ['\\rL','\\mathscr{L}'],
         ['\\rF','\\mathscr{F}'],
         ['\\rmY','\\mathrm{Y}'],
         ['\\rmP','\\mathrm{P}'],
         ['\\ig','\\mathfrak{g}'],
         ['\\iY','\\mathfrak{Y}'],
         ['\\iiY','\\mathbf{\\mathfrak{Y}}'],
         ['\\X','\\mathbf{X}'],
         ['\\hX','\\widehat{X}'],
         ['\\hY','\\widehat{Y}'],
         ['\\Xbar','\\bar{X}'],
         ['\\cPhi','\\mathbf{\\Phi}'],
         ['\\1','\\mathbf{1}'],
         ['\\contfunc','\\mathbf{C}'],
         ['\\contfuncGm','\\mathbf{C}_{[0,\\infty)}(\\Gamma)'],
         ['\\contfuncz','\\mathbf{C}_{[0,\\infty)}(\\Gamma(z))'],
         ['\\contfuncopenbook','\\mathbf{C}_{[0,\\infty)}(\\mathbf{\\Gamma})'],
         ['\\contfuncR','\\mathbf{C}_{[0,T]}(\\mathbb{R})'],
         ['\\contfuncRslash','\\mathbf{C}_{[0,T]}(\\mathbb{R}\\backslash(-1,1))'],
         ['\\grad','\\nabla'],
         ['\\openbook','\\mathbf{\Gamma}'],
         ['\\operator','\\overline{\mathbf{L}}'],
         ['\\domain','\\mathbf{D}'],
         ['\\torus','\\mathbb{T}'],
         ['\\boldA','\\boldsymbol{A}'],
         ['\\boldB','\\boldsymbol{B}'],
         ['\\boldC','\\boldsymbol{C}'],
         ['\\boldQ','\\boldsymbol{Q}'],
         ['\\boldR','\\boldsymbol{R}'],
         ['\\boldN','\\boldsymbol{N}'],
         ['\\boldW','\\boldsymbol{W}'],
         ['\\boldX','\\boldsymbol{X}'],
         ['\\boldb','\\boldsymbol{b}'],
         ['\\bolde','\\boldsymbol{e}'],
         ['\\boldf','\\boldsymbol{f}'],
         ['\\boldg','\\boldsymbol{g}'],
         ['\\boldn','\\boldsymbol{n}'],
         ['\\boldp','\\boldsymbol{p}'],
         ['\\boldq','\\boldsymbol{q}'],
         ['\\boldu','\\boldsymbol{u}'],
         ['\\boldx','\\boldsymbol{x}'],
         ['\\boldy','\\boldsymbol{y}'],
         ['\\boldz','\\boldsymbol{z}'],
         ['\\boldal','\\boldsymbol{\\alpha}'],
         ['\\boldbt','\\boldsymbol{\\beta}'],
         ['\\boldgm','\\boldsymbol{\\gamma}'],
         ['\\boldnu','\\boldsymbol{\\nu}'],
         ['\\boldphi','\\boldsymbol{\\varphi}'],
         ['\\fC','\\mathfrak{C}'],
         ['\\fo','\\mathfrak{o}'],
         ['\\vphi','\\varphi'],
         ['\\bbar','\\bar{b}'],
         ['\\gbar','\\bar{g}'],
         ['\\Vbar','\\overline{V}'],
         ['\\boldXhat','\\widehat{\\boldsymbol{X}'],
         ['\\Xhat','\\widehat{X}'],
         ['\\Zhat','\\widehat{Z}'],
         ['\Atilde','\\widetilde{A}'],
         ['\\Ylow','Y_{\\text{low}}'],
         ['\\spaceX','\\mathcal{X}'],
         ['\\transitionP','\\mathcal{P}'],
         ['\\xsaddle','x_{\\text{saddle}}'],
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
