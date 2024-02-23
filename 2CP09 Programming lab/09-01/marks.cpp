
// copy one file to another file
// filename as a command line argument
// binary file as a ASCII file
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Enter command line argument";
        exit(0);
    }
    ofstream out;
    out.open(argv[1]);
    ifstream in;
    in.open(argv[1]);
    
    int t_sub;
    int temp;
    cout<<"Enter total Subject : ";
    cin>>t_sub;
    for(int i=0;i<t_sub;i++){
        cin>>temp;
        out<<temp<<endl;
    }
    int i=0;
    int a[t_sub];
    while (i<t_sub)
    {
        in>>a[i];
        i++;
    }

    for(int i=0;i<t_sub;i++){
        cout<<a[i]<<endl;
    }

   // mean
    int total=0;
    for(int i=0;i<t_sub;i++){
        total+=a[i];
    }
    cout<<total<<endl;
    float mean=total/(float)t_sub;
    cout<<"Mean Value : "<<mean<<endl;


    //Median
    cout<<"Median : ";
    if(t_sub%2==0){
        int index=((a[(t_sub/2)-1]+a[(((t_sub/2))+1)-1])/2);
        cout<<index<<endl;
    }
    else{
        int index=a[((t_sub+1)/2)-1];

        cout<<index<<endl;
    }

    //Varience
    float std=0;
    for(int i=0;i<t_sub;i++){
        std=std+((a[i]-mean)*(a[i]-mean));
    }
    float variance=(float)std-t_sub;
    cout<<"Variance : "<<variance<<endl;
    return 0;
}

//marks find mean and variance 