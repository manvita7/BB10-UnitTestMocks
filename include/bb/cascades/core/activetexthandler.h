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
#ifndef cascades_activetexthandler_h
#define cascades_activetexthandler_h
#include "gmock/gmock.h"
#include <bb/cascades/core/gesturehandler.h>
namespace bb {
    namespace cascades {
    class ActiveTextHandlerPrivate;
    class ActiveTextTriggeredEvent;
    class ActiveTextHandler : public UIObject 
    {
public:
      ActiveTextHandler(UIObject* parent = 0);
      virtual ~ActiveTextHandler();
      MOCK_METHOD1(triggered, void (bb::cascades::ActiveTextTriggeredEvent *event));
public:
        typedef UIObject BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& onTriggered(const QObject* receiver, const char *method) {
                bool res = QObject::connect(&this->instance(), SIGNAL(triggered(bb::cascades::ActiveTextTriggeredEvent*)), receiver, method);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, ActiveTextHandler> {
        public:
            Builder() : TBuilder<Builder, ActiveTextHandler>(new ActiveTextHandler()) {}
        };
      static Builder create() {
            return Builder();
        }
    };
  }
}
#endif 
