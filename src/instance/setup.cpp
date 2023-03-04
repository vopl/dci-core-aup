/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <dci/aup/instance/setup.hpp>
#include <dci/aup/exception.hpp>
#include "../instance.hpp"

namespace dci::aup::instance::setup
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void start(const std::vector<std::string>& args)
    {
        if(g_instance)
        {
            throw aup::Exception{"instance already initialized"};
        }

        g_instance.reset(new Instance);

        try
        {
            g_instance->start(args);
        }
        catch(...)
        {
            g_instance.reset();
            throw;
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    bool targetComplete()
    {
        if(!g_instance) throw aup::Exception{"instance uninitialized"};
        return g_instance->targetComplete();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void updateTarget()
    {
        if(!g_instance) throw aup::Exception{"instance uninitialized"};
        return g_instance->updateTarget();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void collectGarbage()
    {
        if(!g_instance) throw aup::Exception{"instance uninitialized"};
        return g_instance->collectGarbage();
    }
}
