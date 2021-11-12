/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "target.hpp"
#include <iostream>

namespace dci::aup::collector
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    bool Target::setup(const std::string& key, const std::vector<std::string>& values)
    {
        if("TARGET_TYPE" == key)
        {
            if(1 != values.size())
            {
                std::cerr << "bad target type value" << std::endl;
                return false;
            }

            // на текущий момент не важно
            return true;
        }

        if("TARGET_KIND" == key)
        {
            if(1 != values.size())
            {
                std::cerr << "bad target kind value" << std::endl;
                return false;
            }

            if("AUX"            == values[0]) {_kind = catalog::File::Kind::null;     return true;}
            if("BDEP"           == values[0]) {_kind = catalog::File::Kind::bdep;     return true;}
            if("TEST"           == values[0]) {_kind = catalog::File::Kind::test;     return true;}
            if("MODULE"         == values[0]) {_kind = catalog::File::Kind::runtime;  return true;}
            if("MODULE_SPARE"   == values[0]) {_kind = catalog::File::Kind::runtime;  return true;}
            if("REGULAR"        == values[0]) {_kind = catalog::File::Kind::runtime;  return true;}

            std::cerr << "unknown target kind: " << values[0] << std::endl;
            return false;
        }

        if("TARGET_FILE" == key)
        {
            if(1 != values.size())
            {
                std::cerr << "bad target file value" << std::endl;
                return false;
            }

            checkIsAbsFile(values[0]);
            _file = values[0];
            return true;
        }

        if("TARGET_DEPS" == key)
        {
            checkIsAbsFiles(values);
            _deps.insert(values.begin(), values.end());
            return true;
        }

        return Meta::setup(key, values);
    }
}
