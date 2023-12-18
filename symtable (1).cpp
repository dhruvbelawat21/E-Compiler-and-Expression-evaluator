
#include "symtable.h"

SymbolTable::SymbolTable(){
    
    root=new SymEntry();
    size=0;
    
}
void deleteallnodes(SymEntry* rooty){
    if(rooty->right!=nullptr && rooty->left!=nullptr){
        SymEntry* tempr=rooty->right;
        SymEntry* templ=rooty->left;
        deleteallnodes(tempr);
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right==nullptr && rooty->left!=nullptr){
        SymEntry* templ=rooty->left;
        deleteallnodes(templ);
        delete rooty;
    }
    else if(rooty->right!=nullptr && rooty->left==nullptr){
        SymEntry* tempr=rooty->right;
        
        deleteallnodes(tempr);
        delete rooty;
        
    }
    else if(rooty->right==nullptr && rooty->left==nullptr){
        delete rooty;
    }
    

}
SymbolTable::~SymbolTable(){
    
    deleteallnodes(root);
    //to delete all nodes
}

void SymbolTable::insert(string k, UnlimitedRational* v){
    
    if(size==0){
        
        SymEntry* temp=new SymEntry(k,v);
        
        root=temp;
        size++;
        
    }
    
    else if(size>0){
        
    SymEntry* temp=new SymEntry();
    size++;
    
    SymEntry* node1=new SymEntry(k,v);
    temp=root;
    
    

    while(((k>temp->key) && temp->right!=nullptr) || ((k<temp->key) && temp->left!=nullptr)){
        if(k>temp->key && temp->right!=nullptr){
            temp=temp->right;
            
        }
        else if(k<temp->key && temp->left!=nullptr){
            temp=temp->left;
        }
        else if(temp->left==nullptr || temp->right==nullptr){
            break;
        }
    }
    
    if(k>temp->key){
        temp->right=node1;
    }
    else if(k<temp->key){
        temp->left=node1;
    }

}
}

void SymbolTable::remove(string k){
    bool resp=true;
    size--;
    int pos; //0 if left and 1 if right.
    SymEntry* temp;
    SymEntry* temp2;
    SymEntry* tempparent;
    temp=root;
    while(temp!=nullptr){
        if(k==temp->key){
            resp=true;
            break;
        }
        
        else if(k>temp->key && temp->right!=nullptr){
            tempparent=temp;
            pos=1;
            temp=temp->right;
        }
        else if(k<temp->key && temp->left!=nullptr){
            tempparent=temp;
            pos=0;
            temp=temp->left;
        }
        else if(temp->left==nullptr || temp->right==nullptr){
            break;
            resp=false;
        }
    }

    if(resp){
        if(temp->left==nullptr && temp->right==nullptr){
                if(pos==0){
                    tempparent->left=nullptr;
                    delete temp;
                }
                if(pos==1){
                    tempparent->right=nullptr;
                    delete temp;
                }
                resp=false;
        }
        if(temp->left!=nullptr && temp->right==nullptr){
                if(pos==0){
                    
                    tempparent->left=temp->left;
                    delete temp;
                }
                if(pos==1){
                    tempparent->right=temp->left;
                    delete temp;
                }
                resp=false;
        }
        if(temp->left==nullptr && temp->right!=nullptr){
            if(pos==0){
                    
                tempparent->left=temp->right;
             delete temp;
            }
            if(pos==1){
                tempparent->right=temp->right;
                delete temp;
            }
            resp=false;
    }
        if(temp->left!=nullptr && temp->right!=nullptr){
            temp2=temp->right;
            while(temp2->left!=nullptr){
                temp2=temp2->left;
            }
            UnlimitedRational* vee1=temp2->val;
            string kee1=temp2->key;
            UnlimitedRational* vee2=temp->val;
            string kee2=temp->key;
            temp->val=vee1;
            temp->key=kee1;
            temp2->val=vee2;
            temp2->key=kee2;
            remove(k);

            
        }
    }
}
 
UnlimitedRational* SymbolTable::search(string k){
    bool resp=true;
    SymEntry* temp;
    temp=root;
    while(temp!=nullptr){
        if(k==temp->key){
            resp=true;
            break;
        }
        
        else if(k>temp->key && temp->right!=nullptr){
            temp=temp->right;
        }
        else if(k<temp->key && temp->left!=nullptr){
            temp=temp->left;
        }
        else if(temp->left==nullptr || temp->right==nullptr){
            break;
            resp=false;
        }
    }
    if(resp){ 
        return temp->val;
    }
    else{
        UnlimitedInt* p=new UnlimitedInt(0);
        UnlimitedInt* q=new UnlimitedInt(1);
        UnlimitedRational* adv=new UnlimitedRational(p,q);
        return adv;
    }
}

int SymbolTable::get_size(){
    return size;
}


SymEntry* SymbolTable::get_root(){
    return root;
}
