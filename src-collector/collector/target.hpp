/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/aup/catalog/file.hpp>
#include "meta.hpp"
#include "absAndRel.hpp"

namespace dci::aup::collector
{
    struct Target : Meta
    {
    public:
        using Meta::Meta;

        bool setup(const std::string& key, const std::vector<std::string>& values) override;

    public:
        catalog::File::Kind   _kind{};
        fs::path              _file;
        std::set<fs::path>    _deps;

    public:
        std::set<AbsAndRel>   _resourceDeps;
    };
}
