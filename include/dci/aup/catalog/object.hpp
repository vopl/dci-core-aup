/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "../oid.hpp"
#include <dci/primitives.hpp>

#include <dci/bytes.hpp>

namespace dci::aup::catalog
{
    struct Object;
    using ObjectPtr = std::unique_ptr<Object>;

    template <class To, class From>
    To* objectPtrCast(From* from)
    {
        return dynamic_cast<To*>(from);
    }

    template <class To, class From>
    const To* objectPtrCast(const From* from)
    {
        return dynamic_cast<const To*>(from);
    }

    template <class To, class From>
    std::unique_ptr<To> objectPtrCast(std::unique_ptr<From>&& from)
    {
        To* to = dynamic_cast<To*>(from.get());
        if(to)
        {
            from.release();
            return std::unique_ptr<To>{to};
        }

        return std::unique_ptr<To>{};
    }

    struct Object
    {
        enum class Type
        {
            null        = 0,

            file        = 1,
            unit        = 2,
            release     = 3,
        };

        Set<Oid>   _dependencies;

    public:
        virtual ~Object() = default;
        virtual Type type() const = 0;
    };
}
