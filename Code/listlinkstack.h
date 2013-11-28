template <class Elem> class List {
public:
   void clear() ;
   bool insert(const Elem&) ;
  bool append(const Elem&) ;
   bool remove(Elem&) ;
   void setStart() ;
  void setEnd() ;
   void prev() ;
   void next() ;
   int leftLength() const ;
  int rightLength() const ;
   bool setPos(int pos) ;
   bool getValue(Elem&) const ;
   void print() const ;
};



template <class Elem> class Link 
{
	public:
  	Elem element; 
  	Link *next;   
  	
		Link(const Elem& elemval,
       	Link* nextval =NULL)
     { element = elemval;  next = nextval; }
  	
		
		Link(Link* nextval =NULL)
    	{ next = nextval; }
};

template <class Elem> 
class LStack          
{
 private:
   Link<Elem>* top; // Pointer to first elem
   int size;        // Count number of elems

 public:

  LStack()
    { top = NULL; size = 0; }

  bool push(const Elem& item) 
  {
    top = new Link<Elem>(item, top);
    size++;
    return true;
  }
 bool pop(Elem& it) 
 {
    if (size == 0) return false;
    it = top->element;
    Link<Elem>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return true;
 }

 bool topValue(Elem& it) const 
 {
    if (size == 0) return false;
    it = top->element;
    return true;
 }

 bool empty()
 {
	 if(size==0)
		 return true;
	 else
		 return false;

 }
};


template <class Elem> class LList: public List<Elem> 

{
	private:
  Link<Elem>* head; 
  Link<Elem>* tail; 
  int leftcnt;      
  int rightcnt;
  Link<Elem>* fence;// Last element on left
  
  

void removeall() 
	{   // Return link nodes to free store
    while(head != NULL) {
      fence = head;
      head = head->next;
      delete fence;
    }
  }
void init() 
	{ // Intialization routine
    fence = tail = head = new Link<Elem>;
    leftcnt = rightcnt = 0;
  }

public:


  LList(int size=0)
    { init(); }
  ~LList() { removeall(); }  
  void clear() { removeall(); init(); }

  void setStart() 
{
  fence = head; rightcnt += leftcnt;
  leftcnt = 0; 
}
void setEnd() 
{
  fence = tail; leftcnt += rightcnt;
  rightcnt = 0; 
}
void next() 
{
 
 if (fence != tail) {
   fence = fence->next; rightcnt--; 
      leftcnt++; }
}

int leftLength() const  { return leftcnt; }
int rightLength() const { return rightcnt; }

bool getValue(Elem& it) const 
{
  if(rightLength() == 0) return false;
  it = fence->next->element;
  return true; 


}

template <class Elem>
bool insert(const Elem& item) 
{
  fence->next =
    new Link<Elem>(item, fence->next);  
  if (tail == fence) tail = fence->next; rightcnt++;
  return true;
}

// Append Elem to end of the list
template <class Elem>
bool append(const Elem& item) 
{
  tail = tail->next =
    new Link<Elem>(item, NULL);
  rightcnt++;
  return true;
}



template <class Elem>
bool insertfirst(const Elem& item) 
{	
	Link<Elem>* temp; 
	
	if(fence==head)
	{temp=head;

	temp->next =
    new Link<Elem>(item, temp->next);  
	rightcnt++;}
	else
		{temp=head;

	temp->next =
    new Link<Elem>(item, temp->next);  
	leftcnt++;}
  return true;
	
	
}
//Print
void print()
{
	cout<<"Left count: "<<leftLength();
	cout<<endl;
	cout<<"Right count: "<<rightLength();
	cout<<endl;

}
//Search
void search(int s,Elem& e)

{
	
	Link<Elem>* temp; 
	int c;
	temp=head;
	
	while(temp!=tail)
	{

		c=(temp->next->element.id);
		if(s==c)
		//cout<<(temp->next->element.service)<<"  ";
		e=temp->next->element;
		
			temp=temp->next;
	}

}

//cost
//int costreturn(int s)
//
//{
//
//	Link<Elem>* temp; 
//	int c;
//	temp=head;
//	
//	while(temp!=tail)
//	{
//
//		c=(temp->next->element.id);
//		if(s==c)
//			return temp->next->element.cost;
//		
//			temp=temp->next;
//	}
//
//
//}


//Delete

bool del(int item) 
{
	Link<Elem>* temp; 
	int c;
	temp=head;
	
	while(temp!=tail)
	{
	
		c=(temp->next->element.id);
		if(item==c)
		{
			if(temp->next==tail)
			{
			Link<Elem>* templ;
			//templ=temp->next;
			//temp->next=NULL;
		//tail=temp;

			//delete templ;    
			rightcnt--;
			//cout<<tail->element.id;


			}
			else{
			Link<Elem>* templ;
			templ=temp->next;
			temp->next=templ->next;
			delete templ;      
			rightcnt--;
			}
		}
		
temp=temp->next;

	}

return true;
          
}
	

		
	
		
	
//Set Position
bool setPos(int pos) 
{
  if ((pos < 0) || (pos > rightcnt+leftcnt)) 
    return false;

  fence = head;

  for(int i=0; i<pos; i++)
  {fence = fence->next;
   leftcnt++;
   rightcnt--;}

  return true;
}



};