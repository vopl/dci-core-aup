/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/himpl.hpp>
#include <dci/aup/implMetaInfo.hpp>
#include "api.hpp"
#include "oid.hpp"
#include "catalog/object.hpp"
#include <dci/bytes.hpp>

namespace dci::aup
{
    class API_DCI_AUP Catalog
        : public himpl::FaceLayout<Catalog, impl::Catalog>
    {
        Catalog(const Catalog&) = delete;
        Catalog(Catalog&&) = delete;

        void operator=(const Catalog&) = delete;
        void operator=(Catalog&&) = delete;

    public:
        Catalog();
        ~Catalog();

    public://весь индекс в блоб и обратно
        void deserialize(Bytes&& blob);
        Bytes serialize();

    public://перечисление
        Set<Oid> enumerate(catalog::Object::Type type = catalog::Object::Type::null);

    public://объектный ввод/вывод
        Oid put(catalog::ObjectPtr&& object);
        bool has(const Oid& oid);
        catalog::ObjectPtr get(const Oid& oid);
        void del(const Oid& oid);
    };
}
