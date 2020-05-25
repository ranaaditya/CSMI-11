/* 
*@author Aditya Rana 
*@url https://github.com/ranaaditya
*/


    #include<bits/stdc++.h>

    using namespace std;

    int integer_knapsack(int n, int M, int w[], int p[])

    {
        int i,j;
        
        int tempValue;
        
        int knapsack[M+1];

        knapsack[0]=0;

        for(i=1;i<=M;i++)

        {
            knapsack[i]=knapsack[i-1];

            for(j=0;j<n;j++)

            {
                if(i>=w[j])
                {
                    tempValue=p[j]+knapsack[i-w[j]];

                    if(tempValue>knapsack[i])

                    {

                        knapsack[i]=tempValue;

                    }

                }

            }

        }

        return knapsack[M];

    }

     

    int main()

    {

        int i;

        int n;  //number of items

        int M;  //capacity of knapsack

     

        cout<<"Enter the no. of items ";

        cin>>n;

     

        int w[n];  //weight of items

        int p[n];  //value of items

     

        cout<<"Enter the weight and price of all items \n eg. 5 6 represents 5 -> weight and 6 -> price of this item\n"<<endl;

        for(i=0;i<n;i++)
        {
            cin>>w[i]>>p[i];
        }
        
        cout<<"enter the capacity of knapsack  ";

        cin>>M;

        int result=integer_knapsack(n,M,w,p);

        cout<<"The maximum value of items that can be put into knapsack is "<<result;

        cout<<endl;

        return 0;

    }