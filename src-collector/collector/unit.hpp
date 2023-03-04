/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "meta.hpp"
#include "absAndRel.hpp"

namespace dci::aup::collector
{
    struct Target;
    struct Unit : Meta
    {
    public:
        using Meta::Meta;

        bool setup(const std::string& key, const std::vector<std::string>& values) override;
        Target* getTarget(const std::string& name, bool addIfMissing);

    public:
        std::set<AbsAndRel>             _srcDirs;
        std::set<AbsAndRel>             _srcFiles;

        std::set<AbsAndRel>             _includeDirs;
        std::set<AbsAndRel>             _includeFiles;

        std::set<AbsAndRel>             _idlDirs;
        std::set<AbsAndRel>             _idlFiles;

        std::set<AbsAndRel>             _cmmDirs;
        std::set<AbsAndRel>             _cmmFiles;

        std::set<std::string>           _extraAllowed;
        std::map<std::string, Target>   _targets;
    };
}
