#include<stdio.h>
#include<stdlib.h>
#define AND &&
#define OR ||
int main(){
    //declaring variables
    int i, j, k, m,n, min, max,pos[2][2];
    //declaring a 3x3 matrix
    int matrix[3][3]={{1, 2, 3},{4, 5, 6},{0, 8, 9}};
    m=3;
    n=3;
    for (i = 0; i < m; i++)
		{
            //taking the first element of the row as the smallest
			min = matrix[i][0];
			for (j = 0; j < m; j++)//finding the real smallest element of the row 
				{
					if (min >= matrix[i][j])
						{
							min = matrix[i][j];
							pos[0][0] = i;//stroing the
							pos[0][1] = j;//coords of  the smallest element
						}
				}
     j = pos[0][1];// taking j as the j value of the min elemnent
     max = matrix[0][j];// taking the maximun elemnet of the row as the first elment of the column
	for (k = 0; k < m; k++)
	{
		if (max <= matrix[k][j])
			{
				max = matrix[i][j];
				pos[1][0] = k;//storing the coords of the actual max element
				pos[1][1] = j;
			}
	}
	if (min == max) // if the min of row is max of column then that point is the saddle point
    {
		if (pos[0][0] == pos[1][0] &&pos[0][1] == pos[1][1])
		{
			printf("Saddle point : %d\n", max);//printing the result
            return 0;
		}
	}
}
}