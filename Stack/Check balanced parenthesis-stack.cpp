#include<iostream>
#include<stack>
using namespace std;
bool Arepair(char opening,char closing){
    if(opening=='('&&closing==')')return true;
    if(opening=='{'&&closing=='}')return true;
    if(opening=='['&&closing==']')return true;
    else 
    return false;
}

bool AreParenthesesBalanced(string str){
    stack<char>s;
    for(int i=0;i<str.length();++i){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']'){
            if(s.empty()||!Arepair(s.top(),str[i])){
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    return s.empty()?true:false;
}
int main(){
           string str;
           cout<<"Enter a string:"<<endl;
           cin>>str;
           if(AreParenthesesBalanced(str)){
               cout<<"Balanced"<<endl;
           }
           else{
               cout<<"Not Balanced."<<endl;
           }
           
}