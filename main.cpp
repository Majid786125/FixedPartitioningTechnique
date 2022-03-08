#include <iostream>
using namespace std;
class Partition
{
public:
    int ProcessNo=0,MemoryAllocated=0,MemoryRequired=0,IntFragmentation=0;

    Partition()
    {
        ProcessNo=0;
        MemoryAllocated=0;
        MemoryRequired=0;
        IntFragmentation=0;
    }
    void init(int i,int m);
};

void Partition::init(int i,int m) {
    ProcessNo=i;
    MemoryAllocated=m;
    IntFragmentation=0;
    cout<<"\nEnter Required Memory  P["<<i<<"] : ";
    cin>>MemoryRequired;


}

Partition Print(Partition P[], int N)
{
    cout<<"Process No"<<"             "<<"Required Memory"<<"         "<<"Allocated Memory"<<"          "<<"IntFragmentation"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"     "<<P[i].ProcessNo<<"                          ";
        cout<<P[i].MemoryRequired<<"                 ";
        if(P[i].MemoryRequired<=P[i].MemoryAllocated)
        {
            cout<<P[i].MemoryAllocated<<"                              ";
            cout<<P[i].IntFragmentation;
            cout<<endl;
        }
        else
        {
            cout<<"             "<<endl;
        }
    }
    return *P;
}
Partition Calculation(Partition P[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(P[i].MemoryRequired<P[i].MemoryAllocated)
        {
            P[i].IntFragmentation=P[i].MemoryAllocated-P[i].MemoryRequired;
        }
    }
    return *P;
}
Partition Internal(Partition P[],int N,int TM,int PM,int CP)
{
    int T=0;
    for (int i = 0; i < N; ++i) {
        T=T+P[i].IntFragmentation;
    }
    int Total=CP*PM;
    Total=TM-Total;
    cout<<"Total Internal Fragmentation = "<<T<<" bytes"<<endl;
    cout<<"Total External Fragmentation = "<<Total<<" bytes"<<endl;

    return *P;
}
int main() {
    Partition *P;
    int TM=0,PS=0,TP=0,NP=0,A=0;
    cout<<"Enter Total Memory Size : ";
    cin>>TM;
    cout<<"Enter Partition Size : ";
    cin>>PS;
    cout<<"Enter Number of Process : ";
    cin>>NP;
    TP=TM/PS;
    if(NP<TP)
    {
        P=new Partition[NP];
        A=NP;
    }
    else {
        P=new Partition[NP];
        A=TP;
    }
    for(int i=0;i<A;i++)
    {
        P[i].init(i,PS);

    }
    Calculation(P,A);

    Print(P,A);
    Internal(P,A,TM,PS,TP);
    return 0;
}
