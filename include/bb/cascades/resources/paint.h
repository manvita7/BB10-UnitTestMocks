/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef cascades_paint_h
#define cascades_paint_h

namespace bb {
    namespace cascades {

    class Paint {
    public:
        virtual ~Paint() { }

        virtual bool operator==(const Paint &other) const = 0;

        virtual bool operator!=(const Paint &other) const = 0;

        Paint() { }
        Paint(const Paint &orig) {  }

        Paint& operator=(const Paint& other) { return *this; }

        virtual bool isNull() const = 0;
    };
    
}
}

#endif	/* cascades_paint_h */