#include<iostream>
#include<conio.h>
using namespace std;
class expenseNode;
class priceNode;
class dateNode;
class idNode{
	public:
	int id;
	expenseNode* idnext;
	idNode(int value){
		id=value;
		idnext=NULL;
	}
};
class expenseNode{
	public:
	string expenseName;
	priceNode* expensenext;
		expenseNode(string value){
		expenseName=value;
		expensenext=NULL;
	}
};
class priceNode{
	public:
	int price;
	dateNode* pricenext;
	priceNode(int value){
		price=value;
		pricenext=NULL;
	}
};
class dateNode{
	public:
	string date;
	dateNode(string value){
		date=value;
	}
};
void insertData(idNode* &head,int value,string name,int value2,string value3){
		if(head==NULL){
		idNode* idptr=new idNode(value);
		head=idptr;
		expenseNode* expenseptr=new expenseNode(name);
	    idptr->idnext=expenseptr;
		priceNode* priceptr=new priceNode(value2);
	    expenseptr->expensenext=priceptr;
		dateNode* dateptr=new dateNode(value3);
		priceptr->pricenext=dateptr;
	}
}
void upgradeData(idNode* &head,int value,string name,int value2,string value3,int a){
		if(head==NULL){
			cout<<endl<<a-1<<"th Expense List was deleted"<<endl;
		}
		else{
		head->id = value;
        head->idnext->expenseName = name;
        head->idnext->expensenext->price = value2;
        head->idnext->expensenext->pricenext->date = value3;
 
	}
}
void display(idNode* head,int b){
	if(head==NULL){
			cout<<endl<<b+1<<"th Expense List not Created or has been deleted Deleted"<<endl;
			return;
		}
		cout<<endl<<b+1<<"th Expense List"<<endl;
		cout<<"ID:"<<head->id<<" -> "<<"Name:"<<head->idnext->expenseName<<" -> "<<"Price:"<<head->idnext->expensenext->price<<" -> "<<"Date:"<<head->idnext->expensenext->pricenext->date<<" ";
		return;
	}
void deleteList(idNode* &head,int a){
	
	idNode* temp1=head;
	expenseNode* temp2=head->idnext;
	priceNode* temp3=head->idnext->expensenext;
	dateNode* temp4=head->idnext->expensenext->pricenext;
	delete temp1;
	delete temp2;
	delete temp3;	
	delete temp4;
	cout<<endl<<a<<"th Expense List Deleted Successfully"<<endl;
}	
	
int generateReport(idNode* &head1,idNode* &head2,int u,int y){
	priceNode* temp1=head1->idnext->expensenext;
	priceNode* temp2=head2->idnext->expensenext;
	int a;
	if(temp1->price>temp2->price){
	    a=u;
	}
	else{
		a=y;
	}
	return a;

}
int main(){
	cout<<"-----------------------"<<endl;
	cout<<"Expense Tracker App\n";
	cout<<"-----------------------"<<endl;
	int i=-1;
	idNode* masterArray[100]={NULL};
		int id,price;
		string name,date;
		int expense;
		char c;
do{
	cout<<"1.Add Expense\n2.View Expense\n3.Generate Report\n4.Exit";
	cout<<"\n-----------------------\n";
	int choice;
	cin>>choice;
	switch(choice){ 
		case 1:{ 
			cout<<"-----------------------"<<endl;
		cout<<"Add Expense"<<endl;
			cout<<"-----------------------"<<endl;
		cout<<"1.New Expense\n2.Edit Expense\n3.Delete Expense\n";
		cin>>expense;
		switch(expense){ 
		case 1: {	
			cout<<"-----------------------"<<endl;	
		cout<<"New Expense\n";	
			cout<<"-----------------------"<<endl;
		++i;
		cout<<"Item ID: ";
			cin>>id;
			cout<<"Item Name: ";
			cin>>name;
			cout<<"Item Price: ";
			cin>>price;
			cout<<"Date (dd-mm-yyyy): ";
			cin>>date;
			insertData(masterArray[i],id,name,price,date);	
	break;	} 
	case 2:{
			cout<<"-----------------------"<<endl;
		cout<<"Edit Expense"<<endl;
			cout<<"-----------------------"<<endl;
		int edit;
		cout<<"which Expense list you want to edit\n";
		cin>>edit;
		if(edit-1<=i){
		cout<<"What do you want to Edit\n1.Item ID\n2.Item Name\n3.Item Price\n4.Date\n";
			int node;
			cin>>node;
			switch(node){
				case 1:{
					cout<<"Item new ID: ";
					cin>>id;
					upgradeData(masterArray[edit-1] ,id,name,price,date,edit);
					break;	
				}
				case 2:{
					cout<<"Item new Name: ";
					cin>>name;
					upgradeData(masterArray[edit-1] ,id,name,price,date,edit);
					break;	
				}
				case 3:{
					cout<<"Item new price: ";
					cin>>price;
					upgradeData(masterArray[edit-1] ,id,name,price,date,edit);
					break;	
				}
					case 4:{
					cout<<"new Date (dd-mm-yyyy): ";
					cin>>date;
					upgradeData(masterArray[edit-1] ,id,name,price,date,edit);
					break;	
				}
		}
	}
	
		else{
			cout<<edit<<"th Expense list not created\n";
		}
    break;	}
    case 3:{ 
    	int d;	
		cout<<"-----------------------"<<endl;
		cout<<"Delete Expense List"<<endl;
			cout<<"-----------------------"<<endl;
			cout<<" Delete Expense List no.\n";
			int del;
			cin>>del;
			if(del-1<=i){
				deleteList(masterArray[del-1],del);
				masterArray[del-1]=NULL;
			}	
    	else{
    		cout<<del<<"th Expense list not created\n";
		}
    	
		break;	}
	break;	}
	
	break;}

	case 2:{
			cout<<"-----------------------"<<endl;
		cout<<" View Expense\n";
			cout<<"-----------------------"<<endl;
		int a=0;
		while(a<=i){
			display(masterArray[a],a);
			++a;
		}
		break;	}
		
	case 3:{
			cout<<"-----------------------"<<endl;
		cout<<"Generate Report\n";
			cout<<"-----------------------"<<endl;
		
		if(i==0){
			cout<<"1 list Created\n";
			display(masterArray[i],i);
		}
		else{

    int res=-1;
    for(int x=0;x<=i;++x){
        if(masterArray[x]==NULL) 
		continue;
        if(res==-1){
            res=x;
            continue;
        }
        res=generateReport(masterArray[res],masterArray[x],res,x);
    }
    if(res!=-1){
        display(masterArray[res],res);
    } else {
        cout<<"No valid expense lists available for report generation.\n";
    }
}
		break;	}
		
	case 4:{
		c=1;
		break;	}   

 }  
	cout<<"-----------------------"<<endl;
		cout<<"Press 'e' for Exit";
	cout<<"\n-----------------------"<<endl;
		c=getch();
}while(c!='e');
}
