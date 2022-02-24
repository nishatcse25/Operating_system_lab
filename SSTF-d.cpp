#include <bits/stdc++.h>
using namespace std;

void calculatedifference(int request[], int head,
                         int diff[][2], int n)
{
    for(int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}

int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;

    for(int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[],
                           int head, int n)
{
    if (n == 0)
    {
        return;
    }

    int diff[n][2] = { { 0, 0 } };

    int seekcount = 0;

    int seeksequence[n + 1] = {0};

    for(int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        seekcount += diff[index][0];

        head = request[index];
    }
    seeksequence[n] = head;

    cout << "Total number of seek operations = "
         << seekcount << endl;
    printf("Total distance:");

    for(int i = 0; i < n; i++)
    {
        if (seeksequence[i+1]>seeksequence[i])
        {
            printf("(%d- %d)",seeksequence[i+1], seeksequence[i]);
        }
        else
            printf("(%d- %d)",seeksequence[i], seeksequence[i+1]);


    }
    printf("\n");
    cout << "Seek sequence is : " << " ";
    for (int i=0; i<n; i++)
    {

        cout<< seeksequence[i]<<" ";
    }
}

int main()
{
    int n ,head;
    int proc[100];
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(int i=0;i<n;i++)
     scanf("%d",&proc[i]);
    printf("Enter initial head position\n");
    scanf("%d",&head);


    shortestSeekTimeFirst(proc, head, n);

    return 0;
}
