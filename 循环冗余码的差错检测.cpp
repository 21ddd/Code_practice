#include<bits/stdc++.h>
using namespace std;
/*
��2101 ���㷫
�����VC++����д���룬ʵ�ֻ���ѭ��������Ĳ���⡣

���岽�裺
?1�����������Ķ����ƴ���

2�����뱻�����������ƴ���

3�����㣬���������

4��������͵����ݣ�
sample1:
Please enter the Binary strings:  101001
Please enter the divisor:  1101
The remainder is: 001
The result is:    110101001 
sample2:

*/
string quotient = ""; //�� 
string remainders = ""; //���� 
int startIndex = 0;
int endIndex = 3; 
string binaryStrings;
string divisor;

string quitZero(string remainders){
	string temp = "";
	for(int i=0;i<remainders.size();i++){
		if(remainders[i]=='1'){
			for(int j=i;j<remainders.size();j++){
				temp += remainders[i];
			}
			break;
		}
	}
	return temp;
}

void d(){
	string temp = remainders; 
	for(int i=endIndex-1;i>=0;i--){
		if(remainders[i]==divisor[i]){
			remainders[i] = '0';
		}
		else{
			remainders[i] = '1'; 
		}
	}
	remainders = quitZero(remainders);
}

void Division(){
	if(quotient.size()==binaryStrings.size()-3){
		if(remainders.size()==4){
			d();
		}
		return ;
	}
	if(remainders.size()==4){
		d();
		Division();	
	}
	else if(remainders.size()==3){
		quotient += "1";
		endIndex++;
		remainders = remainders + binaryStrings[endIndex];
		Division();
	}
	else{
		quotient += "0";
		endIndex++;
		remainders = remainders + binaryStrings[endIndex];
		Division();
	}
}

int main(){
	cout<<"Please enter the Binary strings:  ";
	cin>>binaryStrings;
	cout<<"Please enter the divisor:  ";
	cin>>divisor;
	binaryStrings += "000";
	quotient = "1" + quotient;
	string temp = "";
	for(int i=startIndex;i<=endIndex;i++){
			temp += binaryStrings[i];
	}
	for(int i=3;i>=0;i--){
		if(temp[i]==divisor[i]){
			remainders = "0" + remainders;
		}
		else{
			remainders = "1" + remainders;
		}
	}
	remainders = quitZero(remainders);
	Division();
	while(remainders.size()<3){
		remainders = "0" + remainders;
	}
	cout<<"The remainder is: "<<remainders<<endl; 
	cout<<"The result is:    "<<quotient+remainders<<endl;
	
} 
