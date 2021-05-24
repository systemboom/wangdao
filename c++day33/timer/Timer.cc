 ///
 /// @file    Timer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-07-03 11:12:52
 ///
 
#include "Timer.hpp"

#include <unistd.h>
#include <stdio.h>
#include <sys/timerfd.h>
#include <poll.h>

namespace wd
{

Timer::Timer(TimerCallback && cb, int initialTime,int periodicTime)
: _fd(createTimerfd())
, _initialTime(initialTime)
, _periodicTime(periodicTime)
, _cb(std::move(cb))
, _isStarted(false)
{
	
}

void Timer::start()
{
	if(!_isStarted)
		_isStarted = true;


	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	setTimerfd(_initialTime, _periodicTime);
	while(_isStarted) {
		int nready;
		do {
			nready = ::poll(&pfd, 1, 5000);
		}while(nready == -1 && errno == EINTR);

		if(nready == -1) {
			perror("poll");
			return;
		} else if( nready == 0) {
			printf(">>> poll timeout\n");
			continue;
		} else {
			if(pfd.revents & POLLIN) {
				//定时器周期性执行任务的地方
				handleRead();//水平触发
				if(_cb) 
					_cb();
			}
		}
	}
}

void Timer::stop()
{
	setTimerfd(0, 0);
	if(_isStarted)
		_isStarted = false;
}

int Timer::createTimerfd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(-1 == fd) {
		perror("timerfd_create");
	}
	return fd;
}

void Timer::setTimerfd(int initialTime, int periodicTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = periodicTime;
	value.it_interval.tv_nsec = 0;

	int ret = ::timerfd_settime(_fd, 0, &value, nullptr);
	if(ret < 0) {
		perror("timerfd_settime");
	}
}

void Timer::handleRead()
{
	uint64_t howmany;
	int ret = ::read(_fd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		perror("read");
	}
}

}//end of namespace wd
