#include <stdio.h>
#include <stdlib.h>
/**
 *  * Return an array of arrays of size *returnSize.
 *   * The sizes of the arrays are returned as *returnColumnSizes array.
 *    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *     */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i = 0, j = 0, t = 0;
	int head = 0, end = numsSize - 1;
	int lhead = 0, lend = 0, nhead = 0, nend = 0;
	int ptr = 0;
	int a[100] = {0};

	for (i = 0; i < numsSize - 1; ++i)
	{
		for (j = 0; j < numsSize-i-1; ++j)
		{
			if(nums[j] > nums[j+1])
			{
				t = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = t;
			}
		}
	}
	*returnColumnSizes = malloc(100000);
	int **ret  = (int **)malloc(100000);

	while (end > head)
	{
		lend = head+2;
		while (lend <= end)
		{
			i = head + 1;
			for (; i < lend; i++)
			{
				if (nums[i] + nums[lend] + nums[head] == 0)
				{
					if (ptr > 0 && (nums[head] == ret[ptr-1][0] && nums[i] == ret[ptr-1][1]))
						continue;
					ret[ptr] = malloc(sizeof(int) * 3);
					ret[ptr][0] = nums[head];
					ret[ptr][1] = nums[i];
					ret[ptr][2] = nums[lend];
					(*returnColumnSizes)[ptr] = 3;
					ptr++;
				}
			}
			lend++;
			
		}
		do
		{
			head++;
		}while(head < end && nums[head] == nums[head+1]);

	}
	*returnSize = ptr;
	return ret;
}



int main(void)
{
	int nums[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	int *retnums = NULL;
	int ret_len = 0, i = 0;
	int **ret = threeSum(nums, sizeof(nums)/sizeof(nums[0]), &ret_len, &retnums);
	for(i = 0; i < ret_len; i++)
	{
		printf("[%d, %d, %d]\n", ret[i][0], ret[i][1], ret[i][2]);
	}
	free(retnums);
	return 0;
}
