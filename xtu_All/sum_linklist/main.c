#include<stdio.h>
#include<stdlib.h>



typedef struct ListNode {
	int val;
    struct ListNode *next;
}Len_node; 

typedef struct ListNode *linknode;

struct ListNode* add_Two(struct ListNode* l1, struct ListNode* l2) 
{
    char flag = 0;
    char num_plus = 0;
    struct ListNode *ptr_return = l1;
    struct ListNode *ptr_dup_a = NULL;
    struct ListNode *ptr_pre = NULL;
    struct ListNode *ptr_tail = NULL;
    while(l1 && l2)
    {
        
        if(flag)
        {
            num_plus = l1->val + l2->val + 1;              /*进位加一*/
            l1->val = num_plus % 10;
            if(num_plus < 10)
            {
                flag = 0;
            }
        }
        else
        {
            num_plus = l1->val + l2->val;
            l1->val = num_plus % 10;
            if(num_plus < 10)
            {
//                l1->val += l2->val;
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        ptr_pre = l1;
        ptr_dup_a = l1;                  /*滞后当前node的前一个结点*/
        l1 = l1->next;
        l2 = l2->next;
    }
    
    
    if(l1)
    {
        while(l1)
        {
            if(flag)
            {
                l1->val = (l1->val + 1) % 10;
                if(l1->val != 0)                           /*有进位*/
                {
                    flag = 0 ;   
                }
            }
            ptr_pre = l1;           /*滞后一个*/
            l1 = l1->next;
        }
    }
    
    else if(l2)
    {
        ptr_dup_a->next = l2;
        ptr_dup_a = ptr_dup_a->next;
    
        while(ptr_dup_a)
        {
            if(flag)
            {
                ptr_dup_a->val = (ptr_dup_a->val +1) % 10;
                
                if(ptr_dup_a->val != 0)
                {
                    flag = 0; 
                }
            }
            ptr_pre = ptr_dup_a;
            ptr_dup_a = ptr_dup_a->next;
        }
    }

    else
    {
        if(flag)
        {
            ptr_tail = (struct ListNode *)malloc(sizeof(Len_node));
            ptr_tail->val = 1;
            ptr_tail->next = NULL;
            ptr_pre->next = ptr_tail;
            flag = 0;
        }     
    }
    
    /*收尾*/
    if(flag)
    {
       ptr_tail = (struct ListNode *)malloc(sizeof(Len_node));
       ptr_tail->val = 1;
       ptr_tail->next = NULL;
       ptr_pre->next = ptr_tail;
    }
    return ptr_return;
}


int main()
{
	linknode ptr_a = (linknode)malloc(sizeof(Len_node));

	ptr_a->val = 0;
	ptr_a->next = NULL;
	
	linknode ptr_b = (linknode)malloc(sizeof(Len_node));

	ptr_b->val = 1;
	ptr_b->next = NULL;

	//ptr_b->next = (linknode)malloc(sizeof(Len_node));
//	ptr_b->next->val = 1;
//	ptr_b->next->next = NULL;

	ptr_a = add_Two(ptr_a, ptr_b);

	return 0;

}



