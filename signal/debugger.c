/**
*如果在父进程注册一个信号处理，那么
*在fork之后，child 进程会对相应信号作出
* 反应吗？
* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int sig, siginfo_t *info, void* args) {
    if (sig == SIGABRT) {
        printf("pid:%d receive a abort signal", getpid());
        char buf[256];
        int size = sizeof(buf);

        int nptrs = backtrace(&buf, size);
        backtrace_symbols_fd(buf, nptrs, STDOUT_FILENO);
    }
}

void debugger_init() {
    struct sigaction sa;
    int sig = SIGABRT;

    memset(&sa, 0, sizeof(sa));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sig_handler;

    sigaction(sig, &sa, NULL);
}

int main() {
    //debugger_init();
    int pid = fork();
    if (pid == 0) {
        debugger_init();
        printf("child(%d) abort\n", getpid());
        abort();
    } else {
        wait(NULL);
        printf("parent:%d\n", getpid());
    }

    return 0;
}
