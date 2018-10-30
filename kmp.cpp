
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

	puts("请输入源字符串：");
	gets(src);
	puts("请输入模式字符串：");
	gets(mdl);

	len = strlen(mdl);
	match(src, mdl, &index);
	printf("%d", index);
	getchar();
	return 0;
}

/* 匹配函数。通过index返回相匹配的字符串首字符在源字符串中的位置，
   通过返回值返回相匹配的字符串首字符的地址。若无相匹配的字符串，则
   index为-1，并返回空指针NULL
 */
void match(const char * szSrc, const char * szModel, int * index)
{
	char * des;
	int	srcIndex = 0;
	int mdlIndex = 0;
	int srcLen = strlen(szSrc);
	int mdlLen = strlen(szModel);
	/* 创建next数组，并初始化 */
	int *next = (int *)malloc(mdlLen * sizeof(int));
	makeNext(szModel, next, mdlLen);
	
	/* 匹配主循环体 */
	while (mdlIndex < mdlLen && srcIndex < srcLen) {
		/* 若对应位置字符匹配则步进1，否则移动szModel */
		if (mdlIndex == -1 || szSrc[srcIndex] == szModel[mdlIndex]) {
			mdlIndex++; srcIndex++;
		} else {
			mdlIndex = next[mdlIndex];
		}
	}

	/* 若mdlIndex未达到串尾，表明szModel未完成匹配。否则即是完成匹配 */
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

	/* 扫描szModel字符串以确定next数组 */
	while (index < len) {
		while (k >= 0 && szModel[index] != szModel[k])
			/* 若不匹配，则移动字符串，同match函数 */
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

