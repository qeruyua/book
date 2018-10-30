
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_LEN 100
#define MDL_LEN 20

void makeNext(char * szModel, int * next, int len);
void match(char * szSrc, const char * szModel, int * index);

int main(void)
{
	char src[SRC_LEN]n
	char mdl[MDL_LEN];
	int  len;
	int  index;

	puts("������Դ�ַ�����");
	gets(src);
	puts("������ģʽ�ַ�����");
	gets(mdl);

	len = strlen(mdl);
	match(src, mdl, &index);
	printf("%d", index);
	getchar();
	return 0;
}

/* ƥ�亯����ͨ��index������ƥ����ַ������ַ���Դ�ַ����е�λ�ã�
   ͨ������ֵ������ƥ����ַ������ַ��ĵ�ַ��������ƥ����ַ�������
   indexΪ-1�������ؿ�ָ��NULL
 */
void match(const char * szSrc, const char * szModel, int * index)
{
	char * des;
	int	srcIndex = 0;
	int mdlIndex = 0;
	int srcLen = strlen(szSrc);
	int mdlLen = strlen(szModel);
	/* ����next���飬����ʼ�� */
	int *next = (int *)malloc(mdlLen * sizeof(int));
	makeNext(szModel, next, mdlLen);
	
	/* ƥ����ѭ���� */
	while (mdlIndex < mdlLen && srcIndex < srcLen) {
		/* ����Ӧλ���ַ�ƥ���򲽽�1�������ƶ�szModel */
		if (mdlIndex == -1 || szSrc[srcIndex] == szModel[mdlIndex]) {
			mdlIndex++; srcIndex++;
		} else {
			mdlIndex = next[mdlIndex];
		}
	}

	/* ��mdlIndexδ�ﵽ��β������szModelδ���ƥ�䡣���������ƥ�� */
	if (mdlIndex >= mdlLen) {
		*index = srcIndex - mdlLen;
	} else {
		*index = -1; 
	}
}

void makeNext(const char * szModel, int * next, int len)
{
	int index = 0;
	int k = -1;
	next[0] = -1;

	/* ɨ��szModel�ַ�����ȷ��next���� */
	while (index < len) {
		while (k >= 0 && szModel[index] != szModel[k])
			/* ����ƥ�䣬���ƶ��ַ�����ͬmatch���� */
			k = next[k];
		index++; k++;
		/* !!!ATTENTION!!! */
		if (szModel[index] == szModel[k]) {
			next[index] = next[k];
		} else {
			next[index] = k;
		}		
	}
}

