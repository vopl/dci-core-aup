/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "../collector.hpp"
#include <dci/utils/h2b.hpp>

namespace dci::aup
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setMetaFile(std::string v)
    {
        auto p = fs::canonical(v);
        if(!fs::is_regular_file(p))
        {
            throw std::runtime_error{"bad meta file path: "+v+" ("+p.string()+")"};
        }

        _metaFile = p;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setSignerKey(std::string v)
    {
        if(v.size() != _signerKey.size()*2 ||
            !dci::utils::h2b(v.data(), v.size(), _signerKey.data()))
        {
            throw std::runtime_error{"bad signer key value: "+v};
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setStorageDir(std::string v)
    {
        fs::create_directories(v);
        auto p = fs::canonical(v);
        if(!fs::is_directory(p))
        {
            throw std::runtime_error{"bad resulting storage dir: "+v+" ("+p.string()+")"};
        }

        _storageDir = p;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setIgnoreSources(bool v)
    {
        _ignoreSources = v;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setIgnoreDebug4Targets(bool v)
    {
        _ignoreDebug4Targets = v;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Collector::setIgnoreDebug4Others(bool v)
    {
        _ignoreDebug4Others = v;
    }
}
