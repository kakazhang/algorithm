#ifndef DOWNLOADMANAGER_h
#define DOWNLOADMANAGER_h
#include <pthread.h>
#include <queue>

#include "Task.h"

using namespace std;

class DownloadThread {
public:
	DownloadThread();
	virtual ~DownloadThread();

	void start(void* args);

protected:
	static void* run(void* args);
};

class DownloadManager {
public:
	static DownloadManager* getInstance();
	virtual ~DownloadManager();
    void addQueue(Task *task);
	Task* getTask();

	void update() {
        isQueueEmptry = mQueue.empty();
	}
	
private:
	DownloadManager();
private:
	static pthread_mutex_t gLock;
	static DownloadManager* gInstance;

    static pthread_mutex_t gThreadLock;
	static pthread_cond_t gThreadCond;
	static pthread_rwlock_t mTaskLock;

    static pthread_mutex_t gQueueLock;
	static pthread_cond_t gQueueCond;
	queue<Task *> mQueue;

    DownloadThread *mThread;
	volatile bool threadStarted;
    volatile bool isQueueEmptry;
	
	friend class DownloadThread;
};

#endif