/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"


Evaluator::Evaluator(){
    //nothing
    vector<ExprTreeNode*> hhh;
    this->expr_trees=hhh;
    SymbolTable* symtable1=new SymbolTable();
    this->symtable=symtable1;
} 
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
Evaluator::~Evaluator(){
    delete symtable;
    
    for (int i = 0; i < expr_trees.size(); i++)
    {
        
        deleteallnodes(expr_trees[i]);
        
    }
}


void Evaluator::parse(vector<string> code){

UnlimitedInt* a=new UnlimitedInt(1);
UnlimitedInt* b=new UnlimitedInt(1);
UnlimitedRational* c=new UnlimitedRational(a,b);
//point to be noted
ExprTreeNode* vari=new ExprTreeNode("VAR",c);
vari->id=code[0];
ExprTreeNode* root=new ExprTreeNode("VAL",c);
root->id=code[1];
root->left=vari;
vector<string> operators;
vector<ExprTreeNode*> nodes;
for(int i=2;i<code.size();i++){
    //"(", "13", "+", "(", "2", "+", "(", "2", "/", "51", ")", ") )"
    if(code[i]=="+" || code[i]=="-" || code[i]=="*" || code[i]=="/" || code[i]=="%"){
        operators.push_back(code[i]);
        UnlimitedInt* temp=new UnlimitedInt(1);
        string t;
        if(code[i]=="+"){
            t="ADD";
        }
        if(code[i]=="-"){
            t="SUB";
        }
        if(code[i]=="*"){
            t="MUL";
        }
        if(code[i]=="/"){
            t="DIV";
        }
        if(code[i]=="%"){
            t="MOD";
        }
        ExprTreeNode* temp1=new ExprTreeNode(t,temp);
        nodes.push_back(temp1);
    }
    else if(code[i]=="("){
        operators.push_back(code[i]);
        
    }
    else if(code[i]==")"){
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
        if(rightint->type=="VAR"){
            rightint->evaluated_value=symtable->search(rightint->id);
        }
        if(leftint->type=="VAR"){
            leftint->evaluated_value=symtable->search(leftint->id);
        }
        op2->right=rightint;
        op2->left=leftint;
        if(op2->type=="ADD"){
            op2->evaluated_value=UnlimitedRational::add(rightint->evaluated_value,leftint->evaluated_value);
        }
        if(op2->type=="SUB"){
            op2->evaluated_value=UnlimitedRational::sub(leftint->evaluated_value,rightint->evaluated_value);
        }
        if(op2->type=="MUL"){
            op2->evaluated_value=UnlimitedRational::mul(rightint->evaluated_value,leftint->evaluated_value);
        }
        if(op2->type=="DIV"){
            op2->evaluated_value=UnlimitedRational::div(leftint->evaluated_value,rightint->evaluated_value);
        }
        nodes.push_back(op2);
    }
    else{
        if((code[i][0]<='Z' && code[i][0]>='A') || (code[i][0]<='z' && code[i][0]>='a') ){
            UnlimitedRational* yess=symtable->search(code[i]);
            ExprTreeNode* temp1=new ExprTreeNode("VAR",yess);
            temp1->evaluated_value=yess;
            temp1->id=code[i];
            nodes.push_back(temp1);
            
        }
        else{
        UnlimitedInt* temp;
        if(code[i][0]!='-'){
        temp=new UnlimitedInt("+"+code[i]);
        }
        else{
            temp=new UnlimitedInt(code[i]);
        }
        string y="VAL";
        ExprTreeNode* temp1=new ExprTreeNode(y,temp);
        nodes.push_back(temp1);
        
        }
    }
}
root->right=nodes[0];
root->left->evaluated_value=root->right->evaluated_value;
this->expr_trees.push_back(root);
}

    
void Evaluator::eval()
{
    
    
    ExprTreeNode *root = expr_trees[expr_trees.size()-1];
    symtable->insert(root->left->id, root->right->evaluated_value);
}

