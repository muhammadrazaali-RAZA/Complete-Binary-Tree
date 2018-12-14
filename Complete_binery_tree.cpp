#include<iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int no;
	node *left,*right;
	int noode;
};

class Complete_Binary_Tree{
	
	public:
		node *root;
		int key,height,node_count,local_height,one_inser;
		Complete_Binary_Tree();
		~Complete_Binary_Tree();
		int power_fun(int x,int n);
		void insertion(node *);
		void options();
		void destory(node *);
		void in_order(node *);
		void delete_node(node *);
		void dele_last(node *);
		
};

Complete_Binary_Tree::Complete_Binary_Tree(){
	root=NULL;
	height=node_count=local_height=0;
	one_inser=1;
}

void Complete_Binary_Tree::insertion(node *temp){
	if(root==NULL){
		root=new node;
		root->no=key;
		root->left=NULL;
		root->right=NULL;
		node_count++;
		root->noode=node_count;
		return;
	}
	
	if( temp->no==key ){
		cout<<" \n Given numbe r is already present in tree.\n";
		return;
	}
	
	if(power_fun(2,height+1)-1== node_count)
	{
    	if( temp->left!=NULL )
       	{
       		local_height++;
			insertion(temp->left);
			local_height--;
			return;
       	}
      	else
       	{
	 		temp->left=new node;
	 		temp->left->no = key;
	 		temp->left->left=NULL;
	 		temp->left->right=NULL;
	 		node_count++;
	 		temp->left->noode=node_count;
	 		height++;
	 		return;
       	}
   	}
   	if(power_fun(2,height+1)-1 > node_count){
   		
		if(one_inser){
			
			if (local_height==height-1){
	   			
	   			if( temp->left==NULL ){
	   				temp->left=new node;
		 			temp->left->no = key;
		 			temp->left->left=NULL;
		 			temp->left->right=NULL;
		 			node_count++;
		 			temp->left->noode=node_count;
		 			one_inser=0;
		 			return;
		 			
	       		}
	       		
	       		if( temp->right==NULL ){
	       			temp->right=new node;
		 			temp->right->no = key;
		 			temp->right->left=NULL;
		 			temp->right->right=NULL;
		 			node_count++;
		 			temp->right->noode=node_count;
		 			local_height=height;
		 			one_inser=0;
		 			return;
		 			
	       		}
	       		
	       		return;
			}
	   	
			if( temp->left!=NULL ){
				local_height++;
				insertion(temp->left);
				local_height--;
			}
			
			if(	temp->right!=NULL){
				local_height++;
				insertion(temp->right);
				local_height--;
			}
			
			return;
		
		}else{	return;}
	}
	
	cout<<"wrong side...!"<<endl;
	return;
}



void Complete_Binary_Tree:: options()
{
 	cout<<"\n\n ************** Select Option *****************.\n";
 	cout<<"\n Enter any of choices.\n";
 	cout<<"\n 0 : Quitting the Program.\n";
 	cout<<"\n 1 : Print the whole BST .\n";
 	cout<<"\n 2 : Adding (inserting) node in BST.\n";
 	cout<<"\n 3 : Delete (deleting) node in BST.\n";
 	cout<<"\n------------------------------\n";
 	cout<<"height        : "<<height<<endl;
	cout<<"local_height  : "<<local_height<<endl;
	cout<<"Nodes         : "<<node_count<<endl;
	cout<<"------------------------------\n";
}//--------------------------------------------------------------


void Complete_Binary_Tree:: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL ){
  	cout<<"("<<temp->no<<")left->";
  	in_order(temp->left);
  }
    		 
  cout<<temp->no<<"  ";
  if( temp->right!=NULL ){
  	cout<<"("<<temp->no<<")right->";
  	in_order(temp->right);
  }
		 
  return;
}//----------------------------    PROGRAM ENDS HERE  ---------------------------------------
/////--------------power function --------//////
int Complete_Binary_Tree::power_fun(int x,int n){
	int mul=1;
	for(int i=1; i<=n; i++){
		mul=mul*x;
	}
	return mul;
}
/////--------------power function --------//////




//----------------------- destory tree Function Starts  -----------------------

Complete_Binary_Tree::~Complete_Binary_Tree(){
	destory(root);
	cout<<"Done "<<endl;
}

void Complete_Binary_Tree::destory(node *temp){
	if(temp->left!=NULL && temp->right!=NULL){
		destory(temp->left);
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}

	
	else if(temp->left!=NULL && temp->right==NULL){
		destory(temp->left);
		delete temp;
		temp=NULL;
		return;
	}

	else if(temp->left==NULL && temp->right!=NULL){
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}
	
	else{
		delete temp;
		temp=NULL;
		return;
	}
	root=NULL;
}



////-------------------destory function ends -----------//////

//////--------------delete Node--------------////////////

void Complete_Binary_Tree::delete_node(node *temp){
	if(temp==NULL)
		return;
	
	if(root->no==key){
		if(root->left==NULL){
			delete root;
			root= NULL;
			node_count--;
		}else{
			dele_last(root);
			root->no=key;
		}
		return;
	}
	
	
	if(temp->no==key){
		if(temp->noode==node_count){
			dele_last(root);
			return;
		}
		dele_last(root);
		temp->no=key;
		return;	
	}

	if(temp->left!=NULL && temp->right!=NULL){
		delete_node(temp->left);
		delete_node(temp->right);
		return;
	}
	
	if(temp->left!=NULL && temp->right==NULL){
		delete_node(temp->left);
		return;
	}
	
	if(temp->left==NULL && temp->right==NULL){
		return;
	}
	return;
}

void Complete_Binary_Tree::dele_last(node *temp){
	if(temp->left->noode==node_count){
		key=temp->left->no;
		delete temp->left;
		temp->left=NULL;
		
		if(power_fun(2,height) == node_count){
			height--;	
		}
		
		node_count--;
		return;
	}
	
	if(temp->right->noode==node_count){
		key=temp->right->no;
		delete temp->right;
		temp->right=NULL;
		node_count--;
		return;
	}
	
	if(temp->left!=NULL && temp->right!=NULL){
		dele_last(temp->left);
		dele_last(temp->right);
		return;
	}
	
	if(temp->left!=NULL && temp->right==NULL){
		dele_last(temp->left);
		return;
	}
	
	if(temp->left==NULL && temp->right==NULL){
		return;
	}
	return;
}

//////--------------delete Node--------------////////////



int main(){
	char ch;
  	Complete_Binary_Tree obj;
  	while( 4 )
  	{
    obj.options();
    ch=getch();
    switch(ch)
     {
       	case '0':
       		obj.destory(obj.root);
			cout<<"Done "<<endl;
			exit(0);
			break;
		
		case '1':
			obj.in_order(obj.root);
			break;
		case '2':
			cout<<"Enter key : ";
			cin>>obj.key;
			obj.one_inser=1;
			obj.insertion(obj.root);
			obj.local_height=0;
			break;
		case '3':
			cout<<"Enter key to delete: ";
			cin>>obj.key;
			obj.delete_node(obj.root);
			break;
       	default :
			exit(0);
			break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------


