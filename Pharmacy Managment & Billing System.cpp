#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<conio.h>
using namespace std;
struct med
{
	string name;
	string formula;
	float tabletprice;
	int date[3];
	int dawn;
};
void account();
void add(med s[400], int ab);
void pharmacist_menu();
void admin_menu();
void stocks(med s[400],int ab);
void medicine_list();
void medicine_lista();
void alpha(med s[400],int ab);
void salts(med s[400],int ab);
void returnbills();
void storedata(med s1[400]);
void expiry(med a[400],int ab);
int calculatediscount(float discount_per,float orignal_price );
void secbill(string name1, float price1,int date1[3],int quan1, med s[400],int ab);
void thirdbill(string name1, float price1,int date1[3],int quan1,string name2, float price2,int date2[3],int quan2, med s[400],int ab);
void fourthbill(string name1, float price1,int date1[3],int quan1,string name2, float price2,int date2[3],int quan2,string name3, float price3,int date3[3],int quan3, med s[400],int ab);

int main()
{
	system("color F5");
	cout<<"WELCOME TO PHARMACY MANAGEMENT AND BILLING SYSTEM"<<endl;
	cout<<endl;
	cout<<"PLEASE LOGIN YOUR ACCOUNT"<<endl;
	account();
	getch();
	return 0;
}


void account(){
	//a:
	int	flag3=0;
	string b;
		for(int l=0;l<2;l++){
	cout<<endl<<"-> USERNAME : "<<endl;
      cin>>b;
	//getline(cin,b);
	cout<<endl<<"-> PASSWORD : "<<endl;

	 string pass[10];//to store password.
    int i = 0;
    string a;//a Temp char
	for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>="a"&&a<="z")||(a>="A"&&a<="z")||(a>="0"&&a<="9"))
        //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            i++;
            cout<<"*";
        }
        if(a=="\b"&&i>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=="\r")//if enter is pressed
        {
            //pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }


		if(b=="nehal"&&pass[0]=="n"&& pass[1]=="1" && pass[2]=="2"&& pass[3]=="3" && pass[4]=="0")
		{

				cout<<endl;
				flag3++;
				pharmacist_menu();

		}
		if(b=="zahra"&&pass[0]=="z"&& pass[1]=="1" && pass[2]=="2"&& pass[3]=="3")
		{
				cout<<endl;
				flag3++;
				admin_menu();
		}
		if(flag3!=1)
		{
			int a=0;
			if(a==1)
				exit(0);
			cout<<endl<<"                Incorrect!!..            "<<endl;
			cout<<endl<<" Please Enter Username & Password Again : "<<endl;
		}
}
///goto a;
}

//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
void pharmacist_menu()
{
//START:
	system("cls");
	int a;
	cout<<"________________________________________________________________________________________________________________"<<endl;
	cout<<endl<<"************************************ WELCOME TO PHARMACIST ACCOUNT ****************************************"<<endl;
	cout<<"________________________________________________________________________________________________________________"<<endl;
	cout<<" Select an Option :"<<endl;
	cout<<"____________________"<<endl;
	cout<<" -> 1. Medicine list. "<<endl;
	cout<<"____________________"<<endl;
	cout<<" -> 2. Search a medicine. "<<endl;
	cout<<"____________________"<<endl;
	cout<<" -> 3. Return Bills"<<endl;
	cout<<"____________________"<<endl;
	cout<<" -> 4. Logout"<<endl;
	cout<<"____________________"<<endl;
	cin>>a;
	switch(a)
	{
	case 1:

		medicine_list();
	 system("pause");
     system("cls");
     pharmacist_menu();

	 case 2:
	medicine_lista();

	 system("pause");
     system("cls");
     pharmacist_menu();


	//break;
//	goto START;
	case 3:
     returnbills();
     system("pause");
     system("cls");
     pharmacist_menu();
     //break;
//	 goto START;
	case 4:
		system("cls");
	account();
}
}


void returnbills()
{
	cout<<"____________________________________________________________________________________________________________"<<endl;
	cout<<endl<<"                                        ' PREVIOUS BILLS ARE '                                               "<<endl;
	cout<<"____________________________________________________________________________________________________________"<<endl;
	int	o=0,i=1;
	string name;
	int count=0;
	string formula;
	int price;
	fstream returnbill("Bills.txt",ios::in);
	returnbill>>name;
	while(!returnbill.eof())
		{	if(o==0||o%4==0)
			{cout<<endl;
			cout<<"___________________________"<<endl;
				cout<<" BILL NO# "<<i<<endl;
					i++;
			}

			cout<<name<<"  ";

			returnbill>>name;
				o++;
				count++;
		}

	returnbill.close();
	getch();
}


void medicine_list()
{
//void medicine_list()
//	{
int ab;

fstream file("f.txt",ios::in);
file>>ab;
//cout<<ab;
file.close();

string se;
int i,e;
	med s2[400];
      fstream name("medicine_names.txt", ios::in);


	//  	while(!ali.eof())
for(i=0;i<ab;i++)
{
	name>>se;
	s2[i].name=se;

}
name.close();

fstream formula("salts.txt", ios::in);

	  for(i=0;i<ab;i++)
{
	formula>>se;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].formula=se;

}
formula.close();


fstream price("prices.txt",ios::in);
	  for(i=0;i<ab;i++)
{
	price>>e;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].tabletprice=e;

}
price.close();

fstream stock("stock.txt",ios::in);

	  for(i=0;i<ab;i++)
{
	stock>>e;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].dawn=e;

}
stock.close();

fstream date("date.txt",ios::in);
int w;
for(i=0;i<ab;i++)
{
	date>>w;
	s2[i].date[0]=w;
		date>>w;
	s2[i].date[1]=w;
	date>>w;
	s2[i].date[2]=w;

	}
	date.close();

 	system("cls");
 	//a:


 		cout<<" "<<"> NAME <                          "<<" "<<"> PRICE <                          "<<" "<<"> STOCK < "<<endl;
 	 for(i=0;i<ab;i++)
 	{

 		cout<<" "<<i+1<<"."<<"  "<<s2[i].name<<"                                "<<s2[i].tabletprice<<"                                   "<<s2[i].dawn<<endl;
 		cout<<endl<<"___________________________________________________________________________________________________________________________________"<<endl;
 	//	cout<<s2[i].name<<"    "<<s2[i].tabletprice<<"  "<<arr[i]<<"   "<<s2[i].date[0]<<"-"<<s2[i].date[1]<<"-"<<s2[i].date[2]<<endl;
	 }



	 //search
	int flag=0,c,st,n1=0;
	 	int medprice;
 	int meddate[3];
 	string medname;
 	string a;
 //	int i;

//	cout<<"search is working"<<endl;
//	cout<<" Processing.. "<<endl;
	cout<<"Do you want to search medicines  : "<<endl;
     cout<<"-> Press 1 for alphabatically  and ->Press 2 for by SALTS  -> Press 3 for by name:"<<endl;
   cin>>n1;

     	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> n1;
    }
	//n1=1;
	int ij=0;
     if(n1==1){
		 ij++;
     alpha(s2,ab);
 }
   if(n1==2)// 2=q;
   {
//	   cout<<"condition is workkifv"<<endl;
   	salts(s2,ab);
	ij=3;
   }



while(flag==1||flag==0)
{

	cout<<"-> Enter the name of the medicine you want to search : "<<endl;
	if(ij==0||ij==1)
	cin.ignore();
	//ij++;
	//cin.get(a);
	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s2[i].name)
 		{
 			flag=3;
 		break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
 	cout<<" __SORRY__"<<endl;
 ij=4;
	cout<<" Invlaid Entery ... "<<endl;
}
}
if(flag==3){

	for(i=0;i<ab;i++)
 	{
 		if(a==s2[i].name)
 		{
 			//cout<<" Processing ..."<<endl;
 			medname=s2[i].name;
 			medprice=s2[i].tabletprice;
 			meddate[0]=s2[i].date[0];
 			meddate[1]=s2[i].date[1];
 			meddate[2]=s2[i].date[2];
 			st=s2[i].dawn;

 		c=i;
		 }


 }



}




if(st==0)
{
	cout<<endl<<" Oops"<<endl;
	cout<<endl<<" Stock is empty. "<<endl;
	system("pause");
	//goto a;
}else{



//billling

int op,op1 ,op2,quan,quan1;
 	float aa, per,per1,per2,per3,per4,per5,q; //aa is discounted amount
 	//cout<<" Processing.. "<<endl;
// 	q:
	cout<<endl<<"-> Please enter the number of tablets you want to purchase : "<<endl;
	cin>>quan;
	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> quan;
    }
	//if(quan>1||quan<<100)
	//{

	s2[c].dawn=s2[c].dawn-quan;
	if(s2[c].dawn>=0)
	{
	medprice=medprice*quan;
	cout<<"-> Please set the discout percentage : "<<endl;
	 cin>>per;
	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> per;
    }
	 	aa=calculatediscount(per,medprice);
 cout<<" NOW, If you want to purchase another medicine than ->'PRESS-1' : " <<endl;
 cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<endl<<" If you want to make a bill, ->'PRESS-2' : "<<endl;
 cin>>op;
 if(op==1)
 {	secbill(medname,aa,meddate,quan,s2,ab);
 //	secbill(medname,aa,quan,s2);
}else{


 			cout<<endl<<"> NAME <"<<"       "<<medname<<endl;
 			cout<<endl<<"> PRICE <"<<"        "<<aa<<endl;
 			cout<<endl<<"> QUANTITY <"<<"      "<<quan<<endl;
 			cout<<endl<<"> EXPIRY DATE <"<<"   "<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
 			cout<<endl<<"        Thank you.  "<<endl;
 			cout<<endl<<"    Have a nice day.   "<<endl;

			//storing bills
			fstream returnbill("catbills.txt",ios::app);
			returnbill<<medname<<endl;
			returnbill<<aa<<endl;
			returnbill<<quan<<endl;
			returnbill<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
			returnbill.close();
			storedata(s2);


 }

 }else
 {
 	cout<<" Sorry!! "<<endl;
 	cout<<" Not enogh medicines"<<endl;
 	//goto a;
 }

}

}



void medicine_lista()
{
//void medicine_list()
//	{
int ab;

fstream file("f.txt",ios::in);
file>>ab;
//cout<<ab;
file.close();

string se;
int i,e;
	med s2[400];
      fstream name("name.txt", ios::in);


	//  	while(!ali.eof())
for(i=0;i<ab;i++)
{
	name>>se;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].name=se;

}
name.close();

fstream formula("salts.txt", ios::in);

	  for(i=0;i<ab;i++)
{
	formula>>se;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].formula=se;

}
formula.close();


fstream price("prices.txt",ios::in);
	  for(i=0;i<ab;i++)
{
	price>>e;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].tabletprice=e;

}
price.close();

fstream stock("stock.txt",ios::in);

	  for(i=0;i<ab;i++)
{
	stock>>e;
	//cout<<i<<s<<endl;
	//i++;
	s2[i].dawn=e;

}
stock.close();

fstream date("date.txt",ios::in);
int w;
for(i=0;i<ab;i++)
{
	date>>w;
	s2[i].date[0]=w;
		date>>w;
	s2[i].date[1]=w;
	date>>w;
	s2[i].date[2]=w;

	}
	date.close();
/*
	//stocks

		int arr[262];
	int ss;
	fstream stock("catstock.txt",ios::in);
	//stock>>s;
	//while(!stock.eof())
	for(int z=0;z<263;z++)
	{
//	cout<<s<<endl;
	stock>>ss;
	//cout<<s<<endl;
	arr[z]=ss;
//z++;

}
stock.close();
/*
for(i=0;i<5;i++)
{
	cout<<arr[i]<<" ";
}

}
*/


	//showing med list
 	//int i;
 	system("cls");
 	//a:

/*
 		cout<<" "<<"> NAME <                          "<<" "<<"> PRICE <                          "<<" "<<"> STOCK < "<<endl;
 	 for(i=0;i<ab;i++)
 	{

 		cout<<" "<<i+1<<"."<<"  "<<s2[i].name<<"                                "<<s2[i].tabletprice<<"                                   "<<s2[i].dawn<<endl;
 		cout<<endl<<"___________________________________________________________________________________________________________________________________"<<endl;
 		cout<<s[i].name<<"    "<<s[i].tabletprice<<"  "<<arr[i]<<"   "<<s[i].date[0]<<"-"<<s[i].date[1]<<"-"<<s[i].date[2]<<endl;
	 }

	*/

	 //search
	int flag=0,c,st,n1=0,q=2;
 	int medprice;
 	int meddate[3];
 	string medname;
 	string a;
 //	int i;

//	cout<<"search is working"<<endl;
//	cout<<" Processing.. "<<endl;
	cout<<"Do you want to search medicines  : "<<endl;
     cout<<"-> Press 1 for alphabatically  and ->Press 2 for by SALTS  -> Press 3 for by name:"<<endl;
   cin>>n1;

     	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> n1;
    }
	//n1=1;
	int ij=0;
     if(n1==1){
		 ij++;
     alpha(s2,ab);
 }
   if(n1==q)
   {
//	   cout<<"condition is workkifv"<<endl;
   	salts(s2,ab);
	ij=3;
   }



while(flag==1||flag==0)
{

	cout<<"-> Enter the name of the medicine you want to search : "<<endl;
	if(ij==0||ij==1)
	cin.ignore();
	//ij++;
	//cin.get(a);
	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s2[i].name)
 		{
 			flag=3;
 		break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
 	cout<<" __SORRY__"<<endl;
 ij=4;
	cout<<" Invlaid Entery ... "<<endl;
}
}
if(flag==3){

	for(i=0;i<ab;i++)
 	{
 		if(a==s2[i].name)
 		{
 			//cout<<" Processing ..."<<endl;
 			medname=s2[i].name;
 			medprice=s2[i].tabletprice;
 			meddate[0]=s2[i].date[0];
 			meddate[1]=s2[i].date[1];
 			meddate[2]=s2[i].date[2];
 			st=s2[i].dawn;

 		c=i;
		 }


 }



}




if(st==0)
{
	cout<<endl<<" Oops"<<endl;
	cout<<endl<<" Stock is empty. "<<endl;
	system("pause");
	//goto a;
}else{



//billling

int op,op1 ,op2,quan,quan1;
 	float aa, per,per1,per2,per3,per4,per5,q; //aa is discounted amount
 	//cout<<" Processing.. "<<endl;
// 	q:
	cout<<endl<<"-> Please enter the number of tablets you want to purchase : "<<endl;
	cin>>quan;
	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> quan;
    }
	//if(quan>1||quan<<100)
	//{

	s2[c].dawn=s2[c].dawn-quan;
	if(s2[c].dawn>=0)
	{
	medprice=medprice*quan;
	cout<<"-> Please set the discout percentage : "<<endl;
	 cin>>per;
	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> per;
    }
	 	aa=calculatediscount(per,medprice);
 cout<<" NOW, If you want to purchase another medicine than ->'PRESS-1' : " <<endl;
 cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<endl<<" If you want to make a bill, ->'PRESS-2' : "<<endl;
 cin>>op;
 if(op==1)
 {	secbill(medname,aa,meddate,quan,s2,ab);
// 	secbill(medname,aa,quan,s2);
 }else{


 			cout<<endl<<"> NAME <"<<"       "<<medname<<endl;
 			cout<<endl<<"> PRICE <"<<"        "<<aa<<endl;
 			cout<<endl<<"> QUANTITY <"<<"      "<<quan<<endl;
 			cout<<endl<<"> EXPIRY DATE <"<<"   "<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
 			cout<<endl<<"        Thank you.  "<<endl;
 			cout<<endl<<"    Have a nice day.   "<<endl;

			//storing bills
			fstream returnbill("catbills.txt",ios::app);
			returnbill<<medname<<endl;
			returnbill<<aa<<endl;
			returnbill<<quan<<endl;
			returnbill<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
			returnbill.close();
			storedata(s2);


			/*
			fstream stock("catstock.txt",ios::out);
			for(i=0;i<262;i++)
			{
				stock<<arr[i]<<endl;
			}
			stock.close();
			system("pause");
			//goto a;
 	*/
 }

 }else
 {
 	cout<<" Sorry!! "<<endl;
 	cout<<" Not enogh medicines"<<endl;
 	//goto a;
 }

}

}





 void secbill(string name1, float price1,int date1[3],int quan1, med s[400],int ab)
 {
 	 	int i,st,c,n1;




	int flag=0;
 	int medprice;
 	int meddate[3];
 	string medname;
 	string a;
 	int ij=0;

	//cout<<" Processing.. "<<endl;
	cout<<"Do you want to search medicines  : "<<endl;
     cout<<"-> Press 1 for alphabatically  and ->Press 2 for by SALTS  -> Press 3 for by name:"<<endl;
     cin>>n1;
     if(n1==1){
		 ij++;
     alpha(s,ab);
 }
   if(n1==2)
   {
//	   cout<<"condition is workkifv"<<endl;
   	salts(s,ab);
	ij=3;
   }



while(flag==1||flag==0)
{

	cout<<"-> Enter the name of the medicine you want to search : "<<endl;
	if(ij==0||ij==1)
	cin.ignore();
	//ij++;
	//cin.get(a);
	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			flag=3;
 		break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
 	cout<<" __SORRY__"<<endl;
 ij=4;
	cout<<" Invlaid Entery ... "<<endl;
}

}

if(flag==3){

	for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			cout<<"  DONE  "<<endl;
 			//cout<<s[i].name;
 			medname=s[i].name;
 			medprice=s[i].tabletprice;
 			meddate[0]=s[i].date[0];
 			meddate[1]=s[i].date[1];
 			meddate[2]=s[i].date[2];
 			st=s[i].dawn; //check krne k lye k st matlab stock zero to ni,,,

 		c=i;//agge chal k kam aega
		 }
 }
}
if(st==0)
{
	cout<<endl<<" Oops "<<endl;
	cout<<endl<<" Stock is empty : "<<endl;
}else{ //agr stock zero ni to




 	int op,op1 ,op2,quan;
 	float per,per1,per2,per3,per4,per5,q,aa;
 //	cout<<" Processing.. "<<endl;
 //	cout<<" want to sell whole pack press 1"<<endl;

	cout<<endl<<"-> Please Enter the number of medicines : "<<endl;
	cin>>quan;
	 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> quan;
    }
	s[c].dawn=s[c].dawn-quan;
	if(s[c].dawn>=0)
	{
	medprice=medprice*quan;
	cout<<endl<<"-> Please set the discout percentage : "<<endl;
	 cin>>per;
	  while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> per;
    }
	 aa=calculatediscount(per,medprice);
	 cout<<" NOW, If you want to purchase another medicine than ->'PRESS-1' : " <<endl;
 cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<endl<<" If you want to make a bill, ->'PRESS-2' : "<<endl;
 cin>>op;
 if(op==1)
 {
 	 	thirdbill(name1,price1,date1,quan1,medname,aa,meddate,quan,s,ab);

 //	thirdbill(name1,price1,date1,quan1,medname,aa,meddate,quan,s,arr);
 }else{

 	 			cout<<"1ST MED"<<endl;
 			cout<<endl<<"> NAME <"<<"       "<<name1<<endl;
 			cout<<endl<<"> PRICE <"<<"        "<<price1<<endl;
 			cout<<endl<<"> QUANTITY <"<<"      "<<quan1<<endl;
 			cout<<endl<<"> EXPIRY DATE <"<<"   "<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;
 			cout<<endl<<"> 2nd MEDICINE <"<<endl;
 			cout<<"____________________________________"<<endl;
 			cout<<endl<<"> NAME <"<<"       "<<medname<<endl;
 			cout<<endl<<"> PRICE <"<<"        "<<aa<<endl;
 			cout<<endl<<"> QUANTITY <"<<"      "<<quan<<endl;

			 cout<<endl<<"> EXPIRY DATE<"<<"   "<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;

			 cout<<endl<<"     Thank you.  "<<endl;
			 cout<<endl<<"    Have a nice day.  "<<endl;

			 //storing bills
			fstream returnbill("catbills.txt",ios::app);
			returnbill<<name1<<endl;
			returnbill<<price1<<endl;
			returnbill<<quan1<<endl;
			returnbill<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;

			returnbill<<medname<<endl;
			returnbill<<aa<<endl;
			returnbill<<quan<<endl;
			returnbill<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
			returnbill.close();
//			void storedata(med s1[400])
storedata(s);
			/*

			 fstream stock("catstock.txt",ios::out);
			for(i=0;i<262;i++)
			{
				stock<<arr[i]<<endl;
			}
			stock.close();
 	*/



}
}else
{
	cout<<"not enough medicines"<<endl;
}
}
}




 ////////////////////////////////////////////////////////////////////////////////////////////
  void thirdbill(string name1, float price1,int date1[3],int quan1,string name2, float price2,int date2[3],int quan2, med s[400],int ab)
 {
 	 	int i,st,c,n1;

	int flag=0;
 	int medprice;
 	int meddate[3];
 	string medname;
 	string a;
 	int ij=0;

//	cout<<" Processing.. "<<endl;
	cout<<"Do you want to search medicines  : "<<endl;
     cout<<"-> Press 1 for alphabatically  and ->Press 2 for by SALTS  -> Press 3 for by name:"<<endl;
     cin>>n1;
//n1=1;

     if(n1==1){
     alpha(s,ab);
 }
   if(n1==2)
   {
//	   cout<<"condition is workkifv"<<endl;
   	salts(s,ab);
   }


while(flag==1||flag==0)
{
	cout<<endl<<"-> Please Enter the name of medicine you want to search : "<<endl;
	//if(ij==0)
	//cin.ignore();
	//ij++;


	cin.ignore();
	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			flag=3;
 			break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
 	cout<<endl<<" Sorry!!! "<<endl;
	cout<<endl<<" Invlaid entery .. "<<endl;
}
}
if(flag==3){

	for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			cout<<endl<<"              DONE        "<<endl;
 			//cout<<s[i].name;
 			medname=s[i].name;
 			medprice=s[i].tabletprice;
 			meddate[0]=s[i].date[0];
 			meddate[1]=s[i].date[1];
 			meddate[2]=s[i].date[2];
 			st=s[i].dawn; //check krne k lye k st matlab stock zero to ni,,,

 		c=i;//agge chal k kam aega
		 }
 }
}
if(st==0)
{
	cout<<endl<<" Oops "<<endl;
	cout<<endl<<" Stock is empty.. "<<endl;
}else{ //agr stock zero ni to




 	int op,op1 ,op2,quan;
 	float per,per1,per2,per3,per4,per5,q,dp;
 	cout<<endl<<" Processing .."<<endl;
 //	cout<<" want to sell whole pack press 1"<<endl;

	cout<<"-> Please Enter the number of medicines you want to Purchase : "<<endl;
	cin>>quan;
		  while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> quan;
    }

	s[i].dawn=s[i].dawn-quan;
	if(s[i].dawn>=0)
	{
	medprice=medprice*quan;
	cout<<"-> Please set the discout percentage : "<<endl;
	 cin>>per;
	 	  while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> per;
    }
	 dp=calculatediscount(per,medprice);
	 cout<<" NOW, If you want to purchase another medicine than ->'PRESS-1' : " <<endl;
 cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<endl<<" If you want to make a bill, ->'PRESS-2' : "<<endl;

 cin>>op;
 if(op==1)
 {
 	fourthbill(name1,price1,date1,quan1,name2,price2,date2,quan2,medname,dp,meddate,quan,s,ab);
 }else{
 			/////////////////////////////////////
 	 			cout<<" *1ST MED* "<<endl;
 			cout<<endl<<" > NAME < "<<"       "<<name1<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<price1<<endl;// issue 0...solved
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan1<<endl;
 			cout<<endl<<" > EXPIRY DATE < "<<"   "<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;

 			////////////////////////////////////////////////
 			cout<<"________________________________________"<<endl;
 				cout<<" *2ND MED*"<<endl;
 			cout<<endl<<" > NAME < "<<"       "<<name2<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<price2<<endl;// issue 50
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan2<<endl; //issue 0....solved
 			cout<<endl<<" > EXPIRY DATE < "<<"   "<<date2[0]<<"-"<<date2[1]<<"-"<<date2[2]<<endl;

			 /////////////////////////////////////////
			 cout<<" *3RD MED* "<<endl;
 			cout<<endl<<"________________________________________"<<endl;
 			cout<<endl<<" > NAME < "<<"       "<<medname<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<dp<<endl;
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan<<endl;

			 cout<<endl<<" > EXPIRY DATE < "<<"   "<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
 			//////////////////////////////////////////////
			 cout<<endl<<"    Thank you.    "<<endl;
			 cout<<endl<<"  Have a nice day. "<<endl;



			 //storing bills
			fstream returnbill("catbills.txt",ios::app);
			returnbill<<name1<<endl;
			returnbill<<price1<<endl;
			returnbill<<quan1<<endl;
			returnbill<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;

			returnbill<<name2<<endl;
			returnbill<<price2<<endl;
			returnbill<<quan2<<endl;
			returnbill<<date2[0]<<"-"<<date2[1]<<"-"<<date2[2]<<endl;



			returnbill<<medname<<endl;
			returnbill<<dp<<endl;
			returnbill<<quan<<endl;
			returnbill<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
			returnbill.close();


storedata(s);


/*

			 fstream stock("catstock.txt",ios::out);
			for(i=0;i<262;i++)
			{
				stock<<arr[i]<<endl;
			}
			stock.close();*/
}
}else
{
	cout<<endl<<"   Oops  "<<endl;
	cout<<endl<<" Stock is empty : "<<endl;
}
}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////

void fourthbill(string name1, float price1,int date1[3],int quan1,string name2, float price2,int date2[3],int quan2,string name3, float price3,int date3[3],int quan3, med s[400],int ab)
 {
 	 	int i,st,c,n1;

	int flag=0;
 	int medprice;
 	int meddate[3];
 	string medname;
 	string a;
 	int ij=0;

	cout<<" Processing.. "<<endl;
	cout<<"Do you want to search medicines  : "<<endl;
     cout<<"-> Press 1 for alphabatically  and ->Press 2 for by SALTS  -> Press 3 for by name:"<<endl;
     cin>>n1;
    //n1=1;

     if(n1==1){
     alpha(s,ab);
 }
   if(n1==2)
   {
//	   cout<<"condition is workkifv"<<endl;
   	salts(s,ab);
   }



while(flag==1||flag==0)
{
	cout<<endl<<"-> Please Enter the name of medicine you want to search : "<<endl;
//	cin.ignore();
	//if(ij==0)
	cin.ignore();
	//ij++;

	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			flag=3;
 			break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
    cout<<endl<<"  Sorry  "<<endl;
	cout<<endl<<" Invlaid entery. "<<endl;
}
}
if(flag==3){

	for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			cout<<endl<<"         DONE       "<<endl;
 			//cout<<s[i].name;
 			medname=s[i].name;
 			medprice=s[i].tabletprice;
 			meddate[0]=s[i].date[0];
 			meddate[1]=s[i].date[1];
 			meddate[2]=s[i].date[2];
 			st=s[i].dawn; //check krne k lye k st matlab stock zero to ni,,,

 		c=i;//agge chal k kam aega
		 }
 }
}
if(st==0)
{
	cout<<endl<<"   Oops  "<<endl;
	cout<<" Stock is empty..  "<<endl;
}else{


	int op,op1 ,op2,quan;
 	float per,per1,per2,per3,per4,per5,q,dp;
 	cout<<endl<<" Processing.."<<endl;
 //	cout<<" want to sell whole pack press 1"<<endl;

	cout<<endl<<"-> Please Enter the number of medicines you want to purchase : "<<endl;
	cin>>quan;
		  while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> quan;
    }
	s[i].dawn=s[i].dawn-quan;
	if(s[i].dawn>=0)
	{
	medprice=medprice*quan;
	cout<<endl<<"->Please set the discout percentage : "<<endl;
	 cin>>per;
	 	  while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> per;
    }
	 dp=calculatediscount(per,medprice);
	 cout<<" NOW, If you want to purchase another medicine than ->'PRESS-1' : " <<endl;
 cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ OR ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<endl<<" If you want to make a bill, ->'PRESS-2' : "<<endl;
 cin>>op;
 if(op==1)
 {
 	//fifththbill(name1,price1,date1,medname,medprice,meddate,s);
 }else{
 			/////////////////////////////////////
 	 			cout<<"       * 1ST MEDICINE *      "<<endl;
 			cout<<endl<<" > NAME < "<<"       "<<name1<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<price1<<endl;// issue 0...solved
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan1<<endl;
 			cout<<endl<<" > EXPIRY DATE < "<<"   "<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;
 			cout<<endl<<"______________________________________________"<<endl;
 			////////////////////////////////////////////////

 				cout<<"       * 2ND MEDICINE *      "<<endl;
 			cout<<" > NAME < "<<"       "<<name2<<endl;
 			cout<<" > PRICE < "<<"        "<<price2<<endl;// issue 50
 			cout<<" > QUANTITY  < "<<"      "<<quan2<<endl; //issue 0....solved
 			cout<<" > EXPIRY DATE < "<<"   "<<date2[0]<<"-"<<date2[1]<<"-"<<date2[2]<<endl;
 			cout<<endl<<"______________________________________________"<<endl;
			 /////////////////////////////////////////

					cout<<"    * 3ND MEDICINE *      "<<endl;
 			cout<<endl<<" > NAME < "<<"       "<<name3<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<price3<<endl;// issue 50
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan3<<endl; //issue 0....solved
 			cout<<endl<<" > EXPIRY DATE < "<<"   "<<date3[0]<<"-"<<date3[1]<<"-"<<date3[2]<<endl;

		    cout<<endl<<"______________________________________________"<<endl;

			 //////////////////////////////////////////////////////
			 cout<<"  *4TH MEDICINE* "<<endl;

 			cout<<endl<<" > NAME < "<<"       "<<medname<<endl;
 			cout<<endl<<" > PRICE < "<<"        "<<dp<<endl;
 			cout<<endl<<" > QUANTITY < "<<"      "<<quan<<endl;

			 cout<<" > EXPIRY DATE < "<<"   "<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
 			//////////////////////////////////////////////
			 cout<<endl<<"	  Thank you		"<<endl;
             cout<<endl<<"    Have a nice day.      "<<endl;
            cout<<endl<<"______________________________________________"<<endl;
			 		 //storing bills
			fstream returnbill("catbills.txt",ios::app);
			returnbill<<name1<<endl;
			returnbill<<price1<<endl;
			returnbill<<quan1<<endl;
			returnbill<<date1[0]<<"-"<<date1[1]<<"-"<<date1[2]<<endl;

			returnbill<<name2<<endl;
			returnbill<<price2<<endl;
			returnbill<<quan2<<endl;
			returnbill<<date2[0]<<"-"<<date2[1]<<"-"<<date2[2]<<endl;


			returnbill<<name3<<endl;
			returnbill<<price3<<endl;
			returnbill<<quan3<<endl;
			returnbill<<date3[0]<<"-"<<date3[1]<<"-"<<date3[2]<<endl;



			returnbill<<medname<<endl;
			returnbill<<dp<<endl;
			returnbill<<quan<<endl;
			returnbill<<meddate[0]<<"-"<<meddate[1]<<"-"<<meddate[2]<<endl;
			returnbill.close();



//void storedata(med s1[400])
storedata(s);


/*


			 fstream stock("catstock.txt",ios::out);
			for(i=0;i<262;i++)
			{
				stock<<arr[i]<<endl;
			}
			stock.close();
*/

}
}else
{
	cout<<endl<<"   Oops  "<<endl;
	cout<<endl<<"  Stock is empry.."<<endl;
}
}
}


/////////////////////////////////////////////////////////
void alpha(med s[400], int ab)
{
	char a;
	cout<<"plz enter an alphabet"<<endl;
//	getline(cin,a);
	a=getch();
	for(int i=0;i<ab;i++)
	{
		if(s[i].name[0]==a)
		{
			if(i==0)
				cout<<"MEDICINES ARE"<<endl;
			cout<<s[i].name<<endl;
		}
	}



}
void salts(med s[400],int ab)
{
	int flag1=0,ij=0,i;
	string a;
while(flag1==1||flag1==0)
{
	cout<<endl<<"-> Please Enter the name of salt you want to search : "<<endl;
//	cin.ignore();
	if(ij==0)
	cin.ignore();
	ij++;

	getline(cin,a);

		for(i=0;i<ab;i++)
 	{
 		if(a==s[i].formula)
 		{
 			flag1=3;
 			break;
		 }else{
		 	flag1=1;
		 }


 }
 if(flag1==1){
    cout<<endl<<"  Sorry  "<<endl;
	cout<<endl<<" Invlaid entery. "<<endl;
}
}
if(flag1==3){
cout<<"                                          "<<endl;
	cout<<"SHOWING MEDICINES HAVING THIS salt"<<endl;
	cout<<"                                         "<<endl;
	//cout<<"                                         "<<endl;
	cout<<"                                         "<<endl;
	cout<<"NAME"<<"                "<<"PRICE"<<"            "<<endl;
	for(i=0;i<ab;i++)
 	{
 		if(a==s[i].formula)
 		{


 			cout<<s[i].name<<"                "<<s[i].tabletprice<<"            "<<endl;
}
}
}
}

////////////////////////////////////////////////////////


void storedata(med s1[400])
{
		int ab=263;

fstream file("f.txt",ios::in);
file>>ab;
cout<<ab;
file.close();

string se;
int i,e;

      fstream name("name.txt", ios::out);
      name.seekp(ios_base::beg);


	//  	while(!ali.eof())
for(i=0;i<ab;i++)
{

	name<<s1[i].name<<endl;
	//cout<<i<<s<<endl;
	//i++;
//	s2[i].name=se;

}
name.close();

fstream formula("salts.txt", ios::out);
  formula.seekp(ios_base::beg);
	  for(i=0;i<ab;i++)
{

formula<<s1[i].formula<<endl;

}
formula.close();
int v;

fstream price("prices.txt",ios::out);
	  for(i=0;i<ab;i++)
{

	v=s1[i].tabletprice;
	price<<v<<endl;
}
price.close();
int q;
fstream stock("stock.txt",ios::out);
 // stock.seekp(ios_base::beg);
	  for(i=0;i<ab;i++)
{
	q=s1[i].dawn;
	stock<<q<<endl;


	//stock>>e;
	//cout<<i<<s<<endl;
	//i++;
//	s2[i].dawn=e;

}
stock.close();

fstream date("date.txt",ios::out);

int w;
for(i=0;i<ab;i++)
{
	//date>>w;
	w=s1[i].date[0];
		date<<w<<endl;
	w=s1[i].date[1];
	date<<w<<endl;
	w=s1[i].date[2];
	date<<w<<endl;
	}
	date.close();

}
int calculatediscount(float discount_per,float orignal_price )
{
	float q;
		q=(discount_per/100)*orignal_price;  // 10/100=0.1 , 0.1*10=1
		orignal_price=orignal_price-q;

	return orignal_price;


 }
void admin_menu()
{
	int ab;

fstream file("f.txt",ios::in);
file>>ab;
cout<<ab;
file.close();

string se;
int i,e;
	med s[400];
      fstream name("name.txt", ios::in);


	//  	while(!ali.eof())
for(i=0;i<ab;i++)
{
	name>>se;
	//cout<<i<<s<<endl;
	//i++;
	s[i].name=se;

}
name.close();

fstream formula("salts.txt", ios::in);

	  for(i=0;i<ab;i++)
{
	formula>>se;
	//cout<<i<<s<<endl;
	//i++;
	s[i].formula=se;

}
formula.close();


fstream price("prices.txt",ios::in);
	  for(i=0;i<ab;i++)
{
	price>>e;
	//cout<<i<<s<<endl;
	//i++;
	s[i].tabletprice=e;

}
price.close();

fstream stock("catstock.txt",ios::in);

	  for(i=0;i<ab;i++)
{
	stock>>e;
	//cout<<i<<s<<endl;
	//i++;
	s[i].dawn=e;

}
stock.close();

fstream date("date.txt",ios::in);
int w;
for(i=0;i<ab;i++)
{
	date>>w;
	s[i].date[0]=w;
		date>>w;
	s[i].date[1]=w;
	date>>w;
	s[i].date[2]=w;

	}
	date.close();
	system("cls");
	int m=0;
	cout<<"________________________________________________________________________________________________________________"<<endl;
	cout<<endl<<"************************************ 'WELCOME TO ADMIN ACCOUNT' ****************************************"<<endl;
	cout<<"________________________________________________________________________________________________________________"<<endl;
	cout<<endl<<" Select an option : "<<endl;
	cout<<endl<<"____________________"<<endl;
	cout<<endl<<"-> 1. Expiries "<<endl;
	cout<<endl<<"____________________"<<endl;
	cout<<endl<<"-> 2. Stocks"<<endl;
	cout<<endl<<"____________________"<<endl;
	cout<<endl<<"-> 3. Report"<<endl;
		cout<<endl<<"____________________"<<endl;
	cout<<endl<<"-> 4. Logout"<<endl;
	cout<<endl<<"____________________"<<endl;
//	cout<<endl<<"____________________"<<endl;
	cout<<endl<<"-> 5. ADD A MEDICINE"<<endl;
	cout<<endl<<"____________________"<<endl;

//	cout<<"5 for report"<<endl;
//	cout<<"6 to add a madicine"<<endl;
	cin>>m;
	switch(m)
	{
		case 1:
		expiry(s,ab);
		//system("cls");
		system("pause");
		system("cls");
		admin_menu();
		case 2:
		stocks(s,ab);

			 system("pause");
system("cls");
	 admin_menu();
	//	break;
//	/	goto jump;
		case 3:
	 returnbills();

	 system("pause");
	 system("cls");
	 admin_menu();
//		goto jump;
		case 4:
			account();
	//		logout();
		//	break;
		case 5:
		add(s,ab);
		system("pause");
		admin_menu();
	}
}



 void expiry(med a[400],int ab)
 {


	cout<<endl<<"-> Expiry dates of medicines are : "<<endl;


	for(int i=0;i<ab;i++)
	{          cout<<endl<<"                                NAME"<<"                                                   DATE  "<<endl;
	 		cout<<" "<<i+1<<")"<<"                         "<<a[i].name<<"                                            "<<a[i].date[0]<<"-"<<a[i].date[1]<<"-"<<a[i].date[2]<<endl;
	 		cout<<endl<<"_______________________________________________________________________________________________________________________"<<endl;

	}
 }



 void stocks(med s[400],int ab)
 {
 	int c,ij;
 	int flag=0;
 	int i,n;
 	string a;
 	cout<<"OK WE ARE GOING TO UPDATE STOCKS"<<endl;
 //	cout<<"plz enter the name of medicine whose stock you want to update"<<endl;
 //	cin>>a;

while(flag==1||flag==0)
{
	cout<<endl<<"-> Please Enter the Name of medicine you want to search : "<<endl;
//	if(ij==0)
	cin.ignore();
//	ij++;


	//cin.ignore();
	getline(cin,a);

		for(i=0;i<ab;i++)
 	{

 		if(a==s[i].name)
 		{
 			flag=3;
 			break;
		 }else{
		 	flag=1;
		 }


 }
 if(flag==1){
 	cout<<" Sorry!! "<<endl;
	cout<<endl<<" Invlaid Entery.. "<<endl;
}
}
if(flag==3){

 cout<<"we have found the medicine"<<endl;
 	for(i=0;i<ab;i++)
 	{
 		if(a==s[i].name)
 		{
 			c=i;
 			cout<<endl<<"         DONE       "<<endl;
		 }
 }
 	cout<<"plz enter the new stock"<<endl;
 	cin>>n;
 	s[c].dawn=n;
storedata(s);
 }
}

void add(med s[400], int ab)
{string n,salt;
int p,ddd;
int d[3];
	cout<<"OK we are going to add a medicine"<<endl;
	cout<<"plz enter the name of medicine"<<endl;
	cin.ignore();
	getline(cin,n);
	cout<<"plz enter the name of salt"<<endl;
	getline(cin,salt);
	cout<<"plz enter the price"<<endl;
	cin>>p;
	cout<<"plz enter the  stock"<<endl;
	cin>>ddd;
	cout<<"plz enter the expiry date"<<endl;
	cout<<"year"<<endl;
	cin>>d[2];
	cout<<"month"<<endl;
	cin>>d[1];
	cout<<"day"<<endl;
	cin>>d[0];
	s[ab].name=n;
	s[ab].formula=salt;
	s[ab].tabletprice=p;
	s[ab].dawn=ddd;
	s[ab].date[0]=d[0];
	s[ab].date[1]=d[1];
	s[ab].date[2]=d[2];
	//	int ab;

fstream file("f.txt",ios::out);
ab++;
file<<ab;
file.close();
storedata(s);

}
