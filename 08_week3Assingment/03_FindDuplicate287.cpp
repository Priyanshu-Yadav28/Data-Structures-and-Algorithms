#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

//first solution (naive method)

int duplicateElement(vector<int> nums) {

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
       if (nums[i] == nums[i + 1])
       {
        return nums[i];
       }
       
    }

    return - 1;

}


// second solution 
// this is a good solution but it modifies the array 
int duplicate(vector<int> nums) 
{
    int ans = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        
        // already visited
        if (nums[index] < 0)
        {
            ans = index;
            break;
        }

        nums[index] *= -1;
        
    }

    return ans;
}

// third solution : without modifing the array 

//positioning method 
int findDuplicate2(vector<int> nums)  {

    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }

    return nums[0];
    
}

int main()
{

    vector<int> nums{1, 2, 4, 3, 2};

    // cout << duplicate(nums) << endl;
    
    int ans = findDuplicate2(nums);

    cout << ans;

    return 0;
}