/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"


ExprTreeNode::ExprTreeNode(){
    // UnlimitedRational* val1; 
    // val=val1;
    type="";
    id="";

}

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
    UnlimitedInt* one=new UnlimitedInt(1);
    UnlimitedRational* ducky=new UnlimitedRational(v,one);
    
    type=t;
    id="";
    if(t=="VAL"){ 
        val=ducky;
        evaluated_value=ducky;
    }
    
}


ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){
    type=t;
    id="";
    if(t=="VAL"){
        val=v;
        evaluated_value=v;
    }
}

ExprTreeNode::~ExprTreeNode(){
    
    left=nullptr;
    right=nullptr;
    
}