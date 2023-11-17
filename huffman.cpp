#include<bits/stdc++.h>
using namespace std;
struct minheap
{
    char data;
    int freq;
    minheap* left,*right;
    minheap(char data,int freq)
    {
        left=right=nullptr;
        this->data=data;
        this->freq=freq;
    }
};

void printcodes(minheap *root,string s)
{
    if(root==nullptr) return ;
    if(root->data !='$') cout<<root->data<<" "<<"codes:"<<s<<endl;

    printcodes(root->left,s+'0');
    printcodes(root->right,s+'1');
}

struct compare
{
   bool operator()(minheap *a,minheap *b)
   {
    return (a->freq > b->freq);
   }
};

bool isNumber(string s)
{
    for(auto i:s)
    {
        if(!isdigit(i))
        return false;
    }
    return true;
}
int main()
{
    priority_queue<minheap*,vector<minheap*>,compare>minh;

    int freq;
    char ch;
    string input;

    do 
    {
       cout<<"Enter char";
       cin>>input;
       if(input.length()==1 && isalpha(input[0]))
       {
        ch=input[0];
        break;
       }
       else
       cout<<"Enter valid char";
    }while(true);

    do
    {
       cout<<"Enter freq";
       cin>>input;
       if(isNumber(input))
       {
        freq=stoi(input);
        break;
       }
       else
       cout<<"Enter valid freq";
    } while (true);

    minh.push(new minheap(ch,freq));


    while(true)
    {
        char choice;
        cout<<"Do you want to continue(y/n)";
        cin>>choice;
        if(choice=='n')
        break;
        else if(choice !='y' && choice!='n')
        cout<<"Enter valid choice";
        else
        {
            do 
            {
               cout<<"Enter char";
               cin>>input;
               if(input.length()==1 && isalpha(input[0]))
               {
                ch=input[0];
                break;
               }
               else
               cout<<"Enter valid char";
            }while(true);

            do
            {
                cout<<"Enter freq";
                cin>>input;
                if(isNumber(input))
                {
                    freq=stoi(input);
                    break;
                }
                else
                cout<<"enter valid freq";
            } while (true);

            minh.push(new minheap(ch,freq));
            
        }
    }

    while(minh.size()!=1)
    {
        minheap* left=minh.top();
        minh.pop();
        minheap* right=minh.top();
        minh.pop();
        minheap* temp=new minheap('$', left->freq+right->freq);
        temp->left=left;
        temp->right=right;
        minh.push(temp);
    }

    printcodes(minh.top()," ");
    
}