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
#ifndef cascades_segmentedcontrol_h
#define cascades_segmentedcontrol_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/controls/option.h>
namespace bb {
    namespace cascades {
    class SegmentedControlPrivate;
    class Container;
    class SegmentedControl : public Control
    {
public:
        const int SelectedIndexNone;
        SegmentedControl(Container * parent = 0);
        virtual ~SegmentedControl();
        MOCK_CONST_METHOD0(selectedIndex, int ());
        MOCK_METHOD1(setSelectedIndex, void (int index));
        MOCK_METHOD0(resetSelectedIndex, void ());
        MOCK_CONST_METHOD0(selectedOption, bb::cascades::Option* ());
        MOCK_METHOD1(setSelectedOption, void (bb::cascades::Option* option));
        MOCK_METHOD0(resetSelectedOption, void ());
        MOCK_CONST_METHOD0(isSelectedOptionSet, bool ());
        MOCK_CONST_METHOD0(selectedValue, QVariant ());
        MOCK_METHOD1(add, void (bb::cascades::Option* option));
        MOCK_METHOD2(insert, void (int index, bb::cascades::Option* option));
        MOCK_METHOD1(remove, bool (bb::cascades::Option* option));
        MOCK_METHOD0(removeAll, void ());
        MOCK_CONST_METHOD1(at, bb::cascades::Option* (int index));
        MOCK_CONST_METHOD1(indexOf, int (bb::cascades::Option* option));
        MOCK_CONST_METHOD0(count, int ());
        MOCK_METHOD1(selectedIndexChanged, void (int selectedIndex));
        MOCK_METHOD1(selectedOptionChanged, void (bb::cascades::Option* selectedOption));
        MOCK_METHOD1(selectedOptionSetChanged, void (bool selectedOptionSet));
        MOCK_METHOD1(selectedValueChanged, void (const QVariant& selectedValue));
        MOCK_METHOD1(optionAdded, void (bb::cascades::Option *option));
        MOCK_METHOD1(optionRemoved, void (bb::cascades::Option *option));
        typedef SegmentedControl ThisClass;
        typedef Control BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& add(bb::cascades::Option* option)
            {
                this->instance().add(option);
                return this->builder();
            }
            BuilderType& add(const QString &optionText, const QVariant &value = QVariant(), bool selected = false)
            {
                this->instance().add(Option::create().text(optionText).value(value).selected(selected));
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, SegmentedControl>
        {
        public:
            Builder() : TBuilder<Builder, SegmentedControl>(new SegmentedControl())
            {
            }
        };
      static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif
