#include <stdio.h>
#include <pthread.h>

#include "DownloadManager.h"

pthread_mutex_t DownloadManager::gLock = PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t DownloadManager::mTaskLock = PTHREAD_RWLOCK_INITIALIZER;

pthread_mutex_t DownloadManager::gThreadLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t DownloadManager::gThreadCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t DownloadManager::gQueueLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t DownloadManager::gQueueCond = PTHREAD_COND_INITIALIZER;

DownloadManager* DownloadManager::gInstance = NULL;

DownloadManager* DownloadManager::getInstance() {
     if (gInstance == NULL) {
         pthread_mutex_lock(&gLock);
		 gInstance = new DownloadManager();
		 pthread_mutex_unlock(&gLock);
	 }

	 return gInstance;
}

DownloadManager::~DownloadManager() {

}

void DownloadManager::addQueue(Task *task) {
    while (!threadStarted) {
        pthread_mutex_lock(&gThreadLock);
        pthread_cond_wait(&gThreadCond, &gThreadLock);
		pthread_mutex_unlock(&gThreadLock);
	}
	
    if (task) {
		pthread_rwlock_wrlock(&mTaskLock);
        isQueueEmptry = mQueue.empty();
		mQueue.push(task);
		pthread_rwlock_unlock(&mTaskLock);

		if (isQueueEmptry) {
			pthread_mutex_lock(&gQueueLock);
			isQueueEmptry = false;
			pthread_cond_signal(&gQueueCond);
		    pthread_mutex_unlock(&gQueueLock);
		}
	}
}

Task* DownloadManager::getTask() {
    Task* tsk;
	pthread_rwlock_wrlock(&mTaskLock);
	tsk = mQueue.front();
	mQueue.pop();
	pthread_rwlock_unlock(&mTaskLock);

	return tsk;
}

DownloadManager::DownloadManager() {
    threadStarted = false;
	isQueueEmptry = true;

	mThread = new DownloadThread();
	mThread->start(this);
}

DownloadThread::DownloadThread() {
    
}

DownloadThread::~DownloadThread() {

}

void DownloadThread::start(void* args) {
    pthread_t thread;
	pthread_create(&thread, NULL, run, args);
}

void* DownloadThread::run(void* args) {
     DownloadManager* dm = (DownloadManager *)args;
	 
	 pthread_mutex_lock(&dm->gThreadLock);
	 dm->threadStarted = true;
	 pthread_cond_signal(&dm->gThreadCond);
	 pthread_mutex_unlock(&dm->gThreadLock);

	 while (1) {
         while (dm->isQueueEmptry) {
             pthread_mutex_lock(&dm->gQueueLock);
			 pthread_cond_wait(&dm->gQueueCond, &dm->gQueueLock);
			 pthread_mutex_unlock(&dm->gQueueLock);
		 }
		 
         Task* task = dm->getTask();
		 string *msg = new string("success");
		 task->onResult(msg);
		 delete task;
		 
		 dm->update();
	 }

	 return NULL;
}

