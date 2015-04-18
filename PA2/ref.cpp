#include <cmath>
#include <stdio.h>
//#include <stdlib.h>
struct food_data
{
    int x_coordinate;
    int y_coordinate;
    int weight;		
};

int shortestPath_DP(int, struct food_data[], int, int[], int[]);
int shortestPath_GA(int, struct food_data[], int);
int checkCapacity(int, int, struct food_data[], int);
int dist(int, int, struct food_data[]);
int dist2origin(int, struct food_data[]);

int main(void)
{
	int capacity = 10;
	int total_number_of_food = 5;
	int minimal_distance_DP;
	int minimal_distance_GA;
	int minimalDistance[4] = {2147483647,2147483647,2147483647,2147483647,2147483647};
	int goback[5]={0,0,0,0,0};
	
	struct food_data food[] = {{1,2,3},{1,0,3},{3,1,4},{3,1,4},{2,1,6}};
	printf("1. �ʺA��k:\n");
	minimal_distance_DP = shortestPath_DP(total_number_of_food, food, capacity, minimalDistance, goback);
	for(int i = 0; i < 5; i++)
	{
		if(goback[i]<0||i == 4)
		    printf("   �ߧ���%d�ӭ������^\n", i+1);
	}
	for(int i = 0; i < 5; i++)
	    printf("   �ߧ�%d�ӭ����һݳ̵u���{��%d\n", i+1, minimalDistance[i]);
	printf("\n2. �g�ߤ�k:\n");
	minimal_distance_GA = shortestPath_GA(total_number_of_food, food, capacity);
	printf("   �ߧ�%d�ӭ����һݳ̵u���{��%d\n", total_number_of_food, minimal_distance_GA);

	return(0);
}

int shortestPath_DP(int i, struct food_data food[], int capacity, int d[], int goback[])
{	
	if(i == 0)
		return(0);
	
	if(d[i-1] < 2147483647)
	    return(d[i-1]);
	
	int minimalDistance = 2147483647;
	int flag;
	int j;
	int temp;
	int change_sign;
	
	for(j = 0; j < i; j++)
	{
		//�ˬd��j+1�ӭ�����̫�@�ӭ���i�����q�`�M�O�_�W�L�W��
		flag = checkCapacity(j+1, i, food, capacity);
	    if(change_sign * flag < 0)
	        *(goback+j-1) = -1;
		change_sign = flag;
		//�Y�W�L�W���h�N�ۥ[�������`�M���(j++�Ө�ĳ̫�@��i),�~���ˬd 
		if(flag == 1)
		{
			continue; 
		}
		//�Y�S���W�L�W���A�h��ܲ�j�ӭ����@����̫�@�ӭ���i�i�H�@���h��! 
		//�ҥH�̵u���|�|�ܦ�: ��j�ӭ����ɪ��̵u���| + �q���I���j�ӭ������Z�� + ��j�ӭ����̧Ǿ߬B�ѤU����(j+1, j+2...)��̫�@�ӭ������Z��  + �q�̫�@�ӭ�����^���I���Z�� 
		//d[i] = d[j]+dist2origin(j+1)+dist(j+1, i)+dist2orgin(i);
		temp = shortestPath_DP(j, food, capacity, d, goback) + dist2origin(j+1, food) + dist(j+1, i, food) + dist2origin(i, food);

		if(minimalDistance > temp)
		{
		    *(d+i-1) = temp;
			minimalDistance = temp;
	    }
	}
	
	return(minimalDistance);
}

int shortestPath_GA(int i, struct food_data food[], int capacity)
{
	int minimalDistance = 0;
	int index = 1;
	int flag;
	
	if(i == 0)
		return(0);
	
	for(int j = index; j <= i; j++)
	{
		flag = checkCapacity(index, j, food, capacity);
	
		if(flag == 1)
		{
		    minimalDistance += dist2origin(index, food) + dist(index, j-1, food) + dist2origin(j-1, food);
		    index = j;
		    j--;
			printf("   �ߧ���%d�ӭ������^\n", j);
	    }
	    
		if(j == i)
	    {
	    	minimalDistance += dist2origin(index, food) + dist(index, j, food) + dist2origin(j, food);
			printf("   �ߧ���%d�ӭ������^\n", i);
		}
	}
	return(minimalDistance);
}

int checkCapacity(int initial, int terminal, struct food_data food[], int capacity)
{
	int counter;
	int partial_sum_of_weight = 0;
	
	for(counter = initial; counter <= terminal; counter++)
	{
		partial_sum_of_weight = partial_sum_of_weight + ((food + (counter-1)) -> weight);
	}
	
	if(partial_sum_of_weight <= capacity)
	    return(-1); 
	else
		return(1);
}

int dist(int i, int j, struct food_data food[])
{
	int distance = 0;
	int k;
	
	for(k = i; k < j; k++)
	{
	    int x_difference = abs(((food+k) -> x_coordinate)-((food+k-1) -> x_coordinate));
        int y_difference = abs(((food+k) -> y_coordinate)-((food+k-1) -> y_coordinate));
	
    	distance = distance + x_difference + y_difference;
	} 
	return(distance);
}

int dist2origin(int i, struct food_data food[])
{
    if(i ==0)
        return(0);
        
	int x_difference = ((food+i-1) -> x_coordinate);
    int y_difference = ((food+i-1) -> y_coordinate);
    	
	int distance = x_difference + y_difference;
	
	return(distance);
}
