void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
int b[10][10];
void main()
{
    int i,j,r;
    printf("Enter number of vertices:");

    scanf("%d",&n);

    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");

    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
	    scanf("%d",&G[i][j]);

    //visited is initialized to zero
   for(i=1;i<=n;i++)
	visited[i]=0;
   printf("enter the root node:\n");
   scanf("%d",&r);
    DFS(r);

    printf("dfs tree:\n");
    for(i=1;i<=n;i++)
    {
		for(j=1;j<=n;j++)
		printf("\t%d",b[i][j]);
		printf("\n");
    }
}

void DFS(int i)
{
    int j;
    visited[i]=1;

    for(j=1;j<=n;j++)
       if(!visited[j]&&G[i][j]==1)
       {
	    	DFS(j);
	    	b[i][j]=1;
		}
}
