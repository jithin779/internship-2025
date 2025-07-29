#include<stdio.h>
int main()
{
int row,cols,i,j,k,a[10][10],spmatrix[10][3],transmatrix[10][3];
printf("enter the row size and columns size");
scanf("%d%d",&row,&cols);
printf("enter the values of sparse matrix:");
for(i=0;i<row;i++){
for(j=0;j<cols;j++){
scanf("%d",&a[i][j]);
}
}
printf("THE SPARSE MATRIX IS:\n");
for(i=0;i<row;i++){
for(j=0;j<cols;j++){
printf("%d\t",a[i][j]);
}
printf("\n");
}
k=1;
for(i=0;i<row;i++){
for(j=0;j<cols;j++){
if(a[i][j]!=0){
spmatrix[k][0]=i;
spmatrix[k][1]=j;
spmatrix[k][2]=a[i][j];
k=k+1;
}
}
}
printf("TUPLE FORMAT IS : \n");
spmatrix[0][0]=row;
spmatrix[0][1]=cols;
spmatrix[0][2]=k-1;
for(i=0;i<=spmatrix[0][2];i++){
for(j=0;j<3;j++){
printf("%d\t",spmatrix[i][j]);
}
printf("\n");
}
transmatrix[0][0]=spmatrix[0][1];
transmatrix[0][1]=spmatrix[0][0];
transmatrix[0][2]=spmatrix[0][2];
k=1;
for(i=0;i<=spmatrix[0][1];i++){
for(j=1;j<=spmatrix[0][2];j++){
if(spmatrix[j][1]==i){
transmatrix[k][0]=spmatrix[j][1];
transmatrix[k][1]=spmatrix[j][0];
transmatrix[k][2]=spmatrix[j][2];
k=k+1;
}
}
}
printf("THE TRANSPOSE MATRIX IS:\n");
for(i=0;i<=transmatrix[0][2];i++){
for(j=0;j<3;j++){
printf("%d\t",transmatrix[i][j]);
}
printf("\n");
}
}



