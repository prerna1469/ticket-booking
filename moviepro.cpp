//============================================================================
// Name        : moviepro.cpp
// Author      : Sanjana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Admin
{
	public:
	string username;
	string password;
	int duration;
	string date;
	double price;
	string movie_name;
	string movie_time;
	Admin()
	{
		duration=0;
		date="\0";
		movie_name="\0";
		movie_time="\0";
		username="Username";
		password="Password";
		price=0.0;
	}

	void display_movie();
	void accept_movie();
	void update_movie();
	void change_userdetails();

};
class Node
{
	int value;
	int rowpos;
	int colpos;
	Node *link;
	friend class List;
	public:
	Node()
	{
		value=0;
		rowpos=0;
		colpos=0;
		link=NULL;
	}
};

class List:public Admin
{
	Node *head;
	int sparsematrix[4][6]={{0,0,0,0,0,0},
	{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
	int seat_count;
	int lefts=0;
	public:
	List(){
	head=NULL;
	seat_count=0;
	}
	void booktickets();
	void displaymyticket();
};
class User
{
    string name;
    int age;
    long phoneno;
    string email;
public:
    User()
    {
        name="\0";
        age=0;
        phoneno=0;
        email="\0";
    }
    void accept();
    void display();
};

void Admin::accept_movie()
{
	string str;
	cout<<"\n enter the name of the movie here:";
	getline(cin,str);
	getline(cin,movie_name);
	cout<<"\n enter the date of show:";
	getline(cin,date);
	cout<<"\n enter the start time here:";
	getline(cin,movie_time);
	cout<<"\n enter the duration of the movie:";
	cin>>duration;
	cout<<"\n enter the price per seat here:";
	cin>>price;
}
void Admin::display_movie()
{
	cout<<"\n name of the movie:";
	cout<<movie_name;
	cout<<"\n date of the movie:";
	cout<<date;
	cout<<"\n time of the show according to 24 hr clock:";
	cout<<movie_time;
	cout<<"\n duration of the movie:";
	cout<<duration<<"hr";
	cout<<"\n price per seat is :";
	cout<<price;
	cout<<"\n";
}
void Admin::change_userdetails()
{
	int c;
	string str;
	string user;
	string pass;
	cout<<"\n enter 1 to change the username \n enter 2 to change the password \n enter 3 to change both";
	cin>>c;
	if(c==1)
	{

	do{
		cout<<"enter the valid old username here";
		getline(cin,str);
		getline(cin,user);
	}while(user.compare(username)!=0);
	cout<<"\n enter new username here:";
	getline(cin,username);
	cout<<"\n your new username is:";
	cout<<username;
	}
	else if(c==2)
	{
		do{
			cout<<"\n enter the valid old password here:";
			getline(cin,str);
			getline(cin,pass);
		}while(pass.compare(password)!=0);

		cout<<"\n enter the new pass word here:";
		getline(cin,password);
		cout<<"\n new password is:";
		cout<<password;
	}
	else if(c==3)
	{
		do{
			cout<<"\n enter the valid old username here";
			getline(cin,str);
			getline(cin,user);
		}while(user.compare(username)!=0);
		cout<<"\n enter new username here:";
		getline(cin,username);
		cout<<"\n your new useranme is:";
		cout<<username;
		do{
			cout<<"\n enter the valid old password here:";
			getline(cin,pass);
		   }while(pass.compare(password)!=0);
		cout<<"\n enter the new pass word here:";
		getline(cin,password);
		cout<<"\n new password is:";
		cout<<password;
		}
}
void Admin::update_movie()
{
    int choice=0;
    string str;
    cout<<"\n 1.Change date of movie";
    cout<<"\n 2.Change time of movie";
    cout<<"\n 3.Change both date and time of movie";
    cout<<"\n Enter choice";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"\n Enter new date of movie : ";
        		getline(cin,str);
                getline(cin,date);
                break;
        case 2: cout<<"\n Enter new time of movie : ";
        		getline(cin,str);
                getline(cin,movie_time);
                break;
        case 3: cout<<"\n Enter new date of movie : ";
        		getline(cin,str);
                getline(cin,date);
                cout<<"\n Enter new time of movie : ";
                getline(cin,movie_time);
                break;
    }
}


void List::displaymyticket()
{
	int m,n;
	cout<<"  0 1 2 3 4";
	cout<<"\n";
	cout<<" __________";
	for(m=0;m<4;m++)
	{
		cout<<m;
		cout<<" ";
	  for(n=0;n<6;n++)
	  {
		 cout<<sparsematrix[m][n];
		 cout<<" ";
	  }
	  cout<<"\n";
	}

}

void List::booktickets()
{
	int i,j;
	Node *temp;
	Node *ptr;
	int n=0,count=0;
	do{
		lefts=24-seat_count;
		cout<<"\n number of seats left :";
		cout<<lefts;
		cout<<"\n enter the number of seats you want to book:\n ";
	   cin>>n;
	}while(n<=0||n>lefts);
	   do
	   {
		temp=new Node();

		cout<<"enter the row number here:";
		cin>>temp->rowpos;
		cout<<"enter the column number here:";
		cin>>temp->colpos;


		temp->value=1;

		if(head==NULL)
		{
		head=temp;
		}
		else
		{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
		temp->link=NULL;
		}
		i=temp->rowpos;
		j=temp->colpos;
		sparsematrix[i][j]=1;
		count++;
		seat_count++;
		//no. of seat counter for multiple seats
	   }while(count!=n);
	cout<<"\n your ticket has successfully been booked!\n ";
	cout<<"BILL\n ";
	cout<<"movie name:";
	cout<<"\t";
	cout<<movie_name;
	cout<<"\n";
	cout<<"date:";
	cout<<"\t";
	cout<<date;
	cout<<"\n";
	cout<<"amount to be paid:";
	cout<<" ";
	cout<<price*n;
	cout<<"\n";
}

void User::accept()
{
    int cnt=0;
    string str;
    cout<<"\n Enter your name : ";
    getline(cin,str);
    getline(cin,name);
    cout<<"\n Enter your age : ";
    cin>>age;
    do
	{   //validation for phone number,i.e; it should be 10 digits
		cout<<"\n Enter your mobile number : ";
        cin>>phoneno;
		cnt=0;
		long d=0,temp=0;
	    temp=phoneno;
	    while(temp>0)
	    {
	        d=temp%10;
	        cnt++;
	        temp=temp/10;
	    }
		if(cnt!=10)
		{
		    cout<<"\n Invalid phone no. Enter again";
		}
	}while(cnt!=10);
	size_t f1 = email.find("@");
	size_t f2 = email.find(".com");
	size_t f3 = email.find(".in");
	do
	{
    	cout<<"\n Enter your email id : ";
    	getline(cin,str);
        getline(cin,email);
        if(f1!=string::npos && (f2!=string::npos || f3!=string::npos))
        {
            cout<<"\n Invalid email id. Please enter again";
        }
	}while(f1!=string::npos && (f2!=string::npos || f3!=string::npos));
}
void User::display()
{
    cout<<"\n Name of user : "<<name;
    cout<<"\n Age of user : "<<age;
    cout<<"\n Mobile number of user : "<<phoneno;
    cout<<"\n Email id of user : "<<email;
}




int main()
{
	List movie[10];
	Admin ob;
	User ob1[10];
	int movie_no=0,i=0;
	int ch=0;
	string mn,user,pass;
	string str;
	int choice=0;
	int c=0;
	int movie_ch=0;
	char customer_ch;
	do
	{
		cout<<"\n 1.Admin";
		cout<<"\n 2.Customer";
		cout<<"\n 0. Exit";
		cout<<"\n enter choice here:";
		cin>>choice;

		switch(choice)
		{   case 0:
					cout<<"______________________________________";
					break;
			case 1:
				cout<<"\n enter the username here: ";
				getline(cin,str);
				getline(cin,user);
				cout<<"\n enter the password here: ";
				getline(cin,pass);
				if(ob.username.compare(user)==0&&ob.password.compare(pass)==0)
				{
					cout<<"\n enter the number of movies to show here:";
					cin>>movie_no;
					for(i=1;i<=movie_no;i++)
					{
					 movie[i].accept_movie();
					}
					do{
						cout<<"\n 1. display movie list";
						cout<<"\n 2. add a movie";
						cout<<"\n 3. update a movie details";
						cout<<"\n 4. change admin details";
						cout<<"\n 0.exit";
						cout<<"\n Enter your choice here:";
						cin>>ch;
						switch(ch)
						{   case 0:
			    	             cout<<"______________________________________";
			    	              break;
							case 1:
								for(i=1;i<=movie_no;i++)
								{
								  movie[i].display_movie();
								  cout<<"\n";
								}
								break;
							case 2:
								movie[movie_no+1].accept_movie();
								movie_no++;
								break;
							case 3:
								cout<<"\n Enter the name of the movie to be updated here:";
								getline(cin,str);
								getline(cin,mn);
								for(i=1;i<=movie_no;i++)
								{
									if(mn.compare(movie[i].movie_name)==0)
									{
										cout<<"\n movie found";
										movie[i].display_movie();
										movie[i].update_movie();
										break;
									}
									else
									{
										cout<<"\n movie not found!!";
										//ask for the correct movie name agian and direct the user
									}
							}
							break;
						case 4:
							ob.change_userdetails();
							break;

					}
				}while(ch!=0);
		 }
		 else{
		     cout<<"username or password incorrect!!";
		 }
				break;
			case 2:
        			c++;
        			ob1[c].accept();
        			cout<<"\ndo you want to book tickets? \n type 'y' for yes and 'n' for no: ";
        		    cin>>customer_ch;
        		    if(customer_ch=='y'||customer_ch=='Y')
        		    {
        		        cout<<"the movie list is: \n";
        		        	for(i=1;i<=movie_no;i++)
							{
							    cout<<i;
                              movie[i].display_movie();
                              cout<<"\n";
							}
							cout<<"enter the choice here:\n";
							cin>>movie_ch;
							for(i=1;i<=movie_no;i++)
							{
							    if(movie_ch==i)
							    {
			                        movie[i].displaymyticket();
			                        movie[i].booktickets();
			                        movie[i].displaymyticket();
							    }
							}
        		    }

		}
	}while(choice!=0);

}
