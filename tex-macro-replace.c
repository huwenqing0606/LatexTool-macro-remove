#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ReplaceTable{
	char macro[100];
	char original[100]; 
};

struct ReplaceTable replace[]={	{"\\play","\\displaystyle"},
		   						{"\\li","\\limits"},
    							{"\\pt","\\partial"},
         						{"\\ra","\\rightarrow"},
         						{"\\da","\\downarrow"},	
   								{"\\Prob","\\mathbf{P}"},
			       				{"\\E","\\mathbf{E}"},
		         				{"\\Var","\\mathbf{Var}"},
		         				{"\\Cov","\\mathbf{Cov}"},
		         				{"\\al","\\alpha"},
		         				{"\\bt","\\beta"},
		        				{"\\gm","\\gamma"},
		         				{"\\Gm","\\Gamma"},
		         				{"\\dt","\\delta"},
		         				{"\\Dt","\\Delta"},
		         				{"\\ve","\\varepsilon"},
		         				{"\\tht","\\theta"},
		         				{"\\Tht","\\Theta"},
		        				{"\\ththat","\\widehat{\\theta}_n"},
		         				{"\\kp","\\kappa"},
		         				{"\\lb","\\lambda"},
		         				{"\\Lb","\\Lambda"},
		         				{"\\sm","\\sigma"},
		         				{"\\Sm","\\Sigma"},
		         				{"\\om","\\omega"},
		         				{"\\Om","\\Omega"},
		        				{"\\zt","\\zeta"},
		         				{"\\A","\\mathbb{A}"},
        						{"\\C","\\mathbb{C}"},
         						{"\\Half","\\mathbb{H}"},
        						{"\\N","\\mathbb{N}"},
        						{"\\R","\\mathbb{R}"},
         						{"\\T","\\mathbb{T}"},
         						{"\\Z","\\mathbb{Z}"},
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
         						{"\\cx","\\mathcal{x}"},
         						{"\\cu","\\mathcal{u}"},
         						{"\\rH","\\mathscr{H}"},
         						{"\\rL","\\mathscr{L}"},
         						{"\\rF","\\mathscr{F}"},
         						{"\\rmF","\\mathrm{F}"},
         						{"\\rmX","\\mathrm{X}"},
         						{"\\rmY","\\mathrm{Y}"},
         						{"\\rmP","\\mathrm{P}"},
        						{"\\ig","\\mathfrak{g}"},
         						{"\\iX","\\mathfrak{X}"},
         						{"\\iY","\\mathfrak{Y}"},
         						{"\\iiY","\\mathbf{\\mathfrak{Y}}"},
         						{"\\X","\\mathbf{X}"},
								{"\\hX","\\widehat{X}"},
        						{"\\hY","\\widehat{Y}"},
         						{"\\Xbar","\\bar{X}"},
         						{"\\cPhi","\\mathbf{\\Phi}"},
        						{"\\One","\\mathbf{1}"},
         						{"\\contfunc","\\mathbf{C}"},
         						{"\\contfuncGm","\\mathbf{C}_{[0,\\infty)}(\\Gamma)"},
         						{"\\contfuncz","\\mathbf{C}_{[0,\\infty)}(\\Gamma(z))"},
         						{"\\contfuncopenbook","\\mathbf{C}_{[0,\\infty)}(\\mathbf{\\Gamma})"},
         						{"\\contfuncR","\\mathbf{C}_{[0,T]}(\\mathbb{R})"},
         						{"\\contfuncRslash","\\mathbf{C}_{[0,T]}(\\mathbb{R}\\backslash(-1,1))"},
         						{"\\grad","\\nabla"},
         						{"\\openbook","\\mathbf{\\Gamma}"},
         						{"\\operator","\\overline{\\mathbf{L}}"},
         						{"\\domain","\\mathbf{D}"},
         						{"\\torus","\\mathbb{T}"},
         						{"\\boldA","\\boldsymbol{A}"},
         						{"\\boldB","\\boldsymbol{B}"},
         						{"\\boldC","\\boldsymbol{C}"},
         						{"\\boldI","\\boldsymbol{I}"},
         						{"\\boldK","\\boldsymbol{K}"},
         						{"\\boldP","\\boldsymbol{P}"},
         						{"\\boldQ","\\boldsymbol{Q}"},
         						{"\\boldR","\\boldsymbol{R}"},
         						{"\\boldN","\\boldsymbol{N}"},
         						{"\\boldU","\\boldsymbol{U}"},
         						{"\\boldV","\\boldsymbol{V}"},
         						{"\\boldW","\\boldsymbol{W}"},
         						{"\\boldX","\\boldsymbol{X}"},
         						{"\\boldZ","\\boldsymbol{Z}"},
         						{"\\bolda","\\boldsymbol{a}"},
         						{"\\boldb","\\boldsymbol{b}"},
         						{"\\bolde","\\boldsymbol{e}"},
         						{"\\boldf","\\boldsymbol{f}"},
         						{"\\boldg","\\boldsymbol{g}"},
         						{"\\boldh","\\boldsymbol{h}"},
         						{"\\boldk","\\boldsymbol{k}"},
         						{"\\boldn","\\boldsymbol{n}"},
         						{"\\boldp","\\boldsymbol{p}"},
         						{"\\boldq","\\boldsymbol{q}"},
         						{"\\boldu","\\boldsymbol{u}"},
         						{"\\boldv","\\boldsymbol{v}"},
         						{"\\boldx","\\boldsymbol{x}"},
        	 					{"\\boldy","\\boldsymbol{y}"},
         						{"\\boldz","\\boldsymbol{z}"},
         						{"\\boldSm","\\boldsymbol{\\Sigma}"},
         						{"\\boldLb","\\boldsymbol{\\Lambda}"},
         						{"\\boldal","\\boldsymbol{\\alpha}"},
         						{"\\boldbt","\\boldsymbol{\\beta}"},
         						{"\\boldgm","\\boldsymbol{\\gamma}"},
         						{"\\boldnu","\\boldsymbol{\\nu}"},
         						{"\\boldphi","\\boldsymbol{\\varphi}"},
         						{"\\fC","\\mathfrak{C}"},
         						{"\\fh","\\mathfrak{h}"},
         						{"\\fo","\\mathfrak{o}"},
         						{"\\ft","\\mathfrak{t}"},
         						{"\\vphi","\\varphi"},
         						{"\\bbar","\\bar{b}"},
         						{"\\gbar","\\bar{g}"},
         						{"\\Vbar","\\overline{V}"},
         						{"\\boldXhat","\\widehat{\\boldsymbol{X}}"},
         						{"\\Xhat","\\widehat{X}"},
         						{"\\Zhat","\\widehat{Z}"},
         						{"\\Atilde","\\widetilde{A}"},
         						{"\\Ylow","Y_{\\text{low}}"},
         						{"\\spaceX","\\mathcal{X}"},
         						{"\\transitionP","\\mathcal{P}"},
         						{"\\bfE","\\mathbf{E}"},
         						{"\\bfP","\\mathbf{P}"},
         						{"\\vecp","\\vec{p}"},
         						{"\\vecz","\\vec{z}"},
         						{"\\vecd","\\vec{d}"},
         						{"\\vecell","\\vec{\\ell}"},
         						{"\\xsaddle","x_{\\text{saddle}}"},
         						{"\\diag","\\text{diag}"},
								{"\\ZZ","\\mathbb{Z}"},
								{"\\lzb","\\llbracket"},
								{"\\rzb","\\rrbracket"},
								{"\\eqd","\\stackrel{d}{=}"}		};	
         
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
