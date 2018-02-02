
#include<iostream>
using namespace std;

class stack{
    int arr[10000];
public:
    stack(){
        for(int i=0;i<10000;i++){
            arr[i]=INT32_MAX;
        }
    }
    void push(int d){
        if(arr[10000]==INT32_MAX){
            arr[10000]=d;
        }
        else{
            int f;
            for(f=0;arr[f]==INT32_MAX;f++){}
            arr[(f-1)]=d;
        }
    }
    void pop(){
        if(arr[10000]==INT32_MAX){
            cout<<"Nothing in stack to pop.\n";
        }
        else{
            int f;
            for( f=0;arr[f]==INT32_MAX;f++){}
            arr[f]=INT32_MAX;
        }
    }
    void show(){
        if(arr[10000]==INT32_MAX){
            cout<<"Nothing in stack to show.\n";
        }
        else{
            int f;
            for( f=0;arr[f]==INT32_MAX;f++){}
            while(f<10000){
                cout<<arr[f]<<"->";
                f++;
            }
            cout<<"null";
        }
    }
};


int main(){
 stack s;
    int choice;
    int x;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tStack USING ARRAY\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY Stack\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.show();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}

