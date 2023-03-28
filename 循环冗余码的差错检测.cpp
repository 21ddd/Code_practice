#include<bits/stdc++.h>
using namespace std;
/*

请采用VC++，编写代码，实现基于循环冗余码的差错检测。

具体步骤：
?1）输入待传输的二进制串；

2）输入被除数：二进制串；

3）计算，输出余数；

4）输出发送的数据；
sample1:
Please enter the Binary strings:  101001
Please enter the divisor:  1101
The remainder is: 001
The result is:    110101001 
sample2:

*/
string quotient = ""; //商 
string remainders = ""; //余数 
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
