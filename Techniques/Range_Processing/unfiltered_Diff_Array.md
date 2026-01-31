Whenever we see that we have to efficiently update the ranges of an array, we should always think of difference array technique which does this in constant, yes constant time complexity.

We can understand how efficient this is by taking a simple example:
Let us take an array of size 10, for simplicity assume the inital configuration to be all zeros. If we have to apply this updates {(1,4,2),(3,8,3)} normally, in the worst case complexity it will take linear time for each update. Now let us see how difference array techniqye does this
For 1,4,2 instead of iterating over the array from index 1 to 4, we maintain a new array diff(with size generally 1 more then given array.Why 1 more? Easy to implement for me persoanlly)
Now diff[1] = +2 and diff[4+1] = -2.
Similarly, for (3,8,3) we do diff[3] = +3 and diff[8+1] = -3.
So now lets say we need sum of entire updated array, we will have it in linear time, just iterate the diff array ..currently the diff array is (array is 0 indexed but we have done 1 indexed numebring)
[0,2,0,3,0,-2,0,0,0,-3,0]

Now lets have iterator ar index 1 with value 2, we need 2 variables totalSum and cumulativeSum at each step we update cumulativeSum = cumulativeSum + diff[i] and totalSum = totalSum + cumulativeSum.

So, here is a dry run;
i=0, cumulativeSum=0, totalSum=0
i=1, cumulativeSum=2, totalSum=2
i=2, cumulativeSum=2, totalSum=4
i=3, cumulativeSum=5, totalSum=9
i=4, cumulativeSum=5, totalSum=14
i=5, cumulativeSum=3, totalSum=17
i=6, cumulativeSum=3, totalSum=20
i=7, cumulativeSum=3, totalSum=23
i=8, cumulativeSum=3, totalSum=26
i=9, cumulativeSum=0, totalSum=26
i=10, cumulativeSum=0, totalSum=26

So totalSum of the updated array is 26. Let us verfiy it : 4*2 + (8-3+1)*3 = 8 + 18 = 26, which matches

Best thing about this technique is that it is very very easy to implement and also to spot. Also regarding addign extra 1 space in diff, it is to avoid extra check in case the upadte rule contains last element for example 1,10,5, then we need diff[10+1]=-5 which may go out of bounds.

Problems that can be solved by diff array techniqe can also be generallysolved by segment Trees but latter is an overkill according to me.
Also in case there are only range updates, diff does it in O(1) whiel segtTees take O(logn)

NOTE in case there is both range updates and we need to dispaly sum time and again it may be useful to use segTrees as alcaung sum takes O(n) here.Also instead of range updates if there are direct value updates like arr[1]=5, then there may be sligh modification in implemetaiton or better to use segtrees
