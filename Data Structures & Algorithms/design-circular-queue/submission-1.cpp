class MyCircularQueue {
    vector<int> buf;
    int head = 0, cnt = 0;
    public:
    MyCircularQueue(int k) : buf(k) {}
    bool enQueue(int value) {
    if (isFull()) return false;
    buf[(head + cnt) % buf.size()] = value; cnt++;
    return true;
    }
    bool deQueue() {
    if (isEmpty()) return false;
    head = (head + 1) % buf.size(); cnt--;
    return true;
    }
    int Front() { return isEmpty() ? -1 : buf[head]; }
    int Rear() { return isEmpty() ? -1 : buf[(head + cnt - 1) % buf.size()]; }
    bool isEmpty() { return cnt == 0; }
    bool isFull() { return cnt == (int)buf.size(); }
    };