#include "BST.h"
#include <iostream>
#include<string>
#include<cctype>

using namespace std;

int main();
void Choices(int access, int ID);

BST bst;

//Function to give the accesss to the data and return a access value
int Check_Password_Admin(string s, int post_ID){
  string pw1 ="Chairman";//Chairman
  string pw2 ="Director1";//Director1
  string pw3 ="Director2";//Director2
  string pw4 ="Manager1";//Manager1
  string pw5 ="Manager2";//Manager2
  string pw8 ="Employee";//Employee

  int ID1=1;
  int ID2=2;
  int ID3=3;
  int ID4=4;
  int ID5=5;
  int ID8=8;
  
  if (s==pw1 && post_ID==ID1)
      return 1;
  else if (s==pw2 && post_ID==ID2)
      return 2;
  else if (s==pw3 && post_ID==ID3)
      return 2;
  else if (s==pw4 && post_ID==ID4)
      return 3;
  else if (s==pw5 && post_ID==ID5)
      return 3;
  else if (s==pw8 && post_ID==ID8)
      return 4;
  else{
    cout<<"Password or Post ID is incorrect. Please re-enter the Password and the Post ID"<<endl<<endl;
    return 0;
    }
}

//Function to add employee data to the system
void insert(int access, int ID){
    cout<<"*** Adding employees data to the system ***"<<endl<<endl;
  
  if (access)
  {
    cout<<"\tNo. of members to be added : ";
    int p;
    cin>>p;
    for (int i=0;i<p;i++)
    { 
    cout<<endl<<"\t ** Entering employee "<<i+1<< " Data **"<<endl<<endl;
      cout<<"\tEnter preffered Post ID  : " ;
      int ID ;
      cin >> ID ;
      
      cout<<"\tEnter your employee name : " ;
      string s ;
      cin >> s ;
      
      cout<<"\tEnter your employee Age  : " ;
      int a ;
      cin >> a ;

      //Calling the insert function
      bst.insert(ID,s,a);
      cout<<endl;
    }
  }
  else
    cout<<"\tYou cannot insert employee data"<<endl;

  int input;
  
  cout<<endl<<"\t 1 . Back to Main Menu"<<endl;
  cout<<"\t 2 . Re-Login"<<endl;
  cout<<"\t 3 . Exit"<<endl<<endl;
  cout<<"\t Enter your choice : ";
  cin>>input;
  cout<<endl;

  if (input==1)  
    Choices(access,  ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"Thank you, Have a Good day!!!";
}

//function to search data 
void search_details(int access, int ID){

  cout<<"*** Searching Employee Details ***"<<endl<<endl;
  
    if (access!=0)
    {
      int k;
      cout<<"\tInsert the Post ID to be searched : ";
      cin>>k;
      cout<<endl;
      
       if (access== 1 && k>=1)
        bst.print_values(k);
      else if (access== 2 && k==1 )
      cout<<"\tYou are not allowed to access this data";
      else if (access== 2 && k>=2 )
        bst.print_values( k);
      else if (access== 3 && k==1  || access== 3 && k==2 )
      cout<<"\tYou are not allowed to access this data";
      else if (access== 3 && k==3 )
        bst.print_values( k);
    }

    if (access== 0)
    bst.print_values(ID);

  int input;
  cout<<endl<<"\t 1 . Back to Main Menu"<<endl;
  cout<<"\t 2 . Re-Login"<<endl;
  cout<<"\t 3 . Exit"<<endl<<endl;
  cout<<"Enter your choice : ";
  cin>>input;
  cout<<endl;

  if (input==1)
    Choices(access, ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"Thank you Have a Good day!!!";
}

//Function to promote an employee
void promote(int access,int ID)
{
  cout<<"***Promoting an employee"<<endl<<endl;
  
  int k; //Post Id that need to be promoted
  cout<<"\tInsert the Post ID to be promoted    : ";
  cin>>k;
  
  int t; //Targeted post ID to promote
  cout<<"\tInsert the target Post ID to promote : ";
  cin>>t;

    if (access== 1 && k>1)
    bst.promote_without_retirement(k,t);

    else if (access== 2 && k==1 )
    cout<<"\tYou are not allowed to promote";
      
    else if (access== 2 && k>2 )
    bst.promote_without_retirement(k,t);

    else if (access== 3 && k==1  || access== 3 && k==2 )
    cout<<"\tYou are not allowed to promote";

    else if (access== 3 && k==0 )
    bst.promote_without_retirement(k,t);

    else if (access== 0 && k==1 ||access== 0 && k==2 || access== 0 && k==3 )
    cout<<"\tYou are not allowed to promote";

    else
    cout<<"\tYou are not allowed to use this option";

  int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl<<endl;
  cout<<"\tEnter your choice : ";
  cin>>input;
  cout<<endl;

  if (input==1)
    Choices(access,  ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"\tThank you Have a Good day!!!";  
}

//Function to retire an employee
void retire(int access,int ID){
  cout<<"\t*** To retire an employee ***"<<endl<<endl;
  
  int k ; // The post that need to retire
  cout<<"\tInsert the Post ID to be retired : ";
  cin>>k;
  
  int selection;
  //When need to promote another employee for the position
  cout<<endl<<"\t1. Want to promote another employee for this position"<<endl;

  //Only to retire the employee
  cout<<"\t2. Only for retirement of this employee"<<endl<<endl;
  cout<<"\tEnter your option : ";
  cin>>selection;
  cout<<endl;

   if (access== 1 && k>1)
    bst.retire (selection,k);

    else if (access== 2 && k==1 )
    cout<<"\tYou are not allowed to use this option";
      
    else if (access== 2 && k>2 )
    bst.retire (selection,k);

    else if (access== 3 && k==1  || access== 3 && k==2 )
    cout<<"\tYou are not allowed to use this option";

    else if (access== 3 && k==0 )
    bst.retire (selection,k);

    else if (access== 0 && k==1 ||access== 0 && k==2 || access== 0 && k==3 )
    cout<<"\tYou are not allowed to use this option";

    else
      cout<<"\tYou are not allowed to use this option";
  
  int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl<<endl;
  cout<<"\tEnter your choice : ";
  cin>>input;
  cout<<endl;

  //Returning back to the main menu
  if (input==1)
    Choices(access,  ID);

  //Returning to the main function to re login
  else if (input ==2)
    main();

    //Exit
  else
    cout<<endl<<"\tThank you Have a Good day!!!";
  
}

//Function print all the values 
void printall(int access, int ID){
  
    if (access)
    {
    bst.print();
    }

    else
      cout<<"\tYou are not allowed to use this option";
   
  int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl<<endl;
  cout<<"\tEnter your choice : ";
  cin>>input;
  cout<<endl;

  if (input==1)
    Choices(access,  ID);
  
  else if (input ==2)
    main();
  else
    cout<<endl<<"\tThank you Have a Good day!!!";
  
}

//calling the salary calculation function by considering the access
void salary_calulation(int access,int ID){

    cout<<"\t*** Calculation of the salary *** "<<endl<<endl;
    int sal;
    if (access!=0)
    {
    int k;
    cout<<"\tInsert the Post ID to calculate the salary : ";
    cin>>k;
    cout<<endl;

    if (access== 1 && k== 1)
     sal=bst.salary(k);

    else if (access== 1 && k>=1)
    sal=bst.salary(k);

    else if (access== 2 && k==1 )
    cout<<"\tYou are not allowed to access this data";
      
    else if (access== 2 && k>=2 )
    sal=bst.salary(k);

    else if (access== 3 && k==1  || access== 3 && k==2 )
    cout<<"\tYou are not allowed to access this data";

    else if (access== 3 && k==3 )
    sal=bst.salary(k);

  }
   if (access== 0 )
    sal=bst.salary( ID);


  cout<<"\tThe current salary :  "<<sal<<endl;
    
 int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl<<endl;
  cout<<"\tEnter your choice : ";
  cin>>input;
  cout<<endl;
  
  if (input==1)
    Choices(access,  ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"\tThank you Have a Good day!!!";
}

//Calling the marks function by considering the access
void Add_marks(int access, int ID){

  cout<<"\t*** Add marks ***"<<endl<<endl;
  int k; //Post ID to add the marks
  cout<<"\tInsert the Post ID to add marks :";
  cin>>k;
  
  int m;//Marks that need to be added
  cout<<endl<<"\tInsert Marks for addition       :";
  cin>>m;

  //Giving access to add marks
  if (access== 1 && k>1)
    bst.marks ( k,m );

    else if (access== 2 && k==1 )
    cout<<"\tYou are not allowed to use this option";
      
    else if (access== 2 && k>2 )
    bst.marks ( k,m );

    else if (access== 3 && k==1  || access== 3 && k==2 )
    cout<<"\tYou are not allowed to use this option";

    else if (access== 3 && k==0 )
    bst.marks ( k,m );

    else if (access== 0 && k==1 ||access== 0 && k==2 || access== 0 && k==3 )
    cout<<"\tYou are not allowed to use this option";

    else
    cout<<"\tYou are not allowed to use this option";

  int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl<<endl;
  cout<<"\tEnter your option : ";
  cin>>input;
  cout<<endl;

  if (input==1)
    Choices(access,  ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"\tThank you Have a Good day!!!";
}

//Function to search marks
void Search_marks(int access,int ID){

  cout<<"\tSearch marks"<<endl<<endl;
  int m=bst.check_marks (ID);
  cout<<"\tMarks for this employee is "<<m<<endl;
    
 int input;
  cout<<endl<<"\t1 . Back to Main Menu"<<endl;
  cout<<"\t2 . Re-Login"<<endl;
  cout<<"\t3 . Exit"<<endl;
  cout<<"\tEnter your option : ";
  cin>>input;
  cout<<endl;

  if (input==1)
    Choices(access,  ID);
  else if (input ==2)
    main();
  else
    cout<<endl<<"\tThank you Have a Good day!!!";
}

//Function to select the operation needed to be done
void Choices(int access, int ID)
{

  int choice;
  //access given only to chairman,director, manager
  if (access==1 || access==2 || access==3 )
  {  
    cout<<"\t MAIN MENU"<<endl<<endl;
    cout<<"\t 1. Add Employee"<<endl;
    cout<<"\t 2. Search Employee details"<<endl;
    cout<<"\t 3. Promote an Employee "<<endl;
    cout<<"\t 4. Retire an Employee"<<endl;
    cout<<"\t 5. Print all Post ID's"<<endl;
    cout<<"\t 6. Calculate Salary of an Employee"<<endl;
    cout<<"\t 7. Add marks"<<endl;
    cout<<"\t 8. Search Marks"<<endl;
  }

  //Employee have access to his or her data only
  else if(access == 4)  
  {
    cout<<"\tDisplaying your details"<< endl;
    bst.print_values(ID); 
    cout << endl; 
    return;
  }

   cout<<endl<<"\tEnter your Choice :  ";
   cin>>choice;
   cout<<endl;

    switch (choice) {
		case 1:
      //calling the insert function
			 insert(access,ID); 
      cout<<"\tDetails are inserted"<<endl;
      cout << endl;
			break;
		case 2:
      //Calling the search function
			search_details( access,ID); cout << endl;
			break;
		case 3:
      //Callling the promote function
			promote( access,ID); cout << endl;
			break;
     case 4:
       //Calling the retire function
			 retire( access,ID); cout << endl;
			break;
      case 5:
        //Calling the print function
			 printall(access,ID) ; cout << endl;
			break;
      case 6:
        //calling the salary calculation function
			 salary_calulation( access,ID); cout << endl;
			break;
      case 7:
        //Calling the add marks function
			 Add_marks( access,ID); 
      cout<<"\tMarks are added"<<endl;
      cout << endl;
			break;
      case 8:
        //Calling the search mark function
			 Search_marks( access,ID); cout << endl;
			break;
		}
    
   }


int main() {

  cout<<"******* EMPLOYEE MANAGEMENT SYSTEM *******"<<endl<<endl;
  
int Post_ID;    //Post ID of the employee
string PW;      //Password

  //While loop until a correct Post ID and PW given
  while (1)
  {
    //Obtaining the Post ID
    cout<<"Enter your Post_ID : ";
    cin>>Post_ID;
    
    //Obtaining the password 
    cout<<endl<<"Enter your PW : ";
    cin>>PW;
    cout<<endl;

    //Terminating the loop when password and post ID is correct
    if (Check_Password_Admin(PW,Post_ID)!=0)
    {
      break;
    }
 } 

// Initiating the access level to 0
int access_level=0;
  
if (Check_Password_Admin(PW, Post_ID)==1)
  {//Giving access to the Chairman
  cout<<"\t*** Welcome Chairman ***"<<endl<<endl;
   access_level = 1;
  }
  
else if (Check_Password_Admin(PW , Post_ID)==2)
 {//Giving access to the director
  cout<<"\t*** Welcome Director ***"<<endl<<endl;
   access_level = 2;
  }
  
else if (Check_Password_Admin(PW , Post_ID)==3)
{//Giving access to the manager
  cout<<"\t*** Welcome Manager ***"<<endl<<endl;
  access_level = 3;
}

else if (Check_Password_Admin(PW, Post_ID)==4)
  { //Giving access to the employee
   access_level = 4;
  } 
  
else
  access_level = 0;

  //static int is used to ensure the data members won't insert a second time
  // It stays incrementing each time the main function calls
  static int i =0;
  
  // Inserting Data-(insert(Employee Post ID,Employee Name,Employee Age))
  if (i==0)
  {
  bst.insert(1,"Andy",24);
  bst.insert(2,"Erik",23);
	bst.insert(3,"Sara",23);
	bst.insert(4,"Lucas",23);
	bst.insert(5,"Andy",23);
	bst.insert(6, "Amy", 32);
	bst.insert(7, "Lisa",21);
	bst.insert(8, "Leo",19);
	bst.insert(9, "David",24);
	bst.insert(10, "Olivia",23);
	bst.insert(11, "Daniel",18);
	bst.insert(12, "Thomas",44);
	bst.insert(13, "Emily",32);
	bst.insert(14, "John",28);
  bst.insert(15, "Sophia",20);
  bst.insert(16, "Emma",21);
  bst.insert(17, "Robert",25);
  bst.insert(18, "Bella",26);
  }

  i++;

Choices(access_level,Post_ID);
cout<<endl;

return 0;
}
