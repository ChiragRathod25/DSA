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

    cout<<vect[index-1]<<" "<<vect[index+1]<<endl;
    vect.erase(vect.begin()+index+1);
    vect.erase(vect.begin()+index);
    vect.erase(vect.begin()+index-1);
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
    display(vect);
   


}