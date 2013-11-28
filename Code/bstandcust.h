template <class Key, class Elem, class KEComp, class EEComp>
class  Dictionary { 
public:
  virtual void clear() = 0;
  virtual bool insert(const Elem&) = 0;
  virtual bool remove(const Key&, Elem&) = 0;
  virtual bool removeAny(Elem&) = 0;
  //virtual bool updatecust(const Key&, Elem&, string k) const = 0;
  //virtual bool updatecar(const Key&, Elem&,int) const=0;
  virtual int size() = 0;
};


// Binary tree node abstract class
template <class Elem> 
class BinNode {
public:
  virtual Elem& val() = 0;
  virtual void setVal(const Elem&) = 0;
 
  virtual BinNode* left() const = 0;
  virtual void setLeft(BinNode*) = 0;
  virtual BinNode* right() const = 0;
  virtual void setRight(BinNode*) = 0;
  virtual bool isLeaf() = 0;
};

// Binary tree node class
template <class Elem>
class BinNodePtr : public BinNode<Elem> {
private:
  Elem it;                   
  BinNodePtr* lc;            
  BinNodePtr* rc;              
public:
  BinNodePtr() { lc = rc = NULL; }
  BinNodePtr(Elem e, BinNodePtr* l =NULL,
                     BinNodePtr* r =NULL)
    { it = e; lc = l; rc = r; }
  ~BinNodePtr() {}             
  Elem& val() { return it; }
  void setVal(const Elem& e) { it = e; }
  inline BinNode<Elem>* left() const { return lc; }
  void setLeft(BinNode<Elem>* b) { lc = (BinNodePtr*)b; } 
  inline BinNode<Elem>* right() const { return rc; }
  void setRight(BinNode<Elem>* b) { rc = (BinNodePtr*)b; }
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};



template <class Key, class Elem, class KEComp, class EEComp>
class BST : public Dictionary<Key, Elem, KEComp, EEComp> {
private:
  BinNode<Elem>* root;   
  int nodecount;         
 
  void clearhelp(BinNode<Elem>*);
  BinNode<Elem>* inserthelp(BinNode<Elem>*, const Elem&);
  BinNode<Elem>* deletemin(BinNode<Elem>*, BinNode<Elem>*&);
  BinNode<Elem>* removehelp(BinNode<Elem>*, const Key&,
                            BinNode<Elem>*&);
  bool custfindhelp(BinNode<Elem>*, const Key&, Elem&,string ) const;
  bool custIdfind (BinNode<Elem>*, const Key&, Elem& ) const;
  void printhelp(BinNode<Elem>*, int) const;
  void preorder(BinNode<Elem>*,string s)const;
  void findidhelp(BinNode<Elem>*,int k,Elem& e)const;
public:
  BST() { root = NULL; nodecount = 0; }  
  ~BST() { clearhelp(root); }           
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
  bool updatecust(const Key& K, Elem& e,string a) const
    { return custfindhelp(root, K, e, a); }

  void findid(int k,Elem& e)
  {
	  return findidhelp(root,k,e);


  }
 
  
  int size() { return nodecount; }

 
  void print() const {
    if (root == NULL) cout << "The BST is empty.\n";
    else printhelp(root, 0);
  }

  void searchall(string s)
  {
	  return preorder(root,s);


  }

 

  
};

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::
clearhelp(BinNode<Elem>* subroot) {
  if (subroot == NULL) return;
  clearhelp(subroot->left());
  clearhelp(subroot->right());
  delete subroot;
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::
inserthelp(BinNode<Elem>* subroot, const Elem& val) {
  if (subroot == NULL)            // Empty tree: create node
    return (new BinNodePtr<Elem>(val, NULL, NULL));
  if (EEComp::lt(val, subroot->val())) // Insert on left
    subroot->setLeft(inserthelp(subroot->left(), val));
  else subroot->setRight(inserthelp(subroot->right(), val));
  return subroot;  // Return subtree with node inserted
}

template <class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::
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
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::
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
bool BST<Key, Elem, KEComp, EEComp>:: custfindhelp(
      BinNode<Elem>* subroot, const Key& K, Elem& e, string k) const {
  if (subroot == NULL) return false;         // Empty tree
  else if (KEComp::lt(K, subroot->val()))    // Check left
    return custfindhelp(subroot->left(), K, e,k);
  else if (KEComp::gt(K, subroot->val()))    // Check right
    return custfindhelp(subroot->right(), K, e,k);
  else {
		(subroot->val()).lastname=k;	
  return true; } // Found it
}






template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::
printhelp(BinNode<Elem>* subroot, int level) const {
  if (subroot == NULL) return;          // Empty tree
  printhelp(subroot->left(), level+1);  // Do left subtree

  cout<<"First name: "<<subroot->val().firstname<<endl;
  cout<<"Last name: "<<subroot->val().lastname<<endl;
  cout<<"Adress: "<<subroot->val().adress<<endl;
  cout<<"CID: "<<subroot->val().CID<<endl;
  cout<<endl<<endl;
  /*cout <<"ID: "<< subroot->val().id << "\n";
  cout<<"Average: "<<subroot->val().average<<endl<<endl;*/
  printhelp(subroot->right(), level+1);
}

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::
preorder(BinNode<Elem>* subroot, string s) const {
 
  if (subroot == NULL) return; 
  if(subroot->val().lastname==s)
	  cout<<subroot->val().print()<<endl<<endl;
  preorder(subroot->left(),s); 
  preorder(subroot->right(),s);
}

template <class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::
findidhelp(BinNode<Elem>* subroot, int k,Elem& e) const {
 
  if (subroot == NULL) return; 
  if(subroot->val().CID==k)
	  e=subroot->val();
  findidhelp(subroot->left(),k,e); 
  findidhelp(subroot->right(),k,e);
}