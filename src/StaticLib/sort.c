#include "Windows.h"                    // Windows API の機能(NULL)定義
#include <stdbool.h>
#include "../include/libsort.h"

static void swap(node* p1, node* p2)
{
	node tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void quick_sort_sub(node* p, int begin, int end)
{
	/* ソートを行う範囲が１以下の場合 */
	if (begin >= end) 
	{
		return;
	}
	
	node pivot = p[begin];
	int i = begin;
	int j = end;

	while (1)
	{
		while (p[i].key < pivot.key)
		{
			i++;
		}
		while (p[j].key > pivot.key)
		{
			j--;
		}
		if (i >= j)
		{
			break;
		}
		swap(&p[i], &p[j]);
		i++;
		j--;
	}
	quick_sort_sub(p, begin, i - 1);
	quick_sort_sub(p, j + 1, end);
}

// ソート
void quick_sort(array* a)
{
	quick_sort_sub(a->nodes, 0, a->num - 1);
}


//
// 配列の初期化
//
array* create(int num)
{
	array* a = (array*)malloc(sizeof(array));
	if (a == NULL) return NULL;

	a->num = num;
	a->nodes = (node*)malloc(sizeof(node) * num);

	return a;
}


//
// 使用メモリの全解放
//
void finalize(array* a)
{
	free(a->nodes);
	free(a);
}
