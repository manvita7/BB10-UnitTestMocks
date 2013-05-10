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

#ifndef cascades_imagepaint_h
#define cascades_imagepaint_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QMetaType>
#include <QDebug>
#include <bb/cascades/resources/paint.h>
#include <bb/cascades/resources/repeatpattern.h>
namespace bb {
    namespace cascades {
    class ImagePaintDataPrivate;
    class Image;    
    class ImagePaint : public Paint
    {
public:
        ImagePaint();
        ImagePaint(const QUrl& url,
                            RepeatPattern::Type pattern = RepeatPattern::Fill);
        ImagePaint(const Image& image,
                            RepeatPattern::Type pattern = RepeatPattern::Fill);
        ImagePaint(const ImagePaint& orig);
        ImagePaint& operator=(const ImagePaint& other);
        virtual ~ImagePaint();
        bool operator==(const Paint &other) const;
        bool operator!=(const Paint &other) const;
        MOCK_CONST_METHOD0(repeatPattern, RepeatPattern::Type ());
        MOCK_CONST_METHOD0(image, Image ());
    };
    }
}
#endif