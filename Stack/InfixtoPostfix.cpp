#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool IsOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='$'){
        return true;
    }
    else {
        return false;
    }
}
  
bool IsOperand(char c){
    if(c>='0'&&c<='9')return true;
    if(c>='a'&&c<='z')return true;
    if(c>='A'&&c<='Z')return true;
    return false;
}

int GetOperatorWeight(char op){
    int weight=1;
    switch (op){
        case '+':
        case '-':
                 weight=1;
                 break;
        case '*':
        case '/':
                 weight=2;
                 break;
        case '$':
                 weight=3;

    }
    return weight;
}

int IsRightAssociative(char op){
    if(op=='$'){
        return true;
    }
    return false;
}

int HasHigherPrecedence(char op1,char op2){
    int op1weight=GetOperatorWeight(op1);
    int op2weight=GetOperatorWeight(op2);
    if(op1weight==op2weight){
        if(IsRightAssociative(op1)){
            return false;
        }
        else{
            return true;
        }
    }
    return op1weight>op2weight?true:false;
}

string InfixToPostfix(string exp){
    stack<char>s;
    string postfix=" ";
    for(int i=0;i<exp.length();++i){

      if(exp[i]==' '||exp[i]==','){
          continue;
      }

      else if(IsOperator(exp[i])){
          while(!s.empty()&&s.top()!='('&&HasHigherPrecedence(s.top(),exp[i])){
            postfix+=s.top();
            s.pop();
          }
          s.push(exp[i]);
      }

      else if(IsOperand(exp[i])){
         postfix+=exp[i];
      }

      else if(exp[i]=='('){
          s.push(exp[i]);
      }

      else if(exp[i]==')'){
       while(!s.empty()&&s.top()!='('){
           postfix+=s.top();
           s.pop();
       }
       s.pop();
      }
    }
      while(!s.empty()){
          postfix+=s.top();
          s.pop();
      }
      return postfix;
}

int main(){
    string expression;
    cout<<"Enter the Infix expression."<<endl;
    getline(cin,expression);
    string postfix=InfixToPostfix(expression);
    cout<<"Output="<<postfix<<endl;

}