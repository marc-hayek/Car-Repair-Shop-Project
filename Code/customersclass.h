class customers
{
public:
	string firstname;
	string lastname;
	string adress;
	int CID;
	
	customers()
	{ firstname='\0';
	  lastname='\0';
	  adress='\0';
	  CID=0;
	}

	customers(string a, string b , string c, int d)
	{
		firstname=a;
		lastname=b;
		adress=c;
		CID=d;


	}
};