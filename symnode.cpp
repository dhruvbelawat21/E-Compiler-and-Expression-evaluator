/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

//Write your code below this line

SymNode::SymNode(){
    key="";
    height=0;
    par=NULL;
    left=NULL;
    right=NULL;

}

SymNode::SymNode(string k){
    key=k;
    height=0;
    par=NULL;
    left=NULL;
    right=NULL;
}

SymNode* SymNode::LeftLeftRotation(){
    // SymNode* tobeinserted;
    // //upar is identif of the insertednode
    // SymNode* Godnode;
    // Godnode=tobeinserted->par->par->par->par;
    // SymNode* semigodnode;
    // semigodnode=tobeinserted->par->par->par;
    // SymNode* demigodnode;
    // demigodnode=tobeinserted->par->par;
    // SymNode* demigodnode2;
    // demigodnode2=semigodnode->right;
    // SymNode* demigodnoderight;
    // demigodnoderight=demigodnode->right;
    // if(Godnode!=NULL){
    // if(Godnode->right==semigodnode){
    //     demigodnode->left->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     Godnode->right=demigodnode;
    //     demigodnode->right=semigodnode;
    //     semigodnode->left=demigodnoderight;
    //     demigodnode->par=Godnode;
    //     semigodnode->par=demigodnode;
    //     if(demigodnoderight!=NULL){
    //         demigodnoderight->par=semigodnode;
    //     }
        
        
    // }
    // else if(Godnode->left==semigodnode){
    //     demigodnode->left->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     Godnode->left=demigodnode;
    //     demigodnode->right=semigodnode;
    //     semigodnode->left=demigodnoderight;
    //     demigodnode->par=Godnode;
    //     semigodnode->par=demigodnode;
    //     if(demigodnoderight!=NULL){
    //         demigodnoderight->par=semigodnode;
    //     }
        
    // }
    // }
    // else{

    //     demigodnode->left->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     demigodnode->right=semigodnode;
    //     semigodnode->left=demigodnoderight;
    //     semigodnode->par=demigodnode;
    //     if(demigodnoderight!=NULL){
    //         demigodnoderight->par=semigodnode;
    //     }
        
    // }
        SymNode *n;
        n=this;
        SymNode *parent;
        SymNode *temp;
        parent = n;
        temp = parent->left;

        parent->left = temp->right;
        if(temp->right!=NULL){
            temp->right->par=parent;
        }
        
        temp->right = parent;
        
        temp->par=NULL;
        parent->par=temp;
        this->height = max(this->right ? this->right->height : 0, this->left ? this->left->height : 0) + 1;
        temp->height = max(temp->right ? temp->right->height : 0, temp->left ? temp->left->height : 0) + 1;
        return temp;

}

SymNode* SymNode::RightRightRotation(){
    // SymNode* tobeinserted;
    // //upar is identif of the insertednode
    // SymNode* Godnode;
    // Godnode=tobeinserted->par->par->par->par;
    // SymNode* semigodnode;
    // semigodnode=tobeinserted->par->par->par;
    // SymNode* demigodnode;
    // demigodnode=tobeinserted->par->par;
    // SymNode* demigodnode2;
    // demigodnode2=semigodnode->left;
    // SymNode* demigodnodeleft;
    // demigodnodeleft=demigodnode->left;
    // if(Godnode!=NULL){
    // if(Godnode->right==semigodnode){
    //     demigodnode->right->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     Godnode->right=demigodnode;
    //     demigodnode->left=semigodnode;
    //     semigodnode->right=demigodnodeleft;
    //     demigodnode->par=Godnode;
    //     semigodnode->par=demigodnode;
    //     if(demigodnodeleft!=NULL){
    //         demigodnodeleft->par=semigodnode;
    //     }
        
    // }
    // else if(Godnode->left==semigodnode){
    //     demigodnode->right->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     Godnode->left=demigodnode;
    //     demigodnode->left=semigodnode;
    //     semigodnode->right=demigodnodeleft;
    //     demigodnode->par=Godnode;
    //     semigodnode->par=demigodnode;
    //     if(demigodnodeleft!=NULL){
    //         demigodnodeleft->par=semigodnode;
    //     }
        
    // }
    // }
    // else{

    //     demigodnode->right->height=demigodnode->left->height-1;
    //     demigodnode->height=demigodnode->height-1;
    //     semigodnode->height=semigodnode->height+1;
    //     demigodnode2->height=demigodnode2->height+1;
    //     tobeinserted->height=demigodnode->height+2;

    //     demigodnode->left=semigodnode;
    //     semigodnode->right=demigodnodeleft;
    //     semigodnode->par=demigodnode;
    
    //     if(demigodnodeleft!=NULL){
    //         demigodnodeleft->par=semigodnode;
    //     }
    // }
        SymNode *n;
        n=this;
        SymNode* parent;
        SymNode* temp;
        parent = n;
        temp = parent->right;

        parent->right = temp->left;
        if(temp->left!=NULL){
            temp->left->par=parent;
        }   
        
        temp->left = parent;
        temp->par=NULL;
        parent->par=temp;
        this->height = max(this->right ? this->right->height : 0, this->left ? this->left->height : 0) + 1;
        temp->height = max(temp->right ? temp->right->height : 0, temp->left ? temp->left->height : 0) + 1;
        return temp; 
}

SymNode* SymNode::LeftRightRotation(){
        SymNode *n;
        n=this;
        SymNode *parent;
        SymNode *temp;
        SymNode *kik;
        parent = n;
        temp = parent->left;
        kik =parent->left->right;
        parent -> left = kik->right;
        if(kik->right!=NULL){
            kik->right->par=parent;
        }
        temp ->right = kik->left;
        if(kik->left!=NULL){
            kik->left->par=temp;
        }
        
        kik ->right = parent;
        parent->par=kik;
        kik->left = temp; 
        temp->par=kik;
        kik->par=NULL;
        this->height = max(this->right ? this->right->height : 0, this->left ? this->left->height : 0) + 1;
        temp->height = max(temp->right ? temp->right->height : 0, temp->left ? temp->left->height : 0) + 1;
        kik->height = max(kik->right ? kik->right->height : 0, kik->left ? kik->left->height : 0) + 1;
        return kik;
}

SymNode* SymNode::RightLeftRotation(){
        SymNode *n;
        n=this;
        SymNode *parent;
        SymNode *temp;
        SymNode *kik;
        parent = n;
        temp = parent->right;
        kik =parent->right->left;
        parent -> right = kik->left;
        if(kik->left!=NULL){
            kik->left->par=parent;
        }
        
        temp ->left = kik->right;
        if(kik->right!=NULL){
            kik->right->par=temp;
        }
        
        kik ->left = parent;
        parent->par=kik;
        kik->right = temp; 
        temp->par=kik;
        kik->par=NULL;
        this->height = max(this->right ? this->right->height : 0, this->left ? this->left->height : 0) + 1;
        temp->height = max(temp->right ? temp->right->height : 0, temp->left ? temp->left->height : 0) + 1;
        kik->height = max(kik->right ? kik->right->height : 0, kik->left ? kik->left->height : 0) + 1;
        return kik; 
}

SymNode::~SymNode(){
    par=NULL;
    left=NULL;
    right=NULL; 
}