/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <dci/aup/applier.hpp>
#include <dci/aup/catalog.hpp>
#include <dci/aup/storage.hpp>
#include "impl/applier.hpp"

namespace dci::aup
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Applier::Applier()
        : himpl::FaceLayout<Applier, impl::Applier>{}
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Applier::~Applier()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Applier::addCatalog(Catalog* c)
    {
        return impl().addCatalog(himpl::face2Impl(c));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Applier::addStorage(Storage* s)
    {
        return impl().addStorage(himpl::face2Impl(s));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Applier::addRoot(const Oid& oid, const Set<catalog::File::Kind>& fileKinds)
    {
        return impl().addRoot(oid, fileKinds);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    applier::Result Applier::process(const String& place, applier::Task task)
    {
        return impl().process(place, task);
    }
}
