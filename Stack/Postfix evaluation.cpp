#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool IsNumericDigit(char c){
    if(c>='0'&&c<='9')
    return true;

    else 
       return false;
}

bool Isoperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return true;
    }
    else{
        return false;
    }
}

int PerformOperation(char ch,int operand1,int operand2){
if(ch=='+')
return operand1+operand2;
else if(ch=='-')
return operand1-operand2;
else if(ch=='*')
return operand1*operand2;
else if(ch=='/')
return operand1/operand2;
else
cout<<"Unexpected error \n";
return -1;
}

int EvaluatePostfix(string expression){
    stack<int>s;
    for(int i=0;i<expression.length();i++){


        if(expression[i]==' '||expression[i]==','){
            continue;
        }


        else if(Isoperator(expression[i])){
              int operand2=s.top();
              s.pop();
              int operand1=s.top();
              s.pop();

              int result=PerformOperation(expression[i],operand1,operand2);
              s.push(result);
        }



        else if(IsNumericDigit(expression[i])){
             int operand=0;

            /*Here we are assuming that the user will input the string expression along with spaces and 
              commas.If you don't use spaces and commas in the input you will get a wrong answer*/

              /*If you want to enter the string without using spaces and commas then remove the while loop 
              and write
                  
                    operator=expression[i]-'0';
                    s.push(operator);

              This will do the job.*/

              
             while(i<expression.length()&&IsNumericDigit(expression[i])){
                 operand=(operand*10)+(expression[i]-'0');
                 i++;
             }
             i--;
             s.push(operand);
        }
    }
    return s.top();
}

int main(){
    string expression;
    cout<<"Enter a postfix expression\n";
    getline(cin,expression);
    int result=EvaluatePostfix(expression);
    cout<<"Output="<<result<<endl;
}

