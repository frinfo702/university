// 参考：
// https://daeudaeu.com/c-queue-ptr/
// https://daeudaeu.com/stack_queue/ 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

// ノード構造体 
struct NODE {
    int data;
    struct NODE* next; // 次のノードのアドレス
};

// キューの構造体 
struct QUEUE {
    struct NODE* head; // キューの先頭を指すポインタ 
    struct NODE* tail; // キューの最後尾を指すポインタ 
};

// キューを初期化する関数 
void initQueue(struct QUEUE* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

// キューの終了処理をする関数 
void finishQueue(struct QUEUE* queue) {
    struct NODE* p, * next;

    // キュー内の全ノードをdelete 
    p = queue->head;
    while (p != NULL) {
        next = p->next;
        delete p;
        p = next;
    }
}

// エンキューする関数 
void enqueue(struct QUEUE* queue, int input) {

    struct NODE* node;

    // 新しいノードのメモリを確保 
    node = new (struct NODE);

    // メモリが足りなければ終了 
    if (node == NULL) {
        printf("メモリが確保できないためエンキューできません\n");
        return;
    }

    // 追加したノードデータを格納 
    node->data = input;

    // 次のノードはないのでNULLを設定 
    node->next = NULL;

    // キュー（行列）が空の場合 
    if (queue->head == NULL && queue->tail == NULL) {
        // 先頭と最後尾は作成したノードになる
        queue->head = node;
        queue->tail = node;
        return;
    }

    //// 空でない場合はキューの最後尾にnodeを追加 
    // 最後尾ノードの次のノードに追加したノードを指定する 
    queue->tail->next = node;

    // tailを追加したノードで置き換えて追加完了
    queue->tail = node;
}

// デキューする関数 
int dequeue(struct QUEUE* queue) {
    int ret = 0;
    struct NODE* oldHead;

    // キューが空なら何もせずに関数終了 
    if (queue->head == NULL) {
        printf("キューが空です\n");
        return -1;
    }

    // headの指すノードからデータを取得 
    ret = queue->head->data;

    // 取り出すとキューが空になる場合 
    if (queue->head == queue->tail) {
        // headの指すノードをdelete 
        delete queue->head;

        // headとtailにNULLを指させる 
        queue->head = NULL;
        queue->tail = NULL;

        return ret;
    }

    //// 取り出してもキューが空にならない場合 
    // headのアドレスをoldHeadに退避 
    oldHead = queue->head;

    // headに、headが指すノードの次のノードを指させる 
    queue->head = queue->head->next;

    // デキューしたノード（元々のhead）を解放 
    delete oldHead;

    return ret;
}

// キューの中身を表示 
void printQueue(struct QUEUE* queue) {
    struct NODE* p;

    printf("\n------------------------------\n");
    printf("先頭 [ ");
    p = queue->head;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
        if (p != NULL) printf(" | ");
    }
    printf(" ] 最後尾");
    printf("\n------------------------------\n\n");
}

int main(void) {

    string s;
    int input;
    int output;
    struct QUEUE queue;

    // キューを初期化 
    initQueue(&queue);

    int cust_count = 0;
    int timer_count = 0; // 会計時間の計測用
    while (!_kbhit() || (_getch() != 0x0D)) { // [Enter]でループ終了

        if ((cust_count % 3) == 0) { // 3秒ごとにお客様が並んでくる
            input = rand() % 5 + 1; // 1-5秒の会計時間になるように
            printf("%dのお客様が待ち行列に入られました\n", input);
            enqueue(&queue, input);
        }

        if (queue.head) { // 待ち行列にお客様がいるとき
            // 先頭のお客様の処理時間を見る
            int t = queue.head->data;
            if (t > timer_count) { // まだ時間がたっていない
                timer_count++; // 1秒に1回増える
            }
            else { // 会計が終わる時間経過した
                output = dequeue(&queue);
                if (output != -1) {
                    printf("%dのお客様の会計が終わりました\n", output);
                }
                timer_count = 0; // 会計時間カウントをリセット
            }
        }

        printQueue(&queue); // 現在の状態表示

        Sleep(1000); // 1秒スリープ
        cust_count++;
    }

    // 最後にキューのノードを全て解放 
    finishQueue(&queue);

    return 0;
}