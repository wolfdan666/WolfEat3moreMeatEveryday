for(int i=0;i<n;i++){
        int k = s[i] - 'a' + 1;
        int kp=0,kpp=0;
        if(i==0){
            if(k==1){ end = 1/3.0;}
            else if(k==2){ be = 1/3.0; end = 2/3.0;}
            else be = 2/3.0;
            p = 1/3.0;
        }
        else if(i==1){
            kp = s[i-1] - 'a' + 1;
            if(k==1){
                p *= table[kp][k][0];
                end = be + p;
            }
            else if(k==2){
                p *= table[kp][k][0];
                be += table[kp][k-1][0];
                end = be + p;
            }
            else{
                p *= table[kp][k][0];
                be = end - p;
            }
        }
        else{
            kp = s[i-1] - 'a' + 1;
            kpp = s[i-2] - 'a' + 1;
            if(k==1){
                p *= table[kpp][kp][k];
                end = be + p;
            }
            else if(k==2){
                // p *= table[kpp][kp][k];
                // be += table[kpp][kp][k-1];// 这里有bug
                // end = be + p;
                be += p*table[kpp][kp][k-1];// 原来的长度*第一段
                p *= table[kpp][kp][k];
                end = be + p;
            }
            else{
                p *= table[kpp][kp][k];
                be = end - p;
            }
        }
        // cout<<"p监控:"<<p<<endl;
        // cout<<"be:  "<<be<<endl;
        // cout<<"end: "<<end<<endl;
    }
    l = ceil(log(1/p)/log(2));
    cout<<"be:"<<be<<"end:"<<end<<endl;
    double tp = 0.01*be + 0.99*end;
    int tp2;
    ans.resize(0);
    for(int i=0;i<l;i++){
        tp *= 2;
        tp2 = (int)tp;
        tp -= tp2;
        ans += char(tp2+'0');
    }
    cout<<"编码长度为: "<<l<<endl;
    cout<<"编码结果为: "<<ans<<endl;
}