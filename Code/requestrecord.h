class request
{	public:
	int CID;
	int VID;
	int renum;

	int *SID;
	
	int dropoff;

	request()
	{
		CID=0;
		VID=0;
		dropoff=0;
		
	}

	request(int cid, int vid, int renu, int drop)
	{
		CID=cid;
		VID=vid;
		renum=renu;
	}

	void setservice()
	{/*int x;*/
		SID=new int[renum];
		/*for(int i=0;i<renum;i++)
		{
			cout<<"Please Enter Service Number: ";
			cin>>x;
			SID[i]=x;
		}*/

		/*cout<<endl<<endl;*/
	}
};











