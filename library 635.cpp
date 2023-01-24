/* GROUP NAME :CODE HUNTERS
   Members : Amina Habib
           Taqadus Fatima
           Linta Ashfaq
   programing fundamentals
  submitted to: Ma'am Ayesha Hakim 
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;



void addBook(){

	string id,title,ISSN,publisher,cost="";

    int bookNameLimit=30;

    int ISSNLimit=13;

    int publisherNameLimit=20;

    int costLimit=10;

    int idLimit=5;

    id="1";

    if(id.length()>idLimit){

    	id = id.substr(0, idLimit);

	}

	while(id.length()<idLimit){

		id +=" ";

	}

    cout<<"Enter Book Title = ";

    cin >> title;

    if(title.length()>bookNameLimit){

    	title = title.substr(0, bookNameLimit);

	}

	while(title.length()<bookNameLimit){

		title +=" ";

	}

    cout<<"Enter ISSN = ";

    cin >> ISSN;

    if(ISSN.length()>ISSNLimit){

    	ISSN = ISSN.substr(0, ISSNLimit);

	}

	while(ISSN.length()<ISSNLimit){

		ISSN +=" ";

	}

    cout<<"Enter Book Publisher Name = ";

    cin >> publisher;

    if(publisher.length()>publisherNameLimit){

    	publisher = publisher.substr(0, publisherNameLimit);

	}

	while(publisher.length()<publisherNameLimit){

		publisher +=" ";

	}

    cout<<"Enter Book Cost = ";

    cin >> cost;

    if(cost.length()>costLimit){

    	cost = cost.substr(0, costLimit);

	}

	while(cost.length()<costLimit){

		cost +=" ";

	}

    ofstream foutput; 

    ifstream finput;

    finput.open ("allbooks.txt");

    foutput.open ("allbooks.txt",ios::app); 

    if(finput.is_open()){

    	foutput<< " "<<id<<"  |  "<<" "<<title<<"  |  "<<" "<<ISSN<<"  |  "<<" "<<publisher<<"  |  "<<" "<<cost<<"\n";

	}

	finput.close();

 	foutput.close();

 	

 	ofstream fout; 

    ifstream fin;

    fin.open ("onlybooksname.txt");

    fout.open ("onlybooksname.txt",ios::app); 

    if(fin.is_open()){

    	fout<<title<<"\n";

	}

	fout.close();

 	fin.close();

}



void showAvailableBooks(){

	string myText;

	ifstream MyReadFile("allbooks.txt");

	if(MyReadFile.is_open()){

		while (getline (MyReadFile, myText)) {

 		 cout << myText<<endl;

		}

	}

	MyReadFile.close();

}



void reserveBook(){

	string name,bookToReserve;

	int choice=9;

	cout<<"Enter Your Name = ";

	cin>>name;

	string myText;

	int bookNameLimit=30;

	ifstream MyReadFile("allstudents.txt");

	if(MyReadFile.is_open()){

		while (getline (MyReadFile, myText)) {

			if(myText == name){

				cout<<"Please Return Your Reserved Book First"<<endl;

				return;

			}

		}

	}

	MyReadFile.close();

	while(choice !=0){

		cout<<"Enter book Name To Reserve = ";

		cin>>bookToReserve;

		if(bookToReserve.length()>bookNameLimit){

    		bookToReserve = bookToReserve.substr(0, bookNameLimit);

		}

		while(bookToReserve.length()<bookNameLimit){

			bookToReserve +=" ";

		}

		bool bookFound=false;

		string bookName;

		ifstream bfile("onlybooksname.txt");

		if(bfile.is_open()){

			while (getline (bfile, bookName)) {

				

				if(bookName == bookToReserve){

				    cout<<" user  "<<bookToReserve.length()<<endl;

				cout<<" loop "<<bookName.length()<<endl;

					bookFound=true;

					break;

				}

			}

		}

		bfile.close();

		if(bookFound){

		    ofstream foutput; 

			ifstream finput;

			finput.open ("allstudents.txt");

			foutput.open ("allstudents.txt",ios::app); 

			if(finput.is_open()){

				foutput<<name<<"\n";

			}

			finput.close();

			foutput.close();

			return;	

		}

		else{

			cout<<endl<<"Book Is not available "<<endl;

			cout<<"Press 1 to reserve other book "<<endl<<"Press 0 for main menu"<<endl<<"Enter your choice = ";

			cin>>choice;

		}	

	}

	

	

	

	

	

}



void returnBook(){
	string name,bookToReturn;
	int choice=9;
	cout<<"Enter Your Name = ";
	cin>>name;
	string myText;
	int bookNameLimit=30;
	ifstream MyReadFile("allstudents.txt");
	if(MyReadFile.is_open()){
	while (getline (MyReadFile, myText)) {
	if(myText == name){
	cout<<"Enter book Name To Return = ";
	 cin>>
	bookToReturn;
	if(bookToReturn.length()>bookNameLimit){
	bookToReturn = bookToReturn.substr(0, bookNameLimit);
	}
	while(bookToReturn.length()<bookNameLimit){
	bookToReturn +=" ";
	}
            ofstream fout; 
            ifstream fin;
            fin.open ("allstudents.txt");
            fout.open ("allstudents.txt",ios::app); 
            if(fin.is_open()){
                fout<<name<<" has returned "<<bookToReturn<<"\n";
            }
            fin.close();
            fout.close();
            cout<<"Book Returned Successfully"<<endl;
            choice = 0;
            return;
        }
    }
}
MyReadFile.close();
if(choice != 0)
{
    cout<<"No Record Found!"<<endl;
}
	

}



int main(){

	int choice=9;

	while(choice !=0){

		cout<<endl<<"Press 1 to add book"<<endl<<"Press 2 to check avaiable books"<<endl;

		cout<<"Press 3 to reserve a book "<<endl<<"Press 4 to return a book"<<endl<<"Enter 0 to Exit";

		cout<<endl<<"Enter your choice ? = ";

		cin >> choice ;

		if(choice == 1){

			addBook();		

		}

		else if(choice == 2){

			showAvailableBooks();

		}

		else if(choice == 3){

			reserveBook();

		}

		else if(choice == 4){

			returnBook();

		}

		else if(choice == 0) {

			cout<<endl<<"EXIT";

		}	

	}

	

    

}