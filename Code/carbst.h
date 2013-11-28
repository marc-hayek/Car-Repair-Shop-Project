template <class Key, class Elem, class KEComp, class EEComp>
class carBST : public Dictionary<Key, Elem, KEComp, EEComp> {
private:
  BinNode<Elem>* root;   
  int nodecount;         
 
  void clearhelp(BinNode<Elem>*);
  BinNode<Elem>* inserthelp(BinNode<Elem>*, const Elem&);
  BinNode<Elem>* deletemin(BinNode<Elem>*, BinNode<Elem>*&);
  BinNode<Elem>* removehelp(BinNode<Elem>*, const Key&,
                            BinNode<Elem>*&);
 
  bool carfindhelp(BinNode<Elem>*, const Key&, Elem&,int ) const;

  void printhelp(BinNode<Elem>*, int) const;
  void preorder(BinNode<Elem>*,string s)const;
  void findidhelp(BinNode<Elem>*,int k,Elem& e) const;

public:
  carBST() { root = NULL; nodecount = 0; }  
  ~carBST() { clearhelp(root); }           
  void clear()
    { clearhelp(root); root = NULL; nodecount = 0; }
  bool insert(const Elem& e) {
    root = inserthelp(root, e);
    nodecount++;
    return true;
  }
  bool remove(const Key& K, Elem& e) {
    BinNode<Elem>* t = NULL;
    root = removehelp(root, K, t);
    if (t == NULL) return false;  
    e = t->val();
    nodecount--;
    delete t;
    return true;
  }
  bool removeAny(Elem& e) { 
    if (root == NULL) return false; 
    BinNode<Elem>* t;
    root = deletemin(root, t);
    e = t->val();
    delete t;
    nodecount--;
    return true;
  }

  bool updatecar(const Key& K, Elem& e,int a)const
  { return carfindhelp(root,K,e,a);}
 
  
  int size() { return nodecount; }

 
  void print() const {
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
  }

  void searchall(string s)
  {
	  return preorder(root,s);


  }

  
  void findid(int k,Elem& e)
  {
	  return findidhelp(root,k,e);
  }

  int count()
  {	  int counter=0;
	  findcount(root,counter);
	  return counter;

  }

 

  
};

template <class Key, class Elem, class KEComp, class EEComp>
void carBST<Key, Elem, KEComp, EEComp>::
clearhelp(BinNode<Elem>* subroot) {
  if (subroot == NULL) return;
  clearhelp(subroot->left());
  clearhelp(subroot->right());
  delete subroot;
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* carBST<Key, Elem, KEComp, EEComp>::
inserthelp(BinNode<Elem>* subroot, const Elem& val) {
  if (subroot == NULL)            // Empty tree: create node
    return (new BinNodePtr<Elem>(val, NULL, NULL));
  if (EEComp::lt(val, subroot->val())) // Insert on left
    subroot->setLeft(inserthelp(subroot->left(), val));
  else subroot->setRight(inserthelp(subroot->right(), val));
  return subroot;  // Return subtree with node inserted
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* carBST<Key, Elem, KEComp, EEComp>::
deletemin(BinNode<Elem>* subroot, BinNode<Elem>*& min) {
  if (subroot->left() == NULL) { // Found min
    min = subroot;
    return subroot->right();
  }
  else {                         // Continue left
    subroot->setLeft(deletemin(subroot->left(), min));
    return subroot;
  }
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* carBST<Key, Elem, KEComp, EEComp>::
removehelp(BinNode<Elem>* subroot, const Key& K,
           BinNode<Elem>*& t) {
  if (subroot == NULL) return NULL; // Val is not in tree
  else if (KEComp::lt(K, subroot->val())) // Check left
    subroot->setLeft(removehelp(subroot->left(), K, t));
  else if (KEComp::gt(K, subroot->val())) // Check right
    subroot->setRight(removehelp(subroot->right(), K, t));
  else {                           // Found it: remove it
    BinNode<Elem>* temp;
    t = subroot;
    if (subroot->left() == NULL)       // Only a right child
      subroot = subroot->right();      //  so point to right
    else if (subroot->right() == NULL) // Only a left child
      subroot = subroot->left();       //  so point to left
    else {                    // Both children are non-empty
      subroot->setRight(deletemin(subroot->right(), temp)); //temp:inorder successor
															// returns a pointer to subroot->right()
      Elem te = subroot->val();  // remember value of node to remove
      subroot->setVal(temp->val());
      temp->setVal(te);
      t = temp;
    }
  }
  return subroot;
}





template <class Key, class Elem, class KEComp, class EEComp>
bool carBST<Key, Elem, KEComp, EEComp>:: carfindhelp(
      BinNode<Elem>* subroot, const Key& K, Elem& e, int k) const {
  if (subroot == NULL) return false;         // Empty tree
  else if (KEComp::lt(K, subroot->val()))    // Check left
    return carfindhelp(subroot->left(), K, e,k);
  else if (KEComp::gt(K, subroot->val()))    // Check right
    return carfindhelp(subroot->right(), K, e,k);
  else {
		(subroot->val()).VID=k;	
  return true; } // Found it
}





template <class Key, class Elem, class KEComp, class EEComp>
void carBST<Key, Elem, KEComp, EEComp>::
printhelp(BinNode<Elem>* subroot, int level) const {
  if (subroot == NULL) return;          // Empty tree
  printhelp(subroot->left(), level+1);  // Do left subtree

  //cout<<"First name: "<<subroot->val().firstname<<endl;
  //cout<<"Last name: "<<subroot->val().lastname<<endl;
  //cout<<"Adress: "<<subroot->val().adress<<endl;



  cout<<"Make: "<<subroot->val().make<<endl;
  cout<<"Model: "<<subroot->val().model<<endl;
  cout<<"Year: "<<subroot->val().year<<endl;
  cout<<"Color: "<<subroot->val().color<<endl;
  cout<<"VID: "<<subroot->val().VID<<endl;
  //cout<<"conc: "<<subroot->val().conc<<endl<<endl;
  
  /*cout <<"ID: "<< subroot->val().id << "\n";
  cout<<"Average: "<<subroot->val().average<<endl<<endl;*/
  printhelp(subroot->right(), level+1);
}

template <class Key, class Elem, class KEComp, class EEComp>
void carBST<Key, Elem, KEComp, EEComp>::
preorder(BinNode<Elem>* subroot, string s) const {
 
  if (subroot == NULL) return; 
  if(subroot->val().lastname==s)
	  cout<<subroot->val().print()<<endl<<endl;
  preorder(subroot->left(),s); 
  preorder(subroot->right(),s);
}

template <class Key, class Elem, class KEComp, class EEComp>
void carBST<Key, Elem, KEComp, EEComp>::
findidhelp(BinNode<Elem>* subroot, int k,Elem& e) const {
 
  if (subroot == NULL) return; 
  if(subroot->val().VID==k)
	  e=subroot->val();
  findidhelp(subroot->left(),k,e); 
  findidhelp(subroot->right(),k,e);
}

