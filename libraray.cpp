#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
int main(){
	char xx;
	do{
			cout<<"WELCOME to Engineering library"<<endl;
			cout<<"Press 1 to see books present\n";
			cout<<"Press 2 to see barrow any book\n";
			cout<<"Press 3 to return book\nPress 4 to add a book\nPress 5 to look into data relating barrowed books\n";
			int x;
			cin>>x;
			if(x==1){
				ifstream file("Electric Engineering and Author.txt");
				ifstream Number_books("Electric Engineering_Number of books_total.txt");
				ifstream Books("Electric Engineering_Number of books_booked.txt");
				string line,books,booked;
				int i=1;
				cout<<"Book's Number\tBook's and Author name\t\tTotal copies\tBarrowed copies\t\tAvailable copies"<<endl;
				while(getline(file,line) && getline(Number_books,books) && getline (Books,booked)){
					cout<<i<<"\t\t"<<line<<"\t\t\t"<<books<<"\t\t"<<booked;
					stringstream aa(books),bb(booked);
					int a,b;
					aa>>a;
					bb>>b;
					cout<<"\t\t\t"<<a-b<<endl;
					i++;
				}
				file.close();
				Number_books.close();
			}
			if(x==2){
				int counting=0;
				ifstream readfile("Electric Engineering and Author_data.txt");
				string filereading;
				while(getline(readfile,filereading)){
					counting++;
				}
				readfile.close();
				if(counting<=100){
					int uu;
				cout<<"Press 1 if you are just subscriber\n";
				cout<<"Press 2 if you are golden subscriber\n";
				cin>>uu;
				if(uu==1){
					cout<<"You are not a golden subscriber and your barrow time is 3 weeks"<<endl;
					ifstream file("Electric Engineering and Author.txt");
		    		int i=1,xx;
		    		string line;
		    		while(getline(file,line)){
			    		cout<<"Press "<<i<<" to barrow "<<line<<endl;
			    		i++;
			    	}
			    	file.close();
		    		cin>>xx;
		    		if(xx<=i && xx>0){
		    			int mm,array[50]={},count=0,count1=0,total[50]={};
		    			xx--;
			        	cout<<"Enter amount = ";
			        	cin>>mm;
			        	ifstream wfile("Electric Engineering_Number of books_booked.txt");
			        	string lines;
			        	i=0;
			        	while(getline(wfile,lines)){
			        		stringstream aa(lines);
			    	    	aa>>array[i];
			    		    count++;
			    	    	i++;
				    	}
					    wfile.close();
					    ifstream wwfile("Electric Engineering_Number of books_total.txt");
			    	    string lin;
			    	    i=0;
			    	    while(getline(wwfile,lin)){
			    		    stringstream aa(lin);
			    		    aa>>total[i];
			    		    count1++;
			    		    i++;
					    }
					    wwfile.close();
					    if(mm<=(total[xx]-array[xx])){
						    array[xx]=array[xx]+mm;
	    					string name,email,roll[50]={},roll_number,rol;
	    					cin.ignore();
		     				cout<<"Entered amount is available"<<endl;
			    			cout<<"Enter your name = ";
				    		getline(cin,name);
					    	cout<<"Enter your Email = ";
	    					getline(cin,email);
	    					cout<<"Enter your Roll number = ";
	    					getline(cin,roll_number);
	    					ifstream rrrfile("Electric Engineering and Author_roll_number.txt");
	    				    int ii=0,count1=0;
	    			       	while(getline(rrrfile,rol)){
	    		  	    		roll[ii]=rol;
	    		  	    		count1++;
	        	     			ii++;
			        		}
				     		rrrfile.close();
				     		ifstream rrfile("Electric Engineering and Author.txt");
	    			       	string na;
	    			    	ii=0;
	    		        	string nam[50]={};
	   		    	     	while(getline(rrfile,na)){
	  			    	    	nam[ii]=na;
	    	    		        ii++;
					       	}
					  		rrfile.close();
				     		ofstream rfile("Electric Engineering and Author_roll_number.txt");
	    				    for(int i=0;i<=count1;i++){
	    				    	if(roll[i].compare(nam[xx])==0){
	    				    		rfile<<roll[i]<<"\n"<<roll_number<<"\n";
								}
								else{
									rfile<<roll[i]<<"\n";
								}
							}
				     		rfile.close();
	    					cout<<"Enter day = ";
	    					int day,month;
	    					cin>>day;
	    					if(day<30){
	    						cout<<"Enter Month = ";
	    						cin>>month;
	    						if(month<=12){
	    							cout<<"Year is automatically ADDED which is 2020"<<endl;
	    							ofstream writefile("Electric Engineering_Number of books_booked.txt");
			    		        	for(int i=0;i<count;i++){
				    	         		writefile<<array[i]<<"\n";
					            	}
	     				        	writefile.close();
	     				        	ifstream rfile("Electric Engineering and Author_data.txt");
	    			        		string ln;
	    			        		string data[200]={};
	    				        	int ii=0;
	    				        	int count=0;
	    			    	     	while(getline(rfile,ln)){
	    			    	    		data[ii]=ln;
	    			    	    		count++;
	    		    	     			ii++;
					        		}
					        		rfile.close();
					        		ofstream file("Electric Engineering and Author_data.txt");
					        		int p=0;
					        		while(p<=count){
					        			if(data[p].compare(nam[xx])==0){
	     				                	file<<data[p]<<"\n"<<name<<"\t"<<email<<"\t"<<"*"<<mm<<"*"<<"\t"<<day<<"/"<<month<<"/"<<"2020"<<"\t";
	     				                	int year=2020;
	     				                 	for(int i=1;i<=3;i++){
	     				            	    	day=day+7;
	     				             	     	if(day>=30){
	     				            	    		day=day-30;
	     				        	        		month++;
									         	}
								    	    	if(month>=12){
									        		month=1;
									        		year++;
									        	}
								        	}
								         	file<<"/"<<day<<"/"<<month<<"/"<<year<<" \n";
										}
										else{
											file<<data[p]<<"\n";
										}
					        			p++;
									}
	             		        	file.close();
	    						}
								else{
									cout<<"Months is geater than 12"<<endl;
							    	cout<<"Months same method again and enter day less than 12"<<endl;
								}	
							}
							else{
								cout<<"Days is geater than 30"<<endl;
								cout<<"Days same method again and enter day less than 30"<<endl;
							}
		     			}
			    		else{
				    		cout<<"Amount is invalid\n\tThis amount is not available"<<endl;
					    	int a=total[xx]-array[xx];
						    cout<<"Available Amount = "<<a<<endl;
					    } 
			    	}
				else{
					cout<<"Invalid entry "<<endl;
				}
			    	
		
				}
				else if(uu==2){
					cout<<"You are golden subscriber and your barrow time is 3 months"<<endl;
					ifstream file("Electric Engineering and Author.txt");
		    		int i=1,xx;
		    		string line;
		    		while(getline(file,line)){
			    		cout<<"Press "<<i<<" to buy "<<line<<endl;
			    		i++;
			    	}
			    	file.close();
		    		cin>>xx;
		    		if(xx<=i && xx>0){
		    			int mm,array[50]={},count=0,count1=0,total[50]={};
		    			xx--;
			        	cout<<"Enter amount = ";
			        	cin>>mm;
			        	ifstream wfile("Electric Engineering_Number of books_booked.txt");
			        	string lines;
			        	i=0;
			        	while(getline(wfile,lines)){
			        		stringstream aa(lines);
			    	    	aa>>array[i];
			    		    count++;
			    	    	i++;
				    	}
					    wfile.close();
					    ifstream wwfile("Electric Engineering_Number of books_total.txt");
			    	    string lin;
			    	    i=0;
			    	    while(getline(wwfile,lin)){
			    		    stringstream aa(lin);
			    		    aa>>total[i];
			    		    count1++;
			    		    i++;
					    }
					    wwfile.close();
					    if(mm<=(total[xx]-array[xx])){
						    array[xx]=array[xx]+mm;
	    					string name,email,roll[50]={},roll_number,rol;
	    					cin.ignore();
		     				cout<<"Entered amount is available"<<endl;
			    			cout<<"Enter your name = ";
				    		getline(cin,name);
					    	cout<<"Enter your Email = ";
	    					getline(cin,email);
	    					cout<<"Enter your Roll number = ";
	    					getline(cin,roll_number);
	    					ifstream rrrfile("Electric Engineering and Author_roll_number.txt");
	    				    int ii=0,count1=0;
	    			       	while(getline(rrrfile,rol)){
	    		  	    		roll[ii]=rol;
	    		  	    		count1++;
	        	     			ii++;
			        		}
				     		rrrfile.close();
				     		ifstream rrfile("Electric Engineering and Author.txt");
	    			       	string na;
	    			    	ii=0;
	    		        	string nam[50]={};
	   		    	     	while(getline(rrfile,na)){
	  			    	    	nam[ii]=na;
	    	    		        ii++;
					       	}
					  		rrfile.close();
				     		ofstream rfile("Electric Engineering and Author_roll_number.txt");
	    				    for(int i=0;i<=count1;i++){
	    				    	if(roll[i].compare(nam[xx])==0){
	    				    		rfile<<roll[i]<<"\n"<<roll_number<<"\n";
								}
								else{
									rfile<<roll[i]<<"\n";
								}
							}
				     		rfile.close();
	    					cout<<"Enter day = ";
	    					int day,month;
	    					cin>>day;
	    					if(day<30){
	    						cout<<"Enter Month = ";
	    						cin>>month;
	    						if(month<=12){
	    							cout<<"Year is automatically ADDED which is 2020"<<endl;
	    							ofstream writefile("Electric Engineering_Number of books_booked.txt");
			    		        	for(int i=0;i<count;i++){
				    	         		writefile<<array[i]<<"\n";
					            	}
	     				        	writefile.close();
	     				        	ifstream rfile("Electric Engineering and Author_data.txt");
	    			        		string ln;
	    			        		string data[200]={};
	    				        	int ii=0;
	    				        	int count=0;
	    			    	     	while(getline(rfile,ln)){
	    			    	    		data[ii]=ln;
	    			    	    		count++;
	    		    	     			ii++;
					        		}
					        		rfile.close();
					        		ofstream file("Electric Engineering and Author_data.txt");
					        		int p=0;
					        		while(p<=count){
					        			if(data[p].compare(nam[xx])==0){
	     				                	file<<data[p]<<"\n"<<name<<"\t"<<email<<"\t"<<"*"<<mm<<"*"<<"\t"<<day<<"/"<<month<<"/"<<"2020"<<"\t";
	     				                	int year=2020;
	     				                 	for(int i=1;i<=3;i++){
	     				            	    	day=day+30;
	     				             	     	if(day>=30){
	     				            	    		day=day-30;
	     				        	        		month++;
									         	}
								    	    	if(month>=12){
									        		month=1;
									        		year++;
									        	}
								        	}
								         	file<<"/"<<day<<"/"<<month<<"/"<<year<<" \n";
										}
										else{
											file<<data[p]<<"\n";
										}
					        			p++;
									}
	             		        	file.close();
	    						}
								else{
									cout<<"Months is geater than 12"<<endl;
							    	cout<<"Months same method again and enter day less than 12"<<endl;
								}	
							}
							else{
								cout<<"Days is geater than 30"<<endl;
								cout<<"Days same method again and enter day less than 30"<<endl;
							}
		     			}
			    		else{
				    		cout<<"Amount is invalid\n\tThis amount is not available"<<endl;
					    	int a=total[xx]-array[xx];
						    cout<<"Available Amount = "<<a<<endl;
					    } 
					}
				else{
					cout<<"Invalid entry "<<endl;
				}
			    	
		
				}
				else{
					cout<<"Invalid entry"<<endl;
				}
				}
				else{
					cout<<"Sorry books are barrowed by 100 students ,cannot barrow at this moment"<<endl;
				}
								
			}
			else if(x==3){
				string roll,rol,data,roll_number,dat[50]={};
				cin.ignore();
				cout<<"Enter your roll number = ";
				getline(cin,roll);
				ifstream rrfile("Electric Engineering and Author.txt");
				string t,kkk;
				int j=0,counttt=0;
				while(getline(rrfile,t)){
					dat[j]=t;
					j++;
					counttt++;
				}
				rrfile.close();
				ifstream file("Electric Engineering and Author_roll_number.txt");
				ifstream rfile("Electric Engineering and Author_data.txt");
				int found,count1=0;
				while(getline(file,rol) && getline(rfile,data)){
					found=0;
					for(int k=0;k<j;k++){
						if(dat[k].compare(rol)==0){
							kkk=dat[k];
							break;
						}
					}
					if(roll.compare(rol)==0){
						roll_number=data;
						found=1;
						break;
					}
					count1++;
				}
				file.close();
				rfile.close();
				string number;
				found=0;
				for(int i=0;i<roll_number.length();i++){
					if(roll_number[i]=='*'){
						for(int j=i+1;j<roll_number.length();j++){
							if(roll_number[j]!='*'){
								string xx(1,roll_number[j]);
						    	number.append(xx);
							}
							else if(roll_number[j]=='*'){
								found=1;
								break;
							}		
						}
						if(found==1){
							break;
						}
					}
				}
				
				stringstream aaa(number);
				int tt;
				aaa>>tt;
			    int intarray[50]={};
			    ifstream wrfile("Electric Engineering_Number of books_booked.txt");
			    string fg;
			    int ii=0;
			    while(getline(wrfile,fg)){
			    	stringstream nnn(fg);
			    	nnn>>intarray[ii];
			    	ii++;	
				}
				ifstream wwwrfile("Electric Engineering and Author.txt");
	            string ggg;
	        	j=0;
				while(getline(wwwrfile,ggg)){
		            if(ggg.compare(kkk)==0){
		                intarray[j]=intarray[j]-tt;
	        			break;
         			}
		            j++;
	    		}	                         		
				if(found==0){
					cout<<"Book is not barrowed by this ROLL NO"<<endl;
				}
				else{
					int gg=roll_number.length(),ii,count22=0;
					string v="";
					for(ii=0;ii<gg;ii++){
						if(roll_number[gg-ii]!='/' && roll_number[gg-ii]!=' '){
							string s(1,roll_number[gg-ii]);
							v.append(s);
							count22++;
						}
						else if(roll_number[gg-ii]=='/'){
							count22++;
							break;	
						}	
					}
					string ss="";
					for(int i=1;i<=v.length();i++){
						if(v[v.length()-i]!=' ' ){
							string s(1,v[v.length()-i]);
				    		ss.append(s);
						}	
					}
					stringstream aa(ss);
					int a;
					aa>>a;
					v="";
					for(ii=count22+1;ii<gg;ii++){
						if(roll_number[gg-ii]!='/' && roll_number[gg-ii]!=' '){
							string s(1,roll_number[gg-ii]);
							v.append(s);
							count22++;
						}
						else if(roll_number[gg-ii]=='/'){
							count22++;
							break;	
						}	
					}
					ss="";
					for(int i=1;i<=v.length();i++){
						if(v[v.length()-i]!=' ' ){
							string s(1,v[v.length()-i]);
				    		ss.append(s);
						}	
					}
					int b;
					stringstream bb(ss);
					bb>>b;
					
					v="";
					for(ii=count22+1;ii<gg;ii++){
						if(roll_number[gg-ii]!='/' && roll_number[gg-ii]!=' '){
							string s(1,roll_number[gg-ii]);
							v.append(s);
							count22++;
						}
						else if(roll_number[gg-ii]=='/'){
							count22++;
							break;	
						}	
					}
					ss="";
					for(int i=1;i<=v.length();i++){
						if(v[v.length()-i]!=' ' ){
							string s(1,v[v.length()-i]);
				    		ss.append(s);
						}	
					}
					int c;
					stringstream cc(ss);
					cc>>c;
					int day=0,year,month,days;
					cout<<"Enter returning year = ";
					int vv;
					cin>>vv;
					if(vv<2020){
						cout<<"Invalid year"<<endl;
						cout<<"Run program again to retun books "<<endl;
					}
					
					else if(vv>=a){
						string array[50]={},line;
						int k=0,count2=0;
						ifstream file("Electric Engineering and Author_roll_number.txt");
			        	while(getline(file,line)){
			        		array[k]=line;
			        		count2++;
			        		k++;
						}
			        	file.close();
						int fine=0;
						int u=vv-a;
						day=u*365;
						cout<<"Enter retuning month = ";
				    	int month;
				    	cin>>month;
				    	if(month<=12){
				    		if(month>=b){
				    			int uu=month-b;
				    			day=day+(uu*30);
				    			cout<<"Enter returning days = ";
				        		cin>>days;
				        		if(days<=30){
				        			if(days>=c){
				        				int uuu=days-c;
				        				day=day+uuu;
				        				wwwrfile.close();
							       		ofstream wwwfile("Electric Engineering_Number of books_booked.txt");
							    		for(int i=0;i<counttt;i++){
							    			wwwfile<<intarray[i]<<"\n";
							    		}	
							    		wwwfile.close();
				        				cout<<"You are late days = "<<day<<endl;
				                 		cout<<"Fine per day = 50 "<<endl;
				                 		fine=day*50;
				                 		cout<<"Total fine = "<<fine<<endl;
				                 		ofstream file("Electric Engineering and Author_roll_number.txt");
				                 		k=0;
				                 		while(k<=count2){
				                 			if(array[k].compare(array[count1])==0){
				                 				file<<array[k]<<"\t"<<days<<"/"<<month<<"/"<<vv<<"\t"<<fine<<'\n';
											}
											else{
												file<<array[k]<<"\n";
											}
											k++;
										}
															
									}
									else if(month>b && days<c){
										wwwrfile.close();
										ofstream wwwfile("Electric Engineering_Number of books_booked.txt");
										for(int i=0;i<counttt;i++){
											wwwfile<<intarray[i]<<"\n";
										}	
										wwwfile.close();
										day=day-days;
										cout<<"You are late days = "<<day<<endl;
				                 		cout<<"Fine per day = 50 "<<endl;
				                 		fine=day*50;
				                 		cout<<"Total fine = "<<fine<<endl;
										ofstream file("Electric Engineering and Author_roll_number.txt");
				                 		k=0;
				                 		while(k<=count2){
				                 			if(array[k].compare(array[count1])==0){
				                 				file<<array[k]<<"\t"<<days<<"/"<<month<<"/"<<vv<<"\t"<<fine<<'\n';
											}
											else{
												file<<array[k]<<"\n";
											}
											k++;
										}
										file.close();
									}
									else{
										wwwrfile.close();
										ofstream wwwfile("Electric Engineering_Number of books_booked.txt");
										for(int i=0;i<counttt;i++){
											wwwfile<<intarray[i]<<"\n";
										}	
										wwwfile.close();
										ofstream file("Electric Engineering and Author_roll_number.txt");
				                 		k=0;
				                 		while(k<=count2){
				                 			if(array[k].compare(array[count1])==0){
				                 				file<<array[k]<<"\t"<<days<<"/"<<month<<"/"<<vv<<"\t"<<0<<'\n';
											}
											else{
												file<<array[k]<<"\n";
											}
											k++;
										}
										file.close();
									}	
								}
								else{
									cout<<"Invalid Days Entered"<<endl;
									cout<<"Run program again"<<endl;
								}
							}
							else{
								wwwrfile.close();
								ofstream wwwfile("Electric Engineering_Number of books_booked.txt");
								for(int i=0;i<counttt;i++){
									wwwfile<<intarray[i]<<"\n";
								}	
								wwwfile.close();
								cout<<"Fine = "<<fine<<endl;
								ofstream file("Electric Engineering and Author_roll_number.txt");
				               	k=0;
				           		while(k<=count2){
				           			if(array[k].compare(array[count1])==0){
			              				file<<array[k]<<"\t"<<days<<"/"<<month<<"/"<<vv<<"\t"<<fine<<'\n';
									}
									else{
								    	file<<array[k]<<"\n";
									}
								k++;
								}
								file.close();
							}	
				    	}
				    	else{
							cout<<"Invalid Months entered"<<endl;
							cout<<"Run program again"<<endl;
						}
					}
		    	}
			}
			else if(x==4){
				string name,Author;
				cin.ignore();
				cout<<"Enter name of book = ";
				getline(cin,name);
				cout<<"Enter Author name = ";
				getline(cin,Author);
				cout<<"Enter number of copies = ";
				int m;
				cin>>m;
				int count=0;
				ifstream wrrfile("Electric Engineering and Author.txt");
				string line;
				while(getline(wrrfile,line)){
					count++;
				}
				if(count<=40){
					ofstream wwwfile("Electric Engineering and Author_roll_number.txt",ios::app);
				wwwfile<<name<<" by "<<Author<<"\n";
				wwwfile.close();
				ofstream wfile("Electric Engineering and Author_data.txt",ios::app);
				wfile<<name<<" by "<<Author<<"\n";
				wfile.close();
				ofstream wwfile("Electric Engineering and Author.txt",ios::app);
				wwfile<<name<<" by "<<Author<<"\n";
				wwfile.close();
				ofstream Number_books("Electric Engineering_Number of books_total.txt",ios::app);
				Number_books<<m<<"\n";
				Number_books.close();
				ofstream books("Electric Engineering_Number of books_booked.txt",ios::app);
				books<<0<<"\n";
				books.close();
				}
				else{
					cout<<"Sorry space is full and cannot add this book"<<endl;
				}	
			}
			else if(x==5){
				ifstream file("Electric Engineering and Author.txt");
		    		int i=1,ii=0,xx;
		    		string line,array[50]={};
		    		while(getline(file,line)){
			    		cout<<"Press "<<i<<" to Check data of "<<line<<endl;
			    		array[ii]=line;
			    		ii++; 
			    		i++;
			    	}
			    	file.close();
		    		cin>>xx;
		    		if(xx<=i && xx>0){
		    			xx--;
		    			int booked[50]={};
		    			ifstream wfile("Electric Engineering_Number of books_booked.txt");
			        	string lines;
			        	i=0;
			        	while(getline(wfile,lines)){
			        		stringstream aa(lines);
			    	    	aa>>booked[i];
			    	    	i++;
				    	}
					    wfile.close();
			        	cout<<"Book = "<<array[xx]<<endl;
			        	cout<<"Barrowed copies = "<<booked[xx]<<endl;
			        	cout<<"Name\tEmail\tNumber of copies Brrowed\tDay of barrow\tDay should return   Roll number   Returned at  Fine when returned"<<endl;
			        	ifstream rrfile("Electric Engineering and Author_data.txt");
			        	ifstream rfile("Electric Engineering and Author_roll_number.txt");
			        	string ln,roll;
						int ii=0;
			        	int found=0;
			        	while(getline(rrfile,ln) && getline(rfile,roll)){
			        		if(array[xx].compare(ln)==0){
			        			found=1;
							}
							else if(array[xx+1].compare(ln)==0){
								break;
							}
							else if(found==1){
								cout<<ln<<"\t"<<roll<<endl;
							}
						
						}
						rfile.close();
						rrfile.close();
			        	
					}
			}
		
		cout<<"Do you want to enter in library again(Y/N) ";
		cin>>xx;
	}
	while(xx=='Y' || xx=='y');	
}






