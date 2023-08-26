#include<stdio.h>
#include<math.h>
#define im1 2147483563
#define im2 2147483399
#define am (1.0/im1)
#define imm1 (im1-1)
#define ia1 40014
#define ia2 40692
#define iq1 53668
#define iq2 52774
#define ir1 12211
#define ir2 3791
#define ntab 32
#define ndiv (1+imm1/ntab)
#define eps 1.2e-7
#define rnmx (1.0-eps)     
using namespace std;

//incremental variables

#define dt 0.001
#define r 10
#define D 100
#define c sqrt(2*D/dt)

//seeds

#define seed1 1
#define seed2 2

//uniform 0,1 for N(0,1)

float ran2(long id);
float ran2(long idum)
{
	int j;
	long k;
	static long idum2=123456789;
	static long iy=0;
	static long iv[ntab];
	float temp;

	if(idum <=0){
		if( -idum<1) idum=1;
		else idum =-idum;
		idum2=idum;
		for(j=ntab+7;j>=0;j--){
			k=idum/iq1;
			idum=ia1*(idum-k*iq1)-k*ir1;
			if(idum<0) idum +=im1;
			if (j<ntab) iv[j]=idum;
		}
		iy=iv[0];
		}
		k=(idum)/iq1;
		idum=ia1*(idum-k*iq1)-k*ir1;
		if (idum <0) idum +=im1;
		k=idum2/iq2;
		idum2=ia2*(idum2-k*iq2)-k*ir2;
		if (idum2 <0) idum +=im2;
		j=iy/ndiv;
		iy=iv[j]-idum2;
		if (iy<1) iy +=imm1;
		if((temp=am*iy)>rnmx) return rnmx;
		else return temp;
}

//  N( 0,1)

float gasdev( long as);
float gasdev(long idum)
{
	static int iset=0;
	static float gset;
	float fac,rsq,v1,v2;

	if (idum<0) iset=0;
	if (iset==0) {
		do{
			v1=2.0*ran2(idum)-1.0;
			v2=2.0*ran2(idum)-1.0;
			rsq=v1*v1+v2*v2;
		   }while(rsq>=1.0||rsq==0.0);
		fac=sqrt(-2.0*log(rsq)/rsq);
		gset= v1*fac;
		iset=1;
		return v2*fac;
		}
		else{
			iset=0;
			return gset;
		    }
 }



//unif(0,1)

float ran(long id);
float ran(long idum)
{
	int j;
	long k;
	static long idum2=123456789;
	static long iy=0;
	static long iv[ntab];
	float temp;

	if(idum <=0){
		if( -idum<1) idum=1;
		else idum =-idum;
		idum2=idum;
		for(j=ntab+7;j>=0;j--){
			k=idum/iq1;
			idum=ia1*(idum-k*iq1)-k*ir1;
			if(idum<0) idum +=im1;
			if (j<ntab) iv[j]=idum;
		}
		iy=iv[0];
		}
		k=(idum)/iq1;
		idum=ia1*(idum-k*iq1)-k*ir1;
		if (idum <0) idum +=im1;
		k=idum2/iq2;
		idum2=ia2*(idum2-k*iq2)-k*ir2;
		if (idum2 <0) idum +=im2;
		j=iy/ndiv;
		iy=iv[j]-idum2;
		if (iy<1) iy +=imm1;
		if((temp=am*iy)>rnmx) return rnmx;
		else return temp;
}





int main()
{
double x=0;
printf("%f",c);
FILE *f1;
f1=fopen("reset.dat","w");
double g[5000];
for(int i=0;i<5000;i++)
g[i]=gasdev(3);
for(int j=0;j<5000;j++)
{
	fprintf(f1,"%f	%lf	%lf\n",j*dt,x,y);
	if(ran(3)<r*dt)
	x=0;
	else 
	x=x+c*g[j];
y=y+c*g[j];
}
fclose(f1);
return 0;
}









