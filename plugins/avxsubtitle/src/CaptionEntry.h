// Copyright (c) 2012 David Ronca.  All rights reserved.
// videophool@hotmail.com
// http://www.avxsynth.org


// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA, or visit
// http://www.gnu.org/copyleft/gpl.html .
//
// Linking Avisynth statically or dynamically with other modules is making a
// combined work based on Avisynth.  Thus, the terms and conditions of the GNU
// General Public License cover the whole combination.
//
// As a special exception, the copyright holders of Avisynth give you
// permission to link Avisynth with independent modules that communicate with
// Avisynth solely through the interfaces defined in avisynth.h, regardless of the license
// terms of these independent modules, and to copy and distribute the
// resulting combined work under terms of your choice, provided that
// every copy of the combined work is accompanied by a complete copy of
// the source code of Avisynth (the version of Avisynth used to produce the
// combined work), being distributed under the terms of the GNU General
// Public License plus this exception.  An independent module is a module
// which is not derived from or based on Avisynth, such as 3rd-party filters,
// import and export plugins, or graphical user interfaces.auto


#ifndef _CAPTION_ENTRY_H
#define _CAPTION_ENTRY_H

#include "vector"
#include "AvxString.h"
#include "stdint.h"

using namespace std;

using namespace avxsynth;

namespace avxsynth
{
    class CaptionEntry
    {
    public:
        CaptionEntry(int64_t startTime, int64_t endTime, vector< Utf8String > textLines);
        ~CaptionEntry(void);

        CaptionEntry(CaptionEntry const& cpy){*this = cpy;}

        CaptionEntry& operator=(CaptionEntry const& cpy);
        
        int64_t StartTime() const {return this->startTime;}
        int64_t EndTime()const {return this->endTime;}
        vector< Utf8String > const& TextLines() const {return this->textLines;}

        Utf8String toDebugString() const; 
        Utf8String toDisplayString() const;

        bool operator==(CaptionEntry const& cmp) const;
        bool operator!=(CaptionEntry const& cmp) const {return !(*this == cmp);}

        static const CaptionEntry Empty;

    private:

        int64_t startTime;
        int64_t endTime;
        vector< Utf8String > textLines;
    };
} // namespace avxsynth

#endif // #ifndef _CAPTION_ENTRY_H