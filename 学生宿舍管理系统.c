/*
功能:实现简单的学生宿舍基本信息管理，
宿舍的基本信息包括楼号、房间号、面积、所容纳人数、已入住人数等。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(LNode) //结点结构定义


int seat;   //全局变量 

typedef struct LNode{ //宿舍系统结点
	int buildNumber;   //楼号    
	int roomNumber;    //房间号 
	int area;    //面积 
	int conPerson; //所容纳人数
	int inPerson;  //已入住人数  
	    
	struct LNode *next;  //指针域 
} LNode, *LinkList;

// 菜单
void menu(){
	printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("￥                                          欢迎使用                                             ￥\n");
	printf("￥                                     **学生宿舍管理系统**                                      ￥\n");
	printf("￥                                    **********************                                     ￥\n"); 
	printf("￥                                      [1]录入并初始化宿舍信息                                	 ￥\n");
	printf("￥                                      [2]删除宿舍信息                                      	 ￥\n");
	printf("￥                                      [3]查询宿舍信息                                      	 ￥\n");
	printf("￥                                      [4]修改宿舍信息                                      	 ￥\n");
	printf("￥                                      [5]浏览宿舍信息                                      	 ￥\n");
	printf("￥                                      [6]添加宿舍信息                                     	 ￥\n");
	printf("￥                                      [7]按入住人数排序                                    	 ￥\n");
	printf("￥                                      [0]退出系统                                              ￥\n");
	printf("￥                                                                                               ￥\n"); 
	printf("***************************************************************************************************\n\n"); 
	printf("                                            选择命令：");
} 

 
//打印头结点地址为L的链表，查看宿舍信息 
 void printList(LinkList L){    
	
	LinkList p = L; //p指向L，即头结点 
	
    printf("\n--------------------------------------------------------\n");
    printf("楼号 	宿舍号	  面积	  所容纳人数 	已入住人数\n");
    printf("----------------------------------------------------------\n");
	if(L == NULL || L->next == NULL){
		printf("该宿舍管理系统中没有信息！！！\n");
	} else{
		while(p->next != NULL){
			printf("%d 	 %d	   %d	     %d 	    %d\n", p->next->buildNumber, p->next->roomNumber, p->next->area, p->next->conPerson, p->next->inPerson);
			p = p->next;
		}
	}
	printf("----------------------------------------------------------\n");
	return;
} 


//查找位于当前地址元素的前一元素的地址
//LinkList prior(LinkList L, LinkList p){  
//	
//} 


//添加一个元素
void insertElem(LinkList L, LinkList Elem){  
	LinkList p = L;
	while(p->next != NULL){     //p->next是指向了第一个结点 
		p = p->next;
	}
	p->next = Elem;
	Elem->next = NULL;
//	p = p->next; 
	printf("\n");

//	if(p != NULL){
//		p->next = Elem;
//		Elem->next = NULL;
//		p = p->next;
//	}
} 


//创建一个存放信息表，返回头结点地址,输入-1结束 
LinkList creatIncreLink(){  
	LinkList L, p;
//	LinkList s = L;
	int res = 1;  //res让输入表示循环是否终止 
	int buildNumber;   //楼号    
	int roomNumber;    //房间号
	int area;    //面积 
	int conPerson; //所容纳人数
	int inPerson;  //已入住人数  
 	
	L = (LinkList)malloc(LEN);  //生成新的结点作为头结点，用头指针指向头结点
	L->next = NULL; //置空头结点的指针域，即首元结点为NULL 
	
//	printf("请输入楼号：");
//	scanf_s("%d", &buildNumber);
//	printf("请输入宿舍号：");
//	scanf_s("%d", &roomNumber);
//	printf("请输入面积：");
//	scanf_s("%f", &area);
//	printf("请输入所容纳人数：");
//	scanf_s("%d", &conPerson);
//	printf("请输入已入住人数：");
//	scanf_s("%d", &inPerson);  
	
	
	while(res >= 0){
		
		printf("请输入楼号：");
		scanf_s("%d", &buildNumber);
		printf("请输入宿舍号：");
		scanf_s("%d", &roomNumber);
		printf("请输入面积：");
		scanf_s("%d", &area);
		printf("请输入所容纳人数：");
		scanf_s("%d", &conPerson);
		printf("请输入已入住人数：");
		scanf_s("%d", &inPerson); 
		
		p = (LinkList)malloc(LEN);  //创建新的结点
		p->buildNumber = buildNumber;
		p->roomNumber = roomNumber;
		p->area = area;
		p->conPerson = conPerson;
		p->inPerson = inPerson;
		
		insertElem(L, p);

//		s->next = p;
//		p->next = NULL;
//		s = p;
		
		printf("请输入是否还要添加,-1退出！");
		scanf_s("%d", &res);
		
		
		
		
//		if(res == -1){
//			break;
//		}
	
	}
	return (L);
}
	
	

// 从系统中删除第i个元素
void deleteElem(LinkList L, int i){  
	LinkList p = L, q;
	int j = 0;
	//先查找出来这个元素 
	while(p->next && j < i-1){
		p = p->next;
		j++;
	}
	//判断i是否合法，i既不能大于元素的个数，也不能小于等于0
	if(!(p->next)){
		printf("第%d个元素删除失败\n", i); //因为后面没结点的值了 
		return;
	} 
	q = p->next;
	p->next = q->next;
	free(q);  //释放删除的结点
} 


// 按房间号查询 
int searchNum(LinkList L, int n){
	//先查找出来然后再显示
	LinkList p = L->next;
	int flag = 0;
	if(L->next == NULL || L == NULL){
		printf("该宿舍系统中没有元素，查找失败\n");
	} else{
		while(p != NULL){
			if(p->roomNumber == n){
				printf("楼号 	房间号	  面积	  所容纳人数 	已入住人数\n");
				printf("%d 	 %d	   %d	     %d 	    %d\n", p->buildNumber, p->roomNumber, p->area, p->conPerson, p->inPerson);
				flag = 1;
			}
			p = p->next;
		}
	}
	return flag;
} 


// 按房间号删除
int delNum(LinkList L, int n){
	int res = 1, flag = 0;
	LinkList p = L->next; //指针p指向首元结点
	if(L->next == NULL){
		printf("该宿舍系统中没有元素，删除失败\n"); 
	}else{
		while(p != NULL){
			if(p->roomNumber == n){
				p = p->next;
				deleteElem(L, res);
				flag = 1;
			}else{
				p = p->next;
				res++;
			} 
		}
		printf("删除成功！\n");
	}
	return flag;
} 


//按房间号修改元素
int reviseRoom(LinkList L, int n){
	int flag = 0;
	int buildNumber;   //楼号    
	int roomNumber;    //房间号
	int area;    //面积 
	int conPerson; //所容纳人数
	int inPerson;  //已入住人数  
	
	LinkList p = L->next;
	if(L->next == NULL || L == NULL){
		printf("该宿舍系统中没有元素，查找失败\n"); 
	}else{ //先找到要修改的房间号 
		while(p != NULL){
			if(p->roomNumber == n){ //查找成功开始修改 
				printf("请输入修改后楼号：");
				scanf_s("%d", &buildNumber);
				printf("请输入修改后宿舍号：");
				scanf_s("%d", &roomNumber);
				printf("请输入修改后面积：");
				scanf_s("%d", &area);
				printf("请输入修改后所容纳人数：");
				scanf_s("%d", &conPerson);
				printf("请输入修改后已入住人数：");
				scanf_s("%d", &inPerson); 
				
				p->buildNumber = buildNumber;
				p->roomNumber = roomNumber;
				p->area = area;
				p->conPerson = conPerson;
				p->inPerson = inPerson;
				
				printf("修改后此信息为：\n");
				printf("楼号 	房间号	  面积	  所容纳人数 	已入住人数\n");
				printf("%d 	 %d	   %d	     %d 	    %d\n", p->buildNumber, p->roomNumber, p->area, p->conPerson, p->inPerson);
				
				flag = 1;
			}
			p = p->next;
		}
	}
	return flag;
} 


//已有信息基础上添加信息
void addNum(LinkList L){
	LinkList p;
	p = (LinkList)malloc(LEN);
	
	int buildNumber;   //楼号    
	int roomNumber;    //房间号
	int area;    //面积 
	int conPerson; //所容纳人数
	int inPerson;  //已入住人数  
	//输入新结点的信息
	printf("请输入楼号：");
	scanf_s("%d", &buildNumber);
	printf("请输入宿舍号：");
	scanf_s("%d", &roomNumber);
	printf("请输入面积：");
	scanf_s("%d", &area);
	printf("请输入所容纳人数：");
	scanf_s("%d", &conPerson);
	printf("请输入已入住人数：");
	scanf_s("%d", &inPerson); 
	
	p->buildNumber = buildNumber;
	p->roomNumber = roomNumber;
	p->area = area;
	p->conPerson = conPerson;
	p->inPerson = inPerson; 
	
	insertElem(L, p);  // 插入信息到L链表末尾 
	
	printf("添加后宿舍信息为：");
	printList(L);
	
}
 

//按已入住人数排序 
void sortNum(LinkList L){
	int i, count = 0, num; //count记录链表结点个数,num进行内层循环 
	LinkList p, q, tail; //创建三个指针，进行冒泡排序
	p = L; 
	
	int buildNumber;   //楼号    
	int roomNumber;    //房间号
	int area;    //面积 
	int conPerson; //所容纳人数
	int inPerson;  //已入住人数  
	
	//计算结点个数
	while(p->next != NULL){
		count++;
		p = p->next;
	} 
	
	if(L->next == NULL || L == NULL || L->next->next == NULL){
		printf("该宿舍系统中元素小于2，无法排序\n"); 
	}else{
		for(i=0; i<count-1; i++){
			num = count - i - 1; //记录每层循环需要的次数
			q = L->next; //指向首元结点
			p = q->next; //指向p后一个结点
			tail = L; //让 tail始终指向p前一个结点，方便交换也方便进一步操作
			while(num--){ //内存循环
				if(q->inPerson > p->inPerson){ //条件满足则交换指针 
					q->next = p->next;
					p->next = q;
					tail->next = p;
				}
				tail = tail->next;
				q = tail->next;  //q指针在tail和p的中间 
				p = q->next;
			} 
		} 
	} 
	
} 


//主函数
int main(){
	LinkList L = NULL, p;
	int flag = 0, menuNum;  //menuNum指的是菜单选项 ,flag表示链表中是否有信息 
	char temp;
	system("color 1f");
	menu();     //菜单显示 
	
	scanf_s("%d",&menuNum);
	//开始执行
	while(menuNum){
		switch(menuNum){
			case 1:{
				L = creatIncreLink();
				printf("\n建立宿舍信息表");
				printList(L);
				break;
			}
			
			case 2:{
				int n, f;
				printf("请输入要删除的宿舍号：");
				scanf_s("%d", &n);
				f = delNum(L, n);
				if(f != 0){
					printf("删除后：\n");
					printList(L);
				}else{
					printf("无该宿舍号，删除失败！\n");
				}
				break; 
			}
			
			case 3:{
				int room, s;
				printf("请输入要查找的房间号：");
				scanf_s("%d", &room);
				s = searchNum(L, room);
				if(s == 0){
					printf("没有此房间，查找失败！\n");
				}
				break;
			}
			
			case 4:{
				int room, s;
				printf("请输入要修改的房间号：");
				scanf_s("%d", &room);
				s = reviseRoom(L, room);
				if(s == 0){
					printf("没有此房间，修改失败！\n");
				}
				break;
			}
			
			case 5:{
				printf("当前宿舍信息如下：");
				printList(L);
				break;
			}
			
			case 6:{
				addNum(L);
				break;
			} 
			
			case 7:{
				printf("排序后宿舍信息如下：");
				sortNum(L);
				printList(L);
				break;
			}
			
			case 0:{
				exit (0);
			}
			
			default:{
				printf("\n没有此功能，重新输入！");
			}
			
			
		}
		printf("\n选择功能：");
		scanf_s("%d",&menuNum);
	}
	
	return 0;
} 






























































 
 
