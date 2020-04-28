/*
 * tex-macro-replace.c
 *	replaces all macros in tex file by original tex command
 *  Created on: 2020年4月26日
 *  Author: Wenqing Hu (Missouri S&T)
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ReplaceTable{
	char macro[100];	/*100 is the maximal size of each macro/its replacement*/
	char original[100];
};

/*the macro replacement table*/
struct ReplaceTable replace[]={
								{"\\play","\\displaystyle"},
								{"\\li","\\limits"},
								{"\\pt","\\partial"},
								{"\\ra","\\rightarrow"},
								{"\\da","\\downarrow"},
								{"\\Prob","\\mathbf{P}"},
								{"\\E","\\mathbf{E}"},
								{"\\Var","\\mathbf{Var}"},
								{"\\Cov","\\mathbf{Cov}"},
        						{"\\One","\\mathbf{1}"},
         						{"\\contfunc","\\mathbf{C}"},
          						{"\\contfuncR","\\mathbf{C}_{[0,T]}(\\mathbb{R})"},
								{"\\A","\\mathbb{A}"},
        						{"\\C","\\mathbb{C}"},
         						{"\\Half","\\mathbb{H}"},
        						{"\\N","\\mathbb{N}"},
        						{"\\R","\\mathbb{R}"},
         						{"\\T","\\mathbb{T}"},
         						{"\\Z","\\mathbb{Z}"},
		         				{"\\al","\\alpha"},
		         				{"\\bt","\\beta"},
		        				{"\\gm","\\gamma"},
		         				{"\\Gm","\\Gamma"},
		         				{"\\dt","\\delta"},
		         				{"\\Dt","\\Delta"},
		         				{"\\ve","\\varepsilon"},
		         				{"\\tht","\\theta"},
		         				{"\\Tht","\\Theta"},
		         				{"\\kp","\\kappa"},
		         				{"\\lb","\\lambda"},
		         				{"\\Lb","\\Lambda"},
		         				{"\\sm","\\sigma"},
		         				{"\\Sm","\\Sigma"},
		         				{"\\om","\\omega"},
		         				{"\\Om","\\Omega"},
		        				{"\\zt","\\zeta"},
         						{"\\vphi","\\varphi"},
         						{"\\grad","\\nabla"},
         						{"\\boldSm","\\boldsymbol{\\Sigma}"},
         						{"\\boldLb","\\boldsymbol{\\Lambda}"},
         						{"\\boldal","\\boldsymbol{\\alpha}"},
         						{"\\boldbt","\\boldsymbol{\\beta}"},
         						{"\\boldgm","\\boldsymbol{\\gamma}"},
         						{"\\boldnu","\\boldsymbol{\\nu}"},
         						{"\\boldphi","\\boldsymbol{\\varphi}"},
         						{"\\cA","\\mathcal{A}"},
         						{"\\cB","\\mathcal{B}"},
         						{"\\cC","\\mathcal{C}"},
         						{"\\cD","\\mathcal{D}"},
        						{"\\cE","\\mathcal{E}"},
         						{"\\cF","\\mathcal{F}"},
         						{"\\cG","\\mathcal{G}"},
         						{"\\cH","\\mathcal{H}"},
        						{"\\cI","\\mathcal{I}"},
        						{"\\cJ","\\mathcal{J}"},
         						{"\\cK","\\mathcal{K}"},
        						{"\\cL","\\mathcal{L}"},
        						{"\\cM","\\mathcal{M}"},
         						{"\\cN","\\mathcal{N}"},
         						{"\\cO","\\mathcal{O}"},
        						{"\\cP","\\mathcal{P}"},
         						{"\\cQ","\\mathcal{Q}"},
         						{"\\cR","\\mathcal{R}"},
        						{"\\cS","\\mathcal{S}"},
        						{"\\cT","\\mathcal{T}"},
	       		 				{"\\cU","\\mathcal{U}"},
        						{"\\cV","\\mathcal{V}"},
         						{"\\cW","\\mathcal{W}"},
         						{"\\cX","\\mathcal{X}"},
         						{"\\cY","\\mathcal{Y}"},
         						{"\\cZ","\\mathcal{Z}"},
        						{"\\ca","\\mathcal{a}"},
        						{"\\cb","\\mathcal{b}"},
        						{"\\cc","\\mathcal{c}"},
        						{"\\cd","\\mathcal{d}"},
        						{"\\ce","\\mathcal{e}"},
        						{"\\cf","\\mathcal{f}"},
        						{"\\cg","\\mathcal{g}"},
        						{"\\ch","\\mathcal{h}"},
        						{"\\ci","\\mathcal{i}"},
        						{"\\cj","\\mathcal{j}"},
        						{"\\ck","\\mathcal{k}"},
        						{"\\cl","\\mathcal{l}"},
        						{"\\cm","\\mathcal{m}"},
        						{"\\cn","\\mathcal{n}"},
        						{"\\co","\\mathcal{o}"},
        						{"\\cp","\\mathcal{p}"},
        						{"\\cq","\\mathcal{q}"},
        						{"\\cr","\\mathcal{r}"},
        						{"\\cs","\\mathcal{s}"},
        						{"\\ct","\\mathcal{t}"},
        						{"\\cu","\\mathcal{u}"},
        						{"\\cv","\\mathcal{v}"},
        						{"\\cw","\\mathcal{w}"},
        						{"\\cx","\\mathcal{x}"},
        						{"\\cy","\\mathcal{y}"},
         						{"\\cz","\\mathcal{z}"},
         						{"\\boldA","\\boldsymbol{A}"},
         						{"\\boldB","\\boldsymbol{B}"},
         						{"\\boldC","\\boldsymbol{C}"},
        						{"\\boldD","\\boldsymbol{D}"},
        						{"\\boldE","\\boldsymbol{E}"},
        						{"\\boldF","\\boldsymbol{F}"},
        						{"\\boldG","\\boldsymbol{G}"},
        						{"\\boldH","\\boldsymbol{H}"},
        						{"\\boldI","\\boldsymbol{I}"},
        						{"\\boldJ","\\boldsymbol{J}"},
         						{"\\boldK","\\boldsymbol{K}"},
         						{"\\boldL","\\boldsymbol{L}"},
         						{"\\boldM","\\boldsymbol{M}"},
         						{"\\boldN","\\boldsymbol{N}"},
         						{"\\boldO","\\boldsymbol{O}"},
         						{"\\boldP","\\boldsymbol{P}"},
         						{"\\boldQ","\\boldsymbol{Q}"},
         						{"\\boldR","\\boldsymbol{R}"},
         						{"\\boldS","\\boldsymbol{S}"},
         						{"\\boldT","\\boldsymbol{T}"},
         						{"\\boldU","\\boldsymbol{U}"},
         						{"\\boldV","\\boldsymbol{V}"},
         						{"\\boldW","\\boldsymbol{W}"},
         						{"\\boldX","\\boldsymbol{X}"},
         						{"\\boldY","\\boldsymbol{Y}"},
         						{"\\boldZ","\\boldsymbol{Z}"},
         						{"\\bolda","\\boldsymbol{a}"},
         						{"\\boldb","\\boldsymbol{b}"},
         						{"\\boldc","\\boldsymbol{c}"},
         						{"\\boldd","\\boldsymbol{d}"},
         						{"\\bolde","\\boldsymbol{e}"},
         						{"\\boldf","\\boldsymbol{f}"},
         						{"\\boldg","\\boldsymbol{g}"},
         						{"\\boldh","\\boldsymbol{h}"},
         						{"\\boldi","\\boldsymbol{i}"},
         						{"\\boldj","\\boldsymbol{j}"},
         						{"\\boldk","\\boldsymbol{k}"},
         						{"\\boldl","\\boldsymbol{l}"},
         						{"\\boldm","\\boldsymbol{m}"},
         						{"\\boldn","\\boldsymbol{n}"},
         						{"\\boldo","\\boldsymbol{o}"},
         						{"\\boldp","\\boldsymbol{p}"},
         						{"\\boldq","\\boldsymbol{q}"},
         						{"\\boldr","\\boldsymbol{r}"},
         						{"\\bolds","\\boldsymbol{s}"},
         						{"\\boldt","\\boldsymbol{t}"},
         						{"\\boldu","\\boldsymbol{u}"},
         						{"\\boldv","\\boldsymbol{v}"},
         						{"\\boldw","\\boldsymbol{w}"},
         						{"\\boldx","\\boldsymbol{x}"},
        	 					{"\\boldy","\\boldsymbol{y}"},
         						{"\\boldz","\\boldsymbol{z}"},
         						{"\\rF","\\mathscr{F}"},
         						{"\\rH","\\mathscr{H}"},
         						{"\\rL","\\mathscr{L}"},
         						{"\\rmF","\\mathrm{F}"},
         						{"\\rmP","\\mathrm{P}"},
         						{"\\rmX","\\mathrm{X}"},
         						{"\\rmY","\\mathrm{Y}"},
        						{"\\ig","\\mathfrak{g}"},
         						{"\\iX","\\mathfrak{X}"},
         						{"\\iY","\\mathfrak{Y}"},
         						{"\\bfP","\\mathbf{P}"},
         						{"\\bfX","\\mathbf{X}"},
								{"\\hatX","\\widehat{X}"},
        						{"\\hatY","\\widehat{Y}"},
        						{"\\hatZ","\\widehat{Z}"},
          						{"\\barb","\\bar{b}"},
         						{"\\barg","\\bar{g}"},
         						{"\\barV","\\bar{V}"},
         						{"\\barX","\\bar{X}"},
         						{"\\fh","\\mathfrak{h}"},
         						{"\\fo","\\mathfrak{o}"},
         						{"\\ft","\\mathfrak{t}"},
         						{"\\fC","\\mathfrak{C}"},
         						{"\\vecp","\\vec{p}"},
         						{"\\vecz","\\vec{z}"},
         						{"\\vecd","\\vec{d}"},
         						{"\\vecell","\\vec{\\ell}"}
};
/*N is the size of the macro replace table*/
int N=sizeof(replace)/sizeof(struct ReplaceTable);


int main(){
	FILE *oldfilepointer, *newfilepointer;
	int i, indicator=0, ascii, replaceindex, coincidenceindex;
	char oldfilechar[0];
	char *oldword, *newword;
	const char *backslash="\\", *empty="";
	oldword=(char *)malloc(100*sizeof(char));
	newword=(char *)malloc(100*sizeof(char));
	printf("Dictionary has %d pairs.\n", N);
	for (i=0;i<N;i++)
		printf("%d: %s will be replaced by %s\n",i+1,replace[i].macro,replace[i].original);
	if ((oldfilepointer=fopen("test1.txt","rb"))==NULL
		||(newfilepointer=fopen("test2.txt","w"))==NULL)
			printf("file error!\n");
	oldfilechar[0]=fgetc(oldfilepointer);
	while (feof(oldfilepointer)==0){
		if (oldfilechar[0]==92&&indicator==0){
			indicator=1;
			strcpy(oldword,backslash);
			oldfilechar[0]=fgetc(oldfilepointer);}
		if (indicator==1){
			ascii=(int) oldfilechar[0];
			if ((ascii>=65&&ascii<=90)||(ascii>=97&&ascii<=122))
				strcat(oldword,oldfilechar);
			else{
				indicator=0;
				coincidenceindex=0;
				for (replaceindex=0; replaceindex<N; replaceindex++){
					if (strcmp(replace[replaceindex].macro, oldword)==0){
							strcpy(newword,replace[replaceindex].original);
							fputs(newword,newfilepointer);
							printf("%s", newword);
							coincidenceindex=1;
						}
					}
				if (coincidenceindex==0) {
							fputs(oldword,newfilepointer);
							printf("%s", oldword);
						}
				fseek(oldfilepointer,-1L,SEEK_CUR);
				}
		}
		else{
			ascii=(int) oldfilechar[0];
			if (ascii!=10) fputs(oldfilechar,newfilepointer);
			printf("%s",oldfilechar);
 			}
		oldfilechar[0]=fgetc(oldfilepointer);
 	}
 	if (indicator==1) fputs(oldword,newfilepointer);
 	fclose(oldfilepointer);
 	fclose(newfilepointer);
	return 0;
}


