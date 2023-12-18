/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"

UnlimitedRational::UnlimitedRational(){
    UnlimitedInt* a1=new UnlimitedInt(0);
    UnlimitedInt* a2=new UnlimitedInt(1);
    p=a1;
    q=a2;
}
//&& a->get_sign()>=b->get_sign()

UnlimitedInt* gcd(UnlimitedInt* a,UnlimitedInt* b){
    if(a->get_sign()==-1){
        a=new UnlimitedInt("+"+a->to_string().substr(1));
    }
    if(b->get_sign()==-1){
        b=new UnlimitedInt("+"+b->to_string().substr(1));
    }
    if((a->get_size()>b->get_size()) || ((a->get_size()==b->get_size()) && (a->to_string()>b->to_string()))){
        UnlimitedInt* c=UnlimitedInt::mod(a,b);
        if (c->to_string()=="+0" || c->to_string()=="-0" || c->to_string()=="0")
        {
            string gorilla="+"+b->to_string().substr(1);
            UnlimitedInt* jerry=new UnlimitedInt(gorilla);
            UnlimitedInt* lmao=new UnlimitedInt(jerry->get_array(),jerry->get_capacity(),jerry->get_sign(),jerry->get_size());
            return lmao;
        }
        else{
            return gcd(c,b);
        }
    }
    else if((a->get_size()<b->get_size()) || ((a->get_size()==b->get_size()) && (a->to_string()<b->to_string()))){
        UnlimitedInt* c=UnlimitedInt::mod(b,a);
        if (c->to_string()=="+0" || c->to_string()=="-0" || c->to_string()=="0")
        {
            
            string gorilla="+"+a->to_string().substr(1);
            UnlimitedInt* jerry=new UnlimitedInt(gorilla);
            UnlimitedInt* lmao=new UnlimitedInt(jerry->get_array(),jerry->get_capacity(),jerry->get_sign(),jerry->get_size());
            return lmao;
        }
        else{
            return gcd(c,a);
        }
    }
    else{
        return a;
    }
    

}
UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
    // cout<<"here1"<<endl;
    if (den->to_string()=="+0" || den->to_string()=="-0" || den->to_string()=="0"){
        num = new UnlimitedInt(0);
        den = new UnlimitedInt(0);
        p=num;
        q=den;
    }
    else if(num->to_string()=="+0" || num->to_string()=="-0" || num->to_string()=="0"){
        num = new UnlimitedInt(0);
        den = new UnlimitedInt(1);
        p=num;
        q=den;
    }
    else{
        
        UnlimitedInt* r=gcd(num,den);
        
        if(r->to_string()!="+1"){
            p=UnlimitedInt::div(num,r);
            q=UnlimitedInt::div(den,r);
        }
        else{
            p=num;
            q=den;
        }
        
    }
    
}

UnlimitedRational::~UnlimitedRational(){
    delete p;
    delete q;
}
UnlimitedInt* UnlimitedRational::get_p(){
    return p;
}

UnlimitedInt* UnlimitedRational::get_q(){
    return q;
}
string UnlimitedRational::get_p_str(){
    string str=p->to_string().substr(1);
    return str;
    
}

string UnlimitedRational::get_q_str(){
    string str=q->to_string().substr(1);
    return str;
}
    
string UnlimitedRational::get_frac_str(){
    if(p->get_sign()*q->get_sign()==1){
    string str= p->to_string().substr(1) + "/" + q->to_string().substr(1);
    return str;
    }
    else{
        string str= "-"+p->to_string().substr(1) + "/" + q->to_string().substr(1);
    return str;
    }
}
UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *n1=i1->get_p();
    UnlimitedInt *d1=i1->get_q();
    UnlimitedInt *n2=i2->get_p();
    UnlimitedInt *d2=i2->get_q();
    if (i1->q->to_string()=="+0" || i1->q->to_string()=="-0" || i1->q->to_string()=="0"){
        UnlimitedInt *num = new UnlimitedInt(0);
        UnlimitedInt *den = new UnlimitedInt(0);
        UnlimitedRational* ducky=new UnlimitedRational(num,den);
        return ducky;
    }
    
    UnlimitedInt *a1=UnlimitedInt::mul(n1,d2);
    UnlimitedInt *a2=UnlimitedInt::mul(n2,d1);
    UnlimitedInt *a3=UnlimitedInt::add(a1,a2);
    UnlimitedInt *a4=UnlimitedInt::mul(d1,d2);
    // cout<<"a1 "<<a1->to_string()<<endl;
    // cout<<"a2 "<<a2->to_string()<<endl;
    // cout<<"a3 "<<a3->to_string()<<endl;
    // cout<<"a4 "<<a4->to_string()<<endl;
    UnlimitedRational* answer=new UnlimitedRational(a3,a4);
    // <<"answer "<<answer->get_frac_str()<<endl;
    return answer;

}



UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *n1=i1->get_p();
    UnlimitedInt *d1=i1->get_q();
    UnlimitedInt *n2=i2->get_p();
    UnlimitedInt *d2=i2->get_q();
    if (i1->q->to_string()=="+0" || i1->q->to_string()=="-0" || i1->q->to_string()=="0"){
        UnlimitedInt *num = new UnlimitedInt(0);
        UnlimitedInt *den = new UnlimitedInt(0);
        UnlimitedRational* ducky=new UnlimitedRational(num,den);
        return ducky;
    }
    
    UnlimitedInt *a1=UnlimitedInt::mul(n1,d2);
    UnlimitedInt *a2=UnlimitedInt::mul(n2,d1);
    UnlimitedInt *a3=UnlimitedInt::sub(a1,a2);
    UnlimitedInt *a4=UnlimitedInt::mul(d1,d2);
    UnlimitedRational* answer=new UnlimitedRational(a3,a4);
    return answer;
}
UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *n1=i1->get_p();
    UnlimitedInt *d1=i1->get_q();
    UnlimitedInt *n2=i2->get_p();
    UnlimitedInt *d2=i2->get_q();
    if (i1->q->to_string()=="+0" || i1->q->to_string()=="-0" || i1->q->to_string()=="0"){
        UnlimitedInt *num = new UnlimitedInt(0);
        UnlimitedInt *den = new UnlimitedInt(0);
        UnlimitedRational* ducky=new UnlimitedRational(num,den);
        return ducky;
    }
    
    
    UnlimitedInt *a1=UnlimitedInt::mul(n1,n2);
    UnlimitedInt *a2=UnlimitedInt::mul(d1,d2);
    UnlimitedRational* answer=new UnlimitedRational(a1,a2);
    return answer;
} 
UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *n1=i1->get_p(); 
    UnlimitedInt *d1=i1->get_q();
    UnlimitedInt *n2=i2->get_p();
    UnlimitedInt *d2=i2->get_q();
    if (i1->q->to_string()=="+0" || i1->q->to_string()=="-0" || i1->q->to_string()=="0"){
        UnlimitedInt *num = new UnlimitedInt(0);
        UnlimitedInt *den = new UnlimitedInt(0);
        UnlimitedRational* ducky=new UnlimitedRational(num,den);
        return ducky;
    }
    
    
    UnlimitedInt *a1=UnlimitedInt::mul(n1,d2);
    UnlimitedInt *a2=UnlimitedInt::mul(d1,n2);
    UnlimitedRational* answer=new UnlimitedRational(a1,a2);
    return answer;
}

    