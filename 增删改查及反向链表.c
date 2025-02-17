#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
    int data;
    struct _node* next;
} Node;
//创建表头
Node* creatList()
{
    Node* headNode = (Node*)malloc(sizeof(Node));
    //变量使用前必须被初始化
    //headNode->data = 1;  创建空表头
    headNode->next = NULL;

    //返回表头地址
    return headNode;
}
//创建节点
Node* creatNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    //通过函数的形参写入节点的数据
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
//插入
//头插法
void insertNodeByHead(Node* headNode, int data)
{
    //创建插入的节点，创建节点的同时对其数据域赋值
    Node* newNode = creatNode(data);
    newNode->next = headNode->next;//此时newNode—>next ==NULL
    headNode->next = newNode;
}
//尾插法
void insertNodeByTail(Node* headNode, int data)
{
    Node* newNode = creatNode(data);
    //找到表尾
    Node* tailNode = headNode;
    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;

    }
    tailNode->next = newNode;
    //找到表尾
}
//指定位置插入
void insertNodeByPos(Node* headNode, int insertData, int posData)
{
    Node* posNodeFront = headNode;//目标节点的前驱节点
    Node* posNode = headNode->next;//目标节点
    if (posNode == NULL)
    {
        printf("链表为空\n");
        return;
    }
    else
    {
        while (posNode->data != posData)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("未找到该数据\n");
                return;
            }
        }
        Node* newNode = creatNode(insertData);
        newNode->next = posNode;
        posNodeFront->next = newNode;
    }
}
//删除
//表头删除
void deleteNodeByHead(Node* headNode)
{
    Node* deleteNode = headNode->next;
    headNode->next = deleteNode->next;
    free(deleteNode);
    deleteNode = NULL;
}
//表尾删除
void deleteNodeByTail(Node* headNode)
{
    Node* tailNode = headNode;
    Node* tailNodeFront = NULL;
    while (tailNode->next != NULL)
    {
        tailNodeFront = tailNode;
        tailNode = tailNode->next;
    }
    free(tailNode);
    tailNode = NULL;
    tailNodeFront->next = NULL;
}
//指定位置删除
void deleteNodeByPos(Node* headNode, int posData)
{
    Node* posNode = headNode->next;
    Node* posNodeFront = headNode;
    if (posNode == NULL)
        printf("无法删除，链表为空！\n");
    else
    {
        while (posNode->data != posData)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("没有找到相关信息，无法删除！\n");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        posNode = NULL;
    }
}
//修改
void changeNode(Node* headNode, int changeData, int posData)
{
    Node* p = headNode->next;
    if (p == NULL)
    {
        printf("链表为空.\n");
        return;
    }
    else
    {
        while (p->data != posData)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("没有找到该数据.\n");
                return;
            }
        }
        p->data = changeData;
    }
}
void changeNodeSecond(Node* headNode)
{
    Node* p = headNode->next;
    int changeData, posData;
    printf("请输入你想修改的数据：\n");
    scanf_s("%d", &posData);
    printf("请输入修改后的数据：\n");
    scanf_s("%d", &changeData);
    if (p == NULL)
    {
        printf("链表为空.\n");
        return;
    }
    else
    {
        while (p->data != posData)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("没有找到该数据.\n");
                return;
            }
        }
        p->data = changeData;
    }
}
//查询
void findNode(Node* headNode, int findData)
{
    Node* p = headNode;
    printf("请输入您要查询的数据：\n");
    scanf_s("%d", &findData);
    if (p->next == NULL)
    {
        printf("链表为空!\n");
    }
    else
    {
        while (p->data != findData)
        {
            p = p->next;
            if (p->next == NULL)
            {
                printf("没有找到该数据!\n");
                return;
            }
        }
        printf("目标数据:%d存在于链表中！\n", p->data);
    }
}
//反向链表
Node* reverse(Node* L) {
    Node *prep;
    Node *p;
    Node *q;
    p = L->next;
    q = p->next;
    p->next = NULL;
    while (q) {
        prep = p;
        p = q;
        q = q->next;
        p->next = prep;
    }
    L->next = p;
    return L;
}
//打印
void printList(Node* headNode)
{
    Node* p = headNode->next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(void)
{
    printf("以下是链表的相关操作\n");
    printf("--------------------\n");
    printf("--------------------\n");
    Node* list = creatList();
    printf("原始数据\n");
    insertNodeByHead(list, 1);
    printList(list);
    printf("表头法插入（逆序）\n");
    insertNodeByHead(list, 2);
    insertNodeByHead(list, 3);
    printList(list);
    printf("指定位置删除（数据2）\n");
    deleteNodeByPos(list, 2);
    printList(list);


    printf("表尾法插入（顺序）\n");
    insertNodeByTail(list, 4);
    insertNodeByTail(list, 5);
    insertNodeByTail(list, 6);
    printList(list);
    printf("表头删除\n");
    deleteNodeByHead(list);
    printList(list);

    printf("指定位置插入（在5的前面插入666）\n");
    insertNodeByPos(list, 666, 5);
    printList(list);
    printf("表尾删除\n");
    deleteNodeByTail(list);
    printList(list);

    printf("指定位置修改数据（将666修改成888）\n");
    changeNode(list, 888, 666);
    printList(list);
    changeNodeSecond(list);
    printList(list);

    printf("查询数据\n");
    int findData = 0;
    findNode(list, findData);
    printList(list);

    printf("反向链表\n");
    reverse(list);
    printList(list);
    system("pause");
    return 0;
}
