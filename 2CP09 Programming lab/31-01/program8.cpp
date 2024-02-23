#include<iostream>
#include<vector>
using namespace std;


void display(vector<float> vect1,vector<float> vect2){
    for(int i=0;i<vect1.size();i++){
        cout<<vect1[i]<<" "<<vect2[i]<<" "<<vect1[i]/vect2[i]<<endl;
    }
    cout<<"\n";

}
int main(){
    int n;
    float temp;
    vector<float> value;
    vector<float> weight;
    cout<<"Enter total Object : ";
    cin>>n;
    cout<<"Enter values and Weight : ";
    for(int i=0;i<n;i++){
        cin>>temp;
        value.push_back(temp);
        cin>>temp;
        weight.push_back(temp);
    }
    cout<<"Before Sorting "<<endl;
    display(value,weight);


    //sorting objects based on value/weight ratio
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((value[i]/weight[i])<(value[j]/weight[j])){
                float temp=value[i];
                value[i]=value[j];
                value[j]=temp;
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
            }
        }
    }
    cout<<"After Sorting : "<<endl;
    display(value,weight);
    return 0;
}