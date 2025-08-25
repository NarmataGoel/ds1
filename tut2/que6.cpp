
#include<iostream>
using namespace std ;
void input(int mat[1000][3]){
      int row ,column, n;
   cout<<"enter the no of row , column and non zero elements"<<endl;
   cin>>row>> column >>n;
   mat[0][0]=row;
   mat[0][1]=column;
   mat[0][2]=n;
   cout<<"enter the row and column and non-zero element value ";
   for (int i=1;i<=n;i++){
    cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
   }
}
void transposepairs (int mat[1000][3],int transpose[1000][3]){
   int row =mat[0][0];
   int col=mat[0][1];
   int n=mat[0][2];
   transpose[0][0]=col ;
   transpose[0][1]=row;
   transpose[0][2]=n;
    int k=1;
    for (int i=0;i<col ;i++){
      for (int j=1;j<=n;j++){
         if (mat[j][1]==i){
            transpose[k][0]=mat[j][1];
           transpose[k][1]=mat[j][0]; 
           transpose[k][2]=mat[j][2];
           k++;

         }
      }
    }
}
void addition(int mat[1000][3],int mat2[1000][3],int result[1000][3]){
if( mat[0][0]!=mat2[0][0] ||mat[0][1]!=mat2[0][1]){
   cout<<"both matrix cannot be added" <<endl;
}
 result[0][0]=mat[0][0];
 result[0][1]=mat[0][1];
   int i=1 ;
  int j=1;
  int k=1;
  int n1=mat[0][2], n2=mat[0][2];
  while(i<=n1  && j<=n2){
   if (mat[i][0]<mat2[j][0] || (mat[i][0]==mat[j][0] && mat[i][1]<mat2[j][1])){
        result[k][0] =mat[i][0] ;
        result[k][1]=mat [i][1];
        result[k][2]=mat[i][2];
        k++;
        i++;
}
else if (mat[i][0]>mat2[j][0] || (mat[i][0]==mat[j][0] && mat[i][1]>mat2[j][1])){
    result[k][0] =mat[j][0] ;
        result[k][1]=mat [j][1];
        result[k][2]=mat[j][2];
        k++;
        j++;
}
else {
   int sum=mat[i][2]+ mat2[i][2];
   if(sum!=0){
      result[k][0]=mat[i][0];
      result[k][1]=mat[i][1];
   result[k][2]=sum;
   k++;}
   i++;
   j++;
}      }
while (i<=n1){
 result[k][0] =mat[i][0] ;
        result[k][1]=mat [i][1];
        result[k][2]=mat[i][2];
        k++;
        i++;
}
while (j<=n2){
 result[k][0] =mat[j][0] ;
        result[k][1]=mat [j][1];
        result[k][2]=mat[j][2];
        k++;
        j++;
}
result[0][2]=k-1;
}
void multiply(int mat1[1000][3], int mat2[1000][3], int result[1000][3]) {
    if (mat1[0][1] != mat2[0][0]) {
        cout << "Matrix multiplication not possible!" << endl;
        result[0][2] = 0;
        return;
    }

    int r1 = mat1[0][0], c1 = mat1[0][1], n1 = mat1[0][2];
    int r2 = mat2[0][0], c2 = mat2[0][1], n2 = mat2[0][2];

    // Transpose mat2 for easier column access
    int trans2[1000][3];
    transposepairs(mat2, trans2);

    result[0][0] = r1;
    result[0][1] = c2;
    int k = 1;

    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;

            // Find non-zero elements in row i of mat1
            for (int a = 1; a <= n1; a++) {
                if (mat1[a][0] == i) {
                    // For each element in row i, check column j of mat2
                    for (int b = 1; b <= trans2[0][2]; b++) {
                        if (trans2[b][0] == j && trans2[b][1] == mat1[a][1]) {
                            sum += mat1[a][2] * trans2[b][2];
                        }
                    }
                }
            }

            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }

    result[0][2] = k - 1; // total non-zero elements
}
void printsparse(int mat[1000][3]){
   int n=mat[0][2];
   cout<<"rows "<<" coloumns"<<" nono zeo elements";
    for (int i=0;i<=n;i++){
      cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl ;
   }
}
int main(){
   int mat[1000][3];
  input(mat);
   int transpose[1000][3];
   cout<<"the 1 matrix is:"<<endl;
  printsparse(mat);
    transposepairs(mat,transpose);
   cout<<"Transpose matrix of matix1 :"<<endl;
   printsparse( transpose); 
 int mat2[1000][3];
   input(mat2);
   cout<<"the 2nd matrix is :"<<endl;
   printsparse(mat2);
   int result[1000][3];
   addition(mat,mat2,result);
   cout <<"the addition matrix is :"<<endl;
   printsparse(result);
return 0;
}