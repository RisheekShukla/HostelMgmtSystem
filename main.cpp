#include <bits/stdc++.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <iomanip>
#include <windows.h>
#include <sstream>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "Risheek@14";
const char* DB = "extra";
MYSQL* conn;

// //////////////////////////////////////
string convertIt(int num)
	{
		stringstream ss;
		ss<<num;
		string str = ss.str();
		return str;
	}
	
class hostel
{
	public:
	int IdNumber;
	string Name;
	int room;
	string roomate;
	bool outpass_req;
	bool clean_req;
	int contact;
	int parent_contact;	
};

class Admin : public hostel
{
	 string pass = "123@abc";
	
public:
	
		Admin(string get_pass)
		{
			if(get_pass == pass)
			{
				cout<<"****  ADMIN SUCCESSFULLY LOGGED IN  ****"<<endl;
				cout<<endl;
				cout<<endl;
			}
			else
			{
				cout<<"<<<<  WRONG ADMIN KEY  >>>>"<<endl;
				exit(10);
			}
		}
		
		void All_details()
		{
			
			string select = "SELECT * FROM HOSTEL";
			if(mysql_query(conn,select.c_str()))
			{
				
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else
			{
				MYSQL_RES* res; 
				res= mysql_store_result(conn);
				if(res)
				{
					int num_field = mysql_num_fields(res);
					
					// Fetch and print the column names
		            MYSQL_FIELD *field;
		            while ((field = mysql_fetch_field(res)))
		            {
		                cout << setw(10)<<field->name << "\t";
		            }
		            cout << endl;
					cout<<endl;
					// Fetch and print the actual data
		            MYSQL_ROW row;
		            while ((row = mysql_fetch_row(res)))
		            {
		                for (int i = 0; i < num_field; i++)
		                {
		                    cout <<setw(10)<< row[i] << "\t";
		                }
		                cout << endl;
            		}
           			mysql_free_result(res);
				}
			}
		}
		
		void add_student()
		{
			cout<<"----------- PLEASE ENTER THE DETAILS -----------"<<endl<<endl;
			cout<<"Enrollment Number : ";
			cin>>IdNumber;
			cout<<"Name : ";
			cin>>Name;
			cout<<"Room Number : ";
			cin>> room;
			cout<<"Room Mate : ";
			cin>> roomate;
			cout<<"Contact Number : ";
			cin>> contact;
			cout<<"Parent Contact : ";
			cin>> parent_contact;	
			string idn = convertIt(IdNumber);
			string rn = convertIt(room);
			string cnt = convertIt(contact);
			string par = convertIt(parent_contact);
			string odr = "0";
			// query creation
			string insert = "INSERT INTO HOSTEL VALUES ('"+idn+"','"+Name+"','"+rn+"','"+roomate+"','"+odr+"','"+odr+"','"+cnt+"','"+par+"')";
			if(mysql_query(conn,insert.c_str()))
			{
				cout<<"ERROR: "<<mysql_error(conn)<<endl;
			}
			else
			{
				cout<<"^^^^^^^^ DATA INSERTED ^^^^^^^^^^"<<endl;
			}
		}
		
		void delete_student()
		{
			cout<<"----------- PLEASE ENTER THE DETAILS -----------"<<endl<<endl;
			cout<<"Enrollment Number : ";
			cin>>IdNumber;
			string idn = convertIt(IdNumber);
			// query creation
			string delet = "DELETE FROM HOSTEL WHERE ENROLL = '"+idn+"'";
			if(mysql_query(conn,delet.c_str()))
			{
				cout<<"ERROR: "<<mysql_error(conn)<<endl;
			}
			else
			{
				cout<<"!!!!!!!!!! DATA DELETED !!!!!!!!!!!"<<endl;
			}
		}
		
		void update_student()
		{
			cout<<endl<<endl;
			cout<<" Choose the detail to be updated"<<endl<<endl;
			cout<<"\t1. Enrollment Number"<<endl;
			cout<<"\t2. Name"<<endl;
			cout<<"\t3. Room Number "<<endl;
			cout<<"\t4. Room Mate"<<endl;
			cout<<"\t5. Contact Number"<<endl;
			cout<<"\t6. Parent Contact"<<endl<<endl;
			cout<<"ENTER THE CHOICE : ";
			int n;
			cin>>n;
			string deci;
			string cont;
			string enroll;
			cout<<"Enter Enrollment : ";
			cin>>enroll;
			cout<<"Enter new value : ";
			cin>>cont;
			switch(n)
			{
				case 1:
					deci = "enroll";
					break;
				case 2:
					deci = "name";
					break;
				case 3:
					deci = "room";
					break;
				case 4:
					deci = "roomate";
					break;
				case 5:
					deci = "phone";
					break;
				case 6:
					deci = "parentcon";
					break;
				default:
					cout<<"ERROR !! CHOOSE FROM THE GIVEN CHOICES."<<endl;
			}
			// query creation
			string update = "UPDATE HOSTEL SET "+deci+" = '"+cont+"' WHERE ENROLL='"+enroll+"'";
			if(mysql_query(conn,update.c_str()))
			{
				cout<<"ERROR: "<<mysql_error(conn)<<endl;
			}
			else
			{
				cout<<"~~~~~~~~~~ DATA UPDATED ~~~~~~~~~~~"<<endl;
			}
		}
		
		void aget_details(int enrolly)
		{
			string enr = convertIt(enrolly);
			string select = "SELECT * FROM HOSTEL WHERE ENROLL='"+enr+"'";
			if(mysql_query(conn,select.c_str()))
			{
				
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else
			{
				MYSQL_RES* res; 
				res= mysql_store_result(conn);
				if(res)
				{
					int num_field = mysql_num_fields(res);
					
					// Fetch and print the column names
		            MYSQL_FIELD *field;
		            while ((field = mysql_fetch_field(res)))
		            {
		                cout << setw(10)<<field->name << "\t";
		            }
		            cout << endl;
					cout<<endl;
					// Fetch and print the actual data
		            MYSQL_ROW row;
		            while ((row = mysql_fetch_row(res)))
		            {
		                for (int i = 0; i < num_field; i++)
		                {
		                    cout <<setw(10)<< row[i] << "\t";
		                }
		                cout << endl;
            		}
           			mysql_free_result(res);
				}
			}
		}
};


class student : public hostel
{
	public:
		void sget_details(int enroll)
		{
			string enr = convertIt(enroll);
			string select = "SELECT * FROM HOSTEL WHERE ENROLL = '"+enr+"'";
			if(mysql_query(conn,select.c_str()))
			{
				
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else
			{
				MYSQL_RES* res; 
				res= mysql_store_result(conn);
				if(res)
				{
					int num_field = mysql_num_fields(res);
					
					// Fetch and print the column names
		            MYSQL_FIELD *field;
		            while ((field = mysql_fetch_field(res)))
		            {
		                cout << setw(10)<<field->name << "\t";
		            }
		            cout << endl;
					cout<<endl;
					// Fetch and print the actual data
		            MYSQL_ROW row;
		            while ((row = mysql_fetch_row(res)))
		            {
		                for (int i = 0; i < num_field; i++)
		                {
		                    cout <<setw(10)<< row[i] << "\t";
		                }
		                cout << endl;
            		}
           			mysql_free_result(res);
				}
			}
		}
		
		void request_out(int enroll)
		{
			string enr = convertIt(enroll);
			string update = "UPDATE HOSTEL SET OUTPASS = 1 WHERE Enroll ='"+enr+"'";
			if(mysql_query(conn,update.c_str()))
			{
				
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else
			{
				cout<<"----- SUCCESSFULLY REQUESTED FOR OUTPASS ------ "<<endl;
			}
		}
		
		void clean_req(int enroll)
		{
			string enr = convertIt(enroll);
			string update = "UPDATE HOSTEL SET CLEANREQ = 1 WHERE Enroll ='"+enr+"'";
			if(mysql_query(conn,update.c_str()))
			{
				
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else
			{
				cout<<"----- SUCCESSFULLY REQUESTED FOR ROOM CLEANING ------ "<<endl;
			}
		}
		
		void roomate_details(int enroll)
		{
			return;
		}
		
};

int main()
{
//	MYSQL* conn;
	conn = mysql_init(NULL);
	if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0))
	{
		cout<<"ERROR: "<<mysql_error(conn)<<endl;
	}
	else
	{
		cout<<"::::::::::::: LOGGED IN THE DATABASE ::::::::::::::"<<endl;
		cout<<endl;
	}		
//	Admin a1("123@abc");
//	student s1;
//	s1.request_out(191);
//	s1.get_details(199);
//	a1.All_details();
//	a1.add_student();
//	a1.delete_student();
//	a1.update_student();
//	a1.get_details(convertIt(191));

	bool exit=false;
	while(!exit)
	{
		system("cls");
		cout<<">-------------->		WELCOME TO HOSTEL MANAGEMENT SYSTEM		<--------------<"<<endl;
		cout<<endl<<endl<<"WHO ARE YOU ??"<<endl;
		cout<<"\t1. WARDEN "<<endl;
		cout<<"\t2. STUDENT "<<endl;
		cout<<"\t3. EXIT "<<endl;
		cout<<"ENTER YOUR CHOICE: ";
		int who;
		cin>>who;
		if(who==1)
		{
			cout<<"Enter your SECURITY KEY : ";
			string str;
			cin>>str;
			Admin a1(str);
			cout<<endl<<endl<<" >> ENTER THE OPERATIONS "<<endl;
			cout<<"\t1. ALL DETAILS "<<endl;
			cout<<"\t2. ADD STUDENT "<<endl;
			cout<<"\t3. DELETE STUDENT "<<endl;
			cout<<"\t4. UPDATE STUDENT "<<endl;
			cout<<"\t5. GET STUDENT DETAIL "<<endl;
			cout<<"\t6. EXIT "<<endl;
			cout<<"ENTER YOUR CHOICE: ";
			int so;
			cin>>so;
			switch(so)
			{
				case 1:
					a1.All_details();
					break;
				case 2:
					a1.add_student();
					break;
				case 3:
					a1.delete_student();
					break;
				case 4:
					a1.update_student();
					break;
				case 5:
					int enrolls;
					cout<<"ENTER THE ENROLLMENT : ";
					cin>>enrolls;
					a1.aget_details(enrolls);
					break;
				default:
					cout<<"ERROR!! Enter the correct operation"<<endl;
			}
			Sleep(9000);
		}
		else if(who==2)
		{
			student s1;
			cout<<endl<<endl<<" >> ENTER THE OPERATIONS "<<endl;
			cout<<"\t1. GET DETAILS "<<endl;
			cout<<"\t2. REQUEST OUTPASS "<<endl;
			cout<<"\t3. CLEANING REQUEST "<<endl;
			cout<<"\t4. EXIT "<<endl;
			cout<<"ENTER YOUR CHOICE: ";
			int so;
			cin>>so;
			switch(so)
			{
				case 1:
					int enrolls1;
					cout<<"ENTER THE ENROLLMENT : ";
					cin>>enrolls1;
					s1.sget_details(enrolls1);
					break;
				case 2:
					int enrolls2;
					cout<<"ENTER THE ENROLLMENT : ";
					cin>>enrolls2;
					s1.request_out(enrolls2);
					break;
				case 3:
					int enrolls3;
					cout<<"ENTER THE ENROLLMENT : ";
					cin>>enrolls3;
					s1.clean_req(enrolls3);
					break;
				default:
					cout<<"ERROR!! Enter the correct operation"<<endl;
			}
			Sleep(9000);
		}
		else
		{
			exit = true;
			Sleep(9000);
		}
	}
}

// ////////////////////////////////////

//class Hostel
//{
//	private:
//		string name;
//		int bed;
//		int fee;
//		
//	public: 
//	
//		Hostel(string name,int bed,int fee)
//		{
//			this->name = name;
//			this->bed = bed;
//			this->fee = fee;
//		}	
//		
//		string getName()
//		{
//			return name;
//		}
//		
//		int getBed()
//		{
//			return bed;
//		}
//		
//		int getFee()
//		{
//			return fee;
//		}
//	
//};
//
//int main() 
//{
//	
//	MYSQL* conn;
//	conn = mysql_init(NULL);
//	if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0))
//	{
//		cout<<"ERROR: "<<mysql_error(conn)<<endl;
//	}
//	else
//	{
//		cout<<"LOGGED IN THE DATABASE"<<endl;
//	}
//	Sleep(3000);
//	Hostel h1("Risheek",2,55000);
//	
//	int intB = h1.getBed();
//	stringstream ss;
//	ss<<intB;
//	string strB = ss.str();
//	
//	int intf = h1.getFee();
//	stringstream st;
//	st<<intf;
//	string strf = st.str();
//	
//	string insert = "INSERT INTO hostel (Name,Bed,Fee) VALUES ('"+h1.getName()+"','"+strB+"','"+strf+"')";
//	if(mysql_query(conn,insert.c_str()))
//	{
//		cout<<"ERROR: "<<mysql_error(conn)<<endl;
//	}
//	else
//	{
//		cout<<"DATA INSERTED"<<endl;
//	}
//	
//	bool exit=false;
//	while(!exit)
//	{
//		system("cls");
//		cout<<"WELCOME TO HOSTEL MANAGEMENT SYSTEM"<<endl;
//		cout<<"***********************************"<<endl;
//		cout<<"1. RESERVE BED: "<<endl;
//		cout<<"2. EXIT: "<<endl;
//		cout<<"ENTER YOUR CHOICE: ";
//		int val;
//		cin>>val;
//		
//		if(val==1)
//		{
//			string n;
//			cout<<"Enter student Name: ";
//			cin>>n;
//			int total;
//			
//			string check = "SELECT Bed FROM hostel Name = '"+h1.getName()+"'";
//			if(mysql_query(conn,check.c_str()))
//			{
//				cout<<"Error: "<<mysql_error(conn)<<endl;
//			}
//			else
//			{
//				MYSQL_RES* res; 
//				res= mysql_store_result(conn);
//				if(res)
//				{
//					MYSQL_ROW row = mysql_fetch_row(res);
//					if(row)
//					{
//						total = atoi(row[0]);
//					}
//					mysql_free_result(res);
//				}
//			}
//			if(total > 0)
//			{
//				total--;
//				stringstream zs;
//				zs<<total;
//				string strT = zs.str();
//				
//				string update= "UPDATE hostel SET Bed = '"+strT+"' WHERE Name='"+h1.getName()+"' ";
//				if(mysql_query(conn,update.c_str()))
//				{
//					cout<<"Error: "<<mysql_error(conn)<<endl;
//				}
//				else
//				{
//					cout<<endl;
//					cout<<"Bed is Reserved Successfuly in "<<h1.getName()<< " Hostel For Student "<<n<<endl;
//					cout<<"Please Pay "<<h1.getFee()<<" Rupees."<<endl;
//				}
//			}
//			else if(total ==0)
//			{
//				cout<<endl;
//				cout<<"Sorry! No Bed Available"<<endl;
//			}
//			Sleep(8000);
//		}
//		else if(val==2)
//		{	
//			exit = true;
//			cout<<"Good Luck"<<endl;
//			Sleep(3000);
//		}
//		else
//		{
//			cout<<"Invalid Input"<<endl;
//			Sleep(3000);
//		}
//	}
//		mysql_close(conn);
//		return 0;
//}

