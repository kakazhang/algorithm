#include <stdio.h>
#include <string>

#include "Task.h"

using namespace std;

Task::Task(string& url, ICallback *callback)
   :mUrl(url), mCallback(callback)
{

}

Task::~Task() {

}

void Task::onResult(string* msg) {
    if (mCallback != NULL) {
        mCallback->onSuccess(msg);
	}
}

string& Task::getURL() {
    return mUrl;
}
