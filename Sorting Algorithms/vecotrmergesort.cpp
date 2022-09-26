#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> merge_sort(vector<int> list);
vector<int> merge(vector<int> left, vector<int> right);

int main()
{
    vector<int> listToSort;
    listToSort.push_back(7);
    listToSort.push_back(4);
    listToSort.push_back(3);
    listToSort.push_back(5);
    listToSort.push_back(2);
    listToSort.push_back(8);
    listToSort.push_back(1);

    cout << "List sorted: " << endl;

    vector<int> listSorted = merge_sort(listToSort);

    for(int x : listSorted)
        cout << x << ", ";

    return 1;
}

vector<int> merge_sort(vector<int> list)
{
    if(list.size() > 1)
    {
        int mid = floor(list.size()/2);

        vector<int> left, right;
        for(int i = 0; i < mid; i++)
            left.push_back(list[i]);
        for(int j = mid; j < list.size(); j++)
            right.push_back(list[j]);

        left = merge_sort(left);
        right = merge_sort(right);
        return merge(left, right);   
    }
    
    return list;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> list;
    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size())
    {
        if(left[i] < right[j])
        {
            list.push_back(left[i]);
            i++;
        }
        else 
        {
            list.push_back(right[j]); 
            j++;
        }
    }

    while (i < left.size())
    {
        list.push_back(left[i]);
        i++;  
    }

    while (j < right.size())
    {
        list.push_back(right[j]);
        j++;
    }

    return list;
}