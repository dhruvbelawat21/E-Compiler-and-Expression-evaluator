/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "eppcompiler.h"
//Write your code below this line

EPPCompiler::EPPCompiler(){
    string output_file="";
    memory_size=0;
    mem_loc={};



}

EPPCompiler::EPPCompiler(string out_file,int mem_limit){
    output_file=out_file;
    memory_size=mem_limit;
    for(int i=0;i<memory_size;i++){
        mem_loc.push_back(i);
    }
}

void EPPCompiler::compile(vector<vector<string>> code){
    
    for(int i=0;i<code.size();i++){
        
        vector<string> targcc={};
        targcc=code[i];
        vector<string> comands1;
        
        targ.parse(targcc);
        // cout<<"meow"<<endl;
        ExprTreeNode* temp= targ.expr_trees[targ.expr_trees.size()-1];
        ExprTreeNode* temp2=temp->left;
        if(temp2->type=="VAR"){
        if(targ.symtable->search(temp2->id)==-1){
            targ.symtable->assign_address(temp2->id,mem_loc[0]);
            mem_loc.erase(mem_loc.begin()+0);
        }
        //check onceeeeeeeee
        else{
            // int idxx;
            // idxx=targ.symtable->search(temp2->id);
            // targ.symtable->assign_address(temp2->id,idxx);

        }
        
        }
        else if(temp2->type=="DEL"){
            ExprTreeNode* temp3=temp->right;
            int gg=targ.last_deleted;
            
            mem_loc.push_back(gg);
            // targ.symtable->remove(temp3->id);
        }
        comands1=generate_targ_commands();
        
        write_to_file(comands1);
        
        
    }

}

void printPostorder(ExprTreeNode* node,vector<ExprTreeNode*> &post)
{
    if(node==NULL){
        return;
    }
    printPostorder(node->right,post);
    printPostorder(node->left,post);
    if(node!=NULL){
        post.push_back(node);
    }
    
}

vector<string> EPPCompiler::generate_targ_commands(){
    vector<string> commands2;
    vector<ExprTreeNode*> expr_trees1=targ.expr_trees;
    ExprTreeNode *temp=expr_trees1[expr_trees1.size()-1];
    vector<ExprTreeNode*> post1={};
    // vector<ExprTreeNode*> postp={};
    
    printPostorder(temp,post1);
    // cout<<"hmello"<<endl;
    ExprTreeNode* nody2;
    nody2=post1[post1.size()-2];
    // cout<<nody2->type<<endl;
    if(nody2->type=="VAR"){
    for(int k=0;k<post1.size()-2;k++){
        ExprTreeNode* nody;
        nody=post1[k];
        string linee;
        if(nody->type=="VAR"){
            linee="PUSH mem[";
            int idx;
            idx=targ.symtable->search(nody->id);
            linee=linee+to_string(idx);
            linee=linee+"]\n";
        }
        else if(nody->type=="VAL"){
            linee="PUSH ";
            // cout<<nody->num<<endl;
            linee=linee+to_string(nody->num)+"\n";
        }
        else if(nody->type=="SUB"){
            linee="SUB\n";
        }
        else if(nody->type=="ADD"){
            linee="ADD\n";
        }
        else if(nody->type=="MUL"){
            linee="MUL\n";
        }
        else if(nody->type=="DIV"){
            linee="DIV\n";
        }
        
        commands2.push_back(linee);
    }
    
    string linee;
    ExprTreeNode* nody;
    nody=post1[post1.size()-2];
    linee="mem[";
    int idx;
    idx=targ.symtable->search(nody->id);
    linee=linee+to_string(idx);
    linee=linee+"] = POP\n";
    commands2.push_back(linee);
    return commands2;
    }
    else if(nody2->type=="DEL"){
        string linee;
        linee="DEL = mem[";
        int idx;
        idx=targ.last_deleted;
        linee=linee+to_string(idx);
        linee=linee+"]\n";
        commands2.push_back(linee);
        return commands2;
    }
    else if(nody2->type=="RET"){
        
        
        for(int k=0;k<post1.size()-2;k++){
        ExprTreeNode* nody;
        nody=post1[k];
        string linee;
        if(nody->type=="VAR"){
            linee="PUSH mem[";
            int idx;
            idx=targ.symtable->search(nody->id);
            linee=linee+to_string(idx);
            linee=linee+"]\n";
        }
        else if(nody->type=="VAL"){
            linee="PUSH ";
            // cout<<nody->num<<endl;
            linee=linee+to_string(nody->num)+"\n";
        }
        else if(nody->type=="SUB"){
            linee="SUB\n";
        }
        else if(nody->type=="ADD"){
            linee="ADD\n";
        }
        else if(nody->type=="MUL"){
            linee="MUL\n";
        }
        else if(nody->type=="DIV"){
            linee="DIV\n";
        }
        
        commands2.push_back(linee);
    }
        string linee;
        linee="RET = POP\n";
        
        commands2.push_back(linee);
        return commands2;

    }





}

void EPPCompiler::write_to_file(vector<string> commands){
    ofstream outfile;
    outfile.open(output_file,std::ios::app);
    for(int j=0;j<commands.size();j++){
        outfile<<commands[j];
        outfile<<endl;
    }
    outfile.close();
    // outfile<<commands[commands.size()-1];
}

EPPCompiler::~EPPCompiler(){
    //abhi empty
    mem_loc.clear();
}


