/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"
//Write your code below this line

Parser::Parser(){
    vector<ExprTreeNode*> hhh;
    this->expr_trees=hhh;
    SymbolTable* symtable1=new SymbolTable();
    this->symtable=symtable1;
}
 
    // ExprTreeNode *root = expr_trees[expr_trees.size()-1];
    // symtable->insert(root->left->id, root->right->evaluated_value);

int power(int a,int b){
    int answer=1;
    for(int i=0;i<b;i++){
        answer=answer*a;
    }
    return answer;
}

int convert_toint(string s){
    int ans=0;
    for(int j=0;j<s.size();j++){
        ans=ans+(s[j]-'0')*power(10,s.size()-j-1);
    }
    return ans;
}

void Parser::parse(vector<string> expression){
int c=1;
//point to be noted
// if(expression[0]=="del"){
//     last_deleted=symtable->search(expression[2]);
//     ExprTreeNode* rooty=new ExprTreeNode(":=",1);
//     ExprTreeNode* dely=new ExprTreeNode("DEL",1);
//     ExprTreeNode* vary=new ExprTreeNode("VAR",1);
//     vary->id=expression[2];
//     rooty->left=dely;
//     rooty->right=vary;
//     expr_trees.push_back(rooty);
//     // symtable->remove(expression[2]);
    

// }

// else{
ExprTreeNode* lefty=new ExprTreeNode("VAR",c);
lefty->id=expression[0];
if(lefty->id=="del"){
    lefty->type="DEL";
}
if(lefty->id=="ret"){
    lefty->type="RET";
}

ExprTreeNode* root=new ExprTreeNode(":=",c);
root->id=expression[1];
root->left=lefty;
vector<string> operators;
vector<ExprTreeNode*> nodes;
for(int i=2;i<expression.size();i++){
    //"(", "13", "+", "(", "2", "+", "(", "2", "/", "51", ")", ") )"
    if(expression[i]=="+" || expression[i]=="-" || expression[i]=="*" || expression[i]=="/" || expression[i]=="%"){
        operators.push_back(expression[i]);
        int temp=1;
        string t;
        if(expression[i]=="+"){
            t="ADD";
        }
        if(expression[i]=="-"){
            t="SUB";
        }
        if(expression[i]=="*"){
            t="MUL";
        }
        if(expression[i]=="/"){
            t="DIV";
        }
        if(expression[i]=="%"){
            t="MOD";
        }
        ExprTreeNode* temp1=new ExprTreeNode(t,temp);
        nodes.push_back(temp1);
    }
    else if(expression[i]=="("){
        operators.push_back(expression[i]);
        
    }
    else if(expression[i]==")"){
        string op1;
        op1=operators[operators.size()-1];
        operators.pop_back();
        operators.pop_back();
        ExprTreeNode* rightint;
        ExprTreeNode* leftint;
        ExprTreeNode* op2;
        rightint=nodes[nodes.size()-1];
        leftint=nodes[nodes.size()-3];
        op2=nodes[nodes.size()-2];
        nodes.pop_back();
        nodes.pop_back();
        nodes.pop_back();
        // if(rightint->type=="VAR"){
        //     rightint->evaluated_value=symtable->search(rightint->id);
        // }
        // if(leftint->type=="VAR"){
        //     leftint->evaluated_value=symtable->search(leftint->id);
        // }
        op2->right=rightint;
        op2->left=leftint;
        // if(op2->type=="ADD"){
        //     op2->evaluated_value=UnlimitedRational::add(rightint->evaluated_value,leftint->evaluated_value);
        // }
        // if(op2->type=="SUB"){
        //     op2->evaluated_value=UnlimitedRational::sub(leftint->evaluated_value,rightint->evaluated_value);
        // }
        // if(op2->type=="MUL"){
        //     op2->evaluated_value=UnlimitedRational::mul(rightint->evaluated_value,leftint->evaluated_value);
        // }
        // if(op2->type=="DIV"){
        //     op2->evaluated_value=UnlimitedRational::div(leftint->evaluated_value,rightint->evaluated_value);
        // }
        nodes.push_back(op2);
    }
    else{
        if((expression[i][0]<='Z' && expression[i][0]>='A') || (expression[i][0]<='z' && expression[i][0]>='a') ){
            // UnlimitedRational* yess=symtable->search(expression[i]);
            ExprTreeNode* temp1=new ExprTreeNode("VAR",1);
            // temp1->evaluated_value=yess;
            temp1->id=expression[i];
            nodes.push_back(temp1);
            
        }
        else{
        // UnlimitedInt* temp;
        // if(expression[i][0]!='-'){
        // temp=new UnlimitedInt("+"+expression[i]);
        // }
        // else{
        //     temp=new UnlimitedInt(expression[i]);
        // }
        string y="VAL";
       
        ExprTreeNode* temp1=new ExprTreeNode(y,convert_toint(expression[i]));
        
        nodes.push_back(temp1);
        
        }
    }
}
root->right=nodes[0];
// root->left->evaluated_value=root->right->evaluated_value;
this->expr_trees.push_back(root);
if(root->left->type=="VAR"){
    symtable->insert(root->left->id);
}
else if(root->left->type=="DEL"){
    last_deleted=symtable->search(root->right->id);
    symtable->remove(root->left->id);
}
}

// }



void deleteallnodes(ExprTreeNode* rooty){
    
    if(rooty->right!=nullptr && rooty->left!=nullptr){
        
        ExprTreeNode* tempr=rooty->right;
        ExprTreeNode* templ=rooty->left;
        deleteallnodes(tempr);
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right==nullptr && rooty->left!=nullptr){
        
        ExprTreeNode* templ=rooty->left;
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right!=nullptr && rooty->left==nullptr){
        ExprTreeNode* tempr=rooty->right;
        
        deleteallnodes(tempr);
        delete rooty;
        
    }
    else if(rooty->right==nullptr && rooty->left==nullptr){
        delete rooty;
    }
    
    

    
}
Parser::~Parser(){
delete symtable;
    
    for (int i = 0; i < expr_trees.size(); i++)
    {
        
        deleteallnodes(expr_trees[i]);
        
    }
 }


