/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"

UnlimitedInt::~UnlimitedInt(){

    delete[] unlimited_int;
}
UnlimitedInt::UnlimitedInt(){
    size=0;
    sign=1;
    capacity=1;
    unlimited_int=new int[capacity];
    unlimited_int[0]=0;
}
UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
    unlimited_int=ulimited_int;
    capacity=cap;
    sign=sgn;
    size=sz;
}
//d
UnlimitedInt::UnlimitedInt(std::string s) {
    if (s[0] == '+') {
        size = s.size() - 1;
        sign = 1;
    } else if (s[0] == '-') {
        size = s.size() - 1;
        sign = -1;
    }
    capacity = 1;
    while (capacity < size) {
        capacity = capacity * 2;
    }
    unlimited_int = new int[capacity];

    for (int i = size - 1; i >= 0; i--) {
        unlimited_int[size - i - 1] = s[i + 1] - '0';
    }
    for (int i = size; i < capacity; i++) {
        unlimited_int[i] = 0;
    }
}
int UnlimitedInt::get_capacity(){
    return capacity;
}
//d
UnlimitedInt::UnlimitedInt(int i) {
    size = 0;
    int k = i;
        if(i==0){
            size=1;
        }
            if (k < 0) {
            k = -k;
        }

        if (i >= 0) {
            sign = 1;
        } else if (i < 0) {
            sign = -1;
        }
        
        int j = i;
        if (j < 0) {
            j = -j;
        }
        while (j > 0) {
            j = j / 10;
            size++;
        }
        
        capacity = 1;
        while (capacity < size) {
            capacity = capacity * 2;
        }
        
        unlimited_int = new int[capacity];
        for (int idx = 0; idx < size; idx++) {
            int a = k % 10;
            unlimited_int[idx] = a;
            k = k / 10;
        }
        for (int idx = size; idx < capacity; idx++) {
            unlimited_int[idx] = 0;
        }
    
}

//d
int UnlimitedInt::get_size(){
    
    return size;
}
//d
int* UnlimitedInt::get_array(){
    return unlimited_int;
}
//d
int UnlimitedInt::get_sign(){
    return sign;
}
//d
string UnlimitedInt::to_string() {
    string ans = "";
    if (sign == 1) {
        ans = ans + '+';
    }
    if (sign == -1) {
        ans = ans + '-';
    }
    for (int i = size - 1; i >= 0; i--) {
        char b = char('0' + unlimited_int[i]);
        ans = ans + b;
    }
    return ans;
}








UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
    int s1=i1->get_size();
    int s2=i2->get_size();
    int sign1=i1->get_sign();
    int sign2=i2->get_sign();
    int* array1=i1->get_array();
    int* array2=i2->get_array();
    string initial="";
    int s3;
    int sign3;
    int s4;
    if(s1>s2 || (s1==s2 && ((i1->to_string().substr(1))>=(i2->to_string().substr(1))))){
        
        s4=s2;
        s3=s1+1;
        sign3=sign1;
        if(sign3>0){
            initial=initial+"+";
        }
        else if(sign3<0){
            initial=initial+"-";
        }
        for(int i=0;i<=s1;i++){
            initial=initial+"0";
        }
    }
    if(s2>s1 || (s1==s2 && ((i1->to_string().substr(1))<(i2->to_string().substr(1))))){
        initial="";
        s4=s1;
        s3=s2+1;
        sign3=sign2;
        if(sign3>0){
            initial=initial+"+";
        }
        else if(sign3<0){
            initial=initial+"-";
        }
        for(int i=0;i<=s2;i++){
            initial=initial+"0";
        }
        
    }
    
    int cap4;
    UnlimitedInt* i3=new UnlimitedInt(initial);
    int* array3=i3->get_array();
    int* array4;
  
    if(sign1*sign2==1){
        int carry=0;
        int ans;
        /////////////////////////////////////
        for(int i=0;i<s4;i++){
            ans=(array1[i]+array2[i]+carry)%10;
            array3[i]=ans;
            carry=int(array1[i]+array2[i]+carry)/10;

        }
        ///////////////////////////////////////
        if(s4==s2){
        for(int i=s4;i<s3-1;i++){
            ans=(array1[i]+carry)%10;
            array3[i]=ans;
            carry=int(array1[i]+carry)/10;
        }
        }
        /////////////////////////////////////
        if(s4==s1){
            for(int i=s4;i<s3-1;i++){
            ans=(array2[i]+carry)%10;
            array3[i]=ans;
            carry=int(array2[i]+carry)/10;
        }
        }
        ///////////////////////////////////////
        
        array3[s3-1]=carry;
        if(carry==0){
            s3=s3-1;
        }
        cap4=1;
        while(cap4<s3){
            cap4=cap4*2;
        }
        int *array4=new int[cap4];
        for(int i=0;i<s3;i++){
            array4[i]=array3[i];
        }
        for(int i=s3;i<cap4;i++){
            array4[i]=0;
        }
        UnlimitedInt* anss=new UnlimitedInt(array4,cap4,sign3,s3);
    return anss;
        
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////
    else{
        if((i1->to_string().substr(1))==(i2->to_string().substr(1))){
            return new UnlimitedInt(0);
        }
        if(s1>s2 || (s1==s2 && ((i1->to_string().substr(1))>=(i2->to_string().substr(1))))){
            s3--;
            int ans;
            int borrow=0;
            for(int i=0;i<s4;i++){
                
                ans=(array1[i]-array2[i]-borrow);
                borrow=0;
                
                
                
                if(ans<0){
                    ans=ans+10;
                    borrow=1;
                }
                
                array3[i]=ans;
                // carry=int(array1[i]+array2[i]+carry)/10;

            }
            for(int i=s4;i<s3;i++){
                ans=(array1[i]-borrow);
                
                if(ans<0){
                    ans=ans+10;
                    borrow=1;
                }
                
                array3[i]=ans;
            }
            // array3[s3-1]=carry;
        }
        if(s2>s1 || (s1==s2 && ((i1->to_string().substr(1))<(i2->to_string().substr(1))))){
            s3--;
            int ans;
            int borrow=0;
            for(int i=0;i<s4;i++){
                
                ans=(array2[i]-array1[i]-borrow);
                
                if(ans<0){
                    ans=ans+10;
                    borrow=1;
                }
                
                array3[i]=ans;
                // carry=int(array1[i]+array2[i]+carry)/10;

            }
            for(int i=s4;i<s3;i++){
                ans=(array2[i]-borrow);
                
                if(ans<0){
                    ans=ans+10;
                    borrow=1;
                }
                
                array3[i]=ans;
            }
            // array3[s3-1]=carry;
        }

        if(array3[s3-1]==0){
            int g=s3-1;
            while(array3[g]==0){
                g--;
                s3--;
            }
        }
        int* array4;
        cap4=1;
        while(cap4<s3){
            cap4=cap4*2;
        }
        array4=new int[cap4];
        for(int i=0;i<s3;i++){
            array4[i]=array3[i];
        }
        for(int i=s3;i<cap4;i++){
            array4[i]=0;
        }
        
        UnlimitedInt* anss=new UnlimitedInt(array4,cap4,sign3,s3);
    return anss;
        
    }
    ///////////////////////////////////////////////////////////////////////////////////
    

}

UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
    int s1=i1->get_size();
    int s2=i2->get_size();
    int sign1=i1->get_sign();
    int sign2=i2->get_sign();
    int* array1=i1->get_array();
    int* array2=i2->get_array();
    int s3;
    int sign3;
    sign3=sign1*sign2;
    s3=s1+s2;
    string initial="";
    if(sign3==1){
        initial=initial+"+";
    }
    if(sign3==-1){
        initial=initial+"-";
    }
    
    for(int i=0;i<s1+1;i++){
        initial=initial+"0";
    }
    UnlimitedInt* i3=new UnlimitedInt(initial);
    UnlimitedInt* answerr=new UnlimitedInt("+0");
    UnlimitedInt* ten=new UnlimitedInt(10);
    int* array3=i3->get_array();
    int carry;
    int a;
    int b;
    for(int j=0;j<s2;j++){
        a=array2[j];
        carry=0;
        for(int i=0;i<s1;i++){
            
            array3[i]=(array1[i]*a)+carry;
            carry=array3[i]/10;
            array3[i]=array3[i]%10;
            
            
        }
        array3[s1]=carry;
        
        int sz=s1+1;
        if(carry==0){
            sz--;
        }
        int cap=1;
        while(cap<sz){
            cap=cap*2;
        }
        int *array4=new int[cap];
        for(int i=0;i<sz;i++){
            array4[i]=array3[i];
            
        }
        for(int i=sz;i<cap;i++){
            array4[i]=0;
        }

        UnlimitedInt* i7=new UnlimitedInt(array4,cap,1,sz);
        string stri7=i7->to_string();
        
        
        for(int k=0;k<j;k++){
            stri7=stri7+"0";
            
        }
        
        UnlimitedInt* i8=new UnlimitedInt(stri7);
        answerr=add(answerr,i8);
        
    }
    
    
    // int* array4;
    //     int cap4;
    //     cap4=1;
    //     while(cap4<s3){
    //         cap4=cap4*2;
    //     }
    //     array4=new int[cap4];
    //     for(int i=0;i<s3;i++){
    //         array4[i]=array3[i];
    //     }
    //     for(int i=s3;i<cap4;i++){
    //         array4[i]=0;
    //     }
        
    
    // UnlimitedInt* ansss=new UnlimitedInt(array4, cap4,sign3 , s3);
    if(sign3==1){
        return answerr;
    }
    else{
        UnlimitedInt* i69=new UnlimitedInt("-"+answerr->to_string().substr(1));
        return i69;
    }




}

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){
    
    int s2=i2->get_size();
    int cap4=1;
    while(cap4<s2){
        cap4=cap4*2;
    }
    
    int sign2=i2->get_sign();
    sign2=sign2*-1;
    int* array2=i2->get_array();
    UnlimitedInt* i3=new UnlimitedInt(array2,cap4,sign2,s2);

    UnlimitedInt* bb=add(i1,i3);
    return bb;

}
// UnlimitedInt* UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2){
    // UnlimitedInt *i3=new UnlimitedInt(1);
    // UnlimitedInt *i4=new UnlimitedInt(1);
    
    // while(i1->get_size()>i2->get_size()){
    //     i1=sub(i1,i2);
    //     i4=add(i4,i3);
    // }
    // int* array1=i1->get_array();
    // int* array2=i2->get_array();
    // while(i1->get_size()==i2->get_size() && array1[i1->get_size() -1]>array2[i1->get_size() -1]){
    //     i1=sub(i1,i2);
    //     i4=add(i4,i3);
    //     array1=i1->get_array();
    // }
    // return i4;
// UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2)
// {
//     string s1 = i1->to_string();
//     string s2 = i2->to_string();
//     int size1 = i1->get_size();
//     int size2 = i2->get_size();
//     int sign1 = i1->get_sign();
//     int sign2 = i2->get_sign();
//     UnlimitedInt *start = new UnlimitedInt(1);
//     UnlimitedInt *mid = new UnlimitedInt((add(i1, start)->to_string().substr(1)));
//     UnlimitedInt *end = i1;
//     while (sub(mid, start)->to_string().substr(1) != "1" || sub(mid, start)->to_string().substr(1) != "0")
//     {
//         if (is_equal(mul(mid, i2)->to_string().substr(1), i1->to_string().substr(1)) || sub(mid, start)->to_string().substr(1) == "1" || sub(mid, end)->to_string().substr(1) == "1")
//         {
//             cout << mid->to_string() << endl;
//             return mid;
//         }
//         else if (find_greater(mul(mid, i2)->to_string().substr(1), i1->to_string().substr(1)) == 1)
//         {
//             end = mid;
//             mid = new UnlimitedInt((add(start, mid)->to_string().substr(1)));
//             cout << mid->to_string() << endl;
//         }
//         else
//         {
//             start = mid;
//             mid = new UnlimitedInt((add(end, mid)->to_string().substr(1)));
//             cout << mid->to_string() << endl;
//         }
//     }
//     if (mid == start)
//     {
//         return mid;
//     }
// }
string half(string s) {
    string resp = "";
    int num = 0;
    int jjj = 0;

    while (jjj <= s.size() - 1) {
        int temp = ((s[jjj] - '0') + num * 10);
        int t1 = temp / 2;
        num = temp % 2;
        resp = resp + char('0'+ t1);
        jjj++;
    }

    int ki = 0;
    while (ki < resp.size() && resp[ki] == '0') {
        ki++;
    }
    if (ki > 0) {
        resp = resp.substr(ki);
    }

    return resp;
}

UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2){
    UnlimitedInt* one=new UnlimitedInt(1);
    UnlimitedInt* zero=new UnlimitedInt("+0");
    int sign3=i1->get_sign()*i2->get_sign();
    if(i1->get_sign()==-1){
        i1=new UnlimitedInt("+"+i1->to_string().substr(1));
    }
    if(i2->get_sign()==-1){
        i2=new UnlimitedInt("+"+i2->to_string().substr(1));
    }
    UnlimitedInt* mid;
    UnlimitedInt* start;
    UnlimitedInt* end;
    end=i1;
    start=one;
    // mid=new UnlimitedInt(1)
    mid=add(end,start);
    mid=new UnlimitedInt("+"+half(mid->to_string().substr(1)));
    
    while(mid->to_string()!=start->to_string()){
        if(((mul(i2,mid)->get_size()==i1->get_size()) && (mul(i2,mid)->to_string()==i1->to_string())) || (mid->to_string()==start->to_string())){
            break;
        }
        else if((mul(i2,mid)->get_size()<i1->get_size()) || ((mul(i2,mid)->get_size()==i1->get_size()) && (mul(i2,mid)->to_string().substr(1)<i1->to_string().substr(1)))){
            start=mid;
            mid=add(end,start);
            // mid=new UnlimitedInt("+"+half(mid->to_string().substr(1)));
            string gorilla="+"+half(mid->to_string().substr(1));
            UnlimitedInt* jerry=new UnlimitedInt(gorilla);
            
            mid=new UnlimitedInt(jerry->get_array(),jerry->get_capacity(),jerry->get_sign(),jerry->get_size());
            
        }
        else if((mul(i2,mid)->get_size()>i1->get_size()) || ((mul(i2,mid)->get_size()==i1->get_size()) && (mul(i2,mid)->to_string().substr(1)>i1->to_string().substr(1) ))){
            end=mid;
            mid=add(end,start);
            string gorilla="+"+half(mid->to_string().substr(1));
            UnlimitedInt* jerry=new UnlimitedInt(gorilla);
            
            mid=new UnlimitedInt(jerry->get_array(),jerry->get_capacity(),jerry->get_sign(),jerry->get_size());
            
        }   

    }
    if (sign3==1){
        return mid;
    }
    else{
        mid=new UnlimitedInt("-"+mid->to_string().substr(1));
        return mid;
    }
    
    
}


UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){
    if(i1->get_sign()==-1){
        i1=new UnlimitedInt("+"+i1->to_string().substr(1));
    }
    if(i2->get_sign()==-1){
        i2=new UnlimitedInt("+"+i2->to_string().substr(1));
    }
    

    UnlimitedInt* quo=div(i1,i2);
    
    UnlimitedInt* rem;
    
    //rem+qua*i2 =i1
    UnlimitedInt* temp=mul(i2,quo);
    
    rem=sub(i1,temp);
    
    if(rem->to_string()==i2->to_string()){
        
        UnlimitedInt* a=new UnlimitedInt(0);
        return a;
    }
    else{
        return rem;
    }
    

}

