/**
* Copyright: Copyright (c) 2018 angeltears-hyj, All right reserved.
* 
* @Functional description:
* @Author : angeltears-onter
* @Date : 18-9-20.
* @package : Btclient
*/

#ifndef BTCLIENT_LOG_H
#define BTCLIENT_LOG_H

#include <muduo/base/LogFile.h>
#include <muduo/base/Logging.h>
#include <stdarg.h>
#define BUFFSIZE 4000

class argBuff
{
public:
    argBuff():length_(0){}
    static argBuff& set(char * fmt, ...)
    {
        argBuff arg;
        va_list ap;
        va_start(ap, fmt);
        int length = vsnprintf(arg.data(), sizeof buf_, fmt, ap);
        arg.setlength(length);
        va_end(ap);
    }
    char *data()
    { return buf_; }
    int length()
    { return length_; }
    void setlength(int length)
    { length_ = length; }
private:
    char buf_[BUFFSIZE];
    int length_;
};

inline muduo::LogStream& operator<<(muduo::LogStream & s, argBuff& buf )
{
    s.append(buf.data(), buf.length());
    return s;
}

#endif //BTCLIENT_LOG_H
