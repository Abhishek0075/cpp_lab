#include<iostream>
using namespace std;
class Mat
{
    private:
    int **a;
    int r,c;
    public:
    Mat(){}
    Mat(int x,int y)
    {
        r = x;
        c = y;
        if((r>0)&&(c>0))
        {
            a = new int *[r];
            for (int i=0; i<r; i++)
            {
                a[i]= new int [c];
            }
        }
    }
    ~Mat()
    {
        for (int i=0; i<r; i++)
            delete [] a[i];
        delete [] a;
    }
    void matrix_add(Mat a, Mat b);
    void matrix_transpose(void);
    void matrix_mult(Mat a, Mat b);
    void accept_elements(void);
    int matrix_trace(void);
};
void Mat::matrix_add(Mat x, Mat y)
{ 
    int sum [x.r][x.c];
   for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            sum[i][j]=x.a[i][j]+y.a[i][j];
        }
    }
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Mat::matrix_transpose(void)
{ 
   for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
void Mat::matrix_mult(Mat x, Mat y)
{ 
    int sum[x.r][x.r];
   for (int i=0; i<r; i++)
    {
        for (int j=0; j<r; j++)
        {
            sum[i][j]=0;
            for(int k=0;k<r;k++)
            {
                sum[i][j]+=x.a[i][k]*y.a[k][j];
            }
        }
    }
    cout<<"\nThe Product of the two matrices is : "<<endl;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

}
int Mat::matrix_trace(void){
    int sum =0;
    for(int i=0;i<r;i++)
    {
        sum=sum+a[i][i];
    }    
    return sum;
}
void Mat::accept_elements()
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }
}
int main()
{
    int r1,c1,r2,c2;
    cout<<"Enter the number of rows and columns of the first matrix : "<<endl;
    cin>>r1>>c1;
    Mat ob1(r1,c1);
    cout<<"Enter the values of the first matrix: "<<endl;
    ob1.accept_elements();
    cout<<"Enter the number of rows and colums of the second matrix : "<<endl;
    cin>>r2>>c2;
    Mat ob2(r2,c2);
    cout<<"Enter the values of the second matrix: "<<endl;
    ob2.accept_elements();
    cout<<"The Transpose of the First Matrix : "<<endl;
    ob1.matrix_transpose();
    cout<<"\nThe Transpose of the Second Matrix : "<<endl;
    ob2.matrix_transpose();
    int trace1=ob1.matrix_trace();
    cout<<"The Trace of the First Matrix : "<<trace1<<endl;
    int trace2=ob2.matrix_trace();
    cout<<"\nThe Trace of the Second Matrix : "<<trace2<<endl;
    Mat ob3(r1,c1);
     if (r1 != r2 || c1 != c2)
    {
        cout<<"Matrices must have the same number of rows and columns."<<endl;
    }
    else
    {
        cout<<"\nThe sum of the two matrices is: "<<endl; 
        ob3.matrix_add(ob1, ob2);        
    }
    if((r1==c1)&&(r2==c2))
    {
        Mat ob4(r1,r1);
        ob4.matrix_mult(ob1,ob2);
    }
    return 0;
}
