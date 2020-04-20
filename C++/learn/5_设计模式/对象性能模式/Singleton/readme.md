## 动机
- 一些特殊类，只能让它只有一个实例
- 这是类设计者的责任，而不是使用者的责任

## 背景
其实之前侯捷老师也在他的课程中讲过Singleton，所以这节课应该会听得比较爽

## 操作
- 私有构造函数
- 不是使用if，else来new实例，因为万一多线程中有一个进入if还未构造，另一个又进if构造，然后切回原来的那个构造，就构造出了两个实例了
- 可以加锁-->本质也就是线程级别的if..else,但是锁的代价过高，因为创建过了一次之后，还是有锁存在，导致了读也有锁，很浪费---高并发就更浪费了
- 双判断锁，锁前后都加if判断，这样解决了读锁的问题

但是这里还是有漏洞(2000有研究java的专家发现了这个漏洞),我们认为的指令执行循环是
**先分配内存，然后调用构造new,然后返回地址**
但是CPU实际操作的时候可能重新对操作排序
**先分配内存，然后直接把内存地址返回了，再调用构造new**

这里可能在还没有调用构造函数，然后另一个线程来读取，发现地址不为nullptr，然后就快乐地去使用，但是却导致了程序的崩溃


java，c#给类对象加了volatile关键字，然后这样就禁止了cpu指令对这种对象的构建过程重新排序
vc2005的时候自己加了一个volatile,但这在gnu-c并不能使用，而我们的cpp代码追求跨平台

在c++11之后，就有了跨平台的实现了


```cpp



class Singleton{
private:
    Singleton();
    Singleton(const Singleton& other);
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance=nullptr;

//线程非安全版本
// 单线程环境可以用
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}






//线程安全版本，但锁的代价过高
// 非高并发勉强可用，但仍影响效率
Singleton* Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}









//双检查锁，但由于内存读写reorder不安全
// 有安全问题，不可用
Singleton* Singleton::getInstance() {

    if(m_instance==nullptr){
        Lock lock;
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}








//C++ 11版本之后的跨平台实现 (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}

```