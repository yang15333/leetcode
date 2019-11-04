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
	*returnColumnSizes = malloc(numsSize * sizeof(int));

	while (end > head)
	{
		lhead = head;
		nhead = head;
		for (; head < end -1; head++)
		{
			if (nums[head] == nums[lhead])
			{
				nhead = head;
				continue;
			}
			for (i = head + 1; i < end; ++i)
			{
				if ((nums[head] + nums[end]) == -nums[i])
				{
					(*returnSize)++;
					(*returnColumnSizes)[3 * (*returnSize) - 1] = nums[head];
					(*returnColumnSizes)[3 * (*returnSize) - 2] = nums[end];
					(*returnColumnSizes)[3 * (*returnSize) - 3] = nums[i];
					goto a;
				}
			}
		}
a:
		head = nhead + 1;
		lend = end;
		nend = end;		
		for (; end > head + 1; end--)
		{
			if (nums[end] == nums[lend])
			{
				nend = end;
				continue;
			}
			for (i = end - 1; i > head; --i)
			{
				if ((nums[head] + nums[end]) == -nums[i])
				{
					(*returnSize)++;
					(*returnColumnSizes)[3 * (*returnSize) - 1] = nums[head];
					(*returnColumnSizes)[3 * (*returnSize) - 2] = nums[end];
					(*returnColumnSizes)[3 * (*returnSize) - 3] = nums[i];
					goto b;
				}
			}
		}
b:
		end = nend - 1;
	}
}



int main(void)
{
	int nums[10] = {-1,0,1,2,-1,-4};
	int *retnums = NULL;
	int ret_len = 0, i = 0;
	threeSum(nums, 10, &ret_len, &retnums);
	for(i = 0; i < ret_len; i++)
	{
		printf("[%d, %d, %d]\n", retnums[i*3], retnums[i*3+1], retnums[i*3+2]);
	}
	free(retnums);
	return 0;
}
