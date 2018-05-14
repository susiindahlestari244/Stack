#include<iostream>
#include<cstring>
#include <cstdlib>
#include<stack>
using namespace std;


	string infix_ke_postfix(string ekspresi);
	int tingkat_operator(char operator1, char operator2);
	bool Operator(char C);
	bool Operand(char C);


			string infix_ke_postfix(string ekspresi){ 
			stack<char> S;
			string postfix = ""; 
			for(int i = 0;i< ekspresi.length();i++) {
			if(ekspresi[i] == ' ' || ekspresi[i] == ',') continue; 
			else if(Operator(ekspresi[i])){
			
			while(!S.empty() && S.top() != '(' && tingkat_operator(S.top(),ekspresi[i])){
			
				postfix+= S.top();
				S.pop();
			}
			S.push(ekspresi[i]);
		}
		else if(Operand(ekspresi[i])){
		
			postfix +=ekspresi[i];
		}

		else if (ekspresi[i] == '('){ 
		
			S.push(ekspresi[i]);
		}

		else if(ekspresi[i] == ')'){
		
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

bool Operand(char C){

	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool Operator(char C){

	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

int Associative(char op){

	if(op == '$') return true;
	return false;
}
 
int carioperator(char op){

	int weight = -1; 
	switch(op){
	
	case '+':
		
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	case '$':
		weight = 3;
	}
	return weight;
}

int tingkat_operator(char op1, char op2){

	int op1Weight = carioperator(op1);
	int op2Weight = carioperator(op2);
 
	if(op1Weight == op2Weight){
	
		if(Associative(op1)) return false;
		else return true;
		
	}
	return op1Weight > op2Weight ?  true: false;
}




struct Stack{

    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack( unsigned capacity ){

    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array) return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack){

    return stack->top == -1 ;
}
 
char peek(struct Stack* stack){

    return stack->array[stack->top];
}
 
char pop(struct Stack* stack){

    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(struct Stack* stack, char op){

    stack->array[++stack->top] = op;
}
 
 
int evaluatePostfix(char* exp){

    struct Stack* stack = createStack(strlen(exp));
    int i;
 
    if (!stack) return -1;
 	for (i = 0; exp[i]; ++i){
   	 if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else{
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]){
             case '+': push(stack, val2 + val1); break;
             case '-': push(stack, val2 - val1); break;
             case '*': push(stack, val2 * val1); break;
             case '/': push(stack, val2/val1);   break;
            }
        }
    }
    return pop(stack);
}
 

int main(){
	cout<<"===================================================="<<endl;
	cout<<"\t\t Mayda Brilliani Fauzi 1717051003"<<endl;
	cout<<"\t\t Susi Indah Lestari S1717051035"<<endl;
	cout<<"===================================================="<<endl;
	string ekspresi;
	
	ekspresi="5*(6+2)+4-8";
	cout<<"expresi = "<<ekspresi<<endl<<endl;
	
	string postfix = infix_ke_postfix(ekspresi);
	cout<<"menjadi posfix = "<<postfix<<endl;
    char exp[] = "562+*4+8-";
    cout<<"hasil dari "<<exp<<" adalah "<< evaluatePostfix(exp);
    return 0;
}
