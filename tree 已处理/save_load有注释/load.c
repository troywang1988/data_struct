#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	char data;
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;

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

struct node_st *load_(FILE *fp)
{
	int c;
	struct node_st *root;

	c = fgetc(fp);//must be '('	
	if(c != '(')
	{
		fprintf(stderr,"read error.\n");
		return NULL;
	}
	
	c = fgetc(fp);
	if(c == ')')
		return NULL;
	
	root = malloc(sizeof(*root));
	/*if error*/
	root->data = c;
	
	root->l = load_(fp);
	root->r = load_(fp);
	fgetc(fp);// must be ')'
	/*if error*/
	return root;
}

struct node_st *load(const char *path)
{
	FILE *fp;
	struct node_st *root;

	fp = fopen(path,"r");
	if(fp == NULL)
		return NULL;
	
	root = load_(fp);
	
	fclose(fp);
	return root;
}

int main()
{
	tree = load("tmp");

	draw(tree);

	return 0;
}


