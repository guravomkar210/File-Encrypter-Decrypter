#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;

class Encryption{
	bool check=false;
	char ch;
	string filename="sample.txt";
	
	public:
		void encryptFile();
		void decryptFile();
		void showFile();
};

void Encryption::encryptFile(){
	fstream fin,fout;
	fin.open(filename,fstream::in);
	fout.open("sample2.txt",fstream::out);
	while(fin>>noskipws>>ch){
		ch=ch+100;
		fout<<ch;
	}
	fin.close();
	fout.close();
	cout<<"File is sucessfully encrypted."<<endl;
	check=true;
}

void Encryption::decryptFile(){
	fstream fin,fout;
	fin.open("sample2.txt",fstream::in);
	fout.open(filename,fstream::out);
	while(fin>>noskipws>>ch){
		ch=ch-100;
		fout<<ch;
	}
	fin.close();
	fout.close();
	remove("sample2.txt");
	cout<<"File is sucessfully decrypted."<<endl;
	check=false;
}

void Encryption::showFile(){
	fstream fout;
	
	if(check){
		cout<<endl;
		fout.open("sample2.txt",fstream::in);
		while(fout>>noskipws>>ch){
			cout<<ch;
		}
		fout.close();
	}
	else{
		cout<<endl;
		fout.open(filename,fstream::in);
		while(fout>>noskipws>>ch){
			cout<<ch;
		}
		fout.close();
	}
}


int main(){
	int choose;
	Encryption file;
	cout<<"------ FILE ENCRYPTION -------"<<endl;
	do{
		cout<<"Press 1 to encrypt file"<<endl;
		cout<<"Press 2 to decrypt file"<<endl;
		cout<<"Press 3 to show file"<<endl;
		cout<<"Press 4 to exit "<<endl;
		cin>>choose;
		
		switch(choose){
			case 1:{
				file.encryptFile();
				break;
			}
			case 2:{
				file.decryptFile();
				break;
			}
			case 3:{
				file.showFile();
				break;
			}
			case 4:{
				
				break;
			}
			default:{
				cout<<"Enter Valid Input."<<endl;
				break;
			}
		}
	}while(choose!=4);
	
	return 0;
}
