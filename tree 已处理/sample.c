#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st  //树节点的形式
{
	struct score_st data;  //data是结构体类型数据
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;  //全局静态结构体指针tree

static void print_s(struct score_st *d)  //*d只是形参，要打印的是实参内容
{
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int insert(struct node_st **root, struct score_st *data)
{
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}

	if(data->id <= (*root)->data.id)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

struct score_st *find(struct node_st *root,int id)
{
	if(root == NULL)
		return NULL;
	if(id == root->data.id)
		return &root->data;
	if(id < root->data.id)
		return find(root->l,id);
	return find(root->r,id);

}

void draw_(struct node_st *root,int level)
{
	int i;
	if(root == NULL)
		return ;  //遇到return说明递归调用结束，执行函数中其他语句，之后被压入栈的函数逐层探出执行。本程中当draw_递归结束后，接着执行for语句，连续打印level个空格，之后打印执行print_s函数，再执行另一个同样的递归调用。

	draw_(root->r,level+1);

	for(i = 0 ;i < level ; i++)
		printf("	");
	print_s(&root->data);

	draw_(root->l,level+1);
}

void draw(struct node_st *root)
{
	draw_(root,0);
	printf("\n\n\n");
	getchar();
}

static int get_num(struct node_st *root)
{
	if(root == NULL)
		return 0;
	return (get_num(root->l) + get_num(root->r) + 1);
}

static struct node_st *find_min(struct node_st *root)
{
	if(root->l == NULL)
		return root;
	return find_min(root->l);
}

static void turn_left(struct node_st **root)  //每次旋转*tree都会改变，故传指向*tree的2级指针
{
	struct node_st *cur = *root;

	*root = cur->r;  //左旋将根的右子作根
	cur->r = NULL;  //断开cur的右边，即将cur节点分割出来
	find_min(*root)->l = cur;  //从*root开始向左找，找到该树最左侧节点，将cur挂在它的左侧
//	draw(tree);
}

static struct node_st *find_max(struct node_st *root)
{
	if(root->r == NULL)
		return root;
	return find_max(root->r);
}

static void turn_right(struct node_st **root)
{
	struct node_st *cur = *root;

	*root = cur->l;
	cur->l = NULL;
	find_max(*root)->r = cur;
//	draw(tree);
}
void balance(struct node_st **root)
{
	int sub;
	if(*root == NULL)
		return ;
	while(1)
	{
		sub = get_num((*root)->l) - get_num((*root)->r);
		if(sub >= -1 && sub <= 1)
			break;
		if(sub < -1)
			turn_left(root);
		else
			turn_right(root);
	}

	balance(&(*root)->l);
	balance(&(*root)->r);
}
#if 0
void travel(struct node_st *root)
{
	if(root == NULL)
		return ;
	travel(root->l);
	travel(root->r);
	print_s(&root->data);
}
#else
void travel(struct node_st *root)
{
	int ret;
	QUEUE *lq;
	struct node_st *cur;
								
	lq = queue_create(sizeof(struct node_st *));
	if(lq == NULL)
		return ;
				
	queue_en(lq,&root);
	/*if error*/
	
	while(1)
	{	
		ret = queue_de(lq,&cur);
		if(ret == -1)
			break;
		print_s(&cur->data);
		if(cur->l != NULL)
		{
			queue_en(lq,&cur->l);
			/*if error */
		}
		if(cur->r != NULL)
		{
			queue_en(lq,&cur->r);
			/*if error */
		}
	}

	queue_destroy(lq);
}
#endif
int main()
{
	//struct node_st *tree = NULL;  定义无头树
	struct score_st tmp,*datap;
	int arr[] = {1,2,3,7,6,5,9,8,4};
	int i;

	for(i = 0 ;i < sizeof(arr)/sizeof(*arr); i++ )
	{
		tmp.id = arr[i];
		tmp.math = 100 - arr[i]; 
		snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);

		insert(&tree,&tmp);
	}

	draw(tree);
	balance(&tree);
	draw(tree);

	travel(tree);



#if 0
	datap = find(tree,13);
	if(datap == NULL)
		printf("can not find!\n");
	else
		print_s(datap);
#endif


	return 0;
}


