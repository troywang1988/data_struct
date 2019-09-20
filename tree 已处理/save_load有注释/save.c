#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	char data;
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;

int insert(struct node_st **root, int data)
{
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}

	if(data <= (*root)->data)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

void draw_(struct node_st *root,int level)
{
	int i;
	if(root == NULL)
		return ;

	draw_(root->r,level+1);

	for(i = 0 ;i < level ; i++)
		printf("	");
	printf("%c\n",root->data);

	draw_(root->l,level+1);
}

void draw(struct node_st *root)
{
	draw_(root,0);
}

int save_(struct node_st *root,FILE *fp)
{
	fputc('(',fp);
	/*if error*/	
	if(root == NULL)
	{
		fputc(')',fp);
		return 0;
	}	

	fputc(root->data , fp);
	/*if error*/	
	
	save_(root->l,fp);
	/*if error*/	

	save_(root->r,fp);
	/*if error*/	

	fputc(')',fp);
	/*if error*/	
	return 0;
}

int save(struct node_st *root, const char *path)  //tmp文件内容是字符常量，故此处型参修饰成const,否则会报错
{
	FILE *fp;

	fp = fopen(path,"w");  //打开一次文件就生成一个文件类型的结构体;文件不存在，就创建
	if(fp == NULL)
		return -1;
	save_(root,fp);
	/*if error*/	
	
	fclose(fp);
	return 0;
}

int main()
{
	char arr[] = "cefadjbh";
	int i;

	for(i = 0 ;i < sizeof(arr)/sizeof(*arr)-1; i++ )
	{
		insert(&tree,arr[i]);
	}
	draw(tree);

	save(tree,"tmp");

	return 0;
}


