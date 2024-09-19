#include <iostream>
using namespace std;

class Node {
public:

   //Variable for the Employee Data
	int post_ID, Age, Salary  , workingdays , weight , bonus ;
  int  Marks;
  string Employee_Name ; 
	Node* parent;
	Node* left;
	Node* right;

   //Default constructor
	Node() { 
		post_ID= -1, Employee_Name= "", Age= 1, Salary= -1 , Marks= -1, workingdays = 1 , weight = 0  , bonus = 0; 
		parent = NULL;
		left = NULL;
		right = NULL;
	}

//Parameterized constructor
	Node(int k,string Name1, int age) {
		post_ID = k;
    Employee_Name= Name1;
    Age= age;
    Salary= 5000,Marks= 30,workingdays = 10,weight = 0,bonus = 0; 
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

//Building a Binary Search Tree for the employees with Post ID
class BST {
public:
	Node* root;
	int size;

public:
	BST() {
		root = NULL;
		size = 0;
	}

//Obtaining the details of the employees
	void insert(int k, string Name1, int age1) {
    
		Node* temp = new Node(k,Name1,age1);
		Node* current = root;
		Node* prev = NULL;

		if (root == NULL)
			root = temp;
		else {
			while (current != NULL) 
      { 
				prev = current;
				if (k > current->post_ID) {
					current = current->right;
				}
				else if (k < current->post_ID) {
					current = current->left;
				}
				else {
					cout << "Duplicate values are not allowed" << endl;
					return;
				}
			}

			if (k > prev->post_ID) {
				prev->right = temp;
				temp->parent = prev;
			}
			else if (k < prev->post_ID) {
				prev->left = temp;
				temp->parent = prev;
			}
		}	
		size++;
	}

//function to print the Heap 
	void print() {
	
    cout << ("\nIn-order Data : ");
    inorder(root);
    cout << ("\nPre-order Data : ");
    preorder(root);
    cout << ("\nPost-order Data : ")<<endl;
    postorder(root);
    
	}


//Function to print values
void print_values(int k) {

    //converting the heap to BST
    releaseheap(root);
  
		if (root == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = root;
			while (current != NULL){
				if (current->post_ID == k) {
          //printing post ID,Name, Age, Salary,No of  working days,marks within the position

					cout<<endl<<"\tPost ID                   : "<<current->post_ID<<endl;
          cout<<"\tName                      : "<<current->Employee_Name<<endl;
          cout<<"\tAge                       : "<<current->Age<<endl;
          cout<<"\tSalary                    : "<<current->Salary<<endl;
          cout<<"\tNo. of Working Days       : "<<current->workingdays<<endl;
          cout<<"\tMarks within the position : "<<current->Marks<<endl; 
          return;
				}
          
				else if (k < current->post_ID) {
					current = current->left;
				}
				else if (k > current->post_ID) {
					current = current->right;
				}  
			}	
      cout << "Post ID not found" << endl;
		}

  //Converting the BST to heap
  Heap(root);
	}

  //Function to promote an employee
  void promote(int promoting_ID,Node*node){

    //converting the heap to a BST
    releaseheap(root);
    
    int Manager_marks = 50;
    int Director_marks = 75;

    if (root == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = root;
			while (current != NULL){
				if (current->post_ID == promoting_ID && node!=NULL) {
            
            if(current->Marks >=Director_marks){
              swap_for_promote(current,node);
              deleteNode (current->post_ID);
              //maxHeap(root);
            }
            else if(current->Marks >=Manager_marks){
              swap_for_promote(current,node);
              deleteNode (current->post_ID);
              //maxHeap(root);
            }
            else {
              cout<<"\tMarks insufficient for promotion";
              }
              break;
				}
				else if (promoting_ID < current->post_ID) {
					current = current->left;
				}
				else if (promoting_ID > current->post_ID) {
					current = current->right;
				}
			}
			
			
        //cout << "\tPost ID not found" << endl;
      
		}

    Heap(root);
  }


void promote_without_retirement (int promoting_ID,int Substitution_ID){

    releaseheap(root);
    int Manager_marks = 50;
    int Director_marks = 75;

    if (root == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* current = root;
			while (current != NULL){
				if (current->post_ID == promoting_ID) {
					
            if(current->Marks >=Director_marks){
              current->post_ID=Substitution_ID;
            }
            else if(current->Marks >=Manager_marks){
              current->post_ID=Substitution_ID;
            }
            else{
               cout<<"\tMarks insufficient for promotion";   
              }

              break;
				}
				else if (promoting_ID < current->post_ID) {
					current = current->left;
				}
				else if (promoting_ID > current->post_ID) {
					current = current->right;
				}
			}
			//cout << "\tPost ID not found" << endl;
		
		}

    Heap(root);
  }


  void retire (int decision,int k){

    releaseheap(root);
    
    	if (root == NULL) {
			cout << "\tList is empty" << endl;
		}
		else {
			Node* current = root;
			while (current != NULL){
				if (current->post_ID== k) {
					
           if (decision==1){
                  cout<<"\tInput the ID for promotion : ";
                  int P_ID;
                  cin>>P_ID;
                  promote(P_ID,current);
                  break;
                }
          else  {
                deleteNode (current->post_ID);
                break;        
              }
				break;}
				else if (k < current->post_ID) {
					current = current->left;
				}
				else if (k > current->post_ID) {
					current = current->right;
				}
			}
			//cout << "\tPost ID not found" << endl;	
		} 
    Heap(root);
  }

	void deleteNode(int key) {

    //Convert the heap to BST
    releaseheap(root);

		if (root == NULL) {
			cout << "\tList is empty" << endl;
		}
		else {
			Node* current = root;
			//move current pointer to the required key//
			while (current != NULL && current->post_ID != key) {
				if (key < current->post_ID) {
					current = current->left;
				}
				else if (key > current->post_ID) {
					current = current->right;
				}
			}
      
			//delete operations//
			if (current == NULL) {
				cout << "\t Searched ID does not exists" << endl; //key does not exists
			}
			else if (current->left == NULL && current->right == NULL) { //deleting a leaf node
				if (current == root) { //delete root node
					root = NULL;
				}
				if (current->post_ID < current->parent->post_ID) { //delete left leaf
					current->parent->left = NULL;
				}
				else { //delete right leaf
					current->parent->right = NULL;
				}
				delete current;
				size--;
			}
			else if (current->left == NULL) { //node to be deleted has right child

				if (current == root) {
					root = current->right;
					root->parent = NULL;
				}
				if (current->post_ID < current->parent->post_ID) { //current is in the left of parent 
					current->parent->left = current->right;
				}
				else { //current is in the right of parent
					current->parent->right = current->right;
				}
				delete current;
				size--;
			}
			else if (current->right == NULL) { //node to be deleted has a left child
				
				if (current == root) { //if current == root, make left child the root
					root = current->left;
					root->parent = NULL;
				}
				if (current->post_ID < current->parent->post_ID) {
					current->parent->left = current->left;
				}
				else {
					current->parent->right = current->left;
				}
				delete current;
				size--;
			}
			else { //node has 2 children
				//Here, the node to be deleted is replaced by the max value of the tree in the left side (method 1)
				//select node with lowest val from right,, might ask in exam (method 2)

				Node* max = current->left; //take left child as the max
				while (max->right != NULL) {
					max = max->right;
				}

				current->post_ID = max->post_ID; //assign max->key to current->key 
				//now, key of the node to be deleted is replaced by max key of that subtree


				if (max == current->left) {
					current->left = max->left; //max dont have aright child
					if (max->left != NULL) {
						max->left->parent = current;
					}
				}
				else {
					max->parent->right = max->left;//max->right doesnt exist. no ned to check
					if (max->left != NULL) {
						max->left->parent = max->parent;
					}
				}
				delete max;
				size--;
			}
		}
    Heap(root);
    }
	void swap(Node *first, Node *second) {
    
        int value = first->post_ID;
        string Name1=first->Employee_Name;
        int age =first->Age;
        int sal= first->Salary;
        int mrk= first->Marks; 
        int days= first->workingdays ; 
        int wt= first->weight ;
        int bon= first->bonus; 
      
        first->post_ID = second->post_ID;
        second->post_ID = value;
    
        first->Employee_Name = second->Employee_Name;
        second->Employee_Name = Name1;
    
        first->Age = second->Age;
        second->Age = age;
    
        first->Salary = second->Salary;
        second->Salary = sal;
    
        first->Marks = second->Marks;
        second->Marks = mrk;
    
        first->workingdays = second->workingdays;
        second->workingdays = days;
    
        first->bonus = second->bonus;
        second->bonus = value;
    
        first->weight = second->weight;
        second->weight = bon;
  }

        void swap_for_promote(Node *first, Node *second) {
    
        
        string Name1=first->Employee_Name;
        int age =first->Age;
        
        int mrk= first->Marks; 
        int days= first->workingdays ; 
        
    
        first->Employee_Name = second->Employee_Name;
        second->Employee_Name = Name1;
    
        first->Age = second->Age;
        second->Age = age;
    
        first->Marks = second->Marks;
        second->Marks = mrk;
    
        first->workingdays = second->workingdays;
        second->workingdays = days;
  
      }

	void Heap(Node* current) {
	    
        if (current == NULL)
            return;
        Heap(current->left);
        Heap(current->right);
        
        if (current->left != NULL && current->left->post_ID> current->post_ID) {
            swap(current, current->left);
            Heap(current);
        }
        
        if (current->right != NULL && current->right->post_ID > current->post_ID) {
            swap(current, current->right);
            Heap(current);
    }
  }

void releaseheap(Node* current) {
	    
        if (current == NULL)
            return;
        releaseheap(current->left);
        releaseheap(current->right);
        
        if (current->left != NULL && current->left->post_ID > current->post_ID) {
            swap(current, current->left);
            releaseheap(current);
        }
        
        if (current->right != NULL && current->right->post_ID < current->post_ID) {
            swap(current, current->right);
            releaseheap(current);
    }
  }

	void preorder(Node* node) {
		if (node != NULL) {
			cout << " | " << node->post_ID;
			preorder(node->left);
			preorder(node->right);
			return;
		}
	}

	void inorder(Node* node) {
		if (node != NULL) {
			inorder(node->left);
			cout << " | " << node->post_ID;
			inorder(node->right);
			return;
		}
	}

	void postorder(Node* node) {
		if (node != NULL) {
			postorder(node->left);
			postorder(node->right);
			cout << " | " << node->post_ID;
			return;
		}
	}

	void traverse(int method) {
		switch (method) {
		case 1:
			cout << "pre order : "; preorder(root); cout << endl;
			break;
		case 2:
			cout << "in order : "; inorder(root); cout << endl;
			break;
		case 3:
			cout << "post order : "; postorder(root); cout << endl;
			break;
		}
	}

//Function to calculate the salary
int salary (int Get_ID){

    releaseheap(root);

    if (root == NULL) {
			cout << "List is empty" << endl;
      return 0;
		}
		else {
			Node* current = root;
			while (current != NULL){
				if (current->post_ID == Get_ID) {
				
          int temp_Salary = current->Salary;                 
                
                int basic = 0 ;
                if (current->post_ID >= 17){
                  basic = 100000;
                  current->weight = 10;
                }
                else if (current->post_ID >= 12){
                 basic = 80000;
                  current->weight = 8;
                }
                else if (current->post_ID >= 9){
                 basic = 65000;
                  current->weight = 7;
                }
                else if (current->post_ID >= 6){
                 basic = 40000;
                  current->weight = 6;
                }
                else {
                  basic = 20000;
                  current->weight = 3;
                }
                if (current->Marks >= 100){
                  current->bonus = 30000;
                }
                else if(current->Marks >= 75){
                  current->bonus = 22500;
                }
                else if (current->Marks >= 50){
                  current->bonus = 15000;
                }
                else if (current->Marks >= 35) {
                  current->bonus = 5000;
                }
                else {
                  current->bonus = 0;
                }
               temp_Salary =  basic + 100 * current->workingdays * current->weight + current->bonus ;

          current->Salary=temp_Salary;
                  return temp_Salary;}
                  
				else if (Get_ID < current->post_ID) {
					current = current->left;
				}
				else if (Get_ID > current->post_ID) {
					current = current->right;
				}
  }
			cout << "Post ID not found" << endl;
      }
      Heap(root);
      return 0;
		}


  
  

int marks (int Get_ID,int addmarks ) {

  releaseheap(root);

  int temp_marks;
    
    if (root == NULL) {
     
			cout << "\tList is empty" << endl;
      return 0;
		}
		else {
      
			Node* current = root;
			while (current != NULL){

        static int y =0;
        
				if (current->post_ID == Get_ID) {
					
					temp_marks = current->Marks;
    
              temp_marks += addmarks; 
              current->Marks= temp_marks;
            return temp_marks ;

            break;
          
				}

          
				else if (Get_ID < current->post_ID) {
					current = current->left;
				}
				else if (Get_ID > current->post_ID) {
					current = current->right;
				}
        
          if(y==0){
           if (temp_marks >= 100){
              cout <<endl<< "\tRewarded..."<< endl;
            }
          else {
              cout << "\tWarning..." << endl; 
            }
            }

        y++;

        
			}
			cout << "\tPost ID not found" << endl;
    
			temp_marks = 0;
      Heap(root);
      return 0;
		}
  }

int check_marks (int Get_ID){
  
    return marks(Get_ID,0);
  }

};

