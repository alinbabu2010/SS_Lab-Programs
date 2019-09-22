struct node* search_parent(struct node* ptr,int item)
{
  struct node *ptr3,*ptr4;
  top=-1;
  push(ptr);
  while(top!=-1)
  {
     ptr=pop();
     if(ptr!=NULL)
     {
       ptr3=ptr->lc;
       ptr4=ptr->rc;
       if(ptr->data==item)
         flag=1;
       if(ptr4!=NULL)
       {
           push(ptr4);
           parent=ptr;
       }
       if(ptr3!=NULL)
       {
           push(ptr3);
           parent=ptr;
       }
     }
  }
  if(flag==1)
   return parent;
  else
   return NULL;
}