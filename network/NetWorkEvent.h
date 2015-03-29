/*
 * =====================================================================================
 *
 *       Filename:  NetWorkEvent.h
 *
 *    Description:  NetWorkEvent
 *
 *        Version:  1.0
 *        Created:  2015年03月29日 12时28分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Petrus (), silencly07@gmail.com
 *   Organization:  http://www.codeplayer.org
 *
 * =====================================================================================
 */

#ifndef NETWORKEVENT_H_T7FV5Y3S
#define NETWORKEVENT_H_T7FV5Y3S

#include <string>
#include "base/Singleton.hpp"
#include "event2/event.h"

class NetWorkEvent : public Singleton<NetWorkEvent> {
    public:
        NetWorkEvent(std::string log_file_name = "Log/libevent.log");

        ~NetWorkEvent();

    private:
        static void LogCallback(int severity, const char* msg);

        static std::ofstream log_file_;
};

std::ofstream log_file_;

#endif /* end of include guard: NETWORKEVENT_H_T7FV5Y3S */

