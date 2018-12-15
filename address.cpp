z#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void welcome_screen() ;
void welcome_screen()
{
   clrscr() ;
   gotoxy(31,5) ;
   cout<<" W E L C O M E";
   gotoxy(29,7) ;
   cout<<"TELEPHONE MANAGEMENT SOFTWARE";
   gotoxy(23,12) ;
   cout<<"MADE BY : Naman Vashistha";
   gotoxy(25,16) ;
   cout<<" PRESS ANY KEY TO CONTINUE";
   getch() ;
   return ;
}

class directory
{
   public :
   int record ;
   long pn1 ;
   char pn2[10] ;
   int age ;
   char address1[50] ;
   char address2[50] ;
   char occupation[20] ;
   char name[20] ;
   char emailadd[25] ;
   char internetadd[25] ;
   void modification() ;
   void addition() ;
   void deleate() ;
   void menu() ;
   void search() ;
   void view1() ;
   void init() ;
   void display() ;
   void view() ;
   char check(char *) ;
   int test() ;
   } obj ;


void directory :: addition() //ADDING  INFORMATION
{
   ofstream fout ;
   fout.open("naman",ios :: out | ios :: app |ios::binary ) ;
   init() ;
   fout.write(( char * ) & obj, sizeof ( obj )) ;
   fout.close() ;
}


int directory :: test () //FIND NO. OF RECORDS
{
   ifstream fin ;
   fin.open("naman");
   fin.seekg(0,ios :: end) ;
   int n ;
   n=fin.tellg() / sizeof( obj ) ;
   cout<<" \n NUMBER OF RECORDS = " <<n ;
   return n ;
}

void directory :: search()//SEARCHING FOR A PARTICULAR NUMBER
{
   ifstream fin ;
   fin.open("naman") ;
   if(fin.fail())
   {
       cout<<"\n FILE NOT FOUND " ;
       getch() ;
       return ;
   }
   clrscr() ;
   gotoxy(30,1) ;
   cout<<"[SEARCHING]";
   cout<<"\n ENTER PHONE NUMBER TO BE SEARCHED : " ;
   long pn ;
   cin>>pn;
   int n ;
   n =test() ;
   for(int i = 0;i < n;i ++)
   {
      fin.read((char *) & obj, sizeof(obj)) ;
      if(pn==pn1)
      {
	 view1() ;
	 return ;
      }
   }
   if(fin.eof())
   {
       cout<<"\n RECORD NOT FOUND" ;
   }
}


void directory :: init() // ENTERING THE DETAILS
{
   clrscr() ;
   char ch ;
   gotoxy(30,1) ;
   cout<<"[ADDITION]" ;
   cout<<"\n ENTER HOUSE PHONE NUMBER : " ;
   cin>> pn1 ;
   cout<<"\n ENTER OFFICE PHONE NUMBER : " ;
   cin>>pn2 ;
   // ch=cin.get();
   cin.get(ch) ;
   cout<<"\n ENTER NAME : " ;
   cin.getline(name,20) ;
   cout<<"\n ENTER THE OCCUPATION : " ;
   cin.getline (occupation,20) ;
   cout<<"\n ENTER HOUSE ADDRESS : " ;
   cin.getline(address1, 50) ;
   cout<<"\n ENTER OFFICE ADDRESS : " ;
   cin.getline(address2,50) ;
   cout<<" \n ENTER EMAIL ADDRESS : " ;
   cin.getline (emailadd,25) ;
   cout<<"\n ENTER INTERNET ADDRESS : " ;
   cin.getline(internetadd, 25) ;
}


void directory :: view1 () //TO DISPLAY ALL THE RECORDS
{
   cout<<" \n " ;
   cout<<"\nPHONE NUMBER1 : " << obj. pn1;
   cout<<"\nPHONE NUMBER2 : " << obj. pn2;
   cout<<"\nNAME : "<<obj. name;
   cout<<"\nHOUSE ADDRESS : " <<obj. address1;
   cout<<"\nOCCUPATION : " << obj. occupation;
   cout<<"\nOFFICE ADDRESS : " <<obj. address2;
   cout<<"\nEMAIL ADDRESS : " <<obj. emailadd;
   cout<<"\nINTERNET ADDRESS : " <<obj. internetadd;
   getch() ;
}


void directory :: modification() //TO MODIFY ANY DATA
{
   clrscr() ;
   gotoxy(30,1) ;
   cout<<"[ MODIFICATION ]" ;
   long pn;
   int n,i ;
   ifstream fin ;
   ofstream fout ;
   fin.open("naman");
   if(fin.fail())
   {
      cout<<"\n FILE NOT FOUND !" ;
      fout.close() ;
      exit(-1) ;
   }
   fout.open("new") ;
   n=test() ;
   if(n==0)
   {
      cout<<"\n FILE IS EMPTY ! " ;
      getch() ;
      return ;
   }
   while(fin.good())
   {
      fin.read((char *) & obj, sizeof ( obj )) ;
      fout.write((char*) & obj, sizeof ( obj )) ;
   }
   fin.close() ;
   fout.close() ;
   fout.open ("naman",ios :: trunc) ;
   fin.open("new") ;
   if(fin.fail())
   {
      cout<<"\n FILE NOT FOUND !" ;
      exit(-1) ;
   }
   char ch ;
   cout<<"\n ENTER PHONE NUMBER :" ;
   cin>>pn;

   for(i=0;i<n;i++)
   {
      fin.read((char *) & obj, sizeof (obj)) ;
      char d;
      if(pn==pn1)
      {
	 view1() ;
	 d = check( "HOUSE PHONE NUMBER") ;
	 if((d =='y') || (d =='Y'))
	 {
	      cout<<" \n ENTER NEW PHONE NUMBER :" ;
	      cin>>pn1 ;
	 }
	 if(check("OFFICE PHONE NUMBER ") =='Y')
	 {
	      cout<<"\n ENTER NEW PHONE NUMBER :" ;
	      cin>>pn2 ;
	 }
      if(check("NAME")=='y')
      {
	 cout<<"\n ENTER NEW NAME :" ;
	 cin.getline(name,20);
      }
	 if(check("HOME ADDRESS" ) =='y' )
	 {
	   cout<<"\n ENTER NEW ADDRESS :" ;
	   cin.getline(address1, 50 ) ;
	 }
      if(check("OFFICE ADDRESS")=='y' )
      {
	 cout<<"\nENTER NEW ADDRESS :" ;
	 cin.getline(address2, 50 ) ;
      }
      if(check("EMAIL ADDRESS:" ) =='y' )
      {
	 cout<<"\nENTER NEW MAIL ADDRESS :" ;
	 cin.getline(emailadd,25 ) ;
      }
      if(check("INTERNET ADDRESS" ) =='y' )
      {
	 cout<<"\n ENTER NEW INTERNET ADDRESS :" ;
	 cin.getline(internetadd,25) ;
      }
   }
   fout.write((char *) & obj, sizeof(obj)) ;
   }
   fout.close();
   fin.close();
   }

   char directory :: check(char * s)
   {
      cout<<"\n MODIFY \t " <<s <<" \t " << "Y/N" ;
      char ch ;
      ch=getch() ;
      if((ch =='y') ||(ch =='Y'))
      return 'y' ;
      else
      return 'n' ;
   }


void directory :: deleate()// TO DELETE DATA
{
   clrscr() ;
   window(1,1,80,25) ;
   gotoxy(30,1) ;
   cout<<"[DELETION]"  ;
   long pn ;
   int n,i ;
   ifstream fin ;
   ofstream fout ;
   fin. open("naman") ;
   if(fin.fail())
   {
      cout<<"\n FILE NOT FOUND ! " ;
      getch() ;
      return ;
   }
   fout.open("new") ;
   n=test() ;
   if( n==0 )
   {
      cout<<" \n FILE IS EMPTY ! " ;
      getch() ;
      return ;
   }
   for(i=0;i<n;i ++ )
   {
      fin.read((char*) & obj, sizeof(obj)) ;
      fout.write((char *) & obj, sizeof (obj)) ;
   }
   fin.close() ;
   fout.close() ;
   fout.open( "naman" ,ios :: trunc) ;
   fin.open ( "new" ) ;
   if( fin.fail())
   {
      cout<<" \n FILE NOT FOUND ! " ;
      getch() ;
      return ;
   }
   cout<<"\n ENTER PHONE NUMBER :" ;
   cin>>pn;


   for(i=0;i<n;i++)
   {
      fin.read(( char*) & obj, sizeof(obj)) ;
      if(pn != pn1)
	 fout.write((char *) & obj, sizeof (obj)) ;
   }
   fout.close() ;
   fin.close() ;
}


void directory :: view()
{
   ifstream fin ;
   int n,j ;
   fin.open("naman") ;
   if(fin.fail() || fin.bad ())
   {
      cout<<"\n FILE NOT FOUND ! " ;
      getch() ;
      return ;
   }
   clrscr();
   int i=0;
   n=test() ;
   for(j=0;j< n;j++)
   {
      cout<<"\n RECORD " <<i + 1 << " \n " ;
      fin.read((char *) & obj, sizeof (obj)) ;
      cout<<" \n PHONE NUMBER1 :" << obj. pn1;
      cout<<" \n PHONE NUMBER2 :" << obj. pn2;
      cout<<" \n NAME :" <<obj. name;
      cout<<" \n HOUSE ADDRESS :" <<obj. address1;
      cout<<" \n OCCUPATION :" << obj. occupation;
      cout<<" \n OFFICE ADDRESS :" <<obj. address2;
      cout<<" \n INTERNET ADDRESS :" << obj. internetadd;
      cout<<" \n EMAIL ADDRESS : " <<obj. emailadd;
      i=i+1 ;
   }
   fin.close() ;
   getch() ;
}



void directory :: menu()
{
   char ch ;
   clrscr() ;
   gotoxy(30,8) ;
   cout<<"A:ADDITION "  ;
   gotoxy(30,9) ;
   cout<<"D:DELETION  "  ;
   gotoxy(30,10) ;
   cout<<"M:MODIFICATION  "  ;
   gotoxy(30,11) ;
   cout<<"V:VIEW" ;
   gotoxy(30,12) ;
   cout<<"S:SEARCH " ;
   gotoxy(30,13) ;
   cout<<"E:EXIT";
   ch =getch();
   switch(ch)
   {
      case 'a' :
      case 'A' :
	 addition();
	 break;
      case 'd' :
      case 'D' :
	 deleate();
	 break;
      case 'm' :
      case 'M' :
	 modification();
	 break;
     case 'v' :
     case 'V' :
	 view();
	 break;
     case 's' :
     case 'S' :
	 search();
	 break;
      case 'e' :
      case 'E' :
	 system("cls");
	 exit(0);
      default:
      {
      gotoxy(25,14);
      cout<<"PLEASE ENTER THE RIGHT CHOICE";
      getch();
      }
   }
}

int main()
{
   textcolor(12);
   textbackground(25);
   welcome_screen();
   for(;;)
   obj.menu();



}
