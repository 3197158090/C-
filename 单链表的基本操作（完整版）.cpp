#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{ 
    int data; 
	struct Node *next;
}Node,*List; 

/*建立链表*/ 
List CreateList() 
{ 
	List head,node,tail;
	tail=head=NULL;
	int len = 0; 
	scanf("%d", &len); 
	if (len == 0) 
		return NULL; 
	while (len--) 
	{ 
		node = (List)malloc(sizeof(struct Node)); 
		if (head == NULL) 
			head = node; 
		else 
		tail->next = node; 
		node->next = NULL; 
		scanf("%d", &node->data); 
		tail = node;
	} 
	return head; 
} 

//打印链表 
void Print(List head) 
{ 
	List p = head; 
	if (p == NULL) 
		printf("NULL"); 
	else 
		printf("\n"); 
	while (p!=NULL) { 
		printf("%d ", p->data); 
		p = p->next; 
	} 
}

//反转链表 
List Reverse(List head) 
{
	//不知名方法 
	List Temp, Prev; 
	Prev = NULL; 
	while(head) 
	{ 
		Temp = head->next; 
		head->next = Prev; 
		Prev = head; 
		head = Temp; 
	} 
	return Prev; 
	/*双指针法*/ 
	Node *cur=NULL,*pre=head;//cur为新的链表的最后 ,pre为当前待添加到新链表的节点 
	while(pre!=NULL){
		Node *tmp=pre->next; //保存pre->next ； 
		pre->next=cur;
		cur=pre;
		pre=tmp;
	}
	return cur;
	/*递归法*/
	if(head==NULL||head->next==NULL){
		return head;
	}
	List ret=Reverse(head->next);
	head->next->next = head;
    head->next = NULL;
    return ret;
	
}

//将元素x插入指定位置k处  /* 增加 */
List Insert(List head,int k,int x){
	List pre;
    pre=head;
    int temp=0;
    for(temp=1;temp<k;temp++){
        pre=pre->next;
    }

    List p;
    p=(List)malloc(sizeof(Node));
    p->data=x;
    p->next=pre->next;
    pre->next=p;
    return head;
}

//修改链表中的某个值, 将链表中的a值修改为b值   /*改*/ 
List Replace(List head,int a,int b){
	List p;
	p=head->next;
    while(p){
        if(p->data==a){
            p->data=b;
        }
        p=p->next;
    }
    return head;
} 

//删除链表中的某个元素x             /*删*/ 
List Delete(List head,int x){
	List p,pre;
    pre=head;
    p=head->next;

    while(p->data!=x){
        pre=p;
        p=p->next;
    }
    pre->next=p->next;
    free(p);
    return head;
}
//查找操作 
//按序号i查找节点值
List Getelem(List head,int i){
	int num=1;          //计数，初始化为1
	List p=head;  //头结点指针赋给p
	while(num<i&&p->next!=NULL){
		p = p->next;
		num++;
	}
	if(num==i){			//若i等于0，返回头结点
		return p;	
	}
	else
		return NULL;
}

//按元素值x查找节点
List Locate(List head,int x){
	List p=head->next;     //头结点指针赋给p
	while(p!=NULL&&p->data!=x){
		p = p->next;
	}
	return p;	
} 

/*获取链表长度*/
//获取带头结点的长度 
int Length1(List head){
	List p = head;
	int j=0;
	while(p->next){
		p = p->next;
		j++;
	}
	return j; 
}

//获取不带头结点的长度 
int Length2(List head){
	List p = head;  //非空表下指向的就是第一个结点
	int j=0;
	while(p){
		j++;
		p = p->next;
	}
	return j; 
}


int main() 
{ 
	List L1,L2,L3; 
	int x,k;
	//创建链表 
	L1 = CreateList(); 
	Print(L1); 
	printf("\n");
	
	//输出链表长度 
	int length;
	length=Length2(L1);//带头结点的长度比不带头结点的长度少1 
	printf("%d",length);
	printf("\n");
	
	//反转链表 
	L2 = Reverse(L1); 
	Print(L2); 
	printf("\n");
	
	//将元素x插入在k节点位置上 
	scanf("%d %d",&k,&x);
	L3=Insert(L1,k,x);
	Print(L3);
	//printf("\n");
	
	//将k节点的值修改为x 
	scanf("%d %d",&k,&x);
	Replace(L1,k,x);
	Print(L1);
	printf("\n");
	
	//删除指定元素x 
	scanf("%d",&x);
	Delete(L1,x);
	Print(L1);
	printf("\n");
	
	//按照序号i查找元素值
	List p; 
	scanf("%d",&x);
	p=Getelem(L1,x);
	printf("%d",p->data);
	printf("\n");
	
	//按照元素值查找
	List q; 
	scanf("%d",&x);
	q=Locate(L1,x);
	printf("%d",q->data);
	
 	return 0; 
} 
