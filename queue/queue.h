//queue.h: Include Queue class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __QUEUE__
#define __QUEUE__

class Queue {
    private:
    int *array;     //Queue array

    int front;      //First element's index
    int rear;       //Last element's index

    int size;       //Total size of queue array
    bool lastOp;    //Represent last operation(1: enqueue, 0: dequeue)

    public:
    //"Queue" constructor function: Dynamically allocate the array with "s"
    /* Parameter type: int, Return type: X */
    Queue(int s);

    //"~Queue" destructor function: Delete Queue class
    /* Parameter type: void, Return type: X */
    ~Queue();

    //"status" function: Return the status of queue array(empty:-1, enough space:0, full:1)
    /* Parameter type: void, Return type: int */
    int status();

    //"enqueue" function: Insert "value" into the queue array and return the status(0: complete, -1: failed)
    /* Parameter type: int, Return type: int */ 
    int enqueue(int value);

    //"dequeue" function: Delete a value in queue array and return the value/status
    /* Parameter type: void, Return type: int */
    int dequeue();

    //"print" function: Print current status of this queue
    /* Parameter type: void, Return type: void */
    void print();
};

#endif