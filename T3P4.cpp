#include <bits/stdc++.h>

void printParenthesis(int i, int j, int n, int *bracket, char &name){
   
   if (i == j){
        std::cout << name++;
        return;
    }
    std::cout << "(";
    printParenthesis(i, *((bracket+i*n)+j), n, bracket, name);
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    std::cout << ")";
}

void matrixChainOrder(int p[], int n){

    int m[n][n];
    int bracket[n][n];

    for (int i=1; i<n; i++) m[i][i] = 0;
    
    for (int L=2; L<n; L++){
        for (int i=1; i<n-L+1; i++){
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;   
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
 
    std::cout << "La forma de multiplicar es : \n";
    printParenthesis(1, n-1, n, (int *)bracket, name);

    std::cout << "\nMinimo numero de operaciones necesarias : " << m[1][n-1]<<"\n";
}


int main(void){

    std::cout<<"Introduce la cantidad de matrices a multiplicar:\n";
    int N;
    std::cin>>N;
    int arr[N+1];
    int a, b;
    std::cout<<"Introduce las dimensiones de las matrices en orden:\n";
    for(int i=0;i<N;i++){
        std::cin>>a>>b;
        arr[i]=a;
    }
    arr[N]=b;
    int n = sizeof(arr)/sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}
