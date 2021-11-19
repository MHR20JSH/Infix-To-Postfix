#include <iostream>
#include <stack>
#include <list>
#include <array>

using namespace std;

    
    //string finished[1000];
    //int j=0;
    //int i=0;

    struct Power{
       int power1;
       char num;
    };
   stack <Power> operation;
   stack <Power> operation2;
   
   
   string* addBractes(string inter,int &o){
       string finished[200];
       int j=0;
       int i=0;
       o=0;
       for( int k=0;k<inter.length();k++)
      {
                switch(inter[k])
                {
                case '(':
                    
                i++;
              string a[100];
              int n=0;
              
             for (int f = i; inter[f]!=')'; f++) {
                        
                       a[n]=inter[f];
                          n++;     
                          i++;
                  }
              i++;
                 
                 addBractes(a);
                    break;
                    
                    
                case ')':
                    return;
                    break;
                    
                    
                case '*':
                    Power njmah;
                    njmah.num='*';
                    njmah.power1=3;
                     if(operation2.empty())
                        operation2.push(njmah);
                    else{

                           Power Top;
                           Top=operation2.top();
                           
                           if( njmah.power1>Top.power1)
                                operation2.push(njmah);
                            else
                            {
                               for (int s = 0; !operation2.empty(); s++) {
                                   Top=operation2.top();
                                   finished[j]=Top.num;
                                   o++;
                                   j++;
                                   operation2.pop();
                                }

                              

                            }

                    }
                    break;
                case '/':
                    Power kusmah;
                    kusmah.num='/';
                    kusmah.power1=2;
                     if(operation2.empty())
                        operation2.push(kusmah);
                    else{

                           Power Top;
                           Top=operation2.top();
                           if( kusmah.power1>Top.power1)
                                operation2.push(kusmah);
                            else
                            {
                               for (int s = 0; !operation2.empty(); s++) {
                                   Top=operation2.top();
                                   finished[j]=Top.num;
                                   o++;
                                   j++;
                                   operation2.pop();
                               }
                                operation2.push(kusmah);

                            }

                    }
                    break;
                case '+':
                    Power sum;
                    sum.num='+';
                    sum.power1=1;
                     if(operation2.empty())
                        operation2.push(sum);
                    else{

                           Power Top;
                           Top=operation2.top();
                           if( sum.power1>Top.power1)
                                operation2.push(sum);
                            else
                            {
                               for (int s = 0; !(operation2.empty()); s++) {
                                   Top=operation2.top();
                                   finished[j]=Top.num;
                                   o++;
                                   j++;
                                   operation2.pop();
                               }
                               operation2.push(sum);

                            }

                    }
                    break;
                case '-':
                    Power minus;
                    minus.num='-';
                    minus.power1=0;
                     if(operation2.empty())
                        operation2.push(minus);
                    else{

                           Power Top;
                           Top=operation2.top();
                           if( minus.power1>Top.power1)
                                operation2.push(minus);
                            else
                            {
                               for (int s = 0;!operation2.empty(); s++) {
                                   Top=operation2.top();
                                   finished[j]=Top.num;
                                   o++;
                                   j++;
                                   operation2.pop();
                               }
                                operation2.push(minus);

                            }

                    }
                    break;
                default :
                    finished[j]=inter[k];
                    o++;
                    j++;
                    break;

                }
            }
       for (int r = 0; !(operation2.empty()); r++) {
        
           finished[j]=operation2.top().num;
           o++;
           j++;
           operation2.pop();
           
    }
       return finished;
      
   }
  string* infix_to_Postfix(string inter){
      
      string finished[200];
      int j=0;
      int i=0;
      int p;
      string* my[200];

       for(int i=0;i<inter.length();i++)
      {
                switch(inter[i])
                {
                case '(':
                    
              i++;
              string a[100];
              int n=0;
              
             for (int f = i; inter[f]!=')'; f++) {
                        
                       a[n]=inter[f];
                          n++;     
                          i++;
                  }
              i++;
                 
                 
                 my=addBractes(a,p);
                    break;
                    
                    
                case '*':
                    Power njmah;
                    njmah.num='*';
                    njmah.power1=3;
                     if(operation.empty())
                        operation.push(njmah);
                    else{

                           Power Top;
                           Top=operation.top();
                           
                           if( njmah.power1>Top.power1)
                                operation.push(njmah);
                            else
                            {
                               for (int s = 0; !operation.empty(); s++) {
                                   Top=operation.top();
                                   finished[j]=Top.num;
                                   j++;
                                   operation.pop();
                                }

                              

                            }

                    }
                    break;
                case '/':
                    Power kusmah;
                    kusmah.num='/';
                    kusmah.power1=2;
                     if(operation.empty())
                        operation.push(kusmah);
                    else{

                           Power Top;
                           Top=operation.top();
                           if( kusmah.power1>Top.power1)
                                operation.push(kusmah);
                            else
                            {
                               for (int s = 0; !operation.empty(); s++) {
                                   Top=operation.top();
                                   finished[j]=Top.num;
                                   j++;
                                   operation.pop();
                               }
                                operation.push(kusmah);

                            }

                    }
                    break;
                case '+':
                    Power sum;
                    sum.num='+';
                    sum.power1=1;
                     if(operation.empty())
                        operation.push(sum);
                    else{

                           Power Top;
                           Top=operation.top();
                           if( sum.power1>Top.power1)
                                operation.push(sum);
                            else
                            {
                               for (int s = 0; !(operation.empty()); s++) {
                                   Top=operation.top();
                                   finished[j]=Top.num;
                                   j++;
                                   operation.pop();
                               }
                               operation.push(sum);

                            }

                    }
                    break;
                case '-':
                    Power minus;
                    minus.num='-';
                    minus.power1=0;
                     if(operation.empty())
                        operation.push(minus);
                    else{

                           Power Top;
                           Top=operation.top();
                           if( minus.power1>Top.power1)
                                operation.push(minus);
                            else
                            {
                               for (int s = 0;!operation.empty(); s++) {
                                   Top=operation.top();
                                   finished[j]=Top.num;
                                   j++;
                                   operation.pop();
                               }
                                operation.push(minus);

                            }

                    }
                    break;
                default :
                    finished[j]=inter[i];
                    j++;
                    break;

                }
            }
       for (int r = 0; !(operation.empty()); r++) {
        
           finished[j]=operation.top().num;
           j++;
           operation.pop();
           
    }
      // my=addBractes(a);
      for (int i = 0; i < p; i++) {
          finished[j]=my[i];
          j++;

    }

           return finished;
      }

int main()
{
    string inter;
    cout<<"please inter string"<<endl;
    cin>>inter;
    cout<<"________________________"<<endl;
    string* a=infix_to_Postfix(inter);
    for (int i = 0; i < 10; i++) {
        
        cout<<*(a+i);

    }



}
