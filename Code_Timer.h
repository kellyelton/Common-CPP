#pragma once
#ifndef __Code_Timer__
	#define __Code_Timer__
	#include <sys/timeb.h>
		struct Code_Timer
		{
			unsigned long milliseconds;
			unsigned long seconds;
			struct timeb start_t;
			struct timeb end_t;
#ifdef __cplusplus
			void End()
			{
				ftime(&this->end_t);
				this->seconds = this->end_t.time - this->start_t.time;
				this->milliseconds = (this->seconds * 1000) + (this->end_t.millitm - this->start_t.millitm);
			}
			void Start()
			{
				ftime(&this->start_t);
			}
#endif
		};
#pragma warning(push)
#pragma warning(disable : 4244)
		void End_CT(Code_Timer *This)
		{
			ftime(&This->end_t);
			This->seconds = This->end_t.time - This->start_t.time;
			This->milliseconds = (This->seconds * 1000) + (This->end_t.millitm - This->start_t.millitm);
		}
#pragma warning(pop)
		void Start_CT(Code_Timer *This)
		{
			ftime(&This->start_t);
		}
#endif