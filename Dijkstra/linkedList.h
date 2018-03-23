struct node
{
	int v;
	int peso;
	node *next;
};

node* insert(node* curr,int v,int p){
	node* n = new node;
	n->v = v;
	n->peso = p;
	n->next = curr->next;
	curr->next = n;
	return curr;
}