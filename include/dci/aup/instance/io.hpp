/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "../api.hpp"
#include "../oid.hpp"
#include <optional>
#include <dci/bytes.hpp>

namespace dci::aup::instance::io
{
    API_DCI_AUP bool instanceInitialized();

    API_DCI_AUP const Set<Oid>& allReleases();

    API_DCI_AUP const Set<Oid>& targetMostReleases();
    API_DCI_AUP const Set<Oid>& targetCatalogIncomplete();
    API_DCI_AUP const Set<Oid>& targetCatalogComplete();
    API_DCI_AUP const Set<Oid>& targetStorageIncomplete();
    API_DCI_AUP const Set<Oid>& targetStorageComplete();

    API_DCI_AUP const Set<Oid>& bufferMostReleases();
    API_DCI_AUP const Set<Oid>& bufferCatalogIncomplete();
    API_DCI_AUP const Set<Oid>& bufferCatalogComplete();
    API_DCI_AUP const Set<Oid>& bufferStorageIncomplete();
    API_DCI_AUP const Set<Oid>& bufferStorageComplete();

    API_DCI_AUP bool hasCatalogObject(const Oid& oid);
    API_DCI_AUP bool hasStorageObject(const Oid& oid);

    API_DCI_AUP std::optional<Bytes> getCatalogObject(const Oid& oid);
    API_DCI_AUP std::optional<Bytes> getStorageObject(const Oid& oid, uint32 from=0, uint32 to=~uint32{});

    enum class PutObjectResult
    {
        ok,
        corrupted,
        unwanted
    };

    API_DCI_AUP PutObjectResult putCatalogObject(const Oid& oid, Bytes&& blob);
    API_DCI_AUP PutObjectResult putStorageObject(const Oid& oid, Bytes&& blob);

    struct StdFileDeleter
    {
        void operator()(std::FILE* f) const { fclose(f); }
    };

    using StdFilePtr = std::unique_ptr<std::FILE, StdFileDeleter>;
    API_DCI_AUP PutObjectResult putStorageObject(const Oid& oid, StdFilePtr f);
}
