//
//  main.c
//  Doubly_Linked_List
//
//  Created by mac on 2020. 5. 19..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
    element data;
    struct DListNode* prev;
    struct DListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} DListType;

// 이중 연결 리스트 초기화 함수
void init_list(DListType* list)
{
    list->head = (ListNode*)malloc(sizeof(ListNode));  // 리스트의 헤드를 비워둠
    list->head->next = list->head;
    list->head->prev = list->head;
}

// 리스트 출력 함수
void print_list(DListType* list)
{
    ListNode* current = list->head->next;

    if (current == list->head) {    // 노드가 head를 가리키는 경우 (head=?)
        printf("리스트가 비어있습니다!!\n");
        return;
    }

    while (current != list->head) {     // 노드 순회
        printf("<-%d->", current->data);
        current = current->next;
    }

    printf("\n");
}

// 노드 삽입 함수
ListNode* insert_next(DListType* list, ListNode* pos, element data)
{
    if (pos == NULL) return NULL;

    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = data;

    ListNode* after_pos = pos->next;

    pos->next = new_node;
    after_pos->prev = new_node;

    new_node->prev = pos;
    new_node->next = after_pos;

    return new_node;
}

// 노드 삽입 함수
ListNode* insert_prev(DListType* list, ListNode* pos, element data)
{
    if (pos == NULL) return NULL;

    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = data;

    ListNode* before_pos = pos->prev;

    before_pos->next = new_node;
    pos->prev = new_node;

    new_node->prev = before_pos;
    new_node->next = pos;

    return new_node;
}

ListNode* search(DListType* list, element data)
{
    ListNode* current = list->head->next;

    if (current == list->head) {
        return NULL;
    }

    while (current != list->head) {
        if (current->data == data) return current;

        current = current->next;
    }

    return NULL;
}

// 노드 삭제 함수
ListNode* remove_(DListType* list, ListNode* pos)
{
    if (pos == NULL) return NULL;
    if (pos == list->head) return NULL;

    ListNode* before_pos = pos->prev;
    ListNode* after_pos = pos->next;

    before_pos->next = after_pos;
    after_pos->prev = before_pos;

    free(pos);

    return after_pos;
}

// 데이터 갯수
int get_size(DListType* list)
{
    int count = 0;
    ListNode* current = list->head->next;

    while (current != list->head) {
        count++;

        current = current->next;
    }

    return count;
}
// free 함수
void free_list(DListType* list)
{
    ListNode* current = list->head;

    do {
        ListNode* next = current->next;
        free(current);

        current = next;
    } while (current != list->head);
}

int main()
{
    DListType list;
    init_list(&list);

    insert_next(&list, list.head, 1);
    insert_next(&list, list.head, 2);
    insert_next(&list, list.head, 3);

    print_list(&list);
    printf("사이즈 = %d\n", get_size(&list));

    free_list(&list);
    init_list(&list);

    insert_prev(&list, list.head, 1);
    insert_prev(&list, list.head, 2);
    insert_prev(&list, list.head, 3);
    remove_(&list, search(&list, 2));


    print_list(&list);
    printf("사이즈 = %d\n", get_size(&list));

    return 0;
}