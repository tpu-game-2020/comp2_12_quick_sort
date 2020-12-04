// src.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "../include/libsort.h"

int main()
{
	// 初期化
	const int NUM = 100000;
	array* a = create(NUM);

	for (int i = 0; i < NUM; i++) {
		a->nodes[i].key = rand();
	}

	// ソート
	quick_sort(a);

	// 結果の検証
	for (int i = 0; i < a->num; i++) {
		std::cout << a->nodes[i].key << std::endl;
	}

	// 片付け
	finalize(a);
}
