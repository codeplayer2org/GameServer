/*
 * =====================================================================================
 *
 *       Filename:  Thread.h
 *
 *    Description:  Thread
 *
 *        Version:  1.0
 *        Created:  04/24/2015 05:28:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Petrus (), silencly07@gmail.com
 *   Organization:  http://codeplayer.org
 *
 * =====================================================================================
 */
#ifndef THREAD_H_TPCQFSB7
#define THREAD_H_TPCQFSB7

#include <pthread.h>

class ThreadBase {
    public:
        ThreadBase() {}
        virtual ~ThreadBase() {}
        virtual bool Run() = 0;
        virtual void OnShutdown() {}

        pthread_t pthread_id_;
};

class ThreadController {
    public:
        ThreadController() {
            pthread_mutex_init(&mutex_, NULL);
            pthread_cond_init(&cond_, NULL);
            thread_id_ = GenerateThreadId();
        }

        virtual ~ThreadController() {
            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&cond_);
        }

        void Init(pthread_t pthread_id) {
            pthread_id_ = pthread_id;
        }

        void Wait() {
            pthread_mutex_lock(&mutex_);
            pthread_cond_wait(&cond_, &mutex_);
            pthread_mutex_unlock(&mutex_);
        }

        void Signal() {
            pthread_cond_signal(&cond_);
        }

        void Join() {
            pthread_join(pthread_id_, NULL);
        }

        int thread_id() {
            return thread_id_;
        }

    private:
        int GenerateThreadId() {
            int thread_id = ++thread_id_count_;
            return thread_id;
        }

        static volatile int thread_id_count_;

        int thread_id_;
        pthread_t pthread_id_;
        pthread_cond_t cond_;
        pthread_mutex_t mutex_;
};

class Thread {
    public:
        ThreadBase* ExecutionTarget_;
        ThreadController ControlInterface;
};

#endif /* end of include guard: THREAD_H_TPCQFSB7 */
