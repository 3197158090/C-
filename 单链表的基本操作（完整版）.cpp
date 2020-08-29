#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{ 
    int data; 
	struct Node *next;
}Node,*List; 

/*��������*/ 
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

//��ӡ���� 
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

//��ת���� 
List Reverse(List head) 
{
	//��֪������ 
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
	/*˫ָ�뷨*/ 
	Node *cur=NULL,*pre=head;//curΪ�µ��������� ,preΪ��ǰ����ӵ�������Ľڵ� 
	while(pre!=NULL){
		Node *tmp=pre->next; //����pre->next �� 
		pre->next=cur;
		cur=pre;
		pre=tmp;
	}
	return cur;
	/*�ݹ鷨*/
	if(head==NULL||head->next==NULL){
		return head;
	}
	List ret=Reverse(head->next);
	head->next->next = head;
    head->next = NULL;
    return ret;
	
}

//��Ԫ��x����ָ��λ��k��  /* ���� */
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

//�޸������е�ĳ��ֵ, �������е�aֵ�޸�Ϊbֵ   /*��*/ 
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

//ɾ�������е�ĳ��Ԫ��x             /*ɾ*/ 
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
//���Ҳ��� 
//�����i���ҽڵ�ֵ
List Getelem(List head,int i){
	int num=1;          //��������ʼ��Ϊ1
	List p=head;  //ͷ���ָ�븳��p
	while(num<i&&p->next!=NULL){
		p = p->next;
		num++;
	}
	if(num==i){			//��i����0������ͷ���
		return p;	
	}
	else
		return NULL;
}

//��Ԫ��ֵx���ҽڵ�
List Locate(List head,int x){
	List p=head->next;     //ͷ���ָ�븳��p
	while(p!=NULL&&p->data!=x){
		p = p->next;
	}
	return p;	
} 

/*��ȡ������*/
//��ȡ��ͷ���ĳ��� 
int Length1(List head){
	List p = head;
	int j=0;
	while(p->next){
		p = p->next;
		j++;
	}
	return j; 
}

//��ȡ����ͷ���ĳ��� 
int Length2(List head){
	List p = head;  //�ǿձ���ָ��ľ��ǵ�һ�����
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
	//�������� 
	L1 = CreateList(); 
	Print(L1); 
	printf("\n");
	
	//��������� 
	int length;
	length=Length2(L1);//��ͷ���ĳ��ȱȲ���ͷ���ĳ�����1 
	printf("%d",length);
	printf("\n");
	
	//��ת���� 
	L2 = Reverse(L1); 
	Print(L2); 
	printf("\n");
	
	//��Ԫ��x������k�ڵ�λ���� 
	scanf("%d %d",&k,&x);
	L3=Insert(L1,k,x);
	Print(L3);
	//printf("\n");
	
	//��k�ڵ��ֵ�޸�Ϊx 
	scanf("%d %d",&k,&x);
	Replace(L1,k,x);
	Print(L1);
	printf("\n");
	
	//ɾ��ָ��Ԫ��x 
	scanf("%d",&x);
	Delete(L1,x);
	Print(L1);
	printf("\n");
	
	//�������i����Ԫ��ֵ
	List p; 
	scanf("%d",&x);
	p=Getelem(L1,x);
	printf("%d",p->data);
	printf("\n");
	
	//����Ԫ��ֵ����
	List q; 
	scanf("%d",&x);
	q=Locate(L1,x);
	printf("%d",q->data);
	
 	return 0; 
} 
