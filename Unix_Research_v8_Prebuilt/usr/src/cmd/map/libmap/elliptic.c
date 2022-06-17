#include "map.h"

struct coord center;

Xelliptic(p,x,y)
struct place *p;
float *x,*y;
{
	float r1,r2;
	r1 = acos(p->nlat.c*(p->wlon.c*center.c
		- p->wlon.s*center.s));
	r2 = acos(p->nlat.c*(p->wlon.c*center.c
		+ p->wlon.s*center.s));
	*x = -(r1*r1 - r2*r2)/(4*center.l);
	*y = (r1*r1+r2*r2)/2 - (center.l*center.l+*x**x);
	*y = sqrt(*y);
	if(p->nlat.l<0)
		*y = -*y;
	return(1);
}

int (*elliptic(l))()
float l;
{
	int Xazequidistant();
	l = fabs(l);
	if(l>89)
		return(0);
	if(l<1)
		return(Xazequidistant);
	deg2rad(l,&center);
	return(Xelliptic);
}
