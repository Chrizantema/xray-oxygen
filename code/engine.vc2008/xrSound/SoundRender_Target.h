#ifndef SoundRender_TargetH
#define SoundRender_TargetH
#pragma once

#include "SoundRender.h"

class CSoundRender_Target
{
protected:
	CSoundRender_Emitter*		m_pEmitter;
	bool						rendering;
public:
	float						priority;
protected:
	OggVorbis_File				ovf;
	IReader*					wave;					
	void						attach				();
	void						dettach				();
public:
	OggVorbis_File*				get_data			()	{
		if (!wave)	attach		();
		return &ovf;
	}
public:
								CSoundRender_Target	();
	virtual 					~CSoundRender_Target();

	CSoundRender_Emitter*		get_emitter			()	{ return m_pEmitter;	}
	bool						get_Rendering		()	{ return rendering;	}

	virtual bool				_initialize			()=0;
	virtual void				_destroy			()=0;
	virtual void				_restart			()=0;

	virtual void				start				(CSoundRender_Emitter* E)=0;
	virtual void				render				()=0;
	virtual void				rewind				()=0;
	virtual void				stop				()=0;
	virtual void				update				()=0;
	virtual void				fill_parameters		()=0;
	virtual	void				alAuxInit			(ALuint slot)=0;
};
#endif