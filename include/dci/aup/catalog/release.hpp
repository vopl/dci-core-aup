/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "object.hpp"

namespace dci::aup::catalog
{
    struct Release : Object
    {
        String _srcBranch;
        String _srcRevision;

        String _platformOs;
        String _platformArch;
        String _compiler;
        String _compilerVersion;
        String _compilerOptimization;
        uint64 _moment {};//unix time

        String _provider;
        uint32 _stability {};

        Array<uint8, 32> _signer {};
        Array<uint8, 64> _signature {};

        Type type() const override {return Object::Type::release;}
    };

    using ReleasePtr = std::unique_ptr<Release>;
}
