/*

Find out time complexity of the following problems:

Problem 1:
    int i=0,sum = 0;       -->O(1)
    while(i<n)             -->O(N)
    {
        int j=0;
        while(j<n)        -->O(N)
        {
            sum += j;
            j+=2;
        }
        i++;
    }

Problem 1: O(N * N)


Problem 2:
    for(int i=0;i<n;i+=10)     -->O(N)
    {
        for(int j=n;j>=0;j--)  -->O(N)
        {
            cout << "Hello" << endl;
        }
    }


    for(int i=0;i<n;i++)   -->O(N)
    {
        cout << "Hi" << endl;
    }

Problem 2: O(N * N)


Problem 3:
    for(int i=0;i<n;i++)         --> O(N)
    {
        int j=0;
        while(j*j<n)         ---> O(sqrtN)
        {
            i+j;
            j++;
        }
    }

Problem 3: O(N * sqrtN)


Problem 4:
    for(int i=0;i<n;i++)      --> O(N)
    {
        for(int j=n;j>=0;j--)  --> O(N)
        {
            for(int k=1;k<=n;k++) ---> O(N)
            {
                sum += i+j+k;
            }
        }
    }


    for(int i=0;i<n;i++)  --> O(N)
    {
        for(int j=1;j<=n;j++)  --> O(N)
        {
            sum += i+j;
        }
    }

Problem 4: O(N * N *N)


Problem 5:
    for(int i=0;i*i<n;i++)   --> O(sqrtN)
    {
        sum += i;
    }


    for(int i=0;i<n;i++)
    {
        sum += i;
        i*=k;
    }

Problem 5: O(sqrtN)

Problem 6:
    for(int i=0;i<n;i++)        --> O(N)
    {
        cin >> a[i];
    }
    sort(a,a+n);           --> O(NlogN)

Problem 6: O(NlogN)

Problem 7:
    for(int i=0;i<n;i++)  --> O(N)
    {
        sort(a,a+n);  --> O(NlogN)
    }

Problem 7: O(N * NlogN)













 */