#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class ICallback {
public:
	ICallback() {
	}
	virtual ~ICallback() {
	}
	
	virtual void onFailure(string*  msg) = 0;
	virtual void onSuccess(string* msg) = 0;
};

class Task {
public:
	Task(string& url, ICallback* callback);
	virtual ~Task();
	virtual void onResult(string* msg);

    string& getURL();
private:
	string mUrl;
	ICallback* mCallback;
};

#endif