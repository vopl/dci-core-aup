/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/primitives.hpp>


namespace dci::aup::applier
{
    enum Task : uint64
    {
        tNull              = 0x0,
        tVerboseMajor      = 0x1,
        tVerboseMinor      = 0x2,
        tVerbose           = 0x3,
        tCheckStorage      = 0x4,

        tRemoveWrongs      = 0x10,
        tEmplaceMissings   = 0x20,
        tEmplaceChanges    = 0x40,
        tRemoveExtra       = 0x80,

        tAll               = ~uint64{}
    };
}
