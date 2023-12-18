/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"


//Write your code below this line
void deleteallnodes(SymNode* rooty){
    if(rooty->right!=NULL && rooty->left!=NULL){
        SymNode* tempr=rooty->right;
        SymNode* templ=rooty->left;
        deleteallnodes(tempr);
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right==NULL && rooty->left!=NULL){
        SymNode* templ=rooty->left;
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right!=NULL && rooty->left==NULL){
        SymNode* tempr=rooty->right;
        
        deleteallnodes(tempr);
        delete rooty;
        
    }
    else if(rooty->right==NULL && rooty->left==NULL){
        delete rooty;
    }
    


}

void Updateheights(SymNode* &node)
{
    // if (node == NULL){
    //     return;
    // }  
    // Updateheights(node->left);
    // Updateheights(node->right);
    // if(node->right==NULL && node->left==NULL){
    //     node->height=1;
    // }
    // else if(node->right!=NULL && node->left==NULL){
    //     node->height=1+node->right->height;
    // }
    // else if(node->right==NULL && node->left!=NULL){
    //     node->height=1+node->left->height;
    // }
    // else if(node->right!=NULL && node->left!=NULL){
    //     node->height=1+max(node->left->height,node->right->height);
    // }
    if(node==NULL){
        return;
    }
    else if(node->right==NULL && node->left==NULL){
        node->height=1;
        
    }
    else if(node->right!=NULL && node->left==NULL){
        node->height=node->right->height+1;
    }
    else if(node->right==NULL && node->left!=NULL){
        node->height=node->left->height+1;
    }
    else if(node->right!=NULL && node->left!=NULL){
        node->height=1+max(node->right->height,node->left->height);
    }
    SymNode* jacob;
    jacob=node;
    while(jacob->par!=NULL){
        jacob->par->height=max(jacob->par->right ? jacob->par->right->height : 0, jacob->par->left ? jacob->par->left->height : 0) + 1;
        jacob=jacob->par;
        }


}

SymbolTable::SymbolTable(){
        
    root=NULL;
    size=0;
    
}

int balance(SymNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if(node->left!=NULL && node->right!=NULL)
    {
        return (node->left->height - node->right->height);
    }
    else if(node->left==NULL && node->right!=NULL){
        return - node->right->height;
    }
    else if(node->left!=NULL && node->right==NULL){
        return node->left->height;
    }
}

 void SymbolTable::insert(string k){
    if(root==NULL){
        SymNode* rooty=new SymNode();
        rooty->key=k;
        rooty->par=NULL;
        rooty->left=NULL;
        rooty->right=NULL;
        rooty->height=1;
        root=rooty;
        size=1;
    }
    else{
        // cout<<"entered else in rootnull case"<<endl;
    SymNode* temp=root;
    SymNode* node1=new SymNode(k);
    // temp=root;
    // cout<<temp->key<<endl;
    

    while(((k>temp->key) && temp->right!=NULL) || ((k<temp->key) && temp->left!=NULL)){
        // cout<<"entered while loop in else in rootnull case"<<endl;
        if(k>temp->key && temp->right!=NULL){
            temp=temp->right;
            
        }
        else if(k<temp->key && temp->left!=NULL){
            temp=temp->left;
        }
        else if(temp->left==NULL || temp->right==NULL){
            break;
        }
    }
    bool freee=true;
    if(k>temp->key){

        temp->right=node1;
        node1->par=temp;
    //    cout <<"node inserted"<<endl;
        // node1->address=temp->address+1;
    }
    else if(k<temp->key){
        temp->left=node1;
        node1->par=temp;
        // cout<<"node inserted"<<endl;
        // node1->address=temp->address+1;
    }
    else if(k==temp->key){
        freee=false;
    }
    if(freee){

        size++;
    SymNode* tempo;
    tempo=temp->par;
    SymNode* tempoparent;
    tempoparent=NULL;
    
    Updateheights(node1);
    // cout<<node1->height<<endl;
    int balancey=0;
    if(tempo!=NULL){
        tempoparent=tempo->par;
        balancey = balance(tempo);
    }
    
    if(tempoparent!=NULL){
        // cout<<"entered jumpy"<<endl;
        // cout<<balancey<<endl;
    while(tempoparent!=NULL && !(balancey<-1 || balancey>1)){
        // cout<<"yesss2"<<endl;
        // cout<<node1->key<<endl;
        // cout<<"entered while"<<endl;
        tempoparent=tempoparent->par;
        tempo=tempo->par;
    
    if(tempoparent!=NULL){
    if(tempoparent->left!=NULL && tempoparent->right!=NULL && tempoparent->right->height>tempoparent->left->height){
        tempo=tempoparent->right;
    }
    else if(tempoparent->left!=NULL && tempoparent->right!=NULL && tempoparent->right->height<tempoparent->left->height){
        tempo=tempoparent->left;
    }
    else if(tempoparent->left==NULL && tempoparent->right!=NULL){
        tempo=tempoparent->right;
    }
    else if(tempoparent->left!=NULL && tempoparent->right==NULL){
        tempo=tempoparent->left;
    }
    }
    balancey = balance(tempo);
    

    }
    }
    // cout<<"yess";
    if(tempo!=NULL && tempoparent!=NULL){
        // cout<<"yesss"<<endl;
        // cout<<"entered rotations"<<endl;
        bool pizza=true;
        // cout<<tempoparent->left->key<<endl;
        // cout<<tempo->key<<endl;

        if(tempo==tempoparent->right){
            // cout<<"entered tempo right"<<endl;
            SymNode* jock;
        int lexists,rexists;
        lexists=1;
        rexists=1;    
        int balancey = balance(tempo);
        if(tempo->left==NULL){
            lexists=0;
        }
        if(tempo->right==NULL){
            rexists=0;
        }
        if(lexists==1){
            if(balancey > 1 && k < tempo->left->key){
            // cout<<"entered ll rot"<<endl;
            jock=tempo->LeftLeftRotation();
            tempoparent->right=jock;
            jock->par=tempoparent;
            // jock->right->height-=1;
            // jock->height+=1;
            // jock->left->height=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            
        }
        else if(balancey > 1 && k > tempo->left->key){
            // cout<<"entered lr rot"<<endl;
            jock=tempo->LeftRightRotation();
            // cout<<jock->key<<endl;
            tempoparent->right=jock;
            jock->par=tempoparent;
            // jock->height=2;
            // jock->right->height-=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
        }
        }
         if(rexists==1){
            if(balancey < -1 && k > tempo->right->key){
            // cout<<"entered rr rot"<<endl;
            jock=tempo->RightRightRotation();
            tempoparent->right=jock;
            jock->par=tempoparent;
            // jock->left->height-=1;
            // jock->height+=1;
            // jock->right->height=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
        }
        else if(balancey < -1 && k < tempo->right->key){
            // cout<<"entered rl rot"<<endl;
            jock=tempo->RightLeftRotation();
            // cout<<jock->key<<endl;
            tempoparent->right=jock;
            jock->par=tempoparent;
            // jock->height=2;
            // jock->left->height-=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
        }
        }
        
        
        }
    else if(tempo==tempoparent->left){
            SymNode* jock;
            // cout<<"entered tempo left"<<endl;
            int lexists,rexists;
        lexists=1;
        rexists=1;    
        int balancey = balance(tempo);
        if(tempo->left==NULL){
            lexists=0;
        }
        if(tempo->right==NULL){
            rexists=0;
        }
        if(lexists==1){
            if(balancey > 1 && k < tempo->left->key){
            
            jock=tempo->LeftLeftRotation();
            tempoparent->left=jock;
            jock->par=tempoparent;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            
            pizza=false;
        }
        else if(balancey > 1 && k > tempo->left->key){
           
            jock=tempo->LeftRightRotation();
            // cout<<jock->key<<endl;
            tempoparent->left=jock;
            jock->par=tempoparent;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            pizza=false;
        }
        }
        if(rexists==1){
            if(balancey < -1 && k > tempo->right->key){
            // cout<<"banana"<<endl;
            jock=tempo->RightRightRotation();
            tempoparent->left=jock;
            jock->par=tempoparent;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            pizza=false;
        }
        else if(balancey < -1 && k < tempo->right->key){
            
            jock=tempo->RightLeftRotation();
            // cout<<jock->key<<endl;
            tempoparent->left=jock;
            jock->par=tempoparent;

            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            pizza=false;
        }
        }
        
        
        }
        while(root->par!=NULL){
        root=root->par;
        }

    if(pizza){
    //     SymNode* temp6;
    //     temp6=node1;
    //     temp6->height=1;
    //     temp6=temp6->par;
    // while(temp6!=NULL){
    //     temp6->height=1+max(temp6->left->height,temp6->right->height);
    //     temp6=temp6->par;
    // }
        // Updateheights(node1);
    }
    // tempoparent=tempoparent->par;
    // if(tempoparent->left!=NULL && tempoparent->right!=NULL && tempoparent->right->height>tempoparent->left->height){
    //     tempo=tempoparent->right;
    // }
    // else if(tempoparent->left!=NULL && tempoparent->right!=NULL && tempoparent->right->height<tempoparent->left->height){
    //     tempo=tempoparent->left;
    // }
    // else if(tempoparent->left==NULL && tempoparent->right!=NULL){
    //     tempo=tempoparent->right;
    // }
    // else if(tempoparent->left!=NULL && tempoparent->right==NULL){
    //     tempo=tempoparent->left;
    // }
    }
    if(tempoparent==NULL ){
        // cout<<"entered rotations pussy"<<endl;
        
        bool pizza=true;
        SymNode* jock;
        int lexists,rexists;
        lexists=1;
        rexists=1;    
        int balancey=0;
        if(tempo!=NULL){
            
            int balancey = balance(tempo);
        
        
        if(tempo->left==NULL){
            lexists=0;
        }
        if(tempo->right==NULL){
            rexists=0;
        }
        if(lexists==1){
            if(balancey > 1 && k < tempo->left->key){
            // cout<<"entered ll rot"<<endl;
            jock=tempo->LeftLeftRotation();
            // jock->right->height-=1;s
            // jock->height+=1;
            // jock->left->height=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
            
        }
        else if(balancey > 1 && k > tempo->left->key){
            // cout<<"entered lr rot"<<endl;
            jock=tempo->LeftRightRotation();
            
            // jock->height=2;
            // jock->right->height-=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
        }
        }
         if(rexists==1){
            if(balancey < -1 && k > tempo->right->key){
            // cout<<"entered rr rot"<<endl;
            jock=tempo->RightRightRotation();
            // cout<<"gota"<<endl;
            // jock->left->height-=1;
            // jock->height+=1;
            // jock->right->height=1;
            pizza=false;
            
            while(root->par!=NULL){
        
        root=root->par;
    }
    
            Updateheights(jock);
        }
        else if(balancey < -1 && k < tempo->right->key){
            // cout<<"entered rl rot"<<endl;
            jock=tempo->RightLeftRotation();
            // jock->height=2;
            // jock->left->height-=1;
            pizza=false;
            while(root->par!=NULL){
        root=root->par;
    }
            Updateheights(jock);
        
        }
         }
        
        }
        if(pizza){
    //     SymNode* temp6;
    //     temp6=node1;
    //     temp6->height=1;
    //     temp6=temp6->par;
    // while(temp6!=NULL){
    //     temp6->height=1+max(temp6->left->height,temp6->right->height);
    //     temp6=temp6->par;
    // }
        // cout<<"here"<<endl;
        // // Updateheights();
        // cout<<"here"<<endl;
    }
        
    }
    
    }
    

    }
    
}

int SymbolTable::search(string k){
    bool resp=true;
    SymNode* temp;
    temp=root;
    while(temp!=NULL){

        if(k==temp->key){
            resp=true;
            break;
        }
        
        else if(k>temp->key && temp->right!=NULL){
            temp=temp->right;
        }
        else if(k<temp->key && temp->left!=NULL){
            temp=temp->left;
        }
        else if(temp->left==NULL || temp->right==NULL){
            break;
            resp=false;
        }
    }
    if(resp && k==temp->key){ 
        return temp->address;
    }
    else{
        return -2;
    }
}

void SymbolTable::assign_address(string k,int idx){
    bool resp=true;
    SymNode* temp;
    temp=root;
    while(temp!=NULL){

        if(k==temp->key){
            resp=true;
            break;
        }
        
        else if(k>temp->key && temp->right!=NULL){
            temp=temp->right;
        }
        else if(k<temp->key && temp->left!=NULL){
            temp=temp->left;
        }
        else if(temp->left==NULL || temp->right==NULL){
            break;
            resp=false;
        }
    }
    if(resp && k==temp->key){ 
        temp->address=idx;
    }
    else{
        //nothing;
    }
}

int SymbolTable::get_size(){
    return size;
}

SymNode* SymbolTable::get_root(){
    return root;
}

SymbolTable::~SymbolTable(){
    deleteallnodes(root);
}



SymNode* leftspinz(SymNode* node) {
    SymNode* newRoot = node->right;
    SymNode* rooty;
    SymNode* nodekabaap;
    nodekabaap=node->par;
    int resp=2;
    if(nodekabaap!=NULL){
        if(nodekabaap->right==node){
            resp=1;
        }
        else if(nodekabaap->left==node){
            resp=0;
        }
    }
    node->right = newRoot->left;
    if(node->right != NULL){
        newRoot->left->par = node;
    }
    newRoot->left = node;
    node->par = newRoot;
    if(resp==2){
        newRoot->par=NULL;
    }
    else if(resp==1){
        newRoot->par=nodekabaap;
        nodekabaap->right=newRoot;
    }
    else if(resp==0){
        newRoot->par=nodekabaap;
        nodekabaap->left=newRoot;
    }
    
    rooty = node;
    while(rooty->par != NULL){
        rooty = rooty->par;
        
    }
    Updateheights(rooty);
    return newRoot;
}

SymNode* rightspinz(SymNode* node) {
    SymNode* newRoot = node->left;
    SymNode* rooty;
    SymNode* nodekabaap;
    nodekabaap=node->par;
    int resp=2;
    if(nodekabaap!=NULL){
        if(nodekabaap->right==node){
            resp=1;
        }
        else if(nodekabaap->left==node){
            resp=0;
        }
    }
    node->left = newRoot->right;
    if(node->left != NULL){
        node->left->par = node; 
    }

    newRoot->right = node;
    node->par = newRoot;
    if(resp==2){
        newRoot->par=NULL;
    }
    else if(resp==1){
        newRoot->par=nodekabaap;
        nodekabaap->right=newRoot;
    }
    else if(resp==0){
        newRoot->par=nodekabaap;
        nodekabaap->left=newRoot;
    }
    
    rooty = node;
    while(rooty->par != NULL){
        rooty = rooty->par;
    }
    Updateheights(rooty);
    return newRoot;
}

SymNode* findrightkamin(SymNode* node) {
    SymNode* temp = node;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}

SymNode* removewithparam(SymNode* root, string key) {
    if (root == NULL){
        return root;
    } 

    if (key < root->key) {
        root->left = removewithparam(root->left, key);
    } 
    else if (key > root->key) {
        root->right = removewithparam(root->right, key);
    } 
    else {
        if (root->left==NULL || root->right==NULL) {
            SymNode* temp;
            
            if(root->left){
                temp=root->left;
            }
            else{
                temp=root->right;
            }
            if (temp==NULL) {
                temp = root;
                root = NULL;
            } else {
                root = temp;
            }
            delete temp;
        if (root) {
                root->par = NULL;
            }
        } 
        else {
            SymNode* temp = findrightkamin(root->right);
            root->key = temp->key;
            root->address=temp->address;
            root->right = removewithparam(root->right, temp->key);
        }
    }
    
    if (!root){
        
        return root;
    } 
 
    Updateheights(root);
    
    int balancey = balance(root);
    
    if (balancey > 1) {
        
        if (balance(root->left) >= 0) {
            
            
            return rightspinz(root);
        } else {

            root->left = leftspinz(root->left);
            return rightspinz(root);
        }
    }

    if (balancey < -1) {
      
        if (balance(root->right) <= 0) {
            
            return leftspinz(root);
        } else {

            root->right = rightspinz(root->right);
            return leftspinz(root);
        }
    }

    return root;
}

void SymbolTable::remove(std::string k){
    root = removewithparam(root,k);
    size--;
}

