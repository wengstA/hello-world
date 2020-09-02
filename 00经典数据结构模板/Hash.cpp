#include"malloc.h" /* malloc()�� */
#include"stdlib.h" /* exit() */
#include"stdio.h"
#define EQ(a,b) ((a)==(b))
#define SUCCESS 1
#define UNSUCCESS 0
#define NULLKEY -1 /*��ϣ����Ԫ��ʱֵΪ-1*/
typedef int ElemType;
int length;
typedef struct
{
    ElemType* elem; /* ����Ԫ�ش洢��ַ����̬�������� */
    int count; /* ��ǰ����Ԫ�ظ��� */
}HashTable;

void InitHashTable(HashTable* H)
{ /* �������: ����һ������Ϊlength�Ĺ�ϣ��,lengthΪȫ�ֱ��� */
    int i;
    (*H).count = 0; /* ��ǰԪ�ظ���Ϊ0 */             
    (*H).elem = (ElemType*)malloc(length * sizeof(ElemType));
    if (!(*H).elem)
        exit(0); /* �洢����ʧ�� */
    for (i = 0; i < length; i++)
        (*H).elem[i] = NULLKEY; /* δ���¼�ı�־ */
}
unsigned Hash(ElemType K)
{ /* һ���򵥵Ĺ�ϣ����*/
    return (3 * K) % length;
}
void collision(int* p) /*����̽����ɢ�� */
{ /* ���Ŷ�ַ�������ͻ */
    *p = (*p + 1) % length;

}
int SearchHash(HashTable H, ElemType K, int* p, int* c)
{  /* �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��,�����ҳɹ�,��pָʾ�������� */
   /* Ԫ���ڱ���λ��,������SUCCESS;����,��pָʾ����λ��,������UNSUCCESS */
   /* c���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο����㷨9.17 */
    *p = Hash(K); /* ��ù�ϣ��ַ */
    while (H.elem[*p] != NULLKEY && !EQ(K, H.elem[*p]))
    { /* ��λ�������м�¼,���ҹؼ��ֲ���� */
        (*c)++;
        if (*c < length)
            collision(p); /* �����һ̽���ַp */
        else
            break;
    }
    if EQ(K, H.elem[*p])
        return SUCCESS; /* ���ҳɹ���p���ش�������Ԫ��λ�� */
    else
        return UNSUCCESS; /* ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)��p���ص��ǲ���λ�� */
}
int InsertHash(HashTable* H, ElemType e)
{ /* ���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У������ز��ҳ��� */
    int c, p;
    c = 0;
    if (SearchHash(*H, e, &p, &c))   /* ����������e����ͬ�ؼ��ֵ�Ԫ�� */
        printf("��ϣ��������Ԫ��%d��\n", e);
    else { /* ����e */
        (*H).elem[p] = e;
        ++(*H).count;
    }
    return c + 1; /*���ҳ���Ϊ��ͻ������1*/
}
void TraverseHash(HashTable H)
{ /* ����ϣ��ַ��˳���ӡ��ϣ����Ԫ��λ����X��ʾ */
    int i;
    //printf("HashTable Address:0��%d\n", length - 1);
    for (i = 0; i < length; i++)
        if (H.elem[i] == NULLKEY) /* ������ */
            printf("X ");
        else
            printf("%d ", H.elem[i]);
    printf("\n");
}
main()
{
    float i = 0, j = 0;
    ElemType e;
    HashTable H;
    //printf("Input Table length:");
    scanf("%d", &length);
    InitHashTable(&H);
    //printf("Input key words sequence, -1 conclusion input��");
    scanf("%d", &e);
    while (e != -1)
    {
        j++;  /*j��¼����Ԫ�ظ���*/
        i = i + InsertHash(&H, e);  /*i��¼���ҳ��ȵĺ�*/
        scanf("%d", &e);
    }
    TraverseHash(H);
    printf("Average search length=%f\n", i / j);
}
