/*
-----------------------------------------------------------------------------
int k=1;
while(k<=n){
    cout<<k<<endl;
    k=k*2;
}

Time Complexity: O(logN)
-------------------------------------------------------------------------------

for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            cout << i << j;

Time Complexity: O(N * N)
-------------------------------------------------------------------------------

for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            for(int k=j; k > 0; k--)
                cout << i << j << k;

Time Complexity: O(N * N * N)
-------------------------------------------------------------------------------

for(int i=n/2;i<=n;i++){
    for(int j=1;j<=n;j=j*2){
        cout<<i<<j<<endl;
    }
}

Time Complexity: O(NlogN)
--------------------------------------------------------------------------------

for(int i=n/2;i<=n;i++){
    for(int j=1;j<=n;j=j+i){
        cout<<i<<j<<endl;
    }
}

Time Complexity: O(N * N)


*/