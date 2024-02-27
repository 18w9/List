#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
    int data;
    struct _node* next;
} Node;
//������ͷ
Node* creatList()
{
    Node* headNode = (Node*)malloc(sizeof(Node));
    //����ʹ��ǰ���뱻��ʼ��
    //headNode->data = 1;  �����ձ�ͷ
    headNode->next = NULL;

    //���ر�ͷ��ַ
    return headNode;
}
//�����ڵ�
Node* creatNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    //ͨ���������β�д��ڵ������
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
//����
//ͷ�巨
void insertNodeByHead(Node* headNode, int data)
{
    //��������Ľڵ㣬�����ڵ��ͬʱ����������ֵ
    Node* newNode = creatNode(data);
    newNode->next = headNode->next;//��ʱnewNode��>next ==NULL
    headNode->next = newNode;
}
//β�巨
void insertNodeByTail(Node* headNode, int data)
{
    Node* newNode = creatNode(data);
    //�ҵ���β
    Node* tailNode = headNode;
    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;

    }
    tailNode->next = newNode;
    //�ҵ���β
}
//ָ��λ�ò���
void insertNodeByPos(Node* headNode, int insertData, int posData)
{
    Node* posNodeFront = headNode;//Ŀ��ڵ��ǰ���ڵ�
    Node* posNode = headNode->next;//Ŀ��ڵ�
    if (posNode == NULL)
    {
        printf("����Ϊ��\n");
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
                printf("δ�ҵ�������\n");
                return;
            }
        }
        Node* newNode = creatNode(insertData);
        newNode->next = posNode;
        posNodeFront->next = newNode;
    }
}
//ɾ��
//��ͷɾ��
void deleteNodeByHead(Node* headNode)
{
    Node* deleteNode = headNode->next;
    headNode->next = deleteNode->next;
    free(deleteNode);
    deleteNode = NULL;
}
//��βɾ��
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
//ָ��λ��ɾ��
void deleteNodeByPos(Node* headNode, int posData)
{
    Node* posNode = headNode->next;
    Node* posNodeFront = headNode;
    if (posNode == NULL)
        printf("�޷�ɾ��������Ϊ�գ�\n");
    else
    {
        while (posNode->data != posData)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("û���ҵ������Ϣ���޷�ɾ����\n");
                return;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        posNode = NULL;
    }
}
//�޸�
void changeNode(Node* headNode, int changeData, int posData)
{
    Node* p = headNode->next;
    if (p == NULL)
    {
        printf("����Ϊ��.\n");
        return;
    }
    else
    {
        while (p->data != posData)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ�������.\n");
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
    printf("�����������޸ĵ����ݣ�\n");
    scanf_s("%d", &posData);
    printf("�������޸ĺ�����ݣ�\n");
    scanf_s("%d", &changeData);
    if (p == NULL)
    {
        printf("����Ϊ��.\n");
        return;
    }
    else
    {
        while (p->data != posData)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("û���ҵ�������.\n");
                return;
            }
        }
        p->data = changeData;
    }
}
//��ѯ
void findNode(Node* headNode, int findData)
{
    Node* p = headNode;
    printf("��������Ҫ��ѯ�����ݣ�\n");
    scanf_s("%d", &findData);
    if (p->next == NULL)
    {
        printf("����Ϊ��!\n");
    }
    else
    {
        while (p->data != findData)
        {
            p = p->next;
            if (p->next == NULL)
            {
                printf("û���ҵ�������!\n");
                return;
            }
        }
        printf("Ŀ������:%d�����������У�\n", p->data);
    }
}
//��������
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
//��ӡ
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
    printf("�������������ز���\n");
    printf("--------------------\n");
    printf("--------------------\n");
    Node* list = creatList();
    printf("ԭʼ����\n");
    insertNodeByHead(list, 1);
    printList(list);
    printf("��ͷ�����루����\n");
    insertNodeByHead(list, 2);
    insertNodeByHead(list, 3);
    printList(list);
    printf("ָ��λ��ɾ��������2��\n");
    deleteNodeByPos(list, 2);
    printList(list);


    printf("��β�����루˳��\n");
    insertNodeByTail(list, 4);
    insertNodeByTail(list, 5);
    insertNodeByTail(list, 6);
    printList(list);
    printf("��ͷɾ��\n");
    deleteNodeByHead(list);
    printList(list);

    printf("ָ��λ�ò��루��5��ǰ�����666��\n");
    insertNodeByPos(list, 666, 5);
    printList(list);
    printf("��βɾ��\n");
    deleteNodeByTail(list);
    printList(list);

    printf("ָ��λ���޸����ݣ���666�޸ĳ�888��\n");
    changeNode(list, 888, 666);
    printList(list);
    changeNodeSecond(list);
    printList(list);

    printf("��ѯ����\n");
    int findData = 0;
    findNode(list, findData);
    printList(list);

    printf("��������\n");
    reverse(list);
    printList(list);
    system("pause");
    return 0;
}
