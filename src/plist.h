/*
*				plist.h
*
* Include file for plist.c.
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	This file part of:	SExtractor
*
*	Copyright:		(C) 1993-2014 Emmanuel Bertin -- IAP/CNRS/UPMC
*
*	License:		GNU General Public License
*
*	SExtractor is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*	SExtractor is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*	You should have received a copy of the GNU General Public License
*	along with SExtractor. If not, see <http://www.gnu.org/licenses/>.
*
*	Last modified:		09/06/2014
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#ifndef _OBJLIST_H_
#include "objlist.h"
#endif

#ifndef _PLIST_H_
#define _PLIST_H_

/*------------------------------- definitions -------------------------------*/

#define	PLIST(ptr, elem)	(((pbliststruct *)(ptr))->elem)

#define	PLISTEXIST(elem)	(plistexist_##elem)

#define	PLISTPIX(ptr, elem)	(*((PIXTYPE *)((ptr)+plistoff_##elem)))

#define	PLISTFLAG(ptr, elem)	(*((FLAGTYPE *)((ptr)+plistoff_##elem)))

/*------------------------------- structures --------------------------------*/

typedef struct
  {
  int		nextpix;
  int		x, y;
  PIXTYPE       value;
  }	pbliststruct;

/*-------------------------------- globals ----------------------------------*/

int	plistexist_value, plistexist_cvalue,
	plistexist_flag, plistexist_wflag, plistexist_dthresh, plistexist_var,
	plistoff_value, plistoff_cvalue,
	plistoff_flag[MAXFLAG], plistoff_wflag, plistoff_dthresh, plistoff_var,
	plistsize;

/*------------------------------- functions ---------------------------------*/

void	init_plist(void);

#endif
