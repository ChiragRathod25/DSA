#include<bits/stdc++.h>
using namespace std;

class cargo{
    private:
        float value;
        float weight;
        float vw;
    public:
    cargo(){
        value=0;
        weight=0;
        vw=0;
    }
    cargo(int val,int weight){
        this->value=val;
        this->weight=weight;
        this->vw=this->value/this->weight;
    }
        void setValueWeight(int value,int weight){
            this->value=value;
            this->weight=weight;
            this->vw=this->value/this->weight;
        }
        int getValue(){
            return value;
        }
        int getWeight(){
            return weight;
        }
        int getRatio(){
            return vw;
        }
        void display(){
            cout<<this->value<<" "<<this->weight<<" "<<this->vw<<endl;
        }
};

int main(){
    int n;
    cin>>n;
    vector<cargo> c;
    float val,weight;

    for(int i=0;i<n;i++){
        cin>>val>>weight;
        c.push_back(new cargo(val,weight));
    }

    sort(c.begin(),c.end(),[](cargo &a,cargo &b){
        return a.getRatio()<b.getRatio();
    });
    
    for(int i=0;i<n;i++){
        c[i].display();
    }

    

    return 0;
}

