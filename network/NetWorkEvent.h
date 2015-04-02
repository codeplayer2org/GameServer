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
#include "event2/event.h"
#include "base/Singleton.hpp"
#include "common/Common.h"
#include "port/FileSystem.h"
#include "port/WritableFile.h"
#include "port/Env.h"

#if !defined(LIBEVENT_VERSION_NUMBER) || LIBEVENT_VERSION_NUMBER < 0x02010500
#error "Libevent not found or libevent version too old to supporte. Please get 2.0.22-stable or later"
#endif

#define LIBEVENT_LOG_BUFF_SIZE 32768

class NetWorkEvent : public Singleton<NetWorkEvent> {
    public:
        NetWorkEvent() = default;

        ~NetWorkEvent();

        bool Init(std::string log_file_name = "Log/libevent.log");

    private:
        static void LogCallback(int severity, const char* msg);
        static void FatalCallback(int err);
        static bool AppendLog(const std::string& status, const char* msg, ...);

        static WritableFile* log_file_;
};

WritableFile* NetWorkEvent::log_file_ = NULL;

#define sNetWorkEvent NetWorkEvent::getSingleton()

#endif /* end of include guard: NETWORKEVENT_H_T7FV5Y3S */
