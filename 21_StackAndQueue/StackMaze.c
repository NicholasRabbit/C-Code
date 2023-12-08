# include<stdio.h>

# define MAX_ROW 5
# define MAX_COL 5
/*
 * 使用栈实现迷宫回溯。
 * Java数据结构和算法代码使用的是递归，道理相同，都是用到的栈的LIFO的特性。
 *
 *
 * */

//1,使用结构体表示栈，用来记录棋子走过的下标。
struct point{
	int row, col;
} stack[512];

//栈顶
int top = 0;  

//Push
int push(struct point p){
	//注意top++是先赋值，后自加一
	stack[top++] = p;
	return 1;
}

//Pop
struct point pop(){
	//这里必须把--放到前面，先自减一后赋值，因为入栈后top自加一了，是指向栈顶元素的上一个位置的。
	return stack[--top];
}

//2,声明一个结构体数组，容量和maze相同的二维数组，对应坐标位置保存的就是maze的前趋坐标。
struct point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	
};

//3,迷宫maze
int maze[MAX_ROW][MAX_COL] = {
	{0,1,0,0,0},
	{0,1,0,1,0},
	{0,0,0,0,0},
	{0,1,1,1,0},
	{0,0,0,1,0},
};

//printing maze
void print_maze(){
	int i;
	for(i = 0; i < MAX_ROW; i++){
		int j;
		for(j = 0; j < MAX_COL; j++){
			printf("%d, ",maze[i][j]);
		}
		printf("\n");
	}

	printf("==============\n");
}

//
int isEmpty(){
	return top == 0;
}

//4,入栈下个坐标和前趋坐标
int find(int row, int col, struct point pre){

	//找到路径坐标入栈
	struct point find_pt = {row, col};
	push(find_pt);
	//标记已走过
	maze[row][col] = 2;
	//保存前趋坐标，注意前趋点二维数组和maze下标对应。
	//所以不要写作：predecessor[pre.row][pre.col] = pre，这样把这个点的前驱坐标数据保存到这个数据对应的predecessor[][]位置了，原位置没有数据了。
	predecessor[row][col] = pre;

	return 1;
}


int main(void){

	//The original point.
	struct point p = {0,0};
	push(p);
	top ++;  //Don't forget plus 1.
	maze[0][0] = 2;
	//第一个点不用保存前趋节点，没有。
	
	//四个方向查找路径
	while(!isEmpty()){
		p = pop();

		//destination
		if(p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
			break;

		//right
		if(p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0){
			find(p.row, p.col + 1, p);
		}

		//front
		if(p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0){
			find(p.row + 1, p.col, p);
		}

		//left
		if(p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0){
			find(p.row, p.col - 1, p);
		}

		//rear.
		//Caution: if it step backwards, the inex of it must be greater than 0 or equal to 0.
		if(p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0){
			find(p.row - 1, p.col, p);
		}


		print_maze();
	}

	//Print the path
	if(p.row == MAX_ROW - 1 && p.col == MAX_COL - 1){
		printf("(%d,%d)\n", p.row, p.col);
		while(predecessor[p.row][p.col].row > -1 && predecessor[p.row][p.col].col > -1){
			printf("(%d,%d)\n", predecessor[p.row][p.col].row, predecessor[p.row][p.col].col);
			//继续向前找前趋点
			p = predecessor[p.row][p.col];
		}
	}
	

	
	return 0;

}
