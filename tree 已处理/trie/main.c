#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 128
#define DESC_SIZE 128
#define BUFSIZE (KEY_SIZE+DESC_SIZE)
#define SIZE 26
  
struct node_st
{
	struct node_st *ch[SIZE];
	char desc[DESC_SIZE];
};

int get_world(FILE *fp,char *key,char *desc)
{
	char *ret;
	int i,j;
	char buf[BUFSIZE];

	ret = fgets(buf,BUFSIZE,fp);
	if(ret == NULL)
		return -1;

	for(i = 0 ;i < KEY_SIZE-1 && buf[i] != ':';i++ )
		key[i] = buf[i];
	key[i] = '\0';

	i++;
	
	for(j = 0 ; j < DESC_SIZE-1 && buf[i] != '\n' ;i++,j++)
		desc[j] = buf[i];
	desc[j] = '\0';	
	return 0;	
}

static struct node_st *newnode()
{
	int i;
	struct node_st *root;
	
	root = malloc(sizeof(*root));
	if(root == NULL)
		return NULL;
	
	root->desc[0] = '\0';
	for(i = 0 ;i < SIZE ; i++)
		root->ch[i] = NULL;

	return root;
}

//key-->"ant" 
int insert(struct node_st **root,char *key,char *desc)
{
	if(*root == NULL)
	{
		*root = newnode();
		if(*root == NULL)
			return -1;
	}

	if(*key == '\0')
	{
		strncpy((*root)->desc , desc,DESC_SIZE-1);
		(*root)->desc[DESC_SIZE-1] = '\0';
		return 0;
	}
	
	return insert(&(*root)->ch[*key-'a'],key+1,desc);

}

char *find(struct node_st *root,char *key)
{
	if(root == NULL)
		return NULL;
	if(*key == '\0')
		return root->desc;
	return find(root->ch[*key-'a'],key+1);
}

int main()
{
	int ret;
	FILE *fp;
	struct node_st *tree = NULL;
	char key[KEY_SIZE],desc[DESC_SIZE];
	char *datap;

	fp = fopen("tmp","r");		
	if(fp == NULL)
		return -1;	

	while(1)
	{
		ret = get_world(fp,key,desc);
		if(ret == -1)
			break;
		insert(&tree,key,desc);
	}

	datap = find(tree,"donkey");
	if(datap == NULL)
		printf("can not find!\n");
	else
		puts(datap);

	return 0;
}





