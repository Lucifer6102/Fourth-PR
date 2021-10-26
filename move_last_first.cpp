Node* movetofront(Node* head)
{
	Node* temp=head;
	int d;
	while(temp!=NULL)
	{
		if(temp->next->next==NULL)
		{
			d=temp->next->data;
			temp->next=NULL;
		}
		temp=temp->next;
	}
	Node* root;
	root->data=d;
	root->next=head;
	head=root;
	return head;
}

// Time - O(n)
// Spcae - O(1)