//
//  main.c
//  Circular_Linked_List
//
//  Created by yujin on 2020. 5. 16..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 이 리스트는 head가 NULL일 때, 비어있음을 전재로 함.
typedef struct {
    ListNode* head;
} CListType;

// 원형 링크드 리스트 초기화 함수
void init_list(CListType* list)
{
    list->head = NULL;
}

// 리스트를 출력하는 함수
void print_list(CListType* list)
{
    ListNode* current = list->head;

    if (current == NULL) {  // 리스트가 비어있을때, head가 NULL임
        printf("리스트가 비어있습니다!!\n");
        return;
    }

    do {
        printf("%d->", current->data);
        current = current->link;
    } while (current != list->head);

    printf("\n");
}

int get_size(CListType* list)
{
    ListNode* current = list->head;
    int count = 0;

    if (current == NULL) {  // 리스트가 비어있을때, head가 NULL임
        return 0;
    }

    do {
        count++;
        current = current->link;
    } while (current != list->head);

    return count;
}

// 어떤 노드 다음에 새로운 데이터를 삽입하는 함수
ListNode* insert_next(CListType* list, ListNode* pos, element data)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = data;

    if (pos == NULL) {
        list->head = new_node;  // head에 새로운 노드를 할당함
        new_node->link = new_node;  // head의 링크가 자기 자신을 가리킴
    }
    else {
        ListNode* next = pos->link;  // pos의 링크가 원래 가리키고 있던 노드
        pos->link = new_node;       // pos의 링크를 새로운 노드로 할당
        new_node->link = next;      // 새로운 노드의 링크를 pos가 원래 가리키고 있던 노드로 할당
    }

    return new_node;
}

ListNode* insert_prev(CListType* list, ListNode* pos, element data)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = data;

    if (pos == NULL) {
        list->head = new_node;
        new_node->link = new_node;
    }
    else {
        ListNode* prev;

        // 전체를 순회하면서 prev에 pos의 이전 노드를 할당함
        for (prev = pos; prev->link != pos; prev = prev->link);

        prev->link = new_node;
        new_node->link = pos;

        // 아래코드를 주석처리하면, insert_prev(&list, list.head, ...) 에 대해, 리스트의 마지막에 삽입함
//        if (pos == list->head) {
//            list->head = new_node;
//        }
    }

    return new_node;
}

// 리스트에서 어떤 data와 일치하는 노드를 반환하는 함수
ListNode* search(CListType* list, element data)
{
    ListNode* current = list->head;

    if (current == NULL) {  // 리스트가 비어있을때, head가 NULL임
        return NULL;
    }

    do {
        if (current->data == data)  // 모든 노드를 순회하면서 current의 data가 data와 일치한지 확인
            return current;
        current = current->link;
    } while (current != list->head);

    return NULL;
}

// 해당 노드를 리스트에서 삭제
ListNode* remove_(CListType* list, ListNode* pos)
{
    if (pos == NULL) return NULL;

    ListNode* prev, * next;
    next = pos->link;

    // 전체를 순회하면서 prev에 pos의 이전 노드를 할당함
    for (prev = next; prev->link != pos; prev = prev->link);

    prev->link = next;  // 이전 노드가 다음 노드를 가리키게 함
    free(pos);  // 지움

    // 만약에 우리가 지우고자하는 노드가 head일경우, 리스트에 헤드가 바뀜을 알려줘야함
    if (pos == list->head) {
        if (next == list->head) {
            list->head = NULL;
            return NULL;
        }
        list->head = next;
    }

    return next;
}

// 리스트의 모든 노드를 해제하는 함수
void free_list(CListType* list)
{
    while (list->head != NULL)
        remove_(list, list->head);
}

int main()
{
    CListType list;
    init_list(&list);

    ListNode* pos;

    pos = insert_next(&list, list.head, 1);
    pos = insert_next(&list, pos, 2);
    insert_next(&list, pos, 3);

    insert_next(&list, search(&list, 3), 4);

    print_list(&list);
    printf("사이즈 = %d\n", get_size(&list));

    remove_(&list, search(&list, 1));

    print_list(&list);

    free_list(&list);

    print_list(&list);
    printf("사이즈 = %d\n", get_size(&list));

    insert_prev(&list, list.head, 1);
    insert_prev(&list, list.head, 2);
    insert_prev(&list, list.head, 3);

    print_list(&list);

    free_list(&list);

    return 0;
}