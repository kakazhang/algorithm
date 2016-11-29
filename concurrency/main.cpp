#include <stdio.h>
#include <string>
#include <unistd.h>

#include "DownloadManager.h"
#include "Task.h"

using namespace std;

class Callback : public ICallback {
public:
    virtual void onFailure(string* msg) {

    }

    virtual void onSuccess(string* msg) {
        printf("receive:%s\n", msg->c_str());

		delete msg;
    }
};

void test() {
    Callback* callback = new Callback();
	string url("www.google.com.hk");
    Task* tsk = new Task(url, callback);

    DownloadManager* dm = DownloadManager::getInstance();

    dm->addQueue(tsk);

    sleep(1);
}

int main() {
    test();

    return 0;
}
