
#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    cout<<"\n";
}
void update(vector <int>&vect){
    int a,b,index;
    cout<<"Enter index : ";
    cin>>index;
    if(index>vect.size()||index<0){
        cout<<"Invalid index\n Enter valid index\n";
    }
    else{
        vect.erase(vect.begin()+index-1);
    }
    display(vect);
    cout<<"Enter a and b : ";
    cin>>a>>b;
    if((a>vect.size()||a<0)||(b>vect.size()||b<0)){
        cout<<"Invalid index\n Enter valid index\n";
    }
    else{
        
        for(int i=a;i<b;i++){
            vect.erase(vect.begin()+a-1);
        }
    }
    // cout<<vect[index-1]<<" "<<vect[index+1]<<endl;
    // vect.erase(vect.begin()+index+1);
    // vect.erase(vect.begin()+index-1);
}
int main(){
    int n,temp;
    vector<int> vect;
    cout<<"Enter total integer  : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        vect.push_back(temp);
    }
    display(vect);
    update(vect);
    cout<<vect.size()<<endl;
    display(vect);
   


}