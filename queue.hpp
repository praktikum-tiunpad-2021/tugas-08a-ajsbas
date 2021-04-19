#include <iostream>
#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element *next;
  
  Element(T data, int priority){
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
  }
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> newQ;
  newQ.head = nullptr;
  newQ.tail = nullptr;
  return newQ;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> newQ = new Element<T>(value, priority);

  if(q.head == nullptr){
    q.head = newQ;
    q.tail = newQ;
  }
  else{
    ElementPtr<T> pHelp = q.head;
    ElementPtr<T> pHelp2 = nullptr;

    while(pHelp->priority >= priority && pHelp->next != nullptr){
      pHelp2 = pHelp;
      pHelp = pHelp->next;
    }

    if(pHelp == q.head && pHelp->priority < priority){
      newQ->next = pHelp;
      q.head = newQ;
    }
    else if(pHelp == q.tail && pHelp->priority > priority){
      pHelp->next = newQ;
      q.tail = newQ;
    }
    else{
      pHelp2->next = newQ;
      newQ->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delElement;

  if(q.head == nullptr && q.tail == nullptr){
    delElement = nullptr;
  }
  else if(q.head->next == nullptr){
    delElement = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }
  else{
    delElement = q.head;
    q.head = q.head->next;
    delElement -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
