class LastnameCompare 
{
	public:	

static bool lt(const customers& x, const customers& y)
     { return x.lastname < y.lastname; }
   
static bool gt(const customers& x,const  customers& y)
     { return x.lastname > y.lastname; }

static bool eq(const customers& x, const customers& y)
{ return x.lastname == y.lastname; }

};

class LastnamescustomCompare 
{
	public:	

static bool lt(string i,customers& x )
     { return  i<x.lastname ; }
   
static bool gt(string i,customers& x )
     { return  i> x.lastname; }

static bool eq(string i,customers& x )
{ return  i==x.lastname; }

};



class concCompare 
{
	public:	

static bool lt(const cars& x, const cars& y)
{ return x.conc < y.conc; }
   
static bool gt(const cars& x,const  cars& y)
     { return x.conc > y.conc; }

static bool eq(const cars& x, const cars& y)
     { return x.conc == y.conc; }

};

class conccarsCompare 
{
	public:	

static bool lt(int i,cars& x )
     { return  i<x.conc ; }
   
static bool gt(int i,cars& x )
     { return  i> x.conc; }

static bool eq(int i,cars& x )
     { return  i==x.conc ; }

};