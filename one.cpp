#include <iostream>
using namespace std;

class student
{
  protected:
  int rn;
  float sgpa;
  string name;

  public:
  void setData(int rn,double sgpa,string name)
  {
    this->rn = rn;
    this->sgpa = sgpa;
    this->name = name;
  }
  void getData()
  {
    cout<<"Roll number: "<<rn<<endl;
    cout<<"SGPA: "<<sgpa<<endl;
    cout<<"Name: "<<name<<endl;
  }
  //Insertion sort
  friend void Insert_Sort(student s[],int n);
  //Shell sort
  friend void Shell_Sort(student s[],int n);
  //Radix sort
  friend int getMax(student s[],int n);
  friend void countSort(student s[],int n,int exp);
};

//-------------------------------------------------------------------------------
void Insert_Sort(student s[],int n)
{
  for(int i=1;i<n;i++)
  {
    student key = s[i];
    int j=i-1;
    while(j>=0 && s[j].rn>key.rn){
      s[j+1]=s[j];
      j--;
    }
    s[j+1] = key;
  }
}

//----------------------------------------------------------------------------------
void Shell_Sort(student s[],int n)
{
  for(int k=n/2;k>=1;k/=2)
  {
    for(int i=k;i<n;i++)
    {
      student key = s[i];
      int j=i;
      while(j>=k && (s[j-k].name.compare(key.name) > 0)?true:false)
      {
        s[j]=s[j-k];
        j-=k;
      }
      s[j] = key;
    }
  }
}
//----------------------------------------------------------------------------------------
int getMax(student s[],int n)
{
  int m = s[0].sgpa*100;
  for(int i=1;i<n;i++)
  {
    if(s[i].sgpa>m)
      m=s[i].sgpa*100;
  }
  return(m);
}
void countSort(student s[],int n,int exp)
{
  int count[10]={0};
  student out_p[n];

  for(int i=0;i<n;++i)
  {
    int digit=((int)(100*s[i].sgpa)/exp)%10;
    count[digit]++;
  }

  for(int i=1;i<10;++i)
  {
    count[i]+=count[i-1];
  }

  for(int i=n-1;i>=0;--i)
  {
    int digit=((int)(100*s[i].sgpa)/exp)%10;
    out_p[--count[digit]] = s[i];
  }

  for (int i = 0; i < n; i++)
    s[i] = out_p[i];
}

void radix_Sort(student s[],int n)
{
  int max = getMax(s,n);
  for(int j=1;max/j!=0;j*=10)
  {
    countSort(s,n,j);
  }
}

//------------------------------------------------------------------------------------

void output(student s[],int n)
{
  for(int i=0;i<n;i++)
  {
    s[i].getData();
  }
}
int main() 
{
    int n = 8;
    student s[n];

    s[0].setData(5,7.8,"Kunal");
    s[1].setData(6,3.6,"Arnav");
    s[2].setData(2,6.9,"Shinchan");
    s[3].setData(9,5.2,"Aarnav");
    s[4].setData(1,1.8,"Doremon");
    s[5].setData(3,9.9,"Lorem");
    s[6].setData(4,3.1,"Ipsum");
    s[7].setData(7,4.9,"Harsh");

    cout<<"\nStudents: \n";    
    output(s,n);

    cout<<"\nInsertion sorted (Roll. no): \n";
    Insert_Sort(s,n);
    output(s,n);

    cout<<"\nShell sorted (Names): \n";    
    Shell_Sort(s,n);
    output(s,n);
    
    cout<<"\nRadix sorted (GPA): \n";    
    radix_Sort(s,n);
    output(s,n);
}

