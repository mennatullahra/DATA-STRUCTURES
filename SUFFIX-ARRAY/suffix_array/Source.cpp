#include <iomanip>
#include <iostream>

using namespace std;
class element
{
public:

  char  str[50];
  int group;
  int index;

element (){
    for(int i=0;i<50;i++){
    str[i]='\0';
    }
}

bool equal(element second,int iteration){

    int base=2;

    if(iteration==0)
        base=1;

    for(int i=0;i<iteration-1;i++)
        base*=base;

    for(int i=0;i<base;i++){
        if(this->str[i]!=second.str[i])
            return false;
    }
    return true;
    }
};

void compare(element &first,element &second, int iteration){
    int base=2;

    if(iteration==0)
        base=1;

    if(first.group==second.group){
        for(int i=0;i<iteration-1;i++){
            base*=base;
            }
        for(int i=iteration;i<base;i++){//rearrange suffix array after shifting
            if(first.str[i]>second.str[i]){
                element temp=first;
                first=second;
                second=temp;
                break;
                }
            }
        }
    }

class SuffixArray
{
    element *arr;
    int size;

    public:

    SuffixArray(char chars[]){

    size=0;
    while(chars[size]!='\0'){
        size++;
        }

    arr = new element[size];

    for(int i=0;i<size;i++){
        element temp;
        int k=0;
        for(int j=i;j<size;j++){
            temp.str[k++]=chars[j];

            }
        temp.index=i;
        this->arr[i]=temp;
        }
}

void iterationRun(int k){
    bool in =false;
    for(int j=0;j<size-1;j++){

        for(int i=0;i<size-1;i++){

            compare(arr[i],arr[i+1],k);
        }
    }

    arr[0].group=1;
    for(int i=1;i<size;i++){

        if(arr[i].equal(arr[i-1],k)){
        arr[i].group=arr[i-1].group;
        }
    else{
        arr[i].group=arr[i-1].group+1;
        }
    }

    for(int i=0;i<size-1;i++){
    if(arr[i].group==arr[i+1].group){
            in=true;
            }
        }
    if(in)
        iterationRun(k+1);
}


void ConstructUsingPrefixDoubling(){
    iterationRun(0);
}

void Print(){
    for(int i=0;i<size;i++){
        cout << left << setw(5) << i;
        }
    cout<<"\n";
    for(int i=0;i<size;i++){
         cout << left << setw(5) << arr[i].index;
        }
}
};