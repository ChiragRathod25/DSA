#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}
void update(vector<int>&vect){
    int a,b,index;
    cout<<"Enter index to delete : ";
    cin>>index;
    if(index>vect.size()||index<0){
        cout<<"Invalid Index.\n Enter Valid index\n";
    }
    else{
        vect.erase(vect.begin()+index-1);
    }
    display(vect);
    cout<<"Enter a & b :";
    cin>>a>>b;
    if(a>vect.size()||a<0||b>vect.size()||b<0){
        cout<<"Invalid value of a and b.\n";
    }
    else{ 
        for(int i=a;i<b;i++){
            vect.erase(vect.begin()+a-1);
        }
    }
}
int main(void){
    int n,temp;
    vector<int> vect;
    cout<<"Enter total Integer : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        vect.push_back(temp);
    }
    display(vect);
    update(vect);
    display(vect);
    return 0;
}